#include <vector>
#include <map>
#include <cstdlib>
#include <fstream>
#include <iomanip>   
#include <iostream>  
#include <sstream>  // istringstream buffer(myString);
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <math.h>
#include <unordered_map>
#include <queue>
#include <array>
#include <set>
#include <numeric>
#include <complex>

using namespace std;


typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi; // int vec
typedef vector<ll> vll; // int vec
typedef vector<vi> vvi; // int vec vec
typedef vector<vll> vvll; // int vec
typedef vector<pii> vpi; // int int pair vec
typedef vector<pll> vpll; // int int pair vec
typedef complex<double> cd; 

const double pi = 3.1415926535897932384626433832795;
const int maxn = 1e5 + 5;
const ll MOD = 998244353;
const ll INF = 1e9;
const ll INFLL = 1000000000000000005LL;
const ld EPS = 1e-9;
int dirx[8] = { -1, 0, 0, 1, -1, -1, 1, 1 };
int diry[8] = { 0, 1, -1, 0, -1, 1, -1, 1 };

#define d(x) cout << #x << " = " << x << endl;
#define ios ios_base::sync_with_stdio(0), cin.tie(0);
#define forn(i, n) for (int i=0; i< (int)n; ++i) 
#define forab(i, a, b) for (int i=a; i< (int)b; ++i) 
#define foreach(a, b) for (auto&(a) : (b))
#define formap(map) for (const auto &[key, value] : map)
#define all(v) v.begin(), v.end()
#define allar(arr, sz) arr, arr + sz
#define ms(ar, val) memset(ar, val, size)
#define pq(type) priority_queue<type> 
#define pqd(type) priority_queue<type,vector<type>,greater<type> >
#define umap unordered_map
#define uset unordered_set
#define imax INT_MAX
#define imin INT_MIN
#define pb push_back
#define mp make_pair
#define fi first 
#define se second 
#define nl "\n"
#define in(t) while (t--)

int const N = 205;

struct matrix{ // define N
    ll r, c, m[N][N];
    matrix(int r, int c):r(r),c(c){
        memset(m, 0, sizeof m);
    }
    matrix operator -(const matrix &b){
        matrix c = matrix(this->r, this->c);
        forn(i,this->r){
            forn(j,this->c){
                c.m[i][j] = (m[i][j]-b.m[i][j] + MOD) % MOD;
            }
        }
        return c;
    }
    matrix operator *(const matrix &b){
        matrix c = matrix(this->r, b.c);
        forn(i,this->r){
        forn(k,b.r){
            if(!m[i][k]) continue;
            forn(j,b.c){
                c.m[i][j] += ((m[i][k]*b.m[k][j]) % MOD + MOD);
                c.m[i][j] %= MOD;
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
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n, m, k;
    cin >> n >> m >> k;
    matrix A = matrix(n, n);
    matrix D = matrix(n, n);
    forn(i, m){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        A.m[u][v] = 1;
        A.m[v][u] = 1;
        D.m[u][u] += 1;
        D.m[v][v] += 1;
    }
    matrix ans = matrix(n, n);
    if(k == 1){
        ans = A;
    }
    else if(k == 2){
        ans = A*A - D;
    }else{
        matrix I = matrix(n, n);
        forn(i,n) I.m[i][i] = 1;
        matrix L = matrix(2*n, 2*n);
        matrix DI = (D - I);
        forn(i, n){
            forn(j, n){
                L.m[i][j] = A.m[i][j];
                L.m[i][j + n] = -DI.m[i][j];
                L.m[i + n][j] = I.m[i][j];
            }
        }
        // forn(i, 2*n){
        //     forn(j, 2*n){
        //         cout << L.m[i][j] << ' ';
        //     }
        //     cout << nl;
        // }
        matrix lK = pow(L, k - 2);
        matrix s2 = A*A - D;
        matrix s = matrix(2*n, n);
        forn(i, n){
            forn(j, n){
                s.m[i + n][j] = A.m[i][j];
                s.m[i][j] = s2.m[i][j];
            }
        }
        matrix lKS = lK * s;
        forn(i, n){
            forn(j, n){
                ans.m[i][j] = lKS.m[i][j];
            }
        }
    }
    ll res = 0;
    forn(i, n){
        res += ans.m[i][i];
        res %= MOD;
    }
    cout << res << nl;
}