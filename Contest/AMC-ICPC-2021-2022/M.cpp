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
#define ford(i, n) for (int i = n - 1; i > -1; --i)
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define el "\n"

typedef pair<int, int> ii;
typedef vector<int> vi;

const int nax = 1e5+10;
vi g[nax];
int in[nax];
int t = -1;
int timeToNode[nax];
void dfs(int u){
    in[u] = ++t;
    timeToNode[t] = u;
    for(int v: g[u]){
        dfs(v);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin>>q;
    int idx = 1;
    vector<vi> queries(q);
    forn(i,q){
        int k,x;
        cin>>k>>x;
        queries[i] = {k,x};
        if(k==1){
            g[x].pb(++idx);
        }
    }
    dfs(1);
    set<int> s;
    s.insert(in[1]);
    idx = 1;
    forn(i,q){
        int k = queries[i][0], x = queries[i][1];
        if(k == 1){
            s.insert(in[++idx]);
        }else{
            s.erase(in[x]);
            int ans = *s.begin();
            cout<<timeToNode[ans]<<el;
        }
    }

}