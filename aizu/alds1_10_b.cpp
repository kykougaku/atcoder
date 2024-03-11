#include <bits/stdc++.h>

using namespace std;
const long long INF = 1LL << 60;
//区間[l.r)のDP問題
long long rec(long long l, long long r, vector<long long>& rr, vector<long long>& cc, vector<vector<long long>>& dp){
    if(dp.at(l).at(r) != -1) return dp.at(l).at(r);
    if(abs(l-r) <= 1) return 0;

    long long res = INF;
    if(r-l == 2) return res = rr.at(l)*cc.at(l)*cc.at(l+1);
    // 2. 区間を分割
    for(int i = l+1; i <= r-1; i++){
        res = min(res, rec(l, i, rr, cc, dp)+rec(i, r, rr, cc, dp)+rr.at(l)*cc.at(i-1)*cc.at(r-1));
    }
    return dp.at(l).at(r) = res;
}
int main (){
    long long n;
    cin >> n;
    vector<long long> rr(n), cc(n);
    vector<vector<long long>> dp(n+1, vector<long long>(n+1, -1));
    for (int i = 0; i < n; i++) cin >> rr.at(i) >> cc.at(i);
    cout << rec(0, n, rr, cc, dp) << endl;
    return 0;
}