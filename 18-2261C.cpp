#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;cin>>n;
        vector<int> a(n);
        int odd=0;
        for(int i=0;i<n;i++){cin>>a[i];if(a[i]%2!=0) odd++;}
        if(n==1){cout<<"Moggity\n";continue;}
        if(odd%2==0)cout<<"Moggity\n";
        else{
            if(odd==1 && n==2)cout<<"Larpity\n";
            else if(odd==3 && n==3)cout<<"Larpity\n"; //This line required viewing the editorial.
            else cout<<"Moggity\n";
        }
    }
    return 0;
}