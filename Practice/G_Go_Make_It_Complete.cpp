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
#define d(x) cout<< #x<< " " << x<<el
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


const int inf = 1e9;
const int nax = 1e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

int n, m;
vector<vi> g;
vector<vector<ii>> gi;
vector<ii> drg;
vector<ii> sdrg;

bool sol(int k){
    // d(k);
    vector<vector<ii>> tgi = gi;
    vi index(n);
    vi cdrg(n);
    priority_queue<ii, vector<ii>> pq;
    forn(i, n){
        cdrg[i] = drg[i].fi;
        pq.push({cdrg[i], i});
    }
    vector<bool> visn(n, false);
    vector<vi> vis = g;
    while(!pq.empty()){
        int u = pq.top().se;
        pq.pop();
        if(visn[u])continue;
        visn[u] = true;
        for(auto& [vdrg, v] : tgi[u]){
            vdrg = cdrg[v];
        }
        sort(all(tgi[u]), greater<ii>());
        for(auto& [__, v] : tgi[u]){
            if(vis[u][v])continue;
            if(cdrg[u] + cdrg[v] >= k){
                ++cdrg[u];
                ++cdrg[v];
                pq.push({cdrg[v], v});
                vis[u][v] = 1;
                vis[v][u] = 1;
            }
        }
    }
    forn(i, n){
        // d(cdrg[i]);
        if(cdrg[i] != n - 1)return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    cin >> n >> m;
    g = vector<vi>(n, vi(n));
    drg.resize(n);
    forn(i, n)drg[i] = {0, i};
    forn(_, m){
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u][v] = 1;
        g[v][u] = 1;
        ++drg[u].fi;
        ++drg[v].fi;
    }
    gi.resize(n);
    forn(i, n){
        forn(j, n){
            if(i == j)continue;
            if(g[i][j] == 0){
                gi[i].pb({drg[j].fi, j});
            }
        }
        sort(all(gi[i]), greater<ii>());
    }
    sdrg = drg;
    sort(all(sdrg), greater<ii>());
    int l = -1;
    int r = 2*n + 1;
    while(l + 1 < r){
        int mid = l + (r - l) / 2;
        if(sol(mid)){
            l = mid;
        }else{
            r = mid;
        }
    }
    cout << l << el;
}