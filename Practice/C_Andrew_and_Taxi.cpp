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
const int nax = 1e5 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

int n, m;
int r;
vector<vi> g[nax];
int vis[nax];
vector<bool> sn(nax);

bool dfs(int u, int& cycle, int& szs){
    vis[u] = cycle;
    // d(cycle);
    for(auto& vec : g[u]){
        int v = vec[0];
        int w = vec[1];
        if(w <= szs)continue;
        if(vis[v] && vis[v] == cycle)return false;
        if(vis[v])continue;
        if(!dfs(v, cycle, szs))return false;
    }
    return true;
}

int bs(){
    int l = -1;
    while(l + 1 < r){
        // d(l);
        // d(r);
        int mid = l + (r - l) / 2;
        // d(mid);
        forn(i, n){
            vis[i] = 0;
        }
        bool pass = true;
        int cycle = 1;
        forn(i, n){
            if(vis[i])continue;
            pass &= dfs(i, cycle, mid);
            cycle++;
        }
        // cout << "OUT" << el;
        if(pass){
            r = mid;
        }else{
            l = mid;
        }
    }
    return r;
}

vi ts;

void dfs2(int u, int& szs){
    vis[u] = true;
    sn[u] = true;
    for(auto& vec : g[u]){
        int v = vec[0];
        int w = vec[1];
        if(w <= szs)continue;
        if(vis[v] && sn[v])assert(false);
        if(vis[v])continue;
        dfs2(v, szs);
    }
    sn[u] = false;
    ts.pb(u);
}

void topo_sort(int szs){
    forn(i, n){
        vis[i] = false;
        sn[i] = false;
    }
    forn(i, n){
        if(vis[i])continue;
        dfs2(i, szs);
    }
    reverse(all(ts));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    cin >> n >> m;
    r = 0;
    forn(i, m){
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        g[u].pb({v, w, i + 1});
        r = max(w, r);
    }
    int szs = bs();
    topo_sort(szs);
    vi ans;
    set<int> seen;
    for(int& u : ts){
        for(vi& vec : g[u]){
            int v = vec[0];
            int w = vec[1];
            int ind = vec[2];
            if(w <= szs && seen.count(v)){
                ans.pb(ind);
            }
        }
        seen.insert(u);
    }
    sort(all(ans));
    cout << szs << ' ' << sz(ans) << el;
    for(int& u : ans)cout << u << ' ';
    cout << el;
}
