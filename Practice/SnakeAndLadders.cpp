#include <vector>
#include <map>
#include <cstdlib>
#include <fstream>
#include <iomanip>   
#include <iostream>  
#include <sstream>  // istringstream buffer(myString);
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <math.h>
#include <unordered_map>
#include <queue>
#include <array>

// Useful constants 
#define INF                         (int)2e9 
#define EPS                         1e-9

#define el '\n'

#define MAXN                         (int)2e5
#define MAXA                         (int)1e9

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int p, jumps, r, v, vv, turn;
        cin >> p >> jumps >> r;
        int players[p];
        int m[101];
        for(int i = 0; i < 101; ++i)m[i] = 0;
        for(int i = 0; i < p; ++i)players[i] = 1;
        for(int i = 0; i < jumps; ++i){
            cin >> v >> vv;
            m[v] = vv;
        }
        // for(int i = 0; i < 101; ++i){
        //     v = i;
        //     while(m[m[v]] != 0)v = m[v];
        //     m[i] = m[v];
        // }
        turn = 0;
        for(int i = 0; i < r; ++i){
            if(turn == p)turn = 0;
            cin >> v;
            players[turn] += v;
            if(players[turn] >= 100){
                players[turn] = 100;
                break;
            }
            if(m[players[turn]] != 0)players[turn] = m[players[turn]];
            turn++;
        }
        for(int i = 0; i < p; ++i)cout << "Position of player " << i+1 << " is " << players[i] << "." << el;
    }
}