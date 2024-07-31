#include<bits/stdc++.h>

#define el '\n'
#define db(x) cerr << #x << ' ' << x << el
#define forn(i,n) for(int i= 0; i < (int)n;++i)
#define fore(i, l, r) for(int i = (int)l; i <= (int)r; ++i)
#define pb push_back
#define sz(a) (int) a.size()
#define all(a) a.begin(), a.end()
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef double ld;
const ld PI = acos(-1.0L);
const ld one = 1;
const int nax = 2e5;

typedef complex<ld> C;
typedef vector<ld> vd;

void fft(vector<C>& a){
    int n = sz(a), L = 31 - __builtin_clz(n);
    static vector<complex<ld>> R(2, 1);
    static vector<C> rt(2, 1);
    for(static int k = 2; k < n; k *= 2){
        R.resize(n);rt.resize(n);
        auto x = polar(one, PI / k);
        fore(i, k, 2*k - 1) rt[i] = R[i] = i& 1 ? R[i/2] * x : R[i / 2];
    }
    vi rev(n);
    forn(i, n) rev[i] = (rev[i / 2] | (i&1) << L) / 2;
    forn(i, n)if(i < rev[i]) swap(a[i], a[rev[i]]);
    for(int k = 1; k < n; k *= 2){
        for(int i = 0; i < n; i += 2*k){
            forn(j, k){
                auto x = (ld *)&rt[j + k], y =(ld *)&a[i+j+k];
                C z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);
                a[i + j + k] = a[i + j] - z;
                a[i + j] += z;
            }
        }
    }
}
typedef vector<ll> vl;
vl conv (const vl& a, const vl& b){
    if(a.empty() || b.empty())return {};
    vl res(sz(a) + sz(b) - 1);
    int L = 32 - __builtin_clz(sz(res)), n = 1 << L;
    vector<C> in(n), out(n);
    copy(all(a), begin(in));
    forn(i, sz(b))in[i].imag(b[i]);
    fft(in);
    for(C& x : in)x *= x;
    forn(i, n)out[i] = in[-i & (n - 1)] - conj(in[i]);
    fft(out);
    forn(i, sz(res))res[i] = floor(imag(out[i]) / (4 * n) + 0.5);
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    string sn, sm;
    cin >> sn >> sm;
    vl r1 = vl(n, 0), p1 = vl(n, 0), sc1 = vl(n, 0);
    forn(i, n){
        if(sn[i] == 'R'){
            r1[i] = 1;
        }
        else if(sn[i] == 'P'){
            p1[i] = 1;
        }else if(sn[i] == 'S'){
            sc1[i] = 1;
        }
    }
    vl r2 = vl(m, 0), p2 = vl(m, 0), sc2 = vl(m, 0);
    forn(i, m){
        if(sm[i] == 'R'){
            r2[i] = 1;
        }else if(sm[i] == 'P'){
            p2[i] = 1;
        }else if(sm[i] == 'S'){
            sc2[i] = 1;
        }
    }
    reverse(all(r2));
    reverse(all(p2));
    reverse(all(sc2));
    vl asr = conv(sc1, r2);
    vl arp = conv(r1, p2);
    vl aps = conv(p1, sc2);
    ll ans = 0;
    fore(i, m - 1, sz(asr)){
        ans = max(ans, asr[i] + arp[i] + aps[i]);
    }
    cout << ans << el;
}