#include <bits/stdc++.h>
using namespace std;

int sum = 0;

int search(int h, int w, vector<vector<int>>& a){
    set <int> s;
    if(h==0 && w==0){
        return 1;
    }
    else if (h-1>=0){
        s.insert(search(h-1, w, a));
    }
    else if (w-1>=0){
        s.insert(search(h, w-1, a));
    }
}
int main(){
    int h,w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin >> a.at(i).at(j);
        }
    }


    return 0;
}