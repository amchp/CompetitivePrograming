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


const ll inf = 1e9;
const ll nax = 2e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

ll dr[] = {1,-1,0, 0,1,-1,-1, 1};
ll dc[] = {0, 0,1,-1,1, 1,-1,-1};

ll n;
ll ttl;

vll a(nax);
vll b(nax);
vll c(nax);

vll pre[3];

ii ans[3];

ll sum(ll ind, ll l, ll r){
    return pre[ind][r] - (l != 0 ? pre[ind][l - 1] : 0);
}

bool check(ll pref, ll pres, ll l, ll r){
    if(l == r)return false;
    auto it = lower_bound(pre[pref].begin(), (pre[pref].begin() + n), (l != 0 ? pre[pref][l - 1] : 0) + ttl);
    ll l1 = l;
    ll r1 = it - pre[pref].begin();
    if(r1 >= r)return false;
    ll l2 = r1 + 1;
    ll r2 = r;
    if(sum(pref, l1, r1) >= ttl && sum(pres, l2, r2) >= ttl){
        ans[pref] = {l1, r1};
        ans[pres] = {l2, r2};
        return true;
    }
    return false;
}

bool sol(){
    cin >> n;
    ttl = 0;
    forn(i, n){
        cin >> a[i];
        ttl += a[i];
    }
    ll tmp = 0;
    forn(i, n){
        cin >> b[i];
        tmp += b[i];
    }
    assert(tmp == ttl);
    tmp = 0;
    forn(i, n){
        cin >> c[i];
        tmp += c[i];
    }
    assert(tmp == ttl);
    ttl = (ttl + 2) / 3;

    pre[0][0] = a[0];
    for1(i, n - 1)pre[0][i] = pre[0][i - 1] + a[i];
    
    pre[1][0] = b[0];
    for1(i, n - 1)pre[1][i] = pre[1][i - 1] + b[i];

    pre[2][0] = c[0];
    for1(i, n - 1)pre[2][i] = pre[2][i - 1] + c[i];

    forn(i, n - 1){
        if(sum(0, 0, i) >= ttl){
            ans[0] = {0, i};
            if(check(1, 2, i + 1, n - 1)){
                return true;
            }
            if(check(2, 1, i + 1, n - 1)){
                return true;
            }
        }
        if(sum(1, 0, i) >= ttl){
            ans[1] = {0, i};
            if(check(0, 2, i + 1, n - 1)){
                return true;
            }
            if(check(2, 0, i + 1, n - 1)){
                return true;
            }
        }
        if(sum(2, 0, i) >= ttl){
            ans[2] = {0, i};
            if(check(0, 1, i + 1, n - 1)){
                return true;
            }
            if(check(1, 0, i + 1, n - 1)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    forn(i, 3)pre[i] = vll(nax);
    ll t;
    cin >> t;
    while(t--){
        if(sol()){
            forn(i, 3){
                assert(sum(i, ans[i].fi, ans[i].se) >= ttl);
                cout << ans[i].fi + 1 << ' ' << ans[i].se + 1 << ' ';
            }
            cout << el;
        }else{
            cout << -1 << el;
        }
    }
}