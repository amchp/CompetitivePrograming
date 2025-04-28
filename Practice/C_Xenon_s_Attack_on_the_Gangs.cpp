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
typedef array<ll, 2> v2;

const int inf = 1e9;
const int nax = 3000;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

int n;
vi g[nax], hj[nax];

int dfs(int u, int p){
    hj[u] = vi(sz(g[u]));
    int pi = -1;
    int ans = 1;
    forn(i, sz(g[u])){
        int& v = g[u][i];
        if(v == p){
            pi = i;
            continue;
        }
        hj[u][i] = dfs(v, u);
        ans += hj[u][i];
    }
    if(pi != -1){
        hj[u][pi] = n - ans;
    }
    return ans;
}

void sol(){
    cin >> n;
    vector<v2> edgs(n - 1);
    forn(i, n - 1){
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
        edgs[i] = {u, v};
    }
    int cnt = dfs(0, 0);
    assert(cnt == n);
    auto findcnt = [&](int st, int nxt){
        forn(i, sz(g[st])){
            int& v = g[st][i];
            if(v == nxt)return hj[st][i];
        }
        assert(false);
        return 0;
    };
    auto calcnxtcnt = [&](int u, int p){
        int ans = 0;
        forn(i, sz(g[u])){
            int& v = g[u][i];
            if(v == p)continue;
            int lcnt = hj[u][i];
            ans = max(ans, lcnt);
        }
        return ans;
    };
    auto bfs = [&](int l, int r){
        int lft = findcnt(l, r);
        int rgt = findcnt(r, l);
        ll ans = 1ll*lft*rgt;
        int pl = r;
        int pr = l;
        auto [nlft, nl] = calcnxtcnt(l, pl);
        auto [nrgt, nr] = calcnxtcnt(r, pr);
        while(lft > 0 && rgt > 0){
            ll vlft = 1LL*nlft*rgt;
            ll vrgt = 1LL*nrgt*lft;
            if(vlft < vrgt){
                pl = l;
                lft = nlft;

            }
        }
    };
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int t = 1;
    cin >> t;
    while(t--){
        sol();
    }
}