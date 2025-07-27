#include <bits/stdc++.h>
using namespace std;

struct TestCase
{
    int n, m, q;
    vector<int> a;
    vector<int> divs;           // all divisors of m
    unordered_map<int, int> id; // divisor -> index in arrays
    vector<int> D;              // current #drops for every divisor
    vector<int> limit;          // m/g - 1 for every divisor

    void build_divisors()
    {
        for (int i = 1; 1LL * i * i <= m; ++i)
            if (m % i == 0)
            {
                divs.push_back(i);
                if (i != m / i)
                    divs.push_back(m / i);
            }
        sort(divs.begin(), divs.end());
        int d = divs.size();
        D.assign(d, 0);
        limit.resize(d);
        for (int i = 0; i < d; ++i)
        {
            id[divs[i]] = i;
            limit[i] = m / divs[i] - 1;
        }
    }

    inline void addPair(int idx, int g, int delta)
    {
        int i = idx;
        int gi = g;
        int dIdx = id[gi];
        D[dIdx] += delta;
    }

    void adjust_pair(int posL, int posR, int sign)
    {
        if (posL < 1 || posR > n)
            return;
        int vL = a[posL], vR = a[posR];
        for (int k = 0; k < (int)divs.size(); ++k)
        {
            int g = divs[k];
            if (vL % g > vR % g)
                D[k] += sign;
        }
    }

    void build_initial_D()
    {
        int d = divs.size();
        for (int i = 1; i < n; ++i)
        {
            for (int k = 0; k < d; ++k)
            {
                int g = divs[k];
                if (a[i] % g > a[i + 1] % g)
                    ++D[k];
            }
        }
    }

    void run()
    {
        build_divisors();
        build_initial_D();

        while (q--)
        {
            int type;
            cin >> type;
            if (type == 1)
            {
                int idx, x;
                cin >> idx >> x;
                // remove old contributions
                adjust_pair(idx - 1, idx, -1);
                adjust_pair(idx, idx + 1, -1);
                a[idx] = x;
                // add new contributions
                adjust_pair(idx - 1, idx, +1);
                adjust_pair(idx, idx + 1, +1);
            }
            else
            {
                int k;
                cin >> k;
                int g = std::gcd(k, m);
                int p = id[g];
                cout << (D[p] <= limit[p] ? "YES\n" : "NO\n");
            }
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        TestCase tc;
        cin >> tc.n >> tc.m >> tc.q;
        tc.a.resize(tc.n + 1); // 1-based
        for (int i = 1; i <= tc.n; ++i)
            cin >> tc.a[i];
        tc.run();
    }
    return 0;
}