#include <bits/stdc++.h>

using namespace std;

int main (){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n, vector<int>(n,0));
    for(int i = 0; i < m; i++){
        int xt, yt;
        cin >> xt >> yt;
        xt--; yt--;
        G.at(xt).at(yt) = 1;
        G.at(yt).at(xt) = 1;
    }
    for(int i = 0; i<n; i++)G.at(i).at(i) = 1;

    int ans = 0;
    for(int i = 0; i < (1<<n); i++){
        bool flag = true;
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(i & (1<<j)){
                cnt++;
                for(int k = 0; k < n; k++){
                    if(i & (1<<k)){
                        if(G.at(j).at(k) == 0)flag = false;
                    }
                }
            }
        }
        if(flag)ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}