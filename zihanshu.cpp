#include"zhigong.h"
void read(zhigong zggz[])    //�ļ���ȡ
{
    fstream f("gz.dat",ios::in|ios::binary);//�Զ����Ʒ�ʽ��һ�������ļ�
    if(!f)
      {
         cout<<"Cannot open file"<<endl;
         abort();
      }

    for(int i=0;i<100;i++)
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

    n=n-1;//eof()������ִ����һ��
    f.close();
 }

void wirte(zhigong zggz[])
{                               //�ļ�����
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
         if(!f.eof())//�ж��ļ��Ƿ񵽴�ĩβ 
            {
               f<<zggz[i].id<<" "<<zggz[i].name<<" "<<zggz[i].gangwei<<" "<<zggz[i].xinji<<" "<<zggz[i].zhiwu<<" "<<zggz[i].jixiao<<" "<<zggz[i].yingfa<<" "<<zggz[i].geren<<" "<<zggz[i].shifa<<" ";
            }
      }
    f.close();
 
    cout<<"       *******************�ļ��ѱ��棬���������һ������*****************"<<endl;
}

void find(zhigong zggz[])
{                             //��ѯ����
    string gohao;//�����ַ���
    int i;
    cout<<"       ********************��������Ҫ��ѯ�Ĺ��Ż�����*******************"<<endl;//ͨ�����Ż��������в���
    cin>>gohao;

    for(i=0;i<n;i++)
        {
          if(zggz[i].id==gohao||zggz[i].name==gohao)
             {
               cout<<"��ְ����ϢΪ��"<<endl;
               cout<<"���� "<<"����   "<<"��λ���� "<<"н������ "<<"ְ����� "<<"��Ч���� "<<"Ӧ������ "<<"��������˰ "<<"ʵ������ "<<endl;
               add_money(&zggz[i]);//����ְ��Ӧ������
               grsds(&zggz[i]);//����ְ����������˰
               add_wages(&zggz[i]);//����ְ��ʵ������
               cout<<zggz[i].id<<" "<<zggz[i].name<<"      "<<zggz[i].gangwei<<"      "<<zggz[i].xinji<<"      "<<zggz[i].zhiwu<<"      ";
               cout<<zggz[i].jixiao<<"      "<<zggz[i].yingfa<<"      "<<zggz[i].geren<<"      "<<zggz[i].shifa<<endl;
               cout<<"       *********************���������һ�����*************************"<<endl;
               break;
             }
        }

    if(n==i)
      {
        cout<<"ϵͳ���Ҳ�����ְ����Ϣ�������ʵ������Ĺ��Ż������Ƿ��д������������ѯ�����ٽ��в�ѯ"<<endl;
        return;
      }
}

void list(zhigong zggz[])
{                      //�������
    cout<<"ְ����ϢΪ��"<<endl;
    cout<<"���� "<<"����   "<<"��λ���� "<<"н������ "<<"ְ����� "<<"��Ч���� "<<"Ӧ������ "<<"��������˰ "<<"ʵ������ "<<endl;
    for(int i=0;i<n;i++)
       {
         add_money(&zggz[i]);//����ְ��Ӧ������
         grsds(&zggz[i]);//����ְ����������˰
         add_wages(&zggz[i]);//����ְ��ʵ������
         cout<<zggz[i].id<<" "<<zggz[i].name<<"      "<<zggz[i].gangwei<<"      "<<zggz[i].xinji<<"      "<<zggz[i].zhiwu<<"      ";
         cout<<zggz[i].jixiao<<"      "<<zggz[i].yingfa<<"      "<<zggz[i].geren<<"      "<<zggz[i].shifa<<endl;
       } 
    cout<<"       *********************���������һ�����*************************"<<endl;
}

void modify(zhigong zggz[])
{                            //�޸ĺ���
    string gohao;//�����ַ���
    int i,k,p;
    zhigong a;
    cout<<"       ********************��������Ҫ��ѯ�Ĺ��Ż�����*******************"<<endl;//ͨ�����Ż��������в���
    cin>>gohao;

    for(i=0;i<n;i++)
        {
          if(zggz[i].id==gohao||zggz[i].name==gohao)
             {
               cout<<"ְ����ϢΪ��"<<endl;//���ְ���޸���Ϣǰ����Ϣ
               cout<<"���� "<<"����   "<<"��λ���� "<<"н������ "<<"ְ����� "<<"��Ч���� "<<"Ӧ������ "<<"��������˰ "<<"ʵ������ "<<endl;
               cout<<zggz[i].id<<" "<<zggz[i].name<<"      "<<zggz[i].gangwei<<"      "<<zggz[i].xinji<<"      "<<zggz[i].zhiwu<<"      ";
               cout<<zggz[i].jixiao<<"      "<<zggz[i].yingfa<<"      "<<zggz[i].geren<<"      "<<zggz[i].shifa<<endl;

               cout<<"       ****************����1��ʾȷ���޸ģ�����0��ʾ�����޸�***************"<<endl;
               cin>>k;
               if(k==1)//ȷ���޸ĵĲ���
                 {
                   cout<<"������¼��ְ�����š���������λ���ʡ�н�����ʡ�ְ���������Ч����"<<endl;
                   cout<<"���ţ�";
                   cin>>a.id;//����
                   cout<<"������";
                   cin>>a.name;//����
                   cout<<"��λ���ʣ�";
                   cin>>a.gangwei;//��λ����
                   cout<<"н�����ʣ�";
                   cin>>a.xinji;//н������
                   cout<<"ְ�������";
                   cin>>a.zhiwu;//ְ�����
                   cout<<"��Ч���ʣ�";
                   cin>>a.jixiao;//��Ч����
                   zggz[i].id=a.id;
                   zggz[i].name=a.name;
                   zggz[i].gangwei=a.gangwei;
                   zggz[i].xinji=a.xinji;
                   zggz[i].zhiwu=a.zhiwu;
                   zggz[i].jixiao=a.jixiao;
                   add_money(&zggz[i]);//ְ��Ӧ������
                   grsds(&zggz[i]);//ְ����������˰
                   add_wages(&zggz[i]);//ְ��ʵ������

                   cout<<"ְ����Ϣ�޸ĺ�Ϊ��"<<endl;//���ְ���޸���Ϣ�����Ϣ
                   cout<<"���� "<<"����   "<<"��λ���� "<<"н������ "<<"ְ����� "<<"��Ч���� "<<"Ӧ������ "<<"��������˰ "<<"ʵ������ "<<endl;
                   cout<<zggz[i].id<<" "<<zggz[i].name<<"      "<<zggz[i].gangwei<<"      "<<zggz[i].xinji<<"      "<<zggz[i].zhiwu<<"      ";
                   cout<<zggz[i].jixiao<<"      "<<zggz[i].yingfa<<"      "<<zggz[i].geren<<"      "<<zggz[i].shifa<<endl;
                   cout<<"       ***************ְ����Ϣ���޸ģ����������һ�����***************"<<endl;

                   cout<<"       ****************����1��ʾȷ�ϱ��棬����0��ʾ��������***************"<<endl;
                   cin>>p;

                   if(p==1)
                       {
                          wirte(zggz);//ȷ�ϱ���Ĳ���
                          cout<<"       *********************���������һ�����*************************"<<endl;
                          return;
                       }

                   else
                       {
                          cout<<"       *************ְ����Ϣ���޸ģ����������һ�����*****************"<<endl;//���������Ĳ���
                          return;
                       }
                 }

              else
                  {
                     cout<<"       *********************���������һ�����*************************"<<endl;//���޸ĺ�Ĳ���
                     return;
                  }
             }
        }

    if(n==i)
        {
           cout<<"ϵͳ���Ҳ�����ְ����Ϣ�������ʵ������Ĺ��Ż������Ƿ��д������������ѯ�����ٽ��в�ѯ"<<endl;
        }

    cout<<"       *********************���������һ�����*************************"<<endl;
}

void del(zhigong zggz[])  //ɾ������
{
    string gohao;//�����ַ���
    int i,j,k,p;
    cout<<"       ********************��������Ҫ��ѯ�Ĺ��Ż�����*******************"<<endl;//ͨ�����Ż��������в���
    cin>>gohao;

    for(i=0;i<n;i++)
        {
            if(zggz[i].id==gohao||zggz[i].name==gohao)
                {
                   cout<<"ɾ����ְ����ϢΪ��"<<endl;//���ְ���޸���Ϣǰ����Ϣ
                   cout<<"���� "<<"����   "<<"��λ���� "<<"н������ "<<"ְ����� "<<"��Ч���� "<<"Ӧ������ "<<"��������˰ "<<"ʵ������ "<<endl;
                   cout<<zggz[i].id<<" "<<zggz[i].name<<"      "<<zggz[i].gangwei<<"      "<<zggz[i].xinji<<"      "<<zggz[i].zhiwu<<"      ";
                   cout<<zggz[i].jixiao<<"      "<<zggz[i].yingfa<<"      "<<zggz[i].geren<<"      "<<zggz[i].shifa<<endl;

                   cout<<"       ****************����1��ʾȷ��ɾ��������0��ʾ����ɾ��***************"<<endl;
                   cin>>k;
                   if(k==1)
                       {
                          for(j=i;j<n-1;j++)
                               {	
                                  zggz[j]=zggz[j+1];
                               }
                   n=n-1;

                   cout<<"       ****************����1��ʾȷ�ϱ��棬����0��ʾ��������***************"<<endl;
                   cin>>p;
                   if(p==1)
                        {
                           wirte(zggz);//ȷ��ɾ���Ĳ���
                           return;
                        }

                   else
                        {
                           cout<<"       *************ְ����Ϣ���޸ģ����������һ�����*****************"<<endl;//����ɾ����Ĳ���
                           return;
                        }

                   cout<<"ɾ����ʣ��ְ������ϢΪ��"<<endl;
                   cout<<"���� "<<"����   "<<"��λ���� "<<"н������ "<<"ְ����� "<<"��Ч���� "<<"Ӧ������ "<<"��������˰ "<<"ʵ������ "<<endl;
                   for(i=0;i<n;i++)
                        {
                           cout<<zggz[i].id<<" "<<zggz[i].name<<"      "<<zggz[i].gangwei<<"      "<<zggz[i].xinji<<"      "<<zggz[i].zhiwu<<"      ";
                           cout<<zggz[i].jixiao<<"      "<<zggz[i].yingfa<<"      "<<zggz[i].geren<<"      "<<zggz[i].shifa<<endl;
                        }

                   cout<<"       *********************���������һ�����*************************"<<endl;
                   return;
                       }

                   else
                       {
                          cout<<"       *********************���������һ�����*************************"<<endl;//δ�ҵ�ְ����Ϣ��Ĳ���
                          return;
                       }
                }
        }

    if(n==i)
        {
           cout<<"ϵͳ���Ҳ�����ְ����Ϣ�������ʵ������Ĺ��Ż������Ƿ��д������������ѯ�����ٽ��в�ѯ"<<endl;
        }
    cout<<"       *********************���������һ�����*************************"<<endl;
}

void add(zhigong *p)//���Ӻ���
{
    int k,a;
	zhigong *q=p;
    if(n==100)
        {
           cout<<"       **************ְ�������������������ְ����***************"<<endl;
           cout<<"       *********************����������������*************************"<<endl;
           return;
        }

    else
        {
          p=p+n;//��ָ���Ƶ�����ĩβ
          n=n+1;
          cout<<"       ***********************����¼���û���Ϣ***************************"<<endl;//ͨ�����Ż��������в���
          cout<<"���ţ�";
          cin>>p->id;//����
          for(int i=0;i<n-1;i++,q++)//�жϹ�����ͬ�Ĳ������
               if(p->id==q->id)
                  {
                     cout<<"       ****************�����Ѵ��ڣ���������������************************"<<endl;
                     return;
                  }
          cout<<"������";
          cin>>p->name;//����
          cout<<"��λ���ʣ�";
          cin>>p->gangwei;//��λ����
          cout<<"н�����ʣ�";
          cin>>p->xinji;//н������
          cout<<"ְ�������";
          cin>>p->zhiwu;//ְ�����
          cout<<"��Ч���ʣ�";
          cin>>p->jixiao;//��Ч����
          add_money(p);//Ӧ������
          grsds(p);//��������˰
          add_wages(p);//ʵ������
          cout<<"ְ����ϢΪ��"<<endl;
          cout<<"���� "<<"����   "<<"��λ���� "<<"н������ "<<"ְ����� "<<"��Ч���� "<<"Ӧ������ "<<"��������˰ "<<"ʵ������ "<<endl;
          cout<<p->id<<" "<<p->name<<"      "<<p->gangwei<<"      "<<p->xinji<<"      "<<p->zhiwu<<"      ";
          cout<<p->jixiao<<"      "<<p->yingfa<<"      "<<p->geren<<"      "<<p->shifa<<endl;

          cout<<"       ****************����1��ʾȷ�����ӣ�����0��ʾ��������***************"<<endl;
          cin>>k;
          if(k==1)
                {
                    p=p-n+1;
                    wirte(p);//ȷ�����ӵĲ���
                    return;
                }

          else
                {
                    cout<<"       *********************���������һ�����*************************"<<endl;//�������Ӻ�Ĳ���
                    return;
                }
    cout<<"       *********************���������һ�����*************************"<<endl;
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
                p1->geren=(p1->yingfa-5000)*0.2+3000*0.15+1500*0.1+500*0.05;
            }

        else if(p1->yingfa>20000&&p1->yingfa<=40000)                                                     //Ӧ��������20000��40000
            {
                p1->geren=(p1->yingfa-20000)*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;
            }

        else if(p1->yingfa>40000&&p1->yingfa<=60000)                                                                 //Ӧ��������40000��60000
            {
                p1->geren=(p1->yingfa-40000)*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;
            }

        else if(p1->yingfa>60000&&p1->yingfa<=80000)                                                                            //Ӧ��������60000��80000
            {
                p1->geren=(p1->yingfa-60000)*0.35+20000*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;
            }

        else if(p1->yingfa>80000&&p1->yingfa<=100000)                                                                                   //Ӧ��������80000��100000
            {
                p1->geren=(p1->yingfa-80000)*0.4+20000*0.35+20000*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;
            }

        else                                                                                                                      //Ӧ�����ʳ���100000
            {
                p1->geren=(p1->yingfa-100000)*0.45+20000*0.4+20000*0.35+20000*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;
            }
}


void add_wages(zhigong *p1)									//����ʵ������	     
{
        p1->shifa=p1->yingfa-p1->geren;
}
