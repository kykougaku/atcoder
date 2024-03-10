#include <bits/stdc++.h>

using namespace std;

int main (){
    string t;
    cin >> t;
    int n;
    cin >> n;
    vector<vector<string>> s (n, vector<string>());
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a.at(i); 
        for(int j = 0; j < a.at(i); j++){
            string temp;
            cin >> temp;
            s.at(i).push_back(temp);
        }
    }

    while(true){
        int cont = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < a.at(i); j++){
                if(t.starts_with(s.at(i).at(j))){
                    t = t.substr(s.at(i).at(j).size());
                    cont++;
                    break;
                }
            }
        }
        break;
    }
    return 0;
}