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
const int nax = 1e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

struct state {int len,link, cnt;map<char,int> next;}; //clear next!!

struct suffix_automata{
    vector<state> st;
    int last;
    suffix_automata(){
        st.pb(state());
        last=st[0].len=0;
        st[0].link=-1;
    }
    void extend(char c){
        int k=sz(st),p;
        st.pb(state());
        st[k].len=st[last].len+1;
        st[k].cnt = 1;
        for(p=last;p!=-1&&!st[p].next.count(c);p=st[p].link)st[p].next[c]=k;
        if(p==-1)st[k].link=0;
        else {
            int q=st[p].next[c];
            if(st[p].len+1==st[q].len)st[k].link=q;
            else {
                int w=sz(st);
                st.pb(state());
                st[w].len=st[p].len+1;
                st[w].next=st[q].next;st[w].link=st[q].link;
                for(;p!=-1&&st[p].next[c]==q;p=st[p].link)st[p].next[c]=w;
                st[q].link=st[k].link=w;
            }
        }
        last=k;
    }
    void calc_cnt(){
        vi ord(sz(st) - 1);  iota(all(ord), 1);
        sort(all(ord), [&](int i, int j){ return st[i].len > st[j].len; });
        for(int v: ord) st[st[v].link].cnt += st[v].cnt;  // Add cnt to link
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int t;
    cin >> t;
    while(t--){
        int n, l, r;
        cin >> n >> l >> r;
        suffix_automata sa = suffix_automata();
        string s;
        cin >> s;
        for(char& c : s){
            sa.extend(c);
        }
        sa.calc_cnt();
        map<int, int> ans;
        for(state& st : sa.st){
            ans[st.cnt] = max(ans[st.cnt], st.len);
        }
        fore(i, l, r)cout << ans[i] << el;
    }
}