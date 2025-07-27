    #include<bits/stdc++.h>
    using namespace std;
    #define endl '\n'
    #define int long long
    
    //always read question carefully and prove your answer
    int dfs(int i, int j, int& sum, vector<vector<int>>& grid , vector<vector<int>>& vis){
        int delrow[]= {1, 0, -1, 0};
        int delcol[]= {0, 1, 0, -1};
        vis[i][j] = 1;
        sum+= grid[i][j] ;
        for(int x=0; x<4; x++){
            int newx= i+ delrow[x];
            int newy= j+ delcol[x];
            if(newx>=0 && newx< grid.size() && newy<grid[0].size() && newy>= 0 && !vis[newx][newy] && grid[newx][newy]!=0){
                sum+= dfs(newx, newy, sum, grid, vis);
            }
        }
        return sum;
    }
    
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        int cnt=0;
        
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                int sum=0;
                if(!vis[i][j] && grid[i][j]!= 0){
                    sum = dfs(i, j, sum,  grid, vis);
                }
                if(sum % k == 0) cnt++;
            }
        }
        return cnt;
    }
    
    signed main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
       
    
       
            int n, m, k;
            cin >> n >> m >> k;
            vector<vector<int>> v;
            for (int i = 0; i < n; i++){
                for (int j = 0; j < m; ++j){
                    cin >> v[i][j];
                }
        }

        cout << countIslands(v, k) << endl;
        return 0;
    }
    
    
    


    