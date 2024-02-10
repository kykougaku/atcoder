#include <bits/stdc++.h>

using namespace std;

int main (){
    int64_t q;
    cin >> q;
    vector<int64_t> type(q), x(q);
    for(int64_t i = 0; i < q; i++){
        cin >> type.at(i) >> x.at(i);
    }
    vector<int64_t> a;
    for(int64_t i = 0; i < q; i++){
        if(type.at(i) == 1){
            a.push_back(x.at(i));
        }
        else if(type.at(i) == 2){
            cout << a.at(a.size()-x.at(i)) << endl;
        }
    }
    return 0;
}