#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "macro_file.h"                        	//�궨���ļ�
#include "struct_file.h"                       	//�ṹ���ļ�
#include "function_declare_file.h"           	//���������ļ�
#include "student_file.c"                      	//ѧ�������ļ�
#include "administrator_file.c"               	//����Ա�����ļ�
//ȫ�ֱ���
int stu_Count;
int package_Count;
int teach_Count;
int select_Count;
long user_num;
//main����
void main()
{
	int temp,choice,t=-1;
	welcome();                 	//��ӭ����
	choice=user_type();        	//�û�ѡ����ݽ���
	if(choice!=0){
		//����ѧ����Ϣ�ļ�
		Load_student_information("student_information_file.txt"); 
        Load_package_information("package_information_file.txt");
		printf("Press any key to continue\n");
getchar();
if(getchar()) system("cls"); 
    		//����
    		if(choice==1){	
       t=regs();//ע����� 
   }
       if(t==1){
       	regs_student();
	   }
	   if(t==0){
	   exit_system(); 
	   }
		temp=land(choice);    	//��¼������֤
		if(temp==YES)        	//��¼�ɹ�
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
			printf("\n�Բ������ĵ�¼���������꣡\n��ӭ�´ε�¼��\n");  //��¼ʧ��
	}
	else
		printf("\nϵͳ���˳�����ӭ�´ε�¼��\n");
}
//��ӭ����
void welcome()
{
	printf("\n\n\n\n\n\n\n\n\n");
	printf("\t\t|*^**^**^**^**^**^**^**^**^**^**^**^**^**^**^|\n");
	printf("\t\t+============================================+\n");
	printf("\t\t&&|             @  *��*��*��*��*��*��*��*  @ |&&\n");
	printf("\t\t&&|             .                      .     |&&\n");
	printf("\t\t&&|             * ��ӭʹ�ò�����վ����ϵͳ *     |&&\n");
	printf("\t\t&&|             .                      .     |&&\n");
	printf("\t\t&&|             @  *��*��*��*��*��*��*��*  @ |&&\n");
	printf("\t\t+============================================+\n");
	printf("\t\t*-^@^-----^@^-----^@^----^@^-----^@^-----^@^-*\n");
	printf("\n\n\n\n��Enter�����ء���");
	if(getchar())
		system("cls");
}
//ע����� 
int regs()
{
	int ch;
	ch = -1;
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n");
	printf("\t\t|*^**^**^**^**^**^**^**^**^**^**^**^**^**^**^|\n");
	printf("\t\t+============================================+\n");
	printf("\t\t\t@  [1]----------���û�                     | @\n");
	printf("\t\t\t@  [2]----------���û�                     | @\n");
	printf("\t\t\t@  [0]--------�˳�ϵͳ                     | @\n");
	printf("\t\t+============================================+\n");
	printf("\t\t*-^@^-----^@^-----^@^----^@^-----^@^-----^@^-*\n");
	printf("\n\n\n����������ѡ��");
	 scanf("%d", &ch);
	 if(getchar()) 
	 system("cls"); 
    return ch;
} 
//���Ƶ�¼�ĺ���
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
			printf("\n�Բ�����ѡ�����\n");
			break;
	}
	return temp;
}
//ѡ���û����ͽ���
int user_type()
{
	int choice;
	choice = -1;
	system("cls");
	printf("\n\n\n\n��ܰ��ʾ������������˳���˳�ϵͳ^_^\n");
	printf("-------------------------------------------------------\n");
	printf("\n");
	printf("\t\t\t@��@��@��@��@��@��@��@��@��@��@��@\n");
	printf("\t\t\t@             �û�����           @\n");  
	printf("\t\t\t@��@��@��@��@��@��@��@��@��@��@��@\n");               
	printf("\t\t\t@  [1]----------ѧ��             @\n");
	printf("\t\t\t@  [2]----------����Ա           @\n");
	printf("\t\t\t@  [0]--------�˳�ϵͳ           @\n");
	printf("\t\t\t@��@��@��@��@��@��@��@��@��@��@��@\n");
	printf("\t\t-----------------------------------------\n");
    printf("\n\n\n����������ѡ��");
    scanf("%d", &choice);
    return choice;
}

//ϵͳ�˳�����
void exit_system()
{
	//����ѧ����Ϣ
	save_student_information("student_information_file.txt");   
    save_package_information("package_information_file.txt");
	//�˳�����
	system("cls");
	printf("\n\n\n\n\n");
	printf("\t\t\t|^-^**^-^**^-^**^--^**^-^**^-^**^-^|\n");
	printf("\t\t\t|+                                +|\n");
	printf("\t\t\t|+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+|\n");
	printf("\t\t\t|+*                              *+|\n");
	printf("\t\t\t|+(^o^)лл����ʹ�ã���ӭ�´ε�¼!+|\n");
	printf("\t\t\t|+*                              *+|\n");
	printf("\t\t\t|+*                              *+|\n");
	printf("\t\t\t|+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+|\n");
	printf("\t\t\t|*@ . &. @. &. @. &. @. &. @. &. @*|\n");
	printf("\n\n\n\n\n");
	exit(0);
}
