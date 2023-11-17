#include <iostream>
#include <queue>
#include <array>
#include <unordered_map>
#include <cmath>
#include <algorithm>


using namespace std;

int main(){
    int n, r, in, v, e, d;
    string s;
    cin >> n;
    while(n--){
        int transformations[8] = {-1000, -100, -10, -1, 1, 10, 100, 1000};
        int start;
        int target;
        s = "";
        for(int i = 0; i < 4; ++i){
            cin >> in;
            s = s + to_string(in);
        }
        start = stoi(s);
        s = "";
        for(int i = 0; i < 4; ++i){
            cin >> in;
            s = s + to_string(in);
        }
        target = stoi(s);
        cin >> r;
        unordered_map<int, int > restriction;
        for(int i = 0; i < r; ++i){
            s = "";
            for(int j = 0; j < 4; ++j){
                cin >> in;
                s = s + to_string(in);
            }
            v = stoi(s);
            restriction[v] = 1;
        }
        unordered_map<int, int > bfs;
        unordered_map<int, int > parent;

        queue<int> q;
        bfs[start] = 0;
        bfs[target] = -1;
        if(start == target){
            bfs[target] = 0;
            goto stop;
        }
        q.push(start);
        while(!q.empty()){
            v = q.front();
            q.pop();
            for(int i = 0; i < 8; ++i){
                s = to_string(v);
                d = (string((4 - s.length()), '0').append(s)).at(3-(int)log10(abs(transformations[i]))) - '0';
                d += transformations[i]/abs(transformations[i]);
                if(d > 9 || d < 0) e = v - 9*transformations[i];
                else e = v + transformations[i];
                if(e == target){
                    bfs[e] = bfs[v] + 1;
                    goto stop;
                }
                else if(bfs[e] == 0 && restriction[e] != 1){
                    bfs[e] = bfs[v] + 1;
                    q.push(e);
                }
            }
        }
        stop:
        cout << bfs[target] << endl;
    }
}