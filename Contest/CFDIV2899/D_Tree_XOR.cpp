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
const int nax = 2e5 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

int n;
vi g[nax];
vi kids[nax];
int a[nax];
int xr[nax];
ll ans[nax];

ll dfs(int ind, int p, ll& an){
    // d(ind);
    if(p == -1)xr[ind] = 0;
    else xr[ind] = a[p]^a[ind];
    // d(xr[ind]);
    int k = 1;
    int pInd = -1;
    for(int v : g[ind]){
        if(v == p){
            pInd = sz(kids[ind]);
            kids[ind].pb(0);
            continue;
        }
        int ch = dfs(v, ind, an);
        kids[ind].pb(ch);
        k += ch;
    }
    if(pInd != -1){
        kids[ind][pInd] = n - k;
    }
    an += (ll)xr[ind] * k;
    return k;
}

void dfs2(int ind, int p, ll an){
    if(p == -1)ans[ind] = an;
    else{
        // d(ind);
        int oK = 1;
        forn(i, sz(g[p])){
            if(g[p][i] == ind)continue;
            oK += kids[p][i];
        }
        an += (ll)oK * xr[ind];
        int k = 1;
        forn(i, sz(g[ind])){
            if(g[ind][i] == p)continue;
            k += kids[ind][i];
        }
        // d(oK);
        // d(k);
        // d(xr[ind]);
        an -= (ll)k * xr[ind];
        ans[ind] = an;
    }
    for(int v : g[ind]){
        if(v == p)continue;
        dfs2(v, ind, an);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        forn(i, n){
            g[i].clear();
            kids[i].clear();
            cin >> a[i];
        }
        forn(i, n - 1){
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            g[u].pb(v);
            g[v].pb(u);
        }
        ll an = 0;
        dfs(0, -1, an);
        dfs2(0, -1, an);
        forn(i, n)cout << ans[i] << ' ';
        cout << el;
    }
}