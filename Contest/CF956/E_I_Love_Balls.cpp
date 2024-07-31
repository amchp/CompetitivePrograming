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

const int mod = 1e9 + 7;

typedef long long ll;
const int mod = 1e9 + 7;
template <class T>
T bpow(T b, int e) {
  T a(1);
  do{
    if(e & 1) a *= b;
    b *= b;
  }while(e >>= 1);
  return a;
}
struct mint {
  int x;
  mint(): x(0){}
  mint(ll v) : x((v % mod + mod) % mod) {} // be careful of negative numbers!
  // Helpers to shorten code
  #define add(a, b) a + b >= mod ? a + b - mod : a + b
  #define sub(a, b) a < b ? a + mod - b : a - b
  #define yo *this
  #define cmint const mint&
  
  mint &operator += (cmint o) { return x = add(x, o.x), yo; }
  mint &operator -= (cmint o) { return x = sub(x, o.x), yo; }
  mint &operator *= (cmint o) { return x = ll(x) * o.x % mod, yo; }
  mint &operator /= (cmint o) { return yo *= bpow(o, mod-2); }

  mint operator + (cmint b) const { return mint(yo) += b; }
  mint operator - (cmint b) const { return mint(yo) -= b; }
  mint operator * (cmint b) const { return mint(yo) *= b; }
  mint operator / (cmint b) const { return mint(yo) /= b; }

  mint operator - () const { return mint() - mint(yo); }
  bool operator == (cmint b) const { return x == b.x; }
  bool operator != (cmint b) const { return x != b.x; }

  friend ostream& operator << (ostream &os, cmint p) { return os << p.x; }
  friend istream& operator >> (istream &is, mint &p) { return is >> p.x; }
};

struct frac{
  mint num, den;
  frac(){}
  frac(mint num, mint den):num(num), den(den){}
  frac operator+(const frac& b){ return {num*b.den + b.num*den, den*b.den};}
  frac operator-(const frac& b){ return {num*b.den - b.num*den, den*b.den};}
  frac operator*(const frac& b){ return {num*b.num, den*b.den};}
  frac operator/(const frac& b){ return {num*b.den, den*b.num};}
};

void sol(){
    int n, k;
    cin >> n >> k;
    vll a(n);
    ll sm = 0;
    forn(i, n){
        cin >> a[i];
        sm += a[i];
    }
    if(k == n){
        cout << sm << ' ' << 0 << el;
        return;
    }
    frac fa = {0, 1};
    frac fb = {0, 1};
    int nrm = n - k;
    int nrm2 = nrm / 2;
    fore(m, nrm2, nrm2 + k){
        forn(i, n){
            frac pa = frac(2*m, 2*k) - frac(n - k, 2*k);
            fa = fa + pa*frac(m, n)*frac(a[i], 1);
        }
    }
    
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