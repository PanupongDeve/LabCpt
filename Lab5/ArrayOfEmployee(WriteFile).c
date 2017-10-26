#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct employee {
	char name[128];
	float salary;
};
typedef struct employee Employee;

void weiteFile(int num_e);
int main(){
  int num_e = 3;
  weiteFile(num_e);
  printf("Write Success");
  

  return 0;
}
void weiteFile(int num_e){
	Employee *ems = (Employee*)malloc(sizeof(Employee)*num_e);
	int i = 0;
	
	FILE *fp = fopen("employee.bin", "wb");
	
	//Write Number of Employee
	fwrite(&num_e, sizeof(int), 1, fp);
	
	// Print Check Data Before Write
	strcpy(ems[0].name,"Jone Doe");
	strcpy(ems[1].name,"Mark Ken");
	strcpy(ems[2].name,"Sucy Merc");
	ems[0].salary = 3000.0;
	ems[1].salary = 2300.0;
	ems[2].salary = 2000.0;
	
	while(i<num_e){
		printf(" %s:%.1f\n",ems[i].name,ems[i].salary);
		i++;
	}
	
	//Write Employee and Salary
	fwrite(ems, sizeof(Employee), 3, fp);
	fclose(fp);
}

