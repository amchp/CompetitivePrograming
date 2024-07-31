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
#include <set>

using namespace std;

typedef long long ll;

ll solve(vector<vector<ll> >& g, vector<ll>& droids, vector<ll>& dp, vector<bool>& visited, ll& clones, ll cur){ 
    if(cur == 0){
        ll v = clones;
        if(clones <= droids[cur])v /= 2;
        return v;
    }
    if(dp[cur] != -1)return dp[cur];
    visited[cur] = true;
    ll mClones = 0, v;
    for(int i = 0; i < g[cur].size(); ++i){
        if(!visited[g[cur][i]]){
            v = solve(g, droids, dp, visited, clones, g[cur][i]);
            if(v <= droids[cur])v /= 2;
            mClones = max(mClones, v);
        }
    }
    visited[cur] = false;
    dp[cur] = mClones;
    return mClones;
}

int main(){
    ll n, m, x, y, clones;
    cin >> n >> m;
    vector<vector<ll> > g(n, vector<ll>());
    vector<ll> droids(n);
    for(int i = 0; i < m; ++i){
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    cin >> clones;
    for(int i = 0; i < n; ++i)cin >> droids[i];
    vector<ll> dp(n, -1);
    vector<bool> visited(n, false);
    cout << solve(g, droids, dp, visited, clones, n - 1) << '\n';
}