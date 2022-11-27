#include <bits/stdc++.h>
using namespace std;

int n;
vector <int> v;
vector <int> dp;
vector <int> sol;

int rodcut(int mx)
{
    for(int i = 1; i <= n; i ++) {
        sol[i] = i;
        for(int j = 0; j < i; j ++) {
            if(dp[j]+v[i-j] > dp[i]) {
                dp[i] =  dp[j]+v[i-j];
                sol[i] = i-j;
            }
        }
    }

    return dp[mx];
}

int main()
{
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