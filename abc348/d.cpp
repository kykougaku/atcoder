#include <bits/stdc++.h>

using namespace std;

class Edge{
    public:
        pair<long long, long long> to;
        long long weight;
        Edge(pair<long long, long long> to, long long weight) : to(to), weight(weight){} //コンストラクタ　メンバ初期化子リスト
};

using Graph = vector<vector<Edge>>;
int main (){
    vector<long long> dx = {1, 0, -1, 0};
    vector<long long> dy = {0, 1, 0, -1};
    long long h, w;
    cin >> h >> w;
    vector<vector<long long>> a(h, vector<long long>(w));
    pair<long long, long long> start, goal;
    for(long long i = 0; i<h; i++){
        for(long long j = 0; j<w; j++){
            cin >> a.at(i).at(j);
            if(a.at(i).at(j) == 'S'){
                start = make_pair(i, j);
            }
            else if(a.at(i).at(j) == 'G'){
                goal = make_pair(i, j);
            }
        }
    }
    long long n;
    cin >> n;
    vector<long long> r(n), c(n), e(n);
    Graph G(n);
    for(long long i = 0; i<n; i++){
        cin >> r.at(i) >> c.at(i) >> e.at(i);
        r.at(i)--; c.at(i)--;
    }
    for(long long i = 0; i<n; i++){
        //r[i],c[i]を始点として、各マスへの最短距離を求める
        //bfs
        queue<pair<long long, long long>> que;
        vector<vector<long long>> dist(h, vector<long long>(w, -1));
        que.push(make_pair(r.at(i), c.at(i)));
        dist.at(r.at(i)).at(c.at(i)) = 0;
        while(!que.empty()){
            long long x = que.front().first;
            long long y = que.front().second;
            que.pop();
            for(long long j = 0; j<4; j++){
                long long nx = x + dx[j];
                long long ny = y + dy[j];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if(a.at(nx).at(ny) == 1) continue;
                if(dist.at(nx).at(ny) != -1) continue;
                dist.at(nx).at(ny) = dist.at(x).at(y) + 1;
                que.push(make_pair(nx, ny));
                G.at(i).push_back(Edge(
            }
        }

    }
    return 0;
}