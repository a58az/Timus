#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const string root = "Isenbaev";
map<string, int> id;
vector<int> adj[300];
int dist[300];

typedef unsigned int ui;

void bfs()
{
    queue<int> q;

    memset(dist, -1, sizeof(dist));

    // Isenbaev in map
    if (id.find(root) != id.end()) {
        int cur = id[root];

        dist[cur] = 0;
        q.push(cur);

        while (!q.empty()) {
            cur = q.front();
            q.pop();

            for (ui i = 0; i < adj[cur].size(); i++) {
                int next = adj[cur][i];

                if (dist[next] == -1) {
                    dist[next] = dist[cur] + 1;
                    q.push(next);
                }
            }
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    #endif

    int n, counter = 0;
    string name1, name2, name3;
    int a, b, c;

    cin >> n;

    while (n--) {
        cin >> name1 >> name2 >> name3;

        if (id.find(name1) == id.end()) id[name1] = counter++;
        if (id.find(name2) == id.end()) id[name2] = counter++;
        if (id.find(name3) == id.end()) id[name3] = counter++;

        a = id[name1]; b = id[name2]; c = id[name3];

        adj[a].push_back(b); adj[a].push_back(c);
        adj[b].push_back(a); adj[b].push_back(c);
        adj[c].push_back(b); adj[c].push_back(a);
    }

    bfs();

    for(auto& s: id) {
        cout << s.first << " ";
        if (dist[s.second] == -1)
            cout << "undefined";
        else
            cout << dist[s.second];
        cout << endl;
    }
}


