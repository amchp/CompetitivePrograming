#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < n; ++i)
#define ford(i, n) for(int i = (int)n - 1; i >= 0; --i)
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
#define el '\n'
#define d(x) cerr<<#x<<" "<<x<<el

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
int dx[] = {1,1, -1, -1};
int dy[] = {1,-1, 1, -1};
vector<vector<vi>> vis;

int pos[2][2] = {{0,0}, {1,1}};
const int nax = 1000;
int visited[nax][nax];

int n;
bool inbounds(int i, int j){
    return i>=0 && j>=0 && i<n && j<n;
}
void dfs(int i, int j, bool type){
    vis[i][j][type] = 1;
    visited[i][j] = 1;
    int a = pos[type][0], b = pos[type][1];

    forn(_,2){
        forn(k,4){
            int dxx = i + dx[k]*a, dyy = j + dy[k] * b;
            if(!inbounds(dxx,dyy) || vis[dxx][dyy][!type])continue;
            dfs(dxx,dyy, !type);
        }
        swap(a,b);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    memset(visited, 0, sizeof visited);
     cin>>n;
     int a,b,c,d;
     cin>>a>>b>>c>>d;
     pos[0][0] = a, pos[0][1] = b;
     pos[1][0] = c, pos[1][1] = d;

     vis = vector<vector<vi>>(n, vector<vi>(n, vi(2)));
     dfs(0,0,0);
     dfs(0,0,1);
     int ans = 0;
     forn(i,n){
        forn(j,n){
            ans += visited[i][j];
        }
     }
     cout<<ans<<el;
}