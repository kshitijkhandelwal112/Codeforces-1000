#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k; cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        vector<int> xyz(n);
        for(int i=0;i<n;i++){
            xyz[i]=k-((a[i]%k)!=0 ? (a[i]%k):k);
        }
        auto z = min_element(xyz.begin(),xyz.end());
        if(k!=4 || (*z)==0)cout<<*z<<"\n";
        else{
            int two=0;
            for(int i=0;i<n;i++){
                if(xyz[i]==2)two++;
            }
            if(two>1)cout<<0<<"\n";
            else if(two==1) cout<<1<<"\n";
            else if((*z)==1) cout<<(*z)<<"\n";// Before I tried to accomodate this in || with k!=4, as I included (*z)==0
            // but if with *z=1, there are more than two, 2's then answer would be 0 and not 1. So that case has been dealt separately above.
            else if((*z)==3) cout<<2<<"\n";
        }
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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (auto &x : a) cin >> x;

        if (k != 4) {
            // k is prime (2, 3, or 5): cost to fix one element covers it
            int best = k;
            for (int x : a) best = min(best, (k - x % k) % k);
            cout << best << "\n";
            continue;
        }

        // k == 4: track existing "power of 2" supply in the product
        int cnt4 = 0, cnt2 = 0, bestSingle = 4;
        for (int x : a) {
            int r = x % 4;
            if (r == 0) cnt4++;
            else if (r == 2) cnt2++;
            bestSingle = min(bestSingle, (4 - r) % 4);
        }

        int ans;
        if (cnt4 > 0 || cnt2 >= 2) ans = 0;      // already >= 2 factors of 2 total
        else if (cnt2 == 1) ans = 1;              // need one more factor of 2
        else ans = min(bestSingle, 2);            // no factor of 2 yet: single push vs two pushes

        cout << ans << "\n";
    }
}
*/