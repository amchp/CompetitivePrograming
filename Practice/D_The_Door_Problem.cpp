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
const int nax = 2e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

// Complexity O(V+E)
int N;
vi low, num, comp, g[nax];
vector<bool> truth;
int scc, timer;
stack<int> st;
void tjn(int u) {
  low[u] = num[u] = timer++; st.push(u); int v;
  for(int v: g[u]) {
    if(num[v]==-1) tjn(v);
    if(comp[v]==-1) low[u] = min(low[u], low[v]);
  }
  if(low[u]==num[u]) {
    do{ v = st.top(); st.pop(); comp[v]=scc;
    }while(u != v);
    ++scc;
  }
}
bool solve_2SAT() {
  int n = 2*N;
  timer = scc= 0;
  num = low = comp = vi(n,-1);
  forn(i,n)
    if(num[i]==-1) tjn(i);
  truth = vector<bool>(N, false);
  forn(i,N) {
    if (comp[i] == comp[i + N]) return false;
    truth[i] = comp[i] < comp[i + N];
  }
  return true;
}
int neg(int x){
  if(x<N) return x+N;
  else return x-N;
}
void add_edge(int x, int y){
  g[x].pb(y);
}
void add_disjuntion(int x, int y){
  add_edge(neg(x), y);
  add_edge(neg(y), x);
}
void implies(int x, int y) {
  add_edge(x,y);
  add_edge(neg(y),neg(x));
}
void make_true(int u) { add_edge(neg(u), u); }
void make_false(int u) { make_true(neg(u)); }
void make_eq(int x, int y){
  implies(x, y);
  implies(y, x);
}
void make_dif(int x, int y){
  implies(neg(x), y);
  implies(neg(y), x);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int n, m;
    cin >> n >> m;
    N = m;
    vi a(n);
    forn(i, n){
        cin >> a[i];
    }
    vector<vi> swt(n);
    forn(i, m){
        int x;
        cin >> x;
        forn(_, x){
            int dr;
            cin >> dr;
            --dr;
            swt[dr].pb(i);
        }
    }
    forn(i, n){
        if(a[i]){
            add_disjuntion(swt[i][0], neg(swt[i][1]));
            add_disjuntion(neg(swt[i][0]), swt[i][1]);
        }else{
            add_disjuntion(neg(swt[i][0]), neg(swt[i][1]));
            add_disjuntion(swt[i][0], swt[i][1]);
        }
    }
    if(solve_2SAT())cout << "YES" << el;
    else cout << "NO" << el;
}