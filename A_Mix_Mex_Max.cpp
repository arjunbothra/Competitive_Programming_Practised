#include <bits/stdc++.h>
using namespace std;

int sum(int a, int b){
    return a + b;
}

int product(int a, int b){
    return a * b;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;                         // number of test cases
    cin >> tests;
    while (tests--) {
        int len;                       // array length
        cin >> len;

        vector<int> arr(len);          // the array itself
        for (int &val : arr) cin >> val;

        unordered_set<int> fixedVals;  // distinct values ≠ −1
        for (int val : arr)
            if (val != -1) fixedVals.insert(val);

        bool ok;
        if (fixedVals.empty()) {               // all −1 → pick any k > 0
            ok = true;
        } else if (fixedVals.size() > 1) {     // more than one fixed value
            ok = false;
        } else {                               // exactly one fixed value
            ok = (*fixedVals.begin() > 0);     // that value must be positive
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
