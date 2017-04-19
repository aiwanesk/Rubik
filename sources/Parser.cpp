#include "Parser.hpp"
#include <iostream>

void Parser::fillValidMove(){
	vector<string> face = {"F", "R", "U", "L", "B", "D"};
	vector<string> spe = {"'","2"};

	for (auto &x : face){
		validMove.push_back(x);
		for (auto &y : spe)
			validMove.push_back(x + y);
	}
}

vector<string> Parser::generateRandomMove(){
	vector<string> ret;

	srand(time(NULL));
	int nb = rand() % 100 + 1;
	for (int i = 0; i < nb ; i++){
		int where = rand() % (int)validMove.size();
		ret.push_back(validMove[where]);
	}
	for (auto &x : ret)
		cout << x << endl;
	return (ret);
}

vector<string> Parser::splitArg(char *s){
	istringstream iss(s);
	vector<string> tokens{istream_iterator<string>{iss},istream_iterator<string>{}};

	return tokens;
}

void Parser::verifyArgValidity(vector<string> ret){
	for (auto &x : ret){
		if (find(validMove.begin(), validMove.end(), x) == validMove.end())
			throw InvalidData("Invalid arg", x);
	}
}

vector<string> Parser::launchParser(char **av){
	vector<string> ret;

	fillValidMove();
	if (strcmp(av[1], "-R") == 0)
		ret = generateRandomMove();
	else{
		ret = splitArg(av[1]);
		verifyArgValidity(ret);
	}
	return ret;
}
