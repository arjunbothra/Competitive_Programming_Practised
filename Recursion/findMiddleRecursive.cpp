#include<bits/stdc++.h>
using namespace std;


void deleteMiddle(stack<int> &v, int middle){
    if(middle==1){
        v.pop();
        return;
    }
    int k=v.top();
    v.pop();
    deleteMiddle(v, middle-1);
    v.push(k);
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        stack<int> v;
        for (int i = 0; i<n; i++){
            int x;
            cin >> x;
            v.push(x);
        }

        int middle = n / 2 + 1;
        deleteMiddle(v, middle);
        while (!v.empty())
        {
            cout << v.top() << " ";
            v.pop();
        }
    }
    return 0;
}