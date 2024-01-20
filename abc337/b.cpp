#include <bits/stdc++.h>

using namespace std;

int main (){
    string s;
    cin >> s;
    int mode = 1;

    for(int i = 0; i < s.size(); i++){
        if(mode == 1){
            if(s[i] == 'A')
                mode = 1;
            else if(s[i] == 'B')
                mode = 2;
            else if(s[i] == 'C')
                mode = 3;
        }else if(mode == 2){
            if(s[i] == 'C')
                mode = 3;
            else if(s[i] == 'A'){
                cout << "No" << endl;
                return 0;
            }
            else if(s[i] == 'B')
                mode = 2;
        }else if(mode == 3){
            if(s[i] == 'A'){
                cout << "No" << endl;
                return 0;
            }
            else if(s[i] == 'B'){
                cout << "No" << endl;
                return 0;
            }
            else if(s[i] == 'C')
                mode = 3;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
