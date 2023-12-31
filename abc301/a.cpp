#include <bits/stdc++.h>

using namespace std;

int main (){
    int n;
    cin >> n;
    vector<char> s(n);
    int t = 0;
    int a = 0;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        if (s[i] == 'T') {
            t++;
        }
        else {
            a++;
        }
    }
    if (t > a) {
        cout << "T" << endl;
    }
    else if (t < a) {
        cout << "A" << endl;
    }
    else {
        if (s[n-1] == 'A') {
            cout << "T" << endl;
        }
        else {
            cout << "A" << endl;
        }
    }


    return 0;
}