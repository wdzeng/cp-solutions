#include <iostream>
using namespace std;

bool is_prime(int x) {
    if(x%2==0) return false;
    for(int i=3;i*i<=x;i+=2) if(x%i==0) return false;
    return true;
}

int solve(int x) {
    if(x<=3) return -1;
    return is_prime(x-2) ? (x-2) : -1;
} 

int main() {
    int n; cin >> n;
    int s = solve(n);
    if(s==-1) cout << "-1\n";
    else cout << 2 << " " << (n-2) << endl;
    return 0;
}