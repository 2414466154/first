long user_num;
struct time
{
	int year,month,day;
}tim;

 
struct package
{
    long num; 
    char name[20];
    char code[20];
    char phone[20];
    struct time tim;
    char state[20];
 }pac[200];


struct student
{
long num;
char name[20]; 
char phone[20];
char password[50];
}s[STUDENT_MAX];

struct teacher
{
	long num;
	char name[50]; 
	char sex[5];
	int age;
	char company_name[80];
	char password[50]; 	
}t[TEACHER_MAX];
struct selection
{
	long course_num;
	long stu_num;
	double grade;
}select[SELECT_MAX];
