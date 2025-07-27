#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//always read question carefully and prove your answer
int delrow[]= {2, 2, -2, -2, 1, -1, 1, -1};
int delcol[] = {1, -1, 1, -1, 2, 2, -2, -2};

int dijkstra(int i, int j, int di, int dj){
    vector<vector<int>> dist(8, vector<int>(8, LLONG_MAX));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    pq.push({0,{i, j}}); //push source with cost 0;

    // dijkstra main
    while (!pq.empty())
    {
        auto [cost, innerpair] = pq.top();
        auto [x, y] = innerpair;
        pq.pop();

        if(x== di && y== dj)
            return cost;

        if (cost > dist[x][y])
            continue;

        for (int i = 0; i < 8; ++i)
        {
            int newx = x + delrow[i];
            int newy = y + delcol[i];
            int eC = (x*newx) + (y*newy);
            if (newx>=0 && newx<8 && newy>=0 && newy<8 && eC + cost < dist[newx][newy])
            {
                dist[newx][newy] = eC + cost;
                pq.push({eC + cost, {newx, newy}});
            }
        }
        }
        return -1;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

        int i, j, di, dj;
        while(cin >> i >> j >> di >> dj) {
            int ans = dijkstra(i, j, di, dj);
            cout << ans << endl;
    }

        return 0;
}

