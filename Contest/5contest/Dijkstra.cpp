#include <iostream>
#include <vector>
#include <queue>
#include <array>


using namespace std;

int INF = 1000000000;

int main(){
    int v, e, a, b, w, d, ver, p;
    int val;
    array<int, 2> arr;
    vector<array<int, 2> > edges;
    cin >> v >> e;
    int dist[v+1]; 
    int parent[v+1];
    bool visited[v+1];
    vector<array<int, 2> > g[v+1];
    queue<int > dq;
    string output;
    for(int i = 1; i < v+1; ++i){
        dist[i] = INF;
        parent[i] = -1;
        visited[v+1] = false;
    }
    while(e--){
        cin >> a >> b >> w;
        arr[0] = b;
        arr[1] = w;
        g[a].push_back(arr);
        arr[0] = a;
        g[b].push_back(arr);
    }
    
    dist[1] = 0;
    visited[1] = true;
    dq.push(1);
    
    while(!dq.empty()){
        ver = dq.front();
        dq.pop();
        d = dist[ver];
        edges = g[ver];
        for(int i = 0; i < edges.size(); ++i){
            val = d + edges[i][1];
            if(val < dist[edges[i][0]]){
                dist[edges[i][0]] = val;
                parent[edges[i][0]] = ver;
            }
            if(!visited[edges[i][0]]){
                visited[edges[i][0]] = true;
                dq.push(edges[i][0]);
            }
        }
    }

    if(parent[v] == -1) cout << -1 << endl;
    else{
        output = to_string(v);
        p = parent[v];
        while(p != 1){
            output = to_string(p) + " " + output;
            p = parent[p];
        }
        output = "1 " + output;
        cout << output << endl;
    }
}