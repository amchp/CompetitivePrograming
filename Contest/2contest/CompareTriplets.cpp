#include <iostream>

using namespace std;

int main(){
    string s;
    string bs;
    getline (cin, s);
    getline (cin, bs);
    s = s + " ";
    bs = bs + " ";
    int p;
    int bp;
    int a[3];
    int b[3];
    string su;
    for(int i = 0; i < 3; i++){
        p = s.find(" ");
        bp = bs.find(" ");
        a[i] = stoi(s.substr(0, p));
        b[i] = stoi(bs.substr(0, bp));
        s = s.substr(p+1, s.length());
        bs = bs.substr(bp+1, bs.length());
    }
    int points[2] = {0, 0};
    for(int i = 0; i < 3; i++){
        if(a[i] > b[i]){
            points[0]++;
        }else if (b[i] > a[i])
        {
            points[1]++;
        }
    }
     cout << points[0] << " " << points[1];
    return 0;
}