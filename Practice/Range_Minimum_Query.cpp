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

const int N = 1e6 + 10, K = 32;  //K  has to satisfy K> log nax + 1
ll st[N][K];
struct RMQ{
    ll neutro = inf;
    inline ll oper(ll a, ll b){ return a < b ? a : b; }
    RMQ(vi& a){
        forn(i, sz(a)) st[i][0] = a[i];
        for1(j, K-1)
        forn(i, sz(a) - (1 << j) + 1)
            st[i][j] = oper(st[i][j-1], st[i + (1 << (j-1))][j-1]);
    }
    ll query(int l, int r){
        if(l > r) return neutro;
        int j = 31 - __builtin_clz(r-l+1);
        return oper(st[l][j], st[r - (1 << j) + 1][j]);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n;
    cin >> n;
    vi a(n);
    forn(i, n)cin >> a[i];
    int q;
    cin >> q;
    RMQ rmq = RMQ(a);
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << rmq.query(l, r) << el;
    }
}
