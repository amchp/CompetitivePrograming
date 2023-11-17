#include<bits/stdc++.h>

using namespace std;
#define forn(i, n) for(int i = 0; i < n; ++i)
#define for1(i, n) for(int i = 1; i <= n; ++i)
#define fore(i, l, r) for(int i = (int)l; i <= (int)r; ++i)
#define el '\n'
#define sz(a) (int) a.size()
#define pb  push_back
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define d(x) cerr<<#x<<" "<<x<<el
#define RAYA cerr<<"######" << el;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef tuple<int,int,int> iii;

const int nax = 5e5 + 200;

const int MOD[] = {1001864327, 1001265673}, N = 2e5;
const ii BASE(257,367), ZERO(0,0), ONE(1,1);
inline int add(int a, int b,int mod){return a+b>=mod ? a+b-mod: a+b;}
inline int sbt(int a, int b,int mod){return a-b<0 ? a-b+mod: a-b;}
inline int mul(int a, int b,int mod){return ll(a) * b % mod;}

inline ll operator !(const ii a){return (ll(a.fi) <<32) | a.se;}
inline ii operator +(const ii &a, const ii &b){
    return {add(a.fi,b.fi,MOD[0]),add(a.se,b.se,MOD[1])};
}
inline ii operator -(const ii &a, const ii &b){
    return {sbt(a.fi,b.fi,MOD[0]),sbt(a.se,b.se,MOD[1])};
}
inline ii operator *(const ii &a, const ii &b){
    return {mul(a.fi,b.fi,MOD[0]),mul(a.se,b.se,MOD[1])};
}
ii base[N]{ONE};
void prepare(){for1(i,N-1) base[i] =base[i-1] * BASE;}

template<class type>
struct hashing{
    vector<ii> ha;
    hashing(){}
    hashing(type &t) : ha(sz(t)+1,ZERO){
        for1(i,sz(t)) ha[i] = ha[i-1]*BASE + ii{t[i-1],t[i-1]};
    }
    ii query(int l,int r){return ha[r+1] - ha[l] * base[r-l+1];}
};

int n;

hashing<string> der;
hashing<string> rev;
string s;
string rv;

bool check(int l, int r){
    int rl = n - 1 - r;
    int rr = n - 1 - l;
    // fore(i, l, r)cerr << s[i];
    // cerr << el;
    // fore(i, rl, rr)cerr << rv[i];
    // cerr << el;
    // RAYA;
    return der.query(l, r) == rev.query(rl, rr);
}

bool check2(int l1, int r1, int l2, int r2){
    int rl = n - 1 - r2;
    int rr = n - 1 - l2;
    // // d(l1), d(r1);
    // fore(i, l1, r1)cerr << s[i];
    // cerr << el;
    // // d(rl), d(rr);
    // fore(i, rl, rr)cerr << rv[i];
    // cerr << el;
    return der.query(l1, r1) == rev.query(rl, rr);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    prepare();
    cin>>n;
    cin>>s;
    der = hashing<string>(s);
    rv = s;
    reverse(all(rv));
    rev = hashing<string>(rv);
    ll ans = 0;
    forn(i,n){
        int l = -1, r = min(n-i,i+1);
        // d(i);
        // d(l), d(r);
        // cerr << "FIRST" << el;
        while(l + 1 < r){
            int mid = l + (r-l)/2;
            if(check(i - mid, i + mid)){
                l = mid;
            }else r = mid;
        }
        int li = l, ri = r;
        int lb = i - li - 2;
        int rb = i + li + 2;
        // d(li), d(ri);
        l = -1;
        r = min(n-rb,lb + 1);//()
        // cerr << "SECOND" << el;
        // d(l), d(r);
        while(l+1<r){
            int mid = l + (r-l)/2;
            int ll = lb-mid, rl = rb+mid;
            if(
                check2(ll, lb, rb, rl)
            ){
                l = mid;
            }else r = mid;
        }
        // d(l), d(r);
        if(l < r)ans+= l + 2;
        ans+= li + 1;
        // d(ans);
        // RAYA;
    }
    // RAYA;

    for1(i,n-1){
        int l = -1, r = min(n-i,i);// i - i - 1
        // d(i);
        // d(l), d(r);
        // cerr << "FIRST" << el;
        while(l + 1 < r){
            int mid = l + (r-l)/2;
            int lr = n-1-(i+mid), rr = n-1-(i- (mid + 1));
            if(check(i - (mid + 1), i + mid)){
                l = mid;
            }else r = mid;
        }
        int li = l, ri = r;
        // d(li), d(ri);
        int lb = i - li - 3;
        int rb = i + li + 2;
        // d(lb);
        // d(rb);
        l = -1;//invalido ya que no son iguales
        r = min(n-rb,lb + 1);//()
        // d(l),d(r);
        while(l+1<r){
            int mid = l + (r-l)/2;
            int ll = lb - mid, rl = rb+mid;
            if(
                check2(ll, lb, rb, rl)
            ){
                l = mid;
            }else r = mid;
        }
        // d(l),d(r);
        if(l < r)ans+= l + 2;
        ans += li + 1;
        // d(ans);
        // RAYA;
    }
    cout<<ans<<el;
}