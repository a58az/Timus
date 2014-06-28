#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif

    int i, k, n, m, med;
    string medal, name;
    map<string, int> univers;
    map<string, int>::iterator it;
    m = 3; n = 12;
    for (i = 0; i < n; ++i)
    {
        cin >> name;
        // univers[name] = (i / 4) + 1;
        univers.insert(pair<string, int>(name, i/4+1));
    }

    cin >> m;
    int counter, maxCounter, wA;
    maxCounter = wA = 0;
    for (k = 0; k < m; ++k)
    {
        cin >> n;
        counter = 0;
        for (i = 0; i < n; ++i)
        {
            cin >> name >> medal >> medal;
            switch (medal[0]) {
                case 'g': med = 1; break;
                case 's': med = 2; break;
                default: med = 3; break;
            }
            it = univers.find(name);

            if (it->second == med)
            {
                counter++;
            }
        }

        if (counter == maxCounter)
        {
            wA += 1;
        }
        else if (counter > maxCounter)
        {
            maxCounter = counter;
            wA = 1;
        }
    }

    cout << wA * 5;

    return 0;
}
