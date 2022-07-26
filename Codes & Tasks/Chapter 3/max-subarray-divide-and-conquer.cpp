#include <bits/stdc++.h>
#define OO INT_MAX
#define _OO INT_MIN

using namespace std;

struct group {
    int left = 0;
    int right = 0;
    int sum = 0;
};

group max_crossing_sum(vector <int> &v, int l, int mid, int r) {
    int max_left = _OO;
    int sum = 0;
    int max_l = 0;
    for(int i = mid; i >= l; --i) {
        sum += v[i];

        if(sum > max_left) {
            max_left = sum;
            max_l =i;
        }
    }

    int max_right = _OO;
    sum = 0;
    int max_r = 0;
    for(int i = mid+1; i <= r; i ++) {
        sum += v[i];
        if(sum > max_right) {
            max_right = sum;
            max_r = i;
        }
    }
    
    return {max_l, max_r, max_left+max_right};

}

group max_subarray_sum(vector <int> &v, int l, int r) {
    if(l == r) {
        group a = {l, r, v[l]};
        return a;
    }

    group left, right, cross;
    int mid = (l+r)/2;
    left = max_subarray_sum(v, l, mid);
    right = max_subarray_sum(v, mid+1, r);
    cross = max_crossing_sum(v, l, mid, r);

    if(left.sum >= right.sum && left.sum >= cross.sum) {
        return left;
    } else if(right.sum >= cross.sum) {
        return right;
    } else {
        return cross;
    }
}

int main() {
    int n;
    cin >> n;



    vector <int> v(n);
    for(auto &i: v) {
        cin >> i;
    }

    group sol = max_subarray_sum(v, 0, n-1);

    cout << "l: " << sol.left << ", r: " << sol.right << ", sum: " << sol.sum << "\n";
}