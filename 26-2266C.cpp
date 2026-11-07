#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n; cin>>n;
        string s; cin>>s;
        if(s[0]=='1'){
            int zero=0;
            for(int i=0;i<n;i++){
                if(s[i]=='0') zero++;
            }
            cout<<zero<<"\n";
        }else{
            vector<int> ops;
            // making all 1's as 0's (only for special cases)
            int sum=0;
            for(int k=0;k<n;k++){
                if(s[k]=='1') sum++;
            }
            ops.push_back(sum);
            // making all 0's as 1's (only for special cases)
            ops.push_back(n-sum);
            // General case
            /*
            I USED THIS ONE, THAT CAUSED TLE
            int j=0;
            for(int i=0;i<n;i++){
                if(s[i]=='1'){
                    int x=j;
                    for(int j=i+1;j<n;j++){
                        if(s[j]=='0') x++;
                    }
                    ops.push_back(x);
                    j++;
                }
            }
            */
            vector<int> pfsum(n);
            int zeroes = n-sum;
            for(int i=0;i<n;i++){
                zeroes-=(s[i]=='0' ? 1 : 0);
                pfsum[i]=zeroes;
            }
            int j=0;
            for(int i=0;i<n;i++){
                if(s[i]=='1'){
                    ops.push_back(pfsum[i]+j);
                    j++;
                }
            }            
            auto meow = min_element(ops.begin(),ops.end());
            cout<<(*meow)<<"\n";
        }
    }
    return 0;
}