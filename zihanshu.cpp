#include"zhigong.h"
void read(zhigong zggz[],int a)//�ļ���ȡ
{
	fstream f("gx.dat",ios::in|ios::binary);//�Զ����Ʒ�ʽ��һ�������ļ�
	if(!f)
	{
		cout<<"Cannot open file"<<endl;
		abort();
	}
	for(int i=0;i<a;i++)
	{
		n++;//ְ��������1
		f>>zggz[i].id>>zggz[i].name>>zggz[i].gangwei>>zggz[i].xinji>>zggz[i].zhiwu>>zggz[i].jixiao>>zggz[i].yingfa>>zggz[i].geren>>zggz[i].shifa;
	}
	f.close();
}

void wirte(zhigong zggz[])
{//�ļ�����
	if(n<1)
		{
			cout<<"ְ������Ϊ0���޷�д��"<<endl;
			return;
	    }

	fstream f("gz.dat",ios::out|ios::binary);//�Զ����Ʒ�ʽ��һ������ļ�
	if(!f)
	{
		cout<<"Cannot open file"<<endl;
		abort();
	}

	for(int i=0;i<n;i++)
	{
		f.write((char*)&zggz[i],sizeof(zggz[i]));
	}
	f.close();
    
	/*zhigong zggz1[3];
	fstream f1("gz.dat",ios::in|ios::binary);
	if(!f)
	{
		cout<<"Cannot open file"<<endl;
		abort();
	}
	for(int i=0;i<n;i++)
	{
		//f.read((char*)&zggz1[i],sizeof(zggz1[i]));
		f>>zggz1[i].id>>zggz1[i].name>>zggz1[i].gangwei>>zggz1[i].xinji>>zggz1[i].zhiwu>>zggz1[i].jixiao>>zggz1[i].yingfa>>zggz1[i].geren>>zggz1[i].shifa;
		cout<<zggz1[i].id<<" "<<zggz1[i].name<<"      "<<zggz1[i].gangwei<<"      "<<zggz1[i].xinji<<"      "<<zggz1[i].zhiwu<<"      ";
			cout<<zggz1[i].jixiao<<"      "<<zggz1[i].yingfa<<"      "<<zggz1[i].geren<<"      "<<zggz1[i].shifa<<endl;
	}
	f1.close();*/
	cout<<"���������һ������"<<endl;
}

void find(zhigong zggz[])
{//��ѯ����
	string gohao;//�����ַ���
	int i;
	cout<<"��������Ҫ��ѯ�Ĺ��Ż�����"<<endl;
	cin>>gohao;

	for(i=0;i<n;i++)
	{
		if(zggz[i].id==gohao||zggz[i].name==gohao)
		{
			cout<<"��ְ����ϢΪ��"<<endl;
			cout<<"���� "<<"����   "<<"��λ���� "<<"н������ "<<"ְ����� "<<"��Ч���� "<<"Ӧ������ "<<"��������˰ "<<"ʵ������ "<<endl;
			add_money(&zggz[i]);
			grsds(&zggz[i]);
			add_wages(&zggz[i]);
			cout<<zggz[i].id<<" "<<zggz[i].name<<"      "<<zggz[i].gangwei<<"      "<<zggz[i].xinji<<"      "<<zggz[i].zhiwu<<"      ";
			cout<<zggz[i].jixiao<<"      "<<zggz[i].yingfa<<"      "<<zggz[i].geren<<"      "<<zggz[i].shifa<<endl;
			cout<<"���������һ�����"<<endl;
			break;
		}
	}

	if(n==i)
	{
		cout<<"ϵͳ���Ҳ�����ְ����Ϣ�������ʵ������Ĺ����Ƿ��д������������ѯ�����ٽ��в�ѯ"<<endl;
	}
}

void list(zhigong zggz[])
{//�������
	cout<<"ְ����ϢΪ��"<<endl;
	cout<<"���� "<<"����   "<<"��λ���� "<<"н������ "<<"ְ����� "<<"��Ч���� "<<"Ӧ������ "<<"��������˰ "<<"ʵ������ "<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<zggz[i].id<<" "<<zggz[i].name<<"      "<<zggz[i].gangwei<<"      "<<zggz[i].xinji<<"      "<<zggz[i].zhiwu<<"      ";
		cout<<zggz[i].jixiao<<"      "<<zggz[i].yingfa<<"      "<<zggz[i].geren<<"      "<<zggz[i].shifa<<endl;
	}
	cout<<"���������һ�����"<<endl;
}

void modify(zhigong zggz[])
{//�޸ĺ���
	string gohao;//�����ַ���
	int i;
	cout<<"��������Ҫ��ѯ�Ĺ��Ż�����"<<endl;
    cin>>gohao;

	for(i=0;i<n;i++)
	{
		if(zggz[i].id==gohao||zggz[i].name==gohao)
		{

		}
	}

	if(n==i)
	{
		cout<<"ϵͳ���Ҳ�����ְ����Ϣ�������ʵ������Ĺ����Ƿ��д������������ѯ�����ٽ��в�ѯ"<<endl;
	}
}

void del(zhigong zggz[])//ɾ������
{
	string gohao;//�����ַ���
	int i,j,k;
	cout<<"��������Ҫ�޸ĵĹ��Ż�����"<<endl;
    cin>>gohao;

	for(i=0;i<n;i++)
	{
		if(zggz[i].id==gohao||zggz[i].name==gohao)
		{
			cout<<"����1��ʾɾ��������0��ʾ����ɾ��"<<endl;
			cin>>k;
			if(k==1)
			{
				for(j=i;j<n-1;j++)
			    {	
					zggz[j]=zggz[j+1];
				}
			n=n-1;
			break;
			}
			else
			{
				cout<<"���������һ�����"<<endl;
				return;
			}
		}
	}

	if(n==i)
	{
		cout<<"ϵͳ���Ҳ�����ְ����Ϣ�������ʵ������Ĺ����Ƿ��д������������ѯ�����ٽ��в�ѯ"<<endl;
	}
	cout<<"���������һ�����"<<endl;
}

void add(zhigong *p)//���Ӻ���
{
	if(n==100)
	{
		cout<<"ְ�������������������ְ����"<<endl;
		cout<<"����������������"<<endl;
		return;
	}

	else
	{
	n=n+1;
	cout<<"����¼���û���Ϣ"<<endl;
	cin>>p->id;
	cin>>p->name;
	cin>>p->gangwei;
	cin>>p->xinji;
	cin>>p->zhiwu;
	cin>>p->jixiao;
	add_money(p);
	grsds(p);
	add_wages(p);
	cout<<"ְ����ϢΪ��"<<endl;
	cout<<"���� "<<"����   "<<"��λ���� "<<"н������ "<<"ְ����� "<<"��Ч���� "<<"Ӧ������ "<<"��������˰ "<<"ʵ������ "<<endl;
	cout<<p->id<<" "<<p->name<<"      "<<p->gangwei<<"      "<<p->xinji<<"      "<<p->zhiwu<<"      ";
	cout<<p->jixiao<<"      "<<p->yingfa<<"      "<<p->geren<<"      "<<p->shifa<<endl;
	cout<<"���������һ�����"<<endl;
	}
}

void add_money(zhigong *p1)									//����Ӧ������       
{
		p1->yingfa=p1->gangwei+p1->xinji+p1->zhiwu+p1->jixiao;
}

void grsds(zhigong *p1)//�����������˰����
{
		if(p1->yingfa<=500)                //Ӧ�����ʲ�����500
			{
				p1->geren=p1->yingfa*0.05;
		    }

		else if(p1->yingfa>500&&p1->yingfa<=2000)                   //Ӧ��������500��2000
			{
				p1->geren=(p1->yingfa-500)*0.1+500*0.05;
            }

		else if(p1->yingfa>2000&&p1->yingfa<=5000)                                //Ӧ��������2000��5000
			{
				p1->geren=(p1->yingfa-2000)*0.15+1500*0.1+500*0.05;
		    }

		else if(p1->yingfa>5000&&p1->yingfa<=20000)                                          //Ӧ��������5000��20000
			{
				p1->geren=(p1->yingfa-5000)*0.2+15000*0.15+1500*0.1+500*0.05;
		    }

		else if(p1->yingfa>20000&&p1->yingfa<=40000)                                                     //Ӧ��������20000��40000
			{
				p1->geren=(p1->yingfa-20000)*0.25+20000*0.2+15000*0.15+1500*0.1+500*0.05;
		    }

		else if(p1->yingfa>40000&&p1->yingfa<=60000)                                                                 //Ӧ��������40000��60000
			{
				p1->geren=(p1->yingfa-40000)*0.3+20000*0.25+20000*0.2+15000*0.15+1500*0.1+500*0.05;
		    }

		else if(p1->yingfa>60000&&p1->yingfa<=80000)                                                                            //Ӧ��������60000��80000
			{
				p1->geren=(p1->yingfa-60000)*0.35+20000*0.3+20000*0.25+20000*0.2+15000*0.15+1500*0.1+500*0.05;
		    }

		else if(p1->yingfa>80000&&p1->yingfa<=100000)                                                                                   //Ӧ��������80000��100000
			{
				p1->geren=(p1->yingfa-80000)*0.4+20000*0.35+20000*0.3+20000*0.25+20000*0.2+15000*0.15+1500*0.1+500*0.05;
		    }

		else                                                                                                                      //Ӧ�����ʳ���100000
			{
				p1->geren=(p1->yingfa-100000)*0.45+20000*0.4+20000*0.35+20000*0.3+20000*0.25+20000*0.2+15000*0.15+1500*0.1+500*0.05;
		    }
}


void add_wages(zhigong *p1)									//����ʵ������	     
{
		p1->shifa=p1->yingfa-p1->geren;
}
