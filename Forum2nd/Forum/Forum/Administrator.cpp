#include "Administrator.h"
#include "Forum.h"
#include "Ordinaryuser.h"
#include "Moderator.h"

Administrator::Administrator()
{
}


Administrator::~Administrator()
{
}

Administrator::Administrator(string username, string password, string id) :User(username, password, id)
{

}

void Administrator::Appoint(string username, string section,Forum *forum)
{
	for (int i = 0; i < forum->ordinaryusers.size(); i++)
	{
		if (forum->ordinaryusers[i]->GetUsername() == username)
		{
			forum->NewOrdinaryuser = forum->ordinaryusers[i];
			forum->MakeModerator(forum->NewOrdinaryuser->GetUsername(),
				forum->NewOrdinaryuser->GetPassword(),
				forum->NewOrdinaryuser->GetId(),
				section);
			cout << "任命成功!" << forum->NewOrdinaryuser->GetUsername() << "从普通用户升级为" << section << "板块的版主" << endl << endl;
			forum->ordinaryusers.erase(forum->ordinaryusers.begin() + i);		
		}
	}
}

void Administrator::Cancel(string username, Forum *forum)
{
	for (int i = 0; i < forum->moderators.size(); i++)
	{
		if (forum->moderators[i]->GetUsername() == username)
		{
			forum->NewModerator = forum->moderators[i];
			forum->MakeOrdinaryUser(forum->NewModerator->GetUsername(),
				forum->NewModerator->GetPassword(),
				forum->NewModerator->GetId());

			cout << "撤职成功!" << forum->NewModerator->GetUsername() << "用户从" << forum->NewModerator->section << "板块的版主降级为普通用户" << endl << endl;
			forum->moderators.erase(forum->moderators.begin() + i);
		}
	}
}

