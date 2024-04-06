#include <bits/stdc++.h>

using namespace std;

long long dx[4] = {1, 0, -1, 0};
long long dy[4] = {0, 1, 0, -1};

void bfs(vector<vector<char>> &a, vector<vector<long long>> &along, long long h, long long w, long long si, long long sj, vector<vector<long long>> &dist){
    queue<pair<long long, long long>> que;
    dist.at(si).at(sj) = 0;

    que.push(make_pair(si, sj));
    while(!que.empty()){
        long long i = que.front().first;
        long long j = que.front().second;
        que.pop();
        for(long long k = 0; k < 4; k++){
            long long ni = i + dx[k];
            long long nj = j + dy[k];
            if(ni >= 0 && ni < h && nj >= 0 && nj < w && a.at(ni).at(nj) != '#' && dist.at(ni).at(nj) == -1){
                dist.at(ni).at(nj) = dist.at(i).at(j) + 1;
                que.push(make_pair(ni, nj));
            }
        }
    }
}


long long main (){
    long long h, w;
    cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w));
    vector<vector<long long>> along(h, vector<long long>(w, 0));
    for(long long i = 0; i < h; i++){
        for(long long j = 0; j < w; j++){
            cin >> a.at(i).at(j);
            if(a.at(i).at(j) == '#'){
                along.at(i).at(j) = -1;
            }
        }
    }
    long long n;
    cin >> n;
    vector<long long> r(n), c(n), e(n);
    for(long long i = 0; i < n; i++){
        cin >> r.at(i) >> c.at(i) >> e.at(i);
        along.at(r.at(i)-1).at(c.at(i)-1) = e.at(i);
    }

    long long si, sj;
    long long power = 0;
    for(long long i = 0; i < h; i++){
        for(long long j = 0; j < w; j++){
            if(a.at(i).at(j) == 'S'){
                if(along.at(i).at(j) <= 0){
                    cout << "NO" << endl;
                    return 0;
                }
                else{
                    si = i;
                    sj = j;
                    power = along.at(i).at(j);
                }
            }
        }
    }

    vector<vector<long long>> dpmap(h, vector<long long>(w, -1));

    for(int i = 0; i<n; i++){
        vector<vector<long long>> dist(h, vector<long long>(w, -1));
        bfs(a, along, h, w, r.at(i),c.at(i), dist);
        for(int j = 0; j<n; j++){
            if(dist.at(r.at(j)-1).at(c.at(j)-1) != -1){
                dpmap.at(r.at(j)-1).at(c.at(j)-1) = min(dpmap.at(r.at(j)-1).at(c.at(j)-1), dist.at(r.at(j)-1).at(c.at(j)-1));
            }
        }
    }



    return 0;
}