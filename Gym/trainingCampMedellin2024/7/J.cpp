#include<bits/stdc++.h>

#define sz(a) a.size()
#define forn(i,n) for(int i = 0; i < n;++i)
#define for1(i,n) for(int i = 1; i <= n;++i)
#define fore(i, l, r) for(int i = (int)l; i <= (int)r; ++i)
#define el '\n'
#define db(x) cerr<<#x<<" "<<x<<el
#define all(x) x.begin(), x.end()
#define pb push_back

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef double ld;
typedef complex<ld> C;
typedef vector<ld> vd;
typedef pair<int, int> ii;

const int mod = 998244353;

mint binpow(mint b, int e){
    mint ans = 0;
    for(; e; b = b*b, e/=2){
        if(e&1)ans = ans*b;
    }
    return ans;
}

struct mint{
    int x;
    mint() : x(0){}
    mint(ll x) : x(x % mod){}
    mint operator+(mint b){
        int ans = x + b.x;
        if(ans >= mod)ans -= mod;
        return ans;
    }
    mint operator-(mint b){
        int ans = x - b.x;
        if(ans < 0)ans += mod;
        return ans;
    }
    mint operator*(mint b){
        return 1LL*x*b.x%mod;
    }
    mint inv(){
        return binpow(*this, mod - 2);
    }
    mint operator/(mint b){
        return (*this)*b.inv();
    }
};

const int nax = 1 << 20;

mint c1[nax + 9], c2[nax + 9];

void fht(mint* p, int n, bool inv){
    for(int l=1;2*l<=n;l*=2)for(int i=0;i<n;i+=2*l)forn(j, l){
        mint u = p[i+j];
        mint v = p[i+l+j];
        if(!inv){
            p[i+j]=u+v;
            p[i+l+j]=u-v;
        }
        else{
            p[i+j]=(u+v)/2;
            p[i+l+j]=(u-v)/2;
        }
    }
}

vector<mint> multiply(vector<mint>& p1, vector<mint>& p2){
    int n = 1 << (32-__builtin_clz(max(sz(p1), sz(p2))-1));
    forn(i, n)c1[i]=0, c2[i]=0;
    forn(i, sz(p1))c1[i]=p1[i];
    forn(i, sz(p2))c2[i]=p2[i];
    fht(c1, n, false); fht(c2, n, false);
    forn(i, n)c1[i]=c1[i]*c2[i];
    fht(c1, n, true);
    return vector<mint>(c1, c1 + n);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int m, k;
    vector<mint> a(k);
}