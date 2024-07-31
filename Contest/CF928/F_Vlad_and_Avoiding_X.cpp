#include <bits/stdc++.h>

#define fi first
#define se second
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define for1(i, n) for (int i = 1; i <= (int)n; ++i)
#define fore(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define ford(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define fored(i, l, r) for (int i = (int)r; i >= (int)l; --i)
#define pb push_back
#define el '\n'
#define d(x) cout << #x << " " << x << el
#define ri(n) scanf("%d", &n)
#define sz(v) ((int)v.size())
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> ii;
typedef pair<char, int> pci;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int inf = 1e9;
const int nax = 1e5 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {-1, -1, 1, 1};
int dc[] = {-1, 1, -1, 1};
int n = 7;

bool out(int i, int j){
    return (i < 0 || i >= n || j < 0 || j >= n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t;
    cin >> t;
    while(t--){
        vector<vector<char>> mtx(n, vector<char>(n));
        forn(i, n){
            forn(j, n)cin >> mtx[i][j];
        }
        vector<vi> rm(n, vi(n));
        forn(i, n){
            forn(j, n){
                if(mtx[i][j] == 'W')continue;
                forn(k, 4){
                    int di = i + dr[k];
                    int dj = j + dc[k];
                    if(out(di, dj))continue;
                    int sm = 0;
                    forn(l, 4){
                        int ddi = di + dr[l];
                        int ddj = dj + dc[l];
                        if(out(ddi, ddj))continue;
                        sm += mtx[ddi][ddj] == 'B';
                    }
                    if(sm == 4)++rm[i][j];
                }
            }
        }
        int ans = 0;
        int mx = 0;
        do{
            mx = 0; 
            int mi = 0;
            int mj = 0;
            forn(i, n){
                forn(j, n){
                    if(mx < rm[i][j]){
                        mx = rm[i][j];
                        mi = i;
                        mj = j;
                    }
                }
            }
            if(mx == 0){
                break;
            }
            // d(mx);
            // d(mi);
            // d(mj);
            mtx[mi][mj] = 'W';
            rm[mi][mj] = 0;
            ++ans;
            forn(i, n){
                forn(j, n){
                    if(mtx[i][j] == 'W')continue;
                    rm[i][j] = 0;
                    forn(k, 4){
                        int di = i + dr[k];
                        int dj = j + dc[k];
                        if(out(di, dj))continue;
                        int sm = 0;
                        forn(l, 4){
                            int ddi = di + dr[l];
                            int ddj = dj + dc[l];
                            if(out(ddi, ddj))continue;
                            sm += mtx[ddi][ddj] == 'B';
                        }
                        if(sm == 4){
                            ++rm[i][j];
                        }
                    }
                }
            }
        }while(true);
        cout << ans << el;
    }
}
