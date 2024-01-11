#include <bits/stdc++.h>

using namespace std;

int main (){
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for(int i=0;i<n;i++){
        cin >> x[i] >> y[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                float dx1 = x[j] - x[i];
                float dx2 = x[k] - x[i];
                float dy1 = y[j] - y[i];
                float dy2 = y[k] - y[i];
                if(dx2==0){
                    if(dx1==0){
                        cout << "Yes" << endl;
                        return 0;
                    }
                    else{
                        continue;
                    }
                }
                else if(dy2==0){
                    if(dy1==0){
                        cout << "Yes" << endl;
                        return 0;
                    }
                    else{
                        continue;
                    }
                }
                else if (dx1/dx2 == dy1/dy2){
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}