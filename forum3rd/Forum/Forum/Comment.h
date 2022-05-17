#pragma once
#include <string>
#include <time.h>
#include <fstream>
using namespace std;
class Forum;

class Comment
{
private:
	string id;//评论者id
	string content;//评论内容
	string thistime;//评论时间
public:
	Comment();
	~Comment();
	
	Comment(string TempId, string TempContent);
	string GetTime();

	string GetThistime();

	string GetUserId();

	string GetContent();

	void SetThisTime(string ThisTime);

	void SetUserId(string UserId);

	void SetContent(string Content);

	friend ofstream& operator<<(ofstream &output, Comment *comment);
};

