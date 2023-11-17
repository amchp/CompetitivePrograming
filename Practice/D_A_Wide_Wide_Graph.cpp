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
const int maxn = 1e5 + 5;
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
vi g[maxn];

pii dfs(int i, int p){
    int ans = 0;
    int node = i;
    forn(j, g[i].size()){
        if(g[i][j] == p)continue;
        pii cur = dfs(g[i][j], i);
        if(ans < cur.first){
            ans = cur.first;
            node = cur.second;
        }
    }
    return mp(ans + 1, node);
}

vi dfs2(int i, int p, int& corner){
    if(i == corner){
        vi ans;
        ans.pb(i);
        return ans;
    }
    forn(j, g[i].size()){
        if(g[i][j] == p)continue;
        vi cur = dfs2(g[i][j], i, corner);
        if(cur.size()){
            cur.pb(i);
            return cur;
        }
    }
    vi ans;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    cin >> n;
    forn(i, n-1){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    int corner1 = dfs(0, -1).second;
    pii p = dfs(corner1, -1);
    int corner2 = p.second;
    int dist = p.first;
    // cout << corner1 << ' ' << corner2 << ' ' << dist << nl;
    vi path = dfs2(corner1, -1, corner2);
    // forn(i, path.size()){
    //     cout << path[i] << ' ';
    // }
    // cout << nl;
    queue<int> q, qq;
    vector<bool> visited(n, false);
    q.push(path[dist / 2]);
    if(dist % 2 == 0)q.push(path[dist / 2 - 1]);
    vi ans(n, 1);
    int ind = max(dist / 2, 1);
    int curAns = 1;
    while(ind < n && !q.empty()){
        swap(q, qq);
        while(!qq.empty()){
            int u = qq.front();
            qq.pop();
            if(visited[u])continue;
            visited[u] = true;
            curAns = min(n, curAns + 1);
            forn(j, g[u].size()){
                q.push(g[u][j]);
            }
        }
        ans[ind] = curAns;
        ind++;
    }
    while(ind < n){
        ans[ind] = n;
        ind++;
    }
    forn(i, n){
        cout << ans[i] << ' ';
    }
    cout << nl;
}