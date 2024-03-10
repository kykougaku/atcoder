#include <bits/stdc++.h>

using namespace std;

int main (){
    int n, k;
    cin >> n >> k;
    vector<long long> h(n);
    for(int i = 0; i < n; i++) cin >> h.at(i);
    vector<long long> dp(n+1, 1e18);
    dp.at(0) = 0;
    for(int i = 0; i < n; i++){
        int end = min(i+k, n-1);
        for(int j = i+1; j <= end; j++){
            if(j>=n) break;
            dp.at(j) = min(dp.at(j), dp.at(i)+abs(h.at(i)-h.at(j)));
        }
    }
    cout << dp.at(n-1) << endl;
    return 0;
}