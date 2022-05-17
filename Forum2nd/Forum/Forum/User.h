#pragma once
#include <string>
#include <iostream>
using namespace std;
class Forum;
class Comment;
class User
{
private:
	string id;			//�û�id
	string username;		//�û���
	string password;		//����

public:
	User();

	~User();

	User(string username, string password, string id);

	void Log_in(string username, string password, Forum *forum);	//��¼����

	void Log_out(Forum *forum);					//�ǳ�����

	void CheckIdentification();					//�鿴������Ϣ

	string GetUsername();						//�����û���

	string GetPassword();						//��������

	string GetId();							//����id

	void SetUsername(string username);				//�����û���

	void SetPassword(string password);				//��������

	void SetId(string id);						//����id

	virtual void CheckSection(string section,Forum *forum);		//�鿴section���

	void CheckPost(Forum *forum,string section);			//�鿴section�е����Ӽ�������

	void OnlyCheckPost(Forum *forum, string section);		//ֻ�鿴section�е����Ӽ�������

	virtual void DeletePost(int PostOrder, Forum *forum);		//ɾ������

	friend ofstream& operator<<(ofstream &output, User *user);	//���أ�������ļ�

	friend ifstream& operator>> (ifstream &input, User *user);	//���أ����ļ��������ڴ�
};





