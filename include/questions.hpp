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
		"Si Ferdinand Magellan ay namatay noong\nAbril 27, 1521 sa isla ng Mactan.",
		true
	},
	{
		"Si Elpidio Quirino ang kauna-unahang pinoy\nna lumabas sa telebisyon.",
		true
	},
	{
		"Tuwing ika-apat ng Hulyo ipinagdiriwang ang\nAraw ng Kalayaan sa Pilipinas.",
		false
	},
	{
		"Manila ang kabisera ng Pilipinas at\nFilipino ang pambansang wika nito.",
		true
	},
	{
		"Si Andres Bonifacio ang pambansang bayani ng Pilipinas.",
		false
	},
	{
		"Si Theodore Roosevelt, Jr. ang pinakahuling Amerikanong\nGobernador-Heneral sa Pilipinas.",
		false
	}
};

#endif