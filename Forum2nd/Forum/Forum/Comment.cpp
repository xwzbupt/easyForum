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

void Comment::SetThisTime(string a)
{
	this->thistime = a;
}

void Comment::SetUserId(string a)
{
	this->id = a;
}

void Comment::SetContent(string a)
{
	this->content = a;
}

ofstream& operator<<(ofstream &output, Comment *comment)
{
	output << comment->GetThistime() << endl;
	output << comment->GetUserId() << endl;
	output << comment->GetContent() << endl;
	return output;
}