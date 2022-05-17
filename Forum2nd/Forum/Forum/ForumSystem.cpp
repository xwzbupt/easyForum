#include "Forum.h"
#include "Ordinaryuser.h"
#include "Moderator.h"
#include "Administrator.h"
#include "Anonymity.h"
#include <string>
#include <iostream>
using namespace std;
int main()
{
	Forum *forum = new Forum();
	int flag = 1;
	while (flag == 1)
	{
		switch (forum->state)
		{
		case 0:					//��ʼ����̳ϵͳ
			
			forum->ReadPost();
			if (forum->state == 37)break;
			forum->UserReadError();
			if (forum->state == 37)break;
			forum->ReadOrds();
			forum->ReadModerators();
			forum->ReadAllAdmins();
			if (forum->state == 37)break;
			forum->Menu();
			forum->state = 1;
			break;
		case 1:					//��¼
			forum->InputLoginInfo();
			break;
		case 2:					//��ͨ�û��˵�
			forum->MainMenu(forum);
			break;
		case 3:
			forum->MainMenu(forum);
			break;
		case 4:
			forum->AdminMenu(forum);
			break;
		case 5:
			forum->AnonyMenu(forum);
			break;
		case 6:					//��ͨ�û��鿴���1
			forum->NewOrdinaryuser->CheckSection("����ҹ��", forum);
			break;
		case 7:					//��ͨ�û��鿴���2
			forum->NewOrdinaryuser->CheckSection("����ѧϰ", forum);
			break;
		case 8:					//��ͨ�û��鿴������Ϣ
			forum->CheckOrdId(forum->NewOrdinaryuser);
			forum->state = 2;
			break;
		case 9:					//��ͨ�û�����
			forum->OrdSetPost(forum->NewOrdinaryuser);
			forum->SaveAllPosts();
			forum->state = 2;
			break;
		case 10:				//��ͨ�û��鿴���1���Ӽ����µ�����
			forum->NewOrdinaryuser->CheckPost(forum, "����ҹ��");
			break;
		case 11:				//��ͨ�û���������
			forum->OrdSetComment(forum->NewOrdinaryuser, forum->post);
			forum->SaveAllPosts();
			forum->state = 10;
			break;
		case 12:
			forum->OrdDeletePost(forum->NewOrdinaryuser, forum);
			forum->SaveAllPosts();
			break;
		case 13:
			forum->NewOrdinaryuser->CheckPost(forum, "����ѧϰ");
			break;
		case 14:
			forum->OrdSetComment(forum->NewOrdinaryuser, forum->post);
			forum->SaveAllPosts();
			forum->state = 13;
			break;
		case 15:
			forum->OrdDeletePost(forum->NewOrdinaryuser, forum);
			forum->SaveAllPosts();
			break;
		case 16:
			forum->NewModerator->CheckSection("����ҹ��", forum);
			break;
		case 17:
			forum->NewModerator->CheckSection("����ѧϰ", forum);
			break;
		case 18:
			forum->CheckModId(forum->NewModerator);
			forum->state = 3;
			break;
		case 19:
			forum->ModSetPost(forum->NewModerator);
			forum->SaveAllPosts();
			forum->state = 3;
			break;
		case 20:
			forum->NewModerator->CheckPost(forum, "����ҹ��");
			break;
		case 21:
			forum->ModSetComment(forum->NewModerator, forum->post);
			forum->SaveAllPosts();
			forum->state = 20;
			break;
		case 22:
			forum->ModDeletePost(forum->NewModerator, forum);
			forum->SaveAllPosts();
			break;
		case 23:
			forum->NewModerator->CheckPost(forum, "����ѧϰ");
			break;
		case 24:
			forum->ModSetComment(forum->NewModerator, forum->post);
			forum->SaveAllPosts();
			forum->state = 23;
			break;
		case 25:
			forum->ModDeletePost(forum->NewModerator, forum);
			forum->SaveAllPosts();
			break;
		case 26:
			forum->NewAdmin->CheckSection("����ҹ��", forum);
			break;
		case 27:
			forum->NewAdmin->CheckSection("����ѧϰ", forum);
			break;
		case 28:
			forum->CheckAdmin(forum->NewAdmin);
			forum->state = 4;
			break;
		case 29:
			forum->NewAdmin->OnlyCheckPost(forum, "����ҹ��");
			break;
		case 30:
			forum->NewAdmin->OnlyCheckPost(forum, "����ѧϰ");
			break;
		case 31:
			forum->SetModerator(forum->NewAdmin, forum);
			forum->SaveAllModerator();
			forum->SaveAllOrd();
			break;
		case 32:
			forum->DeleteModerator(forum->NewAdmin, forum);
			forum->SaveAllModerator();
			forum->SaveAllOrd();
			break;
		case 33:
			forum->NewAnonymity->CheckSection("����ҹ��", forum);
			break;
		case 34:
			forum->NewAnonymity->CheckSection("����ѧϰ", forum);
			break;
		case 35:
			forum->NewAnonymity->OnlyCheckPost(forum, "����ҹ��");
			break;
		case 36:
			forum->NewAnonymity->OnlyCheckPost(forum, "����ѧϰ");
			break;
		case 37:
			flag = 0;
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}