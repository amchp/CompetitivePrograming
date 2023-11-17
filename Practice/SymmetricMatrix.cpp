
#include <cmath>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <cstdlib>
#include <fstream>
#include <iomanip>   
#include <iostream>  
#include <sstream>  // istringstream buffer(myString);
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>

// Useful constants 
#define INF                         (int)1e9 
#define EPS                         1e-9 

#define el '\n'

using namespace std;

int main(){
    int t, n, m;
    bool pass, check;
    cin >> t;
    while(t--){
        cin >> n >> m;
        pass = false;
        check = true;
        int nTiles[n][2][2];
        if(m % 2 == 1)check = false;
        for(int i = 0; i < n; ++i){
            cin >> nTiles[i][0][0] >> nTiles[n][0][1] >>
                   nTiles[i][1][0] >> nTiles[n][1][1];
            if(nTiles[n][0][1] == nTiles[i][1][0])pass = true;
        }
        if(pass && check) cout << "YES" << el;
        else cout << "NO" << el;
    }
}