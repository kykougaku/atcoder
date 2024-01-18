#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<char>> &s, vector<vector<bool>> &seen, int h, int w, int x, int y, bool &flag){
    if(x<0 || x>=h || y<0 || y>=w)return;
    if(s.at(x).at(y) == '#' || seen.at(x).at(y)) return;

    seen.at(x).at(y) = true;

    if(s.at(x).at(y) == 'g'){
        flag = true;
        return;
    }

    dfs(s, seen, h, w, x+1, y, flag);
    dfs(s, seen, h, w, x-1, y, flag);
    dfs(s, seen, h, w, x, y+1, flag);
    dfs(s, seen, h, w, x, y-1, flag);
}
int main(){
    int h, w, sx, sy;
    cin >> h >> w;
    vector<vector<char>> s(h, vector<char>(w));
    vector<vector<bool>> seen(h, vector<bool>(w, false));
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin >> s[i][j];
            if(s[i][j] == 's'){
                sx = i;
                sy = j;
            }
        }
    }

    bool flag = false;
    dfs(s, seen, h, w, sx, sy, flag);
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}