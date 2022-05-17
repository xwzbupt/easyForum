#pragma once
#include <string>
#include <iostream>
using namespace std;
class Forum;
class Comment;
class User
{
private:
	string id;
	string username;
	string password;
	char Islogin;                  // ÅÐ¶ÏÊÇ·ñÎªµÇÂ¼×´Ì¬

public:
	User();

	~User();

	User(string username, string password, string id);

	void Log_in(string username, string password, Forum *forum);

	void Log_out(Forum *forum);

	void CheckIdentification();

	string GetUsername();

	string GetPassword();

	string GetId();

	void SetUsername(string username);

	void SetPassword(string password);

	void SetId(string id);

	virtual void CheckSection(string section,Forum *forum);

	void CheckPost(Forum *forum,string section);

	void OnlyCheckPost(Forum *forum, string section);

	virtual void DeletePost(int PostOrder, Forum *forum);
};





