#pragma once

#include <vector>
#include "Comment.h"
class Forum;

class Post
{
private:
	int id;//帖子id
	string userid;//发帖者id
	string title;//帖子标题
	string content;//帖子内容
	string thistime;//发帖时间
	string section;//所在版块
public:
	Post();
	~Post();

	vector <Comment*> comments;//帖子容器

	friend class User;

	Post(string TempUserId, string TempTitle, string TempContent, string TempSection);

	void PushComment();

	Post FindPost(string id);

	void SetId(int id);

	int GetId();

	string GetPostUserid();//返回发帖者

	string GetTime();

	string GetPostTitle();

	string GetPostContent();
};


