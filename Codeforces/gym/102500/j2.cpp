#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

class Post {
   public:
    int id, vote;
    int prev, next;
    bool operator<(const Post &p) const { return abs(vote) < abs(p.vote); }
};

int n = 0;
long long c = 0, r = 0;
Post post[500005] = {};
Post sorted[500005] = {};

long long countInitialReports() {
    int pos = 1;
    long long ret = 0;
    for (; pos <= n; ++pos) {
        if (!post[pos].vote) {
            ++ret;
        } else {
            break;
        }
    }
    bool sign = !(post[pos].vote > 0);
    for (; pos <= n; ++pos) {
        if (!post[pos].vote or (sign == post[pos].vote > 0)) {
            ++ret;
        } else {
            sign = !sign;
        }
    }
    return ret;
}

bool needsReport(int l, int r) {
    assert(l <= r);
    if (l == 0 or r == n + 1) return false;
    assert(post[l].vote != 0 and post[r].vote != 0);
    return (r - l) % 2 == !((post[l].vote > 0) xor (post[r].vote > 0));
}

long long solve() {
    memcpy(sorted, post, sizeof(post));
    sort(sorted + 1, sorted + 1 + n);
    int pos = 1;
    long long cnt = countInitialReports();
    long long ans = cnt * r;
    for (; pos <= n and !sorted[pos].vote; ++pos) {
        int id = sorted[pos].id;
        post[post[id].next].prev = post[id].prev;
        post[post[id].prev].next = post[id].next;
    }
    // =========================================================
    cnt = 0;
    for (int i = 0; i <= n; i = post[i].next) {
        cnt += needsReport(i, post[i].next);
    }
    ans = min(ans, c + cnt * r);
    // =========================================================
    for (; pos <= n; ++pos) {
        int id = sorted[pos].id;
        long long fake = abs(sorted[pos].vote) + 1;
        //printf("[%d%d%d] ", needsReport(post[id].prev, id), needsReport(id, post[id].next), needsReport(post[id].prev, post[id].next));
        cnt -= needsReport(post[id].prev, id);
        cnt -= needsReport(id, post[id].next);
        cnt += needsReport(post[id].prev, post[id].next);
        post[post[id].next].prev = post[id].prev;
        post[post[id].prev].next = post[id].next;
        //printf("%lld %lld => %lld\n", fake, cnt, fake * c + cnt * r);
        if (fake * c + cnt * r < ans) {
            ans = fake * c + cnt * r;
        }
    }
    return ans;
}

int main() {
    scanf("%d%lld%lld", &n, &c, &r);
    post[0].id = 0, post[0].next = 1;
    for (int i = 1; i <= n; ++i) {
        post[i].id = i;
        scanf("%d", &post[i].vote);
        post[i].prev = i - 1;
        post[i].next = i + 1;
    }
    post[n + 1].id = n + 1, post[n + 1].prev = n;
    printf("%lld\n", solve());
    return 0;
}