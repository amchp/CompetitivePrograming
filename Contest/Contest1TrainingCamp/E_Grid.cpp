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
#include <tuple>


// Useful constants 
#define INF                         (int)2e9 
#define EPS                         1e-9

#define el '\n'

#define MAXN                         (int)2e5

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
int visited[500][500];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    char c;
    cin >> n >> m;
    vector<vi> v(n, vi(m));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> c;
            v[i][j] = c - '0';
             visited[i][j] = INF;
        }
    }

    int dir[4][2] = {{0,-1}, {-1,0}, {1, 0}, {0,1}};
    queue<pi> q;
    pi p;
    int i, j, x, y;
    int ans = 0;
    bool pass = false;
    visited[0][0] = 0;
    q.push(pi(0, 0));
    while(!q.empty()){
        p = q.front(); q.pop();
        i = p.first;
        j = p.second;
        if(i == n - 1 && j == m - 1){
            break;
        }
        
        for(int k = 0; k < 4; ++k){
            x = dir[k][0]*v[i][j] + i;
            y = dir[k][1]*v[i][j] + j;
            if(x > -1 && x < v.size() && y > -1 && y < v[0].size() && visited[i][j] + 1 < visited[x][y]){
                visited[x][y] = visited[i][j] + 1;
                q.push(make_pair(x, y));
            }
        }
    }
    if(visited[n - 1][m - 1] != INF)cout << visited[n - 1][m - 1] << el;
    else cout << "IMPOSSIBLE" << el;
}