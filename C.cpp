#include <bits/stdc++.h>
using namespace std;

class mediaNet {
public:
    static vector<int> compute(vector<int>& A) {
        int n = A.size();
        vector<pair<int, int>> val_idx;  // {val, original_index}
        for (int i = 0; i < n; ++i) val_idx.emplace_back(A[i], i);

        // Sort by bit priority: highest bit set first
        sort(val_idx.begin(), val_idx.end(), [](auto &a, auto &b) {
            for (int b = 19; b >= 0; --b) {
                bool abit = (a.first >> b) & 1;
                bool bbit = (b.first >> b) & 1;
                if (abit != bbit) return abit > bbit;
            }
            return a.second < b.second; // tie-break: original order
        });

        vector<int> Z(n);
        for (int i = 0; i < n; ++i) Z[i] = val_idx[i].first;

        vector<int> X(20);
        for (int i = 0; i < 20; ++i) {
            int bit = 1 << (19 - i);
            int j = 0;
            while (j < n && (Z[j] & bit)) ++j;
            X[i] = j;
        }

        return X;
    }
};

// DO NOT change this signature
vector<int> solution(vector<int> &A) {
    return mediaNet::compute(A);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // ✅ Correct function call
    auto X = solution(A);
    for (int i = 0; i < 20; ++i) {
        cout << X[i] << (i + 1 < 20 ? ' ' : '\n');
    }
    return 0;
}
