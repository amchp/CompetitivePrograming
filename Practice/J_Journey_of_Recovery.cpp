#include <bits/stdc++.h>

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
const int nax = 2e6 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

struct edge{
    int u, v, st, ext;
    int flight;
    edge(){}
    edge(int u, int v, int st, int ext): u(u), v(v), st(st), ext(ext), flight(inf){}
    bool operator<(edge o){
        if(st == o.st){
            return flight < o.flight;
        }
        return st < o.st;
    }
};


int date_string_to_int(string& s){
    int e = 0;
    int ans = 0;
    while(s[e] != 'd')++e;
    int day = stoi(s.substr(0, e));
    ++e;
    int st = e;
    while(s[e] != ':')++e;
    int h = stoi(s.substr(st, e - st));
    ++e;
    int m = stoi(s.substr(e));
    return day*24*60 + day*60 + m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n;
    cin >> n;
    int ind = 0;
    unordered_map<string, int> aprt;
    vector<edge> edges(n);
    forn(i, n){
        string s;
        cin >> s;
        if(!aprt.count(s)){
            aprt[s] = ind;
            ++ind;
        }
        int u = aprt[s];
        cin >> s;
        int st = date_string_to_int(s);
        cin >> s;
        if(!aprt.count(s)){
            aprt[s] = ind;
            ++ind;
        }
        int v = aprt[s];
        cin >> s;
        int ext = date_string_to_int(s);
        edges[i] = edge(u, v, st, ext);
    }
    int m;
    cin >> m;
    int f;
    forn(i, m){
        cin >> f;
        --f;
        edges[f].flight = i;
    }
    int end = edges[f].v;
    sort(all(edges));
    vector<vector<ii>> dp(ind);
    int ans = inf;
    ford(i, n){
        edge e = edges[i];
        if(e.flight != inf){

        }
        if(e.v == end){
            dp[e.u].pb({e.st, e.ext});
        }
        else if(!dp[e.v].empty()){
            int j = lower_bound(all(dp[e.v]), e.ext) - dp[e.v].begin();
            if(j == sz(dp[e.v]))continue;
            while(dp[e.u].empty() && dp[e.u].back().fi > e.st)dp[e.u].pop_back();
            dp[e.u].pb({e.st, e.ext});
        }
    }
}
