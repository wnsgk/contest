#include <bits/stdc++.h>

using namespace std;

int Answer;
long long mod = 1000000007;

long long pow_(long long x, long long p){
    if(p == 1) return x;
    long long a = pow_(x, p/2);
    a *= a;
    a %= mod;
    if(p%2 == 1) return a*x%mod;
    else return a;
}

long long nCk(int n, int k){
    long long x = 1, y = 1, z = 1;
    for(int i = 1; i <= n; i++) {
        x *= i;
        x %= mod;
    }
    for(int i = 1; i <= k; i++) {
        y *= i;
        y %= mod;
    }
    for(int i = 1; i <= n-k; i++) {
        z *= i;
        z %= mod;
    }
    y *= z;
    y %= mod;
    long long a = pow_(y, mod-2);
    x *= a;
    return x%mod;
}

int main(int argc, char** argv)
{
	  int T, test_case;

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> T;
    for(test_case = 0; test_case  < T; test_case++)
    {
        long long n, k;
        cin>>n>>k;
        vector<long long> v(n+1), sum;
        for(int i = 1; i <= n; i++) {
            cin>>v[i];
            v[i] += v[i-1];
        }
        if(v[n] % k != 0){
            cout << "Case #" << test_case+1 << endl;
            cout << 0 << endl;
            continue;            
        }        
        if(k == 1) {
            cout << "Case #" << test_case+1 << endl;
            cout << 1 << endl;
            continue; 
        }
        if(v[n] < 0){
            for(int i = 1; i <= n; i++) v[i] = -v[i];         
        }
        long long x = v[n]/k;
        if(x == 0){
            int cnt = 0;
            for(int i = 1; i <= n; i++) {
                if(v[i] == 0) cnt++;
            }
            cout << "Case #" << test_case+1 << endl;
            if(cnt >= k) cout << nCk(cnt-1, k-1) << endl;
            else cout << 0 << endl;
            continue; 
        }
        for(int i = 1; i <= n; i++) {
            if(v[i] % x == 0) sum.push_back(v[i]/x);
        }

        long long tot = 0;
        vector<long long> ret(k+1);
        
        for(int i = sum.size()-1; i >= 0; i--) {
            if(sum[i] >= k || sum[i] <= 0) continue;
            else if(sum[i] == k-1) ret[sum[i]]++;
            else if(sum[i] == 1) {
                tot += ret[2];
                tot %= mod;
            }
            else {
                ret[sum[i]] += ret[sum[i]+1];
                ret[sum[i]] %= mod;
            }
            
        }
        if(k == 2) tot = ret[1];

        cout << "Case #" << test_case+1 << endl;
        cout << tot << endl;
    }

    return 0;
}
