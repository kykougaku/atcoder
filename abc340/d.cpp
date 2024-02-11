#include <bits/stdc++.h>
//#include "../mylib.h"

using namespace std;

const long long INF = 1LL << 60;

class Edge{
    public:
        int to;
        long long weight;
        Edge(int to, long long weight) : to(to), weight(weight){} //コンストラクタ　メンバ初期化子リスト
};

using Graph = vector<vector<Edge>>;

//choose min
template <class T> bool chmin(T& a, T b){//aとbは型が分からないのでテンプレート　aは変更を伴うので参照渡し
    if(a > b){
        a=b;
        return true;
    }
    return false;
}



int main (){
    long long n;
    cin >> n;
    vector<long long> a(n), b(n), x(n);
    Graph G(n+1);
    for(long long i = 1; i <= n-1; i++) {
        long long ta, tb, tx;
        cin >> ta >> tb >> tx;
        G.at(i).push_back(Edge(i+1, ta));
        G.at(i).push_back(Edge(tx, tb));
    }

    vector<long long> dist(n+1, INF);
    dist.at(1) = 0;
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> que;// this is min heap of pair
    //max heap is as follows/////////////////////////////
    //priority_queue<int> que;
    //priority_queue<int, vector<int>, less<int>> que;
    ////////////////////////////////////////////////////

    que.push(make_pair(dist.at(1), 1));
    while(!que.empty()){
        pair<long long, long long> p = que.top();
        que.pop();
        long long d = p.first;
        long long v = p.second;
        if(dist.at(v) < d) continue;
        for(auto e : G.at(v)){
            if(chmin(dist.at(e.to), dist.at(v) + e.weight)){
                que.push(make_pair(dist.at(e.to), e.to));
            }
        }
    }

    cout << dist.at(n) << endl;

    return 0;
}