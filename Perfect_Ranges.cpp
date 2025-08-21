#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;                         
    cin >> T;
    while (T--) {
        int N;                      
        cin >> N;

        vector<int> A(N + 1), B(N + 1);
        for (int i = 1; i <= N; ++i) cin >> A[i];
        for (int i = 1; i <= N; ++i) cin >> B[i];

       
        vector<int> low(N + 1), high(N + 1);
        for (int i = 1; i <= N; ++i) {
            low[i]  = min(A[i], B[i]);
            high[i] = max(A[i], B[i]);
        }

        long long answer = 1;        
        int bestLow = 1, bestHigh = 1;

        for (int i = 2; i <= N; ++i) {
            int nextLow  = i;       
            int nextHigh = i;


            if (low[i - 1]  < low[i])   nextLow  = min(nextLow,  bestLow);
            if (high[i - 1] < low[i])   nextLow  = min(nextLow,  bestHigh);
            if (low[i - 1]  < high[i])  nextHigh = min(nextHigh, bestLow);
            if (high[i - 1] < high[i])  nextHigh = min(nextHigh, bestHigh);

            bestLow  = nextLow;
            bestHigh = nextHigh;

            int earliest = min(bestLow, bestHigh);
            answer += (i - earliest + 1);
        }

        cout << answer << endl;
    }
    return 0;
}
