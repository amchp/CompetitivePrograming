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


const ll inf = 1e18;
const int nax = (1 << 20) + 100;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

ll dp[21][nax];
bool vis[21][nax];
ll dist[30][30];
int n, m;
void floyd(){
  forn(k,n){
    forn(u,n){
      forn(v,n){
        if(dist[u][k] == inf || dist[k][v] == inf)continue;
        dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
      }
    }
  }
}

ll sol(int u, int msk){
    if(msk == ((1 << n) - 1))return 0;
    ll& ans = dp[u][msk];
    if(vis[u][msk]){
        return ans;
    }
    vis[u][msk] = true;
    ans = inf;
    forn(v, n){
        if(u == v || dist[u][v] == inf || (msk & (1 << v)))continue;
        ans = min(ans, sol(v, msk | (1 << v)) + dist[u][v]);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    cin >> n >> m;
    forn(u, n){
        forn(v, n){
            if(u == v)dist[u][v] = 0;
            else dist[u][v] = inf;
        }
    }
    forn(i, m){
        int u, v;
        cin >> u >> v;
        --u, --v;
        cin >> dist[u][v];
    }
    floyd();
    ll ans = inf;
    forn(u, n){
        ans = min(ans, sol(u, (1 << u)));
    }
    if(ans == inf)cout << "No" << el;
    else cout << ans << el;
}