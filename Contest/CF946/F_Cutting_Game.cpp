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
#define d(x) cout<< #x<< " " << x<<el
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


const int inf = 1e9;
const int nax = 1e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

vector<ii> px, py;
vector<bool> vis;

int calc_scr(int st, int ed, int dir){
    vector<ii>::iterator it;
    if(dir == 0){
        it = lower_bound(all(px), ii{st, -1});
    }else{
        it = lower_bound(all(py), ii{st, -1});
    }
    int scr = 0;
    while(it != px.end() && it != py.end() && (*it).fi <= ed){
        // d((*it).se);
        scr += !vis[(*it).se];
        vis[(*it).se] = true;
        ++it;
    }
    return scr;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int t;
    cin >> t;
    while(t--){
        int edx, edy, n, m;
        cin >> edx >> edy >> n >> m;
        px.clear();
        py.clear();
        vis.clear();
        forn(i, n){
            px.pb(ii{0, 0});
            py.pb(ii{0, 0});
            vis.pb(false);
            cin >> px[i].fi >> py[i].fi;
            px[i].se = i;
            py[i].se = i;
        }
        sort(all(px));
        sort(all(py));
        int stx = 1, sty = 1;
        int a = 0, b = 0;
        forn(i, m){
            char mv; int k;
            cin >> mv >> k;
            int scr = 0;
            if(mv == 'U'){
                int st = stx;
                int ed = stx + k - 1;
                scr = calc_scr(st, ed, 0);
                stx = stx + k;
            }
            if(mv == 'D'){
                int st = edx - k + 1;
                int ed = edx;
                scr = calc_scr(st, ed, 0);
                edx = edx - k;
            }
            if(mv == 'L'){
                int st = sty;
                int ed = sty + k - 1;
                scr = calc_scr(st, ed, 1);
                sty = sty + k;
            }
            if(mv == 'R'){
                int st = edy - k + 1;
                int ed = edy;
                scr = calc_scr(st, ed, 1);
                edy = edy - k;
            }
            if(i&1)b += scr;
            else a += scr;
        }
        cout << a << ' ' << b << el;
    }
}