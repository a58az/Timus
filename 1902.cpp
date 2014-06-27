#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <map>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    #endif

    int n, time, start, temp;
    cin >> n >> time >> start;

    const int t = start + time;
	cout << setprecision(6);	
    while (n--) {
    	cin >> temp;
    	cout << (t + temp) / 2.0 << endl;
    }

    return 0;
}
