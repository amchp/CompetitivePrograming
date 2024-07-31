#include <bits/stdc++.h>

#define fi first
#define se second
#define forn(i,n) for(int i=0; i< (int)n; ++i)
#define for1(i,n) for(int i=1; i<= (int)n; ++i)
#define fore(i,l,r) for(int i=(int)l; i<= (int)r; ++i)
#define ford(i,n) for(int i=(int)(n) - 1; i>= 0; --i)
#define fored(i,l,r) for(int i=(int)r; i>= (int)l; --i)
#define pb push_back
#define el endl
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
const int nax = 1e4+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

vi g[nax];
int col[nax];

bool dfs(int u, int c){
    for(int& v : g[u]){
        if(col[v] == -1){
            col[v] = !c;
            if(!dfs(v, !c))return false;
        }else if(col[u] == col[v])return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        forn(i, n){
            g[i].clear();
            col[i] = -1;
        }
        forn(i, m){
            int u, v;
            cin >> u >> v;
            --u, --v;
            g[u].pb(v);
            g[v].pb(u);
        }
        if(!dfs(0, 0)){
            cout << "Alice" << endl;
            forn(i, n){
                cout << 1 << ' ' << 2 << endl;
                int u, v;
                cin >> u >> v;
            }
            return 0;
        }
        cout << "Bob" << endl;
        vi one, two;
        forn(i, n){
            if(col[i] == 0)one.pb(i);
            else two.pb(i);
        }
        while(sz(one) && sz(two)){
            int u, v;
            cin >> u >> v;
            if(u != 1 && v != 1){
                cout << two.back() + 1 << ' ' << 2 << endl;
                two.pop_back();
            }else{
                cout << one.back() + 1 << ' ' << 1 << endl;
                one.pop_back();
            }
        }
        while(sz(one)){
            int u, v;
            cin >> u >> v;
            if(u != 2){
                cout << one.back() + 1 << ' ' << u << endl;
            }else{
                cout << one.back() + 1 << ' ' << v << endl;
            }
            one.pop_back();
        }
        while(sz(two)){
            int u, v;
            cin >> u >> v;
            if(u != 1){
                cout << two.back() + 1 << ' ' << u << endl;
            }else{
                cout << two.back() + 1 << ' ' << v << endl;
            }
            two.pop_back();
        }
    }
}