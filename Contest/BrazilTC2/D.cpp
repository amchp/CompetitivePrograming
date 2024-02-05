#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < n; ++i)
#define for1(i, n) for(int i = 1; i <= (int)n; ++i)
#define fore(i, l, r) for(int i = (int)l; i <= (int)r; ++i)
#define all(x) x.begin(), x.end()
#define el '\n'
#define sz(x) x.size()
#define fi first
#define se second
#define pb push_back
#define d(x) cerr << #x << ' ' << x << el;

using namespace std;

typedef __int128_t i128;
typedef vector<int> vi;
typedef vector<i128> vi128;
typedef pair<int, int> ii;
typedef long double ld;

const static int N = 2e6, alpha = 26;
int to[N][alpha], szs;
vector<bool> cnt(N);
inline int conv(char ch){ return ch - 'a'; }
void init(){
    forn(i, szs + 1)cnt[i] = 0, memset(to[i], 0, sizeof(to[i]));
    szs = 0;
}

void add(const string& s){
    int u = 0;
    for(char ch: s){
        int c = conv(ch);
        if(!to[u][c])to[u][c] = ++szs;
        u = to[u][c];
    }
    cnt[u] = true;
}

string ans;
string cur;
string inputs;

void dfs(int msk, int tnd){
    // d(msk);
    // d(tnd);
    // d(cur);
    forn(i, sz(inputs)){
        int ch = conv(inputs[i]);
        if(!(msk & (1 << i)) && to[tnd][ch]){
            cur.pb(inputs[i]);
            dfs(msk | (1 << i), to[tnd][ch]);
            cur.pop_back();
        }
    }
    if(cnt[tnd]){
        if(sz(ans) == sz(cur)){
            ans = min(ans, cur);
        }
        else if(sz(ans) < sz(cur)){
            ans = cur;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    string s;
    init();
    forn(i, n){
        cin >> s;
        add(s);
    }
    int q;
    cin >> q;
    // cout << "HI" << el;
    forn(i, q){
        cin >> inputs;
        ans = "";
        sort(all(inputs));
        dfs(0, 0);
        if(ans == "")cout << "IMPOSSIBLE" << el;
        else cout << ans << el;
    }
    return 0;
}