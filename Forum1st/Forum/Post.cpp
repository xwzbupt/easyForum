#include "Post.h"



Post::Post()
{
}


Post::~Post()
{
}

Post::Post(string TempUserId, string TempTitle, string TempContent, string TempSection)
{
	this->userid = TempUserId;		//发帖人
	this->title = TempTitle;		//帖子标题
	this->content = TempContent;		//帖子内容
	this->thistime = this->GetTime();	//发帖时间
	this->section = TempSection;		//帖子所在板块
}

//设置帖子的id
void Post::SetId(int id)
{
	this->id = id;
}

//获得帖子的id
int Post::GetId()
{
	return this->id;
}

string Post::GetPostTitle()
{
	return this->title;
}

string Post::GetPostContent()
{
	return this->content;
}

//返回发帖者
string Post::GetPostUserid()
{
	return this->userid;
}

string Post::GetTime()
{
	char temp[32] = { NULL };
	time_t t;
	time(&t);
	strftime(temp, sizeof(temp), "%Y-%m-%d %H:%M:%S", localtime(&t));
	return temp;
}