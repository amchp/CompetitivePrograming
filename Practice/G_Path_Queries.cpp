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
const int nax = 2e5 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

int p[nax];
int szs[nax];
ll gans = 0;

ll range_sum(int x){
    return 1LL*(x - 1)*(x) / 2;
}

int find(int x){
    if(p[x] == x)return x;
    return p[x] = find(p[x]);
}

void combine(int u, int v){
    int pu = find(u);
    int pv = find(v);
    // cout << pu << ' ' << pv << el;
    if(pu == pv)return;
    if(szs[pu] < szs[pv])swap(pu, pv);
    p[pv] = pu;
    gans -= range_sum(szs[pu]);
    // d(gans);
    gans -= range_sum(szs[pv]);
    // d(gans);
    szs[pu] += szs[pv];
    gans += range_sum(szs[pu]);
    // d(gans);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n, q;
    cin >> n >> q;
    vector<vi> ord(n - 1);
    forn(i, n - 1){
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        ord[i] = {w, u, v};
        p[i] = i;
        szs[i] = 1;
    }
    p[n - 1] = n - 1;
    szs[n - 1] = 1;
    sort(all(ord));
    vector<ii> queries(q);
    forn(i, q){
        cin >> queries[i].fi;
        queries[i].se = i;
    }
    sort(all(queries));
    vl ans(q);
    int oi = 0;
    int cw = 0;
    for(auto& [qi, ind] : queries){
        while(oi < n - 1){
            cw = ord[oi][0];
            if(cw > qi)break;
            // d(oi);
            // cout << ord[oi][1] << ' ' << ord[oi][2] << el;
            combine(ord[oi][1], ord[oi][2]);
            ++oi;
        }
        ans[ind] = gans;
    }
    forn(i, q)cout << ans[i] << ' ';
    cout << el;
}
