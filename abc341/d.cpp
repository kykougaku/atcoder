#include <bits/stdc++.h>

using namespace std;


int main (){
    long long n,m,k;
    cin >> n >> m >> k;
    long long lcm = n*m/gcd(n,m);

    long long nn = lcm/n;
    long long mm = lcm/m;

    long long size = nn+mm-2;
    long long ks = k/size;
    long long kmods = k%size;

    long long index = 1;
    long long ni = 1;
    long long mi = 1;
    long long last = 0;
    if(kmods != 0){
        while(true){
            
            if(ni*n < mi*m){
                last = ni*n;
                ni++;
            }
            else{
                last = mi*m;
                mi++;
            }
            if(index == kmods){
                break;
            }
            index++;
        }

        cout << ks*lcm+last << endl;


        return 0;
    }
    else{

        if((mm-1)*m < (nn-1)*n){
            last = (nn-1)*n;
        }else{
            last = (mm-1)*m;
        }

        cout << (ks-1)*lcm+last << endl;
        return 0;   
    }
}