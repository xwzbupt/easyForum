#pragma once

#include "Ordinaryuser.h"
class Forum;
class Moderator :
	public Ordinaryuser
{
public:
	string section;//所管理的版

	Moderator();

	Moderator(string username, string password, string id,string section);

	~Moderator();

	void DeletePost(int PostOrder, Forum *forum);

	string GetSection();

	void SetSection(string section);

	friend ofstream& operator<<(ofstream &output, Moderator *moderator);//写出到文件

	friend ifstream& operator>>(ifstream &input, Moderator *moderator);//写出到文件
};

