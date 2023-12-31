#include <bits/stdc++.h>

using namespace std;

int two_to10(string s){
    int res = 0;
    for (int i = s.size(); i>=0; i--){
        res += int(s[i]) * pow(2, s.size()-i);
    }
    return res;
}

int main (){
    string s;
    int n;
    cin >> s >> n;

    return 0;
}