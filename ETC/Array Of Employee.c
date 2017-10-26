#include <string.h>
#include<stdlib.h>
#include<stdio.h>

struct employee {
	char name[128];
	float salary;
};
typedef struct employee Employee;


int checkEmployee();
void inputEmployee(Employee *ems);
void outputEmployee(Employee *ems,int num_em);
void storeEmployee(Employee *em,char* employee,float salary);
float total_salary(Employee *ems,int num_em);
int parseInt(char line[]);

int main(){
	int num_em = 0;	
	float sum;
	
	num_em = checkEmployee();
	Employee *ems = (Employee*)malloc(sizeof(Employee)*num_em);
	inputEmployee(ems);
	outputEmployee(ems,num_em);
	sum = total_salary(ems,num_em);
	printf("= %.1f",sum);
	return 0;
}
int checkEmployee(){
	int count  = 0;
	char line[128];
	FILE *fp = fopen("employee.bin", "rb");
	
	while(!feof(fp)){
		fscanf(fp, " %[^\n]s", &line);
		count++;
	}
	
	fclose(fp);
	
	return count;	
}

void inputEmployee(Employee *ems){
	FILE *fp = fopen("employee.bin", "rb");
	char line[128];
	const char s[2] = ":";
	char *employee;
	char *salary;
	int int_salary;
	float float_salary;
	float sum = 0;
//	Employee em[num_em];
	int i = 0;
	while(!feof(fp)){
		fscanf(fp, " %[^\n]s", &line);
		// split Employee
		employee = strtok(line, s);
		// salary to Float
		salary = strtok(NULL, s);
		int_salary = parseInt(salary);
		float_salary = (float)int_salary;

		storeEmployee(&ems[i],employee,float_salary);
		i++;
		
	}
	
	
	
	fclose(fp);
}

int parseInt(char line[]){
	int number;
	
	number = atoi(line);
	
	return number;
}

void storeEmployee(Employee *em,char* employee,float salary){
	strcpy(em->name, employee);
	em->salary = salary;
}

void outputEmployee(Employee *ems,int num_em){
	int i;
	for(i=0;i<num_em;i++){
		printf(" %s : %.1f \n", ems[i].name, ems[i].salary);	
	}	
}
float total_salary(Employee *ems,int num_em){
	int i;
	float sum_salary=0;
	for(i=0;i<num_em;i++){
		sum_salary += ems[i].salary;
	}
	return sum_salary;
}


