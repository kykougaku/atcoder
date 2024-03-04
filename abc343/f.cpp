#include <bits/stdc++.h>

using namespace std;
/* RMQ：[0,n-1] について、区間ごとの最小値を管理する構造体
    set(int i, T x), build(): i番目の要素をxにセット。まとめてセグ木を構築する。O(n)
    update(i,x): i 番目の要素を x に更新。O(log(n))
    query(a,b): [a,b) での最小の要素を取得。O(log(n))

*/
template <typename T>
class RMQ{
    private:
        const T INF = numeric_limits<T>::max();
        int n;
        vector<vector<T>>> dat;
        function<vector<T>(T, T)> fx = [](vector<T> x1, vector<T>x2) -> T {
            vector<T> temp{x1.at(0), x2.at(0), x1.at(1), x2.at(1)};
            sort(temp.begin(), temp.end());
            temp.pop_back(); temp.pop_back();
            return temp;
        };
        //std::function< 戻り値の方(引数の型) > object = 関数or ラムダ式 or 関数オブイェクト orクラスのメンバ関数;
    public:
        explicit RMQ(int n_) : n(), dat(n_ * 4, vector<T>(2,0)) {
            int x = 1;
            while (n_ > x) {
                x *= 2;
            }
            n = x;
        }

        void set(int i, T x) { dat.at(i + n - 1).at(0) = x; }
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
            if (r <= a || b <= l) return INF;
            else if (a <= l && r <= b) return dat.at(k);
            else{
                vector<T> vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
                vector<T> vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
                return fx(vl, vr);
            }
        }
};

int main (){
    int n, q;
    cin >> n >> q;
    RMQ<int> a(n);
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        a.set(i, temp);
    }
    a.build();
    for(int i = 0; i < q; i++){
        int type;
        cin >> type;
        if(type == 1){
            int x, v;
            cin >> x >> v;
            a.update(x-1, v);
        }
        else{
        int l, r;
        cin >> l >> r;
        int max = a.query(l-1, r);
        int max2 = a.find_leftest(l-1, r, max);
        }
    }
    return 0;
}