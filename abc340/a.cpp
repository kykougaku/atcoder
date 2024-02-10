#include <bits/stdc++.h>

using namespace std;

int main (){
    int a,b,d;
    cin >> a >> b >> d;
    for(int i = a; i <= b; i+=d){
        if(i == a){
            cout << i;
        }
        else{
            cout << " " << i;
        }
    }
    return 0;
}