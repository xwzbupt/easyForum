#pragma once
#include <iostream>
#include "Comment.h"
#include "Post.h"
#include <vector>
#include "User.h"
class Forum;

class Ordinaryuser :
	public User
{
public:
	Ordinaryuser();
	~Ordinaryuser();

	Ordinaryuser(string username, string password, string id);

	void MakeComment(int TempPostId, string TempId, string TempContent, Forum *forum);

	void MakePost(string TempUserId, string TempPostTitle, string TempContent, string TempSection, Forum *forum);
	
	//2�Ѿ�������,1û�����۵������Լ�����,0����ɾ��
	int IsDeletePost(int PostOrder, Forum *forum);

	void DeletePost(int PostOrder, Forum *forum);
};

