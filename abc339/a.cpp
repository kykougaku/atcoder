#include <bits/stdc++.h>

using namespace std;

int main (){
    string s;
    cin >> s;

    int lastdot;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '.'){
            lastdot = i;
        }
    }
    for(int i = lastdot+1; i < s.size(); i++){
        cout << s[i];
    }
    return 0;
}