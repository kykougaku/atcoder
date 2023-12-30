#include <bits/stdc++.h>

using namespace std;

int main (){
    int h, w;
    cin>>h>>w;
    vector<vector<int>> a(h, vector<int>(w));
    vector<vector<int>> b(h, vector<int>(w));
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            char temp;
            cin>>temp;
            if (temp == '#'){
                a[i][j] = 1;
            } else {
                a[i][j] = 0;
            }
        }
    }
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            char temp;
            cin>>temp;
            if (temp == '#'){
                b[i][j] = 1;
            } else {
                b[i][j] = 0;
            }
        }
    }

    for(int s=0; s<h; s++){
        for(int t=0; t<w; t++){
            //check
            bool flag = true;
            for(int i=0; i<h; i++){
                for(int j=0; j<w; j++){
                    if (a[(i-s+h)%h][(j-t+w)%w] != b[i][j]){
                        flag = false;
                    }
                }
            }
            if (flag){
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }
    cout<<"No"<<endl;
    return 0;

}