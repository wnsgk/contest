#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
  	int T, test_case;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> T;
    for(test_case = 0; test_case  < T; test_case++) {
        int n;
        cin>>n;
        vector<pair<int,int>> x(n), y(n);
        for(int i = 0; i < n; i++) {
            cin>>x[i].first>>x[i].second;
            y[i].first = x[i].second;
            y[i].second = x[i].first;
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        int x1 = 0, y1 = 0;
        int cnt = 1;
        for(int i = 1; i < n; i++){
            if(x[i].first == x[i-1].first){
                cnt++;
            }
            else {
                if(cnt%2 == 1){
                    x1 = x[i-1].first;
                    break;
                }
                cnt = 1;
            }
        }
        if(x1 == 0 && cnt%2 == 1) x1 = x[n-1].first;
        cnt = 1;
        for(int i = 1; i < n; i++){
            if(y[i].first == y[i-1].first){
                cnt++;
            }
            else {
                if(cnt%2 == 1){
                    y1 = y[i-1].first;
                    break;
                }
                cnt = 1;
            }
        }
        if(y1 == 0 && cnt%2 == 1) y1 = y[n-1].first;

        if(x1 != 0 && y1 != 0){
            for(int i = 0; i < n; i++) {
                if(x[i].first == x1 && x[i].second == y1) {
                    x.erase(x.begin()+i);
                    break;
                }
            }
            for(int i = 0; i < n; i++) {
                if(y[i].first == y1 && y[i].second == x1) {
                    y.erase(y.begin()+i);
                    break;
                }
            }
        }
        long long ans = 0;
        for(int i = 1; i < n; i+=2){
            ans += x[i].second - x[i-1].second;
            ans += y[i].second - y[i-1].second;
        }

        cout << "Case #" << test_case+1 << endl;
        cout << ans << endl;
    }

    return 0;
}
