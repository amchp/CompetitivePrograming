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
const int nax = 1e5 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

struct vertex {
	unordered_map<char,int> next,go;
	int p,link;
	char pch;
	int leaf;
    int dp;
	vertex(int p=-1, char pch=-1):p(p),pch(pch),link(-1),leaf(0),dp(-1){}
};
struct aho_corasick{
    vector<vertex> t;
    aho_corasick(){ //do not forget!!
        t.pb(vertex());
    }
    void add_string(const string& s){
        int v=0;
        for(char c:s){
            if(!t[v].next.count(c)){
                t[v].next[c]=t.size();
                t.pb(vertex(v,c));
            }
            v=t[v].next[c];
        }
        t[v].leaf++;
    }
    int get_link(int v){
        if(t[v].link<0)
            if(!v||!t[v].p)t[v].link=0;
            else t[v].link=go(get_link(t[v].p),t[v].pch);
        return t[v].link;
    }
    int go(int v, char c){
        if(!t[v].go.count(c))
            if(t[v].next.count(c))t[v].go[c]=t[v].next[c];
            else t[v].go[c]=v==0?0:go(get_link(v),c);
        return t[v].go[c];
    }
    int dfs(int v){
        if(t[v].dp != -1)return t[v].dp;
        return t[v].dp = t[v].leaf + dfs(get_link(v));
    }
    void build(){
        t[0].dp = 0;
        forn(v, sz(t)){
            dfs(v);
        }
    }
    ll match(const string& s){
        ll ans = 0;
        int cur = 0;
        for(char c : s){
            cur = go(cur, c);
            ans += t[cur].dp;
        }
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n, m;
    cin >> n >> m;
    aho_corasick aho = aho_corasick();
    forn(i, n){
        string s;
        cin >> s;
        aho.add_string(s);
    }
    aho.build();
    string song;
    cin >> song;
    ll ans = aho.match(song);
    cout << ans << el;
    forn(i, m){
        int ind;
        char c;
        cin >> ind;
        cin >> c;
        ind--;
        int st = max(ind - 105, 0);
        int e = min(210, sz(song) - st);
        string substr = song.substr(st, e);
        ans -= aho.match(substr);
        song[ind] = c;
        substr = song.substr(st, e);
        ans += aho.match(substr);
        cout << ans << el;
    }
}
