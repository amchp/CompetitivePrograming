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

const int N = 2;
int mod;

struct matrix{ // define N
  int r, c, m[N][N];
  matrix(){
    r = 0;
    c = 0;
  }
  matrix(int r, int c):r(r),c(c){
    memset(m, 0, sizeof m);
  }
  matrix(vector<vi> im){
    r = sz(im);
    c = sz(im[0]);
    forn(i, r){
        forn(j, c){
            m[i][j] = im[i][j];
        }
    }
  }
  matrix operator *(const matrix &b){
    matrix c = matrix(this->r, b.c);
    forn(i,this->r){
      forn(k,b.r){
        if(!m[i][k]) continue;
        forn(j,b.c){
          c.m[i][j] += m[i][k]*b.m[k][j] % mod;
          c.m[i][j] %= mod;
        }
      }
    }
    return c;
  }
};

struct stree{
  matrix neutro = matrix({{1, 0}, {0, 1}});
  int n, l, r, pos;
  matrix val;
  vector<matrix> t;
  stree(const vector<matrix>& a): n(sz(a)), t(n<<2){ build(1, 0, n-1, a); }
  inline matrix oper(matrix a, matrix b){ return a * b; }
  void build(int v, int tl, int tr, const vector<matrix>& a){// solo para el 2. constructor
    if(tl == tr){ t[v] = a[tl];  return; }
    int tm = (tl + tr) >> 1;
    build(v << 1, tl, tm, a), build((v << 1) | 1, tm+1, tr, a);
    t[v] = oper(t[v << 1], t[(v << 1) | 1]);
  }
  matrix query(int v, int tl, int tr){
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
  void upd(int idx, matrix num){ pos = idx, val = num, upd(1, 0, n-1);}
  matrix query(int ql, int qr){ l = ql, r = qr;  return query(1, 0, n-1);}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n, m;
    cin >> mod >> n >> m;
    vector<matrix> a(n, matrix(2, 2));
    forn(i, n){
        forn(j, 2){
            forn(k, 2){
                cin >> a[i].m[j][k];
            }
        }
    }
    stree st(a);
    while(m--){
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        matrix c = st.query(l, r);
        forn(i, 2){
            forn(j, 2){
                cout << c.m[i][j] << ' ';
            }
            cout << el;
        }
        cout << el;
    }
}
