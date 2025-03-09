#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--){
        int n, a, b;
        cin >> n >> a >> b;
        if(n-(a+b)>=2 || a==n && a==b) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}

