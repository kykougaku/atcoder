#include <bits/stdc++.h>

using namespace std;

int main (){
    string wb = "wbwbwwbwbwbw";
    string wb2 = wb + wb;
    for(int i = 0; i < 30; i++){
        wb2 += wb;
    }
    int w, b;
    cin >> w >> b;
    string ans = "No";

    for(int i = 0; i < wb2.size(); i++){
        for(int j = i; j < wb2.size(); j++){
            string subwb2 = wb2.substr(i, j-i+1);
            int cntw = 0;
            int cntb = 0;
            for(int k = 0; k < subwb2.size(); k++){
                if(subwb2.at(k) == 'w'){
                    cntw++;
                }else if(subwb2.at(k) == 'b'){
                    cntb++;
                }
            }
            if(cntw == w && cntb == b){
                ans = "Yes";
                cout << ans << endl;
                return 0;
            }
        }
    }

    cout << ans << endl;
    return 0;
}