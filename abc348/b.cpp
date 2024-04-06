#include <bits/stdc++.h>

using namespace std;

int main (){
    int n;
    cin >> n;
    vector<long long> x(n), y(n);

    for (int i = 0; i < n; i++){
        cin >> x.at(i) >> y.at(i);
    }

    vector<vector<long long>> dist(n, vector<long long>(2,-1));

    for(int i = 0; i < n; i++){

        for(int j = 0; j < n; j++){
            long long ijdist = (x.at(i) - x.at(j)) * (x.at(i) - x.at(j)) + (y.at(i) - y.at(j)) * (y.at(i) - y.at(j));
            if(ijdist > dist.at(i).at(0)){
                dist.at(i).at(0) = ijdist;
                dist.at(i).at(1) = j;
            }
            else if(ijdist == dist.at(i).at(0)){
                dist.at(i).at(1) = min(dist.at(i).at(1), (long long)j);
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << dist.at(i).at(1) + 1 << endl;
    }

    return 0;
}