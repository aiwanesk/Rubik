#include "Parser.hpp"
#include <iostream>

int main(int ac, char **av){
	Parser parser;
	vector<string> move;
	//Solver solver

	try{
		if (ac  == 2)
			move = parser.launchParser(av);
		else if (ac <= 1)
			throw InvalidData("Too few arguments");
		else
			throw InvalidData("Too much arguments");
	}
	catch (InvalidData &e){
		cerr << e.what ();
	}
	//solver.launchSolver(move);
	return (0);
}
