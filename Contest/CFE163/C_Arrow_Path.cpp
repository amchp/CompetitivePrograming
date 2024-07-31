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
const int nax = 2e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

map<char, int> mvs = {{'<', 3}, {'>', 2}};

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

bool dp[2][nax];
int n;
string grd[2];

bool in(int i, int j){
    return i >= 0 && i < 2 && j >=0 && j < n;
}

void sol(int i, int j){
    forn(k, 4){
        int di = i + dr[k];
        int dj = j + dc[k];
        if(in(di, dj)){
            int ddi = di + dr[mvs[grd[di][dj]]];
            int ddj = dj + dc[mvs[grd[di][dj]]];
            if(!dp[ddi][ddj]){
                dp[ddi][ddj] = true;
                sol(ddi, ddj);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        forn(i, 2)cin >> grd[i];
        forn(i, 2){
            forn(j, n)dp[i][j] = false;
        }
        dp[0][0] = true;
        sol(0, 0);
        if(dp[1][n - 1])cout << "YES" << el;
        else cout << "NO" << el;
    }
}