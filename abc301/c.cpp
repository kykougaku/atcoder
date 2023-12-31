#include <bits/stdc++.h>

using namespace std;

int main (){
    string s,t;
    cin >> s >> t;
    int n = s.size();

    vector<int> s_count(256,0);
    vector<int> t_count(256,0);

    for(int i =0; i<n; i++){
        s_count[s[i]]++;
        t_count[t[i]]++;
    }

    string atcoder = "atcoder";
    for(int i =0; i<atcoder.size(); i++){
        if(s_count[atcoder[i]] > t_count[atcoder[i]]){
            t_count['@'] -= (s_count[atcoder[i]] - t_count[atcoder[i]]);
        }
        else if(s_count[atcoder[i]] < t_count[atcoder[i]]){
            s_count['@'] -= (t_count[atcoder[i]] - s_count[atcoder[i]]);
        }
    }
    if(s_count['@'] < 0 || t_count['@'] < 0){
        cout << "No" << endl;
        return 0;
    }
    else if(s_count['@'] != t_count['@']){
        cout << "No" << endl;
        return 0;
    }

    atcoder += '@';
    for(int i =0; i<atcoder.size(); i++){
        s_count[atcoder[i]] = 0;
        t_count[atcoder[i]] = 0;
    }
    for (int i = 0; i<256; i++){
        if(s_count[i] != t_count[i]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}