#include <bits/stdc++.h>
using namespace std;

int n, k;
vector <int> dp;
vector <int> sol;
vector <int> prices;
vector <int> v;

int rodcut(int mx)
{
    for(int i = 1; i <= n; i ++) {
        for(int j = 0; j < i; j ++) {
            if(v[i-j] + dp[j] > dp[i]) {
                int addPrice = j == 0 ? 0 : k;
                dp[i] = v[i-j] + dp[j] - addPrice;
                sol[i] = i-j;
            }
        }
    }
}

int main()
{
    cin >> n, k;
    v.assign(n+1, 0);
    dp.assign(n+1, 0);
    sol.assign(n+1, 0);
    sol.assign(n+1, 0);

    for(int i = 1; i <= n; i ++) cin >> v[i];
    int ans = rodcut(n);

    while(n > 0) {
        cout << sol[n] << " ";
        n -= sol[n];
    }
}