#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_
#include <string>

using namespace std;

class OtherException
{
    public:
        string message();
};

class FileException
{
	private:
		string fname;
    public:
		FileException(string fname);
        string message();
};

#endif