// problem: given two n binary numbers output their n+1 binary sum
// input a, b n binary number
// outpu c n+1 binary number


// note: the binart string will be left to write 
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n], b[n];
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    for(int i = 0; i < n; i ++) {
        cin >> b[i];
    }

    int c[n+1];

    int rem = 0;
    for(int i = 0; i < n; i ++) {
        c[i] = (rem+a[i]+b[i])%2;
        rem = (rem+a[i]+b[i])/2;
    }
    c[n] = rem%2;
    for(int i = 0; i < n+1; i ++) {
        cout << c[i] << " ";
    }
    cout << endl;
}