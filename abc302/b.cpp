#include <bits/stdc++.h>

using namespace std;

int main (){
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for(int i=0; i<h; i++){
        cin >> s[i];
    }

    string nuke = "nuke";
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(s[i][j] == 's'){
                for(int k=-1; k<=1; k++){
                    for(int l=-1; l<=1; l++){
                        for(int m=1; m<=4; m++){
                            if(i+k*m >= 0 && i+k*m < h && j+l*m >= 0 && j+l*m < w){
                                if(s[i+k*m][j+l*m] == nuke[m-1]){
                                    if(m == 4){
                                        cout << i+1 << " " << j+1 << endl;
                                        cout << i+1+k*1 << " " << j+1+l*1 << endl;
                                        cout << i+1+k*2 << " " << j+1+l*2 << endl;
                                        cout << i+1+k*3 << " " << j+1+l*3 << endl;
                                        cout << i+1+k*4 << " " << j+1+l*4 << endl;
                                        return 0;
                                    }
                                }
                                else break;
                            }
                            else{
                                break;
                            }
                        }   
                    }
                }
            }
        }
    }
}