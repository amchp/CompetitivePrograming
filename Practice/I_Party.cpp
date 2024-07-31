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
#define db(x) cerr<< #x<< " " << x<<el
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


const int inf = 1e9;
const int nax = 1e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int n, m;
    cin >> n >> m;
    int e = 1 << n;
    vi g(n, 0);
    forn(i, n)g[i] |= (1 << i);
    vector<a3> dp(e, {inf, -1, -1});
    forn(i, m){
      int u, v;
      cin >> u >> v;
      --u, --v;
      g[u] |= (1 << v);
      g[v] |= (1 << u);
    }
    forn(u, n){
      int bts = g[u];
      forn(v, n){
        if(g[u] & (1 << v)){
          bts &= g[v];
          // db(g[v]);
        }
      }
      dp[bts] = {0, -1, -1};
      // db(bts);
    }
    forn(bts, e){
      forn(u, n){
        if(bts & (1 << u)){
          dp[bts | g[u]] = min(dp[bts | g[u]], {dp[bts][0] + 1, bts, u});
        }
      }
    }
    vi pth;
    int cur = e - 1;
    assert(dp[cur][0] != inf);
    while(dp[cur][1] != -1){
      pth.pb(dp[cur][2]);
      cur = dp[cur][1];
    }
    // reverse(all(pth));
    // cout << dp[e - 1][0] << el;
    cout << sz(pth) << el;
    for(int& v : pth)cout << v + 1 << ' ';
    cout << el;
}