#include <bits/stdc++.h>

using namespace std;

int main (){
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<int> line_map(2*N, 0);
    for(int i = 0; i < M; i++){
        int l, r;
        cin >> l >> r;
        l--; r--;
        line_map.at(2*l)++; line_map.at(2*r+1)--;
    }
    vector<int> p(Q), q(Q);
    for(int i = 0; i < Q; i++){
        int pp, qq;
        cin >> pp >> qq;
        p.at(i) = pp-1; q.at(i) = qq-1;
    }
    return 0;
}