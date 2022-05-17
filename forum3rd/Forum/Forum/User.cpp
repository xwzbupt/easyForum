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
	this->Islogin = 0;//û�е�¼
}

//��¼�˺�
void User::Log_in(string username, string password, Forum *forum)
{

}

//ע���˺�
void User::Log_out(Forum *forum)
{
	this->Islogin = 0;
}

//���user��id
string User::GetId()
{
	return this->id;
}

//���user��username
string User::GetUsername()
{
	return this->username;
}

//���user��password
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
	cout << "����id��:" << this->id << endl;
	cout << "����username��:" << this->username << endl;
	cout << "����password��:" << this->password << endl << endl;
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
		string str = "#����";
		if (forum->posts[i]->GetSection() == section)
		{
			str = str + to_string(i) + "#\n";
			str = str + "����ʱ��:" + forum->posts[i]->thistime + "\n";
			str = str + "������:" + forum->posts[i]->userid + "\n";
			str = str + "���ӱ���:" + forum->posts[i]->title + "\n";
			str = str + "��������:" + forum->posts[i]->content + "\n\n";
			sendstr = sendstr + str;
		}
	}
	sendstr = sendstr + "��������Ҫ���еĲ�������������Ų鿴���ӣ���-1����";
	return sendstr;
}

string User::CheckPost(Forum *forum,int id)
{
	string post = "#";
	string comment;
	string comments="\n";
	post = post + "����" + to_string(id) + "#\n";
	post = post + "����ʱ��:" + forum->posts[id]->thistime + "\n";
	post = post + "������:" + forum->posts[id]->userid + "\n";
	post = post + "���ӱ���:" + forum->posts[id]->title + "\n";
	post = post + "��������:" + forum->posts[id]->content + "\n";
	for (int i = 0; i < forum->posts[id]->comments.size(); i++)
	{
		comment= "-";
		comment = comment + "����" + to_string(i) + "-\n";
		comment = comment + "������:" + forum->posts[id]->comments[i]->GetUserId() + "\n";
		comment = comment + "����:" + forum->posts[id]->comments[i]->GetContent() + "\n";
		comment = comment + "����ʱ��:" + forum->posts[id]->comments[i]->GetThistime() + "\n";
		comments = comments + comment;
	}
	return post + comments + "\n��������˳�����һ��\n";
}

void User::OnlyCheckPost(Forum *forum, string section)
{
	int PostId;
	cout << "��������鿴������,��-1����";
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
				cout << "�����Ӳ��������鿴�İ�������������" << endl;
				cin >> PostId;
			}
			else
				flag = 0;
		}
		else
		{
			cout << "�����Ӳ����ڣ�����������" << endl;
			cin >> PostId;
		}
	}
	cout << endl;
	         
	cout << "--------------------����" << PostId << "--------------------" << endl;
	cout << "����ʱ��:" << forum->posts[PostId]->thistime << endl;
	cout << "������:" << forum->posts[PostId]->GetPostUserid() << endl;
	cout << "���ӱ���:" << forum->posts[PostId]->GetPostTitle() << endl;
	cout << "��������:" << forum->posts[PostId]->GetPostContent() << endl << endl;
	for (int i = 0; i < forum->posts[PostId]->comments.size(); i++)
	{
		cout << "#����" << i << "#" << endl;
		cout << "����ʱ��:" << forum->posts[PostId]->comments[i]->GetThistime() << endl;
		cout << "������:" << forum->posts[PostId]->comments[i]->GetUserId() << endl;
		cout << "��������:" << forum->posts[PostId]->comments[i]->GetContent() << endl << endl;
	}        
	cout << "-------------����" << PostId << "�������۴�ӡ���-------------" << endl << endl;
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
