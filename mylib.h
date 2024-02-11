#ifndef mylib_H_
#define mylib_H_

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

//choose min
template <class T> bool chmin(T& a, T b){//aとbは型が分からないのでテンプレート　aは変更を伴うので参照渡し
    if(a > b){
        a=b;
        return true;
    }
    return false;
}

#endif