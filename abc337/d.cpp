#include <bits/stdc++.h>

using namespace std;

int main (){
    int h,w,k;
    cin >> h >> w >> k;
    vector<vector<char>> v(h, vector<char>(w));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> v.at(i).at(j);
        }
    }

    int ans = 1000000;

    for(int i = 0; i < h; i++){
        int counto = 0;
        int countdot = 0;
        for(int j = 0; j < w; j++){
            if(v.at(i).at(j) == 'x'){
                counto = 0;
                countdot = 0;
            }
            else if(v.at(i).at(j) == 'o'){
                counto++;
                counto = min(counto, k);
            }
            else if(v.at(i).at(j) == '.'){
                countdot++;
                countdot = min(countdot, k);
            }

            if(counto+countdot >= k){
                ans = min(ans, k-counto);
            }
        }
    }

    for(int i = 0; i < w; i++){
        int counto = 0;
        int countdot = 0;
        for(int j = 0; j < h; j++){
            if(v.at(j).at(i) == 'x'){
                counto = 0;
                countdot = 0;
            }
            else if(v.at(j).at(i) == 'o'){
                counto++;
                counto = min(counto, k);
            }
            else if(v.at(j).at(i) == '.'){
                countdot++;
                countdot = min(countdot, k);
            }

            if(counto+countdot >= k){
                ans = min(ans, k-counto);
            }
        }
    }

    if(ans == 1000000){
        cout << -1 << endl;
    }
    else{
        cout << ans << endl;
    }
    return 0;
}