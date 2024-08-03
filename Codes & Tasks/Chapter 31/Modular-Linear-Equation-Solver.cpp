#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

tuple <int, int, int> extendedgcd(int a, int b) {    
    if(b == 0) return {a, 1, 0};
    int dd, xx, yy;
    tie(dd, xx, yy) = extendedgcd(b, a % b);
    return {dd, yy, xx - (a / b) * yy};
}

vector <int> modularLinearEquationSolver(int a, int b, int n) {
    int d, x, y;
    tie(d, x, y) = extendedgcd(a, n);
    vector <int> sol;
    if(b % d == 0) {
        int x0 = (x*(b/d)) % n;
        for(int i = 0; i < d; i ++) {
            sol.push_back(((x0 + i * (n / d)) % n + n) % n);
        }
    }
    return sol;
}

int main() {
    int a, b, n; cin >> a >> b >> n;
    vector <int> sol = modularLinearEquationSolver(a, b, n);
    for(auto i: sol) cout << i << " ";
}