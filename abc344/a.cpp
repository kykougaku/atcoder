#include <bits/stdc++.h>

using namespace std;

int main (){
    string s;
    cin >> s;
    vector<char> v;
    bool flag = false;
    for (int i = 0; i < s.size(); i++){
        if(s.at(i) == '|' and flag == false){
            flag = true;
            continue;
        }
        else if(s.at(i) == '|' and flag == true){
            flag = false;
            continue;
        }
        if(flag == false){
            v.push_back(s.at(i));
        }
    }
    for(int i = 0; i < v.size(); i++){
        cout << v.at(i);
    }
    cout << endl;
    return 0;
}