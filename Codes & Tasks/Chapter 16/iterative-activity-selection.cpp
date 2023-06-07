#include <bits/stdc++.h>

using namespace std;

int n;
vector <pair<int, int>> v;

int acrec(int l, int r)
{

    int sol = 1;
    int end = 1;
    for(int i = 2; i <= n; i ++) {
        if(v[i].first >= v[end].second) {
            end = i;
            sol ++;
        }
    }

    return sol;
}


int main()
{
    cin >> n;
    v.assign(n+1, {});
    for(int i = 1; i <= n; i ++) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    });

    cout << acrec(0, n);
}