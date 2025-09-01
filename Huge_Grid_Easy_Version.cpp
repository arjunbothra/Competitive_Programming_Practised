#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//always read question carefully and prove your answer


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

    int test_cases;
    cin >> test_cases;
    while (test_cases--){
        int length;
        cin >> length;
        string pattern;
        cin >> pattern;

        int total_score = 0;
        if (length == 1) {
            total_score = (pattern[0] - '0');
        } else {
            total_score += 2 * (pattern[0] - '0');
            total_score += 2 * (pattern[length - 1] - '0');
            for (int i = 1; i <= length - 2; ++i) {
                total_score += 3 * (pattern[i] - '0');
            }
        }
        cout << total_score << endl;
    }
    
    return 0;
}