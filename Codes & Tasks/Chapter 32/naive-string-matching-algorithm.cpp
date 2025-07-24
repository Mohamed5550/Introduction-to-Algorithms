#include <iostream>
#include <string>

using namespace std;

bool matchStrings(string &t, int tstart, int tend, string &p, int pstart, int pend)
{
    if(tend - tstart != pend - pstart) return false;
    int length = tend - tstart + 1;
    for(int i = 0; i < length; i ++) {
        if(t[tstart + i] != p[pstart + i]) return false;
    }

    return true;
}

void naiveStringMatcher(string &t, string &p)
{
    int n = t.size();
    int m = p.size();

    for(int i = 0; i <= n - m; i ++ ) {
        if(matchStrings(t, i, i + m - 1, p, 0, m - 1)) {
            cout << "Pattern occurs with shift " << i << "\n";
        }
    }
}

int main()
{
    string t, p;
    cin >> t >> p;

    naiveStringMatcher(t, p);
}
