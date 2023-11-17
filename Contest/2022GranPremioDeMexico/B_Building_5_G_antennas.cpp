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
#include <numeric>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define forn(i, n) for(int i = 0; i < (int)n; ++i)

void dfs(vector<vector<int> >& g, priority_queue<int, std::vector<int>, std::greater<int> >& pq, vector<int>& seen, int i, int k){
    if(k == -1)return;
    if(seen[i] >= k)return;
    if(seen[i] == -1){
        pq.push(i); 
    }
    seen[i] = k;
    forn(j, g[i].size()){
        dfs(g, pq, seen, g[i][j], k-1);
    }
}

int main(){
    ll n, m, k, x, y;
    cin >> n >> k;
    vector<vector<int> > g(n, vector<int>());
    forn(i, n - 1){
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    // forn(i, n){
    //     cout << "i " << i << '\n';
    //     forn(j, g[i].size()){
    //         cout << g[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    priority_queue<int, std::vector<int>, std::greater<int> > pq;
    vector<int> seen(n,  -1);
    vector<ll> ans;
    pq.push(0);
    seen[0] = 0;
    int ind = 1;
    while(!pq.empty()){
        int cur = pq.top();
        ans.push_back(cur);
        pq.pop();
        dfs(g, pq, seen, cur, k);
    }
    forn(i, ans.size()){
        cout << ans[i] + 1 << ' ';
    }
    cout << '\n';
}