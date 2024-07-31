#include <algorithm>
#include <array>
#include <cassert>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream> // istringstream buffer(myString);
#include <stack>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define for1(i, n) for (int i = 1; i <= (int)n; ++i)
#define all(v) v.begin(), v.end()
#define el '\n'
#define pb push_back
#define d(x) cout << #x << " " << x << el

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> ii;

const int nax = 3e5 + 5;

vi g[nax];
vi color(nax, -1);
int dp[nax];
bool visited[nax];

void dfs2(int i, int col){
    color[i] = col;
    for(int v : g[i]){
        if(color[v] != -1){
            if(color[v] == col){
                dp[i]++;
                dp[v]++;
            }else{
                dp[i]--;
                dp[v]--;
            }
        }
    }
    assert(dp[i] <= 1);
    for(int v : g[i]){
        if(color[v] != -1 && dp[v] > 1){
            dfs2(v, !color[v]);
        }
    }
}


void dfs(int i, int col){
    color[i] = col;
    for(int v : g[i]){
        if(color[v] == -1){
            dfs(v,!col);
        }else if(!visited[v] && color[v] == col){
            dp[i]++;
            dp[v]++;
        }
    }
    visited[i] = true;
}
int main(){
    int n, m;
    cin >> n >> m;
    forn(i, m){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    forn(i, n){
        if(color[i] == -1){
            dfs(i, 0);
        }
    }
    forn(i, n){
        if(dp[i] > 1)dfs2(i, !color[i]);
    }
    forn(i, n){
        cout << color[i];
    }
    cout << el;
}