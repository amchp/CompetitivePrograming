#include <bits/stdc++.h>

#define fi first
#define se second
#define forn(i,n) for(int i=0; i< (int)n; ++i)
#define for1(i,n) for(int i=1; i<= (int)n; ++i)
#define fore(i,l,r) for(int i=(int)l; i<= (int)r; ++i)
#define ford(i,n) for(int i=(int)(n) - 1; i>= 0; --i)
#define fored(i,l,r) for(int i=(int)r; i>= (int)l; --i)
#define pb push_back
#define el '\n'
#define d(x) cout<< #x<< " " << x<<el
#define ri(n) scanf("%d",&n)
#define sz(v) int(v.size())
#define all(v) v.begin(),v.end()

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<ld> vd;


const int inf = 1e9;
const int nax = 110;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

int n1, n2, nv;
string s1, s2, virus;
vector<vi> mp1(26), mp2(26);
int dp[nax][nax][nax];
string fans;

struct vertex {
	map<char,int> next,go;
	int p,link;
	char pch;
    bool leaf;
	vertex(int p=-1, char pch=-1):p(p),pch(pch),link(-1), leaf(false){}
};
vector<vertex> t;
void aho_init(){ //do not forget!!
	t.clear();t.pb(vertex());
}
void add_string(string s){
	int v=0;
	for(char c:s){
		if(!t[v].next.count(c)){
			t[v].next[c]=t.size();
			t.pb(vertex(v,c));
		}
		v=t[v].next[c];
	}
    // d(v);
    t[v].leaf = true;
}
int go(int v, char c);
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

int sol(int i, int j, int k){
    int& ans = dp[i][j][k];
    if(ans != -1)return ans;
    ans = 0;
    forn(c, 26){
        auto iti = upper_bound(all(mp1[c]), i);
        auto itj = upper_bound(all(mp2[c]), j);
        int nxtk = go(k, c + 'A');
        // d(nxtk);
        if(iti == mp1[c].end() || itj == mp2[c].end() || t[nxtk].leaf)continue;
        ans = max(ans, 1 + sol(*iti, *itj, nxtk));
    }
    return ans;
}

void reconst(int i, int j, int k){
    int& ans = dp[i][j][k];
    forn(c, 26){
        auto iti = upper_bound(all(mp1[c]), i);
        auto itj = upper_bound(all(mp2[c]), j);
        int nxtk = go(k, c + 'A');
        if(iti == mp1[c].end() || itj == mp2[c].end() || t[nxtk].leaf)continue;
        if(dp[*iti][*itj][nxtk] + 1 == ans){
            fans.pb(c + 'A');
            reconst(*iti, *itj, nxtk);
            return;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    memset(dp, -1, sizeof(dp));
    cin >> s1 >> s2 >> virus;
    n1 = sz(s1);
    n2 = sz(s2);
    nv = sz(virus);
    forn(i, n1){
        int ind = s1[i] - 'A';
        mp1[ind].pb(i + 1);
    }
    forn(i, n2){
        int ind = s2[i] - 'A';
        mp2[ind].pb(i + 1);
    }
    aho_init();
    add_string(virus);
    int ans = sol(0, 0, 0);
    if(ans == 0){
        cout << 0 << el;
        return 0;
    }
    reconst(0, 0, 0);
    cout << fans << el;
}