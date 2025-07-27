#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

// always read question carefully and prove your answer
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> v;
    set<pair<int, int>> st;
    map<pair<int, int>, pair<int, int>> mpp;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
        st.insert({x, y});
    }

    
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i)
    { // v vector
        for (int j = 0; j < 4; ++j)
        {
            int nx = v[i].first + dx[j];
            int ny = v[i].second + dy[j];

            if (st.find({nx, ny}) == st.end())
            {
                mpp[{v[i].first, v[i].second}] = {nx, ny};
                q.push({v[i].first, v[i].second}); //{x, y};
                break;
            }
        }
    } // pushing with dist 1
    // TC- N*4*logn - NlogN;

    
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (!st.count({nx, ny}) || mpp.count({nx, ny}))
                continue;

            q.push({nx, ny});
            mpp[{nx, ny}] = mpp[{x, y}];
        }
    }

    for (auto it : v)
    {
        auto points = mpp[it];
        cout << points.first << " " << points.second << endl;
    }

    return 0;
}
