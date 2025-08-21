#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

// always read question carefully and prove your answer



int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, Q;
    cin >> a >> b >> Q;
    vector<int> shrines(a+2), temples(b+2);
    for (int i = 1; i < a+1; i++)
    {
        cin >> shrines[i];
    }

    for (int i = 1; i < b+1; ++i)
    {
        cin >> temples[i];
    }
    shrines[0] = temples[0]= -1e17;
    shrines[a + 1] = temples[b + 1] = 1e17;
    sort(shrines.begin(), shrines.end());
    sort(temples.begin(), temples.end());


    vector<int> ans;
    while (Q--)
    {
        int x;
        cin >> x;

        int ls = *(--upper_bound(shrines.begin(), shrines.end(), x));
        int lt = *(--upper_bound(temples.begin(), temples.end(), x));
        int rs = *lower_bound(shrines.begin(), shrines.end(), x);
        int rt = *lower_bound(temples.begin(), temples.end(), x);

        int total = LLONG_MAX;
        total = min(total, x- min(lt, ls));  //left
        total = min(total, rt - ls + min(x - ls, rt - x)); // L shrine R temple
        total = min(total, rs - lt + min(x - lt, rs - x)); // R shrine L temple
        total = min(total, max(rt, rs) - x);

        ans.push_back(total);
    }

    for (auto it : ans)
        cout << it << endl;
    return 0;
}
