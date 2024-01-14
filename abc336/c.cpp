#include <bits/stdc++.h>

using namespace std;

int main (){
    int64_t n;
    cin >> n;
    n--;
    vector<int> a{0,2,4,6,8};
    int64_t maxx = 0;
    for (int64_t max = 18; max >= 0; max--){
        if(n >= pow(5,max)){
            maxx = max;
            break;
        }
    }
    for(int64_t i = maxx; i >= 0; i--){
        int64_t tmp = n / pow(5,i);
        cout << a[tmp];
        n -= tmp * pow(5,i);
    }

    return 0;
}