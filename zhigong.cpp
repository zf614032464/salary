/********************************************
Copyright(C),2018-2021,guangximinzhudaxue
Author:zhangfeng  Version:ͷ�ļ�  Date:2018.6.24
Description:ͷ�ļ�
Version:ͷ�ļ�
Funtion List:
1.void read(zhigong zggz[]) �ļ�д��
2.void wirte(zhigong zggz[])�ļ�����
3.void find(zhigong zggz[]) ��ѯְ����Ϣ
4.void list(zhigong zggz[]) ���ְ����Ϣ
5.void modify(zhigong zggz[])�޸�ְ����Ϣ
6.void del(zhigong zggz[]) ɾ��ְ����Ϣ
7.void add(zhigong *p) ����ְ����Ϣ
8.void grsds(zhigong *p1)�����������˰
9.void add_money(zhigong *p1)����Ӧ������
10.void add_wages(zhigong *p1)����ʵ������
zhigong *createlist(zhigong zggz[])//������n��Ԫ�ص�˫������
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
const int M=100;//���峣��
int static n;//���徲̬���� 
using namespace std;

struct zhigong{//����ṹ��
    char id[11];//����
    char name[11];//����
    float gangwei;//��λ����
    float xinji;//н������
    float zhiwu;//ְ�����
    float jixiao;//��Ч����
    float yingfa;//Ӧ������
    float geren;//��������˰
    float shifa;//ʵ������
    struct zhigong *prior;//ָ��ǰ�����
    struct zhigong *next; //ָ���̽��
};
/********************************************
Function: read()
Description: ��Ϊ�Ӻ���д�����ݵ�������
Calls: close()
Calls By: main()
Input: ������Ϊ�βΣ���ַ��Ϊʵ��
Other: �޷���ֵ
*********************************************/

void read(zhigong *head)    //�ļ���ȡ
{
    fstream f("gz.dat",ios::in|ios::binary);//�Զ����Ʒ�ʽ��һ�������ļ�
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

          if(!f.eof())//�ж��ļ��Ƿ񵽴�ĩβ 
             {
                n++;//ְ��������1
                q = (zhigong *)malloc(sizeof(zhigong));
                f>>q->id>>q->name>>q->gangwei>>q->xinji>>q->zhiwu>>q->jixiao>>q->yingfa>>q->geren>>q->shifa;
                p->next = q;           //p���½ڵ�ָ��q
		        head->prior = q;       //head��ǰ�ڵ�ָ��q
		        q->prior = p;          //q��ǰ�ڵ�ָ��p
                q->next = head;        //q���½ڵ�ָ��head
                p = q;
                //f>>zggz[i].id>>zggz[i].name>>zggz[i].gangwei>>zggz[i].xinji>>zggz[i].zhiwu>>zggz[i].jixiao>>zggz[i].yingfa>>zggz[i].geren>>zggz[i].shifa;
              }//���ļ���ȡ���ݵ�˫�������������� 

           else
               {
                  break;
               }	
      }

    p->prior->next=p->next;
    p->next->prior=p->prior;   
    n = n - 1;               //eof()������ִ����һ��
    f.close();
   
 }

/********************************************
Function: createlist()
Description: ��Ϊ�Ӻ�������˫������
Calls By: main()
Input: ������Ϊ�βΣ���ַ��Ϊʵ��
Other: ��ַΪ����ֵ
*********************************************/
/*zhigong *createlist(zhigong zggz[])//������n��Ԫ�ص�˫������ 
{
    zhigong *head, *p, *q;
    head = (zhigong *)malloc(sizeof(zhigong));//Ϊͷ��ָ������ڴ�ռ�
	head->prior = head;
    head->next = head;
    p = head;
    for(int i=0;i<n;i++)//����n��˫������Ԫ��
    {
        q = (zhigong *)malloc(sizeof(zhigong));
		strcpy(q->id ,zggz[i].id);//�������е����ݷ��䵽˫��������������
		strcpy(q->name,zggz[i].name);
		q->gangwei=zggz[i].gangwei;
		q->xinji=zggz[i].xinji;
		q->zhiwu=zggz[i].zhiwu;
		q->jixiao=zggz[i].jixiao;
		q->yingfa=zggz[i].yingfa;
		q->geren=zggz[i].geren;
		q->shifa=zggz[i].shifa;
        p->next = q;           //p���½ڵ�ָ��q
		head->prior = q;       //head��ǰ�ڵ�ָ��q
		q->prior = p;          //q��ǰ�ڵ�ָ��p
        q->next = head;        //q���½ڵ�ָ��head
        p = q;                 //q��ֵ��p
    }
    return head;
}*/


/********************************************
Function: write()
Description: ��Ϊ�Ӻ�����ȡ���ݵ��ļ���
Calls: close()
Calls By: main()
Input: ������Ϊ�βΣ���ַ��Ϊʵ��
Other: �޷���ֵ
*********************************************/

void wirte(zhigong *p)
{                               //�ļ�����
    if(n<1)
        {
            printf("ְ������Ϊ0���޷�д��\n");
            return;
        }

    fstream f("gz.dat",ios::out|ios::binary);//�Զ����Ʒ�ʽ��һ������ļ�
    if(!f)
       {
         printf("Cannot open file\n");
         abort();
       }

    zhigong *q=p;
    q=q->next;
    while(q!=p)
      {
         if(!f.eof())//�ж��ļ��Ƿ񵽴�ĩβ 
            {
               f<<q->id<<" "<<q->name<<" "<<q->gangwei<<" "<<q->xinji<<" "<<q->zhiwu<<" "<<q->jixiao<<" "<<q->yingfa<<" "<<q->geren<<" "<<q->shifa<<" ";
               q=q->next;
            }
      }
    f.close();
 
    printf("       =====================�ļ��ѱ��棬���������һ������=================\n");
}

/********************************************
Function: add_money()
Description: ��Ϊ�Ӻ�������Ӧ������
Calls By:1. find() 2.modify() 3.add() 4.list()
Input: ָ����Ϊ�βΣ���ַ��Ϊʵ��
Other: �޷���ֵ
*********************************************/
void add_money(zhigong *p1)									//����Ӧ������       
{
        p1->yingfa = p1->gangwei + p1->xinji + p1->zhiwu + p1->jixiao;
}

/********************************************
Function: grsds()
Description: ��Ϊ�Ӻ��������������˰
Calls By:1. find() 2.modify() 3.add() 4.list()
Input: ָ����Ϊ�βΣ���ַ��Ϊʵ��
Other: �޷���ֵ
*********************************************/

void grsds(zhigong *p1)//�����������˰����
{
        if(p1->yingfa <= 500)                //Ӧ�����ʲ�����500
            {
                p1->geren = p1->yingfa*0.05;
            }

        else if(p1->yingfa > 500 && p1->yingfa <= 2000)                   //Ӧ��������500��2000
            {
                p1->geren = (p1->yingfa - 500)*0.1 + 500*0.05;
            }

        else if(p1->yingfa > 2000 && p1->yingfa <= 5000)                                //Ӧ��������2000��5000
            {
                p1->geren = (p1->yingfa - 2000)*0.15 + 1500*0.1 + 500*0.05;
            }

        else if(p1->yingfa > 5000 && p1->yingfa <= 20000)                                          //Ӧ��������5000��20000
            {
                p1->geren = (p1->yingfa - 5000)*0.2 + 3000*0.15 + 1500*0.1 + 500*0.05;
            }

        else if(p1->yingfa > 20000 && p1->yingfa <= 40000)                                                     //Ӧ��������20000��40000
            {
                p1->geren = (p1->yingfa - 20000)*0.25 + 15000*0.2 + 3000*0.15 + 1500*0.1 + 500*0.05;
            }

        else if(p1->yingfa > 40000 && p1->yingfa <= 60000)                                                                 //Ӧ��������40000��60000
            {
                p1->geren = (p1->yingfa - 40000)*0.3 + 20000*0.25 + 15000*0.2 + 3000*0.15 + 1500*0.1 + 500*0.05;
            }

        else if(p1->yingfa > 60000 && p1->yingfa <= 80000)                                                                            //Ӧ��������60000��80000
            {
                p1->geren = (p1->yingfa - 60000)*0.35 + 20000*0.3 + 20000*0.25 + 15000*0.2 + 3000*0.15 + 1500*0.1 + 500*0.05;
            }

        else if(p1->yingfa > 80000 && p1->yingfa <= 100000)                                                                                   //Ӧ��������80000��100000
            {
                p1->geren = (p1->yingfa - 80000)*0.4 + 20000*0.35 + 20000*0.3 + 20000*0.25 + 15000*0.2 + 3000*0.15 + 1500*0.1 + 500*0.05;
            }

        else                                                                                                                      //Ӧ�����ʳ���100000
            {
                p1->geren = (p1->yingfa - 100000)*0.45 + 20000*0.4 + 20000*0.35 + 20000*0.3 + 20000*0.25 + 15000*0.2 + 3000*0.15 + 1500*0.1 + 500*0.05;
            }
}

/********************************************
Function: add_wages()
Description: ��Ϊ�Ӻ�������Ӧ������
Calls By:1. find() 2.modify() 3.add() 4.list()
Input: ָ����Ϊ�βΣ���ַ��Ϊʵ��
Other: �޷���ֵ
*********************************************/

void add_wages(zhigong *p1)									//����ʵ������	     
{
        p1->shifa = p1->yingfa - p1->geren;
}


/********************************************
Function: find()
Description: ��Ϊ�Ӻ�����ѯְ����Ϣ
Calls By: main()
Calls��1.add_money���� 2.grsds���� 3.add_wages����
Input: ָ����Ϊ�βΣ���ַ��Ϊʵ��
Other: �޷���ֵ
*********************************************/

void find(zhigong *p)
{                             //��ѯ����
    char gohao[11];//�����ַ���
    int i;
    printf("       ====================��������Ҫ��ѯ�Ĺ��Ż�����===================\n");//ͨ�����Ż��������в���
    scanf("%s",gohao);

    zhigong *q=p;
    q=q->next;
    while(q!=p)
        {
          if(strcmp(q->id,gohao)==0 || strcmp(q->name,gohao)==0)
             {
               printf("��ְ����ϢΪ��\n");
               add_money(q);//����ְ��Ӧ������
               grsds(q);//����ְ����������˰
               add_wages(q);//����ְ��ʵ������
               printf("���ţ�%s\t������%s\t��λ���ʣ�%.2f\n",q->id,q->name,q->gangwei);
               printf("н�����ʣ�%.2f\tְ�������%.2f\t��Ч���ʣ�%.2f\n",q->xinji,q->zhiwu,q->jixiao);
               printf("Ӧ�����ʣ�%.2f\t��������˰��%.2f\tʵ�����ʣ�%.2f\n",q->yingfa,q->geren,q->shifa);
               printf("       =====================���������һ�����========================\n");
               return;
             }
          else
              {
                q=q->next;
              }
        }

    printf("ϵͳ���Ҳ�����ְ����Ϣ�������ʵ������Ĺ��Ż������Ƿ��д������������ѯ�����ٽ��в�ѯ\n");
    return;
}

/********************************************
Function: list()
Description: ��Ϊ�Ӻ������ְ����Ϣ
Calls By: main()
Input: ָ����Ϊ�βΣ���ַ��Ϊʵ��
Other: �޷���ֵ
*********************************************/

void list(zhigong *head)
{                           //�������
	
    zhigong *p;
    p = head;
    p = p->next;
    printf("ְ����ϢΪ��\n");
  
    while(p!=head)
       {
         add_money(p);       //����ְ��Ӧ������
         grsds(p);           //����ְ����������˰
         add_wages(p);       //����ְ��ʵ������
         printf("���ţ�%s\t������%s\t��λ���ʣ�%.2f\n",p->id,p->name,p->gangwei);
         printf("н�����ʣ�%.2f\tְ�������%.2f\t��Ч���ʣ�%.2f\n",p->xinji,p->zhiwu,p->jixiao);
         printf("Ӧ�����ʣ�%.2f\t��������˰��%.2f\tʵ�����ʣ�%.2f\n",p->yingfa,p->geren,p->shifa);
         printf("\n");
		 p=p->next;          //ʹpָ����һ���ڵ�
       }

    printf("       =====================���������һ�����========================\n");
}

/********************************************
Function: modify()
Description: ��Ϊ�Ӻ����޸�ְ����Ϣ
Calls��1.add_money���� 2.grsds���� 3.add_wages����4.write()
Calls By: main()
Input: ������Ϊ�βΣ���ַ��Ϊʵ��
Other: �޷���ֵ
*********************************************/

void modify(zhigong *p)
{                            //�޸ĺ���
    char gohao[11];//�����ַ���
    int i, k, m;
    zhigong a;
    zhigong *b=p;
    printf("       ====================��������Ҫ��ѯ�Ĺ��Ż�����===================\n");//ͨ�����Ż��������в���
    scanf("%s",gohao);

    zhigong *q=p;
    q=q->next;
    while(q!=p)
        {
          if(strcmp(q->id,gohao)==0 || strcmp(q->name,gohao)==0)
             {
               printf("ְ����ϢΪ��\n");//���ְ���޸���Ϣǰ����Ϣ
               printf("���ţ�%s\t������%s\t��λ���ʣ�%.2f\n",q->id,q->name,q->gangwei);
               printf("н�����ʣ�%.2f\tְ�������%.2f\t��Ч���ʣ�%.2f\n",q->xinji,q->zhiwu,q->jixiao);
               printf("Ӧ�����ʣ�%.2f\t��������˰��%.2f\tʵ�����ʣ�%.2f\n",q->yingfa,q->geren,q->shifa);

               printf("       ================����1��ʾȷ���޸ģ�����0��ʾ�����޸�===============\n");
               scanf("%d",&k);
               if(k == 1)//ȷ���޸ĵĲ���
                 {
                   printf("������¼��ְ�����š���������λ���ʡ�н�����ʡ�ְ���������Ч����\n");
                   printf("���ţ�");
                   scanf("%s",&a.id);//����
                   printf("������");
                   scanf("%s",&a.name);//����
                   printf("��λ���ʣ�");
                   scanf("%f",&a.gangwei);//��λ����
                   printf("н�����ʣ�");
                   scanf("%f",&a.xinji);//н������
                   printf("ְ�������");
                   scanf("%f",&a.zhiwu);//ְ�����
                   printf("��Ч���ʣ�");
                   scanf("%f",&a.jixiao);//��Ч����
                   strcpy(q->id , a.id);
                   strcpy(q->name , a.name);
                   q->gangwei = a.gangwei;
                   q->xinji = a.xinji;
                   q->zhiwu = a.zhiwu;
                   q->jixiao = a.jixiao;
                   add_money(q);//ְ��Ӧ������
                   grsds(q);//ְ����������˰
                   add_wages(q);//ְ��ʵ������

                   printf("ְ����Ϣ�޸ĺ�Ϊ��\n");//���ְ���޸���Ϣ�����Ϣ
                   printf("���ţ�%s\t������%s\t��λ���ʣ�%.2f\n",q->id,q->name,q->gangwei);
                   printf("н�����ʣ�%.2f\tְ�������%.2f\t��Ч���ʣ�%.2f\n",q->xinji,q->zhiwu,q->jixiao);
                   printf("Ӧ�����ʣ�%.2f\t��������˰��%.2f\tʵ�����ʣ�%.2f\n",q->yingfa,q->geren,q->shifa);
                   printf("       ***************ְ����Ϣ���޸ģ����������һ�����***************\n");

                   printf("       ================����1��ʾȷ�ϱ��棬����0��ʾ��������===============\n");
                   scanf("%d",&m);

                   if(m == 1)
                       {
                          wirte(b);//ȷ�ϱ���Ĳ���
                          printf("       =====================���������һ�����========================\n");
                          return;
                       }

                   else
                       {
                          printf("       =============ְ����Ϣ���޸ģ����������һ�����=================\n");//���������Ĳ���
                          return;
                       }
                 }

              else
                  {
                     printf("       =====================���������һ�����========================\n");//���޸ĺ�Ĳ���
                     return;
                  }
             }
          else
               {
                q=q->next;
               }
        }

    printf("ϵͳ���Ҳ�����ְ����Ϣ�������ʵ������Ĺ��Ż������Ƿ��д������������ѯ�����ٽ��в�ѯ\n");

    printf("       =====================���������һ�����========================\n");
}

/********************************************
Function: del()
Description: ��Ϊ�Ӻ���ɾ��ְ����Ϣ
Calls:write()
Calls By: main()
Input: ������Ϊ�βΣ���ַ��Ϊʵ��
Other: �޷���ֵ
*********************************************/

void del(zhigong *head)  //ɾ������
{
    char gohao[11];//�����ַ���
    int i, j, k, t;
    zhigong *p = head,*a=head, *q;
    p = p->next;
    printf("       ====================��������Ҫ��ѯ�Ĺ��Ż�����===================\n");//ͨ�����Ż��������в���
    scanf("%s",gohao);

    while(p!=head)
        {
            if(strcmp(p->id,gohao)==0 || strcmp(p->name,gohao)==0)
                {
                   printf("ɾ����ְ����ϢΪ��\n");//���ְ���޸���Ϣǰ����Ϣ
                   printf("���ţ�%s\t������%s\t��λ���ʣ�%.2f\n",p->id,p->name,p->gangwei);
                   printf("н�����ʣ�%.2f\tְ�������%.2f\t��Ч���ʣ�%.2f\n",p->xinji,p->zhiwu,p->jixiao);
                   printf("Ӧ�����ʣ�%.2f\t��������˰��%.2f\tʵ�����ʣ�%.2f\n",p->yingfa,p->geren,p->shifa);

                   printf("       ================����1��ʾȷ��ɾ��������0��ʾ����ɾ��===============\n");
                   scanf("%d", &k);
                   if(k==1)
                       {
                          q = p->next;
                          (p->prior)->next = p->next;
                          (p->next)->prior = p->prior;
                          free(p);
                          p = q;
                   n=n-1;
                   printf("       ================����1��ʾȷ�ϱ��棬����0��ʾ��������===============\n");
                   scanf("%d", &t);
                   if(t == 1)
                        {
                           wirte(a);//ȷ��ɾ���Ĳ���
                           return;
                        }

                   else
                        {
                           printf("       =============ְ����Ϣ���޸ģ����������һ�����================\n");//����ɾ����Ĳ���
                           return;
                        }

                       }

                   else
                       {
                          printf("       =====================���������һ�����========================\n");
                          return;
                       }
                }
           else
                {
                  p=p->next;
                }
        }

    printf("ϵͳ���Ҳ�����ְ����Ϣ�������ʵ������Ĺ��Ż������Ƿ��д������������ѯ�����ٽ��в�ѯ\n");//δ�ҵ�ְ����Ϣ��Ĳ���
    return;
}

/********************************************
Function: add()
Description: ��Ϊ�Ӻ�������ְ����Ϣ
Calls��1.add_money���� 2.grsds���� 3.add_wages����4.write()
Calls By: main()
Input: ������Ϊ�βΣ���ַ��Ϊʵ��
Other: �޷���ֵ
*********************************************/

void add(zhigong *head)//���Ӻ���
{
    int k;
	zhigong *p=head,*t=head,*q,a;
    p=p->next;
    if(n == 100)
        {
           printf("       ==============ְ�������������������ְ����===============\n");
           printf("       =====================����������������====================\n");
           return;
        }

    else
        {
          
          printf("       =======================����¼���û���Ϣ===========================\n");//ͨ�����Ż��������в���
          printf("���ţ�");
          scanf("%s", &a.id);//����
          while(p!=head)//�жϹ�����ͬ�Ĳ������
              { 
                  if(strcmp(p->id,a.id)==0)
                    {
                      printf("       ================�����Ѵ��ڣ���������������========================\n");
                      return;
				     }
                  else
                     {
                       p=p->next;
                     }
              }
          printf("������");
          scanf("%s",&a.name);//����
          printf("��λ���ʣ�");
          scanf("%f",&a.gangwei);//��λ����
          printf("н�����ʣ�");
          scanf("%f",&a.xinji);//н������
          printf("ְ�������");
          scanf("%f",&a.zhiwu);//ְ�����
          printf("��Ч���ʣ�");
          scanf("%f",&a.jixiao);//��Ч����
          add_money(&a);//Ӧ������
          grsds(&a);//��������˰
          add_wages(&a);//ʵ������
          n = n + 1;//ְ��������1
          q = (zhigong *)malloc(sizeof(zhigong));
		  strcpy(q->id ,a.id);//�������е����ݷ��䵽˫��������������
		  strcpy(q->name,a.name);
		  q->gangwei=a.gangwei;
		  q->xinji=a.xinji;
		  q->zhiwu=a.zhiwu;
		  q->jixiao=a.jixiao;
		  q->yingfa=a.yingfa;
		  q->geren=a.geren;
		  q->shifa=a.shifa;
          p->prior->next= q;           //p��ǰ���ڵ�ĺ�ָ��ָ��q
		  head->prior = q;             //head��ǰ�ڵ�ָ��q
		  q->prior = p->prior;          //q��ǰ�ڵ�ָ��p
          q->next = head;              //q���½ڵ�ָ��head 
          printf("ְ����ϢΪ��\n");
          printf("���ţ�%s\t������%s\t��λ���ʣ�%.2f\n",q->id,q->name,q->gangwei);
          printf("н�����ʣ�%.2f\tְ�������%.2f\t��Ч���ʣ�%.2f\n",q->xinji,q->zhiwu,q->jixiao);
          printf("Ӧ�����ʣ�%.2f\t��������˰��%.2f\tʵ�����ʣ�%.2f\n",q->yingfa,q->geren,q->shifa);

          printf("       ================����1��ʾȷ�����ӣ�����0��ʾ��������===============\n");
          scanf("%d",&k);
          if(k == 1)
                {
                    
                    wirte(t);//ȷ�����ӵĲ���
                    return;
                }

          else
                {
                    printf("       =====================���������һ�����========================\n");//�������Ӻ�Ĳ���
                    return;
                }
    //printf("       =====================���������һ�����========================\n");
        }
}


/********************************************
Function: main()
Description: ��Ϊ������������������
Calls: 1.read() 2.write() 3.find() 4.list()
       5.modify() 6.add() 7.del() 
Return: 0
*********************************************/
int main()
{
    //zhigong zggz[M];
    char m[M];
    zhigong *head;
    head = (zhigong *)malloc(sizeof(zhigong));//Ϊͷ��ָ������ڴ�ռ�
    read(head);
    //head = createlist(zggz);
	printf("       ###   ��ӭʹ�ù��������ѧ�������Ϣ��ȫѧԺְ�����ʹ���ϵͳ   ###\n");
    printf("       ��ѡ��<1-7>��                                                     \n");
	printf("       ==================================================================\n");
    printf("       |                      1.��ѯְ�����ʼ�¼                        |\n");
    printf("       |                      2.�޸�ְ�����ʼ�¼                        |\n");
    printf("       |                      3.���ְ�����ʼ�¼                        |\n");
    printf("       |                      4.ɾ��ְ�����ʼ�¼                        |\n");
    printf("       |                      5.���ְ�����ʼ�¼                        |\n");
    printf("       |                      6.����ְ�����ʼ�¼                        |\n");
    printf("       |                      7.�˳�ϵͳ                                |\n");
    printf("       ==================================================================\n");
    printf("       ���ѡ���ǣ�");
	
    while(scanf("%s",&m))//ѭ������
      {
          system("cls");//��������
		  if(strcmp(m,"1")==0)
                  {
                    find(head);//��ѯ
                  }

          else if(strcmp(m,"2")==0)
                  {
                    modify(head);//�޸�
                  }

          else if(strcmp(m,"3")==0)
                  {
                    add(head);//���
                  }

          else if(strcmp(m,"4")==0)
                  {
                    del(head);//ɾ��
                  }

          else if(strcmp(m,"5")==0)
                  {
                    list(head);//���
                  }

         else if(strcmp(m,"6")==0)
                  {
                    wirte(head);//����
                  }

         else if(strcmp(m,"7")==0)
                  {
                    return 0;//�˳�
                  }

        else
             {
                printf("       ================�޴�ָ�����������=============================\n");
             }

         printf("       |                      1.��ѯְ�����ʼ�¼                        |\n");
         printf("       |                      2.�޸�ְ�����ʼ�¼                        |\n");
         printf("       |                      3.���ְ�����ʼ�¼                        |\n");
         printf("       |                      4.ɾ��ְ�����ʼ�¼                        |\n");
         printf("       |                      5.���ְ�����ʼ�¼                        |\n");
         printf("       |                      6.����ְ�����ʼ�¼                        |\n");
         printf("       |                      7.�˳�ϵͳ                                |\n");
         printf("       ==================================================================\n");
        
      }
     
   return 0;
}
