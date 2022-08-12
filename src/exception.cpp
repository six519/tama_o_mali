#include "exception.hpp"

using namespace std;

string OtherException::message()
{
    return "An unexpected error occurred	...\n";
}

FileException::FileException(string fname)
{
    this->fname = fname;
}

string FileException::message()
{
    return "Unable to load file " + this->fname +  "...\n";
}