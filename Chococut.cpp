#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, K;
        cin >> n >> m >> K;
        int total = n * m;
        int maxi = 0;

        if (K == 0) {
            maxi = total;
        } else if (K > total) {
            maxi = 0;
        } else {
            // Try all horizontal cuts
            for (int i = 1; i < n; ++i) {
                int bob = i * m;
                if (bob >= K) {
                    maxi = max(maxi, total - bob);
                }
                bob = (n - i) * m;
                if (bob >= K) {
                    maxi = max(maxi, total - bob);
                }
            }

            // Try all vertical cuts
            for (int j = 1; j < m; ++j) {
                int bob = j * n;
                if (bob >= K) {
                    maxi = max(maxi, total - bob);
                }
                bob = (m - j) * n;
                if (bob >= K) {
                    maxi = max(maxi, total - bob);
                }
            }
        }

        cout << maxi << '\n';
    }

    return 0;
}
