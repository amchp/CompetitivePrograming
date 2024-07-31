#include<bits/stdc++.h>

#define sz(a) a.size()
#define forn(i,n) for(int i = 0; i < n;++i)
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

const ld PI = acos(-1.0L);
const ld one = 1;
const int mod = 998244353;

void fft(vector<C>& a){
    int n = sz(a), L = 31 - __builtin_clz(n);
    static vector<complex<ld>> R(2, 1);
    static vector<C> rt(2, 1);
    for(static int k = 2; k < n; k *= 2){
        R.resize(n); rt.resize(n);
        auto x = polar(one, PI / k);
        fore(i, k, 2*k - 1)rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
    }
    vi rev(n);
    forn(i, n)rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    forn(i, n)if (i < rev[i]) swap(a[i], a[rev[i]]);
    for(int k = 1; k < n; k *=2)
        for(int i = 0; i < n; i += 2*k)forn(j, k){
            auto x = (ld*)&rt[j+k], y = (ld*)&a[i+j+k];
            C z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);
            a[i + j + k] = a[i + j] - z;
            a[i + j] += z;
        }
}

typedef vector<ll> vl;

vl convMod(const vl& a, const vl&b, const int& M){
    if(a.empty() || b.empty())return {};
    vl res(sz(a) + sz(b) - 1);
    int B = 32 - __builtin_clz(sz(res)), n=1<<B, cut=int(sqrt(M));
    vector<C> L(n), R(n), outs(n), outl(n);
    forn(i, sz(a)) L[i] = C((int)a[i] / cut, (int)a[i] % cut);
    forn(i, sz(b)) R[i] = C((int)b[i] / cut, (int)b[i] % cut);
    fft(L), fft(R);
    forn(i, n){
        int j = -i & (n - 1);
        outl[j] = (L[i] + conj(L[j])) * R[i] / (2.0 * n);
        outs[j] = (L[i] - conj(L[j])) * R[i] / (2.0 * n) / 1i;
    }
    fft(outl), fft(outs);
    forn(i, sz(res)){
        ll av = ll(real(outl[i])+.5), cv = ll(imag(outs[i])+.5);
        ll bv = ll(imag(outl[i])+.5) + ll(real(outs[i])+.5);
        res[i] = ((av % M * cut + bv) % M * cut + cv) % M;
    }
    return res;
}

vl operator*(vl& a, vl& b){
    return convMod(a, b, mod);
}

vl binpow(vl b, int e){
    vl bc = b;
    vl ans = {1};
    for(; e; b = b*bc, bc = b, e /=2)
        if(e&1) ans = ans*b;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    int n2 = n / 2;
    vi a(k);
    int mx = 0;
    forn(i, k){
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    vl ft(mx + 1);
    forn(i, k){
        ft[a[i]] = 1;
    }
    vl ftc = ft;
    vl ans = binpow(ft, n2);
    ll fans = 0;
    for(ll& v : ans){
        fans += (v*v) % mod;
        fans %= mod;
    }
    cout << fans << el;
}
