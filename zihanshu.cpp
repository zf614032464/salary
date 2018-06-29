#include"zhigong.h"

/********************************************
Function: read()
Description: ��Ϊ�Ӻ���д�����ݵ�������
Calls: close()
Calls By: main()
Input: ������Ϊ�βΣ���ַ��Ϊʵ��
Other: �޷���ֵ
*********************************************/

void read(zhigong zggz[])    //�ļ���ȡ
{
    fstream f("gz.dat",ios::in|ios::binary);//�Զ����Ʒ�ʽ��һ�������ļ�
    if(!f)
      {
         printf("Cannot open file\n");
         abort();
      }

    for(int i=0; i < 100; i++)
      {

          if(!f.eof())//�ж��ļ��Ƿ񵽴�ĩβ 
             {
                n++;//ְ��������1
                f>>zggz[i].id>>zggz[i].name>>zggz[i].gangwei>>zggz[i].xinji>>zggz[i].zhiwu>>zggz[i].jixiao>>zggz[i].yingfa>>zggz[i].geren>>zggz[i].shifa;
              }//���ļ���ȡ���ݵ��ṹ������

           else
               {
                  break;
               }	
      }

    n = n - 1;//eof()������ִ����һ��
    f.close();
 }

/********************************************
Function: createlist()
Description: ��Ϊ�Ӻ�������˫������
Calls By: main()
Input: ������Ϊ�βΣ���ַ��Ϊʵ��
Other: �޷���ֵ
*********************************************/
zhigong *createlist(zhigong zggz[])       //������n��Ԫ�ص�˫������ 
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
}


/********************************************
Function: write()
Description: ��Ϊ�Ӻ�����ȡ���ݵ��ļ���
Calls: close()
Calls By: main()
Input: ������Ϊ�βΣ���ַ��Ϊʵ��
Other: �޷���ֵ
*********************************************/

void wirte(zhigong zggz[])
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

    for(int i=0; i < n; i++)
      {
         if(!f.eof())//�ж��ļ��Ƿ񵽴�ĩβ 
            {
               f<<zggz[i].id<<" "<<zggz[i].name<<" "<<zggz[i].gangwei<<" "<<zggz[i].xinji<<" "<<zggz[i].zhiwu<<" "<<zggz[i].jixiao<<" "<<zggz[i].yingfa<<" "<<zggz[i].geren<<" "<<zggz[i].shifa<<" ";
            }
      }
    f.close();
 
    printf("       =====================�ļ��ѱ��棬���������һ������=================\n");
}

/********************************************
Function: find()
Description: ��Ϊ�Ӻ�����ѯְ����Ϣ
Calls By: main()
Input: ������Ϊ�βΣ���ַ��Ϊʵ��
Other: �޷���ֵ
*********************************************/

void find(zhigong zggz[])
{                             //��ѯ����
    char gohao[11];//�����ַ���
    int i;
    printf("       ====================��������Ҫ��ѯ�Ĺ��Ż�����===================\n");//ͨ�����Ż��������в���
    scanf("%s",gohao);

    for(i=0;i<n;i++)
        {
          if(strcmp(zggz[i].id,gohao)==0 || strcmp(zggz[i].name,gohao)==0)
             {
               printf("��ְ����ϢΪ��\n");
               add_money(&zggz[i]);//����ְ��Ӧ������
               grsds(&zggz[i]);//����ְ����������˰
               add_wages(&zggz[i]);//����ְ��ʵ������
               printf("���ţ�%s\t������%s\t��λ���ʣ�%.2f\n",zggz[i].id,zggz[i].name,zggz[i].gangwei);
               printf("н�����ʣ�%.2f\tְ�������%.2f\t��Ч���ʣ�%.2f\n",zggz[i].xinji,zggz[i].zhiwu,zggz[i].jixiao);
               printf("Ӧ�����ʣ�%.2f\t��������˰��%.2f\tʵ�����ʣ�%.2f\n",zggz[i].yingfa,zggz[i].geren,zggz[i].shifa);
               printf("       =====================���������һ�����========================\n");
               break;
             }
        }

    if(n == i)
      {
        printf("ϵͳ���Ҳ�����ְ����Ϣ�������ʵ������Ĺ��Ż������Ƿ��д������������ѯ�����ٽ��в�ѯ\n");
        return;
      }
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
    //for(int i=0; i < n; i++)
    while(p!=head)
       {
         add_money(p);//����ְ��Ӧ������
         grsds(p);//����ְ����������˰
         add_wages(p);//����ְ��ʵ������
         printf("���ţ�%s\t������%s\t��λ���ʣ�%.2f\n",p->id,p->name,p->gangwei);
         printf("н�����ʣ�%.2f\tְ�������%.2f\t��Ч���ʣ�%.2f\n",p->xinji,p->zhiwu,p->jixiao);
         printf("Ӧ�����ʣ�%.2f\t��������˰��%.2f\tʵ�����ʣ�%.2f\n",p->yingfa,p->geren,p->shifa);
         printf("\n");
		 p=p->next;
       }

    printf("       =====================���������һ�����========================\n");
}

/********************************************
Function: modify()
Description: ��Ϊ�Ӻ����޸�ְ����Ϣ
Calls:write()
Calls By: main()
Input: ������Ϊ�βΣ���ַ��Ϊʵ��
Other: �޷���ֵ
*********************************************/

void modify(zhigong zggz[])
{                            //�޸ĺ���
    char gohao[11];//�����ַ���
    int i, k, p;
    zhigong a;
    printf("       ====================��������Ҫ��ѯ�Ĺ��Ż�����===================\n");//ͨ�����Ż��������в���
    scanf("%s",gohao);

    for(i=0; i < n; i++)
        {
          if(strcmp(zggz[i].id,gohao)==0 || strcmp(zggz[i].name,gohao)==0)
             {
               printf("ְ����ϢΪ��\n");//���ְ���޸���Ϣǰ����Ϣ
               printf("���ţ�%s\t������%s\t��λ���ʣ�%.2f\n",zggz[i].id,zggz[i].name,zggz[i].gangwei);
               printf("н�����ʣ�%.2f\tְ�������%.2f\t��Ч���ʣ�%.2f\n",zggz[i].xinji,zggz[i].zhiwu,zggz[i].jixiao);
               printf("Ӧ�����ʣ�%.2f\t��������˰��%.2f\tʵ�����ʣ�%.2f\n",zggz[i].yingfa,zggz[i].geren,zggz[i].shifa);

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
                   strcpy(zggz[i].id , a.id);
                   strcpy(zggz[i].name , a.name);
                   zggz[i].gangwei = a.gangwei;
                   zggz[i].xinji = a.xinji;
                   zggz[i].zhiwu = a.zhiwu;
                   zggz[i].jixiao = a.jixiao;
                   add_money(&zggz[i]);//ְ��Ӧ������
                   grsds(&zggz[i]);//ְ����������˰
                   add_wages(&zggz[i]);//ְ��ʵ������

                   printf("ְ����Ϣ�޸ĺ�Ϊ��\n");//���ְ���޸���Ϣ�����Ϣ
                   printf("���ţ�%s\t������%s\t��λ���ʣ�%.2f\n",zggz[i].id,zggz[i].name,zggz[i].gangwei);
                   printf("н�����ʣ�%.2f\tְ�������%.2f\t��Ч���ʣ�%.2f\n",zggz[i].xinji,zggz[i].zhiwu,zggz[i].jixiao);
                   printf("Ӧ�����ʣ�%.2f\t��������˰��%.2f\tʵ�����ʣ�%.2f\n",zggz[i].yingfa,zggz[i].geren,zggz[i].shifa);
                   printf("       ***************ְ����Ϣ���޸ģ����������һ�����***************\n");

                   printf("       ================����1��ʾȷ�ϱ��棬����0��ʾ��������===============\n");
                   scanf("%d",&p);

                   if(p == 1)
                       {
                          wirte(zggz);//ȷ�ϱ���Ĳ���
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
        }

    if(n == i)
        {
           printf("ϵͳ���Ҳ�����ְ����Ϣ�������ʵ������Ĺ��Ż������Ƿ��д������������ѯ�����ٽ��в�ѯ\n");
        }

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

void del(zhigong zggz[])  //ɾ������
{
    char gohao[11];//�����ַ���
    int i, j, k, t;
    printf("       ====================��������Ҫ��ѯ�Ĺ��Ż�����===================\n");//ͨ�����Ż��������в���
    scanf("%s",gohao);

    for(i=0; i < n; i++)
        {
            if(strcmp(zggz[i].id,gohao)==0 || strcmp(zggz[i].name,gohao)==0)
                {
                   printf("ɾ����ְ����ϢΪ��\n");//���ְ���޸���Ϣǰ����Ϣ
                   printf("���ţ�%s\t������%s\t��λ���ʣ�%.2f\n",zggz[i].id,zggz[i].name,zggz[i].gangwei);
                   printf("н�����ʣ�%.2f\tְ�������%.2f\t��Ч���ʣ�%.2f\n",zggz[i].xinji,zggz[i].zhiwu,zggz[i].jixiao);
                   printf("Ӧ�����ʣ�%.2f\t��������˰��%.2f\tʵ�����ʣ�%.2f\n",zggz[i].yingfa,zggz[i].geren,zggz[i].shifa);

                   printf("       ================����1��ʾȷ��ɾ��������0��ʾ����ɾ��===============\n");
                   scanf("%d", &k);
                   if(k==1)
                       {
                          for(j=i; j < n-1; j++)
                               {	
                                  zggz[j]=zggz[j+1];
                               }
                   n = n - 1;

                   printf("       ================����1��ʾȷ�ϱ��棬����0��ʾ��������===============\n");
                   scanf("%d", &t);
                   if(t == 1)
                        {
                           wirte(zggz);//ȷ��ɾ���Ĳ���
                           
                        }

                   else
                        {
                           printf("       =============ְ����Ϣ���޸ģ����������һ�����================\n");//����ɾ����Ĳ���
                           return;
                        }

                   printf("ɾ����ʣ��ְ������ϢΪ��\n");
                   
                   for(i=0 ;i < n; i++)
                        {
                           printf("���ţ�%s\t������%s\t��λ���ʣ�%.2f\n",zggz[i].id,zggz[i].name,zggz[i].gangwei);
                           printf("н�����ʣ�%.2f\tְ�������%.2f\t��Ч���ʣ�%.2f\n",zggz[i].xinji,zggz[i].zhiwu,zggz[i].jixiao);
                           printf("Ӧ�����ʣ�%.2f\t��������˰��%.2f\tʵ�����ʣ�%.2f\n",zggz[i].yingfa,zggz[i].geren,zggz[i].shifa);
                           printf("\n");
                        }

                   printf("       =====================���������һ�����=========================\n");
                   return;
                       }

                   else
                       {
                          printf("       =====================���������һ�����========================\n");
                          return;
                       }
                }
        }

    if(n == i)
        {
           printf("ϵͳ���Ҳ�����ְ����Ϣ�������ʵ������Ĺ��Ż������Ƿ��д������������ѯ�����ٽ��в�ѯ\n");//δ�ҵ�ְ����Ϣ��Ĳ���
        }
    printf("       =====================���������һ�����========================\n");
}

/********************************************
Function: add()
Description: ��Ϊ�Ӻ�������ְ����Ϣ
Calls:write()
Calls By: main()
Input: ������Ϊ�βΣ���ַ��Ϊʵ��
Other: �޷���ֵ
*********************************************/

void add(zhigong *p)//���Ӻ���
{
    int k;
	zhigong *q=p;
    if(n == 100)
        {
           printf("       ==============ְ�������������������ְ����===============\n");
           printf("       =====================����������������====================\n");
           return;
        }

    else
        {
          p = p + n;//��ָ���Ƶ�����ĩβ
          printf("       =======================����¼���û���Ϣ===========================\n");//ͨ�����Ż��������в���
          printf("���ţ�");
          scanf("%s", &p->id);//����
          for(int i=0; i<n; i++, q++)//�жϹ�����ͬ�Ĳ������
              { 
                  if(strcmp(p->id,q->id)==0)
                    {
                      printf("       ================�����Ѵ��ڣ���������������========================\n");
                      return;
				     }
              }
          printf("������");
          scanf("%s",&p->name);//����
          printf("��λ���ʣ�");
          scanf("%f",&p->gangwei);//��λ����
          printf("н�����ʣ�");
          scanf("%f",&p->xinji);//н������
          printf("ְ�������");
          scanf("%f",&p->zhiwu);//ְ�����
          printf("��Ч���ʣ�");
          scanf("%f",&p->jixiao);//��Ч����
          add_money(p);//Ӧ������
          grsds(p);//��������˰
          add_wages(p);//ʵ������
          n = n + 1;//ְ��������1
          printf("ְ����ϢΪ��\n");
          printf("���ţ�%s\t������%s\t��λ���ʣ�%.2f\n",p->id,p->name,p->gangwei);
          printf("н�����ʣ�%.2f\tְ�������%.2f\t��Ч���ʣ�%.2f\n",p->xinji,p->zhiwu,p->jixiao);
          printf("Ӧ�����ʣ�%.2f\t��������˰��%.2f\tʵ�����ʣ�%.2f\n",p->yingfa,p->geren,p->shifa);

          printf("       ================����1��ʾȷ�����ӣ�����0��ʾ��������===============\n");
          scanf("%d",&k);
          if(k == 1)
                {
                    p = p - n + 1;
                    wirte(p);//ȷ�����ӵĲ���
                    return;
                }

          else
                {
                    printf("       =====================���������һ�����========================\n");//�������Ӻ�Ĳ���
                    return;
                }
    printf("       =====================���������һ�����========================\n");
        }
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
