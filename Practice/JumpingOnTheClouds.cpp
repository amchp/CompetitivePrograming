#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n, v;
    cin >> n;
    int clouds[n];
    int bfs[n];
    for(int i = 0; i < n; ++i){
        cin >> clouds[i];
        bfs[i] = 0;
    }
    
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        v = q.front();
        q.pop();
        for(int i = 1; i < 3; ++i){
            if((v + i) == (n - 1)){
                bfs[v+i] = bfs[v] + 1;
                goto stop;
            }
            if(clouds[v+i] == 0 && bfs[v+i] == 0){
                bfs[v+i] = bfs[v] + 1;
                q.push(v+i);
            }
        }
    }
    stop:

    cout << bfs[n-1] << endl;
}