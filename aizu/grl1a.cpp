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
    //頂点数、辺数、始点
    long long v, e, start;
    cin >> v >> e >> start;

    Graph G(v);
    for(long long i = 0; i < e; i++){
        long long s, t, d;
        cin >> s >> t >> d;
        G[s].push_back(Edge(t, d));
        //sからtへの重みdの辺を張る（有向グラフ）
    }

    //ダイクストラ法
    vector<long long> dist(v, INF);
    //(d[v], v)のペアを要素とした優先度付きキューを作る
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> que;

    dist.at(start) = 0;
    que.push(make_pair(dist.at(start), start));

    //ダイクストラ法の反復を開始
    while(!que.empty()){
        //v:使用済みでない頂点のうちd[v]が最小の頂点
        //d:その値
        long long v = que.top().second;
        long long d = que.top().first;
        que.pop();

        //この時点での最小値よりもd[v]が大きければ、この時点での最小値を無視
        if(dist.at(v) < d) continue;

        //隣接する頂点を探索
        for(auto edge : G.at(v)){
            if(dist.at(v) + edge.weight < dist.at(edge.to)){
                //この時点での最小値よりもd[v]が小さければ、更新
                dist.at(edge.to) = dist.at(v) + edge.weight;
                que.push(make_pair(dist.at(edge.to), edge.to));
            }
        }
    }

    //結果出力
    for(long long i = 0; i < v; i++){
        if(dist.at(i) < INF){
            cout << dist.at(i) << endl;
        }else{
            cout << "INF" << endl;
        }
    }
}