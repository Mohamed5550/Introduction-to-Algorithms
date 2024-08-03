#include <iostream>
#include <tuple>

using namespace std;

tuple <int, int, int> extendedgcd(int a, int b) {    
    if(b == 0) return {a, 1, 0};
    int dd, xx, yy;
    tie(dd, xx, yy) = extendedgcd(b, a % b);
    return {dd, yy, xx - (a / b) * yy};
}

int main() {
    int a, b; cin >> a >> b;
    int d, x, y;
    tie(d, x, y) = extendedgcd(a, b);
    cout << d << " " << x << " " << y << "\n";
}   