#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n,q; cin>>n>>q;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        a[n-1]=max(a[n-1],b[n-1]);
        for(int i=n-2;i>=0;i--){
            a[i]=max({a[i],a[i+1],b[i]});
        }
        vector<int> pfsum(n);
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=a[i];
            pfsum[i]=sum;
        }
        while(q--){
            int l,r; cin>>l>>r;
            l--;r--;
            if(l==0){cout<<pfsum[r]<<" ";continue;}
            cout<<pfsum[r]-pfsum[l-1]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}