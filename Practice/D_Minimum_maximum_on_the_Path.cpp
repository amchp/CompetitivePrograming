#include <vector>
#include <map>
#include <cstdlib>
#include <fstream>
#include <iomanip>   
#include <iostream>  
#include <sstream>  // istringstream buffer(myString);
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <math.h>
#include <unordered_map>
#include <queue>
#include <array>
#include <set>
#include <numeric>

using namespace std;


typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi; // int vec
typedef vector<ll> vll; // int vec
typedef vector<vi> vvi; // int vec vec
typedef vector<vll> vvll; // int vec
typedef vector<pii> vpi; // int int pair vec
typedef vector<pll> vpll; // int int pair vec

const double pi = 3.1415926535897932384626433832795;
const int maxn = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ll INFLL = 1000000000000000005LL;
const ld EPS = 1e-9;
int dirx[8] = { -1, 0, 0, 1, -1, -1, 1, 1 };
int diry[8] = { 0, 1, -1, 0, -1, 1, -1, 1 };

#define d(x) cout << #x << " = " << x << endl;
#define ios ios_base::sync_with_stdio(0), cin.tie(0);
#define forn(i, n) for (int i=0; i< (int)n; ++i) 
#define forab(i, a, b) for (int i=a; i< (int)b; ++i) 
#define foreach(a, b) for (auto&(a) : (b))
#define formap(map) for (const auto &[key, value] : map)
#define all(v) v.begin(), v.end()
#define allar(arr, sz) arr, arr + sz
#define ms(ar, val) memset(ar, val, size)
#define pq(type) priority_queue<type> 
#define pqd(type) priority_queue<type,vector<type>,greater<type> >
#define umap unordered_map
#define uset unordered_set
#define imax INT_MAX
#define imin INT_MIN
#define pb push_back
#define mp make_pair
#define fi first 
#define se second 
#define nl "\n"
#define in(t) while (t--)

int n, m;
vpi g[maxn];
int visited[maxn];

bool bfs(int m){
    queue<pii> q;
    queue<pii> qq;
    q.push(make_pair(0, 0));
    while(!q.empty()){
        swap(q, qq);
        while(!qq.empty()){
            pii p = qq.front();
            qq.pop();
            if(p.first == n - 1){
                return true;
            }
            forn(i, g[p.first].size()){
                pii p2 = g[p.first][i];
                if(visited[p2.first] != -1)continue;
                if(p2.second > m)continue;
                visited[p2.first] = p.first;
                q.push(make_pair(p2.first, max(p.first, p2.second)));
            }
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    cin >> n >> m;
    int a, b, c;
    forn(i, m){
        cin >> a >> b >> c;
        a--;
        b--;
        g[a].pb(make_pair(b, c));
    }
    int l = -1, r = 1e9 + 1, m;
    while(l + 1 < r){
        m = l + (r - l) / 2;
        memset(visited, -1, sizeof(visited));
        if(bfs(m)){
            r = m;
        }else{
            l = m;
        }
    }
    if(r == 1e9 + 1){
        cout << -1 << nl;
        return 0;
    }
    memset(visited, -1, sizeof(visited));
    bfs(r);
    vi ans;
    int cur = n - 1;
    while(visited[cur] != -1){
        ans.pb(cur);
        cur = visited[cur];
    }
    ans.pb(cur);
    reverse(all(ans));
    cout << ans.size() - 1 << nl;
    forn(i, ans.size()){
        cout << ans[i] + 1 << ' ';
    }
}