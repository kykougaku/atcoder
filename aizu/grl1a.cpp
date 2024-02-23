#include <bits/stdc++.h>

using namespace std;

class Edge{
    public:
        int to;
        long long weight;
        Edge(int to, long long weight) : to(to), weight(weight){} //コンストラクタ　メンバ初期化子リスト
};

using Graph = vector<vector<Edge>>;

const long long INF = 1LL << 60;


int main (){
    int v, e,r;
    cin >> v >> e >> r;
    Graph G(v);
    for(int i=0; i<e; i++){
        int s,t,d;
        cin >> s >> t >> d;
        G.at(s).push_back(Edge(t,d));
    }
    vector<long long> dist(v,INF);
    dist.at(r) = 0;
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> que;
    que.push(make_pair(0,r));

    while(!que.empty()){
        long long d = que.top().first;
        int v = que.top().second;
        que.pop();

        if(dist.at(v) < d) continue;

        for(auto e : G.at(v)){
            if(dist.at(v)+e.weight < dist.at(e.to)){
                dist.at(e.to) = dist.at(v) + e.weight;
                que.push(make_pair(dist.at(e.to),e.to));
            }
        }
    }
    for(int i = 0; i<v; i++){
        if(dist.at(i) < INF) cout << dist.at(i) << endl;
        else cout << "INF" << endl;
    }
    return 0;
}