#include <bits/stdc++.h>

#define fi first
#define se second
#define forn(i, n) for (ll i = 0; i < (ll)n; ++i)
#define for1(i, n) for (ll i = 1; i <= (ll)n; ++i)
#define fore(i, l, r) for (ll i = (ll)l; i <= (ll)r; ++i)
#define ford(i, n) for (ll i = (ll)(n)-1; i >= 0; --i)
#define fored(i, l, r) for (ll i = (ll)r; i >= (ll)l; --i)
#define pb push_back
#define el '\n'
#define d(x) cout << #x << " " << x << el
#define ri(n) scanf("%d", &n)
#define sz(v) ((ll)v.size())
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ll, ll> ii;
typedef pair<char, ll> pci;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;
typedef vector<ll> vl;

const ll inf = 2e9;
const ll nax = 1e5 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

ll dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
ll dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    ll t;
    cin >> t;
    while(t--){
        ll n, x;
        cin >> n >> x;
        vector<ii> dh(n);
        ll mx = 0;
        forn(i, n){
            cin >> dh[i].fi;
            cin >> dh[i].se;
            mx = max(mx, dh[i].fi);
        }
        ll ans = inf;
        forn(i, n){
            if(dh[i].fi >= x){
                ans = 1;
                break;
            }
            if(dh[i].fi <= dh[i].se){
                continue;
            }
            ll dif = dh[i].fi - dh[i].se;
            ll blw = (x - mx + dif - 1) / dif;
            ll fnl = x - dif*(blw - 1) - mx;
            if(fnl > 0){
                ++blw;
                fnl -= dif;
            }
            assert(fnl <= 0);
            ans = min(ans, blw);
        }
        if(ans == inf){
            cout << -1 << el;
            continue;
        }
        cout << ans << el;
    }
}
