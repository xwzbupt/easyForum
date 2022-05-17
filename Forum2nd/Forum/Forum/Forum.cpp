#include "Forum.h"
#include "User.h"
#include "Ordinaryuser.h"
#include "Moderator.h"
#include "Administrator.h"
#include "Anonymity.h"
Forum::Forum()
{
	this->count = 0;
	this->state = 0;
	this->post = 0;
	this->NewOrdinaryuser = NULL;
	this->NewModerator = NULL;
	this->NewAdmin = NULL;
}

Forum::~Forum()
{
}

Post* Forum::FindPost(int TempPostId)
{
	for (int i = 0; i<this->posts.size(); i++)
	{
		if (this->posts[i]->GetId() == TempPostId)
			return this->posts[i];
	}
	return NULL;
}

void Forum::Menu()
{
	cout << "*****************欢迎来到论坛系统*****************" << endl;
	cout << "Designed by Weiser" << endl;
}

void Forum::MainMenu(Forum *forum)
{
	cout << "选择你要进行的操作：" << endl;
	cout << "                  按 1 查看板块1的帖子" << endl;
	cout << "                  按 2 查看板块2的帖子" << endl;
	cout << "                  按 3 查看个人信息" << endl;
	cout << "                  按 4 发帖" << endl;
	cout << "                  按 5 注销账户" << endl;
	int choose;
	cin >> choose;
	if (forum->state == 2)
	{
		if (choose == 1)
			this->state = 6;
		else if (choose == 2)
			this->state = 7;
		else if (choose == 3)
			this->state = 8;
		else if (choose == 4)
			this->state = 9;
		else if (choose == 5)
		{
			this->state = 1;
			cout << "成功注销" << endl;
		}
		else
		{
			cout << "请输入合法的操作" << endl;
			this->state = 2;
			cin.clear();
			cin.ignore();
		}
	}
	else if (forum->state == 3)
	{
		if (choose == 1)
			this->state = 16;
		else if (choose == 2)
			this->state = 17;
		else if (choose == 3)
			this->state = 18;
		else if (choose == 4)
			this->state = 19;
		else if (choose == 5)
		{
			this->state = 1;
			cout << "成功注销" << endl;
		}
		else
		{
			cout << "请输入合法的操作" << endl;
			this->state = 3;
		}
	}

}

void Forum::AdminMenu(Forum *forum)
{
	cout << "欢迎您,尊敬的管理员" << endl;
	cout << "选择您要进行的操作：" << endl;
	cout << "                  按 1 查看板块1的帖子" << endl;
	cout << "                  按 2 查看板块2的帖子" << endl;
	cout << "                  按 3 查看个人信息" << endl;
	cout << "                  按 4 任命版主" << endl;
	cout << "                  按 5 撤职版主" << endl;
	cout << "                  按 6 注销" << endl;
	int choose;
	cin >> choose;
	if (choose == 1)
		this->state = 26;
	else if (choose == 2)
		this->state = 27;
	else if (choose == 3)
		this->state = 28;
	else if (choose == 4)
		this->state = 31;
	else if (choose == 5)
		this->state = 32;
	else if (choose == 6)
	{
		this->state = 1;
		cout << "成功注销" << endl;
	}
	else
	{
		cout << "请输入合法的操作" << endl;
		this->state = 4;
	}
	
}

void Forum::AnonyMenu(Forum *forum)
{
	cout << "欢迎您以匿名用户身份登录" << endl;
	cout << "选择您要进行的操作:" << endl;
	cout << "                 按 1 查看板块1的帖子" << endl;
	cout << "                 按 2 查看板块2的帖子" << endl;
	cout << "                 按 3 注销" << endl;
	string choose;
	cin >> choose;
	if (choose == "1")
		this->state = 33;
	else if(choose == "2")
		this->state = 34;
	else if(choose=="3")
	{
		this->state = 1;
		cout << "成功注销" << endl << endl;
	}
	else
	{
		cout << "请输入合法的操作" << endl;
		this->state = 5;
	}
}

void Forum::Init()
{
	//this->MakeOrdinaryUser("zhangsan", "123", "张三");
	//this->MakeOrdinaryUser("lisi", "12", "李四");
	//this->MakeOrdinaryUser("wangwu", "1", "王五");

	//this->MakeModerator("zhaosi", "123", "赵四", "宿舍夜聊");

	//this->MakeAdmin("liuba", "123", "刘八");
	//this->MakeAdmin("xuliu", "123", "徐六");

	this->ReadPost();
	this->ReadOrds();
	this->ReadModerators();
	this->ReadAllAdmins();
	/*
	this->ordinaryusers[0]->MakePost(
		this->ordinaryusers[0]->GetId(),
		"大家有什么推荐的好电影吗？",
		"最近没有什么好电影看，大家可以介绍一些好看的电影吗。。。",
		"宿舍夜聊", 
		this);

	this->ordinaryusers[1]->MakePost(
		this->ordinaryusers[1]->GetId(),
		"微机接口作业是什么？",
		"微机接口课没注意，不清楚作业是什么。。。",
		"生活学习", 
		this);

	this->ordinaryusers[0]->MakePost(
		this->ordinaryusers[0]->GetId(),
		"有什么好的推荐的电脑吗？",
		"想入手一款电脑，价位是10000-15000。。。",
		"宿舍夜聊", 
		this);

	this->ordinaryusers[1]->MakePost(
		this->ordinaryusers[1]->GetId(),
		"编译原理作业是什么？",
		"编译原理课没注意，不清楚作业是什么。。。",
		"生活学习", 
		this);

	this->ordinaryusers[2]->MakeComment(0, this->ordinaryusers[2]->GetId(), "《赎罪》", this);
	this->ordinaryusers[1]->MakeComment(0, this->ordinaryusers[1]->GetId(), "《影》", this);

	this->ordinaryusers[2]->MakeComment(1, this->ordinaryusers[2]->GetId(), "1,3,5,8题", this);
	this->ordinaryusers[1]->MakeComment(1, this->ordinaryusers[1]->GetId(), "2,4,5,8题", this);

	this->ordinaryusers[2]->MakeComment(2, this->ordinaryusers[2]->GetId(), "不知道", this);
	this->ordinaryusers[0]->MakeComment(2, this->ordinaryusers[0]->GetId(), "没了解过", this);

	this->ordinaryusers[2]->MakeComment(3, this->ordinaryusers[2]->GetId(), "没作业", this);
	this->ordinaryusers[0]->MakeComment(3, this->ordinaryusers[0]->GetId(), "老师没布置", this);
	*/
}

//登录函数
void Forum::login(string username, string password)
{
	for (int i = 0; i < this->ordinaryusers.size(); i++)
	{
		if (this->ordinaryusers[i]->GetUsername() == username &&
			this->ordinaryusers[i]->GetPassword() == password)
		{
			this->NewOrdinaryuser = this->ordinaryusers[i];
			this->state = 2;
			return;
		}
	}
	for (int i = 0; i < this->moderators.size(); i++)
	{
		if (this->moderators[i]->GetUsername() == username &&
			this->moderators[i]->GetPassword() == password)
		{
			this->NewModerator = this->moderators[i];
			this->state = 3;
			return;
		}
	}
	for (int i = 0; i < this->administrators.size(); i++)
	{
		if (this->administrators[i]->GetUsername() == username &&
			this->administrators[i]->GetPassword() == password)
		{
			this->NewAdmin = this->administrators[i];
			this->state = 4;
			return;
		}
	}
	if (username == "000"&&password == "000")
	{
		this->NewAnonymity = new Anonymity("000", "000", "匿名");
		this->state = 5;
		return;
	}
	cout << "账号或密码错误，请重新输入";
	this->state = 1;
}

void Forum::InputLoginInfo()
{
	cout << "000作为账号密码可匿名登录" << endl;
	cout << "请输入您的账号：" << endl;
	string username, password;
	cin >> username;
	cout << "请输入您的密码" << endl;
	cin >> password;
	this->login(username, password);
}

void Forum::OrdSetPost(Ordinaryuser *user)
{
	string PostTitle, PostContent, PostSection;
	cout << "您要在哪个板块下发帖(宿舍夜聊、学习生活):";
	cin >> PostSection;
	while (section != "宿舍夜聊" && section != "生活学习")
	{
		cout << "请输入合法的板块" << endl;
		cin >> section;
	}
	cout << "您的帖子题目:";
	cin >> PostTitle;
	cout << "您的帖子内容:";
	cin >> PostContent;
	user->MakePost(user->GetId(), PostTitle, PostContent, PostSection,this);
}

void Forum::ModSetPost(Moderator *user)
{
	string PostTitle, PostContent, PostSection;
	cout << "您要在哪个板块下发帖(宿舍夜聊、学习生活):";
	cin >> PostSection;
	while (section != "宿舍夜聊" && section != "生活学习")
	{
		cout << "请输入合法的板块" << endl;
		cin >> section;
	}
	cout << "您的帖子题目:";
	cin >> PostTitle;
	cout << "您的帖子内容:";
	cin >> PostContent;
	user->MakePost(user->GetId(), PostTitle, PostContent, PostSection, this);
}

void Forum::OrdSetComment(Ordinaryuser *user,int post)
{
	string Content;
	cout << "请输入评论的内容:";
	cin.clear();
	cin.ignore();
	getline(cin, Content);
	user->MakeComment(post, user->GetId(), Content, this);
	cout << "评论成功,";
}

void Forum::ModSetComment(Moderator *user, int post)
{
	string Content;
	cout << "请输入评论的内容:";
	cin.clear();
	cin.ignore();
	getline(cin, Content);
	user->MakeComment(post, user->GetId(), Content, this);
	cout << "评论成功,";
}

void Forum::OrdDeletePost(Ordinaryuser *OrdinaryUser,Forum *forum)
{
	if (OrdinaryUser->IsDeletePost(forum->post, forum) == 2)
		cout << "该帖子下已经有评论，不能删除" << endl;
	else if (OrdinaryUser->IsDeletePost(forum->post, forum) == 1)
		cout << "该帖子不是你发的，不能删除" << endl;
	else if (OrdinaryUser->IsDeletePost(forum->post, forum) == 0)
	{
		User *user = new Ordinaryuser(				//基类指针
			OrdinaryUser->GetUsername(), 
			OrdinaryUser->GetPassword(), 
			OrdinaryUser->GetId());

		user->DeletePost(forum->post, forum);			//基类指针指向子类方法
	}
		

	if (forum->state == 12)
		forum->state = 6;
	else if (forum->state == 15)
		forum->state = 7;
}

void Forum::ModDeletePost(Moderator *ModeratorUser, Forum *forum)
{
	if (ModeratorUser->section == forum->section)
	{
		User *user = new Moderator(				//基类指针
			ModeratorUser->GetUsername(), 
			ModeratorUser->GetPassword(), 
			ModeratorUser->GetId(), 
			ModeratorUser->GetSection());

		user->DeletePost(forum->post, forum);			//基类指针调用子类对象
		cout << "删除成功" << endl;
	}
	else
		cout << "您不是该版版主，无权删除" << endl;
	if (forum->state == 22)
		forum->state = 16;
	else if (forum->state == 25)
		forum->state = 17;
}

void Forum::MakeOrdinaryUser(string username, string password, string id)
{
	Ordinaryuser* neworduser = new Ordinaryuser(username, password, id);
	this->ordinaryusers.push_back(neworduser);
}

void Forum::MakeModerator(string username, string password, string id,string section)
{
	Moderator *newmod = new Moderator(username, password, id, section);
	this->moderators.push_back(newmod);
}

void Forum::MakeAdmin(string username, string password, string id)
{
	Administrator *NewAdmin = new Administrator(username, password, id);
	this->administrators.push_back(NewAdmin);
}

void Forum::MakeAnomy(string username, string password, string id)
{
	Anonymity *NewAnony = new Anonymity(username, password, id);
	this->anonymity.push_back(NewAnony);
}

void Forum::CheckOrdId(Ordinaryuser *user)
{
	cout << "您的等级是普通用户" << endl;
	user->CheckIdentification();	
}

void Forum::CheckModId(Moderator *user)
{
	cout << "您的等级是版主,且您管辖的版是:";
	cout << user->section << endl;
	user->CheckIdentification();
}

void Forum::CheckAdmin(Administrator *user)
{
	cout << "您是尊贵的管理员" << endl;
	user->CheckIdentification();
}

void Forum::SetModerator(Administrator* user,Forum *forum)
{
	cout << "普通用户有:" << endl;
	for (int i = 0; i < forum->ordinaryusers.size(); i++)
		cout << forum->ordinaryusers[i]->GetUsername() << endl;
	cout << "输入您想提拔成版主的用户,按-1返回上一步:" << endl;
	string username;
	string section;
	cin >> username;
	if (username == "-1")
	{
		forum->state = 4;
		return;
	}
		
	int flag = 1;
	int i;
	while (flag == 1)
	{
		for (i = 0; i < forum->ordinaryusers.size() && forum->ordinaryusers[i]->GetUsername() != username; i++);
		if (i == forum->ordinaryusers.size())
		{
			cout << "您的输入不合法，请重新输入要提拔的普通用户:" << endl;
			cin >> username;
		}
		else
		{
			flag = 0;
			this->NewOrdinaryuser = forum->ordinaryusers[i];
		}
	}
	cout << "您想将该用户设置什么板块的版主:" << endl;
	cin >> section;
	while (section != "宿舍夜聊" && section != "生活学习")
	{
		cout << "请输入合法的板块" << endl;
		cin >> section;
	}
	user->Appoint(username, section, forum);
	forum->state = 4;
}

void Forum::DeleteModerator(Administrator *user,Forum *forum)
{
	cout << "版主有:" << endl;
	for (int i = 0; i < forum->moderators.size(); i++)
	{
		cout << forum->moderators[i]->GetUsername();
		cout << " 管理的板块是: " << forum->moderators[i]->section << endl;
	}
	cout << "请输入您要撤销的版主,按-1返回上一步操作" << endl;
	string username;
	cin >> username;
	if (username == "-1")
	{
		forum->state = 4; return;
	}
		
	int flag = 1;
	int i;
	while (flag == 1)
	{
		for (i = 0; i < forum->moderators.size() && forum->moderators[i]->GetUsername() != username; i++);
		if (i == forum->moderators.size())
		{
			cout << "您的输入不合法，请重新输入要撤销的版主:" << endl;
			cin >> username;
		}
		else
		{
			flag = 0;
			this->NewModerator = forum->moderators[i];
		}
	}
	user->Cancel(username, forum);
	forum->state = 4;
}

void Forum::SaveAllPosts()
{
	string str("posts.txt");
	ofstream out(str.c_str(), ios::out | ios::trunc);
	for (int i = 0; i < this->posts.size(); i++)
		out << this->posts[i];
	out.close();
}

void Forum::SaveAllOrd()
{
	string str("ords.txt");
	ofstream out(str.c_str(), ios::out | ios::trunc);
	for (int i = 0; i < this->ordinaryusers.size(); i++)
		out << this->ordinaryusers[i];
	out.close();
}

void Forum::SaveAllModerator()
{
	string str("moderators.txt");
	ofstream out(str.c_str(), ios::out | ios::trunc);
	for (int i = 0; i < this->moderators.size(); i++)
		out << this->moderators[i];
	out.close();
}

void Forum::SaveAllAdmin()
{
	string str("admins.txt");
	ofstream out(str.c_str(), ios::out | ios::trunc);
	for (int i = 0; i < this->administrators.size(); i++)
		out << this->administrators[i];
	out.close();
}

void Forum::ReadPost()
{

	string str("posts.txt");
	ifstream in(str.c_str(), ios::in);
	char c;
	
	if (!in)
	{
		cout << "帖子文件不存在，数据库异常" << endl;
		this->state = 37;
		return;
	}
	c = in.get();
	if (in.eof())
	{
		cout << "帖子文件空，数据库异常" << endl;
	}
	else
	{
		in.putback(c);
		while (1)
		{
			Post *post = new Post;
			in >> post;

			this->posts.push_back(post);
			if (in.eof())
				break;
		}
	}

	in.close();
}

void Forum::ReadOrds()
{
	string str("ords.txt");
	ofstream out(str.c_str(), ios::out|ios::app);
	out.close();
	ifstream in(str.c_str(), ios::in);
	while (1)
	{

		Ordinaryuser *ord = new Ordinaryuser;
		in >> ord;
		if (in.eof())
			break;
		this->ordinaryusers.push_back(ord);

	}
	in.close();
}

void Forum::ReadModerators()
{
	string str("moderators.txt");
	ofstream out(str.c_str(), ios::out|ios::app);
	out.close();
	ifstream in(str.c_str(), ios::in);
	while (1)
	{
		
		Moderator *mod = new Moderator;
		in >> mod;
		if (in.eof())
			break;
		this->moderators.push_back(mod);
		
	}
	in.close();
}

void Forum::ReadAllAdmins()
{
	string str("admins.txt");
	ifstream in(str.c_str(), ios::in);
	char c;
	if (!in)
	{
		cout << "管理员数据文件不存在，数据库异常" << endl;
		this->state = 37;
		return;
	}
	c = in.get();
	if (in.eof())
	{
		
		cout << "管理员数据文件为空，数据库异常" << endl;
		this->state = 37;
		return;
	}
	else
	{
		in.putback(c);
		while (1)
		{
			Administrator *admin = new Administrator;
			in >> admin;
			if (in.eof())
				break;
			this->administrators.push_back(admin);

		}
	}
	in.close();
}

void Forum::UserReadError()
{
	string str1("ords.txt");
	string str2("moderators.txt");
	ifstream in1(str1.c_str(), ios::in|ios::_Nocreate);
	ifstream in2(str2.c_str(), ios::in|ios::_Nocreate);
	char ch1, ch2;
	if (!in1 && !in2)
	{
		cout << "普通用户和版主文件不能同时不存在，数据库异常" << endl;
		this->state = 37;
		return;
	}
	ch1 = in1.get();
	ch2 = in2.get();
	if (in1.eof() && in2.eof())
	{
		cout << "普通用户和版主文件不能同时为空，数据库异常" << endl;
		this->state = 37;
		in1.close();
		in2.close();
		return;
	}
	in1.putback(ch1);
	in2.putback(ch2);
	in1.close();
	in2.close();
}