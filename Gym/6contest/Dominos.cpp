#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <array>
 
using namespace std;
 
#define MAXN 100000
#define D(x) cout << #x << " " << x << endl
 
vector<int> st;
vector<bool> visited(MAXN, false);
vector<int> knockOver(MAXN, 0);
vector<int> scc(MAXN, -1);
 
void topoSort(vector<int> g[MAXN], int u) {
    visited[u] = true;
    for(int i = 0; i < g[u].size(); ++i) {
        int next = g[u][i];
        if(!visited[next]) topoSort(g, next);
    }
    st.push_back(u);
}
 
void dfs(vector<int> gr[MAXN], int u, int comp) {
    scc[u] = comp;
    for(int i = 0; i < gr[u].size(); ++i) {
        int next = gr[u][i];
        if(scc[next] == -1) dfs(gr ,next, comp);
    }
}
 
int findScc(vector<int> g[MAXN], vector<int> gr[MAXN],int n) {
    for(int i = 0; i < n; ++i) {
        if(!visited[i]) topoSort(g,i);
    }
    reverse(st.begin(), st.end());
    int comp = -1;
    for(int i = 0; i < st.size(); ++i) {
        int curr = st[i];
        if(scc[curr] == -1) dfs(gr, curr, ++comp);
    }
    return comp;
}
 
void buildMacro(vector<int> g[MAXN], vector<int> gm[MAXN], int n) {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < g[i].size(); ++j) {
            if(scc[i] != scc[g[i][j]])gm[scc[i]].push_back(scc[g[i][j]]);
        }
    }
}
 
 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n, m, x, y, count, v, vv;
        vector<int> g[MAXN];
        vector<int> gr[MAXN];
        vector<int> gm[MAXN];
        cin >> n >> m;
        st = vector<int>();
        visited = vector<bool>(MAXN, false);
        knockOver = vector<int>(MAXN, 0);
        scc = vector<int>(MAXN, -1);
        while(m--) {
            cin >> x >> y;
            x--;
            y--;
            g[x].push_back(y);
            gr[y].push_back(x);
        }
        int size = findScc(g, gr, n);
        buildMacro(g, gm ,n);
        count = 0;
        for(int i = 0; i <= size; ++i){ 
            if(knockOver[i] == 2)continue;
            else{
                queue<int> q;
                knockOver[i] = 1;
                q.push(i);
                count++;
                while(!q.empty()){
                    v = q.front();
                    q.pop();
                    for(int j = 0; j < gm[v].size(); ++j){
                        vv = gm[v][j];
                        if(knockOver[vv] == 1){
                            count--;
                            knockOver[vv] = 2;
                        }else if(knockOver[vv] == 2);
                        else{
                            knockOver[vv] = 2;
                            q.push(vv);
                        }
                        
                    }
                }
            }
            next:continue;
        }
        cout << count << endl;
    }
    return 0;
}