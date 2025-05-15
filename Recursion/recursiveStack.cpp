#include<bits/stdc++.h>
using namespace std;

void insert(stack<int> &v, int temp){
    if(v.empty() || v.top()< temp){
        v.push(temp);
        return;
    }
    int k = v.top();
    v.pop();
    insert(v, temp);
    v.push(k);
    return;
}

void sortStack(stack<int> &v){
    if(v.size()<=1) return ;
    int temp = v.top();
    v.pop();
    sortStack(v);
    insert(v, temp);
    return ;
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

        sortStack(v);
        while (!v.empty())
        {
            cout << v.top() << " ";
            v.pop();
        }
    }
    return 0;
}