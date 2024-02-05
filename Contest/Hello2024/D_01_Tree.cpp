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

int a[nax];
int p[nax];
int lu[nax];
int ru[nax];

int find(int u){
    if(p[u] == u)return u;
    return p[u] = find(p[u]);
}

void uni(int u, int v){
    int pu = find(u);
    int pv = find(v);
    int dif = a[pu] - a[pv];
    if(pu == pv || !(dif == 0 || dif == 1))return;
    lu[pv] = min(lu[pu], lu[pv]);
    ru[pv] = max(ru[pu], ru[pv]);
    p[pu] = pv;
    return;
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
        vi zeros;
        forn(i, n){
            cin >> a[i];
            p[i] = i;
            lu[i] = i;
            ru[i] = i;
            if(a[i] == 0)zeros.pb(0);
        }
        if(sz(zeros) != 1){
            cout << "NO" << el;
            continue;
        }
        vector<ii> sca(n);
        forn(i, n){
            sca[i] = {a[i], i};
        }
        sort(all(sca), greater<ii>());
        for(auto& [v, ind] : sca){
            int u = find(ind);
            int l = lu[u];
            // d(v);
            // d(ind);
            // d(u);
            // d(l);
            // d(r);
            if(a[u] < v)continue;
            if(l > 0)uni(u, l - 1);
            u = find(u);
            if(a[u] < v)continue;
            int r = ru[u];
            if(r < n - 1)uni(u, r + 1);
            // forn(i, n)cout << find(i) << ' ';
            // cout << el;
            // cout << "######" << el;
        }
        int ans = true;
        int gp = find(0);
        // cout << gp << ' ';
        for1(i, n - 1){
            // cout << find(i) << ' ';
            ans &= (gp == find(i));
        }
        // cout << el;
        if(ans)cout << "YES" << el;
        else cout << "NO" << el;
    }
}