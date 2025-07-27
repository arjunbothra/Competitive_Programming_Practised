#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int &x : A) cin >> x;
        sort(A.rbegin(), A.rend());

        vector<int> pre(N + 1, 0);
        for (int i = 0; i < N; ++i) pre[i + 1] = pre[i] + A[i];

        vector<int> ans(2 * N + 1, 0);

        for (int K = 1; K <= 2 * N; ++K) {
            int res = 0;
            // t in [max(0, (K+1)/2), min(K, N)]
            int t1 = K / 2;
            int t2 = min(K, N);
            for (int t = t1; t <= t2; ++t) {
                int j = K - t;
                if (j < 0 || j > t) continue;
                int bonus = j * (2 * t - j - 1) / 2;
                int sum = pre[t] + bonus;
                res = max(res, sum);
            }
            cout << res << " \n"[K == 2 * N];
        }
    }
    return 0;
}