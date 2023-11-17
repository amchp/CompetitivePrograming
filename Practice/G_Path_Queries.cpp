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

const ll inf = 1e18;
const int nax = 2e5 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

map<int, vector<ii>> edges;
int n;
int p[nax];
int szs[nax];
ll ans;

ll calc(ll a, ll b){
    return a*b;
}

void init(){
    ans = 0;
    forn(i, n){
        p[i] = i;
        szs[i] = 1;
    }
}

int find(int u){
    return u == p[u] ? u : p[u] = find(p[u]);
}

void merge(int a, int b){
    int pA = find(a);
    int pB = find(b);
    if(pA == pB)return;
    if(szs[pA] < szs[pB])swap(pA, pB);
    ans += calc(szs[pA], szs[pB]);
    p[pB] = pA;
    szs[pA] += szs[pB];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int m;
    cin >> n >> m;
    forn(i, n - 1){
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        edges[w].pb({u, v});
    }
    vector<pll> lAns;
    lAns.pb({-1LL, 0LL});
    init();
    for(auto &[a, b] : edges){
        for(auto &[u, v] : b){
            merge(u, v);
        }
        lAns.pb({(int)a, ans});
    }
    // for(auto &[a, b]: lAns){
    //     cout << a << ' ' << b << el;
    // }
    forn(i, m){
        ll q;
        cin >> q;
        pll val = {q, inf};
        int ind = upper_bound(lAns.begin(), lAns.end(), val) - lAns.begin();
        ind--;
        cout << lAns[ind].second << ' ';
    }
}
