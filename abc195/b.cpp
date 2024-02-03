#include <bits/stdc++.h>

using namespace std;

int main (){
    int a, b, w;
    cin >> a >> b >> w;
    w *= 1000;
    int min = w / b;
    if(w % b != 0)
        min++;
    int max = w / a;
    if(min <= max)
        cout << min << " " << max << endl;
    else
        cout << "UNSATISFIABLE" << endl;
    return 0;
}