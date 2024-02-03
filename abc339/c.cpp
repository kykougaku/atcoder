#include <bits/stdc++.h>

using namespace std;

int main (){
    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    for(int64_t i = 0; i < n; i++){
        cin >> a.at(i);
    }
    int64_t min = 100000000000000;
    int64_t sum = 0;
    for(int64_t i = 0; i < n; i++){
        sum += a.at(i);
        if(sum < min){
            min = sum;
        }
    }

    if(min >= 0){
        cout << 0+sum << endl;
    }
    else{
        cout << abs(min)+sum << endl;
    }

    return 0;
}