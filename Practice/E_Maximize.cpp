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
    cout << setprecision(20) << fixed;
    int t;
    cin >> t;
    vl pre;
    while(t--){
        int op;
        cin >> op;
        if(op == 1){
            int x;
            cin >> x;
            if(sz(pre))pre.pb(x + pre.back());
            else pre.pb(x);
        }else{
            if(sz(pre) == 1){
                cout << 0 << el;
                continue;
            }
            int l = -1;
            int r = sz(pre) - 1;
            while(l + 1 < r){
                int md = l + (r - l) / 2;
                ll lst = ll(pre.back() - pre[sz(pre) - 2]);
                ll sm = lst + pre[md];
                ld avg = ld(sm) / (md + 2);
                ll val = pre[md] - (md != 0 ? pre[md - 1] : 0);
                if(avg >= val){
                    l = md;
                }else{
                    r = md;
                }
            }
            ll lst = pre.back() - pre[sz(pre) - 2];
            // d(lst);
            ll sm = lst + pre[l];
            // d(sm);
            ld avg = ld(sm) / (l + 2);
            // d(l);
            cout << lst - avg << el;
        }
    }
}
