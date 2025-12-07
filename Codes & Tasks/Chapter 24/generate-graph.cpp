#include <iostream>
#include <vector>

using namespace std;

void fast() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
}

int main() {
    // generate adjacency list and write to file
    fast();
    freopen("input2.txt", "w", stdout);

    int v = 10000; // number of vertices
    int e = 50000; // number of edges
    cout << v << " " << e << "\n";
    srand(time(0));
    for(int i = 1; i <= e; i ++) {
        int a = rand() % v + 1;
        int b = rand() % v + 1;
        int w = rand() % 1000 + 1;
        cout << a << " " << b << " " << w << "\n";
    }

    return 0;
}