// #include<bits/stdc++.h>
// using namespace std;
// #define endl '\n'
// #define int long long

// //always read question carefully and prove your answer


// int32_t main()
// {
//     // Fast I/O
//     std::ios_base::sync_with_stdio(false);
//     std::cin.tie(NULL);

//     int test_cases;
//     std::cin >> test_cases;
//     while (test_cases--)
//     {
//         int num_points;
//         std::string target_pattern;
//         std::cin >> num_points >> target_pattern;

//         std::vector<int> generated_pattern(num_points, 0);

//         for (int i = 1; i + 1 < num_points; i++)
//         {
//             if (target_pattern[i - 1] == '1' && target_pattern[i] == '1' && target_pattern[i + 1] == '1')
//             {
//                 generated_pattern[i - 1] = 1;
//                 generated_pattern[i] = 1;
//                 generated_pattern[i + 1] = 1;
//             }
//         }

//         bool is_possible = true;
//         for (int i = 0; i < num_points; i++)
//         {
//             bool target_is_one = (target_pattern[i] == '1');
//             bool generated_is_one = (generated_pattern[i] == 1);

//             if (target_is_one != generated_is_one)
//             {
//                 is_possible = false;
//                 break;
//             }
//         }
        
//         if(is_possible)
//             cout << "Yes" << endl;
//         else
//             cout << "No" << endl;
//     }
//     return 0;
// }



#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//always read question carefully and prove your answer


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        string v;
        cin >> v;
        int i = 0;
        bool possible = true;

        
        while (i < n)
        {
            if(v[i] == '1'){
                int cnt = 0;
                while (i < n && v[i] == '1')
                {
                    cnt++;
                    i++;
                }
                if(cnt <3){
                    possible = false;
                }
            }
            i++;
        }

    

        // if (v[n - 1] == '1' && v[n-2] !='1'){
        //     possible = false;
        // }

            if (possible)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
    }
    return 0;
}

