#include <bits/stdc++.h>

using namespace std;



int64_t solve(int64_t n, map<int64_t, int64_t> &dp){
    if(dp.count(n)){
        return dp.at(n);
    }
    if(n == 1){
        return 0;
    }
    if(n%2 == 0){
        return dp[n] = 2*solve(n/2, dp) + n;
    }
    else{
        return dp[n] = solve(n/2, dp) + solve(n/2+1, dp) + n;
    }
}

int main (){
    int64_t n;
    cin >> n;
    map<int64_t, int64_t> dp;
    int64_t ans = 0;
    ans = solve(n, dp);
    cout << ans << endl;
    return 0;
}