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
    freopen("hack.in", "r", stdin);
    freopen("hack.out", "w", stdout);
    int n;
    cin >> n;
    vi a(n);
    vi pXor(n + 1);
    pXor[0] = 0;
    vi compr;
    vector<vi> nB(31);
    forn(i, n){
        cin >> a[i];
        pXor[i + 1] = a[i] ^ pXor[i];
        compr.pb(pXor[i + 1]);
        forn(j, 31){
            if(!(a[i] & (1 << j)))nB[j].pb(i);
        }
    }
    sort(all(compr));
    compr.resize(distance(compr.begin(), unique(all(compr))));
    vector<vi> fA(sz(compr));
    forn(i, n){
        int ind = lower_bound(all(compr), pXor[i + 1]) - compr.begin();
        fA[ind].pb(i);
    }
    forn(j, 31)nB[j].pb(n);
    ll ans = 0;
    vi pos;
    forn(i, n){
        pos.clear();
        forn(j, 31){
            if(a[i] & (1 << j)){
                pos.pb(*lower_bound(all(nB[j]), i));
            }
        }
        pos.pb(n);
        sort(all(pos));
        pos.resize(distance(pos.begin(), unique(all(pos))));
        int cAnd = a[i];
        int prv = i;
        // d(i);
        for(int j : pos){
            int tgt = cAnd ^ pXor[i];
            // d(tgt);
            int ind = lower_bound(all(compr), tgt) - compr.begin();
            if(compr[ind] == tgt){
                int l = lower_bound(all(fA[ind]), prv) - fA[ind].begin();
                int r = upper_bound(all(fA[ind]), j - 1) - fA[ind].begin();
                ans += r - l;
            }
            cAnd &= a[j];
            prv = j;
        }
        // cout << el;
    }
    cout << ans << el;
}
