#pragma once

#include "Ordinaryuser.h"
class Forum;
class Moderator :
	public Ordinaryuser
{
public:
	string section;//������İ�

	Moderator();

	Moderator(string username, string password, string id,string section);

	~Moderator();

	void DeletePost(int PostOrder, Forum *forum);

	string GetSection();

	void SetSection(string section);

	friend ofstream& operator<<(ofstream &output, Moderator *moderator);//д�����ļ�

	friend ifstream& operator>>(ifstream &input, Moderator *moderator);//д�����ļ�
};

