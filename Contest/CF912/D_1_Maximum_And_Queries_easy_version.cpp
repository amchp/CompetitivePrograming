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

const int inf = 1e9;
const int nax = 1e5 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

int n, q;
ll k;
int a[nax];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    cin >> n >> q;
    forn(i, n)cin >> a[i];
    vector<vi> bits(63);
    forn(i, n){
        forn(j, 63){
            if(a[i] & (1LL << j))bits[j].pb(i);
        }
    }
    while(q--){
        cin >> k;
        ll ans = 0;
        set<int> seen;
        ford(i, 63){
            __int128_t cost = 0;
            ll bit = (1LL << i);
            ll num = bit - 1;
            forn(j, n){
                if(seen.count(j)){
                    cost += bit;
                    continue;
                }
                if(a[j] & bit)continue;
                ll val = a[j] & num;
                cost += bit - val;
            }
            // d(i);
            // d(ll(cost));
            if(k >= cost){
                ans |= bit;
                k -= cost;
                forn(j, n){
                    if(a[j] & bit)continue;
                    seen.insert(j);
                }
            }
            // d(ans);
        }
        cout << ans << el;
    }
}
