#include <bits/stdc++.h>

using namespace std;

int main (){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a.at(i);
    }

    vector<int> b;
    for(int i = 0; i < n-1; i++) {
        b.push_back(a.at(i));
        if(a.at(i+1) - a.at(i) > 1) {
            for(int j = a.at(i)+1; j < a.at(i+1); j++) {
                b.push_back(j);
            }
        }
        else if(a.at(i+1) - a.at(i) < -1) {
            for(int j = a.at(i)-1; j > a.at(i+1); j--) {
                b.push_back(j);
            }
        }
    }
    b.push_back(a.at(n-1));

    for(int i = 0; i < b.size(); i++) {
        cout << b.at(i) << " ";
    }

    return 0;
}