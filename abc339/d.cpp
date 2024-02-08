#include <bits/stdc++.h>

using namespace std;


int main (){
    int n;
    cin >> n;
    vector <int> start;
    vector<vector<char>> map(n, vector<char>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map.at(i).at(j);
            if(map.at(i).at(j) == 'P'){
                start.push_back(i);
                start.push_back(j);
            }
        }
    }

    vector<vector<vector<vector<int>>>> dist(n, vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n, 10000000))));
    
    dist.at(start.at(0)).at(start.at(1)).at(start.at(2)).at(start.at(3)) = 0;
    queue<vector<int>> que;
    que.push(start);

    while(!que.empty()){
        vector<int> pos = que.front();
        que.pop();
        int x = pos.at(0);
        int y = pos.at(1);
        int a = pos.at(2);
        int b = pos.at(3);
        if(x==a && y==b){
            cout << dist.at(x).at(y).at(a).at(b) << endl;
            return 0;
        }
        for(int i = -1; i < 2; i++){
            for(int j = -1; j < 2; j++){
                if(i == 0 || j == 0){
                    if(x+i >= 0 && x+i < n && y+j >= 0 && y+j < n && map.at(x+i).at(y+j) != '#' && a+i >= 0 && a+i < n && b+j >= 0 && b+j < n && map.at(a+i).at(b+j) != '#' && dist.at(x+i).at(y+j).at(a+i).at(b+j) == 10000000){   
                        dist.at(x+i).at(y+j).at(a+i).at(b+j) = dist.at(x).at(y).at(a).at(b) + 1;
                        que.push({x+i, y+j, a+i, b+j});
                    }
                    else if(x+i >= 0 && x+i < n && y+j >= 0 && y+j < n && map.at(x+i).at(y+j) != '#' && dist.at(x+i).at(y+j).at(a).at(b) == 10000000){
                        dist.at(x+i).at(y+j).at(a).at(b) = dist.at(x).at(y).at(a).at(b) + 1;
                        que.push({x+i, y+j, a, b});
                    }
                    else if(a+i >= 0 && a+i < n && b+j >= 0 && b+j < n && map.at(a+i).at(b+j) != '#' && dist.at(x).at(y).at(a+i).at(b+j) == 10000000){
                        dist.at(x).at(y).at(a+i).at(b+j) = dist.at(x).at(y).at(a).at(b) + 1;
                        que.push({x, y, a+i, b+j});
                    }
                }
            }
        }
    }

    cout << -1 << endl;
    return 0;
}