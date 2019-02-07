extern long user_num;
extern int stu_Count;


//搜索学生函数
int stu_search(long stu_num)
{	
	int i;
	for(i=0;i<stu_Count;i++)
		if(s[i].num==stu_num) return i;
	return NO_FOUND;	
}
//密码验证
int stu_land()
{
	int i=1,j,temp;
	char user_pwd[15];
	do{
		printf("\n温馨提示：初始密码均为 student\n\n");
		printf("\n请输入您的用户名:");
		scanf("%ld", &user_num);
		printf("\n请输入您的密码:");
		for(j=0;;j++)
  {
      user_pwd[j]=getch();
       if(user_pwd[j]=='\x0d')
  {
        user_pwd[j]='\0';
         break;
   }
      if(user_pwd[j]==8&&j>0)
      {
           printf("\b \b");
              j=j-2;
           continue;
      }
          printf("*");
} 
		if((temp=stu_search(user_num))==NO_FOUND)
		{
			printf("\n用户名错误！");
		}
		else
		{
			if(s[temp].num==user_num&&(strcmp(s[temp].password,  user_pwd)==0))
				return YES;
			else
				printf("\n密码错误！");
		}
		printf("请重新输入!\n");
		i++;
		printf("---------------------------------------------------\n");
	}while(i<=3);    
	return NO;
}
//用户功能主菜单
int stu_menu()
{
	int choice=-1;
	printf("\n温馨提示：请您按正常顺序退出系统^_^\n");
 	printf("-------------------------------------------------------\n");
	printf("\n");
	printf("\t\t\t*-----*-----*-----*-----*----*---*\n");
	printf("\t\t\t|+    学 生 信 息 管 理 系 统     |\n");  
	printf("\t\t\t|+!^^^^^^^^^^^^^^^^^^^^^^^^!+|\n");               
	printf("\t\t\t|+   【1】**** 查询个人信息     +|\n");
	printf("\t\t\t|+   【2】**** 修改个人信息     +|\n");
	printf("\t\t\t|+   【3】**** 查询货物信息     +|\n");
	printf("\t\t\t|+   【0】**** 退出系统         +|\n");
	printf("\t\t\t|+*·*·*·*·*·*·*·*·* *·*·*·*·*+|\n");
	printf("\n");
	printf("-------------------------------------------------------\n");
	printf("请输入您的选择：");
	scanf("%d",&choice);
	return choice;
}


//载入用户信息的函数
void Load_student_information(char * file_name)
{
	FILE *fp;
	struct student *p;
	if((fp=fopen(file_name,"r"))==NULL)
	{
		printf("未找到用户文件！\n");
		return;
	}
	while(!feof(fp))
	{
		p=(struct student *)malloc(sizeof(struct student));
		if(fscanf(fp,"%ld%s%s%s\r",&p->num,p->name,
		   p->phone,p->password)==0)
		{
			printf("用户文件载入失败!\n");
			return;
		}
		s[stu_Count]=*p;
		stu_Count++;
	}
	printf("stu_Count=%d",stu_Count);
	free(p);
	fclose(fp);
	printf("\n学生文件已载入!\n\n");
}


//保存用户信息的函数
void save_student_information(char *file_name)
{
	FILE *fp;
	struct student *p;
	int i;
	if((fp=fopen(file_name,"w"))==NULL)
		printf("未找到学生文件,不能保存!\n");
	for(i=0;i<stu_Count;i++)
	{
		p=(struct student *)malloc(sizeof(struct student));
		*p=s[i];
		if(fprintf(fp,"%ld%s%s%s\r",&p->num,p->name,p->phone,p->password)==0)
		{
			printf("学生文件保存失败!\n");
			return;
		}
	}
	free(p);
	fclose(fp); 
	printf("学生文件已保存!\n");
}



//学生功能控制函数
void student()
{
	int choice,temp;
	system("cls");
	do{
		choice=stu_menu();
		system("cls");
		switch(choice)
{
		case 1:
			temp=stu_search(user_num);
			printf("姓名\t手机号码\t登录密码\n");
			printf("---------------------------------------------\n\n");
			printf("%s\t%s\t %s \n",
				  s[temp].name,s[temp].phone,s[temp].password);
			break;
		case 2:
			stu_modify();
			system("cls");
			continue;
		case 3:
//			 temp=package_search(user_num);
////		temp=stu_search(user_num);
//			printf("\n\n*单号*收件人*手机号*送达时间*状态*取货码*\n");
//			printf("---------------------------------------------\n\n");
//			
//				  printf("%ld%s%s%d%d%d%s%s",&pac[temp].num,pac[temp].name,
//       pac[temp].phone,&pac[temp].tim.year,&pac[temp].tim.month,&pac[temp].tim.day,pac[temp].state,pac[temp].code);
//			break;
			
		case 0:
			exit_system();
			break;
		default:
			printf("\n对不起，您选择错误！\n");
			break;
		}
		printf("\n\n\n\n按Enter键返回……");
		getchar();
		if(getchar())
			system("cls");
	}while(1);
}

//用户修改个人基本信息
void stu_modify()
{
	int temp;
	int choice;
	temp=stu_search(user_num);
	system("cls");  // 调用DOS命令进行清屏
	do{
		printf("请选择您要修改的信息内容：\n");
		printf("\t\t\t+**********************+\n");        
		printf("\t\t\t| 姓名              请按 1 |\n");
		printf("\t\t\t| 手机号码          请按 2 |\n");
		printf("\t\t\t| 登录密码          请按 3 |\n");
		printf("\t\t\t| 取消              请按 0 |\n");
		printf("\t\t\t+**********************+\n");
		printf("请选择：");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			printf("请输入新姓名：");
			scanf("%s",s[temp].name);
			break;
		case 2:
			printf("请输入手机号码：");
			scanf("%s",s[temp].phone);
			break;
		case 3:
			printf("请输入新密码：");
			scanf("%s",s[temp].password);
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


