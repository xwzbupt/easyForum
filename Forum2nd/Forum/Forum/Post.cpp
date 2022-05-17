#include "Post.h"
#include "Comment.h"
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

ifstream& operator>>(ifstream &input, Post *post)
{
	string line;
	getline(input, line);
	if (line == "##########")
		getline(input, line);
	post->thistime = line;
	getline(input, line);
	post->userid = line;
	getline(input, line);
	post->title = line;
	getline(input, line);
	post->content = line;
	getline(input, line);
	post->section = line;
	getline(input, line);
	while (line != "##########" && !input.eof())
	{
		Comment *comment = new Comment;
		comment->SetThisTime(line);
		getline(input, line);
		comment->SetUserId(line);
		getline(input, line);
		comment->SetContent(line);
		post->comments.push_back(comment);
		getline(input, line);
	}
	return input;
}

ofstream& operator<<(ofstream &output, Post *post)
{
	output << "##########" << endl;
	output << post->thistime << endl;
	output << post->userid << endl;
	output << post->title << endl;
	output << post->content << endl;
	output << post->section << endl;
	for (int i = 0; i < post->comments.size(); i++)
		output << post->comments[i];
	return output;
}