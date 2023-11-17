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
#include <math.h>
#include <unordered_map>
#include <queue>
#include <array>

// Useful constants 
#define INF                         (int)2e9 
#define EPS                         1e-9

#define el '\n'

#define MAXN                         (int)2e5

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x, y, c;
    cin >> n;
    char a[n][n];
    int dir[4][2] = {{0,-1}, {-1,0}, {1,0}, {0,1}};
    bool pass = true;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j)cin >> a[i][j];
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            c = 0;
            for(int k = 0; k < 4; ++k){
                x = i + dir[k][0];
                y = j + dir[k][1];
                if(x > -1 && x < n && y > -1 && y < n && a[x][y] == 'o')c++;
            }
            if(c % 2 != 0){
                pass = false;
                goto end;
            }
        }
    }
    end:
    if(pass)cout << "YES" << el;
    else cout << "NO" << el;
}