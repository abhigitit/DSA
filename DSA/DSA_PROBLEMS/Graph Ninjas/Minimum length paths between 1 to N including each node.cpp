/*
https://www.codingninjas.com/codestudio/library/minimum-length-paths-between-1-to-n-including-each-node

*/

#include<iostream>
#include<queue>
using namespace std;
#define ll long long int

void calcMinDist(int start, int end, int edgeList[][3])
{
    vector<ll> edge[100];

    for (int i = 0; i < end; i++) {
        int temp1 = edgeList[i][0] - 1;
        int temp2 = edgeList[i][1] - 1;
        edge[temp1].push_back(temp2);
        edge[temp2].push_back(temp1);
    }

    queue<pair<ll, ll> > bfs1;
    bfs1.push({ 0, 0 });
    vector<int> minDistF(start, INT32_MAX);
    minDistF[0] = 0;

    while (!bfs1.empty()) {
        auto up = bfs1.front();

        bfs1.pop();
        int x = up.first;
        int lev = up.second;
        if (lev > minDistF[x])
            continue;
        if (x == start - 1)
            continue;

        for (ll y : edge[x]) {
            if (minDistF[y] > lev + 1) {
                minDistF[y] = lev + 1;
                bfs1.push({ y, lev + 1 });
            }
        }
    }

    queue<pair<ll, ll> > bfs2;
    bfs2.push({ start - 1, 0 });
    vector<int> minDistB(start, INT32_MAX);
    minDistB[start - 1] = 0;

    while (!bfs2.empty()) {
        auto up = bfs2.front();

        bfs2.pop();
        int x = up.first;
        int lev = up.second;
        if (lev > minDistB[x])
            continue;
        if (x == 0)
            continue;

        for (ll y : edge[x]) {
            if (minDistB[y] > lev + 1) {
                minDistB[y] = lev + 1;
                bfs2.push({ y, lev + 1 });
            }
        }
    }

    for (int i = 0; i < start; i++) {

        if (minDistF[i] + minDistB[i] > INT32_MAX)
            cout << -1 << " ";

        else
            cout << "Minimum distance from Node 1 to Node " << (start) << " passing through Node " << (i+1) << " is: " << minDistF[i] + minDistB[i] << endl;
    }
}

int main()
{
    int nodes = 5;
    int edges = 8;
    int edgeList[edges][3] = {  { 1, 2 }, { 1, 4 },  {1, 5},
                                { 2, 3 }, { 2, 4},
                                { 3, 4 }, { 3, 5},
                                { 4, 5},
                            };

    calcMinDist(nodes, edges, edgeList);

    return 0;
}
