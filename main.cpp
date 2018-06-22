#include"zhigong.h"
int main()
{
    zhigong stu[M];
    int m;
    read(stu);
    cout<<"            欢迎来到职工工资管理系统，请按照命令提示输入，进行操作"<<endl;
    cout<<"                           输出提示信息及功能菜单"<<endl;
    cout<<"                            1.查询 2.修改 3.添加"<<endl;
    cout<<"                            4.删除 5.浏览 6.保存"<<endl;
    cout<<"                                   7.退出"<<endl;
    cout<<"                                请输入你的指令"<<endl;
	
    while(cin>>m)//循环命令
      {
        switch(m){
                  case 1:find(stu);break;//查询

                  case 2:modify(stu);break;//修改

                  case 3:add(stu);break;//添加

                  case 4:del(stu);break;//删除

                  case 5:list(stu);break;//浏览

                  case 6:wirte(stu);break;//保存

                  case 7:return 0;//退出

                  default:cout<<"此指令不存在，请重新输入"<<endl;
                 }

        cout<<"                           输出提示信息及功能菜单"<<endl;
        cout<<"                            1.查询 2.修改 3.添加"<<endl; 
        cout<<"                            4.删除 5.浏览 6.保存"<<endl;
        cout<<"                                   7.退出"<<endl;
        cout<<"                                 请输入你的指令"<<endl;
      }
     
   return 0;
}