#include <bits/stdc++.h>

using namespace std;

int main (){
    string s, t;
    cin >> s >> t;
    int length = 3;
    if(t.at(2) == 'X'){
        length = 2;
    }
    int now = 0;
    for(int i = 0; i < s.size(); i++){
        if(now >= length){
            cout << "Yes" << endl;
            return 0;
        }
        if(t.at(now) + 32 == s.at(i)){
            now++;
        }
    }
    if(now >= length){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}