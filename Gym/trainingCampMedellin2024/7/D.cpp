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

vl create_flat_grid(vector<vi>& grid, int col, int buf){
    int r = sz(grid);
    int c = sz(grid[0]);
    vl fgrid = vl(r*(c + buf) - buf, 0);
    forn(i, r){
        forn(j, c){
            fgrid[i*(c+buf) + j] = grid[i][j] == col;
        }
    }
    return fgrid;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int r, c;
    cin >> r >> c;
    vector<vi> ptrn(r, vi(c));
    set<int> cols;

    forn(i, r){
        forn(j, c){
            cin >> ptrn[i][j];
            if(ptrn[i][j]){
                cols.insert(ptrn[i][j]);
            }
        }
    }

    int R, C;
    cin >> R >> C;
    vector<vi> grid(R, vi(C));
    forn(i, R){
        forn(j, C){
            cin >> grid[i][j];
        }
    }

    if(r > R || c > C){
        cout << 0 << el;
        return 0;
    }

    vl fgridarbitary = vl(R*C, 1);
    vl fptrnarbitary = create_flat_grid(ptrn, 0, C - c);
    reverse(all(fptrnarbitary));
    vl ans = conv(fgridarbitary, fptrnarbitary);
    for(int col : cols){
        vl fgrid = create_flat_grid(grid, col, 0);
        vl fptrn = create_flat_grid(ptrn, col, C - c);
        reverse(all(fptrn));
        vl cans = conv(fgrid, fptrn);
        assert(sz(ans) == sz(cans));
        forn(i, sz(ans)){
            ans[i] += cans[i];
        }
    }

    vector<ii> fans;
    int dif = C - c;
    for(int i = sz(fptrnarbitary) - 1; i <= sz(ans) - 1; i += C - dif){
        forn(j, dif + 1){
            if(ans[i + j] == r*c){
                int ind = (i + j) - (sz(fptrnarbitary) - 1);
                int x = ind / C;
                int y = ind % C;
                fans.pb({x, y});
            }
        }
    }

    cout << sz(fans) << el;
    for(auto& [i, j] : fans)cout << i + 1 << ' ' << j + 1 << el;
}