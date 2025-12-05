#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;

// always read question carefully and prove your answer



// NUMBER THEORY AND MATHS
//  1) SPF
//  2) Prime Factorisation (Sieve of Eratosthenes)
//  3) Factorsiation
//  4) Unique Prime Factors
//  5) Modular Arithmetic
//  6) Binary Exponential in TC- log2 pwer;
//  7) GCD
//  8) Euclidean Algorithm


int EuclideanAlgorithm(int a, int b){
    while(b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int binaryExponential(int a, int b){    //Binary Exponential 
    int res= 1;
    while(b>0){
        if(b&1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int32_t main(){
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
    }
    return 0;
}

