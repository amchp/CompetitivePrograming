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

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

const int nax = 3e5 + 5;

vi g[nax];
vi visited(nax, 0);
int val[nax];
vi p,ranks, cost;
const int inf =  2e9;
void make_set(int u){
    p[u] = u;
}
int find(int u){
    return p[u] = (p[u] == u ? u : find(p[u])) ;
}
void join(int u, int v){
    int a = find(u), b = find(v);
    if(a == b) return;
    if(ranks[b] > ranks[a])swap(a,b);
    p[b] = a;
    ranks[a] += ranks[b];
}

int main(){
    int n, m;
    cin >> n >> m;
    p.resize(n),ranks.resize(n), cost.resize(n,inf);
    forn(i,n){
        cin>>val[i];
        make_set(i);
    }
    forn(i, m){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].pb(v);
        join(u,v);
    }
    forn(i,n){
        int par = find(i);
        cost[par] = min(cost[par] , val[i]);
    }
    ll ans = 0;
    forn(i,n){
        int par = find(i);

        if(!visited[par])
        {
            visited[par] = 1;
            ans+=cost[par];
        }

    }
    cout<<ans<<"\n";



}