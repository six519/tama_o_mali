#ifndef _QUESTIONS_H_
#define _QUESTIONS_H_
#include <string>
#include <vector>

using namespace std;

struct Question {
	string q;
	bool a;
};

const vector<Question> questions = {
	{
		"Si Ferdinand Magellan ay namatay noong Abril 27, 1521\nsa isla ng Mactan.",
		true
	}
};

#endif