#pragma once
#include <vector>
#include "Post.h"
#include <string>
using namespace std;

class Ordinaryuser;
class User;
class Moderator;
class Administrator;
class Anonymity;

class Forum
{
public:

	Forum();

	~Forum();

	int count;

	int state;//����״̬�Զ�����״̬

	Ordinaryuser* NewOrdinaryuser;

	Moderator* NewModerator;

	Administrator* NewAdmin;

	Anonymity* NewAnonymity;

	vector <Post*>  posts;	//������������

	int post;		//������ڲ鿴������id

	string section;		//������ڲ鿴�İ��

	vector <Ordinaryuser*> ordinaryusers;

	vector <Moderator*> moderators;

	vector <Administrator*> administrators;

	vector<Anonymity*> anonymity;

	Post* FindPost(int TempPostId);

	void Menu();

	void MainMenu(Forum *forum);

	void AdminMenu(Forum *forum);

	void AnonyMenu(Forum *forum);

	void Init();

	//��¼����
	void login(string username, string password);

	void InputLoginInfo();

	void MakeOrdinaryUser(string username, string password, string id);

	void MakeModerator(string username, string password, string id,string section);

	void MakeAdmin(string username, string password, string id);

	void MakeAnomy(string username, string password, string id);

	void CheckOrdId(Ordinaryuser *user);

	void CheckModId(Moderator *user);

	void CheckAdmin(Administrator *user);

	void OrdSetPost(Ordinaryuser *user);

	void ModSetPost(Moderator *user);

	void OrdSetComment(Ordinaryuser *user,int post);

	void ModSetComment(Moderator *user, int post);

	void OrdDeletePost(Ordinaryuser *user,Forum *forum);

	void ModDeletePost(Moderator *user, Forum *forum);

	void SetModerator(Administrator *user, Forum *forum);

	void DeleteModerator(Administrator *user, Forum *forum);

	void SaveAllPosts();

	void ReadPost();

	void SaveAllOrd();

	void SaveAllModerator();

	void ReadOrds();
	
	void ReadModerators();

	void SaveAllAdmin();

	void ReadAllAdmins();

	void UserReadError();
};

