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

ll a[nax];
ll sq[nax];

ll calcsq(ll x, ll y){
    assert(x != 1);
    ll csq = 0;
    while(x * x < y){
        x = x*x;
        ++csq;
    }
    ++csq;
    return csq;
}

ll compare(ll i, ll j){
    if(a[i] <= a[j]){
        if(a[i] == 1)return 0;
        ll csq = calcsq(a[i], a[j]);
        if(sq[i] < csq)return 0;
        ll nxt = a[i];
        forn(i, csq)nxt = nxt *nxt;
        return (nxt != a[j]) + sq[i] - csq;
    }else{
        if(a[j] == 1)return -1;
        ll csq = calcsq(a[j], a[i]);
        return csq + sq[i];
    }
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
            sq[i] = 0;
        }
        ll ans = 0;
        for1(i, n - 1){
            sq[i] = compare(i - 1, i);
            // db(sq[i]);
            if(sq[i] == -1){
                ans = -1;
                break;
            }
            ans += sq[i];
        }
        // cout << el;
        cout << ans << el;
    }
}