#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//always read question carefully and prove your answer
int power(int a, int b){
    int res = 1;

    while(b>0){
        if(b&1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<int>> a(200001);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)   //prime factorise every number
    {
        int v;
        cin >> v;

        for (int j = 2; j * j <=v ; ++j){
            int count = 0;
            while (v % j == 0){
                v /= j;
                count++;
            }
            if(count > 0)
            a[j].push_back(count);
        }
        if(v>1) a[v].push_back(1);
    }

    int ans = 1;
    /*
    loop idea: if size==(n-1) then take the 0 index, if size(n) then take index 1 
    because 2nd lowest pow needs to be taken, is size<n-1 means 2nd lowest power is 0 so nothing to be donw
    */
    for (int i = 2; i < 200001; ++i){
        sort(a[i].begin(), a[i].end());
        if(a[i].size() == n-1)
            ans *= pow(i, a[i][0]);
        else if(a[i].size() == n)
            ans *= pow(i, a[i][1]);
    }

    cout << ans << endl;
    return 0;
}

