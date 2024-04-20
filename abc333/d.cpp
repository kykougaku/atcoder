#include <bits/stdc++.h>

using namespace std;

int main (){
    long long n;
    cin >> n;
    vector<vector<long long>> g(n);
    for (int i = 0; i < n-1; i++){
        long long u, v;
        cin >> u >> v;
        u--; v--;
        g.at(u).push_back(v); g.at(v).push_back(u);
    }
    if(g.at(0).size() == 1){
        cout << 1 << endl;
        return 0;
    }
    vector<long long> dist(n, -1);
    dist.at(0) = 0;
    vector<long long> cntlist;
    for (long long i = 0; i < g.at(0).size(); i++){
        queue<long long> q;
        q.push(g.at(0).at(i));
        dist.at(g.at(0).at(i)) = 1;
        long long cnt = 0;
        while(!q.empty()){
            long long v = q.front();
            q.pop();
            cnt++;
            if(v == 0) continue;
            for (long long nv : g.at(v)){
                if(dist.at(nv) != -1) continue;
                dist.at(nv) = dist.at(v) + 1;
                q.push(nv);
            }
        }
        cntlist.push_back(cnt);
    }
    sort(cntlist.begin(), cntlist.end());

    long long ans = 0;
    for(long long i = 0; i < cntlist.size()-1; i++){
        ans += cntlist.at(i);
    }
    cout << ans+1 << endl;
    return 0;
}