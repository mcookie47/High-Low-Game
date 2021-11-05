#include <iostream>

using namespace std;

class Player {
public:
	string name;
	float balance;
	float starting_balance;

	
public:
	Player() {
		name = "";
		balance = 0;
		starting_balance = 0;
	}
	
};

class Yesno {
public:
	string answer;

public:
	Yesno() {
		answer = "";
	}
};