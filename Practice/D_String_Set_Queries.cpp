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
const int nax = 1e5 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

struct vertex {
	map<char,int> next,go;
	int p,link;
	char pch;
    int val;
    int dp;
	vertex(int p=-1, char pch=-1):p(p),pch(pch),link(-1),val(0), dp(-1){}
};

struct aho{
    vector<vertex> t;
    vector<string> strs;
    aho(){ //do not forget!!
        t.pb(vertex());
    }
    void add_string(const string& s){
        strs.pb(s);
        int v=0;
        for(char c:s){
            if(!t[v].next.count(c)){
                t[v].next[c]=t.size();
                t.pb(vertex(v,c));
            }
            v=t[v].next[c];
        }
        t[v].val++;
    }

    int go_(int v, char c){return go(v, c);}
    int get_link(int v){
        if(t[v].link<0){
            if(!v||!t[v].p){
                t[v].link=0;
            }
            else{
                t[v].link=go_(get_link(t[v].p),t[v].pch);
            }
        }
        return t[v].link;
    }
    int go(int v, char c){
        if(!t[v].go.count(c)){
            if(t[v].next.count(c)){
                t[v].go[c]=t[v].next[c];
            }
            else{
                t[v].go[c]=v==0?0:go(get_link(v),c);
            }
        }
        return t[v].go[c];
    }

    int sol(int v){
        int& w = t[v].dp;
        if(w != -1)return w;
        return w = t[v].val + sol(get_link(v));
    }

    void dp_init(){
        t[0].dp = 0;
        forn(i, t.size()){
            sol(i);
        }
    }

    void clear(){
        t.clear();
        strs.clear();
        t.pb(vertex());
    }
};

struct aho_update
{
    vector<aho> v;
    aho_update(){
        v = vector<aho>();
    }

    void add_string(const string& a){
        int last = 0;
        while(last < v.size() && v[last].strs.size() != 0)last++;
        if(last == v.size())v.pb(aho());
        v[last].add_string(a);
        forn(i, last){
            for(string s : v[i].strs){
                v[last].add_string(s);
            }
            v[i].clear();
        }
        v[last].dp_init();
    }

    int query(const string& s){
        int ans = 0;
        for(aho& a : v){
            if(a.strs.size() == 0)continue;
            int w = 0;
            for(char c : s){
                ans += a.t[w].dp;
                w = a.go(w, c);
            }
            ans += a.t[w].dp;
        }
        return ans;
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int m;
    cin >> m;
    aho_update add;
    aho_update sub;
    forn(i, m){
        int t;
        string s;
        cin >> t >> s;
        if(t == 1){
            add.add_string(s);
        }else if(t == 2){
            sub.add_string(s);
        }else if(t == 3){
            int ans = add.query(s) - sub.query(s);
            cout << ans << el;
            cout.flush();
        }
    }
}