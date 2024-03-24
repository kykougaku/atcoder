#include <bits/stdc++.h>

using namespace std;
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

int main (){
    int n;
    cin >> n;

    vector<int> x(n), y(n);
    for(int i = 0; i < n; i++){
        cin >> x.at(i) >> y.at(i);
        x.at(i)--; y.at(i)--;
    }

    UnionFind uf(n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            int x1 = x.at(i), y1 = y.at(i), x2 = x.at(j), y2 = y.at(j);
            for(int dx = -1; dx <= 1; dx++){
                for(int dy = -1; dy <= 1; dy++){
                    if(dx+dy == 0) continue;
                    if(x1 + dx == x2 && y1 + dy == y2){
                        uf.unite(i, j);
                    }
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        if(uf.root(i) == i) ans++;
    }
    cout << ans << endl;

    return 0;
}