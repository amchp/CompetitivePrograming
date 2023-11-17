#include <iostream>

using namespace std;

int main(){
    int d, m, y;
    int ed, em, ey;
    cin >> d >> m >> y >> ed >> em >> ey;
    if(ey < y) cout << 10000 << endl;
    else if(ey == y && em < m) cout << 500*(m - em) << endl;
    else if(ey == y && em == m && ed  < d) cout << 15*(d-ed) << endl;
    else cout << 0 << endl;
}