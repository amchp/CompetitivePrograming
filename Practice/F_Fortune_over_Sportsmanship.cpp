#include <bits/stdc++.h>

#define fi first
#define se second
#define forn(i,n) for(int i=0; i< (int)n; ++i)
#define for1(i,n) for(int i=1; i<= (int)n; ++i)
#define fore(i,l,r) for(int i=(int)l; i<= (int)r; ++i)
#define ford(i,n) for(int i=(int)(n) - 1; i>= 0; --i)
#define fored(i,l,r) for(int i=(int)r; i>= (int)l; --i)
#define pb push_back
#define el '\n'
#define db(x) cout<< #x<< " " << x<<el
#define ri(n) scanf("%d",&n)
#define sz(v) int(v.size())
#define all(v) v.begin(),v.end()

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<ld> vd;
typedef array<int, 3> a3;

const int inf = 1e9;
const int nax = 1000+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

int p[nax];

int find(int x){
    return p[x] = x == p[x] ? x : find(p[x]);
}

vector<ii> ans;

bool join(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v)return false;
    ans.pb({u, v});
    if(u < v)p[v] = u;
    else p[u] = v;
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int n;
    cin >> n;
    vector<vi> mtx(n, vi(n));
    forn(i, n)p[i] = i;
    forn(i, n){
        forn(j, n)cin >> mtx[i][j];
    }
    vector<a3> edg;
    forn(i, n){
        fore(j, i + 1, n - 1){
            edg.pb({mtx[i][j], i, j});
        }
    }
    sort(all(edg), greater<a3>());
    int vans = 0;
    for(auto& [val, u, v] : edg){
        if(join(u, v))vans += val;
    }
    cout << vans << el;
    assert(sz(ans) == n - 1);
    for(auto& [u, v] : ans)cout << u + 1 << ' ' << v + 1 << el;
}