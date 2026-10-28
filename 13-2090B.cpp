#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n,m; cin>>n>>m;
        vector<string> a(n);
        vector<bool> one(m);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        bool errored=false;
        for(int j=0;j<m && errored==false;j++){
            if(a[0][j]=='1'){
                one[j]=true;
                for(int i=0;i<n;i++){
                    if(a[i][j]=='0') one[j]=false;
                    if(a[i][j]=='1' && one[j]==false){
                        string str(j+1,'1');
                        if(a[i].substr(0,j+1)==str);
                        else {errored=true;break;}
                    }
                }
            }else{
                for(int i=0;i<n;i++){
                    if(a[i][j]=='1'){
                        string str(j+1,'1');
                        if(a[i].substr(0,j+1)==str);
                        else {errored=true;break;}
                    }
                }
            }
        }
        if(errored==true)cout<<"NO\n";
        else cout<<"YES\n";

    }
    return 0;
}
/* BEST SOLUTION GIVEN BY CLAUDE
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> a(n);
        for (auto &row : a) cin >> row;

        // NOW MAIN LOGIC ENTERS: (same thing done as mine, but very different management)
        // L[i][j]: a[i][0..j] are all '1'
        // U[i][j]: a[0..i][j] are all '1'
        vector<vector<bool>> L(n, vector<bool>(m, false)), U = L;
        bool ok = true;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == '1') {
                    L[i][j] = (j == 0) || L[i][j - 1];
                    U[i][j] = (i == 0) || U[i - 1][j];
                    if (!L[i][j] && !U[i][j]) ok = false;
                }
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}
*/