#pragma once
#include <iostream>
#include <vector>
#include "Comment.h"
#include <fstream>
class Forum;

class Post
{
private:
	int id;		//����id
	string userid;	//������id
	string title;	//���ӱ���
	string content;	//��������
	string thistime;//����ʱ��
	string section;	//���ڰ��
public:
	Post();
	~Post();

	vector <Comment*> comments;					//��������

	friend class User;

	Post(string TempUserId, string TempTitle, string TempContent, string TempSection);

	void SetId(int id);

	int GetId();							//��������id

	string GetPostUserid();						//���ط�����

	string GetTime();						//���ط���ʱ��

	string GetPostTitle();						//����������Ŀ

	string GetPostContent();					//������������

	friend ifstream& operator>> (ifstream &input, Post *post);	//�����������ʹ�����д�����

	friend ofstream& operator<<(ofstream &output, Post *post);	//д�����ļ�
};


