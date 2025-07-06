#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

char v[8][8];
int Qrowpos[8];

bool checker(int row, int col){
   
   for(int i=0; i<row; i++){
    int prow=i;
    int pcol=Qrowpos[i];
    if(pcol==col || abs(prow-row)==abs(pcol-col)) return false;
   }
    return true;
}

int solve(int level){
    //base case
    if(level>=8) return 1;

    //checker function
   int ans=0;

    for(int col=0; col<8; col++){
        if(v[level][col]=='*') continue;
        else{
          if(checker(level, col)) {
            Qrowpos[level]=col;
            ans+= solve(level+1);
            Qrowpos[level]=-1;
          }
        }
    }
    return ans;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        
        for (int i = 0; i < 8; i++){
            for(int j=0; j<8; j++)
            cin >> v[i][j];
        }
        memset(Qrowpos, -1, sizeof(Qrowpos));
        cout<< solve(0) << endl;

    return 0;
}

