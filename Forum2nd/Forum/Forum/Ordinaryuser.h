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

	void MakeComment(int TempPostId, string TempId, string TempContent, Forum *forum);//评论

	void MakePost(string TempUserId, string TempPostTitle, string TempContent, string TempSection, Forum *forum);//发帖
	
	
	int IsDeletePost(int PostOrder, Forum *forum);//是否可以被删除，返回2已经有评论,1没有评论但不是自己发的,0可以删除

	void DeletePost(int PostOrder, Forum *forum);//删除帖子
};

