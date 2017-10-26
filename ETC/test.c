#include <string.h>
#include <stdio.h>

struct employee {
	char name[128];
	float salary;
};
typedef struct employee Employee;


int main()
{
   char str[80] = "Jone Doe:20000";
   const char s[2] = ":";
   char *token;
   Employee em[4];
   
   strcpy(em[0].name,"Jone Doe");
   
//
   printf("%s", em[0].name);
   
//   printf("%c", s[0]);
   
   /* get the first token */
//   token = strtok(str, s);
//   printf( " %s\n", token );
   /* walk through other tokens */
  
     
    
//    token = strtok(NULL, s);
//  	printf( " %s\n", token );
   
   return(0);
}

