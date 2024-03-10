#include <bits/stdc++.h>

using namespace std;

int main (){
    stack<long long> s;
    while(true){
        long long a;
        cin >> a;
        s.push(a);
        if(a == 0){
            break;
        }
    }
    long long l = s.size();
    for(int i = 0; i < l; i++){
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}