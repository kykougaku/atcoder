#include <bits/stdc++.h>
using namespace std;


void dfs(vector<vector<int>> &g, int v, int p, vector<int> &ans){
    for(auto nv : g[v]){
        if(nv == p) continue;
        ans[nv] += ans[v];
        dfs(g, nv, v, ans);
    }
}

int main(){
    int n, q;
    cin >> n >> q;
    vector<vector<int>> g(n);
    vector<int> ans(n, 0);
    for(int i=0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }
    
    for(int i=0; i<q; i++){
        int p,x;
        cin >> p >> x;
        p--;
        ans[p] += x;
    }

    dfs(g, 0, -1, ans);

    
    for(int i=0; i<n; i++){
        cout << ans[i] << " ";
    }
    return 0;
}