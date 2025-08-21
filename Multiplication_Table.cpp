#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//always read question carefully and prove your answer
bool checker(int mid, int n){
    int cnt = 0;
    for (int i = 1; i <= min(n, mid); ++i)
    {   
        cnt += min(n, mid / i);
    }
    return cnt >= (n*n +1)/2;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

    
        int n;
        cin >> n;
        int low=1, high=n*n;
        int ans = -1;
        while (low <= high)
        {
            int mid = (low + high) >> 1;
            if(checker(mid, n)){
                high = mid - 1;
                ans = mid;
            }
            else
                low = mid + 1;
        }

        cout << ans << endl;

        return 0;
}




#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//always read question carefully and prove your answer

vector<int> dijkstra(int src, int final, int n, vector<vector<pair<int, int>>> & adj){
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, src});
        dist[src]=0;

        //dijkstra main
        while(!pq.empty()){
            auto [cost, node] = pq.top();
            pq.pop();

            if(cost > dist[node])
                continue;
            
            for(auto it: adj[node]){
                int w = it.second;
                int child =it.first;
                    if(w+dist[node] < dist[child]){
                        dist[child] = w + dist[node];
                        pq.push({dist[child], child});
                    }
            }
        }
        return dist;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

        int n, m;
        cin >> n >> m;
        vector<vector<pair<int, int>>> adj(n);

        for (int i = 0; i < m; ++i) {
            int u, v, w; 
            cin >> u >> v >> w;
            u--;
            v--;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
            // int u = edges[i][0];
            // int v = edges[i][1];
            // int c = edges[i][2];
        }


    
    return 0;
}

