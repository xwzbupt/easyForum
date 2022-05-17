#pragma once
#include "User.h"
class Anonymity :
	public User
{
public:
	Anonymity();

	Anonymity(string username, string password, string id);

	~Anonymity();
};

