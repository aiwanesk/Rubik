#ifndef PARSER_HPP
#define PARSER_HPP

#include <vector>
#include <exception>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <sstream>
using namespace std;

class Parser{
	public:
		vector<string> launchParser(char **av);

	private:
		vector<string> validMove;

		void fillValidMove();
		vector<string> splitArg(char *av);
		void verifyArgValidity(vector<string> toVerify);
		vector<string> generateRandomMove();
};

class InvalidData : public exception{
	public:
		InvalidData(string error, string data) throw() : error(error), data(data){};
		InvalidData(string error) throw() : error(error){};

		virtual const char *what() const throw(){
			string ret;
			if (data.size() > 0)
				ret = "Error Message : " + error  + "\nFrom this sentence : " + data + "\n";
			else
				ret = "Error Message : " + error  + "\n";
			return ret.c_str();
		}
	private:
		string error;
		string data;
};

#endif
