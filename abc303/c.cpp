#include <bits/stdc++.h>
using namespace std;

int main(){
    int sssize = 404000;
    int n,m,h,k;
    cin >> n >> m >> h >> k;
    string s;
    cin >> s;
    set <pair<int,int>> item;
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        item.insert({x,y});
    }
    int x,y;
    x = y = 0;
    for(int i=0;i<n;i++){
        if(s[i] == 'R'){
            x++;
            h--;
        }
        else if(s[i] == 'L'){
            x--;
            h--;
        }
        else if(s[i] == 'U'){
            y++;
            h--;
        }
        else if(s[i] == 'D'){
            y--;
            h--;
        }

        if(h < 0){
            cout << "No" << endl;
            return 0;
        }
        if(i == n-1){
            cout << "Yes" << endl;
            return 0;
        }

        if(item.count({x,y}) && h < k){
            item.erase({x,y});
            h = k;
        }
    }
}