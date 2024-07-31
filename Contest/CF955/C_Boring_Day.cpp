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

struct stree{
  int neutro = 0, n, l, r, pos, val;  vi t;
  stree(int n): n(n), t(n << 2, 0){}
  stree(const vi& a): n(sz(a)), t(n<<2){ build(1, 0, n-1, a); }
  inline int oper(int a, int b){ return max(a, b); }
  void build(int v, int tl, int tr, const vi& a){// solo para el 2. constructor
    if(tl == tr){ t[v] = a[tl];  return; }
    int tm = (tl + tr) >> 1;
    build(v << 1, tl, tm, a), build((v << 1) | 1, tm+1, tr, a);
    t[v] = oper(t[v << 1], t[(v << 1) | 1]);
  }
  int query(int v, int tl, int tr){
    if(tl > r || tr < l) return neutro;  // estoy fuera
    if(l <= tl && tr <= r) return t[v];
    int tm = (tl + tr) >> 1;
    return oper(query(v << 1, tl, tm), query((v << 1) | 1, tm+1, tr));
  }
  void upd(int v, int tl, int tr){
    if(tl == tr){ t[v] = val;  return; }
    int tm = (tl + tr) >> 1;
    if(pos <= tm) upd(v << 1, tl, tm);
    else upd((v << 1) | 1, tm+1, tr);
    t[v] = oper(t[v << 1], t[(v << 1) | 1]);
  }
  void upd(int idx, int num){ pos = idx, val = num, upd(1, 0, n-1);}
  int query(int ql, int qr){ l = ql, r = qr;  return query(1, 0, n-1);}
};

int n;
ll l, r;

void sol(){
    // Input
    cin >> n >> l >> r;
    vi a(n);
    forn(i, n)cin >> a[i];
    // Prefix
    vll pre(n + 1);
    pre[0] = 0;
    for1(i, n)pre[i] = pre[i - 1] + a[i - 1];
    // max segment tree
    stree st(n + 1);
    // for cards
    for1(cur, n){
        int lft = lower_bound(all(pre), pre[cur] - r) - pre.begin();
        int rgt = upper_bound(all(pre), pre[cur] - l) - pre.begin() - 1;
        // db(lft);
        // db(rgt);
        // db(pre[cur] - r);
        // db(pre[cur] - l);
        // Max three queries (range + 1, before range, after range)
        int ans = 0;
        if(lft <= rgt){
            ans = max({
                st.query(lft, rgt) + 1,
                st.query(0, lft),
                st.query(rgt, cur - 1)
            });
        }else{
            ans = st.query(0, cur - 1);
        }
        // db(ans);
        // update segement tree  
        st.upd(cur, ans);
    }
    // print dp n - 1
    cout << st.query(n, n) << el;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int t;
    cin >> t;
    while(t--){
        sol();
    }
}