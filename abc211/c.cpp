#include <bits/stdc++.h>

using namespace std;

int main (){
    string s;
    cin >> s;

    vector<int64_t> dp(8, 0);

    while(s.size() > 0){
        char back_s = s.back();
        s.pop_back();
        if(back_s == 'i'){
            dp[7] += 1;
        }
        else if(back_s == 'a'){
            dp[6] += dp[7];
        }
        else if(back_s == 'd'){
            dp[5] += dp[6];
        }
        else if(back_s == 'u'){
            dp[4] += dp[5];
        }
        else if(back_s == 'k'){
            dp[3] += dp[4];
        }
        else if(back_s == 'o'){
            dp[2] += dp[3];
        }
        else if(back_s == 'h'){
            dp[1] += dp[2];
        }
        else if(back_s == 'c'){
            dp[0] += dp[1];
        }
    }
    cout << dp[0] % 1000000007 << endl;
    return 0;
}