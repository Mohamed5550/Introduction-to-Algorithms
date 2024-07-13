#include <bits/stdc++.h>


using namespace std;
typedef long long ll;

#define MOD 1000000007
#define mmax(a, b) ((a > b) ? a : b)
#define mmin(a, b) ((a < b) ? a : b)

// Common file
#include <ext/pb_ds/assoc_container.hpp>
// Including tree_order_statistics_node_update
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

double pi = acos(-1);

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

unsigned long long modex(unsigned long long x, unsigned long long y, unsigned long long m) {
     if (y == 0)
        return 1;
    long long p = modex(x, y / 2, m) % m;
    p = (p * p) % m;
 
    return (y % 2 == 0) ? p : (x * p) % m;
}
unsigned long long modinv(unsigned long long b) { return modex(b, MOD - 2, MOD);}

void setParents(int n) {
    vector<vector<int>> par(n+1, vector<int>(20));
    for (int i = 1; i <= n; i++) par[i][0] = parents[i];
    for (int j = 1; j < 20; j++) {
        for (int i = 1; i <= n; i++) {
            if (par[i][j - 1] == -1) par[i][j] = -1;
            else par[i][j] = par[par[i][j - 1]][j - 1];
        }
    }
    g2 = par;
}

int mth(int u, int m)
{
    for (int i = 0; i < 20; i++) {
        if ((m >> i) & 1) {
            u = g2[u][i];
        }
    }
    return u;
}

int m = 0;
vector <int> p(m+1, 1);
void sieve() {
    p[0] = p[1] = 0;
    for(int i = 2; i * i <= m; i ++) {
        if(p[i]) {
            for(int j = i * 2; j <= m; j += i) {
                p[j] = 0;
            }
        }
    }
}

vector <int> spf(m+1);
void spf_sieve() {
    spf[1] = 1;
    for(int i = 2; i <= m; i ++) {
        spf[i] = i;
    }

    for(int i = 2; i <= m; i += 2) {
        spf[i] = 2;
    }

    for(long long i = 3; i * i <= m; i ++) {
        if(spf[i] == i) {
            for(long long j = i*i; j <= m; j += i) {
                if(spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

int gcdExtended(int a, int b, int *x, int *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }

    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b%a, a, &x1, &y1);

    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
}

long long binpow(long long x, long long y, long long m) {
    if(y == 0) return 1;
    long long res;

    if(y % 2) {
        res = binpow(x, y-1, m);
        if(res * x >= m) {
            y = 1;
        }
        return (res%m * x%m)%m;
    }

    res = binpow(x, y/2, m);
    if(res * res >= m) {
        y = 1;
    }

    return (res%m * res%m)%m;
}

long long cmb(long long n, long long r) {
    r = min(r, n-r);
    long long ans = 1;
    for(int i = 1; i <= r; i ++) {
        ans *= (n-r)+i;
        ans /= i;
    }

    return ans;
}

struct segtree {
    int size = 1;
    vector <int> mins;

    void init(int n) {
        while(size < n) size *= 2;

        mins.assign(size*2, 0);
    }

    void set(int i , int v, int x, int lx, int rx) {
        if(rx - lx == 1) {
            mins[x] = v;
            return;
        }

        int m = (rx+lx)/2;
        if(i < m) {
            set(i, v, 2*x+1, lx, m);
        } else {
            set(i, v, 2*x+2, m, rx);
        }

        mins[x] = min(mins[2*x+1], mins[2*x+2]);
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    int calc(int l, int r, int x, int lx, int rx) {
        if(rx <= l || lx >= r) return 1e9;
        if(lx >= l && rx <= r) return mins[x];

        int m = (lx+rx)/2;
        int m1 = calc(l, r, 2*x+1, lx, m);
        int m2 = calc(l, r, 2*x+2, m, rx);

        return min(m1,m2);
    }

    int calc(int l, int r) {
        return calc(l, r, 0, 0, size);
    }
};

vector<vector<int>> matmul(vector<vector<int>> m1, vector<vector<int>> m2)
{
    vector <vector<int>> mr(m1.size(), vector<int>(m2[0].size()));
    for(int i = 0; i < m1.size(); i ++) {
        for(int j = 0; j < m1[0].size(); j ++) {
            for(int k = 0; k < m2.size(); k ++) {
                mr[i][j] += m1[i][k] * m2[k][j];
                mr[i][j] %= MOD;
            }
        }
    }
    
    return mr;
}

vector <vector<int>> matex(vector<vector<int>> m, int n)
{
    if(n == 1) return m;
    
    if(n%2 == 0) {
        vector <vector<int>> mul = matex(m, n/2);
        return matmul(mul, mul);
    } else {
        return matmul(m, matex(m, n-1));
    }
}

int main() {
    fast();
    //freopen("test.in", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t;
    t = 1;
    cin >> t;

	while(t--) {
       
    }
}