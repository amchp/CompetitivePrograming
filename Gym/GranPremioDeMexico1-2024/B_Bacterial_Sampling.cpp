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
const int mod = 1e9 + 7;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

const int N = 10;
struct mint{
    int x;
    mint(): x(0){}
    mint(int x): x(x % mod){}
    mint operator+(mint b){
        int ans = x + b.x;
        if(ans >= mod)ans -= mod;
        return ans;
    }
    mint operator*(mint b){
        return 1LL*x*b.x%mod;
    }
};

struct matrix{ // define N
  int r, c;
  mint m[N][N];
  matrix(int r, int c):r(r),c(c){
    memset(m, 0, sizeof m);
  }
  matrix operator *(const matrix &b){
    matrix c = matrix(this->r, b.c);
    forn(i,this->r){
      forn(k,b.r){
        if(!m[i][k].x) continue;
        forn(j,b.c){
          c.m[i][j] = c.m[i][j] + m[i][k]*b.m[k][j];
        }
      }
    }
    return c;
  }
};
matrix pow(matrix &b, ll e){
  matrix c = matrix(b.r, b.c);
  forn(i,b.r) c.m[i][i] = 1;
  while(e){
    if(e&1LL) c = c*b;
    b = b*b , e/=2;
  }
  return c;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int t;
    cin >> t;
    matrix st(10, 1);
    st.m[0][0] = 1;
    while(t--){
        int n;
        cin >> n;
        n /= 2;
        matrix mtx(10, 10);
        mtx.m[0][0] = 0;
        mtx.m[0][1] = 0;
        fore(i, 2, 9){
            mtx.m[0][i] = (3*!bool(i&1));
        }
        forn(i, 9){
            mtx.m[i + 1][i] = 1;
        }
        matrix ans = pow(mtx, n)*st;
        mint cnt = 0;
        forn(i, 10){
            cnt = cnt + ans.m[i][0];
        }
        cout << cnt.x << el;
    }
}