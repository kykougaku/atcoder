#include <bits/stdc++.h>

using namespace std;

int main (){
    long long n;
    cin >> n;
    for(long long i = 1000000; i > 0; i--){
        if(n < i*i*i) continue;
        string s = to_string(i*i*i);
        vector<int> v(s.size());
        for(int j = 0; j < s.size(); j++){
            v.at(j) = s.at(j) - '0';
        }
        bool flag = true;
        for(int j = 0; j < v.size()/2; j++){
            if(v.at(j) != v.at(v.size()-1-j)){
                flag = false;
            }
        }
        if(flag){
            cout << i*i*i << endl;
            return 0;
        }
    }
    return 0;
}