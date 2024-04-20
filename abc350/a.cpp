#include <bits/stdc++.h>

using namespace std;

int main (){
    string s;
    cin >> s;
    int n = (s.at(3) - '0')*100 + (s.at(4) - '0')*10 + (s.at(5) - '0');
    if(n == 316){
        cout << "No" << endl;}
    else if(n < 350 and n > 0){
        cout << "Yes" << endl;}
    else{
        cout << "No" << endl;}
    return 0;
}