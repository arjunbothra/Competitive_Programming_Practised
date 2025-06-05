#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> queenpos(20, -1);
bool check(int row, int col)
{
    for (int i = 0; i < row; i++){
        int prow = i;
        int pcol = queenpos[i];
        if(pcol == col || abs(prow-row) == abs(pcol-col))
            return false;
    }
    return true;
}

int solve(int level, int n){
    if(level==n)
        return 1;

    int ans = 0;
    for (int col = 0; col < n; col++)
    {
        if(check(level, col)){
            queenpos[level] = col;
            
            ans+=solve(level + 1, n);
            queenpos[level] = -1;
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

        int N;
        cin >> N;
        cout << solve(0, N) << endl;

        return 0;
}

