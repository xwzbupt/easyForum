#include "User.h"
#include "Forum.h"
#include "Comment.h"
User::User()
{
	int i;
}

User::User(string username, string password, string id)
{	
	this->username = username;
	this->password = password;
	this->id = id;
	this->Islogin = 0;//没有登录
}

//登录账号
void User::Log_in(string username, string password, Forum *forum)
{

}

//注销账号
void User::Log_out(Forum *forum)
{
	this->Islogin = 0;
}

//获得user的id
string User::GetId()
{
	return this->id;
}

//获得user的username
string User::GetUsername()
{
	return this->username;
}

//获得user的password
string User::GetPassword()
{
	return this->password;
}

void User::SetUsername(string username)
{
	this->username = username;
}

void User::SetPassword(string password)
{
	this->password = password;
}

void User::SetId(string Id)
{
	this->id = Id;
}

void User::CheckIdentification()
{
	cout << "您的id是:" << this->id << endl;
	cout << "您的username是:" << this->username << endl;
	cout << "您的password是:" << this->password << endl << endl;
}

User::~User()
{

}

string User::CheckSection(Forum *forum, string section)
{
	string sendstr="\n\n";
	string num;
	std::stringstream ss;
	for (int i = 0; i < forum->posts.size(); i++)
	{
		string str = "#帖子";
		if (forum->posts[i]->GetSection() == section)
		{
			str = str + to_string(i) + "#\n";
			str = str + "发帖时间:" + forum->posts[i]->thistime + "\n";
			str = str + "发帖人:" + forum->posts[i]->userid + "\n";
			str = str + "帖子标题:" + forum->posts[i]->title + "\n";
			str = str + "帖子内容:" + forum->posts[i]->content + "\n\n";
			sendstr = sendstr + str;
		}
	}
	sendstr = sendstr + "请输入您要进行的操作，按帖子序号查看帖子，按-1返回";
	return sendstr;
}

string User::CheckPost(Forum *forum,int id)
{
	string post = "#";
	string comment;
	string comments="\n";
	post = post + "帖子" + to_string(id) + "#\n";
	post = post + "发帖时间:" + forum->posts[id]->thistime + "\n";
	post = post + "发帖人:" + forum->posts[id]->userid + "\n";
	post = post + "帖子标题:" + forum->posts[id]->title + "\n";
	post = post + "帖子内容:" + forum->posts[id]->content + "\n";
	for (int i = 0; i < forum->posts[id]->comments.size(); i++)
	{
		comment= "-";
		comment = comment + "评论" + to_string(i) + "-\n";
		comment = comment + "评论人:" + forum->posts[id]->comments[i]->GetUserId() + "\n";
		comment = comment + "内容:" + forum->posts[id]->comments[i]->GetContent() + "\n";
		comment = comment + "评论时间:" + forum->posts[id]->comments[i]->GetThistime() + "\n";
		comments = comments + comment;
	}
	return post + comments + "\n按任意键退出到上一步\n";
}

void User::OnlyCheckPost(Forum *forum, string section)
{
	int PostId;
	cout << "输入您想查看的帖子,按-1返回";
	cin >> PostId;
	if (PostId == -1 && (forum->state == 29 || forum->state == 30))
	{
		forum->state = 4;
		return;
	}
		
	else if (PostId == -1 && (forum->state == 35 || forum->state == 36))
	{
		forum->state = 5;
		return;
	}
		
	int flag = 1;
	while (flag == 1)
	{
		if (PostId < forum->posts.size())
		{
			if (forum->posts[PostId]->section != section)
			{
				cout << "该帖子不在你所查看的版块里，请重新输入" << endl;
				cin >> PostId;
			}
			else
				flag = 0;
		}
		else
		{
			cout << "该帖子不存在，请重新输入" << endl;
			cin >> PostId;
		}
	}
	cout << endl;
	         
	cout << "--------------------帖子" << PostId << "--------------------" << endl;
	cout << "发帖时间:" << forum->posts[PostId]->thistime << endl;
	cout << "发帖人:" << forum->posts[PostId]->GetPostUserid() << endl;
	cout << "帖子标题:" << forum->posts[PostId]->GetPostTitle() << endl;
	cout << "帖子内容:" << forum->posts[PostId]->GetPostContent() << endl << endl;
	for (int i = 0; i < forum->posts[PostId]->comments.size(); i++)
	{
		cout << "#评论" << i << "#" << endl;
		cout << "评论时间:" << forum->posts[PostId]->comments[i]->GetThistime() << endl;
		cout << "评论人:" << forum->posts[PostId]->comments[i]->GetUserId() << endl;
		cout << "评论内容:" << forum->posts[PostId]->comments[i]->GetContent() << endl << endl;
	}        
	cout << "-------------帖子" << PostId << "及其评论打印完毕-------------" << endl << endl;
	getchar();
	getchar();
	if (forum->state == 29)
		forum->state = 26;
	else if (forum->state == 30)
		forum->state = 27;
	else if (forum->state == 35)
		forum->state = 33;
	else if (forum->state == 36)
		forum->state = 34;
}

void User::DeletePost(int PostOrder, Forum *forum)
{

}

ofstream& operator<<(ofstream &output, User *user)
{
	output << user->username << endl;
	output << user->password << endl;
	output << user->id << endl;
	return output;
}

ifstream& operator>>(ifstream &input, User *user)
{
	string line;
	getline(input, line);
	user->username = line;
	getline(input, line);
	user->password = line;
	getline(input, line);
	user->id = line;
	return input;
}
