#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    #endif

    int i, k, n, m, med;
    string name, medal;
    unordered_map<string, int> univers;
    m = 3; n = 4;
    for (k = 1; k <= m; k++)
        for (i = 0; i < n; ++i)
        {
            cin >> name;
            univers[name] = k;
        }

    cin >> m;   
    int maxCounter, wA;
	maxCounter = wA = 0;
    for (k = 0; k < m; ++k) { 
        cin >> n;
        int counter = 0;
        for (i = 0; i < n; ++i) {
            cin >> name >> medal >> medal;
            med = medal[0] == 'g' ? 1 : medal[0] == 's' ? 2 : 3;
            if (univers[name] == med) {
                counter++;                
            }
        }
        if (counter == maxCounter) {
            wA += 1;
        } else if (counter > maxCounter) {
            maxCounter = counter;
            wA = 1;
        }
    }

    cout << wA * 5;

    return 0;
}
