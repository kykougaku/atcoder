#include <bits/stdc++.h>

using namespace std;

int main (){
    int n;
    cin >> n;

    if(n == 1){
        cout << "Not Prime" << endl;
        return 0;
    }
    if(n ==2){
        cout << "Prime" << endl;
        return 0;
    }

    bool is_prime = true;
    for(int i = 2; i <= sqrt(n)+1; i++){
        if(n % i == 0){
            is_prime = false;
        }
    }
    if(is_prime){
        cout << "Prime" << endl;
        return 0;
    }

    if(n % 2 != 0 && n % 5 != 0 && n % 3 != 0){
        cout << "Prime" << endl;
        return 0;
    }
    cout << "Not Prime" << endl;
    return 0;
}