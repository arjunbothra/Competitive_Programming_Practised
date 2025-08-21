#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//always read question carefully and prove your answer

string s;
void solve(int i, string curr, vector<string> &ans, vector<int>& freq)
{
    
    if(i == s.size()){
        ans.push_back(curr);
        return;
    }

    for (int j = 0; j < 26; ++j){
        if(freq[j]>0){
            freq[j]--;
            solve(i + 1, curr + char(j + 'a'), ans, freq);
            freq[j]++;
        }
    }
}


/*          aabac
            /  \
           a    abac
          /      / \
         a      a  bac

*/          


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    int n = s.size();
    vector<string> ans;
    string curr;
    vector<int> freq(26, 0);
    for (int i = 0; i < s.size(); ++i)
    {
        freq[s[i]-'a']++;
    }
    
    solve(0, curr, ans, freq);
    
    cout << ans.size() << endl;
    for(auto it: ans)
        cout << it << endl;

    return 0;
}

