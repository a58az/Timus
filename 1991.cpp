#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    #endif

    int n, k;
    cin >> n >> k;
    int temp, sum, rem;
    rem = sum = 0;
    while (n--) {
        cin >> temp;

        if (temp > k) {
            rem += temp - k;
        } else {
            sum += (k - temp);
        }
    }

    cout << rem << " " << sum;
}
