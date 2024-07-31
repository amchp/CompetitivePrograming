#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < (int)n; ++i)
#define for1(i, n) for(int i = 1; i <= (int)n; ++i)
#define fore(i, l, r) for(int i = (int)l; i <= (int)r; ++i)
#define ford(i, n) for(int i = (int)n-1; i >= 0; --i)
#define el '\n'
#define sz(x) x.size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int nax = 501;
const ll inf = 1e18;
int n;

int g[nax][nax];
ll d[nax][nax];
vi s;


void dikstra(int st){
    for(int v : s){
        d[st][v] = inf;
    }
    priority_queue<ii, vector<ii>, greater<ii>> q;
    d[st][st] = 0;
    q.push(ii{0, st});
    ll dist;
    int u, v, w;
    while(sz(q)){
        tie(dist, u) = q.top();
        q.pop();
        if(dist > d[st][u])continue;
        for(int v : s){
            w = g[u][v];
            if(d[st][u] + w < d[st][v]){
                d[st][v] = d[st][u] + w;
                q.push(ii{d[st][v], v});
            }
        }
    }
}

ll dI[nax];

void dikstra2(int st){
    for(int v : s){
        dI[v] = inf;
    }
    priority_queue<ii, vector<ii>, greater<ii>> q;
    dI[st] = 0;
    q.push(ii{0, st});
    ll dist;
    int u, v, w;
    while(sz(q)){
        tie(dist, u) = q.top();
        q.pop();
        if(dist > dI[u])continue;
        for(int v : s){
            w = g[v][u];
            if(dI[u] + w < dI[v]){
                dI[v] = dI[u] + w;
                q.push(ii{dI[v], v});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        forn(i, n){
            forn(j, n){
                cin >> g[i][j];
                d[i][j] = inf;
            }
        }
        s.clear();
        vi order(n);
        forn(i, n){
            cin >> order[i];
        }
        ll tAns = 0;
        ford(i, n){
            int st = order[i];
            s.pb(st);
            dikstra(st);
            dikstra2(st);
            for(int v : s){
                d[v][st] = dI[v];
            }
            ll ans = 0;
            for(int &u : s){
                for(int &v : s){
                    d[u][v] = min(d[u][v], d[u][st] + d[st][v]);
                }
            }
            for(int &u : s){
                for(int &v : s){
                    ans += d[u][v];
                }
            }
            tAns += ans;
        }
        cout << tAns << el;
    }
}