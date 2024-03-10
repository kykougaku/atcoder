#include <bits/stdc++.h>

using namespace std;

int main (){
    int n;
    cin >> n;
    vector<vector<long long>> p(n, vector<long long>(n)), r(n, vector<long long>(n)), d(n, vector<long long>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> p.at(i).at(j);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            r.at(i).at(j) = p.at(i).at(j);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            d.at(i).at(j) = p.at(i).at(j);
        }
    }
    vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(4*n*n)));
    dp.at(0).at(0).at(0) = 0;
    return 0;
}