#include"zhigong.h"
/********************************************
Function: main()
Description: ��Ϊ������������������
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
                    find(stu);//��ѯ
                  }

          else if(strcmp(m,"2")==0)
                  {
                    modify(stu);//�޸�
                  }

          else if(strcmp(m,"3")==0)
                  {
                    add(stu);//���
                  }

          else if(strcmp(m,"4")==0)
                  {
                    del(stu);//ɾ��
                  }

          else if(strcmp(m,"5")==0)
                  {
                    list(stu);//���
                  }

         else if(strcmp(m,"6")==0)
                  {
                    wirte(stu);//����
                  }

         else if(strcmp(m,"7")==0)
                  {
                    return 0;//�˳�
                  }

        else
             {
                printf("�޴�ָ�����������\n");
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