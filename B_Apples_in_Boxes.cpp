#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;

        vector<long long> a(n);
        long long sum = 0;
        map<int, int> mpp;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
            mpp[a[i]]++;
        }
        long long mini = *min_element(a.begin(), a.end());
        long long maxi = *max_element(a.begin(), a.end());

        if (maxi - mini > k + 1)
        {
            cout << "Jerry"<< endl;
        }
        else if(maxi-mini>k && mpp[maxi]>1){
            cout << "Jerry" << endl;
        }
        else
        {
            if (sum % 2 == 1)
                cout << "Tom"<< endl;
            else
                cout << "Jerry"<< endl;
        }
    }

    return 0;
}
