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

	void DeletePost(int PostOrder, Forum *forum);

	string GetSection();

	~Moderator();
};

