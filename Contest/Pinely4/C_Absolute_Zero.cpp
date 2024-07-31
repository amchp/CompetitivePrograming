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


const ll inf = 1e9 + 100;
const ll nax = 1e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

ll dr[] = {1,-1,0, 0,1,-1,-1, 1};
ll dc[] = {0, 0,1,-1,1, 1,-1,-1};

ll n;
vi ans;

bool sol(){
    ans.clear();
    cin >> n;
    ll mn = inf, mx = -1;
    vi a(n);
    forn(i, n){
        cin >> a[i];
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }
    sort(all(a));
    forn(i, n - 1){
        if((a[i + 1] - a[i])&1)return false;
    }
    forn(_, 40){
        if(mn == 0 && mx == 0)break;
        ll mid = mn + (mx - mn) / 2;
        ans.pb(mid);
        mn = inf, mx = -1;
        forn(i, n){
            a[i] = abs(a[i] - mid);
            mn = min(mn, a[i]);
            mx = max(mx, a[i]);
        }
    }
    return mn == 0 && mx == 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    ll t;
    cin >> t;
    while(t--){
        if(sol()){
            cout << sz(ans) << el;
            for(ll& v : ans)cout << v << ' ';
            cout << el;
        }else{
            cout << -1 << el;
        }
    }
}