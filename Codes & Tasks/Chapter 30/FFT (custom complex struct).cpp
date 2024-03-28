#include <bits/stdc++.h>

using namespace std;
const double PI = acos(-1);

struct cd { // complex double
    double real, imag;
    cd(double x = 0, double y = 0) : real(x), imag(y) {}
    cd operator +(const cd &o) { return cd(real + o.real, imag + o.imag); }
    cd operator -(const cd &o) { return cd(real - o.real, imag - o.imag); }
    cd operator *(const cd &o) { return cd(real * o.real - imag * o.imag, real * o.imag + imag * o.real); }
    cd operator /(const cd &o) { return cd((real * o.real + imag * o.imag) / (o.real * o.real + o.imag * o.imag), (imag * o.real - real * o.imag) / (o.real * o.real + o.imag * o.imag)); }
};

vector <cd> FFT(vector <cd> &p, bool inv = false)
{
    int n = p.size();
    if(n == 1) return p;

    vector <cd> Aeven(n/2);
    vector <cd> Aodd(n/2);
    for(int i = 0; i < n; i ++)
    {
        if(i%2 == 0) {
            Aeven[i/2] = p[i];  
        } else {
            Aodd[i/2] = p[i];
        }
    }

    vector <cd> Peven = FFT(Aeven, inv);
    vector <cd> Podd = FFT(Aodd, inv);
    cd omega = 1;
    double angle = 2*PI/n * (inv ? -1 : 1);
    cd omegaN = cd(cos(angle), sin(angle));

    vector <int> P(n);

    for(int i = 0; i < n/2; i ++) {
        p[i] = Peven[i] + omega * Podd[i];
        p[i + n/2] = Peven[i] - omega * Podd[i];

        omega = omega * omegaN;
    }

    return p;
}

vector <cd> FFTI(vector<cd> &c)
{
    int n = c.size();
    c = FFT(c, true);
    for(int i = 0; i < n; i ++) {
        c[i] = c[i] / n;
    }

    return c;
}

vector <int> multiply(vector <int> &a, vector <int> &b)
{
    int n = 1;
    while(n < a.size() + b.size()) {
        n <<= 1;
    }
    vector <cd> A(n);
    vector <cd> B(n);

    for(int i = 0; i < a.size(); i ++) {
        A[i] = a[i];
    }
    for(int i = 0; i < b.size(); i ++) {
        B[i] = b[i];
    }

    A = FFT(A);
    B = FFT(B);

    vector <cd> C(n);
    for(int i = 0; i < n; i ++) {
        C[i] = A[i] * B[i];
    }

    C = FFTI(C); // inverse
    vector <int> c(n);
    
    for(int i = 0; i < n; i ++) {
        c[i] = round(C[i].real);
    }

    return c;
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