#pragma once

#include "Ordinaryuser.h"
class Forum;
class Moderator :
	public Ordinaryuser
{
public:
	string section;//������İ�

	Moderator();

	Moderator(string username, string password, string id,string section);

	~Moderator();

	void DeletePost(int PostOrder, Forum *forum);//����������ɾ������

	string GetSection();			     //���ذ�������İ��

	void SetSection(string section);	     //���ð�������İ��

	friend ofstream& operator<<(ofstream &output, Moderator *moderator);//д�����ļ�

	friend ifstream& operator>>(ifstream &input, Moderator *moderator);//д�����ļ�
};

