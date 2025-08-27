#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

// always read question carefully and prove your answer


vector<int> uniquePrimeFactors(int n)
{
    vector<int> ans;

    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            ans.push_back(i);
            while (n % i == 0)
            {
                n /= i;
            }
        }
    }

    if (n > 1)
        ans.push_back(n);
    return ans;
}


vector<int> primeFactors(int n){
    vector<int> ans;

    for (int i = 2; i * i <= n; ++i){
        while (n%i == 0){
            ans.push_back(i);
            n /= i;
        }
    }
    if(n>1)
        ans.push_back(n);
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 1e12;
    auto an2 = primeFactors(n);
    auto ana2 = uniquePrimeFactors(n);
    for (auto it : an2)
        cout << it << " ";
    cout << endl;
    for(auto it: ana2)
        cout << it << " ";
    
    return 0;
}


