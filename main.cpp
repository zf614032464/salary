#include"zhigong.h"
int main()
{
	zhigong stu[M];
	int m;
	read(stu,3);
	cout<<"��ӭ����ְ�����ʹ���ϵͳ�������밴��������ʾ�����в���"<<endl;
	cout<<"����1��ʾ��ѯ��2��ʾ�޸ģ�3��ʾ��ӣ�4��ʾɾ����5��ʾ��� ��6��ʾ���� ��7��ʾ�˳�"<<endl;
	cout<<"���������ָ��"<<endl;

	while(cin>>m)//ѭ������
	{
		switch(m){
		    case 1:find(stu);break;
			case 2:modify(stu);break;
			case 3:add(&stu[n]);break;
			case 4:del(stu);break;
			case 5:list(stu);break;
			case 6:wirte(stu);break;
			case 7:return 0;
			default:cout<<"��ָ����ڣ�����������"<<endl;
		}
	}

	return 0;
}