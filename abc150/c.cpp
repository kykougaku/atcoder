#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> p(n);
    vector<int> q(n);
    for(int i=0; i<n; i++){
        cin >> p.at(i);
    }
    for(int i=0; i<n; i++){
        cin >> q.at(i);
    }

    vector<int> v(n);
    for(int i=0; i<n; i++){
        v.at(i) = i+1;
    }

    int a, b;
    int count = 0;

    do{
        for(int i=0; i<n; i++){
            if(v.at(i) != p.at(i)){
                break;
            }
            if(i == n-1){
                a = count;
            }
        }

        for(int i=0; i<n; i++){
            if(v.at(i) != q.at(i)){
                break;
            }
            if(i == n-1){
                b = count;
            }
        }
        count++;
    }while(next_permutation(v.begin(), v.end()));

    cout <<abs(a-b) << endl;

    return 0;
}