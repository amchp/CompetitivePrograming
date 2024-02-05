#include <bits/stdc++.h>

#define fi first
#define se second
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define for1(i, n) for (int i = 1; i <= (int)n; ++i)
#define fore(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define ford(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define fored(i, l, r) for (int i = (int)r; i >= (int)l; --i)
#define pb push_back
#define el '\n'
#define d(x) cout << #x << " " << x << el
#define ri(n) scanf("%d", &n)
#define sz(v) ((int)v.size())
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> ii;
typedef pair<char, int> pci;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll inf = 1e18;
const int nax = 1e5 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi a(n);
        forn(i, n)cin >> a[i];
        vl pa(n + 1);
        pa[0] = 0;
        for1(i, n)pa[i] = a[i -1] + pa[i - 1];
        vi factors;
        for(int i = 1; i*i <= n; ++i){
            if(n % i == 0){
                factors.pb(i);
                int j = n / i;
                if(i != j)factors.pb(j);
            }
        }
        ll ans = 0;
        sort(all(factors));
        for(int& factor : factors){
            // d(factor);
            ll mn = inf;
            ll mx = 0;
            for(int i = factor; i <= n; i += factor){
                ll seg = pa[i] - pa[i - factor];
                // d(seg);
                mn = min(mn, seg);
                mx = max(mx, seg);
            }
            // d(mx - mn);
            ans = max(ans, mx - mn);
        }
        cout << ans << el;
    }
}
