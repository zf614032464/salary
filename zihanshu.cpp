#include"zhigong.h"
void read(zhigong zggz[])    //文件读取
{
    fstream f("gz.dat",ios::in|ios::binary);//以二进制方式打开一个输入文件
    if(!f)
      {
         cout<<"Cannot open file"<<endl;
         abort();
      }

    for(int i=0;i<100;i++)
      {

          if(!f.eof())//判断文件是否到达末尾 
             {
                n++;//职工人数加1
                f>>zggz[i].id>>zggz[i].name>>zggz[i].gangwei>>zggz[i].xinji>>zggz[i].zhiwu>>zggz[i].jixiao>>zggz[i].yingfa>>zggz[i].geren>>zggz[i].shifa;
              }//从文件读取数据到结构体数组

           else
               {
                  break;
               }	
      }

    n=n-1;//eof()函数多执行了一次
    f.close();
 }

void wirte(zhigong zggz[])
{                               //文件保存
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
         if(!f.eof())//判断文件是否到达末尾 
            {
               f<<zggz[i].id<<" "<<zggz[i].name<<" "<<zggz[i].gangwei<<" "<<zggz[i].xinji<<" "<<zggz[i].zhiwu<<" "<<zggz[i].jixiao<<" "<<zggz[i].yingfa<<" "<<zggz[i].geren<<" "<<zggz[i].shifa<<" ";
            }
      }
    f.close();
 
    cout<<"       *******************文件已保存，请你进行下一步命令*****************"<<endl;
}

void find(zhigong zggz[])
{                             //查询函数
    string gohao;//定义字符串
    int i;
    cout<<"       ********************请输入你要查询的工号或姓名*******************"<<endl;//通过工号或姓名进行查找
    cin>>gohao;

    for(i=0;i<n;i++)
        {
          if(zggz[i].id==gohao||zggz[i].name==gohao)
             {
               cout<<"此职工信息为："<<endl;
               cout<<"工号 "<<"姓名   "<<"岗位工资 "<<"薪级工资 "<<"职务津贴 "<<"绩效工资 "<<"应发工资 "<<"个人所得税 "<<"实发工资 "<<endl;
               add_money(&zggz[i]);//更正职工应发工资
               grsds(&zggz[i]);//更正职工个人所得税
               add_wages(&zggz[i]);//更正职工实发工资
               cout<<zggz[i].id<<" "<<zggz[i].name<<"      "<<zggz[i].gangwei<<"      "<<zggz[i].xinji<<"      "<<zggz[i].zhiwu<<"      ";
               cout<<zggz[i].jixiao<<"      "<<zggz[i].yingfa<<"      "<<zggz[i].geren<<"      "<<zggz[i].shifa<<endl;
               cout<<"       *********************请你进行下一步命令！*************************"<<endl;
               break;
             }
        }

    if(n==i)
      {
        cout<<"系统中找不到此职工信息，请你核实你输入的工号或姓名是否有错，请重新输入查询命令再进行查询"<<endl;
        return;
      }
}

void list(zhigong zggz[])
{                      //浏览函数
    cout<<"职工信息为："<<endl;
    cout<<"工号 "<<"姓名   "<<"岗位工资 "<<"薪级工资 "<<"职务津贴 "<<"绩效工资 "<<"应发工资 "<<"个人所得税 "<<"实发工资 "<<endl;
    for(int i=0;i<n;i++)
       {
         add_money(&zggz[i]);//更正职工应发工资
         grsds(&zggz[i]);//更正职工个人所得税
         add_wages(&zggz[i]);//更正职工实发工资
         cout<<zggz[i].id<<" "<<zggz[i].name<<"      "<<zggz[i].gangwei<<"      "<<zggz[i].xinji<<"      "<<zggz[i].zhiwu<<"      ";
         cout<<zggz[i].jixiao<<"      "<<zggz[i].yingfa<<"      "<<zggz[i].geren<<"      "<<zggz[i].shifa<<endl;
       } 
    cout<<"       *********************请你进行下一步命令！*************************"<<endl;
}

void modify(zhigong zggz[])
{                            //修改函数
    string gohao;//定义字符串
    int i,k,p;
    zhigong a;
    cout<<"       ********************请输入你要查询的工号或姓名*******************"<<endl;//通过工号或姓名进行查找
    cin>>gohao;

    for(i=0;i<n;i++)
        {
          if(zggz[i].id==gohao||zggz[i].name==gohao)
             {
               cout<<"职工信息为："<<endl;//输出职工修改信息前的信息
               cout<<"工号 "<<"姓名   "<<"岗位工资 "<<"薪级工资 "<<"职务津贴 "<<"绩效工资 "<<"应发工资 "<<"个人所得税 "<<"实发工资 "<<endl;
               cout<<zggz[i].id<<" "<<zggz[i].name<<"      "<<zggz[i].gangwei<<"      "<<zggz[i].xinji<<"      "<<zggz[i].zhiwu<<"      ";
               cout<<zggz[i].jixiao<<"      "<<zggz[i].yingfa<<"      "<<zggz[i].geren<<"      "<<zggz[i].shifa<<endl;

               cout<<"       ****************输入1表示确认修改，输入0表示放弃修改***************"<<endl;
               cin>>k;
               if(k==1)//确认修改的操作
                 {
                   cout<<"请重新录入职工工号、姓名、岗位工资、薪级工资、职务津贴、绩效工资"<<endl;
                   cout<<"工号：";
                   cin>>a.id;//工号
                   cout<<"姓名：";
                   cin>>a.name;//姓名
                   cout<<"岗位工资：";
                   cin>>a.gangwei;//岗位工资
                   cout<<"薪级工资：";
                   cin>>a.xinji;//薪级工资
                   cout<<"职务津贴：";
                   cin>>a.zhiwu;//职务津贴
                   cout<<"绩效工资：";
                   cin>>a.jixiao;//绩效工资
                   zggz[i].id=a.id;
                   zggz[i].name=a.name;
                   zggz[i].gangwei=a.gangwei;
                   zggz[i].xinji=a.xinji;
                   zggz[i].zhiwu=a.zhiwu;
                   zggz[i].jixiao=a.jixiao;
                   add_money(&zggz[i]);//职工应发工资
                   grsds(&zggz[i]);//职工个人所得税
                   add_wages(&zggz[i]);//职工实发工资

                   cout<<"职工信息修改后为："<<endl;//输出职工修改信息后的信息
                   cout<<"工号 "<<"姓名   "<<"岗位工资 "<<"薪级工资 "<<"职务津贴 "<<"绩效工资 "<<"应发工资 "<<"个人所得税 "<<"实发工资 "<<endl;
                   cout<<zggz[i].id<<" "<<zggz[i].name<<"      "<<zggz[i].gangwei<<"      "<<zggz[i].xinji<<"      "<<zggz[i].zhiwu<<"      ";
                   cout<<zggz[i].jixiao<<"      "<<zggz[i].yingfa<<"      "<<zggz[i].geren<<"      "<<zggz[i].shifa<<endl;
                   cout<<"       ***************职工信息已修改，请你进行下一步命令！***************"<<endl;

                   cout<<"       ****************输入1表示确认保存，输入0表示放弃保存***************"<<endl;
                   cin>>p;

                   if(p==1)
                       {
                          wirte(zggz);//确认保存的操作
                          cout<<"       *********************请你进行下一步命令！*************************"<<endl;
                          return;
                       }

                   else
                       {
                          cout<<"       *************职工信息已修改，请你进行下一步命令！*****************"<<endl;//放弃保存后的操作
                          return;
                       }
                 }

              else
                  {
                     cout<<"       *********************请你进行下一步命令！*************************"<<endl;//不修改后的操作
                     return;
                  }
             }
        }

    if(n==i)
        {
           cout<<"系统中找不到此职工信息，请你核实你输入的工号或姓名是否有错，请重新输入查询命令再进行查询"<<endl;
        }

    cout<<"       *********************请你进行下一步命令！*************************"<<endl;
}

void del(zhigong zggz[])  //删除函数
{
    string gohao;//定义字符串
    int i,j,k,p;
    cout<<"       ********************请输入你要查询的工号或姓名*******************"<<endl;//通过工号或姓名进行查找
    cin>>gohao;

    for(i=0;i<n;i++)
        {
            if(zggz[i].id==gohao||zggz[i].name==gohao)
                {
                   cout<<"删除的职工信息为："<<endl;//输出职工修改信息前的信息
                   cout<<"工号 "<<"姓名   "<<"岗位工资 "<<"薪级工资 "<<"职务津贴 "<<"绩效工资 "<<"应发工资 "<<"个人所得税 "<<"实发工资 "<<endl;
                   cout<<zggz[i].id<<" "<<zggz[i].name<<"      "<<zggz[i].gangwei<<"      "<<zggz[i].xinji<<"      "<<zggz[i].zhiwu<<"      ";
                   cout<<zggz[i].jixiao<<"      "<<zggz[i].yingfa<<"      "<<zggz[i].geren<<"      "<<zggz[i].shifa<<endl;

                   cout<<"       ****************输入1表示确认删除，输入0表示放弃删除***************"<<endl;
                   cin>>k;
                   if(k==1)
                       {
                          for(j=i;j<n-1;j++)
                               {	
                                  zggz[j]=zggz[j+1];
                               }
                   n=n-1;

                   cout<<"       ****************输入1表示确认保存，输入0表示放弃保存***************"<<endl;
                   cin>>p;
                   if(p==1)
                        {
                           wirte(zggz);//确认删除的操作
                           return;
                        }

                   else
                        {
                           cout<<"       *************职工信息已修改，请你进行下一步命令！*****************"<<endl;//放弃删除后的操作
                           return;
                        }

                   cout<<"删除后剩余职工的信息为："<<endl;
                   cout<<"工号 "<<"姓名   "<<"岗位工资 "<<"薪级工资 "<<"职务津贴 "<<"绩效工资 "<<"应发工资 "<<"个人所得税 "<<"实发工资 "<<endl;
                   for(i=0;i<n;i++)
                        {
                           cout<<zggz[i].id<<" "<<zggz[i].name<<"      "<<zggz[i].gangwei<<"      "<<zggz[i].xinji<<"      "<<zggz[i].zhiwu<<"      ";
                           cout<<zggz[i].jixiao<<"      "<<zggz[i].yingfa<<"      "<<zggz[i].geren<<"      "<<zggz[i].shifa<<endl;
                        }

                   cout<<"       *********************请你进行下一步命令！*************************"<<endl;
                   return;
                       }

                   else
                       {
                          cout<<"       *********************请你进行下一步命令！*************************"<<endl;//未找到职工信息后的操作
                          return;
                       }
                }
        }

    if(n==i)
        {
           cout<<"系统中找不到此职工信息，请你核实你输入的工号或姓名是否有错，请重新输入查询命令再进行查询"<<endl;
        }
    cout<<"       *********************请你进行下一步命令！*************************"<<endl;
}

void add(zhigong *p)//增加函数
{
    int k,a;
	zhigong *q=p;
    if(n==100)
        {
           cout<<"       **************职工人数已满，不能添加职工了***************"<<endl;
           cout<<"       *********************请你输入其他命令*************************"<<endl;
           return;
        }

    else
        {
          p=p+n;//把指针移到数组末尾
          n=n+1;
          cout<<"       ***********************请你录入用户信息***************************"<<endl;//通过工号或姓名进行查找
          cout<<"工号：";
          cin>>p->id;//工号
          for(int i=0;i<n-1;i++,q++)//判断工号相同的不能添加
               if(p->id==q->id)
                  {
                     cout<<"       ****************工号已存在，请重新输入命令************************"<<endl;
                     return;
                  }
          cout<<"姓名：";
          cin>>p->name;//姓名
          cout<<"岗位工资：";
          cin>>p->gangwei;//岗位工资
          cout<<"薪级工资：";
          cin>>p->xinji;//薪级工资
          cout<<"职务津贴：";
          cin>>p->zhiwu;//职务津贴
          cout<<"绩效工资：";
          cin>>p->jixiao;//绩效工资
          add_money(p);//应发工资
          grsds(p);//个人所得税
          add_wages(p);//实发工资
          cout<<"职工信息为："<<endl;
          cout<<"工号 "<<"姓名   "<<"岗位工资 "<<"薪级工资 "<<"职务津贴 "<<"绩效工资 "<<"应发工资 "<<"个人所得税 "<<"实发工资 "<<endl;
          cout<<p->id<<" "<<p->name<<"      "<<p->gangwei<<"      "<<p->xinji<<"      "<<p->zhiwu<<"      ";
          cout<<p->jixiao<<"      "<<p->yingfa<<"      "<<p->geren<<"      "<<p->shifa<<endl;

          cout<<"       ****************输入1表示确认增加，输入0表示放弃增加***************"<<endl;
          cin>>k;
          if(k==1)
                {
                    p=p-n+1;
                    wirte(p);//确认增加的操作
                    return;
                }

          else
                {
                    cout<<"       *********************请你进行下一步命令！*************************"<<endl;//放弃增加后的操作
                    return;
                }
    cout<<"       *********************请你进行下一步命令！*************************"<<endl;
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
                p1->geren=(p1->yingfa-5000)*0.2+3000*0.15+1500*0.1+500*0.05;
            }

        else if(p1->yingfa>20000&&p1->yingfa<=40000)                                                     //应发工资在20000到40000
            {
                p1->geren=(p1->yingfa-20000)*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;
            }

        else if(p1->yingfa>40000&&p1->yingfa<=60000)                                                                 //应发工资在40000到60000
            {
                p1->geren=(p1->yingfa-40000)*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;
            }

        else if(p1->yingfa>60000&&p1->yingfa<=80000)                                                                            //应发工资在60000到80000
            {
                p1->geren=(p1->yingfa-60000)*0.35+20000*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;
            }

        else if(p1->yingfa>80000&&p1->yingfa<=100000)                                                                                   //应发工资在80000到100000
            {
                p1->geren=(p1->yingfa-80000)*0.4+20000*0.35+20000*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;
            }

        else                                                                                                                      //应发工资超过100000
            {
                p1->geren=(p1->yingfa-100000)*0.45+20000*0.4+20000*0.35+20000*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;
            }
}


void add_wages(zhigong *p1)									//计算实发工资	     
{
        p1->shifa=p1->yingfa-p1->geren;
}
