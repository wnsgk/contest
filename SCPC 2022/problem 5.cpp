#include <bits/stdc++.h>

using namespace std;

char v[2000][2000];
int s[2001][2001], vv[2000][2000], vvr[2000][2000], sharp[2000][2000], sharpr[2000][2000];

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
        memset(sharpr, 0, sizeof(sharpr));
        memset(vv, 0, sizeof(vv));
        memset(vvr, 0, sizeof(vvr));
        memset(sharp, 0, sizeof(sharp));
        memset(s, 0, sizeof(s));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++){
                cin>>v[i][j];
            }
        }
        for(int i = n-1; i >= 0; i--){
            for(int j = 1; j <= n; j++) {
                s[i][j] = s[i+1][j] + s[i][j-1] - s[i+1][j-1];
                if(v[i][j-1] == '#') s[i][j]++;
            }
        }
        for(int i = n-2; i >= 0; i--) {
            if(v[n-1][i] == '#') sharp[n-1][i]++;
            for(int j = n-2; j >= 0; j--) {
                sharp[j][i] = sharp[j+1][i];
                vv[j][i] = vv[j+1][i];
                if(v[j][i] == '#') {
                    sharp[j][i]++;
                    vv[j][i] = n-j - sharp[j][i];
                }
            }
        }
        for(int i = n-1; i >= 0; i--) {
            for(int j = n-2; j >= 0; j--) {
                if(vv[i][j] == 0) continue;
                if(v[i][j] == '#') vv[i][j] += vv[i][j+1];
                else if(i != n-1) vv[i][j] = vv[i+1][j];
            }
        }
        for(int i = n-2; i >= 0; i--) {
            if(v[i][n-1] == '#') sharpr[i][n-1]++;
            for(int j = n-2; j >= 0; j--) {
                sharpr[i][j] = sharpr[i][j+1];
                vvr[i][j] = vvr[i][j+1];
                if(v[i][j] == '#') {
                    sharpr[i][j]++;
                    vvr[i][j] = n-j - sharpr[i][j];
                }
            }
        }
        for(int j = n-1; j >= 0; j--) {
            for(int i = n-2; i >= 0; i--) {
                if(vvr[i][j] == 0) continue;
                if(v[i][j] == '#') vvr[i][j] += vvr[i+1][j];
                else if(j != n-1) vvr[i][j] = vvr[i][j+1];
            }
        }

        long long ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++){
                if(v[i][j] == '#') {
                    continue;
                }
                int tmp = vv[i][j] + vvr[i][j] + (n-1-i)*j - s[i+1][j];
                ans += tmp;
            }
        }

        cout << "Case #" << test_case+1 << endl;
        cout << ans << endl;
    }

    return 0;
}
