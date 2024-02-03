#include <bits/stdc++.h>

using namespace std;

int main (){
    int h, w, n;
    cin >> h >> w >> n;
    int t = 0;
    int x = 0;
    int y = 0;
    vector<vector<char>> a(h, vector<char>(w, '.'));

    for(int i = 0; i < n; i++){
        if(a.at(y).at(x) == '.'){
            a.at(y).at(x) = '#';
            t = (t+1)%4;
        }
        else if (a.at(y).at(x) == '#'){
            a.at(y).at(x) = '.';
            t = (t+3)%4;
        }

        if(t == 0){
            y = (y+h-1)%h;
        }
        else if(t == 1){
            x = (x+1)%w;
        }
        else if(t == 2){
            y = (y+1)%h;
        }
        else if(t == 3){
            x = (x+w-1)%w;
        }
    }

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cout << a.at(i).at(j);
        }
        cout << endl;
    }
    return 0;
}