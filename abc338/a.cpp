#include <bits/stdc++.h>

using namespace std;

int main (){
    string s;
    cin >> s;
    if ('A' <= s[0] && s[0] <= 'Z'){
        for(int i = 1; i < s.size(); i++){
            if ('a' <= s[i] && s[i] <= 'z') continue;
            else{
                cout << "No" << endl;
                return 0;
            }
        }
        cout << "Yes" << endl;
        return 0;
    }
    else{
        cout << "No" << endl;
        return 0;
    }
}