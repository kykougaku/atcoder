#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> s(m, vector<int>());
    vector<int> k(m);
    vector<int> p(m);
    for(int i = 0; i < m; i++){
        cin >> k.at(i);
        for(int j = 0; j < k.at(i); j++){
            int tmp;
            cin >> tmp;
            tmp--;
            s.at(i).push_back(tmp);
        }
    }
    for(int i = 0; i < m; i++) cin >> p.at(i);

    long long ans = 0;
    for(int i = 0; i <(1 << n); i++){
        for(int j = 0; j< m; j++){
            int cnt = 0;
            for(int l = 0; l < k.at(j); l++){
                if(i & (1 << (s.at(j).at(l)))) cnt++;
            }
            if(cnt % 2 != p.at(j)) break;
            if(j == m - 1) ans++;
        }
    }

    cout << ans << endl;
    return 0;
}