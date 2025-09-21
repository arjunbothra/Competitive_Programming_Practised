#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//always read question carefully and prove your answer


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

   int n;
   cin >> n;
   vector<int> a;
   while (n != 0)
   {
       int last = n % 10;
       n = n / 10;
       a.push_back(last);
   }

   if(a.size()==1)
       cout << a[0] << endl;
    
   cout << a[0] << a[1] << endl;
   return 0;
}

