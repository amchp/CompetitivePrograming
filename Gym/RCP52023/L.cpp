#include <vector>
#include <map>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream> // istringstream buffer(myString);
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
typedef vector<int> vi;   // int vec
typedef vector<ll> vll;   // int vec
typedef vector<vi> vvi;   // int vec vec
typedef vector<vll> vvll; // int vec
typedef vector<pii> vpi;  // int int pair vec
typedef vector<pll> vpll; // int int pair vec

const double pi = 3.1415926535897932384626433832795;
const int maxn = 2e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ll INFLL = 1000000000000000005LL;
const ld EPS = 1e-9;
int dirx[8] = {-1, 0, 0, 1, -1, -1, 1, 1};
int diry[8] = {0, 1, -1, 0, -1, 1, -1, 1};

// #define d(x) cout << #x << " = " << x << endl;
#define ios ios_base::sync_with_stdio(0), cin.tie(0);
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define forab(i, a, b) for (int i = a; i < (int)b; ++i)
#define foreach(a, b) for (auto &(a) : (b))
#define formap(map) for (const auto &[key, value] : map)
#define all(v) v.begin(), v.end()
#define allar(arr, sz) arr, arr + sz
#define ms(ar, val) memset(ar, val, size)
#define pq(type) priority_queue<type>
#define pqd(type) priority_queue<type, vector<type>, greater<type>>
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


vector<pll> g[maxn];
ll d[maxn];
ll p[maxn];
vll sPath;
ll meet[maxn];

void dijkstra(int s, int n)
{
    forn(i, n) d[i] = INFLL, p[i] = -1, meet[i] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> q;
    d[s] = 0;
    meet[0] = 1;
    q.push(mp(0, s));
    ll dist, u, v, w;
    while (!q.empty())
    {
        tie(dist, u) = q.top();
        q.pop();
        if (dist > d[u])
            continue;
        vll::iterator nxt = upper_bound(all(sPath), d[u]);
        for (pii e : g[u])
        {
            tie(v, w) = e;
            if(nxt != sPath.end() && d[u] + w > *nxt){
            	// cout << d[u] << nl;
                // cout << d[u] + w << ' ' << () << nl;
                continue;
            }
            if(d[u] + w == d[v])meet[v] = min(meet[v] + meet[u], 2LL);
            if (d[u] + w < d[v])
            {
                meet[v] = meet[u];
                d[v] = d[u] + w;
                p[v] = u;
                q.push(mp(d[v], v));
            }
        }
    }
}

vll find_path(int t){
    vll path;
    int cur = t;
    while(cur != -1){
    	// cout << cur << nl;
        path.pb(cur);
        cur = p[cur];
    }
    reverse(all(path));
    return path;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    ll n, m, d;
    cin >> n >> m >> d;
    ll u, v, w;
    forn(i, m){
        cin >> u >> v >> w;
        u--;
        v--;
        g[u].pb(mp(v, w));
    }
    sPath.resize(d);
    // meet.resize(d, 0);
    forn(i, d){
        cin >> sPath[i];
        // cout << sPath[sPath.size() - 1] << nl;
    }
    sort(all(sPath));
    dijkstra(0, n);
    // cout << nl;
    // cout << paths << nl;
    if(meet[n - 1] == 0){
        cout << 0 << nl;
        return 0;
    }
    if(meet[n - 1] > 1){
        cout << 1 << nl;
        return 0;
    }
    vll path = find_path(n - 1);
    cout << path.size() << nl;
    forn(i, path.size()){
        cout << path[i] + 1 << nl;
    }
}