#pragma GCC optimize("O3", "unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
inline int gcd(int a,int b)
{
    if(!b)return a;
    return gcd(b,a%b);
}
struct SparseTable {
    const int N;
    vector<vector<int>> bitarray;
    SparseTable(const vector<int> & vec) : N(vec.size()) {
        bitarray.assign(__lg(N) + 1, vector<int>(N));
        bitarray[0] = vec;
        for (int i = 1; (1 << i) <= N; i++) {
            int k = N - (1 << i);
            for (int j = 0; j < k; j++) {
                bitarray[i][j] = gcd(bitarray[i - 1][j], bitarray[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    int query(int left_inc, int right_inc) {
        int k = __lg(right_inc - left_inc + 1);
        return gcd(bitarray[k][left_inc], bitarray[k][right_inc - (1 << k) + 1]);
    }
};

int main() {
    cin.tie(0), ios::sync_with_stdio(0); 
   int N, Q , T;
   cin >> T;
   while(T--){
    cin >> N >> Q;
    vector<int> a(N+1);
    for(int i=1; i<=N; i++)
        cin >> a[i];
    SparseTable ST(a);
    while(Q--)
    {
       int L,R,D;
       cin >> L >> R >>D;
       ll ans = 0;
       for(int i=L; i<=R; i++)
       {
            int low = i, high = R;
            int big = R+1, small = i-1;
            while(low <= high)
            {
                int mid =(low+high)>>1;
                if(ST.query(i,mid)>=D)
                {
                    small = max(small,mid);
                    low = mid +1;
                }
                else high = mid-1;
            }
            while(low<=high)
            {
                int mid = (low+high)>>1;
                if(ST.query(i,mid)<=D)
                {
                    big = min(big,mid);
                    high = mid-1;
                }
                else low = mid+1;
            }
            if(small<i || R<big) continue;
            if(small<=big)ans += (big-small+1);
           // cout << i << " " << small << " " << big << endl;
       }
       cout << ans << "\n";
    }}
    return 0;
}
