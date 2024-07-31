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
typedef array<int, 3> a3;


const int inf = 1e9;
const int nax = 3e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

struct mint{
    int x;
    mint(): x(0){}
    mint(int x): x(min(x, 2)){}
    mint operator+(mint b){
        int ans = x + b.x;
        return min(ans, 2);
    }
};

int n;
int a[nax];
ii dp[nax][3][2];
bool vis[nax][3][2];

ii sol(int ind, int prt, int& lft){
    // d(ind);
    // d(prt);
    // d(lft);
    if(prt >= 3)return {-1, -1};
    if(ind == n - 1){
        if(prt >= 1)return {prt == 1, prt == 2};
        else return {-1, -1};
    }
    ii& ans = dp[ind][prt][lft];
    if(vis[ind][prt][lft])return ans;
    vis[ind][prt][lft] = true;
    ans = {-1, -1};
    int& cur = a[ind];
    int& nxt = a[ind + 1];
    int dif = nxt - cur;
    if(dif <= 1000){
        ans = sol(ind + 1, prt + 1, lft);
    }
    else if(dif >= 2000){
        if(prt > 0){
            ans = sol(ind + 1, 0, lft);
            if(ans.fi != -1){
                if(prt == 1)++ans.fi;
                else ++ans.se;
            }
        }
    }
    else{
        if(lft){
            ans = sol(ind + 1, prt + 1, lft);
            if(ans.fi == -1 && prt > 0){
                ans = sol(ind + 1, 0, lft);
                if(ans.fi != -1){
                    if(prt == 1)++ans.fi;
                    else ++ans.se;
                }
            }
        }else{
            if(prt > 0){
                ans = sol(ind + 1, 0, lft);
                if(ans.fi != -1){
                    if(prt == 1)++ans.fi;
                    else ++ans.se;
                }
            }
            if(ans.fi == -1)ans = sol(ind + 1, prt + 1, lft);
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    memset(vis, false, sizeof(vis));
    cin >> n;
    forn(i, n)cin >> a[i];
    int lft = 0;
    ii ansl = sol(0, 0, lft);
    // d(ansl.fi);
    // d(ansl.se);
    if(ansl.fi == -1){
        cout << "Impossible" << el;
        return 0;
    }
    lft = 1;
    ii ansr = sol(0, 0, lft);
    // d(ansr.fi);
    // d(ansr.se);
    if(ansl.fi != ansr.fi || ansl.se != ansr.se){
        cout << "Ambiguous" << el;
        return 0;
    }
    cout << "Cars without trailers: " << ansl.fi << el;
    cout << "Cars with trailers: " << ansl.se << el;
}