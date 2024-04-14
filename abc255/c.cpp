#include <bits/stdc++.h>

using namespace std;

int main (){
    long long x,a,d,n;
    cin >> x >> a >> d >> n;
    if(d>=0){
        if(x<=a){
            cout << a-x << endl;
        }
        else if(a+(n-1)*d <= x){
            cout << x - (a+(n-1)*d) << endl;
        }
        else{
            long long marume = (x-a)/d;
            cout << min(x-(a+marume*d), (marume+1)*d+a-x) << endl;
        }
    }
    else{
        if(x>=a){
            cout << x-a << endl;
        }
        else if(a+(n-1)*d >= x){
            cout << (a+(n-1)*d) - x << endl;
        }
        else{
            long long marume = (a-x)/(-d);
            cout << min(a+marume*d-x, x-((marume+1)*d+a)) << endl;
        }
    }
    return 0;
}