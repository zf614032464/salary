#include"zhigong.h"
int main()
{
	zhigong stu[M];
	int m;
	read(stu,3);
	cout<<"欢迎来到职工工资管理系统，请输入按照命令提示，进行操作"<<endl;
	cout<<"输入1表示查询，2表示修改，3表示添加，4表示删除，5表示浏览 ，6表示保存 ，7表示退出"<<endl;
	cout<<"请输入你的指令"<<endl;

	while(cin>>m)//循环命令
	{
		switch(m){
		    case 1:find(stu);break;
			case 2:modify(stu);break;
			case 3:add(&stu[n]);break;
			case 4:del(stu);break;
			case 5:list(stu);break;
			case 6:wirte(stu);break;
			case 7:return 0;
			default:cout<<"此指令不存在，请重新输入"<<endl;
		}
	}

	return 0;
}