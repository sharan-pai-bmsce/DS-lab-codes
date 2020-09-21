#include<stdio.h>

int main(){
	typedef struct{
		int studentId;
		int age;
		int marks;
	}Student;
	
	int num;
	scanf("%d",&num);
	Student s[num];
	int i;
	for(i=0;i<num;i++){
		printf("Enter the Student Id\n");
		scanf("%d",&s[i].studentId);
		printf("Enter the age\n");
		scanf("%d",&s[i].age);
		printf("Enter the marks\n");
		scanf("%d",&s[i].marks);
	}
	for(i=0;i<num;i++){
		if(s[i].age>20 && s[i].marks>=0 && s[i].marks<=100){
			if(s[i].marks>=65){
				printf("Student Id: %d\tAdmission Allowed and data is valid\n",s[i].studentId);
			}else{
				printf("Student Id: %d\tAdmission not Allowed and data is valid\n",s[i].studentId);
			}
		}else{
			printf("Student Id: %d\tData Invalid\n",s[i].studentId);
		}
	}
	return 0;
}
