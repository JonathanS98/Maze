//Jonathan Shahi
//den 12 maj 2022
//Ill be happy with an E

#include "maze.h"

maze::maze() : rows(11), colums(11), mymaze(new std::vector<std::vector<node>>) {
	for (int i = 0; i < rows; i++) {
		std::vector<node> temp;
		for (int j = 0; j < colums; j++) {
			if (i % 2 == 0 || j % 2 == 0) {
				temp.push_back(node(i, j, true, false));
			}
			else {
				temp.push_back(node(i, j, false, false));
			}
		}
		mymaze->push_back(temp);
	}
}

void maze::print() {
	for (int x = 0; x < rows; x++) {
		for (int y = 0; y < colums; y++) {
			if (x == 1 && y == 0) {
				std::cout << "S";
				std::cout << " ";
			}
			else if (x == 9 && y == 10) {
				std::cout << "E";
				std::cout << " ";
			}
			else if ((*mymaze)[x][y].wall) {
				std::cout << "X";
				std::cout << " ";
			}
			else {
				std::cout << " ";
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
}

bool maze::unvisited_neigh(node n) {
	if ((n.x > 1) && (!(*mymaze)[n.x - 2][n.y].visited)) {
		return true;
	}
	if ((n.x < rows - 2) && (!(*mymaze)[n.x + 2][n.y].visited)) {
		return true;
	}
	if ((n.y > 1) && (!(*mymaze)[n.x][n.y - 2].visited)) {
		return true;
	}
	if ((n.y < colums - 2) && (!(*mymaze)[n.x][n.y + 2].visited)) {
		return true;
	}

	return false;
}

maze::node& maze::pick_rand_unvisited_neigh(node n) {
	std::vector<node> temp;
	if ((n.x > 1) && (!(*mymaze)[n.x - 2][n.y].visited)) {
		temp.push_back((*mymaze)[n.x - 2][n.y]);
	}
	if ((n.x < rows - 2) && (!(*mymaze)[n.x + 2][n.y].visited)) {
		temp.push_back((*mymaze)[n.x + 2][n.y]);
	}
	if ((n.y > 1) && (!(*mymaze)[n.x][n.y - 2].visited)) {
		temp.push_back((*mymaze)[n.x][n.y - 2]);
	}
	if ((n.y < colums - 2) && (!(*mymaze)[n.x][n.y + 2].visited)) {
		temp.push_back((*mymaze)[n.x][n.y + 2]);
	}
	size_t a = rand() % temp.size();
	return (*mymaze)[temp[a].x][temp[a].y];
}

void maze::connect(node n, node g) {
	if (n.x == (g.x - 2))
		(*mymaze)[n.x + 1][n.y].wall = false;
	if (n.x == (g.x + 2))
		(*mymaze)[n.x - 1][n.y].wall = false;
	if (n.y == (g.y - 2))
		(*mymaze)[n.x][n.y + 1].wall = false;
	if (n.y == (g.y + 2))
		(*mymaze)[n.x][n.y - 1].wall = false;
}

void maze::dfs() {
	std::stack<node> s;

	node& n = (*mymaze)[1][1];
	n.visited = true;
	s.push(n);
	while (!s.empty()) {
		n = s.top();	
		if (unvisited_neigh(n)) {
			s.push(n);
			node& g = pick_rand_unvisited_neigh(n);
			connect(n, g);
			g.visited = true;
			s.push(g);
		}
		else {
			s.pop();
		}
	}
}