#include <bits/stdc++.h>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
  int T, test_case;

  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
    int n;
    cin>>n;
    vector<pair<pair<long long, long long>, int>> v(n+1);
    for(int i = 1; i <= n; i++) cin>>v[i].first.second;
    for(int i = 1; i <= n; i++) cin>>v[i].first.first;
    for(int i = 1; i <= n; i++) v[i].second = i;
    vector<pair<pair<long long, long long>, int>> v1(v);
    vector<int> c(n+1);
    sort(v1.begin(), v1.end());
    for(int i = 1; i <= n; i++){
      c[v1[i].second] = i;  
    }
    long long ret = 0;
    	
		for(int i = 1; i <= n; i++){
        if(c[v[i].second] == i) continue;
        long long ans = 0;
        int cnt = 0;
        int j = i;
        int s = v[i].first.second;
        int e = 0;
        while(1){
          cnt++;
          int next = c[v[j].second];
          ans += abs(v[j].first.second - v[next].first.second);
          e = v[next].first.second;
          v[j] = v1[j];
          if(next == i) break;
          j = next;
        }
        ans += abs(s - e);
        ret += ans;
    }
      
		cout << "Case #" << test_case+1 << endl;
		cout << ret << endl;
	}

	return 0;
}
