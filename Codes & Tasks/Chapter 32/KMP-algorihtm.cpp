#include <iostream>
#include <vector>

using namespace std;

vector<int> computeTransitionFunction(string p)
{
    int m = p.size();
    vector <int> trans(m);

    trans[1] = 0;
    int k = 0;
    for(int i = 1; i < m; i ++) {
        while(k > 0 && p[k] != p[i]) {
            k = trans[k-1];
        }

        if(p[k] == p[i]) k ++;

        trans[i] = k;
    }

    return trans;
}

void KMP(string t, string p)
{
    vector <int> trans = computeTransitionFunction(p);
    int n = t.size();
    int m = p.size();

    int k = 0;

    for(int i = 0; i < n; i ++) {
        while(k > 0 && p[k] != t[i]) {
            k = trans[k-1];
        }

        if(p[k] == t[i]) k ++;

        if(k == m) {
            cout << "Pattern occurs with shift " << i - m + 1 << "\n";
            k = trans[k-1];
        }
    }
}

int main()
{
    string t, p; cin >> t >> p;
    KMP(t, p);

    // T: abababacaba
    // P: ababaca
}
