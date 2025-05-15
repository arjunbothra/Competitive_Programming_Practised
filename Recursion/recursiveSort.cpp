#include<bits/stdc++.h>
using namespace std;

void insert(vector<int> &v, int temp){
    if(v.size()==0 || v[v.size()-1]< temp){
        v.push_back(temp);
        return;
    }
    int k = v.back();
    v.pop_back();
    insert(v, temp);
    v.push_back(k);
    return;
}

void recursivesort(vector<int> &v){
    if(v.size()<=1) return ;
    int temp = v.back();
    v.pop_back();
    recursivesort(v);
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
        vector<int> v(n);
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }

        recursivesort(v);
        for (auto i : v)
        {
            cout << i << " ";
        }
    }
    return 0;
}