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

#define forn(i, n) for(int i = 0; i < (int)n; ++i)
#define el '\n'
#define pb push_back

typedef long long ll;
typedef vector<int> vi;
const int nax = 2e5 + 200;

vi g[nax];
int color[nax];

void dfs(int i, int p, int col){
    color[i] = col;
    for(int v : g[i]){
        if(color[v] == -1)dfs(v, i, !col);
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n;
    cin >> n;
    memset(color, -1, sizeof(color));
    forn(i, n - 1){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0, -1, 0);
    int w = 0, b = 0;
    forn(i, n){
        if(color[i])w++;
        else b++;
    }
    cout << min(w - 1, b - 1) << el;
}