#include <bits/stdc++.h>

using namespace std;

int main (){
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a.at(i) >> b.at(i);
    vector<vector<bool>> dp(n+1, vector<bool>(x+1, false));
    dp.at(0).at(0) = true;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= x; j++){
            if(!dp.at(i-1).at(j)) continue;
            dp.at(i).at(j) = true;
            for(int k = 0; k <= b.at(i-1); k++){
                if(j + a.at(i-1) * k > x) break;
                dp.at(i).at(j + a.at(i-1) * k) = true;
            }
        }
    }
    if(dp.at(n).at(x)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}