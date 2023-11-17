

using namespace std;

int main(){
    int H, W, sum = 0;
    int sides[4][2] = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
    cin >> H >> W;
    int toys[H][W];
    for(int i = 0; i < H; ++i){
        for(int j = 0; j < W; ++j){
            cin >> toys[i][j];
        }
    }
    for(int i = 0; i < H; ++i){
        for(int j = 0; j < W; ++j){
            if(toys[i][j] == 0)continue;
            sum += 2;
            for(int k = 0; k < 4; ++k){
                int x = i + sides[k][0];
                int y = j + sides[k][1];
                bool canX = (x > -1 && x < H);
                bool canY = (y > -1 && y < W);
                if(canX && canY && toys[i][j] > toys[x][y]){
                    sum += toys[i][j] - toys[x][y];
                }
                else if(!canX || !canY) sum += toys[i][j];
            }
        }
    }
    cout << sum << endl;
}