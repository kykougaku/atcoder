#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> ans_vec;
    while(true){
        int w,h;
        cin >> w >> h;
        if(w == 0 && h == 0) break;
        vector<vector<int>> a(h, vector<int>(w));
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> a.at(i).at(j);
            }
        }
        vector<vector<bool>> seen(h, vector<bool>(w, false));
        int ans = 0;

        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(seen.at(i).at(j)) continue;
                if(a.at(i).at(j) == 0) continue;
                ans++;
                stack<pair<int, int>> s;
                s.push(make_pair(i, j));

                while(!s.empty()){
                    pair<int, int> p = s.top();
                    s.pop();
                    int x = p.first;
                    int y = p.second;

                    if(x < 0 || x >= h || y < 0 || y >= w) continue;
                    if(seen.at(x).at(y)) continue;
                    if(a.at(x).at(y) == 0) continue;
                    seen.at(x).at(y) = true;
                    for(int dx = -1; dx <= 1; dx++){
                        for(int dy = -1; dy <= 1; dy++){
                            int nx = x + dx;
                            int ny = y + dy;
                            if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                            if(a.at(nx).at(ny) == 0) continue;
                            if(seen.at(nx).at(ny)) continue;
                            s.push(make_pair(nx, ny));
                        }
                    }
                }
            }
        }
        ans_vec.push_back(ans);
    }
    for(int i = 0; i < ans_vec.size(); i++){
        cout << ans_vec.at(i) << endl;
    }

    return 0;
}