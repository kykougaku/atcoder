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

//union find
class UnionFind{
    public:
        vector<int> par, siz;
        UnionFind(int n) : par(n, -1), siz(n, 1) {}//コンストラクタ　メンバ初期化子リスト
        int root(int x){
            if(par.at(x) == -1) return x;
            else return par.at(x) = root(par.at(x));
        }
        bool issame(int x, int y){
            return root(x) == root(y);
        }
        bool unite(int x, int y){
            x = root(x);
            y = root(y);
            if(x == y) return false;
            if(siz.at(x) < siz.at(y)) swap(x, y);
            par.at(y) = x;
            siz.at(x) += siz.at(y);
            return true;
        }
        int size(int x){
            return siz.at(root(x));
        }
};



//segment tree
/* RMQ：[0,n-1] について、区間ごとの最小値を管理する構造体
    set(int i, T x), build(): i番目の要素をxにセット。まとめてセグ木を構築する。O(n)
    update(i,x): i 番目の要素を x に更新。O(log(n))
    query(a,b): [a,b) での最小の要素を取得。O(log(n))
    find_rightest(a,b,x): [a,b) で x以下の要素を持つ最右位置を求める。O(log(n))
    find_leftest(a,b,x): [a,b) で x以下の要素を持つ最左位置を求める。O(log(n))
*/
template <typename T>
class RMQ{
    private:
        const T INF = numeric_limits<T>::max();
        int n;
        vector<T> dat;
        function<T(T, T)> fx = [](T x1, T x2) -> T { return min(x1, x2); };
        //std::function< 戻り値の方(引数の型) > object = 関数or ラムダ式 or 関数オブイェクト orクラスのメンバ関数;
    public:
        explicit RMQ(int n_) : n(), dat(n_ * 4, INF) {
            int x = 1;
            while (n_ > x) {
                x *= 2;
            }
            n = x;
        }

        void set(int i, T x) { dat.at(i + n - 1) = x; }
        void build() {
            for (int k = n - 2; k >= 0; k--) dat.at(k) = fx(dat.at(2 * k + 1), dat.at(2 * k + 2));
        }

        void update(int i, T x) {
            i += n - 1;
            dat.at(i) = x;
            while (i > 0) {
                i = (i - 1) / 2;  // parent
                dat.at(i) = fx(dat.at(i * 2 + 1), dat.at(i * 2 + 2));
            }
        }

        T query(int a, int b) { return query_sub(a, b, 0, 0, n); }
        T query_sub(int a, int b, int k, int l, int r) {
            // k:現在見ているノードの位置  [l,r):dat[k]が表している区間
            if (r <= a || b <= l) return INF;// 範囲外なら考えない
            else if (a <= l && r <= b) return dat.at(k);
            else{// 一部区間が被る時
                T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
                T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
                return fx(vl, vr);
            }
        }

        int find_rightest(int a, int b, T x) { return find_rightest_sub(a, b, x, 0, 0, n); }
        int find_leftest(int a, int b, T x) { return find_leftest_sub(a, b, x, 0, 0, n); }
        int find_rightest_sub(int a, int b, T x, int k, int l, int r) {
            if (dat.at(k) > x || r <= a || b <= l) return a - 1;
            else if (k >= n - 1) return (k - (n - 1));
            else{
                int vl = find_rightest_sub(a, b, x, k * 2 + 1, l, (l + r) / 2);
                if(vl != -1) return vl;
                else return find_rightest_sub(a, b, x, k * 2 + 2, (l + r) / 2, r);
            }
        }
        int find_leftest_sub(int a, int b, T x, int k, int l, int r) {
            if (dat.at(k) > x || r <= a || b <= l) return b;
            else if (k >= n - 1) return (k - (n - 1));
            else{
                int vr = find_leftest_sub(a, b, x, k * 2 + 2, (l + r) / 2, r);
                if(vr != b) return vr;
                else return find_leftest_sub(a, b, x, k * 2 + 1, l, (l + r) / 2);
            }
        }
};

#endif