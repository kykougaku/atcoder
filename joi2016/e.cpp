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
    long long n, m, k, s, p, q;
    cin >> n >> m >> k >> s >> p >> q;
    vector<long long> a(m), b(m), c(k);
    Graph G(n);
    for(long long i = 0; i<k; i++){
        cin >> c.at(i);
    }
    for(long long i = 0; i < m; i++){
        cin >> a.at(i) >> b.at(i);
        a.at(i)--; b.at(i)--;
        G.at(a.at(i)).push_back(Edge(b.at(i), 0));
        G.at(b.at(i)).push_back(Edge(a.at(i), 0));
    }

    return 0;
}