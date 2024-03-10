#include <bits/stdc++.h>

using namespace std;

double f(double x, double p){
    return (1.0 - (2.0*p*log(2.0)*pow(2.0, -2.0*x/3.0)/3.0));
}

int main (){
    double p;
    cin >> p;
    double l = 0.0, r = p*2;
    for(int itr = 0; itr < 100000; itr++){
        double mid = (l + r) / 2.0;
        if(f(mid, p) > 0.0){
            r = mid;
        }
        else{
            l = mid;
        }
    }
    cout<<setprecision(20) << r + p*pow(2.0, -r/1.5) << endl;
    return 0;
}