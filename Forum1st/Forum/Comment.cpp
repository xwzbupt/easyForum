#include "Comment.h"
#include <ctime>


Comment::Comment()
{
}

Comment::Comment(string TempId, string TempContent)
{
	this->id = TempId;
	this->content = TempContent;
	this->thistime = this->GetTime();
}

string Comment::GetTime()
{
	char temp[32] = { NULL };
	time_t t;
	time(&t);
	strftime(temp, sizeof(temp), "%Y-%m-%d %H:%M:%S", localtime(&t));
	return temp;
}

string Comment::GetThistime()
{
	return this->thistime;
}

string Comment::GetUserId()
{
	return this->id;
}

string Comment::GetContent()
{
	return this->content;
}

Comment::~Comment()
{

}
