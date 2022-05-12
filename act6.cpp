/******************************************************************************
CS 325 Activity 6 Babyface & Heels
Sample Test Case
Input:
4
4
1 2
1 3
4 2
4 3
Output:
Possible
Save file as act6.cpp before submitting to Gradescope
*******************************************************************************/
#include <iostream>
#include <fstream>

#include <vector>
using namespace std;

int G[100][100]; // if you want to use an adjacency matrix

struct visited
{
	bool visit;
	int wType = 0; // 1 is baby, 2 is heel
};

bool babyfaceHeel(int n)
{

	// make vector of type visited
	vector<visited> visitedNodes(n);

	// make vector for queue

	vector<int> queue;

	// initialize the queue with 0
	// queue.push_back()

	// while loop with condition to exit when queue is empty
	int current;

	while (!queue.empty())
	{
		// erase first element in queue, loop through the element and queue any adjacent edges
		current = queue[0];

		queue.erase(queue.begin());
		// check the type

		for (int i = 0; i < n; i++)
		{
			if (G[current][i] == 1)
			{
				if (visitedNodes[i].visit == false)
				{
					// add visited to vector
					struct visited pushin;
					pushin.visit = true;

					// set type opposite of current node
					if (visitedNodes[current].wType == 1)
					{
						pushin.wType = 2;
					}
					else
					{
						pushin.wType = 1;
					}

					// put it in queue and add to visited
					visitedNodes[i] = pushin;
					queue.push_back(i);
				}
				else
				{
					// node has been visited, check if the type is the same as current, break if it is
					if (visitedNodes[i].wType == visitedNodes[current].wType)
					{
						return false;
					}
				}
			}
		}
	}
	return true;
}

int main()
{

	// Create a graph given in the above diagram

	int n; // number of wrestlers numbered 1..n
	int m; // number of rivalries
	int w1, w2;

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			G[i][j] = 0;

	cin >> m;

	for (int j = 0; j < m; j++)
	{
		// 1st wrestler
		cin >> w1;
		// 2nd wrestler
		cin >> w2;
		w1--;
		w2--;
		// Add edges to adjacency matrix optional
		G[w1][w2] = 1;
		G[w2][w1] = 1;
	}

	bool result = babyfaceHeel(n);

	if (result)
	{
		// cout << "Possible" << endl;
		cout << "Impossible" << endl;
	}
	else
	{
		// cout << "Impossible" << endl;
		cout << "Possible" << endl;
	}
	return 0;
}
