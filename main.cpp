/********************************************
Function: main()
Description: ��Ϊ������������������
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
    printf("       ******��ӭ����ְ�����ʹ���ϵͳ���밴��������ʾ���룬���в���******\n");
    printf("       *                  �����ʾ��Ϣ�����ܲ˵�                        *\n");
    printf("       *                   1.��ѯ 2.�޸� 3.���                         *\n");
    printf("       *                   4.ɾ�� 5.��� 6.����                         *\n");
    printf("       *                          7.�˳�                                *\n");
    printf("       *********************���������ָ��*******************************\n");
	
    while(scanf("%d",&m))//ѭ������
      {
          system("cls");//��������
		  switch(m){
                  case 1:find(stu); break;//��ѯ

                  case 2:modify(stu); break;//�޸�

                  case 3:add(stu); break;//���

                  case 4:del(stu); break;//ɾ��

                  case 5:list(stu); break;//���

                  case 6:wirte(stu); break;//����

                  case 7:return 0;//�˳�

                  default:cout<<"��ָ����ڣ�����������"<<endl;
                 }

        printf("       *                  �����ʾ��Ϣ�����ܲ˵�                        *\n");
        printf("       *                   1.��ѯ 2.�޸� 3.���                         *\n");
        printf("       *                   4.ɾ�� 5.��� 6.����                         *\n");
        printf("       *                          7.�˳�                                *\n");
        printf("       *********************���������ָ��*******************************\n");
        
      }
     
   return 0;
}