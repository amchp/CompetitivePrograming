#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int d, shared, liked, dLiked;
    cin >> d;
    shared = 5;
    liked = 0;
    for(int i = 0; i < d; ++i){
        dLiked = floor(shared/2);
        shared = dLiked*3;
        liked += dLiked;
    }
    cout << liked << endl;
}