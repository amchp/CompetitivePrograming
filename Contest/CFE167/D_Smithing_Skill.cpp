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
#define db(x) cerr<< #x<< " " << x<<el
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


const ll inf = 1e9;
const ll nax = 1e6+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

ll dr[] = {1,-1,0, 0,1,-1,-1, 1};
ll dc[] = {0, 0,1,-1,1, 1,-1,-1};

ll a[nax], b[nax];
ll use[nax];
ll dp[nax];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    ll n, m;
    cin >> n >> m;
    vector<ii> cst(n);
    forn(i, n){
        cin >> a[i];
        cst[i] = {a[i], i};
    }
    forn(i, n)cin >> b[i];
    sort(all(cst));
    ll cur = 0;
    ii cans = {inf, -1};
    forn(i, nax){
        while(cur < n && cst[cur].fi <= i){
            ll ind = cst[cur].se;
            cans = min(cans, {a[ind] - b[ind], ind});
            ++cur;
        }
        use[i] = cans.se;
        // cout << use[i] << ' ';
    }
    // cout << el;
    forn(x, nax){
        if(use[x] == -1){
            dp[x] = 0;
            continue;
        }
        ll ind = use[x];
        ll dif = a[ind] - b[ind];
        ll dst = x - a[ind];
        assert(dst >= 0);
        // db(ind);
        assert(dif != 0);
        ll num = (dst + dif) / dif;
        assert(x - dif*num >= 0);
        dp[x] = dp[x - dif*num] + 2*num;
    }
    ll ans = 0;
    forn(i, m){
        ll val;
        cin >> val;
        if(val >= nax){
            ll ind = use[nax - 1];
            ll dif = a[ind] - b[ind];
            ll dst = val - a[ind];
            assert(dst >= 0);
            assert(dif != 0);
            ll num = (dst + dif) / dif;
            assert(val - dif*num >= 0);
            assert(val - dif*num < nax);
            ans += dp[val - dif*num] + 2*num;
        }else{
            ans += dp[val];
        }
    }
    cout << ans << el;
}