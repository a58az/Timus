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

    int road[5][5];
    int *pa = *road;
    int i, x, y;

    int path[4][5] =
    {
        {1,2,3,4,5},
        {1,4,3,2,5},
        {1,3,2,4,5},
        {1,3,4,2,5}
    };

    for (i = 0; i < 25; i++) {
        cin >> *(pa++);
    }

    int sum, row, minRow, minSum = 60000;
    sum = row = minRow = 0;

    for ( ; row < 4; row++) {
        for (sum = i = 0; i < 4; i++) {
            x = path[row][i]-1;
            y = path[row][i+1]-1;
            sum += road[x][y];
        }
        if (sum < minSum) {
            minSum = sum;
            minRow = row;
        }
    }

    cout << minSum << endl;
    pa = path[minRow];
    for (i = 0; i < 5; i++)
        cout << *pa++ << " ";

    delete pa;

    return 0;
}
