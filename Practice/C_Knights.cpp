#include <algorithm>
#include <array>
#include <cassert>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream> // istringstream buffer(myString);
#include <stack>
#include <unordered_map>
#include <utility>
#include <vector>

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
const int nax = 305;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dc[] = {-1, 1, -2, 2, -2, 2, -1, 1};

int n;
int dp[nax][nax][2];

void bfs(int h, int sI, int sJ){
    queue<ii> q, qq;
    q.push({sI, sJ});
    dp[sI][sJ][h] = 0;
    int dist = 1;
    while(!q.empty()){
        swap(q, qq);
        while(!qq.empty()){
            ii p = qq.front();
            qq.pop();
            int x = p.first;
            int y = p.second;
            forn(k, 8){
                int dx = x + dr[k];
                int dy = y + dc[k];
                if(dx > -1 && dx < n && dy > -1 && dy < n && dp[dx][dy][h] == -1){
                    dp[dx][dy][h] = dist;
                    q.push({dx, dy});
                }
            }
        }
        dist++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    while(n){
        
        if((a + b) % 2 != (c + d) % 2){
            cout << '*' << el;
        }else{
            forn(i, n){
                forn(j, n){
                    dp[i][j][0] = -1;
                    dp[i][j][1] = -1;
                }
            }
            bfs(0, a, b);
            bfs(1, c, d);
            int ans = inf;
            forn(i, n){
                forn(j, n){
                    if(dp[i][j][0] == -1 || dp[i][j][1] == -1)continue;
                    ans = min(ans, max(dp[i][j][0], dp[i][j][1]));
                }
            }
            if(ans == inf)cout << '*' << el;
            else cout << ans << el;
        }
        cin >> n >> a >> b >> c >> d;
    }
}
