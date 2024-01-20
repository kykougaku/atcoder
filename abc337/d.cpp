#include <bits/stdc++.h>

using namespace std;

int main (){
    int h, w, k;
    cin >> h >> w >> k;
    vector<vector<char>> s(h, vector<char>(w));
    for(int i =0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> s[i][j];
        }
    }
    int ans = k;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(s[i][j] == 'o'){
                int u = 0;
                for(int l = 0; l < h; l++){
                    if(i+l >= h){
                        u = k;
                        break;
                    }
                    if(s[i+l][j] == 'o')
                        continue;
                    else if(s[i+l][j] == '.')
                        u++;
                    else{
                        u = k;
                        break;}
                }

                int d = 0;
                for(int l = 0; l < h; l++){
                    if(i-l < 0){
                        d = k;
                        break;
                    }
                    if(s[i-l][j] == 'o')
                        continue;
                    else if(s[i-l][j] == '.')
                        d++;
                    else{
                        d = k;
                        break;}
                }

                int r = 0;
                for(int l = 0; l < w; l++){
                    if(j+l >= w){
                        r = k;
                        break;
                    }
                    if(s[i][j+l] == 'o')
                        continue;
                    else if(s[i][j+l] == '.')
                        r++;
                    else{
                        r = k;
                        break;}
                }

                int ll = 0;
                for(int l = 0; l < w; l++){
                    if(j-l < 0){
                        ll = k;
                        break;
                    }
                    if(s[i][j-l] == 'o')
                        continue;
                    else if(s[i][j-l] == '.')
                        ll++;
                    else{
                        ll = k;
                        break;}
                }

            
                ans = min(ans, u);
                ans = min(ans, d);
                ans = min(ans, r);
                ans = min(ans, ll);
            }
        }
    }
    cout << ans << endl;
    return 0;
}