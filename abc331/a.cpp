#include<bits/stdc++.h>

using namespace std;

int main(){
    int M, D, y, m, d;
    cin >> M >> D;
    cin >> y >> m>> d;

    if(d+1 > D){
        d = 1;
        if(m+1 > M){
            m = 1;
            y++;
        }
        else{
            m++;
        }
    }
    else{
        d++;
    }

    cout <<y<<" "<<m<<" "<<d<<endl;


    return 0;
}