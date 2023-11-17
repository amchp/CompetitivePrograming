#include <bits/stdc++.h>

#define fi first
#define se second
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define for1(i, n) for (int i = 1; i <= (int)n; ++i)
#define fore(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define ford(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define fored(i, l, r) for (int i = (int)r; i >= (int)l; --i)
#define pb push_back
#define el '\n'
#define d(x) cout << #x << " " << x << el
#define ri(n) scanf("%d", &n)
#define sz(v) ((int)v.size())
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> ii;
typedef pair<char, int> pci;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int inf = 1e9;
const int nax = 3e5 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

int n, m, x;
ll ttl;
ll a[nax];
vector<bool> vis(nax, false);
map<ii, int> gI;
vi g[nax];
vi gt[nax];
set<int> gc[nax];
bool pass = true;
vi ans;

void dfs(int ind, int p){
    vis[ind] = true;
    for(int& v : g[ind]){
        if(!vis[v]){
            gt[ind].pb(v);
            gt[v].pb(ind);
            dfs(v, ind);
        }
    }
    if(p != -1 && a[ind] >= x){
        ans.pb(gI[{ind, p}]);
        gc[ind].insert(p);
        gc[p].insert(ind);
        a[p] += a[ind] - x;
        a[ind] = 0;
    }
}

void dfs2(int ind, int p){
    for(int& v : gt[ind]){
        if(gc[ind].count(v))continue;
        if(ttl + a[v] >= x){
            ttl += a[v] - x;
            a[v] = 0;
            ans.pb(gI[{ind, v}]);
            gc[ind].insert(v);
            gc[v].insert(ind);
        }else{
            pass = false;
            return;
        }
    }
    for(int& v : gt[ind]){
        if(v == p)continue;
        dfs2(v, ind);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    cin >> n >> m >> x;
    forn(i, n){
        cin >> a[i];
    }
    forn(i, m){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].pb(v);
        g[v].pb(u);
        gI[{u, v}] = i + 1;
        gI[{v, u}] = i + 1;
    }
    dfs(0, -1);
    ttl = a[0];
    a[0] = 0;
    dfs2(0, -1);
    if(!pass){
        cout << "NO" << el;
        return 0;
    }
    cout << "YES" << el;
    for(int& v : ans){
        cout << v << el;
    }
}
