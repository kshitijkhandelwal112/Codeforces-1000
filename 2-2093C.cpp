#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int repeat(int x, int k){
    string X = to_string(x); // Learnt to_string function. vice versa can be done using stoi function.
    // Silly mistake- I was doubling string in every step instead of adding single X each time.
    string X1=X; // This fixes the silly mistake.
    if(k>1){// This was another mistake due to which the loop couldn't work. If k=1, then X will just be the original one.
        for(int i=1;i<k;i++){
            X+=X1;
        }
    }
    int z=stoi(X); // Converts string to integer.
    return z;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x,k; cin>>x>>k;
        int X = repeat(x,k);
        if(X%2==0 && X!=2) cout<<"NO\n";
        else if(X==1)cout<<"NO\n";
        else if(X==3 || X==2) cout<<"YES\n";
        else if(X%6!=5 && X%6!=1) cout<<"NO\n"; // Silly mistake: Unnecessarily confused between && and ||.
        else{
            bool nonprime=false;
            for(int i=2;i<=sqrt(X);i++){ // Another mistake: <=sqrt(X) should be there and not only <sqrt(X)
                if(X%i==0){nonprime=true;cout<<"NO\n";break;}
            }
            if(nonprime==false) cout<<"YES\n";
        }
    }
    return 0;
}