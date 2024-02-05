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

const ll inf = 1e13;
const int nax = 1e5 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

struct node{
	ll pre,suf,bst,sum;
	node(ll x): pre(x),suf(x),bst(x),sum(x){}
  node operator+(ll val){
    node ans = node(0);
    ans.pre = val + pre;
    ans.suf = val + suf;
    ans.bst = val + bst;
    ans.sum = val + sum;
    return ans;
  }
};

struct stree{
  node neutro = node(-inf);
  int n, l, r, pos;
  ll val;  vector<node> t;
  stree(int n): n(n), t(n << 2, node(0)){}
  inline node oper(node& a, node& b){
    node ans = node(0);
    ans.bst = max({
      a.bst,
      b.bst,
      a.suf + b.pre
    });
    ans.pre = max(a.pre, a.sum + b.pre);
    ans.suf = max(b.suf, b.sum + a.suf);
    ans.sum = a.sum + b.sum;
    return ans;
  }
  node query(int v, int tl, int tr){
    if(tl > r || tr < l) return neutro;  // estoy fuera
    if(l <= tl && tr <= r) return t[v];
    int tm = (tl + tr) >> 1;
    node lv = query(v << 1, tl, tm);
    node rv =  query((v << 1) | 1, tm+1, tr);
    return oper(lv, rv);
  }
  void upd(int v, int tl, int tr){
    if(tl == tr){
      t[v] = t[v] + val;
      return; 
    }
    int tm = (tl + tr) >> 1;
    if(pos <= tm) upd(v << 1, tl, tm);
    else upd((v << 1) | 1, tm+1, tr);
    t[v] = oper(t[v << 1], t[(v << 1) | 1]);
  }
  void upd(int idx, ll num){ pos = idx, val = num, upd(1, 0, n-1);}
  ll query(int ql, int qr){ l = ql, r = qr;  return query(1, 0, n-1).bst;}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n, m;
    cin >> n >> m;
    vector<vi> events(2*m);
    forn(i, m){
        int l, r, x;
        cin >> l >> r >> x;
        l--;
        r--;
        events[2*i] = {l, i, x};
        events[2*i + 1] = {r+1, i, -x};
    }
    int q;
    cin >> q;
    vector<vi> querys(q);
    forn(i, q){
        int k, l, r;
        cin >> k >> l >> r;
        k--;
        l--;
        r--;
        querys[i] = {k, l, r, i};
    }
    sort(all(querys));
    sort(all(events));
    int ck = 0;
    int ie = 0;
    vl ans(q);
    stree st = stree(m);
    for(vi& vec : querys){
        int k = vec[0];
        int l = vec[1];
        int r = vec[2];
        int ind = vec[3];
        while(ck != (k + 1)){
            while(ie < sz(events) && events[ie][0] == ck){
                st.upd(events[ie][1], events[ie][2]);
                ++ie;
            }
            ++ck;
        }
        ans[ind] = st.query(l, r);
    }
    for(ll& v : ans)cout << v << el;
}
