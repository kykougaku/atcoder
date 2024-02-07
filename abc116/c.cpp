#include <bits/stdc++.h>

using namespace std;

int ans = 0;
int solve(vector<int>& h, int l, int r){
    if(l > r) return 0;
    int min_h = 1000000000;
    vector<int> zero;
    for (int i = l; i <= r; i++){
        min_h = min(min_h, h.at(i));
    }


    zero.push_back(l-1);
    for (int i = l; i <= r; i++){
        h.at(i) -= min_h;
        if(h.at(i) == 0) zero.push_back(i);
    }
    zero.push_back(r+1);

    ans += min_h;

    for (int i = 0; i < zero.size()-1; i++){
        solve(h, zero.at(i)+1, zero.at(i+1)-1);
    }
    return ans;
}

int main (){
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++){
        cin >> h.at(i);
    }
    cout << solve(h, 0, n-1) << endl;

    return 0;
}