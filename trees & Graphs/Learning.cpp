#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

class Node{
    public:
    int data;
    struct Node* left;
    struct Node *right;

    Node(int val){
        data= val;
        left=NULL;
        right = NULL;
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }
    }
    return 0;
}
