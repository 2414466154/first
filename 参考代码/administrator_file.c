extern int package_Count;
extern long user_num;
//载入货物信息的函数
//搜索学生函数
int package_search(long package_num)
{	
	int i;
	for(i=0;i<package_Count;i++)
		if(pac[i].num==package_num) return i;
	return NO_FOUND;	
}
void Load_package_information(char * file_name)
{
	FILE *fp;
	struct package *p;
	if((fp=fopen(file_name,"r"))==NULL)
	{
		printf("未找到货物文件！\n");
		return;
	}
	while(!feof(fp))
	{
		p=(struct package *)malloc(sizeof(struct package));
		if(fscanf(fp,"%ld%s%s%d%d%d%s%s\r",&p->num,p->name,p->phone,&p->tim.year,&p->tim.month,&p->tim.day,p->state,p->code)==0)
		{
			printf("货物文件载入失败!\n");
			return;
		}
		pac[package_Count]=*p;
		package_Count++;
	}
	printf("package_Count=%d",package_Count);
	free(p);
	fclose(fp);
	printf("\n货物文件已载入!\n\n");
}

//保存快递信息的函数
void save_package_information(char *file_name)
{
	FILE *fp;
	struct package *p;
	int i;
	if((fp=fopen(file_name,"w"))==NULL)
		printf("未找到货物文件,不能保存!\n");
	for(i=0;i<package_Count;i++)
	{
		p=(struct package *)malloc(sizeof(struct package));
		*p=pac[i];
	if(fprintf(fp,"%ld%s%s%d%d%d%s%s\r",&p->num,p->name,p->phone,&p->tim.year,&p->tim.month,&p->tim.day,p->state,p->code)==0)
		{
			printf("货物文件保存失败!\n");
			return;
		}
	}
	free(p);
	fclose(fp); 
	printf("货物文件已保存!\n");
}

//管理员登录密码验证
int admin_land()
{
	int i=1,j;
	char user_name[15];
	char admin_pwd[15];
	do{
		printf("\n请输入管理员用户名:");
		scanf("%s",user_name);
		printf("\n请输入管理员密码:");
				for(j=0;;j++)
  {
      admin_pwd[j]=getch();
       if(admin_pwd[j]=='\x0d')
  {
        admin_pwd[j]='\0';
         break;
   }
      if(admin_pwd[j]==8&&j>0)
      {
           printf("\b \b");
              j=j-2;
           continue;
      }
          printf("*");
} 
		if((strcmp(user_name,ADMIN_PASSWARD)==0 && 
              strcmp(admin_pwd,ADMIN_PASSWARD)==0)) 
			return YES;
		else
			printf("\n密码错误！");
		printf("请重新输入!\n");
		i++;
		printf("---------------------------------------------------\n");
	}while(i<=3);    
	return NO;
}

//管理员功能主菜单
int admin_menu()
{
	int choice;
	choice = -1;
	printf("\n温馨提示：请您按正常顺序退出系统^_^\n");
	printf("-------------------------------------------------------\n");
	printf("\n");
	printf("\t\t\t*-----*-----*-----*-----*----*-----*\n");
	printf("\t\t\t|+         管 理 员 管 理 系 统          |\n");  
	printf("\t\t\t|+!^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^!+|\n");               
	printf("\t\t\t|+        【1】**** 维护用户信息       +|\n");
	printf("\t\t\t|+        【2】**** 维护货物信息       +|\n");
//	printf("\t\t\t|+        【3】**** 维护课程信息       +|\n");
	printf("\t\t\t|+        【0】**** 退出系统           +|\n");
	printf("\t\t\t|+*·*·*·*·*·*·*·*·* *·*·*·*·*·*·*·*+|\n");
	printf("\n");
	printf("-------------------------------------------------------\n");
	printf("请输入您的选择：");
	scanf("%d", &choice);
	return choice;
}
//管理员功能控制函数
void administrator()
{
	int choice;
	system("cls");
	do{
		choice=admin_menu();
		system("cls");
		switch(choice){
		case 1:
			manage_student();
			break;
		case 2:
			manage_package();
			break;	
		case 0:
			exit_system();
			break;
		default:
			printf("\n对不起，您选择错误！\n");
			break;
		}
		system("cls");
	}while(1);
}

//维护学生信息的菜单和控制流程
void manage_student()
{
	int choice;	
	do{
		printf("\t\t\t***************************\n");
		printf("\t\t\t**  录入用户信息     请按1  **\n");
		printf("\t\t\t**  浏览用户信息     请按2  **\n");
		printf("\t\t\t**  删除用户信息     请按3  **\n");
		printf("\t\t\t**  取消             请按0  **\n");
		printf("\t\t\t***************************\n");
		printf("请选择：");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				add_student();
				break;
			case 2:
				display_all_student();
				break;
			case 3:
				dele_student();
				break;
			case 0:
				return;
			default:
				printf("\n对不起，您选择错误！\n");
				break;
		}
		printf("\n\n\n\n按Enter键返回……");
		getchar();
		if(getchar()) system("cls");
	}while(1);
}

//管理员录入新学生
void add_student()
{
	int i;
	char judge;
	printf("\n\n提示：请按*账号*姓名*手机号码*登录密码*的顺序输入注册信息的信息！\n");
	printf("----------------------------------------------------\n\n");
	scanf("%ld%s%s%s",&s[stu_Count].num,s[stu_Count].name,
       s[stu_Count].phone,s[stu_Count].password);
	getchar();
	printf("\n\n\n您的录入操作已完成！您是否要保存录入的信息？\n");
	printf("\n\"是\" 请按 Y");
	printf("\n\"否\" 请按 N\n");
	judge=getchar();
	if(judge=='Y' || judge=='y')
	{
		stu_Count++;
	}
	else
		printf("\n\n信息未保存！\n");
}

//注册新学生
void regs_student()
{
	int i;
	char judge;
	printf("\n\n提示：请按*账号*姓名*手机号码*登录密码*的顺序输入注册信息的信息！\n");
	printf("----------------------------------------------------\n\n");
	scanf("%ld%s%s%s",&s[stu_Count].num,s[stu_Count].name,
       s[stu_Count].phone,s[stu_Count].password);
	getchar();
	printf("\n\n\n信息录入已完成！您是否确定？\n");
	printf("\n\"是\" 请按 Y");
	printf("\n\"否\" 请按 N\n");
	judge=getchar();
	if(judge=='Y' || judge=='y')
	{
		stu_Count++;
	}
	else
		{
		printf("\n\n注册失败！\n");
		}
 if(getchar()) system("cls");
}

//管理员浏览学生的基本信息
void display_all_student()
{
	int i;
	printf("\n\n账号\t姓名\t手机号码\t登陆密码\n");
	printf("-----------------------------------------------------\n\n");
	for(i=0;i<stu_Count;i++)
		printf("%ld%s%s%d",&s[i].num,s[i].name,
       s[i].phone,s[i].password);
}

//管理员删除学生
void dele_student()
{
	int j=0,temp;
	long stu_num;
	char judge;
	printf("\n请输入要删除学生的账号：");
	scanf("%ld",&stu_num);
	getchar();
	if((temp=stu_search(stu_num))==NO_FOUND)
		printf("\n对不起，该用户信息不存在！\n");
	else
	{
		printf("\n\n\n您确定要删除学号为%ld的学生？\n",stu_num);
		printf("\n\"是\" 请按 Y");
		printf("\n\"否\" 请按 N\n");
		judge=getchar();
		if(judge=='Y' || judge=='y')
		{
			for(j=temp;j<=stu_Count-1;j++)
			{
				s[j]=s[j+1];
				
			}
			stu_Count--;

			printf("\n删除信息完成！");
		}
		else
			printf("\n\n您暂未删除学号为%ld的学生！\n",stu_num);
	}
}

//维护学生信息的菜单和控制流程
void manage_package()
{
	int choice;	
	do{
		printf("\t\t\t***************************\n");
		printf("\t\t\t**  录入货物信息     请按1  **\n");
		printf("\t\t\t**  浏览货物信息     请按2  **\n");
		printf("\t\t\t**  删除货物信息     请按3  **\n");
		printf("\t\t\t**  修改货物信息     请按4  **\n");
		printf("\t\t\t**  取消             请按0  **\n");
		printf("\t\t\t***************************\n");
		printf("请选择：");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				add_package();
				break;
			case 2:
				display_all_package();
				break;
//			case 3:
//				dele_student();
//				break;
            case 4:
				pac_modify();
				break; 
			case 0:
				return;
			default:
				printf("\n对不起，您选择错误！\n");
				break;
		}
		printf("\n\n\n\n按Enter键返回……");
		getchar();
		if(getchar()) system("cls");
	}while(1);
}

void add_package()
{
	int i;
	char judge;
    printf("\n\n提示：请按*单号*收件人*手机号*送达时间*状态的顺序输入快递的信息！\n");
	printf("----------------------------------------------------\n\n");
	scanf("%ld%s%s%d%d%d%s",&pac[package_Count].num,pac[package_Count].name,
       pac[package_Count].phone,&pac[package_Count].tim.year,&pac[package_Count].tim.month,&pac[package_Count].tim.year,pac[package_Count].state);
	getchar();
	printf("录入取货码");
	scanf("%s",pac[package_Count].code);
	getchar();
	printf("\n\n\n您的录入操作已完成！您是否要保存录入的信息？\n");
	printf("\n\"是\" 请按 Y");
	printf("\n\"否\" 请按 N\n");
	judge=getchar();
	if(judge=='Y' || judge=='y')
	{
		package_Count++;
	}
	else
		{
		printf("\n\n信息未保存！\n");
	}
}


void display_all_package()
{
	int i;
	printf("\n\n*单号*收件人*手机号*送达时间*状态*取货码*\n");
	printf("-----------------------------------------------------\n\n");
	for(i=0;i<package_Count;i++)
		{
		printf("%ld%s%s%d%d%d%s%s",&pac[i].num,pac[i].name,
       pac[i].phone,&pac[i].tim.year,&pac[i].tim.month,&pac[i].tim.day,pac[i].state,pac[i].code);
	   }
}

void pac_modify()
{
	int temp;
	int choice;
	temp=package_search(user_num);
	system("cls");  // 调用DOS命令进行清屏
	do{
		printf("请选择您要修改的信息内容：\n");
		printf("\t\t\t+**********************+\n");        
		printf("\t\t\t| 收件人            请按 1 |\n");
		printf("\t\t\t| 手机号码          请按 2 |\n");
		printf("\t\t\t| 取货码            请按 3 |\n");
		printf("\t\t\t| 取消              请按 0 |\n");
		printf("\t\t\t+**********************+\n");
		printf("请选择：");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			printf("请输入收件人：");
			scanf("%s",pac[temp].name);
			break;
		case 2:
			printf("请输入新手机号码：");
			scanf("%s",pac[temp].phone);
			break;
		case 3:
			printf("请输入新取货码：");
			scanf("%s",pac[temp].code);
			break;
		case 0:
			return;
		default:
			printf("\n无效选项!");
			continue;
		}
		printf("\n\n\n\n按Enter键返回……");
		getchar();
		if(getchar()) system("cls");
	}while(choice!=0);
}




