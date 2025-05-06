#include<bits/stdc++.h>
using namespace std;
int R, C;
vector<vector<int>> ans, A, B;

void summation(vector<vector<int>>&A, vector<vector<int>> &B, int i, int j){
    if(i>=R)
        return;
    if(j>=C) {
        summation(A, B, i + 1, 0);
        return;
    }
    ans[i][j] = A[i][j] + B[i][j];
    summation(A, B, i, j + 1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;
    A.resize(R, vector<int>(C)), B.resize(R, vector<int>(C)), ans.resize(R, vector<int>(C));

    for (int i = 0; i<R; i++){
        for (int j = 0; j < C; j++)
            cin >> A[i][j];
        
    }

    for (int i = 0; i<R; i++){
        for (int j = 0; j < C; j++)
            cin >> B[i][j];
        
    }
    
    summation(A, B, 0, 0);

    for (int i = 0; i<R; i++){
        for (int j = 0; j < C; j++)
           cout<< ans[i][j]<< " ";
        
        cout << endl;
    }

    return 0;
}

