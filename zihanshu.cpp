#include"zhigong.h"
void read(zhigong zggz[],int a)//文件读取
{
	fstream f("gx.dat",ios::in|ios::binary);//以二进制方式打开一个输入文件
	if(!f)
	{
		cout<<"Cannot open file"<<endl;
		abort();
	}
	for(int i=0;i<a;i++)
	{
		n++;//职工人数加1
		f>>zggz[i].id>>zggz[i].name>>zggz[i].gangwei>>zggz[i].xinji>>zggz[i].zhiwu>>zggz[i].jixiao>>zggz[i].yingfa>>zggz[i].geren>>zggz[i].shifa;
	}
	f.close();
}

void wirte(zhigong zggz[])
{//文件保存
	if(n<1)
		{
			cout<<"职工人数为0，无法写入"<<endl;
			return;
	    }

	fstream f("gz.dat",ios::out|ios::binary);//以二进制方式打开一个输出文件
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
	cout<<"请你进行下一步命令"<<endl;
}

void find(zhigong zggz[])
{//查询函数
	string gohao;//定义字符串
	int i;
	cout<<"请输入你要查询的工号或姓名"<<endl;
	cin>>gohao;

	for(i=0;i<n;i++)
	{
		if(zggz[i].id==gohao||zggz[i].name==gohao)
		{
			cout<<"此职工信息为："<<endl;
			cout<<"工号 "<<"姓名   "<<"岗位工资 "<<"薪级工资 "<<"职务津贴 "<<"绩效工资 "<<"应发工资 "<<"个人所得税 "<<"实发工资 "<<endl;
			add_money(&zggz[i]);
			grsds(&zggz[i]);
			add_wages(&zggz[i]);
			cout<<zggz[i].id<<" "<<zggz[i].name<<"      "<<zggz[i].gangwei<<"      "<<zggz[i].xinji<<"      "<<zggz[i].zhiwu<<"      ";
			cout<<zggz[i].jixiao<<"      "<<zggz[i].yingfa<<"      "<<zggz[i].geren<<"      "<<zggz[i].shifa<<endl;
			cout<<"请你进行下一步命令！"<<endl;
			break;
		}
	}

	if(n==i)
	{
		cout<<"系统中找不到此职工信息，请你核实你输入的工号是否有错，请重新输入查询命令再进行查询"<<endl;
	}
}

void list(zhigong zggz[])
{//浏览函数
	cout<<"职工信息为："<<endl;
	cout<<"工号 "<<"姓名   "<<"岗位工资 "<<"薪级工资 "<<"职务津贴 "<<"绩效工资 "<<"应发工资 "<<"个人所得税 "<<"实发工资 "<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<zggz[i].id<<" "<<zggz[i].name<<"      "<<zggz[i].gangwei<<"      "<<zggz[i].xinji<<"      "<<zggz[i].zhiwu<<"      ";
		cout<<zggz[i].jixiao<<"      "<<zggz[i].yingfa<<"      "<<zggz[i].geren<<"      "<<zggz[i].shifa<<endl;
	}
	cout<<"请你进行下一步命令！"<<endl;
}

void modify(zhigong zggz[])
{//修改函数
	string gohao;//定义字符串
	int i;
	cout<<"请输入你要查询的工号或姓名"<<endl;
    cin>>gohao;

	for(i=0;i<n;i++)
	{
		if(zggz[i].id==gohao||zggz[i].name==gohao)
		{

		}
	}

	if(n==i)
	{
		cout<<"系统中找不到此职工信息，请你核实你输入的工号是否有错，请重新输入查询命令再进行查询"<<endl;
	}
}

void del(zhigong zggz[])//删除函数
{
	string gohao;//定义字符串
	int i,j,k;
	cout<<"请输入你要修改的工号或姓名"<<endl;
    cin>>gohao;

	for(i=0;i<n;i++)
	{
		if(zggz[i].id==gohao||zggz[i].name==gohao)
		{
			cout<<"输入1表示删除，输入0表示放弃删除"<<endl;
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
				cout<<"请你进行下一步命令！"<<endl;
				return;
			}
		}
	}

	if(n==i)
	{
		cout<<"系统中找不到此职工信息，请你核实你输入的工号是否有错，请重新输入查询命令再进行查询"<<endl;
	}
	cout<<"请你进行下一步命令！"<<endl;
}

void add(zhigong *p)//增加函数
{
	if(n==100)
	{
		cout<<"职工人数已满，不能添加职工了"<<endl;
		cout<<"请你输入其他命令"<<endl;
		return;
	}

	else
	{
	n=n+1;
	cout<<"请你录入用户信息"<<endl;
	cin>>p->id;
	cin>>p->name;
	cin>>p->gangwei;
	cin>>p->xinji;
	cin>>p->zhiwu;
	cin>>p->jixiao;
	add_money(p);
	grsds(p);
	add_wages(p);
	cout<<"职工信息为："<<endl;
	cout<<"工号 "<<"姓名   "<<"岗位工资 "<<"薪级工资 "<<"职务津贴 "<<"绩效工资 "<<"应发工资 "<<"个人所得税 "<<"实发工资 "<<endl;
	cout<<p->id<<" "<<p->name<<"      "<<p->gangwei<<"      "<<p->xinji<<"      "<<p->zhiwu<<"      ";
	cout<<p->jixiao<<"      "<<p->yingfa<<"      "<<p->geren<<"      "<<p->shifa<<endl;
	cout<<"请你进行下一步命令！"<<endl;
	}
}

void add_money(zhigong *p1)									//计算应发工资       
{
		p1->yingfa=p1->gangwei+p1->xinji+p1->zhiwu+p1->jixiao;
}

void grsds(zhigong *p1)//计算个人所得税函数
{
		if(p1->yingfa<=500)                //应发工资不超过500
			{
				p1->geren=p1->yingfa*0.05;
		    }

		else if(p1->yingfa>500&&p1->yingfa<=2000)                   //应发工资在500到2000
			{
				p1->geren=(p1->yingfa-500)*0.1+500*0.05;
            }

		else if(p1->yingfa>2000&&p1->yingfa<=5000)                                //应发工资在2000到5000
			{
				p1->geren=(p1->yingfa-2000)*0.15+1500*0.1+500*0.05;
		    }

		else if(p1->yingfa>5000&&p1->yingfa<=20000)                                          //应发工资在5000到20000
			{
				p1->geren=(p1->yingfa-5000)*0.2+15000*0.15+1500*0.1+500*0.05;
		    }

		else if(p1->yingfa>20000&&p1->yingfa<=40000)                                                     //应发工资在20000到40000
			{
				p1->geren=(p1->yingfa-20000)*0.25+20000*0.2+15000*0.15+1500*0.1+500*0.05;
		    }

		else if(p1->yingfa>40000&&p1->yingfa<=60000)                                                                 //应发工资在40000到60000
			{
				p1->geren=(p1->yingfa-40000)*0.3+20000*0.25+20000*0.2+15000*0.15+1500*0.1+500*0.05;
		    }

		else if(p1->yingfa>60000&&p1->yingfa<=80000)                                                                            //应发工资在60000到80000
			{
				p1->geren=(p1->yingfa-60000)*0.35+20000*0.3+20000*0.25+20000*0.2+15000*0.15+1500*0.1+500*0.05;
		    }

		else if(p1->yingfa>80000&&p1->yingfa<=100000)                                                                                   //应发工资在80000到100000
			{
				p1->geren=(p1->yingfa-80000)*0.4+20000*0.35+20000*0.3+20000*0.25+20000*0.2+15000*0.15+1500*0.1+500*0.05;
		    }

		else                                                                                                                      //应发工资超过100000
			{
				p1->geren=(p1->yingfa-100000)*0.45+20000*0.4+20000*0.35+20000*0.3+20000*0.25+20000*0.2+15000*0.15+1500*0.1+500*0.05;
		    }
}


void add_wages(zhigong *p1)									//计算实发工资	     
{
		p1->shifa=p1->yingfa-p1->geren;
}
