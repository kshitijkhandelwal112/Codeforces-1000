#include <bits/stdc++.h>
#define int long long
using namespace std;
// Sorting would be one of the important things.
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n,m; cin>>n>>m;
        vector<int> b(n*m);
        int N = max(n,m),M=min(n,m); // just to make it easy to write.
        for(int i=0;i<n*m;i++) cin>>b[i];
        sort(b.begin(),b.end());
        // We want same minimum term and same maximum term to repeat in maximum subgrids
        // Case-1: Taking minimum term b[0] as first term of grid.
        int z = -1*b[0]*n*m;
        z+=b[0];//First term of grid only;
            //Taking maximum element in second cell of first row (considering N columns, M rows)
            //Second-max element in second cell of first column
        z+=(b[m*n-1]*M*(N-1));
        z+=(b[m*n-2]*(M-1));
            // z is answer corresponding to this case (and z1 for next case, we'll compare them)
        // Case-2: Taking maximum term b[n*m-1] as first term of grid.
        int z1 = b[m*n-1]*n*m;
        z1-=b[m*n-1];//First term of grid only;
        z1-=(b[0]*M*(N-1));
        z1-=(b[1]*(M-1));
        cout<<(max(z1,z))<<"\n";
    }
    return 0;
}
/* BEST SOLUTION GIVEN IN EDITORIAL (//very different syntax from what I write traditionally)
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mxn=2e5+5;
ll a[mxn];
inline void solve(){
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;++i)cin>>a[i];
	sort(a+1,a+n*m+1);
	if(n>m)swap(n,m);
	if(n==1)cout<<(m-1)*(a[n*m]-a[1])<<'\n';
	else{
		ll ans1=(n*m-1)*(a[n*m])-a[1]*(n*(m-1))-a[2]*(n-1);
		ll ans2=a[n*m]*(n*(m-1))+a[n*m-1]*(n-1)-a[1]*(n*m-1);
		cout<<max(ans1,ans2)<<'\n';
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T;cin>>T;
	for(;T--;)solve();
	return 0;
}
*/