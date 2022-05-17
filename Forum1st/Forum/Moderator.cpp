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