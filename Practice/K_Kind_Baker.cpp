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


const int inf = 1e9;
const int nax = 1e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

// vi grid[100][100];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int k;
    cin >> k;
    if(k == 1){
        cout << 0 << el;
        return 0;
    }
    int lg = 32 - __builtin_clz(k - 1);
    cout << lg << el;
    vector<ii> full;
    for(int i = 2; i < 100; i += 2){
        forn(j, 100){
            full.pb({i, j});
        }
        full.pb({i + 1, 0});
    }
    
    forn(i, lg){
        vector<ii> ans;
        forn(j, k - 2){
            if((j + 1) & (1 << i)){
                ans.pb({(j / 99), (j % 99) + 1});
            }
        }
        cout << sz(full) + sz(ans) << ' ';
        for(auto& [x, y] : full){
            cout << x << ' ' << y + 1 << ' ';
            // grid[x - 1][y].pb(i);
        }
        for(auto& [x, y] : ans){
            cout << 2*x + 1 << ' ' << y + 1 << ' ';
            // grid[2*x][y].pb(i);
        }
        cout << el;
    }
    // set<vi> st;
    // forn(i, 100){
    //     forn(j, 100){
    //         st.insert(grid[i][j]);
    //     }
    // }
    // cout << sz(st) << el;
    // for(vi vec : st){
    //     for(int& v : vec)cout << v << ' ';
    //     cout << el;
    // }
}