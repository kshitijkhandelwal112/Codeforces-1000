#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string s; cin>>s; int zero=0;
        int l = s.length();
        if(l==1) {cout<<1<<"\n";continue;}
        for(int i=0;i<l;i++){if(s[i]=='0')zero++;}
        if(l%2==0 && zero==l/2){cout<<0<<"\n";continue;}
        if(zero==0 || zero==l){cout<<l<<"\n";continue;}
        bool zeromin=false;
        if(zero<(int)(l-zero)) zeromin=true;
        int O = min(zero,l-zero);
        if(zeromin==true){
            for(int i=0;i<l;i++){
                if(s[i]=='1') O--;
                if(O<0){cout<<l-i<<"\n";break;}
            }
        }else{
            for(int i=0;i<l;i++){
                if(s[i]=='0') O--;
                if(O<0){cout<<l-i<<"\n";break;}
            }
        }
    }
    return 0;
}
/* BETTER/SHORTER SOLUTION GIVEN BY CLAUDE
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        int c0 = count(s.begin(), s.end(), '0');
        int c1 = n - c0;
        int i = 0;
        for (; i < n; i++) {
            if (s[i] == '0') {
                if (c1 == 0) break;   // need a '1' but none left
                c1--;
            } else {
                if (c0 == 0) break;   // need a '0' but none left
                c0--;
            }
        }
        cout << n - i << "\n";
    }
    return 0;
}
*/