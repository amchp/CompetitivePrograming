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
        int n, x, k;
        cin >> n >> k >> x;
        vi a(n);
        forn(i, n)cin >> a[i];
        sort(all(a));
        int st = max(n, 0);
        int e = n + k;
        int ans = -inf;
        vi pre(n + 1);
        pre[0] = 0;
        for1(i, n){
            pre[i] = pre[i - 1] + a[i - 1];
            // cout << pre[i] << ' ';
        }
        // cout << el;
        // d(st);
        // d(e);
        fored(i, st, e){
            int ind = i - k;
            int ix = max(ind - x, 0);
            // d(ind);
            // d(ix);
            // d(pre[ix]);
            // d(pre[ind] - pre[ix]);
            // d(pre[ix] - (pre[ind] - pre[ix]));
            ans = max(ans, pre[ix] - (pre[ind] - pre[ix]));
        }
        cout << ans << el;
    }
}
