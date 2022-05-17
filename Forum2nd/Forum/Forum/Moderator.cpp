#include "Moderator.h"
#include "Ordinaryuser.h"
#include "Forum.h"

Moderator::Moderator()
{

}

Moderator::Moderator(string username, string password, string id,string section) 
{
	this->SetUsername(username);
	this->SetPassword(password);
	this->SetId(id);
	this->section = section;
}


Moderator::~Moderator()
{
}

//版主无条件删除版内的帖子
void Moderator::DeletePost(int PostOrder, Forum *forum)
{
	forum->posts.erase(forum->posts.begin() + PostOrder);//删除帖子
	for (int i = 0; i < forum->posts.size(); i++)//对帖子的id重新进行分配
	{
		forum->posts[i]->SetId(i);
	}
}

string Moderator::GetSection()
{
	return this->section;
}

void Moderator::SetSection(string section)
{
	this->section = section;
}

ofstream& operator<<(ofstream &output, Moderator *moderator)
{
	output << moderator->GetUsername() << endl;
	output << moderator->GetPassword() << endl;
	output << moderator->GetId() << endl;
	output << moderator->section << endl;
	return output;
}

ifstream& operator>>(ifstream &input, Moderator *moderator)
{
	string line;

		getline(input, line);
		moderator->SetUsername(line);
		getline(input, line);
		moderator->SetPassword(line);
		getline(input, line);
		moderator->SetId(line);
		getline(input, line);
		moderator->SetSection(line);

	return input;
}