//Jonathan Shahi
//den 12 maj 2022
//Ill be happy with an E

#include "maze.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
	srand(time(NULL));
	
	int ans;
	while (true) {
		cout << "Welcome to my simple maze" << endl;
		cout << "[1] Generate a random maze" << endl;
		cout << "[0] Exit" << std::endl;
		cin >> ans;

		if (ans == 1) {
			maze m;
			m.dfs();
			m.print();
		}
		else if (ans == 0) {
			cout << "Have a nice day" << endl;
			exit(0);
		}
		else {
			cout << "Invalid Input, Pls try again" << endl;
		}
	}
	return 0;
}