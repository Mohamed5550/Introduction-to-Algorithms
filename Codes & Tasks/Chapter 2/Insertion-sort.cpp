#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> v(n);


    // getting numbers from user
    for(int i = 0; i < n; i ++) {
        cin >> v[i];
    }

    // Insertion sort code
    for(int i = 1; i < n; i ++) {
        int key = v[i];
        int j = i-1;
        while(j >= 0 && v[j] > key) {
            v[j+1] = v[j];
            j --;
        }

        v[j+1] = key;
    }

    for(auto i: v) {
        cout << i << " ";
    }
}