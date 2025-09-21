#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//always read question carefully and prove your answer


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

    int t;
    cin >> t;
    while (t--){
        int w, h;
        cin >> w >> h;
        int ans = 0;

        int h1;
        cin >> h1;

        int p0, pn;

        for (int i = 0; i < h1; ++i)
        {
            int a;
            cin >> a;
            if (i == 0)
                p0 = a;
            if(i== h1-1)
                pn = a;
        }

        ans = max(ans, (pn - p0) * h);

        int h2;
        cin >> h2;

        for (int i = 0; i < h2; ++i)
        {
            int a;
            cin >> a;
            if (i == 0)
                p0 = a;
            if(i== h2-1)
                pn = a;
        }

        ans = max(ans, (pn - p0) * h);

        int w1;
        cin >> w1;

        for (int i = 0; i < w1; ++i)
        {
            int a;
            cin >> a;
            if (i == 0)
                p0 = a;
            if(i== w1-1)
                pn = a;
        }

        ans = max(ans, (pn - p0) * w);

        int w2;
        cin >> w2;

         for (int i = 0; i < w2; ++i)
        {
            int a;
            cin >> a;
            if (i == 0)
                p0 = a;
            if(i== w2-1)
                pn = a;
        }
        
        ans = max(ans, (pn - p0) * w);
        cout << ans << endl;
    }

    
    return 0;
}

