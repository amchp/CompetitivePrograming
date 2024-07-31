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

vl conv(const vl& a, const vl& b){
    if (a.empty() || b.empty())return {};
    vl res(sz(a) + sz(b) - 1);
    int L = 32 - __builtin_clz(sz(res)), n = 1 << L;
    vector<C> in(n), out(n);
    copy(all(a), begin(in));
    forn(i, sz(b)) in[i].imag(b[i]);
    fft(in);
    for (C& x : in)x *= x;
    forn(i, n) out[i] = in[-i & (n - 1)] - conj(in[i]);
    fft(out);
    forn(i, sz(res)) res[i] = floor(imag(out[i]) / (4 * n) + 0.5);
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vi a(n);
    int mx = 0;
    forn(i, n){
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    vl ft(mx + 1);
    forn(i, n){
        // db(a[i]);
        ft[a[i]] = 1;
    }
    queue<vl> q;
    forn(i, k){
        q.push(ft);
    }
    while(sz(q) >= 2){
        vl a = q.front();
        q.pop();
        vl b = q.front();
        q.pop();
        vl c = conv(a, b);
        for(ll& v : c){
            v = min(1LL, v);
        }
        q.push(c);
    }
    vl& ans = q.front();
    forn(i, sz(ans)){
        if(ans[i] != 0){
            cout << i << ' ';
        }
    }
    cout << el;
}