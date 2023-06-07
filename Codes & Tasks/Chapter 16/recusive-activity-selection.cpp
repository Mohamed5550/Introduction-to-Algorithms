#include <bits/stdc++.h>

using namespace std;

int n;
vector <pair<int, int>> v;

int acrec(int l, int r)
{
    int m = l+1;
    while(m <= n && v[m].first < v[l].second) m ++;

    if(m <= n)
        return 1 + acrec(m, r);
    else return 0;
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