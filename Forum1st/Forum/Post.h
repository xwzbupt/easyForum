#pragma once

#include <vector>
#include "Comment.h"
class Forum;

class Post
{
private:
	int id;//����id
	string userid;//������id
	string title;//���ӱ���
	string content;//��������
	string thistime;//����ʱ��
	string section;//���ڰ��
public:
	Post();
	~Post();

	vector <Comment*> comments;//��������

	friend class User;

	Post(string TempUserId, string TempTitle, string TempContent, string TempSection);

	void PushComment();

	Post FindPost(string id);

	void SetId(int id);

	int GetId();

	string GetPostUserid();//���ط�����

	string GetTime();

	string GetPostTitle();

	string GetPostContent();
};


