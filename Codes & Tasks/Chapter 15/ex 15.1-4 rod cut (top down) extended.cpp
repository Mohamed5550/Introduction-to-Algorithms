#include <bits/stdc++.h>
using namespace std;

int n;
vector <int> v;
vector <int> dp;
vector <int> sol;
int rodcut(int mx)
{
    if(dp[mx]) return dp[mx];

    if(mx == 1) {
        sol[1] = 1;
        return v[1];
    }
    int x = -1;
    for(int i = 0; i < mx; i ++) {
        if(v[mx-i] + rodcut(i) > x) {
            x = v[mx-i] + rodcut(i);
            sol[mx] = mx-i;
        }
    }
    dp[mx] = x;
    return x;
}

int main() {
    cin >> n;
    v.assign(n+1, 0);
    dp.assign(n+1, 0);
    sol.assign(n+1, 0);
    for(int i = 1; i <= n; i ++) cin >> v[i];

    int ans = rodcut(n);

    while(n > 0) {
        cout << sol[n] << " ";
        n -= sol[n];
    }
}