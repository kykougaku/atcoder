#include <bits/stdc++.h>

using namespace std;

int bfs(vector<vector<vector<vector<char>>>> map, vector<int> start, int n){
    queue<vector<int>> que;
    que.push(start);

    while(!que.empty()){
        vector<int> pos = que.front();
        que.pop();
        int x = pos.at(0);
        int y = pos.at(1);
        for(int i = -1; i < 2; i++){
            for(int j = -1; j < 2; j++){
                if(i == 0 || j == 0){
                    if(x+i >= 0 && x+i < n && y+j >= 0 && y+j < n && map.at(x+i).at(y+j) != '#' && dist.at(x+i).at(y+j) == -1){
                        dist.at(x+i).at(y+j) = dist.at(x).at(y) + 1;
                        que.push({x+i, y+j});
                        if(map.at(x+i).at(y+j) == 'P'){
                            return dist.at(x+i).at(y+j);
                        }
                    }
                }
            }
        }
    }

    return -1;
}

int main (){
    int n;
    cin >> n;
    vector <int> start(2);
    vector<vector<vector<vector<char>>>> map(n, vector<char>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map.at(i).at(j);
            if(map.at(i).at(j) == 'P'){
                start.at(0) = i;
                start.at(1) = j;
            }
        }
    }
    int ans = bfs(map, start, n);

    cout << ans << endl;
    return 0;
}