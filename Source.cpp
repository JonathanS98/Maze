#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

class maze {
public:
	struct node {
		int x;
		int y;
		bool wall = false;
		bool start = false;
		bool end = false;
		bool visited = false;
		node(int x, int y, bool wall);
	};
	maze();
	void dfs();
	void initiate();
	void connect(node n, node g);

	int rows = 11;
	int colums = 11;
	std::pair<int, int> startcor;
	std::pair<int, int> endcor;
	std::vector<std::vector<node>> *mymaze;
};

maze::node::node(int x, int y, bool wall) {
	this->x = x;
	this->y = y;
	this->wall = wall;
}

maze::maze() : rows(11), colums(11), mymaze(new std::vector<std::vector<node>>) {
	for (int i = 0; i < rows; i++) {
		std::vector<node> temp;
	}
}