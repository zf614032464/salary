#include<iostream>
#include<fstream>
#include<string>
const int M=100;//定义常量
int static n;//定义静态变量 
using namespace std;
struct zhigong{//定义结构体
	string id;//工号
	string name;//姓名
	float gangwei;//岗位工资
    float xinji;//薪级工资
	float zhiwu;//职务津贴
	float jixiao;//绩效工资
	float yingfa;//应发工资
	float geren;//个人所得税
	float shifa;//实发工资
	struct zhigong *prev; //定义前指针 
    struct zhigong *next;//定义后指针 
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