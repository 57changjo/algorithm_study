#if 1

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

long dive = 1000000007;
string str;

void inputdata() {
    cin >> str;
}

long  solve() {
     long ans = 0;
    for (int i = str.length()-1; i >= 0; i--) {
        if (str[i] == 'O') {
           ans = ( ans << 1 ) | 1 ;
        }
        else {
            ans =  ans << 1;
        }
        ans = ans % dive;
    }
    return ans;
}

int main(void) {
   (void) freopen("prob1.txt", "r", stdin);
    inputdata();
    //cout << str[1];
    cout << solve();
    return 0;
}
#endif

#endif
