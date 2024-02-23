#include <bits/stdc++.h>

using namespace std;

const int INF = 1001001001;

int main (){
    int r,c;
    cin >> r >> c;
    int sy,sx,gy,gx;
    cin >> sy >> sx >> gy >> gx;
    vector<vector<char>> meiz(r,vector<char>(c));
    for(int i=0;i<r;i++)for(int j=0;j<c;j++) cin >> meiz.at(i).at(j);
    vector<vector<int>> dist(r,vector<int>(c,INF));
    vector<vector<bool>> visited(r,vector<bool>(c,false));

    queue<pair<int,int>> q;
    q.push(make_pair(sy-1,sx-1));
    dist.at(sy-1).at(sx-1) = 0;
    visited.at(sy-1).at(sx-1) = true;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                if(i*j!=0) continue;
                if(i==0 && j==0) continue;
                if(x+i<0 || x+i>=c) continue;
                if(y+j<0 || y+j>=r) continue;
                if(meiz.at(y+j).at(x+i)=='#') continue;
                if(visited.at(y+j).at(x+i)) continue;
                q.push(make_pair(x+i,y+j));
                dist.at(y+j).at(x+i) = dist.at(y).at(x) + 1;
                visited.at(y+j).at(x+i) = true;
            }
        }
        if(visited.at(gy-1).at(gx-1)) break;
    }
    cout << dist.at(gy-1).at(gx-1) << endl;

    return 0;
}