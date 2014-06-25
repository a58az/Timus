#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    #endif

    int n, x, y;
    int king, knight, bishop, rook, queen;
    king = knight = bishop = rook = queen = 0;

    cin >> n >> x >> y;

    int xy[4] = {
        x - 1, // left
        n - x, // right
        n - y, // top
        y - 1  // bottom
    };
                   
    int diag[4] = {
        min(xy[0], xy[2]), // top left
        min(xy[1], xy[2]), // top right
        min(xy[1], xy[3]), // bottom right
        min(xy[0], xy[3])  // bottom left
    };

    for(auto& i : xy) {
        king += (i > 0 ? 1 : 0);
        rook += i;
    }

    for(auto& i : diag) {
        king += (i > 0 ? 1 : 0);
        bishop += i;
    }

    queen = rook + bishop;

    // top
    if (y + 2 <= n) {
        knight += (x + 1 <= n) ? 1 : 0; // right
        knight += (x - 1 >= 1) ? 1 : 0; // left
    }
    // bottom
    if (y - 2 >= 1) {
        knight += (x + 1 <= n) ? 1 : 0; // right
        knight += (x - 1 >= 1) ? 1 : 0; // left
    }
    // right
    if (x + 2 <= n) {
        knight += (y + 1 <= n) ? 1 : 0; // top
        knight += (y - 1 >= 1) ? 1 : 0; // bottom
    }
    // left
    if (x - 2 >= 1) {
        knight += (y + 1 <= n) ? 1 : 0; // top
        knight += (y - 1 >= 1) ? 1 : 0; // bottom
    }

    cout << "King: " << king << endl;
    cout << "Knight: " << knight << endl;
    cout << "Bishop: " << bishop << endl;
    cout << "Rook: " << rook << endl;
    cout << "Queen: " << queen << endl;

    return 0;
}
