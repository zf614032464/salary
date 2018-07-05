#include"zhigong.h"
/********************************************
Function: main()
Description: 作为主函数调用其他函数
Calls: 1.read() 2.write() 3.find() 4.list()
       5.modify() 6.add() 7.del() 
Return: 0
*********************************************/
int main()
{
    zhigong stu[M];
    char m[10];
    zhigong *head;
    read(stu);
    
	printf("       ###   欢迎使用广西民族大学软件与信息安全学院职工工资管理系统   ###\n");
    printf("       请选择<1-7>：                                                     \n");
	printf("       ==================================================================\n");
    printf("       |                      1.查询职工工资记录                        |\n");
    printf("       |                      2.修改职工工资记录                        |\n");
    printf("       |                      3.添加职工工资记录                        |\n");
    printf("       |                      4.删除职工工资记录                        |\n");
    printf("       |                      5.浏览职工工资记录                        |\n");
    printf("       |                      6.保存职工工资记录                        |\n");
    printf("       |                      7.退出系统                                |\n");
    printf("       ==================================================================\n");
    printf("       你的选择是：");
	
    while(scanf("%s",&m))//循环命令
      {
          system("cls");//清屏函数
          if(strcmp(m,"1")==0)
                  {
                    find(stu);//查询
                  }

          else if(strcmp(m,"2")==0)
                  {
                    modify(stu);//修改
                  }

          else if(strcmp(m,"3")==0)
                  {
                    add(stu);//添加
                  }

          else if(strcmp(m,"4")==0)
                  {
                    del(stu);//删除
                  }

          else if(strcmp(m,"5")==0)
                  {
                    list(stu);//浏览
                  }

         else if(strcmp(m,"6")==0)
                  {
                    wirte(stu);//保存
                  }

         else if(strcmp(m,"7")==0)
                  {
                    return 0;//退出
                  }

        else
             {
                printf("无此指令，请重新输入\n");
             }

         printf("       |                      1.查询职工工资记录                        |\n");
         printf("       |                      2.修改职工工资记录                        |\n");
         printf("       |                      3.添加职工工资记录                        |\n");
         printf("       |                      4.删除职工工资记录                        |\n");
         printf("       |                      5.浏览职工工资记录                        |\n");
         printf("       |                      6.保存职工工资记录                        |\n");
         printf("       |                      7.退出系统                                |\n");
         printf("       ==================================================================\n");
        
      }
     
   return 0;
}