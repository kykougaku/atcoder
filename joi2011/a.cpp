#include <bits/stdc++.h>

using namespace std;

int main (){
    int n, m, k;
    cin >> m >> n >> k;
    vector<vector<char>> ma(m, vector<char>(n));
    vector<vector<int>> mapj(m+1, vector<int>(n+1,0));
    vector<vector<int>> mapo(m+1, vector<int>(n+1,0));
    vector<vector<int>> mapi(m+1, vector<int>(n+1,0));
    vector<int> a(k), b(k), c(k), d(k);
    for(int i =0; i<m; i++){
        for(int j = 0; j<n; j++){
            cin >> ma.at(i).at(j);
            int tempi = 0, tempo = 0, tempj = 0;
            if(ma.at(i).at(j) == 'J') tempi = 1;
            else if(ma.at(i).at(j) == 'O') tempo = 1;
            else if(ma.at(i).at(j) == 'I') tempj = 1;
            mapj.at(i+1).at(j+1) = mapj.at(i).at(j+1) + mapj.at(i+1).at(j) - mapj.at(i).at(j) + tempi;
            mapo.at(i+1).at(j+1) = mapo.at(i).at(j+1) + mapo.at(i+1).at(j) - mapo.at(i).at(j) + tempo;
            mapi.at(i+1).at(j+1) = mapi.at(i).at(j+1) + mapi.at(i+1).at(j) - mapi.at(i).at(j) + tempj;
        }
    }
    for(int i = 0; i<k; i++){
        cin >>a.at(i) >> b.at(i) >> c.at(i) >> d.at(i);
        a.at(i)--; b.at(i)--;
    }
    for(int i =0; i<k; i++){
        cout << mapj.at(c.at(i)).at(d.at(i)) - mapj.at(a.at(i)).at(d.at(i)) - mapj.at(c.at(i)).at(b.at(i)) + mapj.at(a.at(i)).at(b.at(i)) << " ";
        cout << mapo.at(c.at(i)).at(d.at(i)) - mapo.at(a.at(i)).at(d.at(i)) - mapo.at(c.at(i)).at(b.at(i)) + mapo.at(a.at(i)).at(b.at(i)) << " ";
        cout << mapi.at(c.at(i)).at(d.at(i)) - mapi.at(a.at(i)).at(d.at(i)) - mapi.at(c.at(i)).at(b.at(i)) + mapi.at(a.at(i)).at(b.at(i)) << endl;
    }
    return 0;
}