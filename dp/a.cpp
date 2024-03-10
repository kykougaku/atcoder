#include <bits/stdc++.h>

using namespace std;

int main (){
    int n; 
    cin >> n;
    vector<long long> h(n);
    for(int i = 0; i < n; i++) cin >> h.at(i);
    vector<long long> dp(n+1, 1e18);
    dp.at(1) = 0;
    dp.at(2) = abs(h.at(1) - h.at(0));
    for(int i = 3; i <= n; i++){
        dp.at(i) = min(dp.at(i-2)+abs(h.at(i-1)-h.at(i-3)), dp.at(i-1)+abs(h.at(i-1)-h.at(i-2)));
    }
    cout << dp.at(n) << endl;
    return 0;
}