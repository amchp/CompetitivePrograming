#include <iostream>

using namespace std;

int main(){
    int s, t, a, b, m, n, dist;
    int aSum, oSum = 0;
    cin >> s >> t >> a >> b >> m >> n;
    int apples[m], oranges[n];
    for(int i = 0; i < m; ++i){
        cin >> apples[i];
        dist = apples[i] + a;
        if(dist >= s && dist <= t) aSum++;
    }
    for(int i = 0; i < n; ++i){
        cin >> oranges[i];
        dist = oranges[i] + b;
        if(dist >= s && dist <= t) oSum++;
    }
    cout << aSum << endl << oSum << endl;
}