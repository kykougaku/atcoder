#include <bits/stdc++.h>

using namespace std;

int main (){
    int w, h;
    cin >> w >> h;
    vector<vector<int>> map(h, vector<int>(w, 0));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> map.at(i).at(j);
        }
    }
    return 0;
}