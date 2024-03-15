#include <bits/stdc++.h>

using namespace std;
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
int main (){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n);
    UnionFind uf(n);
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        uf.unite(a, b);
        G.at(a).push_back(b);
    }
    string ans = "Yes";
    map<int, int> mp;
    for(int i=0; i<n; i++){
        mp[uf.root(i)] += G.at(i).size();
    }
    for(auto p: mp){
        if(p.second != uf.size(p.first)){
            ans = "No";
            cout << ans << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}