#include <bits/stdc++.h>

using namespace std;

bool check_heihou(int a){
    int b = sqrt(a);
    if(b*b == a) return true;
    else return false;
    }


int main (){
    int n;
    cin >> n;
    vector<int> a(n);
    int cntn0 = 0;
    for(int i = 0; i < n; i++){
        cin >> a.at(i);
        if(a.at(i) == 0) cntn0++;
    }
    int cnt = 0;
    if(cntn0>0){
        cnt += (n-cntn0)*cntn0+cntn0*(cntn0-1)/2;
    }
    vector<int> b(1000000,0);
    for(int i = 0; i < n; i++){
        if(a.at(i) == 0) continue;
        int temp = 0;
        int sqrt_a = sqrt(a.at(i));
        for(int j = 1; j<=sqrt_a+1; j++){
            if(a.at(i)%(j*j) == 0){
                temp = a.at(i)/(j*j);
            }
        }
        b.at(temp)++;
    }
    for(int i = 1; i < 1000000; i++){
        if(b.at(i) == 0) continue;
        if(b.at(i) == 1) continue;
        cnt += b.at(i)*(b.at(i)-1)/2;
    }
    cout << cnt << endl;
    return 0;
}