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
typedef vector<vl> vvl;

const int inf = 1e9;
const int nax = 1e5 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

struct node{
    int i, j;
    ll val;
    node(){};
    node(int i, int j, ll val): i(i), j(j), val(val){}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vvl a(n, vl(m));
    forn(i, n){
        forn(j, m)cin >> a[i][j];
    }
    queue<node> q;
    vector<map<ll, ll>> dgup(min(n, m));
    int mnnm = min(n, m);
    q.push(node(0, 0, a[0][0]));
    while(!q.empty()){
        node nd = q.front();
        q.pop();
        int i = nd.i, j = nd.j;
        int di = i + 1, dj = j + 1;
        ll val = nd.val;
        if(i + j == mnnm - 1){
            dgup[j][val]++;
            continue;
        }
        if(di < n){
            ll nval = a[di][j] ^ val;
            q.push(node(di, j, nval));
        }
        if(dj < m){
            ll nval = a[i][dj] ^ val;
            q.push(node(i, dj, nval));
        }
    }
    vector<map<ll, ll>> dgdw(min(n, m));
    q.push(node(n - 1, m - 1, a[n - 1][m - 1]));
    while(!q.empty()){
        node nd = q.front();
        q.pop();
        int i = nd.i, j = nd.j;
        int di = i - 1, dj = j - 1;
        ll val = nd.val;
        if(i + j == mnnm - 1){
            dgdw[j][val]++;
            continue;
        }
        if(di >= 0){
            ll nval = a[di][j] ^ val;
            q.push(node(di, j, nval));
        }
        if(dj >= 0){
            ll nval = a[i][dj] ^ val;
            q.push(node(i, dj, nval));
        }
    }
    ll ans = 0;
    forn(i, mnnm){
        for(auto& [key, val] : dgup[i]){
            ans += val*dgdw[i][key ^ a[mnnm - 1 - i][i] ^ k];
        }
    }
    cout << ans << el;
}
