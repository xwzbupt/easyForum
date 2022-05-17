#pragma once
#include <string>
#include <sstream>
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
	char Islogin;                  // 判断是否为登录状态

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

	virtual string CheckSection(Forum *forum,string section);

	string CheckPost(Forum *forum,int id);

	void OnlyCheckPost(Forum *forum, string section);

	virtual void DeletePost(int PostOrder, Forum *forum);

	 friend ofstream& operator<<(ofstream &output, User *user);//写出到文件

	 friend ifstream& operator>> (ifstream &input, User *user); //
};





