#include <iostream>

using namespace std;

int modex(int a, int b, int m)
{
    if(b == 0) return 1;
    if(b%2 == 0) {
        int d = modex(a, b/2, m);
        return (d*d)%m;
    } else {
        return a*modex(a, b-1, m)%m;
    }
}

int main()
{
    int a, b, m; cin >> a >> b >> m;

    cout << modex(a, b, m) << "\n";
}