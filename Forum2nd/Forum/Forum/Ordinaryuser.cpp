#include "Ordinaryuser.h"
#include "Forum.h"


Ordinaryuser::Ordinaryuser()
{
	int i;
}



Ordinaryuser::Ordinaryuser(string username, string password, string id) :User(username, password, id)
{

}


Ordinaryuser::~Ordinaryuser()
{
}

void Ordinaryuser::MakeComment(int TempPostId, string TempId, string TempContent, Forum *forum)
{
	Comment *NewComment = new Comment(TempId, TempContent);				//新建一条评论
	forum->posts[TempPostId]->comments.push_back(NewComment);
}

void Ordinaryuser::MakePost(string TempUserId, string TempPostTitle, string TempContent, string TempSection, Forum *forum)
{
	Post *NewPost = new Post(TempUserId, TempPostTitle, TempContent, TempSection);   //新建一条帖子
	NewPost->SetId(++forum->count);							//设置这条post的id
	forum->posts.push_back(NewPost);						//将新建的帖子压入vector容器中
}

//2已经有评论,1没有评论但不是自己发的,0可以删除
int Ordinaryuser::IsDeletePost(int PostOrder, Forum *forum)
{
	Post* post = forum->posts[PostOrder];
	if (!post->comments.empty())//已经有评论
		return 2;
	else if (post->GetPostUserid().compare(this->GetId()) != 0)//没有评论但不是自己发的帖
		return 1;
	else//可以删除
		return 0;
}

void Ordinaryuser::DeletePost(int PostOrder, Forum *forum)
{
	if (IsDeletePost(PostOrder, forum))
	{
		forum->posts.erase(forum->posts.begin() + PostOrder);//删除帖子
		for (int i = 0; i < forum->posts.size(); i++)//对帖子的id重新进行分配
		{
			forum->posts[i]->SetId(i);
		}
		cout << "删除成功" << endl;
	}
	else cout << "不允许删除" << endl;
	
}