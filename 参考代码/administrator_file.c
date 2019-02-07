extern int package_Count;
extern long user_num;
//���������Ϣ�ĺ���
//����ѧ������
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
		printf("δ�ҵ������ļ���\n");
		return;
	}
	while(!feof(fp))
	{
		p=(struct package *)malloc(sizeof(struct package));
		if(fscanf(fp,"%ld%s%s%d%d%d%s%s\r",&p->num,p->name,p->phone,&p->tim.year,&p->tim.month,&p->tim.day,p->state,p->code)==0)
		{
			printf("�����ļ�����ʧ��!\n");
			return;
		}
		pac[package_Count]=*p;
		package_Count++;
	}
	printf("package_Count=%d",package_Count);
	free(p);
	fclose(fp);
	printf("\n�����ļ�������!\n\n");
}

//��������Ϣ�ĺ���
void save_package_information(char *file_name)
{
	FILE *fp;
	struct package *p;
	int i;
	if((fp=fopen(file_name,"w"))==NULL)
		printf("δ�ҵ������ļ�,���ܱ���!\n");
	for(i=0;i<package_Count;i++)
	{
		p=(struct package *)malloc(sizeof(struct package));
		*p=pac[i];
	if(fprintf(fp,"%ld%s%s%d%d%d%s%s\r",&p->num,p->name,p->phone,&p->tim.year,&p->tim.month,&p->tim.day,p->state,p->code)==0)
		{
			printf("�����ļ�����ʧ��!\n");
			return;
		}
	}
	free(p);
	fclose(fp); 
	printf("�����ļ��ѱ���!\n");
}

//����Ա��¼������֤
int admin_land()
{
	int i=1,j;
	char user_name[15];
	char admin_pwd[15];
	do{
		printf("\n���������Ա�û���:");
		scanf("%s",user_name);
		printf("\n���������Ա����:");
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
			printf("\n�������");
		printf("����������!\n");
		i++;
		printf("---------------------------------------------------\n");
	}while(i<=3);    
	return NO;
}

//����Ա�������˵�
int admin_menu()
{
	int choice;
	choice = -1;
	printf("\n��ܰ��ʾ������������˳���˳�ϵͳ^_^\n");
	printf("-------------------------------------------------------\n");
	printf("\n");
	printf("\t\t\t*-----*-----*-----*-----*----*-----*\n");
	printf("\t\t\t|+         �� �� Ա �� �� ϵ ͳ          |\n");  
	printf("\t\t\t|+!^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^!+|\n");               
	printf("\t\t\t|+        ��1��**** ά���û���Ϣ       +|\n");
	printf("\t\t\t|+        ��2��**** ά��������Ϣ       +|\n");
//	printf("\t\t\t|+        ��3��**** ά���γ���Ϣ       +|\n");
	printf("\t\t\t|+        ��0��**** �˳�ϵͳ           +|\n");
	printf("\t\t\t|+*��*��*��*��*��*��*��*��* *��*��*��*��*��*��*��*+|\n");
	printf("\n");
	printf("-------------------------------------------------------\n");
	printf("����������ѡ��");
	scanf("%d", &choice);
	return choice;
}
//����Ա���ܿ��ƺ���
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
			printf("\n�Բ�����ѡ�����\n");
			break;
		}
		system("cls");
	}while(1);
}

//ά��ѧ����Ϣ�Ĳ˵��Ϳ�������
void manage_student()
{
	int choice;	
	do{
		printf("\t\t\t***************************\n");
		printf("\t\t\t**  ¼���û���Ϣ     �밴1  **\n");
		printf("\t\t\t**  ����û���Ϣ     �밴2  **\n");
		printf("\t\t\t**  ɾ���û���Ϣ     �밴3  **\n");
		printf("\t\t\t**  ȡ��             �밴0  **\n");
		printf("\t\t\t***************************\n");
		printf("��ѡ��");
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
				printf("\n�Բ�����ѡ�����\n");
				break;
		}
		printf("\n\n\n\n��Enter�����ء���");
		getchar();
		if(getchar()) system("cls");
	}while(1);
}

//����Ա¼����ѧ��
void add_student()
{
	int i;
	char judge;
	printf("\n\n��ʾ���밴*�˺�*����*�ֻ�����*��¼����*��˳������ע����Ϣ����Ϣ��\n");
	printf("----------------------------------------------------\n\n");
	scanf("%ld%s%s%s",&s[stu_Count].num,s[stu_Count].name,
       s[stu_Count].phone,s[stu_Count].password);
	getchar();
	printf("\n\n\n����¼���������ɣ����Ƿ�Ҫ����¼�����Ϣ��\n");
	printf("\n\"��\" �밴 Y");
	printf("\n\"��\" �밴 N\n");
	judge=getchar();
	if(judge=='Y' || judge=='y')
	{
		stu_Count++;
	}
	else
		printf("\n\n��Ϣδ���棡\n");
}

//ע����ѧ��
void regs_student()
{
	int i;
	char judge;
	printf("\n\n��ʾ���밴*�˺�*����*�ֻ�����*��¼����*��˳������ע����Ϣ����Ϣ��\n");
	printf("----------------------------------------------------\n\n");
	scanf("%ld%s%s%s",&s[stu_Count].num,s[stu_Count].name,
       s[stu_Count].phone,s[stu_Count].password);
	getchar();
	printf("\n\n\n��Ϣ¼������ɣ����Ƿ�ȷ����\n");
	printf("\n\"��\" �밴 Y");
	printf("\n\"��\" �밴 N\n");
	judge=getchar();
	if(judge=='Y' || judge=='y')
	{
		stu_Count++;
	}
	else
		{
		printf("\n\nע��ʧ�ܣ�\n");
		}
 if(getchar()) system("cls");
}

//����Ա���ѧ���Ļ�����Ϣ
void display_all_student()
{
	int i;
	printf("\n\n�˺�\t����\t�ֻ�����\t��½����\n");
	printf("-----------------------------------------------------\n\n");
	for(i=0;i<stu_Count;i++)
		printf("%ld%s%s%d",&s[i].num,s[i].name,
       s[i].phone,s[i].password);
}

//����Աɾ��ѧ��
void dele_student()
{
	int j=0,temp;
	long stu_num;
	char judge;
	printf("\n������Ҫɾ��ѧ�����˺ţ�");
	scanf("%ld",&stu_num);
	getchar();
	if((temp=stu_search(stu_num))==NO_FOUND)
		printf("\n�Բ��𣬸��û���Ϣ�����ڣ�\n");
	else
	{
		printf("\n\n\n��ȷ��Ҫɾ��ѧ��Ϊ%ld��ѧ����\n",stu_num);
		printf("\n\"��\" �밴 Y");
		printf("\n\"��\" �밴 N\n");
		judge=getchar();
		if(judge=='Y' || judge=='y')
		{
			for(j=temp;j<=stu_Count-1;j++)
			{
				s[j]=s[j+1];
				
			}
			stu_Count--;

			printf("\nɾ����Ϣ��ɣ�");
		}
		else
			printf("\n\n����δɾ��ѧ��Ϊ%ld��ѧ����\n",stu_num);
	}
}

//ά��ѧ����Ϣ�Ĳ˵��Ϳ�������
void manage_package()
{
	int choice;	
	do{
		printf("\t\t\t***************************\n");
		printf("\t\t\t**  ¼�������Ϣ     �밴1  **\n");
		printf("\t\t\t**  ���������Ϣ     �밴2  **\n");
		printf("\t\t\t**  ɾ��������Ϣ     �밴3  **\n");
		printf("\t\t\t**  �޸Ļ�����Ϣ     �밴4  **\n");
		printf("\t\t\t**  ȡ��             �밴0  **\n");
		printf("\t\t\t***************************\n");
		printf("��ѡ��");
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
				printf("\n�Բ�����ѡ�����\n");
				break;
		}
		printf("\n\n\n\n��Enter�����ء���");
		getchar();
		if(getchar()) system("cls");
	}while(1);
}

void add_package()
{
	int i;
	char judge;
    printf("\n\n��ʾ���밴*����*�ռ���*�ֻ���*�ʹ�ʱ��*״̬��˳�������ݵ���Ϣ��\n");
	printf("----------------------------------------------------\n\n");
	scanf("%ld%s%s%d%d%d%s",&pac[package_Count].num,pac[package_Count].name,
       pac[package_Count].phone,&pac[package_Count].tim.year,&pac[package_Count].tim.month,&pac[package_Count].tim.year,pac[package_Count].state);
	getchar();
	printf("¼��ȡ����");
	scanf("%s",pac[package_Count].code);
	getchar();
	printf("\n\n\n����¼���������ɣ����Ƿ�Ҫ����¼�����Ϣ��\n");
	printf("\n\"��\" �밴 Y");
	printf("\n\"��\" �밴 N\n");
	judge=getchar();
	if(judge=='Y' || judge=='y')
	{
		package_Count++;
	}
	else
		{
		printf("\n\n��Ϣδ���棡\n");
	}
}


void display_all_package()
{
	int i;
	printf("\n\n*����*�ռ���*�ֻ���*�ʹ�ʱ��*״̬*ȡ����*\n");
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
	system("cls");  // ����DOS�����������
	do{
		printf("��ѡ����Ҫ�޸ĵ���Ϣ���ݣ�\n");
		printf("\t\t\t+**********************+\n");        
		printf("\t\t\t| �ռ���            �밴 1 |\n");
		printf("\t\t\t| �ֻ�����          �밴 2 |\n");
		printf("\t\t\t| ȡ����            �밴 3 |\n");
		printf("\t\t\t| ȡ��              �밴 0 |\n");
		printf("\t\t\t+**********************+\n");
		printf("��ѡ��");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			printf("�������ռ��ˣ�");
			scanf("%s",pac[temp].name);
			break;
		case 2:
			printf("���������ֻ����룺");
			scanf("%s",pac[temp].phone);
			break;
		case 3:
			printf("��������ȡ���룺");
			scanf("%s",pac[temp].code);
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




