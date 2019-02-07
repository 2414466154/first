#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "macro_file.h"                        	//宏定义文件
#include "struct_file.h"                       	//结构体文件
#include "function_declare_file.h"           	//函数声明文件
#include "student_file.c"                      	//学生代码文件
#include "administrator_file.c"               	//管理员代码文件
//全局变量
int stu_Count;
int package_Count;
int teach_Count;
int select_Count;
long user_num;
//main函数
void main()
{
	int temp,choice,t=-1;
	welcome();                 	//欢迎界面
	choice=user_type();        	//用户选择身份界面
	if(choice!=0){
		//载入学生信息文件
		Load_student_information("student_information_file.txt"); 
        Load_package_information("package_information_file.txt");
		printf("Press any key to continue\n");
getchar();
if(getchar()) system("cls"); 
    		//清屏
    		if(choice==1){	
       t=regs();//注册界面 
   }
       if(t==1){
       	regs_student();
	   }
	   if(t==0){
	   exit_system(); 
	   }
		temp=land(choice);    	//登录密码验证
		if(temp==YES)        	//登录成功
		{	
            system("cls");
			switch(choice){
			case 1:
				student();
				break;
			case 2:
				administrator();
				break;
			}
		}
		else
			printf("\n对不起，您的登录机会已用完！\n欢迎下次登录！\n");  //登录失败
	}
	else
		printf("\n系统已退出，欢迎下次登录！\n");
}
//欢迎界面
void welcome()
{
	printf("\n\n\n\n\n\n\n\n\n");
	printf("\t\t|*^**^**^**^**^**^**^**^**^**^**^**^**^**^**^|\n");
	printf("\t\t+============================================+\n");
	printf("\t\t&&|             @  *·*·*·*·*·*·*·*  @ |&&\n");
	printf("\t\t&&|             .                      .     |&&\n");
	printf("\t\t&&|             * 欢迎使用菜鸟驿站管理系统 *     |&&\n");
	printf("\t\t&&|             .                      .     |&&\n");
	printf("\t\t&&|             @  *·*·*·*·*·*·*·*  @ |&&\n");
	printf("\t\t+============================================+\n");
	printf("\t\t*-^@^-----^@^-----^@^----^@^-----^@^-----^@^-*\n");
	printf("\n\n\n\n按Enter键返回……");
	if(getchar())
		system("cls");
}
//注册界面 
int regs()
{
	int ch;
	ch = -1;
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n");
	printf("\t\t|*^**^**^**^**^**^**^**^**^**^**^**^**^**^**^|\n");
	printf("\t\t+============================================+\n");
	printf("\t\t\t@  [1]----------新用户                     | @\n");
	printf("\t\t\t@  [2]----------老用户                     | @\n");
	printf("\t\t\t@  [0]--------退出系统                     | @\n");
	printf("\t\t+============================================+\n");
	printf("\t\t*-^@^-----^@^-----^@^----^@^-----^@^-----^@^-*\n");
	printf("\n\n\n请输入您的选择：");
	 scanf("%d", &ch);
	 if(getchar()) 
	 system("cls"); 
    return ch;
} 
//控制登录的函数
int land(int user_type)
{
	int temp;
	switch(user_type){
		case 1:
			temp=stu_land();
			break;
		case 2:
			temp=admin_land();
			break;
		default:
			printf("\n对不起，您选择错误！\n");
			break;
	}
	return temp;
}
//选择用户类型界面
int user_type()
{
	int choice;
	choice = -1;
	system("cls");
	printf("\n\n\n\n温馨提示：请您按正常顺序退出系统^_^\n");
	printf("-------------------------------------------------------\n");
	printf("\n");
	printf("\t\t\t@·@·@·@·@·@·@·@·@·@·@·@\n");
	printf("\t\t\t@             用户类型           @\n");  
	printf("\t\t\t@·@·@·@·@·@·@·@·@·@·@·@\n");               
	printf("\t\t\t@  [1]----------学生             @\n");
	printf("\t\t\t@  [2]----------管理员           @\n");
	printf("\t\t\t@  [0]--------退出系统           @\n");
	printf("\t\t\t@·@·@·@·@·@·@·@·@·@·@·@\n");
	printf("\t\t-----------------------------------------\n");
    printf("\n\n\n请输入您的选择：");
    scanf("%d", &choice);
    return choice;
}

//系统退出函数
void exit_system()
{
	//保存学生信息
	save_student_information("student_information_file.txt");   
    save_package_information("package_information_file.txt");
	//退出界面
	system("cls");
	printf("\n\n\n\n\n");
	printf("\t\t\t|^-^**^-^**^-^**^--^**^-^**^-^**^-^|\n");
	printf("\t\t\t|+                                +|\n");
	printf("\t\t\t|+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+|\n");
	printf("\t\t\t|+*                              *+|\n");
	printf("\t\t\t|+(^o^)谢谢您的使用，欢迎下次登录!+|\n");
	printf("\t\t\t|+*                              *+|\n");
	printf("\t\t\t|+*                              *+|\n");
	printf("\t\t\t|+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+|\n");
	printf("\t\t\t|*@ . &. @. &. @. &. @. &. @. &. @*|\n");
	printf("\n\n\n\n\n");
	exit(0);
}
