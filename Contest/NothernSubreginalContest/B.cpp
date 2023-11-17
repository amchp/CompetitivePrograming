
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string.h>
#include <string>
#include <math.h>
#include <queue>
#include <set>
#include <functional>
// #pragma GCC optimize("O3")(uncomment when not having a lot of recursions)
// #pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "=============================" << endl

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
#define count1s(v) __builtin_popcount(v)
#define count1sll(v) __builtin_popcountll(v)
#define countL0s(v) __builtin_clz(v)
#define countL0sll(v) __builtin_clzll(v)


using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<pair<ll, ll>, ll> iii;

typedef pair<char, int> pci;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<char> vc;

const int inf = 2e9;
const int MAXS = 1e5 + 2;
const int MAXT = 1e2 + 2;

int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, 1, -1, 1, 1, -1, -1};
const int nax = 2e5+1;
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<string> vs(n);
    vi votes(n);
    forn(i,n)cin>>vs[i];
    int invalid = 0;
    forn(i,m){
        string s;
        cin>>s;
        int k = s.size(), ind = -1;
        bool sepuede = 1;
        forn(j,k){
            if(s[j] == 'X'){
                if(ind != -1){
                    sepuede = 0;
                    break;
                }
                ind = j;
            }
        }
        if(ind == -1)sepuede = 0;
        if(sepuede){
            votes[ind]++;
        }else{
            invalid++;
        }
    }
    vector<pair<ld,int>> v(n);
    forn(i,n){

        ld perc = 1.0L*votes[i] / m;
        perc = 10000.0L * perc;
        perc = round(perc);
        perc/=100.0L;
        // d(perc);
        v[i] = {perc,i};
    }
    sort(all(v),[&](pair<ld,int> &a, pair<ld,int> &b)->bool{
        if(a.fi == b.fi)return a.se<b.se;
        else return a.fi>b.fi;
    });
    forn(i,n){
        cout<<vs[v[i].se]<<" ";
        // cout<<v[i].fi;
        printf("%.2f",v[i].fi);
        cout<<"%\n";
    }
    cout<<"Invalid ";
    ld perc = 1.0L * invalid/m;
    perc= perc * 10000.0L;
    perc = round(perc);
    perc/=100.0L;
    printf("%.2f",perc);
    // cout<<perc;
        cout<<"%\n";

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // cout.precision(9);
    // freopen("bad.in", "r", stdin);
    // freopen("bad.out", "w", stdout);
    int tt;
    tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
    return 0;
}
//run g++ --std=c++17 A.cpp -o A