#pragma once
#include <string>
#include <time.h>
#include <fstream>
using namespace std;
class Forum;

class Comment
{
private:
	string id;	//������id
	string content;	//��������
	string thistime;//����ʱ��
public:
	Comment();
	~Comment();
	
	Comment(string TempId, string TempContent);	//

	string GetTime();//�������ڵ�ʱ��

	string GetThistime();//��������ʱ��

	string GetUserId();//����������id

	string GetContent();//������������

	void SetThisTime(string ThisTime);//��������ʱ��

	void SetUserId(string UserId);//����������id

	void SetContent(string Content);//������������

	friend ofstream& operator<<(ofstream &output, Comment *comment);//д�뵽�ļ�
};

