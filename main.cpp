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
    int m;
    zhigong *head;
    read(stu);
    head = createlist(stu);
	printf("       ###   欢迎使用广西民族大学软件与信息安全学院职工工资管理系统   ###\n");
    printf("       请选择<1-7>：                                                     \n");
	printf("       ==================================================================\n");
    printf("       =                      1.查询职工工资记录                        =\n");
    printf("       =                      2.修改职工工资记录                        =\n");
    printf("       =                      3.添加职工工资记录                        =\n");
    printf("       =                      4.删除职工工资记录                        =\n");
    printf("       =                      5.浏览职工工资记录                        =\n");
    printf("       =                      6.保存职工工资记录                        =\n");
    printf("       =                      7.退出系统                                =\n");
    printf("       ==================================================================\n");
    printf("       你的选择是：");
	
    while(scanf("%d",&m))//循环命令
      {
          system("cls");//清屏函数
		  switch(m){
                  case 1:find(stu); break;//查询

                  case 2:modify(stu); break;//修改

                  case 3:add(stu); break;//添加

                  case 4:del(stu); break;//删除

                  case 5:list(head); break;//浏览

                  case 6:wirte(stu); break;//保存

                  case 7:return 0;//退出

                  default:cout<<"此指令不存在，请重新输入"<<endl;
                 }

         printf("       =                      1.查询职工工资记录                        =\n");
         printf("       =                      2.修改职工工资记录                        =\n");
         printf("       =                      3.添加职工工资记录                        =\n");
         printf("       =                      4.删除职工工资记录                        =\n");
         printf("       =                      5.浏览职工工资记录                        =\n");
         printf("       =                      6.保存职工工资记录                        =\n");
         printf("       =                      7.退出系统                                =\n");
         printf("       ==================================================================\n");
        
      }
     
   return 0;
}