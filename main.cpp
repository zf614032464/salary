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
    int m;
    zhigong *head;
    read(stu);
    head = createlist(stu);
	printf("       ###   ��ӭʹ�ù��������ѧ�������Ϣ��ȫѧԺְ�����ʹ���ϵͳ   ###\n");
    printf("       ��ѡ��<1-7>��                                                     \n");
	printf("       ==================================================================\n");
    printf("       =                      1.��ѯְ�����ʼ�¼                        =\n");
    printf("       =                      2.�޸�ְ�����ʼ�¼                        =\n");
    printf("       =                      3.���ְ�����ʼ�¼                        =\n");
    printf("       =                      4.ɾ��ְ�����ʼ�¼                        =\n");
    printf("       =                      5.���ְ�����ʼ�¼                        =\n");
    printf("       =                      6.����ְ�����ʼ�¼                        =\n");
    printf("       =                      7.�˳�ϵͳ                                =\n");
    printf("       ==================================================================\n");
    printf("       ���ѡ���ǣ�");
	
    while(scanf("%d",&m))//ѭ������
      {
          system("cls");//��������
		  switch(m){
                  case 1:find(stu); break;//��ѯ

                  case 2:modify(stu); break;//�޸�

                  case 3:add(stu); break;//���

                  case 4:del(stu); break;//ɾ��

                  case 5:list(head); break;//���

                  case 6:wirte(stu); break;//����

                  case 7:return 0;//�˳�

                  default:cout<<"��ָ����ڣ�����������"<<endl;
                 }

         printf("       =                      1.��ѯְ�����ʼ�¼                        =\n");
         printf("       =                      2.�޸�ְ�����ʼ�¼                        =\n");
         printf("       =                      3.���ְ�����ʼ�¼                        =\n");
         printf("       =                      4.ɾ��ְ�����ʼ�¼                        =\n");
         printf("       =                      5.���ְ�����ʼ�¼                        =\n");
         printf("       =                      6.����ְ�����ʼ�¼                        =\n");
         printf("       =                      7.�˳�ϵͳ                                =\n");
         printf("       ==================================================================\n");
        
      }
     
   return 0;
}