#pragma once
#include <string>
#include <time.h>
#include <fstream>
using namespace std;
class Forum;

class Comment
{
private:
	string id;	//评论者id
	string content;	//评论内容
	string thistime;//评论时间
public:
	Comment();
	~Comment();
	
	Comment(string TempId, string TempContent);	//

	string GetTime();//返回现在的时间

	string GetThistime();//返回评论时间

	string GetUserId();//返回评论人id

	string GetContent();//返回评论内容

	void SetThisTime(string ThisTime);//设置评论时间

	void SetUserId(string UserId);//设置评论者id

	void SetContent(string Content);//设置评论内容

	friend ofstream& operator<<(ofstream &output, Comment *comment);//写入到文件
};

