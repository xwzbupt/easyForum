#pragma once
#include <string>
#include <iostream>
using namespace std;
class Forum;
class Comment;
class User
{
private:
	string id;			//用户id
	string username;		//用户名
	string password;		//密码

public:
	User();

	~User();

	User(string username, string password, string id);

	void Log_in(string username, string password, Forum *forum);	//登录函数

	void Log_out(Forum *forum);					//登出函数

	void CheckIdentification();					//查看个人信息

	string GetUsername();						//返回用户名

	string GetPassword();						//返回密码

	string GetId();							//返回id

	void SetUsername(string username);				//设置用户名

	void SetPassword(string password);				//设置密码

	void SetId(string id);						//设置id

	virtual void CheckSection(string section,Forum *forum);		//查看section板块

	void CheckPost(Forum *forum,string section);			//查看section中的帖子及其评论

	void OnlyCheckPost(Forum *forum, string section);		//只查看section中的帖子及其评论

	virtual void DeletePost(int PostOrder, Forum *forum);		//删除帖子

	friend ofstream& operator<<(ofstream &output, User *user);	//重载：输出到文件

	friend ifstream& operator>> (ifstream &input, User *user);	//重载：从文件读出到内存
};





