/********************************************
Copyright(C),2018-2021,guangximinzhudaxue
Author:zhangfeng  Version:头文件  Date:2018.6.24
Description:头文件
Version:头文件
Funtion List:
1.void read(zhigong zggz[]) 文件写入
2.void wirte(zhigong zggz[])文件保存
3.void find(zhigong zggz[]) 查询职工信息
4.void list(zhigong zggz[]) 浏览职工信息
5.void modify(zhigong zggz[])修改职工信息
6.void del(zhigong zggz[]) 删除职工信息
7.void add(zhigong *p) 增加职工信息
8.void grsds(zhigong *p1)计算个人所得税
9.void add_money(zhigong *p1)计算应发工资
10.void add_wages(zhigong *p1)计算实发工资
zhigong *createlist(zhigong zggz[])//创建有n个元素的双向链表
*********************************************/
#include<iostream>
#include<stdio.h>
#include<cstring>
#include<fstream>
#include<string>
#include<string.h>
#include<stdarg.h>
#include<stdlib.h>
#include<malloc.h>
const int M=100;//定义常量
int static n;//定义静态变量 
using namespace std;

struct zhigong{//定义结构体
    char id[11];//工号
    char name[11];//姓名
    float gangwei;//岗位工资
    float xinji;//薪级工资
    float zhiwu;//职务津贴
    float jixiao;//绩效工资
    float yingfa;//应发工资
    float geren;//个人所得税
    float shifa;//实发工资
    struct zhigong *prior;//指向前驱结点
    struct zhigong *next; //指向后继结点
};
/********************************************
Function: read()
Description: 作为子函数写入数据到数组中
Calls: close()
Calls By: main()
Input: 数组作为形参，地址作为实参
Other: 无返回值
*********************************************/

void read(zhigong *head)    //文件读取
{
    fstream f("gz.dat",ios::in|ios::binary);//以二进制方式打开一个输入文件
    /*if(!f)
      {
         printf("Cannot open file\n");
         abort();
      }*/

    zhigong *p,*q;
    head->prior = head;
    head->next = head;
    p = head;
    for(int i=0; i < 100; i++)
      {

          if(!f.eof())//判断文件是否到达末尾 
             {
                n++;//职工人数加1
                q = (zhigong *)malloc(sizeof(zhigong));
                f>>q->id>>q->name>>q->gangwei>>q->xinji>>q->zhiwu>>q->jixiao>>q->yingfa>>q->geren>>q->shifa;
                p->next = q;           //p的下节点指向q
		        head->prior = q;       //head的前节点指向q
		        q->prior = p;          //q的前节点指向p
                q->next = head;        //q的下节点指向head
                p = q;
                //f>>zggz[i].id>>zggz[i].name>>zggz[i].gangwei>>zggz[i].xinji>>zggz[i].zhiwu>>zggz[i].jixiao>>zggz[i].yingfa>>zggz[i].geren>>zggz[i].shifa;
              }//从文件读取数据到双向链表数据域里 

           else
               {
                  break;
               }	
      }

    p->prior->next=p->next;
    p->next->prior=p->prior;   
    n = n - 1;               //eof()函数多执行了一次
    f.close();
   
 }

/********************************************
Function: createlist()
Description: 作为子函数创建双向链表
Calls By: main()
Input: 数组作为形参，地址作为实参
Other: 地址为返回值
*********************************************/
/*zhigong *createlist(zhigong zggz[])//创建有n个元素的双向链表 
{
    zhigong *head, *p, *q;
    head = (zhigong *)malloc(sizeof(zhigong));//为头部指针分配内存空间
	head->prior = head;
    head->next = head;
    p = head;
    for(int i=0;i<n;i++)//创建n个双向链表元素
    {
        q = (zhigong *)malloc(sizeof(zhigong));
		strcpy(q->id ,zggz[i].id);//把数组中的数据分配到双向链表数据域中
		strcpy(q->name,zggz[i].name);
		q->gangwei=zggz[i].gangwei;
		q->xinji=zggz[i].xinji;
		q->zhiwu=zggz[i].zhiwu;
		q->jixiao=zggz[i].jixiao;
		q->yingfa=zggz[i].yingfa;
		q->geren=zggz[i].geren;
		q->shifa=zggz[i].shifa;
        p->next = q;           //p的下节点指向q
		head->prior = q;       //head的前节点指向q
		q->prior = p;          //q的前节点指向p
        q->next = head;        //q的下节点指向head
        p = q;                 //q赋值给p
    }
    return head;
}*/


/********************************************
Function: write()
Description: 作为子函数读取数据到文件中
Calls: close()
Calls By: main()
Input: 数组作为形参，地址作为实参
Other: 无返回值
*********************************************/

void wirte(zhigong *p)
{                               //文件保存
    if(n<1)
        {
            printf("职工人数为0，无法写入\n");
            return;
        }

    fstream f("gz.dat",ios::out|ios::binary);//以二进制方式打开一个输出文件
    if(!f)
       {
         printf("Cannot open file\n");
         abort();
       }

    zhigong *q=p;
    q=q->next;
    while(q!=p)
      {
         if(!f.eof())//判断文件是否到达末尾 
            {
               f<<q->id<<" "<<q->name<<" "<<q->gangwei<<" "<<q->xinji<<" "<<q->zhiwu<<" "<<q->jixiao<<" "<<q->yingfa<<" "<<q->geren<<" "<<q->shifa<<" ";
               q=q->next;
            }
      }
    f.close();
 
    printf("       =====================文件已保存，请你进行下一步命令=================\n");
}

/********************************************
Function: add_money()
Description: 作为子函数计算应发工资
Calls By:1. find() 2.modify() 3.add() 4.list()
Input: 指针作为形参，地址作为实参
Other: 无返回值
*********************************************/
void add_money(zhigong *p1)									//计算应发工资       
{
        p1->yingfa = p1->gangwei + p1->xinji + p1->zhiwu + p1->jixiao;
}

/********************************************
Function: grsds()
Description: 作为子函数计算个人所得税
Calls By:1. find() 2.modify() 3.add() 4.list()
Input: 指针作为形参，地址作为实参
Other: 无返回值
*********************************************/

void grsds(zhigong *p1)//计算个人所得税函数
{
        if(p1->yingfa <= 500)                //应发工资不超过500
            {
                p1->geren = p1->yingfa*0.05;
            }

        else if(p1->yingfa > 500 && p1->yingfa <= 2000)                   //应发工资在500到2000
            {
                p1->geren = (p1->yingfa - 500)*0.1 + 500*0.05;
            }

        else if(p1->yingfa > 2000 && p1->yingfa <= 5000)                                //应发工资在2000到5000
            {
                p1->geren = (p1->yingfa - 2000)*0.15 + 1500*0.1 + 500*0.05;
            }

        else if(p1->yingfa > 5000 && p1->yingfa <= 20000)                                          //应发工资在5000到20000
            {
                p1->geren = (p1->yingfa - 5000)*0.2 + 3000*0.15 + 1500*0.1 + 500*0.05;
            }

        else if(p1->yingfa > 20000 && p1->yingfa <= 40000)                                                     //应发工资在20000到40000
            {
                p1->geren = (p1->yingfa - 20000)*0.25 + 15000*0.2 + 3000*0.15 + 1500*0.1 + 500*0.05;
            }

        else if(p1->yingfa > 40000 && p1->yingfa <= 60000)                                                                 //应发工资在40000到60000
            {
                p1->geren = (p1->yingfa - 40000)*0.3 + 20000*0.25 + 15000*0.2 + 3000*0.15 + 1500*0.1 + 500*0.05;
            }

        else if(p1->yingfa > 60000 && p1->yingfa <= 80000)                                                                            //应发工资在60000到80000
            {
                p1->geren = (p1->yingfa - 60000)*0.35 + 20000*0.3 + 20000*0.25 + 15000*0.2 + 3000*0.15 + 1500*0.1 + 500*0.05;
            }

        else if(p1->yingfa > 80000 && p1->yingfa <= 100000)                                                                                   //应发工资在80000到100000
            {
                p1->geren = (p1->yingfa - 80000)*0.4 + 20000*0.35 + 20000*0.3 + 20000*0.25 + 15000*0.2 + 3000*0.15 + 1500*0.1 + 500*0.05;
            }

        else                                                                                                                      //应发工资超过100000
            {
                p1->geren = (p1->yingfa - 100000)*0.45 + 20000*0.4 + 20000*0.35 + 20000*0.3 + 20000*0.25 + 15000*0.2 + 3000*0.15 + 1500*0.1 + 500*0.05;
            }
}

/********************************************
Function: add_wages()
Description: 作为子函数计算应发工资
Calls By:1. find() 2.modify() 3.add() 4.list()
Input: 指针作为形参，地址作为实参
Other: 无返回值
*********************************************/

void add_wages(zhigong *p1)									//计算实发工资	     
{
        p1->shifa = p1->yingfa - p1->geren;
}


/********************************************
Function: find()
Description: 作为子函数查询职工信息
Calls By: main()
Calls：1.add_money（） 2.grsds（） 3.add_wages（）
Input: 指针作为形参，地址作为实参
Other: 无返回值
*********************************************/

void find(zhigong *p)
{                             //查询函数
    char gohao[11];//定义字符串
    int i;
    printf("       ====================请输入你要查询的工号或姓名===================\n");//通过工号或姓名进行查找
    scanf("%s",gohao);

    zhigong *q=p;
    q=q->next;
    while(q!=p)
        {
          if(strcmp(q->id,gohao)==0 || strcmp(q->name,gohao)==0)
             {
               printf("此职工信息为：\n");
               add_money(q);//更正职工应发工资
               grsds(q);//更正职工个人所得税
               add_wages(q);//更正职工实发工资
               printf("工号：%s\t姓名：%s\t岗位工资：%.2f\n",q->id,q->name,q->gangwei);
               printf("薪级工资：%.2f\t职务津贴：%.2f\t绩效工资：%.2f\n",q->xinji,q->zhiwu,q->jixiao);
               printf("应发工资：%.2f\t个人所得税：%.2f\t实发工资：%.2f\n",q->yingfa,q->geren,q->shifa);
               printf("       =====================请你进行下一步命令！========================\n");
               return;
             }
          else
              {
                q=q->next;
              }
        }

    printf("系统中找不到此职工信息，请你核实你输入的工号或姓名是否有错，请重新输入查询命令再进行查询\n");
    return;
}

/********************************************
Function: list()
Description: 作为子函数浏览职工信息
Calls By: main()
Input: 指针作为形参，地址作为实参
Other: 无返回值
*********************************************/

void list(zhigong *head)
{                           //浏览函数
	
    zhigong *p;
    p = head;
    p = p->next;
    printf("职工信息为：\n");
  
    while(p!=head)
       {
         add_money(p);       //更正职工应发工资
         grsds(p);           //更正职工个人所得税
         add_wages(p);       //更正职工实发工资
         printf("工号：%s\t姓名：%s\t岗位工资：%.2f\n",p->id,p->name,p->gangwei);
         printf("薪级工资：%.2f\t职务津贴：%.2f\t绩效工资：%.2f\n",p->xinji,p->zhiwu,p->jixiao);
         printf("应发工资：%.2f\t个人所得税：%.2f\t实发工资：%.2f\n",p->yingfa,p->geren,p->shifa);
         printf("\n");
		 p=p->next;          //使p指向下一个节点
       }

    printf("       =====================请你进行下一步命令！========================\n");
}

/********************************************
Function: modify()
Description: 作为子函数修改职工信息
Calls：1.add_money（） 2.grsds（） 3.add_wages（）4.write()
Calls By: main()
Input: 数组作为形参，地址作为实参
Other: 无返回值
*********************************************/

void modify(zhigong *p)
{                            //修改函数
    char gohao[11];//定义字符串
    int i, k, m;
    zhigong a;
    zhigong *b=p;
    printf("       ====================请输入你要查询的工号或姓名===================\n");//通过工号或姓名进行查找
    scanf("%s",gohao);

    zhigong *q=p;
    q=q->next;
    while(q!=p)
        {
          if(strcmp(q->id,gohao)==0 || strcmp(q->name,gohao)==0)
             {
               printf("职工信息为：\n");//输出职工修改信息前的信息
               printf("工号：%s\t姓名：%s\t岗位工资：%.2f\n",q->id,q->name,q->gangwei);
               printf("薪级工资：%.2f\t职务津贴：%.2f\t绩效工资：%.2f\n",q->xinji,q->zhiwu,q->jixiao);
               printf("应发工资：%.2f\t个人所得税：%.2f\t实发工资：%.2f\n",q->yingfa,q->geren,q->shifa);

               printf("       ================输入1表示确认修改，输入0表示放弃修改===============\n");
               scanf("%d",&k);
               if(k == 1)//确认修改的操作
                 {
                   printf("请重新录入职工工号、姓名、岗位工资、薪级工资、职务津贴、绩效工资\n");
                   printf("工号：");
                   scanf("%s",&a.id);//工号
                   printf("姓名：");
                   scanf("%s",&a.name);//姓名
                   printf("岗位工资：");
                   scanf("%f",&a.gangwei);//岗位工资
                   printf("薪级工资：");
                   scanf("%f",&a.xinji);//薪级工资
                   printf("职务津贴：");
                   scanf("%f",&a.zhiwu);//职务津贴
                   printf("绩效工资：");
                   scanf("%f",&a.jixiao);//绩效工资
                   strcpy(q->id , a.id);
                   strcpy(q->name , a.name);
                   q->gangwei = a.gangwei;
                   q->xinji = a.xinji;
                   q->zhiwu = a.zhiwu;
                   q->jixiao = a.jixiao;
                   add_money(q);//职工应发工资
                   grsds(q);//职工个人所得税
                   add_wages(q);//职工实发工资

                   printf("职工信息修改后为：\n");//输出职工修改信息后的信息
                   printf("工号：%s\t姓名：%s\t岗位工资：%.2f\n",q->id,q->name,q->gangwei);
                   printf("薪级工资：%.2f\t职务津贴：%.2f\t绩效工资：%.2f\n",q->xinji,q->zhiwu,q->jixiao);
                   printf("应发工资：%.2f\t个人所得税：%.2f\t实发工资：%.2f\n",q->yingfa,q->geren,q->shifa);
                   printf("       ***************职工信息已修改，请你进行下一步命令！***************\n");

                   printf("       ================输入1表示确认保存，输入0表示放弃保存===============\n");
                   scanf("%d",&m);

                   if(m == 1)
                       {
                          wirte(b);//确认保存的操作
                          printf("       =====================请你进行下一步命令！========================\n");
                          return;
                       }

                   else
                       {
                          printf("       =============职工信息已修改，请你进行下一步命令！=================\n");//放弃保存后的操作
                          return;
                       }
                 }

              else
                  {
                     printf("       =====================请你进行下一步命令！========================\n");//不修改后的操作
                     return;
                  }
             }
          else
               {
                q=q->next;
               }
        }

    printf("系统中找不到此职工信息，请你核实你输入的工号或姓名是否有错，请重新输入查询命令再进行查询\n");

    printf("       =====================请你进行下一步命令！========================\n");
}

/********************************************
Function: del()
Description: 作为子函数删除职工信息
Calls:write()
Calls By: main()
Input: 数组作为形参，地址作为实参
Other: 无返回值
*********************************************/

void del(zhigong *head)  //删除函数
{
    char gohao[11];//定义字符串
    int i, j, k, t;
    zhigong *p = head,*a=head, *q;
    p = p->next;
    printf("       ====================请输入你要查询的工号或姓名===================\n");//通过工号或姓名进行查找
    scanf("%s",gohao);

    while(p!=head)
        {
            if(strcmp(p->id,gohao)==0 || strcmp(p->name,gohao)==0)
                {
                   printf("删除的职工信息为：\n");//输出职工修改信息前的信息
                   printf("工号：%s\t姓名：%s\t岗位工资：%.2f\n",p->id,p->name,p->gangwei);
                   printf("薪级工资：%.2f\t职务津贴：%.2f\t绩效工资：%.2f\n",p->xinji,p->zhiwu,p->jixiao);
                   printf("应发工资：%.2f\t个人所得税：%.2f\t实发工资：%.2f\n",p->yingfa,p->geren,p->shifa);

                   printf("       ================输入1表示确认删除，输入0表示放弃删除===============\n");
                   scanf("%d", &k);
                   if(k==1)
                       {
                          q = p->next;
                          (p->prior)->next = p->next;
                          (p->next)->prior = p->prior;
                          free(p);
                          p = q;
                   n=n-1;
                   printf("       ================输入1表示确认保存，输入0表示放弃保存===============\n");
                   scanf("%d", &t);
                   if(t == 1)
                        {
                           wirte(a);//确认删除的操作
                           return;
                        }

                   else
                        {
                           printf("       =============职工信息已修改，请你进行下一步命令！================\n");//放弃删除后的操作
                           return;
                        }

                       }

                   else
                       {
                          printf("       =====================请你进行下一步命令！========================\n");
                          return;
                       }
                }
           else
                {
                  p=p->next;
                }
        }

    printf("系统中找不到此职工信息，请你核实你输入的工号或姓名是否有错，请重新输入查询命令再进行查询\n");//未找到职工信息后的操作
    return;
}

/********************************************
Function: add()
Description: 作为子函数增加职工信息
Calls：1.add_money（） 2.grsds（） 3.add_wages（）4.write()
Calls By: main()
Input: 数组作为形参，地址作为实参
Other: 无返回值
*********************************************/

void add(zhigong *head)//增加函数
{
    int k;
	zhigong *p=head,*t=head,*q,a;
    p=p->next;
    if(n == 100)
        {
           printf("       ==============职工人数已满，不能添加职工了===============\n");
           printf("       =====================请你输入其他命令====================\n");
           return;
        }

    else
        {
          
          printf("       =======================请你录入用户信息===========================\n");//通过工号或姓名进行查找
          printf("工号：");
          scanf("%s", &a.id);//工号
          while(p!=head)//判断工号相同的不能添加
              { 
                  if(strcmp(p->id,a.id)==0)
                    {
                      printf("       ================工号已存在，请重新输入命令========================\n");
                      return;
				     }
                  else
                     {
                       p=p->next;
                     }
              }
          printf("姓名：");
          scanf("%s",&a.name);//姓名
          printf("岗位工资：");
          scanf("%f",&a.gangwei);//岗位工资
          printf("薪级工资：");
          scanf("%f",&a.xinji);//薪级工资
          printf("职务津贴：");
          scanf("%f",&a.zhiwu);//职务津贴
          printf("绩效工资：");
          scanf("%f",&a.jixiao);//绩效工资
          add_money(&a);//应发工资
          grsds(&a);//个人所得税
          add_wages(&a);//实发工资
          n = n + 1;//职工人数加1
          q = (zhigong *)malloc(sizeof(zhigong));
		  strcpy(q->id ,a.id);//把数组中的数据分配到双向链表数据域中
		  strcpy(q->name,a.name);
		  q->gangwei=a.gangwei;
		  q->xinji=a.xinji;
		  q->zhiwu=a.zhiwu;
		  q->jixiao=a.jixiao;
		  q->yingfa=a.yingfa;
		  q->geren=a.geren;
		  q->shifa=a.shifa;
          p->prior->next= q;           //p的前驱节点的后指针指向q
		  head->prior = q;             //head的前节点指向q
		  q->prior = p->prior;          //q的前节点指向p
          q->next = head;              //q的下节点指向head 
          printf("职工信息为：\n");
          printf("工号：%s\t姓名：%s\t岗位工资：%.2f\n",q->id,q->name,q->gangwei);
          printf("薪级工资：%.2f\t职务津贴：%.2f\t绩效工资：%.2f\n",q->xinji,q->zhiwu,q->jixiao);
          printf("应发工资：%.2f\t个人所得税：%.2f\t实发工资：%.2f\n",q->yingfa,q->geren,q->shifa);

          printf("       ================输入1表示确认增加，输入0表示放弃增加===============\n");
          scanf("%d",&k);
          if(k == 1)
                {
                    
                    wirte(t);//确认增加的操作
                    return;
                }

          else
                {
                    printf("       =====================请你进行下一步命令！========================\n");//放弃增加后的操作
                    return;
                }
    //printf("       =====================请你进行下一步命令！========================\n");
        }
}


/********************************************
Function: main()
Description: 作为主函数调用其他函数
Calls: 1.read() 2.write() 3.find() 4.list()
       5.modify() 6.add() 7.del() 
Return: 0
*********************************************/
int main()
{
    //zhigong zggz[M];
    char m[M];
    zhigong *head;
    head = (zhigong *)malloc(sizeof(zhigong));//为头部指针分配内存空间
    read(head);
    //head = createlist(zggz);
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
                    find(head);//查询
                  }

          else if(strcmp(m,"2")==0)
                  {
                    modify(head);//修改
                  }

          else if(strcmp(m,"3")==0)
                  {
                    add(head);//添加
                  }

          else if(strcmp(m,"4")==0)
                  {
                    del(head);//删除
                  }

          else if(strcmp(m,"5")==0)
                  {
                    list(head);//浏览
                  }

         else if(strcmp(m,"6")==0)
                  {
                    wirte(head);//保存
                  }

         else if(strcmp(m,"7")==0)
                  {
                    return 0;//退出
                  }

        else
             {
                printf("       ================无此指令，请重新输入=============================\n");
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
