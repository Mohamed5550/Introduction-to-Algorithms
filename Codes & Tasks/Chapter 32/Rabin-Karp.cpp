#include <iostream>
#include <string>
using namespace std;

bool checkMatch(string &t, string &p, int shift)
{
    for(int i = 0; i < p.size(); i ++) {
        if(t[i + shift] != p[i]) return false;
    }

    return true;
}

int intPow(int a, int b, int mod)
{
    int res = 1;
    while(b > 0) {
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }

    return res;
}

void RabinKarp(string t, string p)
{
    int n = t.size();
    int m = p.size();
    int d = 256;
    int q = 101; // A prime number
    int h = intPow(d, m - 1, q);
    int p_hash = 0;
    int t_hash = 0;

    for(int i = 0; i < m; i ++) {
        p_hash = (d * p_hash + p[i]) % q;
        t_hash = (d * t_hash + t[i]) % q;
    }

    for(int i = 0; i <= n - m; i ++) {
        if(p_hash == t_hash) {
            bool match = checkMatch(t, p, i);
            if(match) {
                cout << "Pattern occurs with shift " << i << "\n";
            }
        }
        if(i < n - m) {
            t_hash = ((d * (t_hash - t[i] * h) + t[i + m]) % q + q) % q;
        }
    }
}

int main()
{
    string t, p; cin >> t >> p;
    RabinKarp(t, p);

/*abababacaba
ababaca*/
    return 0;
}
