#include <bits/stdc++.h>

using namespace std;

int main (){
    int n;
    cin >> n;
    vector<vector<int>> input(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>input.at(i).at(j);
        }
    }
    vector<vector<int>> v(n);
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(input.at(i).at(j) == 1){
                v.at(i).push_back(j+1);
                v.at(j).push_back(i+1);
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < v.at(i).size(); j++){
            cout << v.at(i).at(j) << " ";
        }
        cout << endl;
    }
    return 0;
}