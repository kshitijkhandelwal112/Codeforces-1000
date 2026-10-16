#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n; cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        int maxm=a[0];
        vector<int> reqmt;
        for(int i=0;i<n;i++){
            if(a[i]>=maxm) maxm=a[i];
            else reqmt.push_back(maxm-a[i]);
        }
        if((int)reqmt.size()==0){
            cout<<0<<"\n";
            continue;
        }
        sort(reqmt.begin(),reqmt.end());
        int coins=0;
        int sum=reqmt[0];
        int z = reqmt.size();
        for(int i=0;i<z;i++){
            if(i>0) sum=reqmt[i]-reqmt[i-1];
            int m = (z-i+1)*sum;
            coins+=m;
        }
        cout<<coins<<"\n";
    }
    return 0;
}