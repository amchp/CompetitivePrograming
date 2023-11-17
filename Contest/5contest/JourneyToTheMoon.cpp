#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <queue>


using namespace std;

bool compareInterval(array<int, 2> a1, array<int, 2> a2){
    return (a1[2] >= a2[1]);
}

int main(){
    int n, p, p1, p2, v;
    cin >> n >> p;
    int pairs[p][2];
    int index = 1;
    vector<int> g[n];
    int visited[n];
    for(int i = 0; i < n; ++i){
        visited[i] = -1;
    }
    for(int i = 0; i < p; ++i){
        cin >> p1 >> p2;
        g[p1].push_back(p2);
        g[p2].push_back(p1);
        visited[p1] = 0;
        visited[p2] = 0;
    }
    

    for(int i = 0; i < n; ++i){
        if(visited[i] == 0){
            queue<int> q;
            q.push(i);
            visited[i] = index;
            while(!q.empty()){
                v = q.front();
                q.pop();
                for(int j = 0; j < g[v].size(); ++j){
                    if(visited[g[v][j]] == 0){
                        q.push(g[v][j]);
                        visited[g[v][j]] = index;
                    }
                }
            }
            index++;
        }
    }

    vector<int> countries[index];
    for(int i = 0; i < n; ++i){
        if(visited[i] == -1)countries[0].push_back(i);
        else countries[visited[i]].push_back(i);
    }

    // for(int i = 0; i < index; ++i){
    //     for(int j = 0; j < countries[i].size(); ++j){
    //         cout << countries[i][j] << " ";
    //     }
    //     cout << endl;
    // }


    long long sum = 0;

    for(int i = 1; i < countries[0].size(); ++i){
        sum += i;
    }

    for(int i = 0; i < index; ++i){
        for(int j = i + 1; j < index; ++j){
            sum += countries[i].size() * countries[j].size();
        }
    }
    cout << sum << endl;

}