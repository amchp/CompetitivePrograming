#include <bits/stdc++.h>

#define fi first
#define se second
#define forn(i,n) for(int i=0; i< (int)n; ++i)
#define for1(i,n) for(int i=1; i<= (int)n; ++i)
#define fore(i,l,r) for(int i=(int)l; i<= (int)r; ++i)
#define ford(i,n) for(int i=(int)(n) - 1; i>= 0; --i)
#define fored(i,l,r) for(int i=(int)r; i>= (int)l; --i)
#define pb push_back
#define el '\n'
#define db(x) cout<< #x<< " " << x<<el
#define ri(n) scanf("%d",&n)
#define sz(v) int(v.size())
#define all(v) v.begin(),v.end()

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<ld> vd;
typedef array<int, 3> a3;
typedef array<int, 4> a4;


const int inf = 1e9;
const int nax = 5e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

int n, m;
vi g[nax];
vi gc[nax];
int col[nax];
int p[nax];
int szs[nax];
bool vis[nax];

int find(int x){
    if(x == p[x])return x;
    return p[x] = find(p[x]);
}

void dfs(int u, int cl){
    vis[u] = true;
    col[u] = cl;
    for(int& v : g[u]){
        if(vis[v])continue;
        dfs(v, !cl);
    }
    vis[u] = false;
}

bool bip(int u, int cl){
    vis[u] = true;
    col[u] = cl;
    for(int& v : gc[u]){
        if(vis[v]){
            if(col[v] == col[u])return false;
            continue;
        }
        if(!bip(v, !cl))return false;
    }
    return true;
}

bool check_bip(){
    forn(i, n)vis[i] = false;
    forn(u, n){
        if(!vis[u]){
            if(!bip(u, 0))return false;
        }
    }
    return true;
}


bool same(int u, int v){
    u = find(u);
    v = find(v);
    return u == v;
}

void merge(int u, int v){
    if(same(u, v))return;
    int pu = find(u);
    int pv = find(v);

    if(szs[pu] < szs[pv]){
        swap(u, v);
        swap(pu, pv);
    }

    if(col[u] == col[v]){
        dfs(v, !col[u]);
    }

    p[pv] = pu;

    szs[pu] += szs[pv];

    g[u].pb(v);
    g[v].pb(u);
}

void makeunique(vi& vec){
    sort(all(vec));
    vec.erase(unique(all(vec)), vec.end());
}

bool chk(vector<a4>& difs, int ind){
    auto& [tcu, tcv, tu, tv] = difs[ind];
 
    for(auto& [cu, cv, u, v] : difs){
        vector<ii> org = {
            {tcu, tu}, {tcv, tv}, {cu, u}, {cv, v}
        };
 
        sort(all(org));
        org.erase(unique(all(org)), org.end());
        // cout << sz(org) << el;
        if(sz(org) == 4)return true;
    }
    return false;
}

bool check(vi& zeros, vi& ones, vector<a4>& difs){
    if(sz(zeros) && sz(ones))return true;

    makeunique(zeros);
    if(sz(zeros) > 1)return true;

    makeunique(ones);
    if(sz(ones) > 1)return true;

    vi cdifs;

    for(auto& [cu, cv, u, v] : difs){
        cdifs.pb(find(u));
    }

    vi fnl;
    for(int& v : zeros)fnl.pb(v);
    for(int& v : ones)fnl.pb(v);
    for(int& v : cdifs)fnl.pb(v);

    makeunique(fnl);
    if(sz(fnl) > 1)return true;

    auto& [tcu, tcv, tu, tv] = difs[0];

    for(auto& [cu, cv, u, v] : difs){
        vector<ii> org = {
            {tcu, col[tu]}, {tcv, col[tv]}, {cu, col[u]}, {cv, col[v]}
        };

        sort(all(org));
        org.erase(unique(all(org)), org.end());
        if(sz(org) == 4)return true;
    }

    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;

    cin >> n >> m;
    forn(i, n){
        p[i] = i;
        szs[i] = 1;
    }
    vector<a3> edg(m);
    forn(i, m){
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        edg[i] = {w, u, v};
        gc[u].pb(v);
        gc[v].pb(u);
    }
    sort(all(edg), greater<a3>());

    int pv = inf + 100;
    vector<vector<a3>> lvls;

    for(auto& vec : edg){
        if(vec[0] != pv){
            lvls.pb({vec});
        }else{
            lvls.back().pb(vec);
        }
        pv = vec[0];
    }
    vi ans;
    for(auto& vec : lvls){
        vi zeros;
        vi ones;
        vector<a4> difs;
        int wgt;
        for(auto& [w, u, v] : vec){
            wgt = w;
            if(same(u, v)){
                if(col[u] == col[v]){
                    if(col[u] == 0)zeros.pb(find(u));
                    else ones.pb(find(u));
                }
            }else{
                difs.pb({find(u), find(v), u, v});
            }
        }
        // db(wgt);
        for(auto& [w, u, v] : vec){
            // cout << u << ' ' << v << el;
            if(same(u, v))continue;
            merge(u, v);
        }
        // db(sz(difs));
        // db(sz(zeros));
        // db(sz(ones));
        // forn(i, 4)cout << col[i] << ' ';
        // cout << el;
        if(check(zeros, ones, difs))ans.pb(wgt);
        if(sz(zeros) || sz(ones)){
            break;
        }
    }
    if(check_bip())ans.pb(0);
    if(sz(ans) == 0){
        cout << "IMPOSSIBLE" << el;
        return 0;
    }
    reverse(all(ans));
    for(int& v : ans)cout << v << el;
}