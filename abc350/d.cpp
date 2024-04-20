#include <bits/stdc++.h>

using namespace std;
//union find
class UnionFind{
    public:
        vector<long long> par, siz;
        UnionFind(long long n) : par(n, -1), siz(n, 1) {}//コンストラクタ　メンバ初期化子リスト
        long long root(long long x){
            if(par.at(x) == -1) return x;
            else return par.at(x) = root(par.at(x));
        }
        bool issame(long long x, long long y){
            return root(x) == root(y);
        }
        bool unite(long long x, long long y){
            x = root(x);
            y = root(y);
            if(x == y) return false;
            if(siz.at(x) < siz.at(y)) swap(x, y);
            par.at(y) = x;
            siz.at(x) += siz.at(y);
            return true;
        }
        long long size(long long x){
            return siz.at(root(x));
        }
};

int main (){
    long long n ,m;
    cin >> n >> m;
    vector<long long> a(m), b(m);
    vector<vector<long long>> g(n);
    UnionFind uf(n);
    for(long long i = 0; i < m; i++){
        cin >> a.at(i) >> b.at(i);
        a.at(i)--; b.at(i)--;
        g.at(a.at(i)).push_back(b.at(i));
        g.at(b.at(i)).push_back(a.at(i));
        uf.unite(a.at(i), b.at(i));
    }
    long long sum = 0;
    for(long long i = 0; i < n; i++){
        if(uf.root(i) == i){
            sum += uf.size(i) * (uf.size(i) - 1) / 2;
        }
    }
    cout << sum - m << endl;
    return 0;
}