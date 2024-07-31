#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


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
using namespace __gnu_pbds;

typedef long long ll;
typedef double ld;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<ld> vd;
typedef tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> ordered_set;


const int inf = 1e9;
const int nax = 1e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

struct stree{
  ll neutro = 0;
  int n, l, r, pos;
  ll val;  vll t;
  stree(int n): n(n), t(n << 2){}
  stree(const vi& a): n(sz(a)), t(n<<2){ build(1, 0, n-1, a); }
  inline ll oper(ll a, ll b){ return a + b; }
  void build(int v, int tl, int tr, const vi& a){// solo para el 2. constructor
    if(tl == tr){ t[v] = a[tl];  return; }
    int tm = (tl + tr) >> 1;
    build(v << 1, tl, tm, a), build((v << 1) | 1, tm+1, tr, a);
    t[v] = oper(t[v << 1], t[(v << 1) | 1]);
  }
  ll query(int v, int tl, int tr){
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
  ll query(int ql, int qr){ l = ql, r = qr;  return query(1, 0, n-1);}
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int t;
    cin >> t;
    while(t--){
      int n, q;
      cin >> n >> q;
      vector<ordered_set> ord(n);
      vi col(n);
      forn(i, n){
        cin >> col[i];
        --col[i];
        ord[col[i]].insert(i);
      }
      vi a(n);
      forn(i, n){
        cin >> a[i];
      }
      stree st = stree(a);
      forn(_, q){
        int op, pos, x;
        cin >> op >> pos >> x;
        --pos;
        if(op == 1){
          --x;
          ord[col[pos]].erase(pos);
          col[pos] = x;
          ord[col[pos]].insert(pos);
        }
        if(op == 2){
          st.upd(pos, x);
        }
        if(op == 3){
          vi sa(x);
          vi inc(x);
          vi ninc(x);
          forn(i, x){
            cin >> sa[i];
            --sa[i];
            inc[i] = ord[sa[i]].order_of_key(pos + 1);
            ninc[i] = ord[sa[i]].order_of_key(pos);
          }
          int l = -1, r = pos + 1;
          while(l + 1 < r){
            int mid = l + (r - l) / 2;
            int sm = 0;
            forn(i, x){
              int lft = ord[sa[i]].order_of_key(mid);
              sm += inc[i] - lft;
            }
            // assert(sm <= pos - mid + 1);
            if(sm == pos - mid + 1){
              r = mid;
            }else{
              l = mid;
            }
          }
          int al = r;
          l = pos - 1, r = n;
          while(l + 1 < r){
            int mid = l + (r - l) / 2;
            int sm = 0;
            forn(i, x){
              int rgt = ord[sa[i]].order_of_key(mid + 1);
              sm += rgt - ninc[i];
            }
            // assert(sm <= mid - pos + 1);
            if(sm == mid - pos + 1){
              l = mid;
            }else{
              r = mid;
            }
          }
          int ar = l;
          // assert(0 <= al && al < n);
          // assert(0 <= ar && ar < n);
          // assert(al <= ar);
          cout << st.query(al, ar) << el;
        }
      }
    }
}