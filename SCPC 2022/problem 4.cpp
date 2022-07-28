#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
	  int T, test_case;

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> T;
    for(test_case = 0; test_case  < T; test_case++)
    {
        int nx, ny, xa=0, ya = 0;
        string x, y;
        cin>>nx>>ny;
        cin>>x>>y;
        
        vector<int> vx, vy;
        int prev = 0;
        for(int i = 0; i < nx; i++){
            if(x[i] == 'b'){
                vx.push_back(i-prev);
                prev = i+1;
            }
        }
        vx.push_back(nx-prev);
        prev = 0;
        for(int i = 0; i < ny; i++){
            if(y[i] == 'b'){
                vy.push_back(i-prev);
                prev = i+1;
            }
        }
        vy.push_back(ny-prev);
        if(vx.size() < vy.size()){
            cout << "Case #" << test_case+1 << endl;
		    cout<<"NO"<<endl;
            continue;
        }
        if(vy.size() == 1){
            int cnt = 0;
            for(int i = 0; i < nx; i++){
                if(x[i] == 'a') cnt++;
            }
            cout << "Case #" << test_case+1 << endl;
		    if(cnt >= vy[0])  cout << "YES" << endl;
            else cout<<"NO"<<endl;
            continue;
        }
        
        vector<int> vy2, sum(vx.size()+1);
        for(int i = 0; i < vx.size(); i++){
            sum[i+1] = sum[i] + vx[i];
        }
        int start = -1, end = -1;
        for(int i = 0; i < vy.size(); i++) {
            if(vy[i] != 0){
                if(start == -1) start = i;
                end = i;
            }
        }
        if(start == -1){
            cout << "Case #" << test_case+1 << endl;
		        cout<<"YES"<<endl;
            continue;
        }
        bool suc = false;
        for(int i = 0; i < (int)vx.size()-(int)vy.size()+1; i++){
            if(start == 0 && sum[i+1] < vy[0]) continue;
            if(start != 0 && start != (int)vy.size()-1 && vx[i+start] < vy[start]) continue;
            if(end == 0){
                suc = true;
                break;
            }
            bool tmp = true;
            for(int j = start+1; j < end; j++){
                if(vy[j] != vx[i+j]) {
                    tmp = false;
                    break;
                }
            }
            if(tmp){
                if(end == (int)vy.size()-1){
                    if(sum[vx.size()] - sum[i+end] >= vy[end]){
                        suc = true;
                        break;
                    }
                }
                else {
                    if(vx[i+end] >= vy[end]){
                        suc =  true;
                        break;
                    }
                }
            }
        }
        
        cout << "Case #" << test_case+1 << endl;
        if(suc) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
