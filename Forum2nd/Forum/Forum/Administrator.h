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

	void Appoint(string username, string section,Forum *forum);//任命版主

	void Cancel(string username, Forum*forum);		   //撤职版主

};

