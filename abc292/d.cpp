#include <bits/stdc++.h>

using namespace std;

int main (){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n);
    vector<int> seen(n, false);
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        G.at(a).push_back(b);
    }
    string ans = "Yes";
    for(int i = 0; i < n; i++){
        if(seen.at(i)) continue;
        queue<int> que;
        int edgecnt =0;
        int pointcnt = 1;
        for(int j = 0; j < G.at(i).size(); j++){
            que.push(G.at(i).at(j));
            edgecnt++;
        }
        while(!que.empty()){
            int v = que.front();
            que.pop();
            if(seen.at(v)) continue;
            seen.at(v) = true;
            pointcnt++;
            for(int j = 0; j < G.at(v).size(); j++){
                que.push(G.at(v).at(j));
                edgecnt++;
            }
        }
        if(edgecnt != pointcnt){
            ans = "No";
            cout << ans << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}