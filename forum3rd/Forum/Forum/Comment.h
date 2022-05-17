#pragma once
#include <string>
#include <time.h>
#include <fstream>
using namespace std;
class Forum;

class Comment
{
private:
	string id;//������id
	string content;//��������
	string thistime;//����ʱ��
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

