extern long user_num;
extern int stu_Count;


//����ѧ������
int stu_search(long stu_num)
{	
	int i;
	for(i=0;i<stu_Count;i++)
		if(s[i].num==stu_num) return i;
	return NO_FOUND;	
}
//������֤
int stu_land()
{
	int i=1,j,temp;
	char user_pwd[15];
	do{
		printf("\n��ܰ��ʾ����ʼ�����Ϊ student\n\n");
		printf("\n�����������û���:");
		scanf("%ld", &user_num);
		printf("\n��������������:");
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
			printf("\n�û�������");
		}
		else
		{
			if(s[temp].num==user_num&&(strcmp(s[temp].password,  user_pwd)==0))
				return YES;
			else
				printf("\n�������");
		}
		printf("����������!\n");
		i++;
		printf("---------------------------------------------------\n");
	}while(i<=3);    
	return NO;
}
//�û��������˵�
int stu_menu()
{
	int choice=-1;
	printf("\n��ܰ��ʾ������������˳���˳�ϵͳ^_^\n");
 	printf("-------------------------------------------------------\n");
	printf("\n");
	printf("\t\t\t*-----*-----*-----*-----*----*---*\n");
	printf("\t\t\t|+    ѧ �� �� Ϣ �� �� ϵ ͳ     |\n");  
	printf("\t\t\t|+!^^^^^^^^^^^^^^^^^^^^^^^^!+|\n");               
	printf("\t\t\t|+   ��1��**** ��ѯ������Ϣ     +|\n");
	printf("\t\t\t|+   ��2��**** �޸ĸ�����Ϣ     +|\n");
	printf("\t\t\t|+   ��3��**** ��ѯ������Ϣ     +|\n");
	printf("\t\t\t|+   ��0��**** �˳�ϵͳ         +|\n");
	printf("\t\t\t|+*��*��*��*��*��*��*��*��* *��*��*��*��*+|\n");
	printf("\n");
	printf("-------------------------------------------------------\n");
	printf("����������ѡ��");
	scanf("%d",&choice);
	return choice;
}


//�����û���Ϣ�ĺ���
void Load_student_information(char * file_name)
{
	FILE *fp;
	struct student *p;
	if((fp=fopen(file_name,"r"))==NULL)
	{
		printf("δ�ҵ��û��ļ���\n");
		return;
	}
	while(!feof(fp))
	{
		p=(struct student *)malloc(sizeof(struct student));
		if(fscanf(fp,"%ld%s%s%s\r",&p->num,p->name,
		   p->phone,p->password)==0)
		{
			printf("�û��ļ�����ʧ��!\n");
			return;
		}
		s[stu_Count]=*p;
		stu_Count++;
	}
	printf("stu_Count=%d",stu_Count);
	free(p);
	fclose(fp);
	printf("\nѧ���ļ�������!\n\n");
}


//�����û���Ϣ�ĺ���
void save_student_information(char *file_name)
{
	FILE *fp;
	struct student *p;
	int i;
	if((fp=fopen(file_name,"w"))==NULL)
		printf("δ�ҵ�ѧ���ļ�,���ܱ���!\n");
	for(i=0;i<stu_Count;i++)
	{
		p=(struct student *)malloc(sizeof(struct student));
		*p=s[i];
		if(fprintf(fp,"%ld%s%s%s\r",&p->num,p->name,p->phone,p->password)==0)
		{
			printf("ѧ���ļ�����ʧ��!\n");
			return;
		}
	}
	free(p);
	fclose(fp); 
	printf("ѧ���ļ��ѱ���!\n");
}



//ѧ�����ܿ��ƺ���
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
			printf("����\t�ֻ�����\t��¼����\n");
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
//			printf("\n\n*����*�ռ���*�ֻ���*�ʹ�ʱ��*״̬*ȡ����*\n");
//			printf("---------------------------------------------\n\n");
//			
//				  printf("%ld%s%s%d%d%d%s%s",&pac[temp].num,pac[temp].name,
//       pac[temp].phone,&pac[temp].tim.year,&pac[temp].tim.month,&pac[temp].tim.day,pac[temp].state,pac[temp].code);
//			break;
			
		case 0:
			exit_system();
			break;
		default:
			printf("\n�Բ�����ѡ�����\n");
			break;
		}
		printf("\n\n\n\n��Enter�����ء���");
		getchar();
		if(getchar())
			system("cls");
	}while(1);
}

//�û��޸ĸ��˻�����Ϣ
void stu_modify()
{
	int temp;
	int choice;
	temp=stu_search(user_num);
	system("cls");  // ����DOS�����������
	do{
		printf("��ѡ����Ҫ�޸ĵ���Ϣ���ݣ�\n");
		printf("\t\t\t+**********************+\n");        
		printf("\t\t\t| ����              �밴 1 |\n");
		printf("\t\t\t| �ֻ�����          �밴 2 |\n");
		printf("\t\t\t| ��¼����          �밴 3 |\n");
		printf("\t\t\t| ȡ��              �밴 0 |\n");
		printf("\t\t\t+**********************+\n");
		printf("��ѡ��");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			printf("��������������");
			scanf("%s",s[temp].name);
			break;
		case 2:
			printf("�������ֻ����룺");
			scanf("%s",s[temp].phone);
			break;
		case 3:
			printf("�����������룺");
			scanf("%s",s[temp].password);
			break;
		case 0:
			return;
		default:
			printf("\n��Чѡ��!");
			continue;
		}
		printf("\n\n\n\n��Enter�����ء���");
		getchar();
		if(getchar()) system("cls");
	}while(choice!=0);
}


