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

struct pt{
	ll x, y;
    int ind;
	pt(){}
	pt(ll x, ll y, int ind): x(x), y(y), ind(ind){}
  // ------- BASIC OPERATORS -------  //        
    pt operator+(pt p){ return pt(x+p.x, y+p.y, -1); }
	pt operator-(pt p){ return pt(x-p.x, y-p.y, -1); }
	ll operator*(pt p){ return x*p.x + y*p.y; }
	ll operator%(pt p){ return x*p.y - y*p.x; }
    ll side(pt p, pt q){ return (q-p) % (*this-p); }// C is: >0 L, ==0 on AB, <0 R
	bool left(pt p, pt q){ // Left of directed line PQ? (eps == 0 if integer)
		return side(p, q) > 0; 
    } // (change to >= -eps to accept collinear)
};

const int L = 24;
int timer, up[nax][L+1], n;
int in[nax], out[nax];
vi g[nax];
void dfs(int u, int p){
  in[u] = ++timer;
  up[u][0] = p;
  for1(i,L) up[u][i] = up[up[u][i-1]][i-1];
  for(int v: g[u]){
    if(v==p) continue;
    dfs(v,u);
  }
  out[u] = ++timer;
}
bool anc(int u, int v){
  return in[u]<= in[v] && out[u]>= out[v];
}
void solve(int root){
  timer = 0;
  dfs(root,root);
}
int lca(int u, int v){
  if(anc(u,v)) return u;
  if(anc(v,u)) return v;
  for(int i= L; i>=0; --i){
    if(!anc(up[u][i],v))
      u = up[u][i];
  }
  return up[u][0];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int n;
    cin >> n;
    vector<pt> pts(n);
    forn(i, n){
        cin >> pts[i].x >> pts[i].y;
        pts[i].ind = i;
    }
    vector<pt> st;
    st.push_back(pts.back());
    pt zero = pt(0, 0, -1);
    ford(i, n - 1){
        while(sz(st) >= 2 && (st[sz(st) - 2] - pts[i]).left(zero, st[sz(st) - 1] - pts[i])){
            // d((st[sz(st) - 2] - pts[i]).side(zero, st[sz(st) - 1] - pts[i]));
            st.pop_back();
        }
        int& u = st.back().ind;
        int& v = pts[i].ind;
        // d(u);
        // d(v);
        g[u].pb(v);
        g[v].pb(u);
        st.push_back(pts[i]);
    }
    solve(n - 1);
    int m;
    cin >> m;
    forn(i, m){
        int u, v;
        cin >> u >> v;
        --u, --v;
        int lc = lca(u, v);
        cout << lc + 1 << ' ';
    }
    cout << el;
}