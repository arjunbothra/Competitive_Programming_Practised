#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Fast input: disable sync with stdio, untie cin
void prepare_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
    prepare_io();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<long long> p(n), s(n), a(n), pref(n), suff(n);
        for (int i = 0; i < n; ++i) cin >> p[i];
        for (int i = 0; i < n; ++i) cin >> s[i];

        for (int i = 0; i < n; ++i) {
            long long g = __gcd(p[i], s[i]);
            a[i] = (p[i]/g) * s[i];
        }

        // Prefix GCD
        pref[0] = a[0];
        for (int i = 1; i < n; ++i) {
            pref[i] = __gcd(pref[i-1], a[i]);
        }

        // Suffix GCD
        suff[n-1] = a[n-1];
        for (int i = n-2; i >= 0; --i) {
            suff[i] = __gcd(a[i], suff[i+1]);
        }

        bool ok = true;
        for (int i = 0; i < n && ok; ++i)
            if (pref[i] != p[i]) ok = false;
        for (int i = 0; i < n && ok; ++i)
            if (suff[i] != s[i]) ok = false;

        cout << (ok ? "Yes" : "No") << '\n';
    }
    return 0;
}
