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
    // d(t);
    while(t--){
        int n, q;
        cin >> n >> q;
        // d(n);
        // d(q);
        vl a(n);
        forn(i, n){
            cin >> a[i];
            // cout << i << ' ';
        }
        int sn = sqrt(n);
        vector<vector<vl>> pre(sn + 1);
        vector<vector<vl>> pres(sn + 1);
        for1(i, sn){
            pre[i].resize(i);
            pres[i].resize(i);
            forn(j, i){
                // d(i);
                ll ind = 1;
                for(int k = j; k < n; k += i){
                    // d(k);
                    pre[i][j].pb(a[k]);
                    pres[i][j].pb(a[k]*ind);
                    ++ind;
                }
                for1(k, sz(pre[i][j]) - 1){
                    pre[i][j][k] += pre[i][j][k - 1];
                    pres[i][j][k] += pres[i][j][k - 1];
                }
            }
        }
        while(q--){
            int s, d, k;
            cin >> s >> d >> k;
            --s;
            if(d <= sn){
                int l = s / d;
                int r = (s + (d*(k - 1))) / d;
                int j = s % d;
                ll sans = pres[d][j][r] - (l != 0 ? pres[d][j][l - 1] : 0);
                ll nans = pre[d][j][r] - (l != 0 ? pre[d][j][l - 1] : 0);
                ll ans = sans - nans*(l);
                cout << ans << ' ';
                continue;
            }
            ll ans = 0;
            int ind = s;
            for(int i = 0; i < k; ++i){
                ans += a[ind]*(i + 1);
                ind += d;
            }
            cout << ans << ' ';
        }
        cout << el;
    }
}
