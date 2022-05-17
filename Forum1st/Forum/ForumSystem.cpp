//#include "Comment.h"
#include "Forum.h"
//#include "Post.h"
//#include "User.h"
#include "Ordinaryuser.h"
#include "Moderator.h"
#include "Administrator.h"
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
		case 0:					//初始化论坛系统
			forum->Init();
			forum->Menu();
			forum->state = 1;
			break;
		case 1:					//登录
			forum->InputLoginInfo();
			break;
		case 2:					//普通用户菜单
			forum->MainMenu(forum);
			break;
		case 3:
			forum->MainMenu(forum);
			break;
		case 4:
			forum->AdminMenu(forum);
			break;
		case 5:

			break;
		case 6:					//普通用户查看板块1
			forum->NewOrdinaryuser->CheckSection("宿舍夜聊", forum);
			break;

		case 7:					//普通用户查看板块2
			forum->NewOrdinaryuser->CheckSection("生活学习", forum);
			break;
		case 8:					//普通用户查看个人信息
			forum->CheckOrdId(forum->NewOrdinaryuser);
			forum->state = 2;
			break;
		case 9:					//普通用户发帖
			forum->OrdSetPost(forum->NewOrdinaryuser);
			forum->state = 2;
			break;
		case 10:				//普通用户查看板块1帖子及以下的评论
			forum->NewOrdinaryuser->CheckPost(forum, "宿舍夜聊");
			break;
		case 11:				//普通用户发送评论
			forum->OrdSetComment(forum->NewOrdinaryuser, forum->post);
			forum->state = 10;
			break;
		case 12:
			forum->OrdDeletePost(forum->NewOrdinaryuser, forum);
			break;
		case 13:
			forum->NewOrdinaryuser->CheckPost(forum, "生活学习");
			break;
		case 14:
			forum->OrdSetComment(forum->NewOrdinaryuser, forum->post);
			forum->state = 13;
			break;
		case 15:
			forum->OrdDeletePost(forum->NewOrdinaryuser, forum);
			break;
		case 16:
			forum->NewModerator->CheckSection("宿舍夜聊", forum);
			break;
		case 17:
			forum->NewModerator->CheckSection("生活学习", forum);
			break;
		case 18:
			forum->CheckModId(forum->NewModerator);
			forum->state = 3;
			break;
		case 19:
			forum->ModSetPost(forum->NewModerator);
			forum->state = 3;
			break;
		case 20:
			forum->NewModerator->CheckPost(forum, "宿舍夜聊");
			break;
		case 21:
			forum->ModSetComment(forum->NewModerator, forum->post);
			forum->state = 20;
			break;
		case 22:
			forum->ModDeletePost(forum->NewModerator, forum);
			break;
		case 23:
			forum->NewModerator->CheckPost(forum, "生活学习");
			break;
		case 24:
			forum->ModSetComment(forum->NewModerator, forum->post);
			forum->state = 23;
			break;
		case 25:
			forum->ModDeletePost(forum->NewModerator, forum);
			break;
		case 26:
			forum->NewAdmin->CheckSection("宿舍夜聊", forum);
			break;
		case 27:
			forum->NewAdmin->CheckSection("生活学习", forum);
			break;
		case 28:
			forum->CheckAdmin(forum->NewAdmin);
			forum->state = 4;
			break;
		case 29:
			forum->NewAdmin->OnlyCheckPost(forum, "宿舍夜聊");
			break;
		case 30:
			forum->NewAdmin->OnlyCheckPost(forum, "生活学习");
			break;
		case 31:
			forum->SetModerator(forum->NewAdmin, forum);
			break;
		case 32:
			forum->DeleteModerator(forum->NewAdmin, forum);
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}