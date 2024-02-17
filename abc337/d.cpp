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
        int block =-1;
        for(int j = 0; j < w; j++){
            if(v.at(i).at(j) == 'x'){
                counto = 0;
                countdot = 0;
                block = j;
            }
            else if(v.at(i).at(j) == 'o'){
                counto++;
            }
            else if(v.at(i).at(j) == '.'){
                countdot++;
            }

            if(j-block < k) continue;

            if(j-k>=0 and v.at(i).at(j-k) == 'o'){
                counto--;
            }
            else if(j-k>=0 and v.at(i).at(j-k) == '.'){
                countdot--;
            }

            ans = min(ans, countdot);
        }
    }

    for(int i = 0; i < w; i++){
        int counto = 0;
        int countdot = 0;
        int block = -1;
        for(int j = 0; j < h; j++){
            if(v.at(j).at(i) == 'x'){
                counto = 0;
                countdot = 0;
                block = j;
            }
            else if(v.at(j).at(i) == 'o'){
                counto++;
            }
            else if(v.at(j).at(i) == '.'){
                countdot++;
            }

            if(j-block < k) continue;


            if(j-k>=0 and v.at(j-k).at(i) == 'o'){
                counto--;
            }
            else if(j-k>=0 and v.at(j-k).at(i) == '.'){
                countdot--;
            }

            ans = min(ans, countdot);

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