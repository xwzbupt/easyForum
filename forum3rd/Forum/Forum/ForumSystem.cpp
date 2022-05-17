#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "winsock2.h"
#include <cstdlib>
#include "Forum.h"
#include "Ordinaryuser.h"
#include "Moderator.h"
#include "Administrator.h"
#include "Anonymity.h"
#pragma comment(lib, "WS2_32")
using namespace std;
int Login(SOCKET sockConnect,Forum *forum)
{
	char Username[1024];
	char Password[1024];
	string str = "�����������˺�:\n";
	send(sockConnect, &str[0], str.length() + 1, 0);
	if (recv(sockConnect, Username, 1024, 0) == -1)//TCP CLIENT�˹رպ󣬷������˵�recv��һֱ����-1����ʱ������˳��������recv��һֱ����
	{
		cout << "����ʧ�ܣ������ǿͻ����ѹر�" << endl;
		system("pause");
		return -1;
	}

	str = "��������������:\n";
	send(sockConnect, &str[0], str.length() + 1, 0);

	if (recv(sockConnect, Password, 1024, 0) == -1)//TCP CLIENT�˹رպ󣬷������˵�recv��һֱ����-1����ʱ������˳��������recv��һֱ����
	{
		cout << "����ʧ�ܣ������ǿͻ����ѹر�" << endl;
		system("pause");
		return -1;
	}

	string username = string(Username);
	string password = string(Password);
	for (int i = 0; i < forum->ordinaryusers.size(); i++)
	{
		if (forum->ordinaryusers[i]->GetUsername() == username &&
			forum->ordinaryusers[i]->GetPassword() == password)
		{
			forum->NewOrdinaryuser = forum->ordinaryusers[i];
			forum->user = new User(
				forum->NewOrdinaryuser->GetUsername(),
				forum->NewOrdinaryuser->GetPassword(),
				forum->NewOrdinaryuser->GetId());
			forum->state = 1;
			return 1;
		}
	}
	for (int i = 0; i < forum->moderators.size(); i++)
	{
		if (forum->moderators[i]->GetUsername() == username &&
			forum->moderators[i]->GetPassword() == password)
		{
			forum->NewModerator = forum->moderators[i];
			forum->user = new User(
				forum->NewModerator->GetUsername(),
				forum->NewModerator->GetPassword(),
				forum->NewModerator->GetId());
			forum->state = 1;
			return 1;
		}
	}
	for (int i = 0; i < forum->administrators.size(); i++)
	{
		if (forum->administrators[i]->GetUsername() == username &&
			forum->administrators[i]->GetPassword() == password)
		{
			forum->NewAdmin = forum->administrators[i];
			forum->user = new User(
				forum->NewAdmin->GetUsername(),
				forum->NewAdmin->GetPassword(),
				forum->NewAdmin->GetId());
			forum->state = 1;
			return 1;
		}
	}
	return 0;
}

int main()
{
	int flag = 1;
	char recvBuf[1024];
	Forum *forum = new Forum;
	//1.����SOCKET�⣬�汾Ϊ2.0
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	wVersionRequested = MAKEWORD(2, 0);
	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0)
	{
		cout << "Socket2.0��ʼ��ʧ�ܣ�Exit!";
		return 0;
	}
	if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 0)
	{
		WSACleanup();
		return 0;
	}

	//2.�����׽���,���ڼ���
	SOCKET sock;
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == INVALID_SOCKET)
	{
		cout << "Socket ����ʧ�ܣ�Exit!";
		return 0;
	}

	//3.��
	SOCKADDR_IN myaddr; //sockaddr_in�൱��sockaddr�ṹ
	memset(&myaddr, 0, sizeof(myaddr));//��ʼ��  ���� 
	myaddr.sin_family = AF_INET;//ֻ��Ϊ���ֵ
	myaddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);//��u_long��ת��Ϊ�����ֽ�����
	myaddr.sin_port = htons(7861);// ��u_short��ת��Ϊ�����ֽ�����

	bind(sock, (SOCKADDR*)&myaddr, sizeof(myaddr));//���׽���

						       //4.���ü���
	listen(sock, 5);

	//5.�ȴ�����������
	SOCKADDR_IN addrClient;
	int len = sizeof(SOCKADDR);
	//char buf[256] = "";
	int number = 0;
	cout << "�ȴ��ͻ�������..." << endl;
	while (true)
	{
		SOCKET sockConnect = accept(sock, (SOCKADDR*)&addrClient, &len);
		cout << "��IP��ַ��" << inet_ntoa(addrClient.sin_addr) << "�������ӡ�" << endl;

		while (true)
		{
			string str;
			string section;
			string post;
			int choose;
			int id;
			switch (forum->state)
			{
			case 0:
				forum->ReadPost();
				if (forum->state == 37)break;
				forum->UserReadError();
				if (forum->state == 37)break;
				forum->ReadOrds();
				forum->ReadModerators();
				forum->ReadAllAdmins();
				if (forum->state == 37)break;
				str = "------��ӭ������̳ϵͳ(���˺������Ϊ000����������ʽ��¼)------\nDesigned by Weiser\n����������س�����ϵͳ\n";
				send(sockConnect, &str[0], str.length() + 1, 0);
				if (recv(sockConnect, recvBuf, 1024, 0) == -1)//TCP CLIENT�˹رպ󣬷������˵�recv��һֱ����-1����ʱ������˳��������recv��һֱ����
				{
					cout << "����ʧ�ܣ������ǿͻ����ѹر�" << endl;
					system("pause");
					return -1;
				}
				memset(recvBuf, 0, sizeof(recvBuf));//�ѽ��յ��������
				forum->state = 1;
				break;
			case 1:
				if (Login(sockConnect, forum) == 1)
				{
					forum->state = 2;
				}
				else
				{
					str = "�˺Ż�������������������ַ��������µ�¼\n";
					send(sockConnect, &str[0], str.length() + 1, 0);
					if (recv(sockConnect, recvBuf, 1024, 0) == -1)//TCP CLIENT�˹رպ󣬷������˵�recv��һֱ����-1����ʱ������˳��������recv��һֱ����
					{
						cout << "����ʧ�ܣ������ǿͻ����ѹر�" << endl;
						system("pause");
						return -1;
					}
					forum->state = 1;
				}
				break;

			case 2:
				str = "��¼�ɹ�,��������Ҫ���еĲ�������1�鿴���1,��2�鿴���2,��3ע���˺�\n";
				send(sockConnect, &str[0], str.length() + 1, 0);
				if (recv(sockConnect, recvBuf, 1024, 0) == -1)//TCP CLIENT�˹رպ󣬷������˵�recv��һֱ����-1����ʱ������˳��������recv��һֱ����
				{
					cout << "����ʧ�ܣ������ǿͻ����ѹر�" << endl;
					system("pause");
					return -1;
				}
				choose = atoi(recvBuf);
				if (choose == 1)
					forum->state = 3;
				else if (choose == 2)
					forum->state = 4;
				else if (choose == 3)
					forum->state = 1;
				break;
			case 3:
				section = forum->user->CheckSection(forum, "NightChatting");
				send(sockConnect, &section[0], section.length() + 1, 0);
				if (recv(sockConnect, recvBuf, 1024, 0) == -1)//TCP CLIENT�˹رպ󣬷������˵�recv��һֱ����-1����ʱ������˳��������recv��һֱ����
				{
					cout << "����ʧ�ܣ������ǿͻ����ѹر�" << endl;
					system("pause");
					return -1;
				}
				id = atoi(recvBuf);
				if (id == -1)
					forum->state = 2;
				else
				{
					if (forum->posts[id]->GetSection() == "NightChatting")
						forum->state = 5;
					else
						forum->state = 3;
				}
				break;
			case 4:
				section = forum->user->CheckSection(forum, "Life&Study");
				send(sockConnect, &section[0], section.length() + 1, 0);
				if (recv(sockConnect, recvBuf, 1024, 0) == -1)//TCP CLIENT�˹رպ󣬷������˵�recv��һֱ����-1����ʱ������˳��������recv��һֱ����
				{
					cout << "����ʧ�ܣ������ǿͻ����ѹر�" << endl;
					system("pause");
					return -1;
				}
				id = atoi(recvBuf);
				if (id == -1)
					forum->state = 2;
				else
				{
					if (forum->posts[id]->GetSection() == "Life&Study")
						forum->state = 6;
					else
						forum->state = 4;
				}
				break;
			case 5:
				post = forum->user->CheckPost(forum, id);
				send(sockConnect, &post[0], post.length() + 1, 0);
				if (recv(sockConnect, recvBuf, 1024, 0) == -1)//TCP CLIENT�˹رպ󣬷������˵�recv��һֱ����-1����ʱ������˳��������recv��һֱ����
				{
					cout << "����ʧ�ܣ������ǿͻ����ѹر�" << endl;
					system("pause");
					return -1;
				}
				forum->state = 3;
				break;
			case 6:
				post = forum->user->CheckPost(forum, id);
				send(sockConnect, &post[0], post.length() + 1, 0);
				if (recv(sockConnect, recvBuf, 1024, 0) == -1)//TCP CLIENT�˹رպ󣬷������˵�recv��һֱ����-1����ʱ������˳��������recv��һֱ����
				{
					cout << "����ʧ�ܣ������ǿͻ����ѹر�" << endl;
					system("pause");
					return -1;
				}
				forum->state = 4;
				break;
			}
			
		}
		closesocket(sockConnect);
	}

	cout << "�������ر�" << endl;
	closesocket(sock);
	WSACleanup();
	return 0;
}




/*
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
			forum->NewOrdinaryuser->CheckSection("NightChatting", forum);
			break;
		case 7:					//��ͨ�û��鿴���2
			forum->NewOrdinaryuser->CheckSection("Lify", forum);
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
			forum->NewOrdinaryuser->CheckPost(forum, "NightChatting");
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
			forum->NewOrdinaryuser->CheckPost(forum, "Life&Study");
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
			forum->NewModerator->CheckSection("NightChatting", forum);
			break;
		case 17:
			forum->NewModerator->CheckSection("Life&Study", forum);
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
			forum->NewModerator->CheckPost(forum, "NightChatting");
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
			forum->NewModerator->CheckPost(forum, "Life&Study");
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
			forum->NewAdmin->CheckSection("NightChatting", forum);
			break;
		case 27:
			forum->NewAdmin->CheckSection("Life&Study", forum);
			break;
		case 28:
			forum->CheckAdmin(forum->NewAdmin);
			forum->state = 4;
			break;
		case 29:
			forum->NewAdmin->OnlyCheckPost(forum, "NightChatting");
			break;
		case 30:
			forum->NewAdmin->OnlyCheckPost(forum, "Life&Study");
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
			forum->NewAnonymity->CheckSection("NightChatting", forum);
			break;
		case 34:
			forum->NewAnonymity->CheckSection("Life&Study", forum);
			break;
		case 35:
			forum->NewAnonymity->OnlyCheckPost(forum, "NightChatting");
			break;
		case 36:
			forum->NewAnonymity->OnlyCheckPost(forum, "Life&Study");
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
*/