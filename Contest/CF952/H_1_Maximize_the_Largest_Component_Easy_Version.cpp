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
typedef vector<char> vc;


const int inf = 1e9;
const int nax = 1e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0};
int dc[] = {0, 0,1,-1};


struct comp{
    int i, j;
    int val;
    map<int, int> rw, col;
    comp(int i, int j): i(i), j(j){}
};

int n, m;
vector<vi> brd;
vector<vector<bool>> vis;
vector<comp> cmp;

bool inside(int i, int j){
    return 0 <= i && i < n && 0 <= j && j < m && brd[i][j] == 1 && !vis[i][j];
}

int dfs(int i, int j, comp& ccmp){
    ++ccmp.rw[i];
    ++ccmp.col[j];
    vis[i][j] = true;
    int ans = 1;
    forn(k, 4){
        int di = i + dr[k];
        int dj = j + dc[k];
        if(!inside(di, dj))continue;
        ans += dfs(di, dj, ccmp);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        brd = vector<vi>(n, vi(m));
        vis = vector<vector<bool>>(n, vector<bool>(m, false));
        vi rws = vi(n);
        vi cols = vi(m);
        vi rcm = vi(n);
        vi ccm = vi(m);
        int ans = 0;
        forn(i, n){
            forn(j, m){
                char c;
                cin >> c;
                brd[i][j] = c == '#';
            }
        }
        if(n == 1 || m == 1){
            cout << n*m << el;
            continue;
        }
        forn(i, n){
            forn(j, m){
                if(inside(i, j)){
                    cmp.pb(comp(i, j));
                    cmp.back().val = dfs(i, j, cmp.back());
                    ans = max(ans, cmp.back().val);
                }
            }
        }
        forn(i, n){
            forn(j, m)vis[i][j] = false;
        }
        for(auto& ccmp : cmp){
            int i = 0;
            for(auto& [rc, cval] : ccmp.rw){
                int sm = i != 0 && i != sz(ccmp.rw) - 1 ? ccmp.val : 0;
                rws[rc] += ccmp.val;
                rcm[rc] += sm;
                rcm[rc] += sz(ccmp.rw) != 1 ? cval : 0;
                ++i;
            }
            i = 0;
            for(auto& [ccl, cval] : ccmp.col){
                int sm = i != 0 && i != sz(ccmp.col) - 1 ? ccmp.val : 0;
                cols[ccl] += ccmp.val;
                ccm[ccl] += sm;
                ccm[ccl] += sz(ccmp.col) != 1 ? cval : 0;
                ++i;
            }
        }
        
        ans = max(ans, m + rws[1] - rcm[0]);
        // db(0);
        // db(rws[1]);
        // db(rcm[0]);
        // db(m + rws[1] - rcm[0]);
        for1(i, n - 2){
            ans = max(ans, m + rws[i - 1] + rws[i + 1] - rcm[i]);
            // db(i);
            // db(m + rws[i - 1] + rws[i + 1] - rcm[i]);
            // db(rws[i - 1]);
            // db(rws[i + 1]);
            // db(rcm[i]);
        }
        // db(n - 1);
        // db(rws[n - 2] - rcm[n - 1]);
        ans = max(ans, m + rws[n - 2] - rcm[n - 1]);

        ans = max(ans, n + cols[1] - ccm[0]);
        for1(j, m - 2){
            ans = max(ans, n + cols[j - 1] + cols[j + 1] - ccm[j]);
            // db(j);
            // db(n + cols[j - 1] + cols[j + 1] - ccm[j]);
            // db(cols[j - 1]);
            // db(cols[j + 1]);
            // db(ccm[j]);
        }
        ans = max(ans, n + cols[n - 2] - ccm[n - 1]);
        cout << ans << el;
    }
}