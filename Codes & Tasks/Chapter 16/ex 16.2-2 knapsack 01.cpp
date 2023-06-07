#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, w; cin >> n >> w;
    vector <int> v(n+1), ww(n+1);
    for(int i = 1; i <= n; i ++) cin >> v[i];
    for(int i = 1; i <= n; i ++) cin >> ww[i];
    
    int dp[n+1][w+1];
    memset(dp, 0, sizeof dp);
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= w; j ++) {
            dp[i][j] = dp[i-1][j];
            if(j-ww[i] <= 0) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-ww[i]] + v[i]);
            }
        }
    }

    cout << dp[n][w] << "n";
}