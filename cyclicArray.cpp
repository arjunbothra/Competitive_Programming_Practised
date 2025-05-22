#include<bits/stdc++.h>
using namespace std;

void f(int r, int c, int val, vector<vector<int>> &ans, int n){
    if(r==n || c==n || r<0 || c<0 || ans[r][c]!= -1)
        return;

    ans[r][c]=val--;
    //right
    while(c+1<n && ans[r][c+1]==-1)
        ans[r][++c] = val--;
    //down

    while(r+1<n && ans[r+1][c]==-1)
        ans[++r][c]=val--;
    //left

    while(c-1>0 && ans[r][c-1]==-1)
        ans[r][--c] = val--;
    //up
    while(r-1>0 && ans[r-1][c]==-1)
        ans[--r][c] = val--;

    f(r, c+1, val, ans, n);
}

    int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<vector<int>> ans(n, vector<int>(n, -1));
        f(0, 0, (n * n) - 1, ans, n);
        for (int i = 0; i < n; i++){
            for(int j=0; j<n; j++){
                cout<< ans[i][j]<< " ";
            }
            cout << endl;
        }
    }
    return 0;
}
