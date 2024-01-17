#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &g, vector<int> &ans, int oya, int v, int x){
    ans[v] += x;
    for(int nv : g[v]){
        if(oya==nv) continue;
        dfs(g, ans, v, nv, x);
    }
}

int main(){
    int n, q;
    cin >> n >> q;
    vector<vector<int>> g(n);
    vector<int> p(q), x(q);
    vector<bool> seen(n, false);
    for(int i=0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        g[a-1].push_back(b-1);
    }
    
    for(int i=0; i<n-1; i++){

    }
    for(int i=0; i<q; i++){
        cin >> p[i] >> x[i];
    }

    vector<int> ans(n, 0);
    for(int i=0; i<q; i++){
        dfs(g, ans, p[i]-1, x[i]);
    }
    
    for(int i=0; i<n; i++){
        cout << ans[i] << " ";
    }
    return 0;
}