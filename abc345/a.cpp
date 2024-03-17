#include <bits/stdc++.h>

using namespace std;

int main (){
    string s;
    cin >> s;
    int start = 0;
    int end = 0;
    for(int i =0; i<s.size(); i++){
        if(s.at(i) == '<'){
            start++;
        }
        else if(s.at(i) == '>'){
            end++;
        }
    }
    if(start == 1 and  end == 1){
        cout << "Yes" << endl;
    }
    else{
        cout <<"No" << endl;
    }
    return 0;
}