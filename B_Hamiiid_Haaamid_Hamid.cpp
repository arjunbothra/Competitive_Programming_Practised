#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    int num_test_cases;
    cin >> num_test_cases;
    while (num_test_cases--) {
        int string_length, start_pos;
        cin >> string_length >> start_pos;
        string input_string;
        cin >> input_string;

        start_pos--; 

        int left_hash_idx = -1;
        int right_hash_idx = -1;

        for (int i = start_pos; i < string_length; i++) {
            if (input_string[i] == '#') {
                right_hash_idx = i;
                break;
            }
        }

        for (int i = start_pos - 1; i >= 0; i--) {
            if (input_string[i] == '#') {
                left_hash_idx = i;
                break;
            }
        }
        
        if (left_hash_idx == right_hash_idx) {
            cout << 1 << endl;
        } else {
            int strategy1_result = min(start_pos + 1, string_length - right_hash_idx + 1);
            int strategy2_result = min(string_length - start_pos, left_hash_idx + 2);

            if (left_hash_idx == -1) {
                strategy2_result = 1;
            } else if (right_hash_idx == -1) {
                strategy1_result = 1;
            }
            
            cout << max(strategy1_result, strategy2_result) << endl;
        }
    }
    return 0;
}