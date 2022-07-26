#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector <int> v(n);
    
    // getting numbers from user
    for(int i = 0; i < n; i ++) {
        cin >> v[i];
    }

    int ans = 0;

    for(int i = 0; i < n; i ++) {
        if(v[i] == x) {
            ans = i+1;
        }
    }

    cout << ans;


    // Using invariant to prove the correctness of the code
    /*
    
    Initializing: when I start the loop, ther is no elements before me, so it is ok for any start.
    Maintance: When I go to the next element, I am sure that the program solution hold (true or false), and will continue with this to the next iteration
    Termintting: When I finish the loop, if there is an element equals to x, I am sure I got it, otherwise, the program will print 0
    
    */
}