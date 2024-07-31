#include <bits/stdc++.h>

#define fi first
#define se second
#define forn(i,n) for(ll i=0; i< (ll)n; ++i)
#define for1(i,n) for(ll i=1; i<= (ll)n; ++i)
#define fore(i,l,r) for(ll i=(ll)l; i<= (ll)r; ++i)
#define ford(i,n) for(ll i=(ll)(n) - 1; i>= 0; --i)
#define fored(i,l,r) for(ll i=(ll)r; i>= (ll)l; --i)
#define pb push_back
#define el '\n'
#define db(x) cout<< #x<< " " << x<<el
#define ri(n) scanf("%d",&n)
#define sz(v) ll(v.size())
#define all(v) v.begin(),v.end()

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ll,ll> ii;
typedef pair<ll,ll> pll;
typedef tuple<ll, ll, ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<ld> vd;
typedef array<ll, 20> a4;


const ll inf = 1e18;
const ll nax = 3e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

ll dr[] = {1,-1,0, 0,1,-1,-1, 1};
ll dc[] = {0, 0,1,-1,1, 1,-1,-1};

ll a[nax];
vi g[nax];

a4 dfs(ll u, ll p){
    ll& att = a[u];
    a4 ans;
    forn(i, 20)ans[i] = att*(i + 1);
    for(ll& v : g[u]){
        if(v == p)continue;
        a4 chjs = dfs(v, u);
        a4 cans;
        forn(i, 20)cans[i] = inf;
        forn(i, 20){
            forn(j, 20){
                if(i == j)continue;
                cans[i] = min(cans[i], chjs[j]);
            }
        }
        forn(i, 20)ans[i] += cans[i];
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        forn(i, n){
            cin >> a[i];
            g[i].clear();
        }
        forn(i, n - 1){
            ll u, v;
            cin >> u >> v;
            --u, --v;
            g[u].pb(v);
            g[v].pb(u);
        }
        a4 ans = dfs(0, -1);
        ll fans = inf;
        forn(i, 20)fans = min(fans, ans[i]);
        cout << fans << el;
    }
}