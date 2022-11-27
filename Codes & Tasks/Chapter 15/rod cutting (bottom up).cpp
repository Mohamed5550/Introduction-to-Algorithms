#include <bits/stdc++.h>
using namespace std;

int n;
vector <int> v;
vector <int> dp;

int rodcut(int mx)
{
    for(int i = 1; i <= n; i ++) {
        for(int j = 0; j < i; j ++) {
            dp[i] = max(dp[i], dp[j]+v[i-j]);
        }
    }

    return dp[mx];
}

int main()
{
    cin >> n;
    v.assign(n+1, 0);
    dp.assign(n+1, 0);
    for(int i = 1; i <= n; i ++) cin >> v[i];

    cout << rodcut(n) << "\n";
}