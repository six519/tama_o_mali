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
	},
	{
		"Ang kasarian ng pangngalan na Nanay ay PAMBABAE.",
		true
	},
	{
		"Ang Pilipinas ay mayroong labing-pitong rehiyon.",
		true
	},
	{
		"Ang ilog Pasig ang pinakamahabang ilog sa Pilipinas.",
		false
	},
	{
		"Ang guro ay nagtuturo.\nAng kasarian ng GURO ay PAMBABAE.",
		false
	},
	{
		"Ang lapis ay matulis. Ang kasarian ng LAPIS ay DI-TIYAK.",
		false
	},
	{
		"Si ate ay naglalaba ng mga damit.\nAng ATE ay may kasarian na PAMBABAE.",
		true
	},
	{
		"Ang bata ay naglalaro.\nAng kasarian ng BATA ay PANLALAKI.",
		false
	},
	{
		"Ang kasarian ng pangngalan na TITO ay PAMBABAE.",
		false
	},
	{
		"Ang labandera ay naglalaba.\nAng kasarian ng LABANDERA ay DI-TIYAK.",
		false
	},
	{
		"Ang Pilipinas ay isang arkipelago o kapuluan.",
		true
	}
};

#endif