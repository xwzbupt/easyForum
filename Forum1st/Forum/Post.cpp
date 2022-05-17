#include "Post.h"



Post::Post()
{
}


Post::~Post()
{
}

Post::Post(string TempUserId, string TempTitle, string TempContent, string TempSection)
{
	this->userid = TempUserId;		//������
	this->title = TempTitle;		//���ӱ���
	this->content = TempContent;		//��������
	this->thistime = this->GetTime();	//����ʱ��
	this->section = TempSection;		//�������ڰ��
}

//�������ӵ�id
void Post::SetId(int id)
{
	this->id = id;
}

//������ӵ�id
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

//���ط�����
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