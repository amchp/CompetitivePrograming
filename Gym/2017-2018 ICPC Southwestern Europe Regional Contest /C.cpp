#include <bits/stdc++.h>
#define el '\n'
#define forn(i, n) for(int i = 0; i < (int)n; ++i)
#define for1(i, n) for(int i = 1; i <= (int)n; ++i)
#define fore(i, l, r)for(int i = l; i <= (int)r; ++i)
#define all(a) a.begin(), a.end()
#define d(x) cerr<<#x<<" "<<x<<el
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

const int N = 257, mod = 1e9;

inline int add(int a,int b){
    if(a+b>=mod) return a+b-mod;
    return a+b;
}
inline int mul(int a,int b){
    return 1LL*a*b%mod;
}
struct matrix{
    int r,c, m[N][N];
    matrix(int r, int c): r(r), c(c){
        memset(m, 0, sizeof(m));
    }
    matrix operator *(const matrix &b){
        assert(this->c == b.r);
        matrix c= matrix(this->r, b.c);
        forn(i,this->r){
            forn(k,b.r){
                if(!m[i][k]) continue;
                forn(j,b.c){
                    c.m[i][j] = add(c.m[i][j], mul(m[i][k], b.m[k][j]));
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
        b = b*b, e/=2;
    }
    return c;
}
int dp[N];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    ll m;
    cin>>n>>m;

    dp[0] = 1, dp[1] = 1;
    fore(i,2,n){
        dp[i] = dp[i-1] + dp[i-2];
    }
    int pot = 1<<n;
    matrix trans(pot, pot);
    forn(col1,pot){
        forn(col2, pot){
            bool flag = 0;
            forn(i, n) if(!((1<<i)&col1) && !((1<<i)&col2) ) flag = 1;
            if(flag) continue;
            int andd = col1 & col2;

            int w = 1;
            for(int i = 0; i < n;){
                while(i < n && !(andd & (1<<i))) ++i;
                if(i==n)break;
                int l = i;
                while(i < n && (andd & (1<<i))) ++i;
                w = mul(w, dp[i-l]);
            }
            trans.m[col1][col2] = w;
        }
    }
    matrix base(pot, 1);
    base.m[pot-1][0] = 1;
    matrix ans = pow(trans, m) * base;
    int tot = ans.m[pot-1][0];
    cout<<tot<<el;
}