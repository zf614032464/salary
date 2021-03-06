/********************************************
Copyright(C),2018-2021,guangximinzhudaxue
Author:zhangfeng  Version:头文件  Date:2018.6.24
Description:头文件
Version:头文件
Funtion List:
1.void read(zhigong zggz[]) 文件写入
2.void wirte(zhigong zggz[])文件保存
3.void find(zhigong zggz[]) 查询职工信息
4.void list(zhigong zggz[]) 浏览职工信息
5.void modify(zhigong zggz[])修改职工信息
6.void del(zhigong zggz[]) 删除职工信息
7.void add(zhigong *p) 增加职工信息
8.void grsds(zhigong *p1)计算个人所得税
9.void add_money(zhigong *p1)计算应发工资
10.void add_wages(zhigong *p1)计算实发工资	
*********************************************/
#include<iostream>
#include<stdio.h>
#include<cstring>
#include<fstream>
#include<string>
#include<string.h>
#include<stdarg.h>
#include<stdlib.h>
#include<malloc.h>
const int M=100;//定义常量
int static n;//定义静态变量 
using namespace std;

struct zhigong{//定义结构体
    char id[11];//工号
    char name[11];//姓名
    float gangwei;//岗位工资
    float xinji;//薪级工资
    float zhiwu;//职务津贴
    float jixiao;//绩效工资
    float yingfa;//应发工资
    float geren;//个人所得税
    float shifa;//实发工资
    struct zhigong *prior;//指向前驱结点
    struct zhigong *next; //指向后继结点
};

void read(zhigong zggz[]);//文件读取
void wirte(zhigong zggz[]);//文件写入
void find(zhigong zggz[]);//查询函数
void list(zhigong zggz[]);//浏览函数
void modify(zhigong zggz[]);//修改函数
void del(zhigong zggz[]);//删除函数
void add(zhigong *p);//增加函数
void grsds(zhigong *p1);//计算个人所得税函数
void add_money(zhigong *p1);//计算应发工资   
void add_wages(zhigong *p1);//计算实发工资	

