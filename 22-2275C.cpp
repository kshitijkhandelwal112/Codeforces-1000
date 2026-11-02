#include <bits/stdc++.h>
#define int long long
using namespace std;
// I WROTE O(N^2), AND CONVERTING TO O(N LOG N) WAS REQUIRED, I COULDN'T DO THAT, LEARNT FROM AI
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n; cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        vector<int> l;
        for(int i=0;i<n-4;i++){
            int x = a[i]+a[i+2]-a[i+4];
            l.push_back(x);
        }
        int N = l.size();
        int ways=0;
        /* MY FIRST APPROACH
        for(int i=0;i<N;i++){
            for(int j=6;j<N-i;j+=2){
                if(l[i]==l[i+j])ways++;
            }
            for(int j=1;j<N-i;j+=2){
                if(l[i]==l[i+j])ways++;
            }
        }
            */
        // Above approach simplified in single nested loop:
        /*
        for(int i=0;i<N;i++){
            for(int j=1;j<N-i;j++){
                if(j==2 || j==4) continue;
                if(l[i]==l[i+j]) ways++;
            }
        }Still gives TLE {it's the same loop still, just number of statements decreased.}
        BINARY SEARCH TO BE USED*/
        // First use binary search to get all ways, and then eliminate forbidden ways corresponding to i+2, i+4 that I wrote earlier.
        vector<int> s(l);
        sort(s.begin(),s.end());
        // Best way: method-1, using lower_bound and upper_bound (preferred by me as I know it):
        for (int i = 0; i < N; ) {
            int lo = lower_bound(s.begin(), s.end(), s[i]) - s.begin();
            int hi = upper_bound(s.begin(), s.end(), s[i]) - s.begin();
            int c = hi - lo;
            ways += c * (c - 1) / 2;
            i = hi;   // jump to the start of the next distinct value
        }
        // Method-2: Conventional method of Binary search.
        /*
        for (int i = 0; i < N; ) {
            int j = i;
            while (j < N && s[j] == s[i]) j++;
            int c = j - i;
            ways += c * (c - 1) / 2;
            i = j;
        }
        */
        // Method-3: The shortest one:
        /*
        auto [lo, hi] = equal_range(s.begin(), s.end(), s[i]);
        int c = hi - lo;
        i = hi - s.begin();
        */

        // remove forbidden distances
        for (int i = 0; i + 2 < N; i++) if (l[i] == l[i+2]) ways--;
        for (int i = 0; i + 4 < N; i++) if (l[i] == l[i+4]) ways--;
        cout<<ways<<"\n";
    }
    return 0;
}