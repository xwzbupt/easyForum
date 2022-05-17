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

//��¼�˺�
void User::Log_in(string username, string password, Forum *forum)
{

}

//ע���˺�
void User::Log_out(Forum *forum)
{

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

void User::CheckSection(string section,Forum *forum)
{
	forum->section = section;
	cout << "******************" << section << "******************" << endl;
	for (int i = 0; i < forum->posts.size(); i++)
	{
		if (forum->posts[i]->section == section)
		{
			cout << endl;
			cout << "#����" << i << "#" << endl;
			cout << "����ʱ��:" << forum->posts[i]->thistime << endl;
			cout << "������:" << forum->posts[i]->GetPostUserid() << endl;
			cout << "���ӱ���:" << forum->posts[i]->GetPostTitle() << endl;
			cout << "��������:" << forum->posts[i]->GetPostContent() << endl << endl;
		}
	}
	cout << "******************��ӡ���******************" << endl << endl;
	cout << "ѡ����Ҫ���еĲ���:" << endl;
	cout << "                 �� 1 �鿴�ð���µ�����һ������" << endl;
	cout << "                 �� 2 ������һ������" << endl;
	int choose;
	int choosen;
	cin >> choose;
	while (choose != 1 && choose != 2)
	{
		cout << "������Ϸ�ѡ��" << endl;
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
	cout << "��������鿴������,��-1����" << endl;
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
	cout << "����������еĲ���:" << endl;
	cout << "                  �� 1 ��������" << endl;
	cout << "                  �� 2 ɾ��" << endl;
	cout << "                  �� 3 �����ϲ�����" << endl;
	int choose;
	cin >> choose;
	while (choose != 1 && choose != 2 && choose != 3)
	{
		cout << "������Ϸ�ѡ��" << endl;
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
