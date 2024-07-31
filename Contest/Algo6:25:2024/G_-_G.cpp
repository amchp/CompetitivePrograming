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


const ll inf = 1e18;
const ll nax = 1e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

ll dr[] = {1,-1,0, 0,1,-1,-1, 1};
ll dc[] = {0, 0,1,-1,1, 1,-1,-1};

struct stree{
  ll neutro = -inf, n, l, r, pos, val, c;  vll t;
  stree(ll n): n(n), t(n << 2){}
  stree(const vll& a, ll c): n(sz(a)), t(n<<2), c(c){ build(1, 0, n-1, a); }
  inline ll oper(ll a, ll b){ return max(a, b); }
  void build(ll v, ll tl, ll tr, const vll& a){// solo para el 2. constructor
    if(tl == tr){ t[v] = a[tl] + c*tl;  return; }
    ll tm = (tl + tr) >> 1;
    build(v << 1, tl, tm, a), build((v << 1) | 1, tm+1, tr, a);
    t[v] = oper(t[v << 1], t[(v << 1) | 1]);
  }
  ll query(ll v, ll tl, ll tr){
    if(tl > r || tr < l) return neutro;  // estoy fuera
    if(l <= tl && tr <= r) return t[v];
    ll tm = (tl + tr) >> 1;
    return oper(query(v << 1, tl, tm), query((v << 1) | 1, tm+1, tr));
  }
  void upd(ll v, ll tl, ll tr){
    if(tl == tr){ t[v] = val + c*tl;  return; }
    ll tm = (tl + tr) >> 1;
    if(pos <= tm) upd(v << 1, tl, tm);
    else upd((v << 1) | 1, tm+1, tr);
    t[v] = oper(t[v << 1], t[(v << 1) | 1]);
  }
  void upd(ll idx, ll num){ pos = idx, val = num, upd(1, 0, n-1);}
  ll query(ll ql, ll qr){ l = ql, r = qr;  return query(1, 0, n-1);}
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    ll n, c;
    cin >> n >> c;
    ll m;
    cin >> m;
    vll a(n), dp(n);
    forn(i, n){
        a[i] = -inf;
        dp[i] = -inf;
    }
    a[0] = 0;
    dp[0] = 0;
    stree ast(a, c), sst(a, -c);
    forn(_, m){
        ll ind, val;
        cin >> ind >> val;
        --ind;
        dp[ind] = max(
            ast.query(0, ind) - c*ind,
            sst.query(ind, n - 1) + c*ind
        ) + val;
        ast.upd(ind, dp[ind]);
        sst.upd(ind, dp[ind]);
    }
    ll ans = 0;
    forn(i, n){
        ans = max(ans, dp[i]);
    }
    cout << ans << el;
}