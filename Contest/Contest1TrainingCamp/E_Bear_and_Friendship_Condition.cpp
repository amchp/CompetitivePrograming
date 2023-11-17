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

int n, m;
vi visited(150000, 0);
int curGroup = 0;
vector<vi> group;
vector<vi> g(150000);

int dfs(int v){
    visited[v] = true;
    group[]
    for (int i = 0; i < g[v].size(); ++i) {
        if (!visited[g[v][i]])dfs(g[v][i]);
    }
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int u, v;
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 0; i < n; ++i){
        group
        if(!visited[i])dfs(i);
    }
}