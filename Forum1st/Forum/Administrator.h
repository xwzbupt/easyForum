#pragma once
#include "User.h"
class Forum;
class Administrator :
	public User
{
public:

	Administrator();

	Administrator(string username,string password,string id);

	~Administrator();

	void Appoint(string username, string section,Forum *forum);

	void Cancel(string username, Forum*forum);

};

