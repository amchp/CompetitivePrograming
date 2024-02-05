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

const int inf = 2e9;
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
    int n;
    cin >> n;
    vi a(n), lft(n), rgt(n);
    forn(i, n)cin >> a[i];
    lft[0] = a[0];
    for1(i, n - 1)lft[i] = max(a[i], lft[i - 1] + 1);
    rgt[n - 1] = a[n - 1];
    ford(i, n - 1)rgt[i] = max(a[i], rgt[i + 1] + 1);
    int ans = inf;
    forn(i, n){
        int ind = n - i;
        int lf = i != 0 ? lft[i - 1] : -inf;
        int rg = i != n - 1 ? rgt[i + 1] : -inf;
        // d(lf + ind);
        // d(a[i]);
        // d(rg + i + 1);
        ans = min(ans, max({lf + ind, a[i], rg + i + 1}));
    }
    cout << ans << el;
}
