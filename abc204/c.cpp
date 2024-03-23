#include <bits/stdc++.h>

using namespace std;

void dfs(int v, vector<vector<int>> &g, vector<bool> &seen, int &count){
    seen.at(v) = true;
    count++;

    for(auto next_v : g.at(v)){
        if(seen.at(next_v)) continue;
        dfs(next_v, g, seen, count);
    }
}

int main (){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g.at(a).push_back(b);
    }

    int count = 0;
    for(int i = 0; i < n; i++){
        vector<bool> seen(n, false);
        dfs(i, g, seen, count);
    }
    cout << count << endl;

    return 0;
}