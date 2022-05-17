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
	Comment *NewComment = new Comment(TempId, TempContent);				//�½�һ������
	forum->posts[TempPostId]->comments.push_back(NewComment);
}

void Ordinaryuser::MakePost(string TempUserId, string TempPostTitle, string TempContent, string TempSection, Forum *forum)
{
	Post *NewPost = new Post(TempUserId, TempPostTitle, TempContent, TempSection);   //�½�һ������
	NewPost->SetId(++forum->count);							//��������post��id
	forum->posts.push_back(NewPost);						//���½�������ѹ��vector������
}

//2�Ѿ�������,1û�����۵������Լ�����,0����ɾ��
int Ordinaryuser::IsDeletePost(int PostOrder, Forum *forum)
{
	Post* post = forum->posts[PostOrder];
	if (!post->comments.empty())//�Ѿ�������
		return 2;
	else if (post->GetPostUserid().compare(this->GetId()) != 0)//û�����۵������Լ�������
		return 1;
	else//����ɾ��
		return 0;
}

void Ordinaryuser::DeletePost(int PostOrder, Forum *forum)
{
	if (IsDeletePost(PostOrder, forum))
	{
		forum->posts.erase(forum->posts.begin() + PostOrder);//ɾ������
		for (int i = 0; i < forum->posts.size(); i++)//�����ӵ�id���½��з���
		{
			forum->posts[i]->SetId(i);
		}
		cout << "ɾ���ɹ�" << endl;
	}
	else cout << "������ɾ��" << endl;
	
}