#include <bits/stdc++.h>

using namespace std;

int main (){
    vector<string> in;
    string line;
    int h=0, w=0;

    getline(cin,line);

    while(!cin.eof()){
        getline(cin,line);  
        in.push_back(line);
        w = line.size();
        h++;
    }
    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    vector<vector<int>> dist(h,vector<int>(w,-1));
    dist[0][0] = 0;
    int dx[] = {1,0,-1,0};
    int dy[] = {0,1,0,-1};
    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = p.second + dx[i];
            int ny = p.first + dy[i];
            if(nx<0 || nx>=w || ny<0 || ny>=h) continue;
            if(in[ny][nx] == '#') continue;
            if(dist[ny][nx] != -1) continue;
            dist[ny][nx] = dist[p.first][p.second] + 1;
            q.push(make_pair(ny,nx));
        }
        if(dist[h-1][w-1] != -1) break;
    }
    if(dist[h-1][w-1] == -1){
        cout << -1 << endl;
        return 0;
    }
    long long ans = h*w;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(in[i][j] == '#') ans--;
        }
    }
    cout << ans - dist[h-1][w-1] - 1 << endl;
    return 0;
}