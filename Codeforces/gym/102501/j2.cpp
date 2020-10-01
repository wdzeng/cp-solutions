const int MOD = 1'000'000'007;
using Mint = Modular<MOD>;

void Run() {
    int n;
    cin >> n;
    vector<Mint> fact(2 * n + 1);
    fact[0] = fact[1] = 1;
    for (int i = 2; i <= 2 * n; ++i) {
        fact[i] = Mint(i) * fact[i - 1];
    }
    stack<int> stk;
    vector<int> a(n);
    Mint ans = 1;
    auto Catalan = [&](int x) {
        return fact[2 * x] / (fact[x] * fact[x + 1]);
    };
    const int MAX = 1e6;
    vector<int> values(MAX + 1);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        while (!stk.empty() && a[stk.top()] > a[i]) {
            stk.pop();
        }
        if (stk.empty() || a[stk.top()] != a[i]) {
            ans *= Catalan(values[a[i]]);
            values[a[i]] = 1;
        } else {
            ++values[a[i]];
        }
        stk.push(i);
    }
    for (int i = 0; i <= MAX; ++i) {
        ans *= Catalan(values[i]);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Run();
    return 0;
}