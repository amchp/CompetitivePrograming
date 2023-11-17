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
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi; // int vec
typedef vector<ll> vll; // int vec
typedef vector<vi> vvi; // int vec vec
typedef vector<vll> vvll; // int vec
typedef vector<pii> vpi; // int int pair vec
typedef vector<pll> vpll; // int int pair vec

const double pi = 3.1415926535897932384626433832795;
const int maxn = 3000 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ll INFLL = 1000000000000000005LL;
const ld EPS = 1e-9;
int dirx[8] = { -1, 0, 0, 1, -1, -1, 1, 1 };
int diry[8] = { 0, 1, -1, 0, -1, 1, -1, 1 };

#define d(x) cout << #x << " = " << x << endl;
#define ios ios_base::sync_with_stdio(0), cin.tie(0);
#define forn(i, n) for (int i=0; i< (int)n; ++i) 
#define forab(i, a, b) for (int i=a; i< (int)b; ++i) 
#define foreach(a, b) for (auto&(a) : (b))
#define formap(map) for (const auto &[key, value] : map)
#define all(v) v.begin(), v.end()
#define allar(arr, sz) arr, arr + sz
#define ms(ar, val) memset(ar, val, size)
#define pq(type) priority_queue<type> 
#define pqd(type) priority_queue<type,vector<type>,greater<type> >
#define umap unordered_map
#define uset unordered_set
#define imax INT_MAX
#define imin INT_MIN
#define pb push_back
#define mp make_pair
#define fi first 
#define se second 
#define nl "\n"
#define in(t) while (t--)

int n;
map<int, int> g[maxn];
ll ans = 0;
set<int> s;

void dfs(int node, int prev){
    ans += *s.lower_bound(0);
    // cout << node <<  ' ';
    // cout << "Add: " << *s.lower_bound(0) << nl;
    for(map<int, int>::iterator it = g[node].begin(); it != g[node].end(); it++){
        if((*it).first != prev){
            s.erase((*it).second);
            // cout << "Erase: " << g[node][i].second << nl;
            dfs((*it).first, node);
            // cout << "Insert: " << g[node][i].second << nl;
            s.insert((*it).second);
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int u, v;
    cin >> n;
    forn(i, n - 1){
        cin >> u >> v;
        u--;
        v--;
        g[u][v] = -1;
        g[v][u] = -1;
        s.insert(i);
    }
    queue<int> q;
    queue<int> qq;
    forn(i, n){
        if(g[i].size() == 1)q.push(i);
    }
    s.insert(n - 1);
    int ind = n - 2;
    int node;
    vector<bool> visited(n, false);
    while(!q.empty()){
        swap(q, qq);
        while(!qq.empty()){
            node = qq.front();
            qq.pop();
            for(map<int, int>::iterator it = g[node].begin(); it != g[node].end(); it++){
                if((*it).second == -1){
                    g[node][(*it).first] = ind;
                    g[(*it).first][node] = ind;
                    ind--;
                    if(!visited[(*it).first])q.push((*it).first);
                    visited[(*it).first] = true;
                }
            }
        }
    }
    forn(i, n){
        // cout << i << nl;
        // for(map<int, int>::iterator it = g[i].begin(); it != g[i].end(); it++){
        //     cout << (*it).first << ' ' << (*it).second << nl;
        // }
        dfs(i, -1);
        // cout << nl;
    }
    // cout << ans << nl;
    ans /= 2;
    cout << ans << nl;
}