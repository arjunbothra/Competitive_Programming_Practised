#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//always read question carefully and prove your answer

// int dfs(int curr, int parent, vector<vector<int>>& adj)


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

    
        int n;
        cin >> n;
        vector<int> indeg(n);
        for (int i = 0; i < n-1; i++){
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            indeg[u]++;
            indeg[v]++;
        }

        int count2 = 0, count1 = 0, countGreater2 = 0;
        for (int i = 0; i < n; ++i)
        {
            if(indeg[i]==1)
                count1++;
            if(indeg[i]==2)
                count2++;
            if(indeg[i]>2)
                countGreater2++;
        }

        if(count2 == n-2 && count1 == 2){
            cout << "Yes" << endl;
            cout << 1 << endl;

            int first = -1, second = -1;
            for (int i = 0; i < n; ++i){    
                if(first == -1 && indeg[i]==1){
                    first = i;
                }
                else if(second == -1 && indeg[i]==1 ) {
                    second = i;
                    break;
                }
            }

            cout << first+1 << " " << second+1 << endl;
        }

        else if (countGreater2 == 1){
            cout << "Yes" << endl;
            int cnt = 0;
            int node = -1;
            for (int i = 0; i < n; ++i){
                if(indeg[i] > 2) {
                    node = i;
                }
                if(indeg[i]==1)
                    cnt++;
            }

            cout << cnt << endl;
            for (int i = 0; i < n; ++i)
            {
                if(indeg[i] == 1){
                    cout << node+1 << " " << i + 1 << endl;
                }
            }
        }

        else
            cout << "No" << endl;

            return 0;
}

