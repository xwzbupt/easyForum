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

	void DeletePost(int PostOrder, Forum *forum);

	string GetSection();

	~Moderator();
};

