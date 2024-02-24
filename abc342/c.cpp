#include <bits/stdc++.h>

using namespace std;



int main (){
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    int q;
    cin >> q;
    vector<char> c(q), d(q);
    vector<int> map(26);
    for(int i = 0; i < 26; i++){
        map.at(i) = i;
    }
    for(int i = 0; i < q; i++){
        cin >> c.at(i) >> d.at(i);
        for(int j = 0; j < 26; j++){
            if(map.at(j) == c.at(i)-'a'){
                map.at(j) = d.at(i)-'a';
            }
        }
    }

    for(int i = 0; i < n; i++){
        s.at(i) = map.at(s.at(i)-'a')+'a';
    }
    cout << s << endl;
    return 0;
}