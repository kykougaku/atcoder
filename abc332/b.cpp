#include <bits/stdc++.h>

using namespace std;

int main (){
    int K,G,M;
    cin >> K >> G >> M;
    int g = 0;
    int m = 0;
    for(int i = 0; i < K; i++){
        if(g == G){
            g = 0;
        }
        else if(m==0){
            m = M;
        }
        else{
            if(g+m<=G){
                g += m;
                m = 0;
            }
            else{
                m -= G-g;
                g = G;
            }
        }
    }
    cout << g<<" "<<m<<endl;
    return 0;
}