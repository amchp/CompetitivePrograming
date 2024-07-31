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
#define d(x) cerr<< #x<< " " << x<<el
#define ri(n) scanf("%d",&n)
#define SZ(v) int(v.size())
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
const int nax = 1e6+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

struct state {int len,link;map<char,int> next;}; //clear next!!
state st[nax];
int sz,last;
void sa_init(){
	last=st[0].len=0;sz=1;
	st[0].link=-1;
}
void sa_extend(char c){
	int k=sz++,p;
	st[k].len=st[last].len+1;
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

int n, m;
int mtch[nax];

bool sol(int mid){
    vector<int> itvl(n + 1);
    forn(i, n){
        if(mtch[i] >= mid){
            if(i + mid >= n){
                ++itvl[(i + mid) % n];
                --itvl[i + 1];
            }else{
                ++itvl[0];
                --itvl[i + 1];
                ++itvl[i + mid];
                --itvl[n];
            }
        }
    }
    int pre = 0;
    forn(i, n){
        int& v = itvl[i];
        pre += v;
        if(pre == 0)return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    cin >> n >> m;
    string s;
    cin >> s;
    s += s;
    string ptrns = "";
    forn(i, m){
        string s2;
        cin >> s2;
        ptrns += s2;
        ptrns += '#';
    }
    sa_init();
    for(char& c : ptrns){
        sa_extend(c);
    }
    int lft = 0;
    int rgt = 0;
    int cur = 0;
    int szs = 0;
    vi nd(n);
    while(lft < n){
        while(rgt < 2*n && st[cur].next.count(s[rgt])){
            cur = st[cur].next[s[rgt]];
            ++rgt;
            ++szs;
        }
        nd[lft] = cur;
        mtch[lft] = szs;
        ++lft;
        if(rgt < lft)++rgt;
        szs = max(szs - 1, 0);
        while(cur != 0 && szs <= st[st[cur].link].len){
            cur = st[cur].link;
        }
    }
    // forn(i, n){
    //     int cur = 0;
    //     int szs = 0;
    //     int j = i;
    //     while(j < 2*n && st[cur].next.count(s[j])){
    //         cur = st[cur].next[s[j]];
    //         ++szs;
    //         ++j;
    //     }
    //     // d(i);
    //     // d(cur);
    //     // d(nd[i]);
    //     assert(nd[i] == cur);
    //     // assert(szs == mtch[i]);
    // }
    int l = 0, r = n + 1;
    while(l + 1 < r){
        int mid = l + (r - l) / 2;
        if(sol(mid)){
            r = mid;
        }else{
            l = mid;
        }
    }
    cout << l << el;
}