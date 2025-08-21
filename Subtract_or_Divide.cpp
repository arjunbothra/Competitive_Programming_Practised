// #include <bits/stdc++.h>
// using namespace std;
// #define endl '\n'
// #define int long long

// // always read question carefully and prove your answer
// // Subtracting scenarios-  if n is even then = n/2-1, if n is odd then = n/2;
// // divide scenarios- divide by 2 until n isn't odd && n>1;

// int32_t main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;
//         if(n== 1){
//              cout << 1 << endl;
//              continue;
//         }
//         if(n==2){
//             cout << 2 << endl;
//             continue;
//         }

//         if (n % 2 == 1)
//         {
//             cout << (n / 2) + 1 << endl;
//             continue;
//         }

//         if (n % 2 == 0)
//         {
//             ans += (n / 2); // -2

//             int new1 = n;
//             bool flag = true;
//             while (new1 > 1)
//             {
//                 new1 = new1 / 2;
//                 // cout << new1 << " Ans:" << ans <<endl;
//                 if (new1 % 2 == 1)
//                 {
//                     flag = false;
//                     ans += (new1 / 2) + 1;
//                     break;
//                 }
//             }
//             if(flag)
//                 cout << ans + 1 << endl;
//             else cout << ans << endl;
//         }
//     }
//     return 0;
// }



#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int  long long           

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    while (T--) {
        int N; 
        cin >> N;

        int ans;
        if (N & 1) {                        // N is odd
            ans = (N + 1) / 2;
        } else {                            // N is even
            int half = N / 2;               // number of reachable evens
            ans = half + (half + 1) / 2;    // add reachable odds
        }

        cout << ans << endl;
    }
    return 0;
}
