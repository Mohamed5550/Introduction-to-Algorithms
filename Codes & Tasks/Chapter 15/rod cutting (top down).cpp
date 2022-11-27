#include <bits/stdc++.h>
using namespace std;

int n;
vector <int> v;
vector <int> dp;
int rodcut(int mx)
{
    if(dp[mx]) return dp[mx];

    if(mx == 1) return v[1];
    int x = v[mx];
    for(int i = 1; i < mx; i ++) {
        x = max(x, v[mx-i] + rodcut(i));
    }
    dp[mx] = x;
    return x;
}

int main() {
    cin >> n;
    v.assign(n+1, 0);
    dp.assign(n+1, 0);
    for(int i = 1; i <= n; i ++) cin >> v[i];

    cout << rodcut(n) << "\n";
}