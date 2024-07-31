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
#define d(x) cout<< #x<< " " << x<<el
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


const int inf = 1e9;
const int nax = 1e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int n, m, l;
    cin >> n >> m >> l;
    vector<ii> a(n), b(m);
    ll ans = 0;
    forn(i, n){
        cin >> a[i].fi;
        a[i].se = i;
    }
    forn(i, m){
        cin >> b[i].fi;
        b[i].se = i;
    }
    sort(all(a), greater<ii>());
    sort(all(b), greater<ii>());
    vector<vi> g(n);
    forn(i, l){
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
    }
    forn(u, n)sort(all(g[u]));
    forn(u, n){
        int ind = 0;
        while(ind < m && binary_search(all(g[a[u].se]), b[ind].se))++ind;
        if(ind != m){
            // d(a[u].fi);
            // d(b[ind].fi);
            ans = max(ans, 1LL*a[u].fi + b[ind].fi);
        }
    }
    cout << ans << el;
}