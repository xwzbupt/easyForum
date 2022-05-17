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

//����������ɾ�����ڵ�����
void Moderator::DeletePost(int PostOrder, Forum *forum)
{
	forum->posts.erase(forum->posts.begin() + PostOrder);//ɾ������
	for (int i = 0; i < forum->posts.size(); i++)//�����ӵ�id���½��з���
	{
		forum->posts[i]->SetId(i);
	}
}

string Moderator::GetSection()
{
	return this->section;
}