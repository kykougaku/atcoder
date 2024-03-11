#include <bits/stdc++.h>

using namespace std;

//区間[l.r)のDP問題
int rec(int l, int r, vector<int> &w, vector<vector<int>>& dp){
    if(dp.at(l).at(r) != -1) return dp.at(l).at(r);
    if(abs(l-r) <= 1) return 0;

    int res = 0;
    // 1. 両端とナカが取り除ける
    if(abs(w.at(l) - w.at(r-1)) <= 1 && rec(l+1, r-1, w, dp) == r-l-2){
        res = r-l;
    }
    // 2. 区間を分割
    for(int i = l+1; i <= r-1; i++){
        res = max(res, rec(l, i, w, dp)+rec(i, r, w, dp));
    }
    return dp.at(l).at(r) = res;
}

int main (){
    vector<int> ans;
    while(true){
        int n;
        cin >> n;
        if(n == 0) break;
        vector<int> w(n);
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        for(int i = 0; i < n; i++) cin >> w.at(i);
        ans.push_back(rec(0, n, w, dp));
    }

    for(int i = 0; i < ans.size(); i++) cout << ans.at(i) << endl;
    return 0;
}