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

const int inf = 1e9;
const int nax = 1e5 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

struct stree{
  int neutro = 0, n, l, r, pos, val;  vi t;
  stree(int n): n(n), t(n << 2){}
  stree(const vi& a): n(sz(a)), t(n<<2){ build(1, 0, n-1, a); }
  inline int oper(int a, int b){ return a + b; }
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
  int query2(int v, int tl, int tr){
    if(tl == tr){
        if(val - t[v] > 0)return -1;
        return tl;
    }
    int tm = (tl + tr) >> 1;
    // d(val);
    // d(t[v << 1]);
    if(t[v << 1] >= val){
        return query2(v << 1, tl, tm);
    }else{
        val -= t[v << 1];
        return query2((v << 1) | 1, tm + 1, tr);
    }
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
  int query2(int qval){val = qval;  return query2(1, 0, n-1);}
};

void sol(){
    int n, q;
    cin >> n >> q;
    vi a(n);
    set<int> ones;
    forn(i, n){
        cin >> a[i];
        if(a[i] == 1)ones.insert(i);
    }
    stree st(a);
    while(q--){
        int op, num;
        cin >> op >> num;
        if(op == 1){
            int ind = st.query2(num);
            // d(ind);
            if(ind == -1){
                cout << "NO" << el;
                continue;
            }
            // d(st.query(0, ind));
            if(
                st.query(0, ind) == num ||
                (
                    !ones.empty() &&
                    (
                        ind < (*ones.rbegin()) ||
                        ind + (*ones.begin()) < n
                    )
                ) 
            ){
                cout << "YES" << el;
                continue;
            }
            cout << "NO" << el;
        }else if(op == 2){
            num--;
            int val;
            cin >> val;
            st.upd(num, val);
            if(a[num] == 1)ones.erase(num);
            a[num] = val;
            if(a[num] == 1)ones.insert(num);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t;
    cin >> t;
    while(t--){
        sol();
    }
}
