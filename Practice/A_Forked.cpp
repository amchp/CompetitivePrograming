#include <bits/stdc++.h>

#define forn(i,n) for(int i=0; i<n; ++i)
#define for1(i,n) for(int i=1; i<=n; ++i)
#define fore(i,l,r) for(int i=l; i<=r; ++i)
#define sz(v) int(v.size())
#define el endl
#define fi first
#define se second
#define pb push_back
#define all(v) v.begin(),v.end()
#define d(x) cout << #x << " = " << x << el;

using namespace std;

typedef long long ll;
typedef double ld;
typedef vector<ll> vll;
typedef pair<ll,ll> ii;

int a,b,x1,y1;
vector<int> vx={-1,-1,1,1};
vector<int> vy={-1,1-1,1};
int bfs(int x,int y,int k){
    int cont=0;
    if(k){
        forn(i,4){
            if((x+vx[i]*b==x1) && (y+vy[i]*a==y1))cont++;
            if((x+vx[i]*a==x1) && (y+vy[i]*b==y1))cont++;
        }
        return cont;
    }
    forn(i,4){
        cout<<x+vx[i]*a<<" "<<y+vy[i]*b<<endl;
        cont+=bfs(x+vx[i]*a, y+vy[i]*b, k+1);
        cont+=bfs(x+vx[i]*b, y+vy[i]*a, k+1);
    }
    return cont;
}

int main(){
    int t,x,y,cont;
    cin>>t;
    while(t--){
        cin>>a>>b>>x>>y>>x1>>y1;
        cont=bfs(x,y,0);
        if(a==b)cout<<cont/2<<endl;
        else cout<<cont<<endl;
    }
}