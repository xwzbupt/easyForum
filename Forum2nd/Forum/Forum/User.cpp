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

}

//登录账号
void User::Log_in(string username, string password, Forum *forum)
{

}

//注销账号
void User::Log_out(Forum *forum)
{

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

void User::CheckSection(string section,Forum *forum)
{
	forum->section = section;
	cout << "******************" << section << "******************" << endl;
	for (int i = 0; i < forum->posts.size(); i++)
	{
		if (forum->posts[i]->section == section)
		{
			cout << endl;
			cout << "#帖子" << i << "#" << endl;
			cout << "发帖时间:" << forum->posts[i]->thistime << endl;
			cout << "发帖人:" << forum->posts[i]->GetPostUserid() << endl;
			cout << "帖子标题:" << forum->posts[i]->GetPostTitle() << endl;
			cout << "帖子内容:" << forum->posts[i]->GetPostContent() << endl << endl;
		}
	}
	cout << "******************打印完毕******************" << endl << endl;
	cout << "选择您要进行的操作:" << endl;
	cout << "                 按 1 查看该板块下的任意一个帖子" << endl;
	cout << "                 按 2 返回上一步操作" << endl;
	int choose;
	int choosen;
	cin >> choose;
	while (choose != 1 && choose != 2)
	{
		cout << "请输入合法选择" << endl;
		cin >> choosen;
		choose = choosen;
	}
	if (forum->state == 6)
	{
		if (choose == 1)
			forum->state = 10;
		else if (choose == 2)
			forum->state = 2;
	}
	else if (forum->state == 7)
	{
		if (choose == 1)
			forum->state = 13;
		else if (choose == 2)
			forum->state = 2;
	}
	else if (forum->state == 16)
	{
		if (choose == 1)
			forum->state = 20;
		else if (choose == 2)
			forum->state = 3;
	}
	else if (forum->state == 17)
	{
		if (choose == 1)
			forum->state = 23;
		else if (choose == 2)
			forum->state = 3;
	}
	else if (forum->state == 26)
	{
		if (choose == 1)
			forum->state = 29;
		else if (choose == 2)
			forum->state = 4;
	}
	else if (forum->state == 27)
	{
		if (choose == 1)
			forum->state = 30;
		else if (choose == 2)
			forum->state = 4;
	}
	else if (forum->state == 33)
	{
		if (choose == 1)
			forum->state = 35;
		else if (choose == 2)
			forum->state = 5;
	}
	else if (forum->state == 34)
	{
		if (choose == 1)
			forum->state = 36;
		else if (choose == 2)
			forum->state = 5;
	}
}

void User::CheckPost(Forum *forum,string section)
{
	int PostId;
	cout << "输入您想查看的帖子,按-1返回" << endl;
	cin >> PostId;
	if (PostId == -1 && (forum->state == 10 || forum->state == 13))
	{
		forum->state = 2; return;
	}
		
	else if (PostId == -1 && (forum->state == 20 || forum->state == 23))
	{
		forum->state = 3; return;
	}
	int flag = 1;
	while (flag == 1)
	{
		if(PostId < forum->posts.size())
		{ 
			if(forum->posts[PostId]->section != section)
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
	cout << "输入您想进行的操作:" << endl;
	cout << "                  按 1 发送评论" << endl;
	cout << "                  按 2 删帖" << endl;
	cout << "                  按 3 返回上步操作" << endl;
	int choose;
	cin >> choose;
	while (choose != 1 && choose != 2 && choose != 3)
	{
		cout << "请输入合法选择" << endl;
		cin >> choose;
	}
	if (forum->state == 10)
	{
		forum->post = PostId;
		if (choose == 1)	
			forum->state = 11;
		else if (choose == 2)
			forum->state = 12;
		else if (choose == 3)
			forum->state = 6;
	}
	else if (forum->state == 13)
	{
		forum->post = PostId;
		if (choose == 1)	
			forum->state = 14;		
		else if (choose == 2)
			forum->state = 15;
		else if (choose == 3)
			forum->state = 7;
	}	
	else if (forum->state == 20)
	{
		forum->post = PostId;
		if (choose == 1)
			forum->state = 21;
		else if (choose == 2)
			forum->state = 22;
		else if (choose == 3)
			forum->state = 16;
	}
	else if (forum->state == 23)
	{
		forum->post = PostId;
		if (choose == 1)
			forum->state = 24;
		else if (choose == 2)
			forum->state = 25;
		else if (choose == 3)
			forum->state = 17;
	}
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
