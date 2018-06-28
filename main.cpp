/********************************************
Function: main()
Description: 作为主函数调用其他函数
Calls: 1.read() 2.write() 3.find() 4.list()
       5.modify() 6.add() 7.del() 
Return: 0
*********************************************/
#include"zhigong.h"
int main()
{
    zhigong stu[M];
    int m;
    read(stu);
    printf("       ******欢迎来到职工工资管理系统，请按照命令提示输入，进行操作******\n");
    printf("       *                  输出提示信息及功能菜单                        *\n");
    printf("       *                   1.查询 2.修改 3.添加                         *\n");
    printf("       *                   4.删除 5.浏览 6.保存                         *\n");
    printf("       *                          7.退出                                *\n");
    printf("       *********************请输入你的指令*******************************\n");
	
    while(scanf("%d",&m))//循环命令
      {
          system("cls");//清屏函数
		  switch(m){
                  case 1:find(stu); break;//查询

                  case 2:modify(stu); break;//修改

                  case 3:add(stu); break;//添加

                  case 4:del(stu); break;//删除

                  case 5:list(stu); break;//浏览

                  case 6:wirte(stu); break;//保存

                  case 7:return 0;//退出

                  default:cout<<"此指令不存在，请重新输入"<<endl;
                 }

        printf("       *                  输出提示信息及功能菜单                        *\n");
        printf("       *                   1.查询 2.修改 3.添加                         *\n");
        printf("       *                   4.删除 5.浏览 6.保存                         *\n");
        printf("       *                          7.退出                                *\n");
        printf("       *********************请输入你的指令*******************************\n");
        
      }
     
   return 0;
}