//Jonathan Shahi
//den 12 maj 2022
//Ill be happy with an E

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <ctime>

class maze {

	struct node {
		int x; // rows
		int y; // colums
		bool wall = false; // #
		bool start = false; // S
		bool end = false; // E
		bool visited = false;
		/// <summary>
		/// paramath constructor
		/// </summary>
		node(int x, int y, bool wall, bool visited) {
			this->x = x;
			this->y = y;
			this->wall = wall;
			this->visited = visited;
		}
	};
public:
	/// <summary>
	/// default constructor to create the walls
	/// </summary>
	maze();
	/// <summary>
	/// Depth_first_search to generate a maze.
	/// </summary>
	void dfs();
	/// <summary>
	/// print out the maze on the screen
	/// </summary>
	void print();
	/// <summary>
	/// Opens a way between the given nodes.
	/// </summary>
	void connect(node n, node g);
	/// <summary>
	/// this function checks if the given node(position) has any neighbors
	/// </summary>
	/// <returns>return true or false, depending if the node has neighbors or not</returns>
	bool unvisited_neigh(node n);
	/// <summary>
	/// pick a unvisited neighbor at random and sets it as it current position
	/// </summary>
	/// <returns>return the random picked neighbor </returns>
	node& pick_rand_unvisited_neigh(node n);

	int rows = 11;
	int colums = 11;
	std::vector<std::vector<node>>* mymaze;
};