#include"zhigong.h"
int main()
{
    zhigong stu[M];
    int m;
    read(stu);
    cout<<"            ��ӭ����ְ�����ʹ���ϵͳ���밴��������ʾ���룬���в���"<<endl;
    cout<<"                           �����ʾ��Ϣ�����ܲ˵�"<<endl;
    cout<<"                            1.��ѯ 2.�޸� 3.���"<<endl;
    cout<<"                            4.ɾ�� 5.��� 6.����"<<endl;
    cout<<"                                   7.�˳�"<<endl;
    cout<<"                                ���������ָ��"<<endl;
	
    while(cin>>m)//ѭ������
      {
        switch(m){
                  case 1:find(stu);break;//��ѯ

                  case 2:modify(stu);break;//�޸�

                  case 3:add(stu);break;//���

                  case 4:del(stu);break;//ɾ��

                  case 5:list(stu);break;//���

                  case 6:wirte(stu);break;//����

                  case 7:return 0;//�˳�

                  default:cout<<"��ָ����ڣ�����������"<<endl;
                 }

        cout<<"                           �����ʾ��Ϣ�����ܲ˵�"<<endl;
        cout<<"                            1.��ѯ 2.�޸� 3.���"<<endl; 
        cout<<"                            4.ɾ�� 5.��� 6.����"<<endl;
        cout<<"                                   7.�˳�"<<endl;
        cout<<"                                 ���������ָ��"<<endl;
      }
     
   return 0;
}