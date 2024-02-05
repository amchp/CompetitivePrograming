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
        int n, q;
        cin >> n >> q;
        vector<vl> ln;
        int lst;
        forn(i, n){
            ll op, x;
            cin >> op >> x;
            if(sz(ln) && ln.back()[0] == inf)continue;
            if(op == 1){
                if(sz(ln))ln.pb({ln.back()[0] + 1, x, lst});
                else ln.pb({1, x, -1});
                lst = i;
            }
            if(op == 2){
                if((inf / (x + 1)) < ln.back()[0]){
                    ln.pb({inf, -1, lst});
                    continue;
                }
                ln.pb({ln.back()[0]*(x + 1), -1, lst});
            }
        }
        // for(auto& vec : ln)cout << vec[0] << ' ' << vec[1] << ' ' << vec[2] << el;
        while(q--){
            ll k;
            cin >> k;
            auto it = lower_bound(all(ln), vl{k, -1, -1});
            while((*it)[1] == -1){
                if(it == ln.begin())assert(false);
                ll mod = ln[(*it)[2]][0];
                // d(mod);
                k = k % mod;
                if(k == 0)k = mod;
                // d(k);
                it = lower_bound(all(ln), vl{k, -1, -1});
            }
            // d((*it)[1]);
            cout << (*it)[1] << ' ';
        }
        cout << el;
    }
}
