#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct employee {
	char name[128];
	float salary;
};
typedef struct employee Employee;

void readFile(Employee *ems,int *num_e);
void showData(Employee *ems,int *num_e);

int main(){
  int num_e;
  Employee *ems; 
  ems = (Employee*)malloc(sizeof(Employee)*3);
  
  readFile(ems,&num_e);
  showData(ems,&num_e);

  return 0;
}
void readFile(Employee *ems,int *num_e){

	FILE *fp = fopen("employee.bin", "rb");
	//Read Number of Employee
	fread(num_e, sizeof(int), 1, fp);
	//Read Employee and Salary
	fread(ems, sizeof(Employee), num_e , fp);

	fclose(fp);	 
}
void showData(Employee *ems,int *num_e){
	int i=0;
	float sum = 0;

	while(i< *num_e){
		printf(" %s:%.1f\n",ems[i].name,ems[i].salary);
		i++;
	}
	
	i=0;
	while(i< *num_e){
		sum += ems[i].salary;
		i++;
	}
	printf("=%.1f",sum);	
}
