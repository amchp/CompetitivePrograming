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
        int n;
        cin >> n;
        vi a(n);
        forn(i, n)cin >> a[i];
        vector<ii> pre(n);
        vector<ii> suf(n);
        forn(i, n - 1){
            if(i == 0){
                pre[1] = {a[1] - a[0], 1};
                continue;
            }
            if(abs(a[i] - a[i - 1]) < abs(a[i + 1] - a[i])){
                pre[i + 1] = pre[i];
                continue;
            }
            pre[i + 1] = {pre[i].fi + a[i + 1] - a[i], pre[i].se + 1};
        }
        fored(i, 1, n - 1){
            if(i == n - 1){
                suf[n - 2] = {a[n - 1] - a[n - 2], 1};
                continue;
            }
            if(abs(a[i + 1] - a[i]) < abs(a[i] - a[i - 1])){
                suf[i - 1] = suf[i];
                continue;
            }
            suf[i - 1] = {suf[i].fi + a[i] - a[i - 1], suf[i].se + 1};
        }
        int q;
        cin >> q;
        while(q--){
            int l, r;
            cin >> l >> r;
            --l;
            --r;
            int ans;
            if(l < r){
                ans = (a[r] - a[l]) - (pre[r].fi - pre[l].fi) + (pre[r].se - pre[l].se);
            }else{
                ans = (a[l] - a[r]) - (suf[r].fi - suf[l].fi) + (suf[r].se - suf[l].se);
            }
            cout << ans << el;
        }
    }
}
