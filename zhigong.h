#include<iostream>
#include<fstream>
#include<string>
const int M=100;//���峣��
int static n;//���徲̬���� 
using namespace std;
struct zhigong{//����ṹ��
	string id;//����
	string name;//����
	float gangwei;//��λ����
    float xinji;//н������
	float zhiwu;//ְ�����
	float jixiao;//��Ч����
	float yingfa;//Ӧ������
	float geren;//��������˰
	float shifa;//ʵ������
	struct zhigong *prev; //����ǰָ�� 
    struct zhigong *next;//�����ָ�� 
};
void read(zhigong zggz[]);//�ļ���ȡ
void wirte(zhigong zggz[]);//�ļ�д��
void find(zhigong zggz[]);//��ѯ����
void list(zhigong zggz[]);//�������
void modify(zhigong zggz[]);//�޸ĺ���
void del(zhigong zggz[]);//ɾ������
void add(zhigong *p);//���Ӻ���
void grsds(zhigong *p1);//�����������˰����
void add_money(zhigong *p1);//����Ӧ������   
void add_wages(zhigong *p1);//����ʵ������	