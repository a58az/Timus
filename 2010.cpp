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

    int xy[4];
    int n, x, y;
    int king, knight, bishop, rook, queen;
    king = knight = bishop = rook = queen = 0;

    cin >> n >> x >> y;

    // left
    xy[0] = x - 1;
    // right
    xy[1] = n - x;
    // top
    xy[2] = n - y;
    // bottom
    xy[3] = y - 1;

    // top left
    bishop += min(xy[0], xy[2]);
    // top right
    bishop += min(xy[1], xy[2]);
    // bottom right
    bishop += min(xy[1], xy[3]);
    // bottom left
    bishop += min(xy[0], xy[3]);

    rook = xy[0] + xy[1] + xy[2] + xy[3];

    king = (xy[0] > 0 ? 1 : 0) + (xy[1] > 0 ? 1 : 0) +
        (xy[2] > 0 ? 1 : 0) + (xy[3] > 0 ? 1 : 0) +
        (min(xy[0], xy[2]) > 0 ? 1 : 0) +
        (min(xy[1], xy[2]) > 0 ? 1 : 0) +
        (min(xy[1], xy[3]) > 0 ? 1 : 0) +
        (min(xy[0], xy[3]) > 0 ? 1 : 0);

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


    queen = rook + bishop;

    // cout << endl << king << endl << knight << endl << bishop << endl << rook << endl << queen;
    cout << "King: " << king << endl;
    cout << "Knight: " << knight << endl;
    cout << "Bishop: " << bishop << endl;
    cout << "Rook: " << rook << endl;
    cout << "Queen: " << queen << endl;

    return 0;
}
