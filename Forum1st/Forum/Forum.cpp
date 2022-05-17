#include "Forum.h"
#include "User.h"
#include "Ordinaryuser.h"
#include "Moderator.h"
#include "Administrator.h"
Forum::Forum()
{
	this->count = 0;
	this->state = 0;
	this->post = 0;
	this->NewOrdinaryuser = NULL;
	this->NewModerator = NULL;
	this->NewAdmin = NULL;
}

Forum::~Forum()
{
}

Post* Forum::FindPost(int TempPostId)
{
	for (int i = 0; i<this->posts.size(); i++)
	{
		if (this->posts[i]->GetId() == TempPostId)
			return this->posts[i];
	}
	return NULL;
}

void Forum::Menu()
{
	cout << "*****************��ӭ������̳ϵͳ*****************" << endl;
	cout << "Designed by Weiser" << endl;
}

void Forum::MainMenu(Forum *forum)
{
	cout << "ѡ����Ҫ���еĲ�����" << endl;
	cout << "                  �� 1 �鿴���1������" << endl;
	cout << "                  �� 2 �鿴���2������" << endl;
	cout << "                  �� 3 �鿴������Ϣ" << endl;
	cout << "                  �� 4 ����" << endl;
	cout << "                  �� 5 ע���˻�" << endl;
	int choose;
	cin >> choose;
	if (forum->state == 2)
	{
		if (choose == 1)
			this->state = 6;
		else if (choose == 2)
			this->state = 7;
		else if (choose == 3)
			this->state = 8;
		else if (choose == 4)
			this->state = 9;
		else if (choose == 5)
		{
			this->state = 1;
			cout << "�ɹ�ע��" << endl;
		}
		else
		{
			cout << "������Ϸ��Ĳ���" << endl;
			this->state = 2;
			cin.clear();
			cin.ignore();
		}
	}
	else if (forum->state == 3)
	{
		if (choose == 1)
			this->state = 16;
		else if (choose == 2)
			this->state = 17;
		else if (choose == 3)
			this->state = 18;
		else if (choose == 4)
			this->state = 19;
		else if (choose == 5)
		{
			this->state = 1;
			cout << "�ɹ�ע��" << endl;
		}
		else
		{
			cout << "������Ϸ��Ĳ���" << endl;
			this->state = 3;
		}
	}

}

void Forum::AdminMenu(Forum *forum)
{
	cout << "��ӭ��,�𾴵Ĺ���Ա" << endl;
	cout << "ѡ����Ҫ���еĲ�����" << endl;
	cout << "                  �� 1 �鿴���1������" << endl;
	cout << "                  �� 2 �鿴���2������" << endl;
	cout << "                  �� 3 �鿴������Ϣ" << endl;
	cout << "                  �� 4 ��������" << endl;
	cout << "                  �� 5 ��ְ����" << endl;
	cout << "                  �� 6 ע��" << endl;
	int choose;
	cin >> choose;
	if (choose == 1)
		this->state = 26;
	else if (choose == 2)
		this->state = 27;
	else if (choose == 3)
		this->state = 28;
	else if (choose == 4)
		this->state = 31;
	else if (choose == 5)
		this->state = 32;
	else if (choose == 6)
	{
		this->state = 1;
		cout << "�ɹ�ע��" << endl;
	}
	else
	{
		cout << "������Ϸ��Ĳ���" << endl;
		this->state = 2;
	}
	
}

void Forum::Init()
{
	this->MakeOrdinaryUser("zhangsan", "123", "����");
	this->MakeOrdinaryUser("lisi", "12", "����");
	this->MakeOrdinaryUser("wangwu", "1", "����");

	this->MakeModerator("zhaosi", "123", "����", "����ҹ��");

	this->MakeAdmin("liuba", "123", "����");
	this->MakeAdmin("xuliu", "123", "����");

	this->ordinaryusers[0]->MakePost(
		this->ordinaryusers[0]->GetId(),
		"�����ʲô�Ƽ��ĺõ�Ӱ��",
		"���û��ʲô�õ�Ӱ������ҿ��Խ���һЩ�ÿ��ĵ�Ӱ�𡣡���",
		"����ҹ��", 
		this);

	this->ordinaryusers[1]->MakePost(
		this->ordinaryusers[1]->GetId(),
		"΢���ӿ���ҵ��ʲô��",
		"΢���ӿڿ�ûע�⣬�������ҵ��ʲô������",
		"����ѧϰ", 
		this);

	this->ordinaryusers[0]->MakePost(
		this->ordinaryusers[0]->GetId(),
		"��ʲô�õ��Ƽ��ĵ�����",
		"������һ����ԣ���λ��10000-15000������",
		"����ҹ��", 
		this);

	this->ordinaryusers[1]->MakePost(
		this->ordinaryusers[1]->GetId(),
		"����ԭ����ҵ��ʲô��",
		"����ԭ���ûע�⣬�������ҵ��ʲô������",
		"����ѧϰ", 
		this);

	this->ordinaryusers[2]->MakeComment(0, this->ordinaryusers[2]->GetId(), "�����", this);
	this->ordinaryusers[1]->MakeComment(0, this->ordinaryusers[1]->GetId(), "��Ӱ��", this);

	this->ordinaryusers[2]->MakeComment(1, this->ordinaryusers[2]->GetId(), "1,3,5,8��", this);
	this->ordinaryusers[1]->MakeComment(1, this->ordinaryusers[1]->GetId(), "2,4,5,8��", this);

	this->ordinaryusers[2]->MakeComment(2, this->ordinaryusers[2]->GetId(), "��֪��", this);
	this->ordinaryusers[0]->MakeComment(2, this->ordinaryusers[0]->GetId(), "û�˽��", this);

	this->ordinaryusers[2]->MakeComment(3, this->ordinaryusers[2]->GetId(), "û��ҵ", this);
	this->ordinaryusers[0]->MakeComment(3, this->ordinaryusers[0]->GetId(), "��ʦû����", this);
}

//��¼����
void Forum::login(string username, string password)
{
	for (int i = 0; i < this->ordinaryusers.size(); i++)
	{
		if (this->ordinaryusers[i]->GetUsername() == username &&
			this->ordinaryusers[i]->GetPassword() == password)
		{
			this->NewOrdinaryuser = this->ordinaryusers[i];
			this->state = 2;
			return;
		}
	}
	for (int i = 0; i < this->moderators.size(); i++)
	{
		if (this->moderators[i]->GetUsername() == username &&
			this->moderators[i]->GetPassword() == password)
		{
			this->NewModerator = this->moderators[i];
			this->state = 3;
			return;
		}
	}
	for (int i = 0; i < this->administrators.size(); i++)
	{
		if (this->administrators[i]->GetUsername() == username &&
			this->administrators[i]->GetPassword() == password)
		{
			this->NewAdmin = this->administrators[i];
			this->state = 4;
			return;
		}
	}
	cout << "�˺Ż������������������";
	this->state = 1;
}

void Forum::InputLoginInfo()
{
	cout << "�����������˺ţ�" << endl;
	string username, password;
	cin >> username;
	cout << "��������������" << endl;
	cin >> password;
	this->login(username, password);
}

void Forum::OrdSetPost(Ordinaryuser *user)
{
	string PostTitle, PostContent, PostSection;
	cout << "��Ҫ���ĸ�����·���(����ҹ�ġ�ѧϰ����):";
	cin >> PostSection;
	while (section != "����ҹ��" && section != "����ѧϰ")
	{
		cout << "������Ϸ��İ��" << endl;
		cin >> section;
	}
	cout << "����������Ŀ:";
	cin >> PostTitle;
	cout << "������������:";
	cin >> PostContent;
	user->MakePost(user->GetId(), PostTitle, PostContent, PostSection,this);
}

void Forum::ModSetPost(Moderator *user)
{
	string PostTitle, PostContent, PostSection;
	cout << "��Ҫ���ĸ�����·���(����ҹ�ġ�ѧϰ����):";
	cin >> PostSection;
	while (section != "����ҹ��" && section != "����ѧϰ")
	{
		cout << "������Ϸ��İ��" << endl;
		cin >> section;
	}
	cout << "����������Ŀ:";
	cin >> PostTitle;
	cout << "������������:";
	cin >> PostContent;
	user->MakePost(user->GetId(), PostTitle, PostContent, PostSection, this);
}

void Forum::OrdSetComment(Ordinaryuser *user,int post)
{
	string Content;
	cout << "���������۵�����:";
	cin.clear();
	cin.ignore();
	getline(cin, Content);
	user->MakeComment(post, user->GetId(), Content, this);
	cout << "���۳ɹ�,";
}

void Forum::ModSetComment(Moderator *user, int post)
{
	string Content;
	cout << "���������۵�����:";
	cin.clear();
	cin.ignore();
	getline(cin, Content);
	user->MakeComment(post, user->GetId(), Content, this);
	cout << "���۳ɹ�,";
}

void Forum::OrdDeletePost(Ordinaryuser *OrdinaryUser,Forum *forum)
{
	if (OrdinaryUser->IsDeletePost(forum->post, forum) == 2)
		cout << "���������Ѿ������ۣ�����ɾ��" << endl;
	else if (OrdinaryUser->IsDeletePost(forum->post, forum) == 1)
		cout << "�����Ӳ����㷢�ģ�����ɾ��" << endl;
	else if (OrdinaryUser->IsDeletePost(forum->post, forum) == 0)
	{
		User *user = new Ordinaryuser(				//����ָ��
			OrdinaryUser->GetUsername(), 
			OrdinaryUser->GetPassword(), 
			OrdinaryUser->GetId());

		user->DeletePost(forum->post, forum);			//����ָ��ָ�����෽��
	}
		

	if (forum->state == 12)
		forum->state = 6;
	else if (forum->state == 15)
		forum->state = 7;
}

void Forum::ModDeletePost(Moderator *ModeratorUser, Forum *forum)
{
	if (ModeratorUser->section == forum->section)
	{
		User *user = new Moderator(				//����ָ��
			ModeratorUser->GetUsername(), 
			ModeratorUser->GetPassword(), 
			ModeratorUser->GetId(), 
			ModeratorUser->GetSection());

		user->DeletePost(forum->post, forum);			//����ָ������������
		cout << "ɾ���ɹ�" << endl;
	}
	else
		cout << "�����Ǹð��������Ȩɾ��" << endl;
	if (forum->state == 22)
		forum->state = 16;
	else if (forum->state == 25)
		forum->state = 17;
}

void Forum::MakeOrdinaryUser(string username, string password, string id)
{
	Ordinaryuser* neworduser = new Ordinaryuser(username, password, id);
	this->ordinaryusers.push_back(neworduser);
}

void Forum::MakeModerator(string username, string password, string id,string section)
{
	Moderator *newmod = new Moderator(username, password, id, section);
	this->moderators.push_back(newmod);
}

void Forum::MakeAdmin(string username, string password, string id)
{
	Administrator *NewAdmin = new Administrator(username, password, id);
	this->administrators.push_back(NewAdmin);
}

void Forum::CheckOrdId(Ordinaryuser *user)
{
	cout << "���ĵȼ�����ͨ�û�" << endl;
	user->CheckIdentification();	
}

void Forum::CheckModId(Moderator *user)
{
	cout << "���ĵȼ��ǰ���,������Ͻ�İ���:";
	cout << user->section << endl;
	user->CheckIdentification();
}

void Forum::CheckAdmin(Administrator *user)
{
	cout << "�������Ĺ�����" << endl;
	user->CheckIdentification();
}

void Forum::SetModerator(Administrator* user,Forum *forum)
{
	cout << "��ͨ�û���:" << endl;
	for (int i = 0; i < forum->ordinaryusers.size(); i++)
		cout << forum->ordinaryusers[i]->GetUsername() << endl;
	cout << "����������γɰ������û�,��-1������һ��:" << endl;
	string username;
	string section;
	cin >> username;
	if (username == "-1")
		forum->state = 4;
	int flag = 1;
	int i;
	while (flag == 1)
	{
		for (i = 0; i < forum->ordinaryusers.size() && forum->ordinaryusers[i]->GetUsername() != username; i++);
		if (i == forum->ordinaryusers.size())
		{
			cout << "�������벻�Ϸ�������������Ҫ��ε���ͨ�û�:" << endl;
			cin >> username;
		}
		else
		{
			flag = 0;
			this->NewOrdinaryuser = forum->ordinaryusers[i];
		}
	}
	cout << "���뽫���û�����ʲô���İ���:" << endl;
	cin >> section;
	while (section != "����ҹ��" && section != "����ѧϰ")
	{
		cout << "������Ϸ��İ��" << endl;
		cin >> section;
	}
	user->Appoint(username, section, forum);
	forum->state = 4;
}

void Forum::DeleteModerator(Administrator *user,Forum *forum)
{
	cout << "������:" << endl;
	for (int i = 0; i < forum->moderators.size(); i++)
	{
		cout << forum->moderators[i]->GetUsername();
		cout << " ����İ����: " << forum->moderators[i]->section << endl;
	}
	cout << "��������Ҫ�����İ���,��-1������һ������" << endl;
	string username;
	cin >> username;
	if (username == "-1")
		forum->state = 4;
	int flag = 1;
	int i;
	while (flag == 1)
	{
		for (i = 0; i < forum->moderators.size() && forum->moderators[i]->GetUsername() != username; i++);
		if (i == forum->moderators.size())
		{
			cout << "�������벻�Ϸ�������������Ҫ�����İ���:" << endl;
			cin >> username;
		}
		else
		{
			flag = 0;
			this->NewModerator = forum->moderators[i];
		}
	}
	user->Cancel(username, forum);
	forum->state = 4;
}