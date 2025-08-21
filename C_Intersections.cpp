#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

// always read question carefully and prove your answer

int newArr(int low, int mid, int high, vector<int> &pos)
{
    vector<int> temp;
    int cnt = 0;
    int right = mid + 1, left = low;
    while (left <= mid && right <= high)
    {
        if (pos[left] <= pos[right])
        {
            temp.push_back(pos[left]);
            left++;
        }
        else
        {
            temp.push_back(pos[right]);
            right++;
            cnt += (mid - left) + 1;
        }
    }

    while (left <= mid)
    {
        temp.push_back(pos[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(pos[right]);
        right++;
    }

    int j = 0;
    for (int i = low; i <= high; ++i)
    {
        pos[i] = temp[j];
        j++;
    }

    return cnt;
}

int merge(int low, int high, vector<int> &pos)
{
    if (low >= high)
        return 0;

    int cnt = 0;
    int mid = (low + high) / 2;
    cnt += merge(low, mid, pos);
    cnt += merge(mid + 1, high, pos);
    cnt += newArr(low, mid, high, pos);
    return cnt;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        map<int, int> mpp;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            mpp[a[i]] = i;
        }

        for (int i = 0; i < n; ++i)
            cin >> b[i];

        vector<int> pos(n);
        for (int i = 0; i < n; ++i)
        {
            pos[i] = mpp[b[i]];
        }

        // for (auto it : mpp)
        //     cout << it.second << " ";
        // cout << endl;

        // for(auto it: pos)
        //     cout << it << " ";
        // cout << endl;

        auto ans = merge(0, n - 1, pos);

        cout << ans << endl;
    }
    return 0;
}
