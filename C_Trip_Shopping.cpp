#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;                       
    cin >> tc;
    while (tc--) {
        int n, k;              
        cin >> n >> k;

        vector<int> A(n), B(n);  
        for (int &x : A) cin >> x;
        for (int &x : B) cin >> x;

        long long base = 0;       
        vector<int> diff(n);
        for (int i = 0; i < n; ++i) {
            diff[i] = llabs(A[i] - B[i]);
            base += diff[i];
        }

        if (k % 2 == 0) {         
            cout << base << '\n';
            continue;
        }

        long long best = LLONG_MAX;     
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j) {
                long long v1 = llabs(A[i] - B[j]) + llabs(A[j] - B[i]);
                long long v2 = llabs(A[i] - A[j]) + llabs(B[i] - B[j]);
                long long delta = max(v1, v2) - diff[i] - diff[j];
                best = min(best, delta);
            }

        cout << base + best << '\n';
    }
    return 0;
}
