#include <bits/stdc++.h>

using namespace std;
const double PI = acos(-1);

vector <complex<double>> getEven(vector <complex<double>> &p, int n)
{
    vector <complex<double>> even;
    for(int i = 0; i < n; i += 2)
    {
        even.push_back(p[i]);
    }
    return even;
}

vector <complex<double>> getOdd(vector <complex<double>> &p, int n)
{
    vector <complex<double>> odd;
    for(int i = 1; i < n; i += 2)
    {
        odd.push_back(p[i]);
    }
    return odd;
}

vector <complex<double>> FFT(vector <complex<double>> p, bool inv = false)
{
    int n = p.size();
    if(n == 1) return p;

    vector <complex<double>> Aeven = getEven(p, n);
    vector <complex<double>> Aodd = getOdd(p, n);

    vector <complex<double>> Peven = FFT(Aeven, inv);
    vector <complex<double>> Podd = FFT(Aodd, inv);
    complex<double> omega = 1;
    complex<double> omegaN = exp(complex<double>(0, 2*PI / n * (inv ? -1 : 1)));

    vector <int> P(n);

    for(int i = 0; i < n/2; i ++) {
        p[i] = Peven[i] + omega * Podd[i];
        p[i + n/2] = Peven[i] - omega * Podd[i];

        omega *= omegaN;
    }

    return p;
}

vector <complex<double>> FFTI(vector<complex<double>> c)
{
    int n = c.size();
    c = FFT(c, true);
    for(int i = 0; i < n; i ++) {
        c[i] /= n;
    }

    return c;
}

vector <long long int> multiply(vector <long long int> a, vector <long long int> b)
{
    int n = 1;
    while(n < a.size() + b.size()) {
        n <<= 1;
    }
    vector <complex<double>> A(n);
    vector <complex<double>> B(n);

    for(int i = 0; i < a.size(); i ++) {
        A[i] = a[i];
    }
    for(int i = 0; i < b.size(); i ++) {
        B[i] = b[i];
    }

    A = FFT(A);
    B = FFT(B);

    vector <complex<double>> C(n);
    for(int i = 0; i < n; i ++) {
        C[i] = A[i] * B[i];
    }

    C = FFTI(C); // inverse
    vector <long long int> c(n);
    
    for(int i = 0; i < n; i ++) {
        c[i] = round(C[i].real());
    }

    return c;
}

int main()
{
    vector <long long int> a = {1, 2, 3, 4};
    vector <long long int> b = {5, 6, 7, 8};

    vector <long long int> c = multiply(a, b);

    for(int i = 0; i < c.size(); i ++) {
        cout << c[i] << " ";
    }
    cout << "\n";
}