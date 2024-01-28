#include <bits/stdc++.h>

using namespace std;

int main (){
    string s;
    cin >> s;
    vector<int> v(26);
    for(int i = 0; i < (int)s.size(); i++){
        v.at(s[i] - 'a')++;
    }

    int max = 0;
    int max_index = 0;
    for(int i = 0; i < 26; i++){
        if(v.at(i) > max) {
            max = v.at(i);
            max_index = i;
        }
    }
    cout << (char)('a' + max_index) << endl;
    return 0;
}