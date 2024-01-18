#include <bits/stdc++.h>
using namespace std;

int dfs(int hv, int wv, int h, int w, vector<vector<int>> &a, set<int> s){
    int ans = 0;
    if(hv >= h || wv >= w || s.find(a.at(hv).at(wv)) != s.end()) return 0;

    if(hv == h-1 && wv == w-1 && s.find(a.at(hv).at(wv)) == s.end()) return 1;

    s.insert(a.at(hv).at(wv));
    ans += dfs(hv+1, wv, h, w, a, s);
    ans += dfs(hv, wv+1, h, w, a, s);

    return ans;
}
int main(){
    int h,w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin >> a.at(i).at(j);
        }
    }

    int ans;
    ans = dfs(0, 0, h, w, a, set<int>());
    cout << ans << endl;


    return 0;
}