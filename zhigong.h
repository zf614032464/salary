/********************************************
Copyright(C),2018-2021,guangximinzhudaxue
Author:zhangfeng  Version:ͷ�ļ�  Date:2018.6.24
Description:ͷ�ļ�
Version:ͷ�ļ�
Funtion List:
1.void read(zhigong zggz[]) �ļ�д��
2.void wirte(zhigong zggz[])�ļ�����
3.void find(zhigong zggz[]) ��ѯְ����Ϣ
4.void list(zhigong zggz[]) ���ְ����Ϣ
5.void modify(zhigong zggz[])�޸�ְ����Ϣ
6.void del(zhigong zggz[]) ɾ��ְ����Ϣ
7.void add(zhigong *p) ����ְ����Ϣ
8.void grsds(zhigong *p1)�����������˰
9.void add_money(zhigong *p1)����Ӧ������
10.void add_wages(zhigong *p1)����ʵ������	
*********************************************/
#include<iostream>
#include<stdio.h>
#include<cstring>
#include<fstream>
#include<string>
const int M=100;//���峣��
int static n;//���徲̬���� 
using namespace std;
struct zhigong{//����ṹ��
    char id[11];//����
    char name[11];//����
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