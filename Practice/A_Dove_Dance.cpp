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

struct vertex{
    int ind;
    bool val;
    vi nxt;
    vertex(int i):ind(i), val(0), nxt(26, 0){}
};

struct trie{
    vector<vertex> t;
    int n;
    trie():n(1){
        t.pb(vertex(0));
    }
    void add(string& s){
        int cur = 0;
        for(char& c : s){
            if(t[cur].nxt[c - 'a'] == 0){
                t.pb(vertex(n));
                t[cur].nxt[c - 'a'] = n;
                cur = n;
                n++;
            }else{
                cur = t[cur].nxt[c - 'a'];
            }
            t[cur].val = true;
        }
    }
    int traverse(string& s){
        int cur = 0;
        for(char& c : s){
            if(t[cur].nxt[c - 'a'] == 0){
                return false;
            }else{
                cur = t[cur].nxt[c - 'a'];
            }
        }
        return t[cur].val;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n;
    cin >> n;
    bool sw = false;
    trie pre = trie();
    trie suf = trie();
    forn(i, n){
        int op;
        cin >> op;
        if(op == 1){
            string s;
            cin >> s;
            if(sw){
                suf.add(s);
                reverse(all(s));
                pre.add(s);
            }else{
                pre.add(s);
                reverse(all(s));
                suf.add(s);
            }
        }else if(op == 2){
            string s;
            cin >> s;
            if(sw){
                cout << suf.traverse(s) << el;
            }else{
                cout << pre.traverse(s) << el;
            }
        }else if(op == 3){
            sw = !sw;
        }
    }
}
