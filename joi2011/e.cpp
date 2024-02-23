#include <bits/stdc++.h>

using namespace std;

int bfs(vector<vector<char>> meiz, int sx, int sy, int gx, int gy, int h, int w, int n){
    vector<vector<int>> dist(h,vector<int>(w,0));
    vector<vector<int>> dx = {{1,0},{-1,0},{0,1},{0,-1}};
    queue<pair<int,int>> que;
    que.push(make_pair(sx,sy));
    while(!que.empty()){
        pair<int,int> p = que.front();
        que.pop();
        for(int i=0;i<4;i++){
            int nx = p.first + dx.at(i).at(0);
            int ny = p.second + dx.at(i).at(1);
            if(nx<0 || nx>=h || ny<0 || ny>=w) continue;
            if(meiz.at(nx).at(ny) == 'X') continue;
            if(dist.at(nx).at(ny) != 0) continue;
            dist.at(nx).at(ny) = dist.at(p.first).at(p.second) + 1;
            que.push(make_pair(nx,ny));
        }
        if(dist.at(gx).at(gy) != 0) return dist.at(gx).at(gy);
    }
}

int main (){
    int h, w, n;
    cin >> h >> w >> n;
    vector<vector<char>> meiz(h,vector<char>(w));
    vector<vector<int>> point(n+1,vector<int>(2));

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> meiz.at(i).at(j);
            if(meiz.at(i).at(j)=='X' || meiz.at(i).at(j)=='.') continue;
            if(meiz.at(i).at(j) == 'S'){
                point.at(0).at(0) = i; point.at(0).at(1) = j;
            }
            else{
                int num = meiz.at(i).at(j) - '0';
                point.at(num).at(0) = i; point.at(num).at(1) = j;
            }
        }
    }

    int ans = 0;
    for(int i=1;i<n+1;i++){
        ans += bfs(meiz,point.at(i-1).at(0),point.at(i-1).at(1),point.at(i).at(0),point.at(i).at(1),h,w,n);
    }
    cout << ans << endl;
    return 0;
}