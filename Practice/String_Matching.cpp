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
const int nax = 4e6+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

struct state {int len,link, cnt = 0;map<char,int> next; bool vis = false; }; //clear next!!
state st[nax];
int sz,last;
void sa_init(){
	last=st[0].len=0;sz=1;
	st[0].link=-1;
    st[0].cnt = 0;
}
void sa_extend(char c){
	int k=sz++,p;
	st[k].len=st[last].len+1;
    st[k].cnt = 1;
	for(p=last;p!=-1&&!st[p].next.count(c);p=st[p].link)st[p].next[c]=k;
	if(p==-1)st[k].link=0;
	else {
		int q=st[p].next[c];
		if(st[p].len+1==st[q].len)st[k].link=q;
		else {
			int w=sz++;
			st[w].len=st[p].len+1;
			st[w].next=st[q].next;st[w].link=st[q].link;
			for(;p!=-1&&st[p].next[c]==q;p=st[p].link)st[p].next[c]=w;
			st[q].link=st[k].link=w;
		}
	}
	last=k;
}

int sol(){
    string ptrn;
    cin >> ptrn;
    int cur = 0;
    for(char& c : ptrn){
        if(!st[cur].next.count(c))return 0;
        cur = st[cur].next[c];
    }
    return st[cur].cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    string s;
    cin >> s;
    sa_init();
    for(char& c : s){
        sa_extend(c);
    }
    vi ts;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        ts.push_back(u);
        for(auto& [c, nxt] : st[u].next){
            if(!st[nxt].vis){
                st[nxt].vis = true;
                q.push(nxt);
            }
        }
    }
    reverse(all(ts));
    for(int& u : ts){
        // cout << u << ' ' << el;
        if(st[u].link != -1){
            st[st[u].link].cnt += st[u].cnt;
        }
    }
    int n;
    n = 1;
    forn(i, n){
        cout << sol() << el;
    }
}