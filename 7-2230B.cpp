#include <bits/stdc++.h>
using namespace std;
// I solved 1/2 of this question, but stuck at second 1/2.
// BUT WHOLE GAME CHANGED WHEN I TRIED TO UNDERSTAND THE SECOND HALF.
// STILL IT SHOWS WRONG ANSWER IN TEST 2.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s; cin>>s;
        int n = s.length();
        int four=0;
        // Below 2 lines I realised at the end:
        int OneThree=0;
        int two=0;
        for(int i=0;i<n;i++){
            if(s[i]=='4')four++;
            else if(s[i]=='2') two++; // Realised at end.
            else OneThree++; // Realised at end.
        }
        // After this I tried some awkward method and couldn't reach answer.
        // Claude simply told that we must ensure that "no 2 must be there after 1 or 3"
        // And hence, as Claude told that answer is simply four+min(ones_and_threes, twos)

        // Basically:
        // Firstly I tried to do some extra unimportant steps, converting 3's to 1's and removing 4's:
        /*
        vector<int> xyz(n-four,0);
        for(int i=0;i<n;i++){
            int j=0;
            while(j<n-four){
                if(s[i]!=4) {xyz[j]=((s[i]-'0')%2!=0 ? 1 : 2);j++;}
            }
        }
            */

        // As in my case as I have converted all 3's to 1's, I must ensure that there is no 2 after 1.
        /*
        int one=0;
        for(int i=0;i<n-four;i++){
            if(xyz[i]==1) one++;
            else two++;
        }
        // cout<<four+min(one,two);
        */
        
        cout<<four + min(two, OneThree)<<"\n";
    }
    return 0;
}
// EVEN THIS SOLUTION GAVE WRONG ANSWER IN TEST 2
/* FINAL SOLUTION GIVEN BY CLAUDE:
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.length();

        int suf = 0;
        for (char c : s) {
            if (c == '1' || c == '3') suf++;
        }

        int pref2 = 0;
        int best = pref2 + suf; // split before the string starts (keep only suffix 1s/3s)

        for (char c : s) {
            if (c == '2') pref2++;
            if (c == '1' || c == '3') suf--;
            best = max(best, pref2 + suf);
        }

        cout << (n - best) << "\n";
    }
    return 0;
}
*/