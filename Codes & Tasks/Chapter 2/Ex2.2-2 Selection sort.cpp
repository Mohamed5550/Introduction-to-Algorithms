#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i ++) {
        cin >> arr[i];
    }

    for(int i = 0; i < n-1; i ++) {
        int mn = 1e9;
        int index = i;
        for(int j = i; j < n; j ++) {
            if(arr[j] < mn) {
                index = j;
                mn = arr[j];
            }
        }
        swap(arr[i], arr[index]);
    }

    for (int i = 0; i < n; i ++) {
        cout << arr[i] << " ";
    }
}

/*
= loop invariants: 
    - initialization: It begins with the first eleent, so there is nothing to worry about in the initial state
    - maintance: After each iteration, it is guaranteed that the last keys are sorted and has the smallest k elements
    - terminate: It is being terminated in the n-1 iteration because the last element is guaranteed to be the max element (The answer to the next question)

= worst case analysis: O(n^2)
= best case analysis: O(n^2)
*/