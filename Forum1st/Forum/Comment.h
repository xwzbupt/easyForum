#pragma once
#include <string>
#include <time.h>

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
};

