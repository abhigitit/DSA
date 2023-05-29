/*
https://www.geeksforgeeks.org/check-if-the-given-permutation-is-a-valid-bfs-of-a-given-tree/
*/

#include <bits/stdc++.h>
using namespace std;

// map for storing the tree
map<int, vector<int> > tree;

// map for marking
// the nodes visited
map<int, int> vis;

// Function to check if
// permutation is valid
bool valid_bfs(vector<int>& v)
{
	int n = (int)v.size();
	queue<set<int> > q;
	set<int> s;
	s.insert(1);

	/*inserting the root in
	the front of queue.*/
	q.push(s);
	int i = 0;

	while (!q.empty() && i < n)
	{

		// If the current node
		// in a permutation
		// is already visited
		// then return false
		if (vis.count(v[i]))
		{
			return 0;
		}
		vis[v[i]] = 1;

		// if all the children of previous
		// nodes are visited then pop the
		// front element of queue.
		if (q.front().size() == 0)
		{
			q.pop();
		}

		// if the current element of the
		// permutation is not found
		// in the set at the top of queue
		// then return false
		if (q.front().find(v[i])
			== q.front().end()) {
			return 0;
		}
		s.clear();

		// push all the children of current
		// node in a set and then push
		// the set in the queue.
		for (auto j : tree[v[i]]) {
			if (vis.count(j)) {
				continue;
			}
			s.insert(j);
		}
		if (s.size() > 0) {
			set<int> temp = s;
			q.push(temp);
		}
		s.clear();

		// erase the current node from
		// the set at the top of queue
		q.front().erase(v[i]);

		// increment the index
		// of permutation
		i++;
	}

	return 1;
}

// Driver code
int main()
{
	tree[1].push_back(2);
	tree[2].push_back(1);
	tree[1].push_back(5);
	tree[5].push_back(1);
	tree[2].push_back(3);
	tree[3].push_back(2);
	tree[2].push_back(4);
	tree[4].push_back(2);
	tree[5].push_back(6);
	tree[6].push_back(5);

	vector<int> arr
		= { 1, 5, 2, 3, 4, 6 };

	if (valid_bfs(arr))
		cout << "Yes" << endl;

	else
		cout << "No" << endl;

	return 0;
}

