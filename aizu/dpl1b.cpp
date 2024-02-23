#include <bits/stdc++.h>

using namespace std;

int main (){
    long long n, W;
    cin >> n >> W;
    vector<long long> ww(n), vv(n);
    vector<vector<long long>> dp(n+1, vector<long long>(W+1, 0));
    for(long long i = 0; i<n; i++) cin >> vv.at(i) >> ww.at(i);

    for(long long i = 1; i<n+1; i++){
        for(long long j = 0; j < W+1; j++){
            dp.at(i).at(j) = dp.at(i-1).at(j);
            if(j-ww.at(i-1)>=0) dp.at(i).at(j) = max(dp.at(i-1).at(j), dp.at(i-1).at(j-ww.at(i-1))+vv.at(i-1));
        }
    }
    cout << dp.at(n).at(W) << endl;
    return 0;
}