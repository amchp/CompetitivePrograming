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

ll sol(ll n){
    return n*(n + 1) / 2;
}

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
        vl a(n);
        forn(i, n)cin >> a[i];
        vl pre(n);
        pre[0] = a[0];
        for1(i, n - 1)pre[i] = pre[i - 1] + a[i];
        int q;
        cin >> q;
        while(q--){
            int sl, u;
            cin >> sl >> u;
            --sl;
            int l = sl - 1;
            int r = n;
            while(l + 1 < r){
                int m = l + (r - l) / 2;
                // d(m);
                // d(sl);
                // d(pre[m]);
                // d(pre[sl - 1]);
                ll sm = pre[m] - (sl != 0 ? pre[sl - 1] : 0);
                // d(sm);
                if(sm <= u)l = m;
                else r = m;
            }
            // d(l);
            // d(r);
            if(l == sl - 1){
                cout << r + 1 << ' ';
                continue;
            }
            if(r == n){
                // cout << "HI" << el;
                cout << l + 1 << ' ';
                continue;
            }
            ll ansl = pre[l] - (sl != 0 ? pre[sl - 1] : 0);
            ll pl = sol(u) - sol(u - ansl);
            ll ansr = pre[r] - (sl != 0 ? pre[sl - 1] : 0);
            ll pr = sol(u) - sol(u - ansr);
            if(pl >= pr)cout << l + 1 << ' ';
            else cout << r + 1 << ' ';
        }
        cout << el;
    }
}
