#include<bits/stdc++.h>

using namespace std;

int main(){
    double d;
    cin >> d;

    int d_dash = 1+round(sqrt(d));

    int min = 99999999;

    for (int x =0; x<=d_dash; x++){
        for(int y=0; y<=x; y++){
            int temp = abs(x*x + y*y - d);
            if(temp < min){
                min = temp;
            }
        }
    }
    
    cout << min << endl;

    return 0;
}