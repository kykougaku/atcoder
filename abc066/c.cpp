#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    for(int i=0;i<N;i++){
        cin >> a[i];
    }
    vector<int> b(N);
    for(int i=0;i<N;i++){
        if((N-i)%2==0){
            b.at(N-((N-i)/2)) = a.at(i);
        }
        else{
            b.at((N-i)/2) = a.at(i);
        }
    }
    for (int i=0;i<N;i++){
        cout << b.at(i)<< " ";
    }
    return 0;
}