#include <bits/stdc++.h>

using namespace std;

const long long INF = 1LL << 60;

class Edge{
    public:
        int to;
        long long weight;
        Edge(int to, long long weight) : to(to), weight(weight){} //コンストラクタ　メンバ初期化子リスト
};

using Graph = vector<vector<Edge>>;

int main (){
    int n, k;
    cin >> n >> k;
    Graph G(n);
    vector<long long> ans;
    for(int i=0; i<k; i++){
        int com;
        cin >> com;
        if(com == 0){
            int a, b;
            cin >> a >> b;
            a--; b--;
            vector<long long> dist(n, INF);
            dist.at(a) = 0;
            priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> que;
            que.push(make_pair(0,a));
            while(!que.empty()){
                long long d = que.top().first;
                int v = que.top().second;
                que.pop();
                if(dist[v] < d) continue;
                for(auto e : G.at(v)){
                    if(dist.at(v)+e.weight < dist.at(e.to)){
                        dist.at(e.to) = dist.at(v) + e.weight;
                        que.push(make_pair(dist.at(e.to),e.to));
                    }
                }
            }
            ans.push_back(dist.at(b));
        }
        else{
            int c, d, e;
            cin >> c >> d >> e;
            c--; d--;
            G.at(c).push_back(Edge(d, e));
            G.at(d).push_back(Edge(c, e));
        }
    }
    for(int i = 0; i<ans.size(); i++){
        if(ans.at(i) < INF) cout << ans.at(i) << endl;
        else cout << "-1" << endl;
    }
    return 0;
}