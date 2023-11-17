#include <iostream>
#include <vector>
#include <queue>


using namespace std;

int main(){
    int q, n, m, r1, r2, start, level, p;
    vector<int> v;
    cin >> q;
    while(q--){
        cin >> n >> m;
        long long bfs[n+1];
        int parent[n+1];
        vector<int> g[n+1];
        for(int i = 1; i < n + 1; ++i){
            g[i].push_back(i);
            bfs[i] = 0;
            parent[i] = -1;
        }
        while(m--){
            cin >> r1 >> r2;
            g[r1].push_back(r2);
            g[r2].push_back(r1);
        }
        cin >> start;
        queue<int> bfsQueue;
        bfsQueue.push(start);
        level = 0;
        while(!bfsQueue.empty()){
            p = bfsQueue.front();
            bfsQueue.pop();
            v = g[p];
            for(int i = 1; i < v.size(); ++i){
                if(bfs[v[i]] == 0){
                    bfs[v[i]] = bfs[p] + 1;
                    bfsQueue.push(v[i]);
                    parent[v[i]] = p;
                }
            }
        }

        for(int i = 1; i < n+1; ++i){
            if(i == start)continue;
            else if(bfs[i] == 0)cout << -1 << " ";
            else cout << bfs[i]*6 << " ";
            if(i == n) cout << endl;
        }
    }
}