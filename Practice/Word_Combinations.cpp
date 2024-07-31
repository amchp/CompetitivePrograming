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
const int nax = 2e4 + 200;
const int mod = 1e9 + 7;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

struct mint{
    int x;
    mint(){}
    mint(ll x): x(x % mod){}
    mint operator+(mint b){
        int ans = x + b.x;
        if(ans >= mod)ans -= mod;
        return ans;
    }
};

struct state {int len,link;map<char,int> next; vi idxs;}; //clear next!!
state st[nax];
int SZ,last;
void sa_init(){
	last=st[0].len=0;SZ=1;
	st[0].link=-1;
}
void sa_extend(char c, int idx){
	int k=SZ++,p;
	st[k].len=st[last].len+1;
    st[k].idxs.pb(idx);
	for(p=last;p!=-1&&!st[p].next.count(c);p=st[p].link)st[p].next[c]=k;
	if(p==-1){
        st[k].link=0;
    }
	else {
		int q=st[p].next[c];
		if(st[p].len+1==st[q].len){
            st[k].link=q;
        }
		else {
			int w=SZ++;
			st[w].len=st[p].len+1;
			st[w].next=st[q].next;st[w].link=st[q].link;
			for(;p!=-1&&st[p].next[c]==q;p=st[p].link){
                st[p].next[c]=w;
            }
			st[q].link=st[k].link=w;
		}
	}
	last=k;
}

vi trns[nax];
mint dp[nax];
bool vis[nax];

void bfs(){
    queue<int> q;
    q.push(0);
    vector<bool> vis(SZ);
    vi ts;
    while(!q.empty()){
        int u = q.front();
        ts.push_back(u);
        q.pop();
        for(auto& [c, nxt] : st[u].next){
            if(vis[nxt])continue;
            vis[nxt] = true;
            q.push(nxt);
        }
    }
    reverse(all(ts));
    for(int& u : ts){
        vi& idxs = st[u].idxs;
        sort(all(idxs));
        idxs.erase(unique(all(idxs)), idxs.end());
        int link = st[u].link;
        if(link == -1)continue;
        vi& lidxs = st[link].idxs;
        lidxs.insert(lidxs.end(), all(idxs));
    }
}

mint sol(int ind){
    // d(ind);
    if(ind == -1)return 1;
    mint& ans = dp[ind];
    if(ans.x != -1)return ans;
    ans.x = 0;
    for(int& jmp : trns[ind]){
        ans = ans + sol(ind - jmp);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    string s;
    cin >> s;
    sa_init();
    forn(i, sz(s)){
        char& c = s[i];
        sa_extend(c, i);
    }
    bfs();
    int n;
    cin >> n;
    forn(i, n){
        string ptrn;
        cin >> ptrn;
        int cur = 0;
        for(char& c : ptrn){
            if(!st[cur].next.count(c)){
                cur = -1;
                break;
            }
            cur = st[cur].next[c];
        }
        if(cur == -1)continue;
        // d(ptrn);
        for(int& ind : st[cur].idxs){
            // cout << ind << ' ';
            trns[ind].pb(sz(ptrn));
        }
        // cout << el;
    }
    forn(i, sz(s))dp[i] = -1;
    int ans = sol(sz(s) - 1).x;
    cout << ans << el;
}