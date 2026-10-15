#include <bits/stdc++.h>
using namespace std;
vector<int> permute3(int n){
    vector<int> b;
    set<int> x{1,2,3,4};
    x.erase(n);
    for(int i : x){
        for(int j : x){
            for(int k : x){
                if(i!=j && j!=k && i!=k) b.push_back(100*i + 10*j + k);
            }
        }
    }
    return b;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--){
        int n,j,k; cin>>n>>j>>k;
        if(n==12){
            if(j==k) cout<<"2A0B\n";
            else cout<<"0A2B\n";
        }
        else if(n==123){
            vector<int> g = permute3(4);
            int x = g[j-1], y=g[k-1];
            int a=0;
            for(int i=0;i<3;i++){
                if(x%10==y%10){a++;}
                x/=10;y/=10;
            }
            cout<<a<<"A"<<(3-a)<<"B\n";
        }else if(n==1234){
            int meow=(j%6==0 ? j/6 : (j/6)+1);
            int bhaw=(k%6==0 ? k/6 : (k/6)+1);
            int idxj=(j%6==0 ? 5 : j%6-1);
            int idxk=(k%6==0 ? 5 : k%6-1);
            int reqj = permute3(meow)[idxj] + meow*1000;
            int reqk = permute3(bhaw)[idxk] + bhaw*1000;
            int a=0;
            for(int i=0;i<4;i++){
                if(reqj%10==reqk%10){a++;}
                reqj/=10;reqk/=10;
            }
            cout<<a<<"A"<<(4-a)<<"B\n";
        }
    }
    return 0;
}
/*  BEST CODE GIVEN BY CLAUDE:
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string n;
        int j, k;
        cin >> n >> j >> k;

        // n's digits are already ascending (12, 123, 1234),
        // so next_permutation enumerates permutations in sorted order.
        vector<string> perms;
        string s = n;
        do {
            perms.push_back(s);
        } while (next_permutation(s.begin(), s.end()));

        const string &a = perms[j - 1];
        const string &b = perms[k - 1];

        int A = 0, len = n.size();
        for (int i = 0; i < len; i++)
            if (a[i] == b[i]) A++;

        cout << A << "A" << len - A << "B\n";
    }
    return 0;
}
*/