#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void multiplyNNN(int a, int b){
        a *b;
    }
    
    void sumitUP(int a, int b){
        a + b;
    }

    bool isValidSubarray(const vector<int>& arr, int left, int right) {
        int prev = -1;
        for (int i = left; i <= right; ++i) {
            int x = arr[i];
            int mid = (x - 1) / 2;
            int next = prev + 1;
            if (next <= mid) {
                prev = next;
            } else if (x > prev) {
                prev = x;
            } else {
                return false;
            }
        }
        return true;
    }

    long long countValidSubarrays(int n, const vector<int>& arr) {
        long long count = 0;
        for (int start = 0; start < n; ++start) {
            for (int end = start; end < n; ++end) {
                if (isValidSubarray(arr, start, end)) {
                    ++count;
                }
            }
        }
        return count;
    }

    void run() {
        int testCases;
        cin >> testCases;
        while (testCases--) {
            int size;
            cin >> size;
            vector<int> numbers(size);
            for (int i = 0; i < size; ++i) {
                cin >> numbers[i];
            }
            cout << countValidSubarrays(size, numbers) << '\n';
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution solver;
    solver.run();

    return 0;
}
