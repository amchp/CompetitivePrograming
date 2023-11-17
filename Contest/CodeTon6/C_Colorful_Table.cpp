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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<ii> ans(k);
        vi a(n);
        vector<ii> m(k, ii{inf, -1});
        forn(i, n){
            cin >> a[i];
            a[i]--;
            m[a[i]].first = min(m[a[i]].first, i);
            m[a[i]].second = max(m[a[i]].second, i);
        }
        int mn = inf;
        int mx = -1;
        ford(i, k){
            if(m[i].first == inf && m[i].second == -1){
                ans[i] = ii{1, 0};
                continue;
            }
            mn = min(m[i].first, mn);
            mx = max(m[i].second, mx);
            ans[i] = ii{mn, mx};
        }
        forn(i, k){
            cout << 2*(ans[i].second - ans[i].first + 1) << ' ';
        }
        cout << el;
    }
}
