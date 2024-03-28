#include <bits/stdc++.h>

using namespace std;
const double PI = acos(-1);

vector <int> sum(vector<int> &a, vector<int> &b)
{
    int n = max(a.size(), b.size());
    vector <int> c(n);
    for(int i = 0; i < n; i ++) {
        c[i] = 0;
        if(i < a.size()) {
            c[i] += a[i];
        }
        if(i < b.size()) {
            c[i] += b[i];
        }
    }
    return c;
}

vector <int> subtract(vector<int> &a, vector<int> &b)
{
    int n = max(a.size(), b.size());
    vector <int> c(n);
    for(int i = 0; i < n; i ++) {
        c[i] = 0;
        if(i < a.size()) {
            c[i] += a[i];
        }
        if(i < b.size()) {
            c[i] -= b[i];
        }
    }
    return c;
}

vector <int> shift(vector<int> &a, int n)
{
    int m = a.size();
    while(m < a.size() + n) {
        m <<= 1;
    }
    vector <int> c(m);
    for(int i = 0; i < a.size(); i ++) {
        c[i + n] = a[i];
    }
    return c;
}

vector <int> mul(vector<int> a, vector<int> b)
{
    // (h1x+l1)(h2x+l2) = h1h2x^2 + h1l2x + l1h2x + l1l2
    // (h1x+l1)(h2x+l2) = ((h1+l1)(h2+l2) - h1h2 - l1l2)x + h1h2x^2 + l1l2;
    // A(x)*B(X) = ((H1+L1)*(H2+L2) - H1*H2 - L1*L2)*x^(n/2) + H1*H2*x^n + L1*L2;
    
    int n = a.size();
    
    if(n == 1) return {a[0]*b[0]};
    
    vector <int> L1(n/2);
    vector <int> H1(n/2);

    vector <int> L2(n/2);
    vector <int> H2(n/2);

    for(int i = 0; i < n/2; i ++) {
        L1[i] = a[i];
        L2[i] = b[i];

        H1[i] = a[i + n/2];
        H2[i] = b[i + n/2];
    }

    vector <int> H1H2 = mul(H1, H2);
    vector <int> L1L2 = mul(L1, L2);
    vector <int> S_H1_L1 = sum(H1, L1);
    vector <int> S_H2_L2 = sum(H2, L2);
    vector <int> M__S_H1_L1__S_H2_L2 = mul(S_H1_L1, S_H2_L2);
    vector <int> shift_H1H2_n = shift(H1H2, n);
    vector <int> first_sub = subtract(M__S_H1_L1__S_H2_L2, H1H2);
    vector <int> second_sub = subtract(first_sub, L1L2);
    vector <int> first_sum = shift(second_sub, n/2);
    vector <int> last_sum = sum(shift_H1H2_n, L1L2);
    vector <int> p = sum(first_sum, last_sum);

    return p;

}

vector <int> multiply(vector<int> a, vector<int> b)
{   
    int n = 1;
    while(n < max(a.size(), b.size())) {
        n <<= 1;
    }
    a.resize(n);
    b.resize(n);
    return mul(a, b);
}

int main()
{
    vector <int> a = {1, 2, 3, 4};
    vector <int> b = {5, 6, 7, 8};

    vector <int> c = multiply(a, b);

    for(int i = 0; i < c.size(); i ++) {
        cout << c[i] << " ";
    }
    cout << "\n";
}