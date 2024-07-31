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


const int inf = 1e9;
const int nax = 1e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

vector<ii> ans;

bool sol(int n, int m){
    vector<vi> g(n, vi(n, 0));
    forn(i, n)g[i][i] = 1;
    forn(_, m){
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u][v] = 1;
        g[v][u] = 1;
    }
    if(n == 1)return false;
    int mid = n / 2;
    forn(u, mid){
        fore(v, u + 1, mid - 1){
            if(g[u][v] == 0){
                ans.pb({u, v});
                g[u][v] = 1;
                g[v][u] = 1;
            }
        }
    }
    fore(u, mid, n - 1){
        fore(v, u + 1, n - 1){
            if(g[u][v] == 0){
                ans.pb({u, v});
                g[u][v] = 1;
                g[v][u] = 1;
            }
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int n, m;
    cin >> n >> m;
    if(sol(n, m)){
        cout << "YES" << el;
        // db(sz(ans));
        assert(sz(ans) <= n*(n - 1) / 4);
        cout << sz(ans) << el;
        for(auto& [u, v] : ans)cout << u + 1 << ' ' << v + 1 << el;
    }else{
        cout << "NO" << el;
    }
}