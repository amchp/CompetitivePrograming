#include<bits/stdc++.h>


using namespace std;

#define forn(i,n) for(int i = 0; i< n;++i)
#define fore(i,l, r) for(int i = l ; i<= r;++i)
#define for1(i,n) for(int i = 1; i <= n;++i)
#define all(a) a.begin(), a.end()
#define db(x) cerr<<#x<<" "<<x<<el
#define pb push_back
#define el '\n'
typedef double ld;
typedef long long ll;
typedef array<int,2> v2;
typedef array<int,27> v27;
typedef pair<int, int> ii;

const int nax = 2e6 + 100;

struct state {int len, link, contains=0;v27 next{0}; };
state st[nax];
int sz, last;
void sa_init(){
    last=st[0].len=0; sz = 1;
    st[0].link=-1;
}

void sa_extend(int c, int idx){
    assert(c < 27);
    int k=sz++,p;
    st[k].len=st[last].len+1;
    st[k].contains |= 1<<idx;
    for(p=last;p!=-1&&!st[p].next[c];p=st[p].link){
        st[p].next[c] = k;
    }
    if(p==-1){
        st[k].link=0;
    }
    else{
        int q = st[p].next[c];
        if(st[p].len+1==st[q].len){
            st[k].link=q;
        }
        else{
            int w=sz++;
            st[w].len = st[p].len+1;
            st[w].next = st[q].next; st[w].link=st[q].link;
            for(;p!=-1&&st[p].next[c]==q;p=st[p].link){
                st[p].next[c] = w;
            }
            st[q].link=st[k].link=w;
        }
    }
    last = k;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.precision(20);
    vector<string> vec;
    sa_init();
    string s;
    int n = 0;
    getline(cin, s);
    while(s != ""){
        s.pb('a'+26);
        vec.pb(s);
        ++n;
        getline(cin, s);
    }
    vec.back().pop_back();
    forn(i, n){
        string& s = vec[i];
        for(char& c : s){
            sa_extend(c-'a', i);
        }
    }
    int ans = 0;
    int all = (1 << n) - 1;
    vector<ii> ord(nax);
    forn(i, nax){
        ord[i] = {st[i].len, i};
    }
    sort(all(ord), greater<ii>());
    forn(i, nax){
        int u = ord[i].second;
        int link = st[u].link;
        if(link == -1)continue;
        st[link].contains |= st[u].contains;
    }
    forn(i, nax){
        if(st[i].contains == all)ans = max(ans, st[i].len);
    }
    cout << ans << el;
}