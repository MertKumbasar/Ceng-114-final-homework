#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	char name[20];
	char type[20];
	int age;
	int payment;
	char operation[20];
}pat;
void f1(pat a[],int *p);
void f2(pat a[],int size, char type[],pat b[],int *p);
void f3(pat a[],int size, pat b[],int *p);
pat f4(void);
void f5(pat a[],int size,pat pet1);
void f6(pat a[],int size);
int f7(void);
int main(void){
	int size,i,choice,flag=0; //size for func1's array will help us to print the array
	int size2; //size for func2's array will help us to print the array
	int size3; //size for func3's array will help us to print the array
	char type[20];
	pat transfused[30];
	pat info[30];
	pat type_array[30];
	pat new_pet;
	while(1){
		choice=f7();
		if(flag==0 && choice!=1){
			printf("you must use 1 to get the data!!\n"); // making sure the user uses the first option
		}
		else{
			if(choice==1){
				flag=1;
				f1(info,&size);
				printf("the data has been read!!\n");
				printf("---------------------------------------\n");
				for(i=0;i<size;i++){
					printf("%s %s %d %d %s\n",info[i].name,info[i].type,info[i].age,info[i].payment,info[i].operation);
				}
				printf("---------------------------------------\n");
			}
			else if(choice==2){
				printf("which type would you like to cheak:");
				scanf("%s",type);
				f2(info,size,type,type_array,&size2);
				printf("---------------------------------------\n");
				for(i=0;i<size2;i++){
					printf("%s %s %d %d %s\n",type_array[i].name,type_array[i].type,type_array[i].age,type_array[i].payment,type_array[i].operation);
				}
				printf("---------------------------------------\n");
			}
			else if(choice==3){
				printf("patients that will take transfuse opertaion\n");
				f3(info,size,transfused,&size3);
				printf("---------------------------------------\n");
				for(i=0;i<size3;i++){
					printf("%s %s %d %d %s\n",transfused[i].name,transfused[i].type,transfused[i].age,transfused[i].payment,transfused[i].operation);
				}
				printf("---------------------------------------\n");
			}
			else if(choice==4){
				new_pet=f4();
				f5(info,size,new_pet);
				size++;
				printf("---------------------------------------\n");
				for(i=0;i<size;i++){
					printf("%s %s %d %d %s\n",info[i].name,info[i].type,info[i].age,info[i].payment,info[i].operation);
				}
				printf("---------------------------------------\n");
				
			}
			else if(choice==5){
				f6(info,size);
			}
			else if(choice==6){
				exit(1);
			}
			else{
				printf("invalid number try again");
			}
		}
	}
	return 0;
}
void f1(pat a[],int *p){
	*p=0;
	FILE *infile;
	infile=fopen("patients.txt","r");
	if(infile== NULL){
		printf("File could not be opened !!");
		exit(1);
	}
	else{
		while(fscanf(infile," %s %s %d %d %s",a[*p].name,a[*p].type,&a[*p].age,&a[*p].payment,a[*p].operation)!=EOF){
			*p=*p+1;
		}
	}
}
void f2(pat a[],int size, char type[],pat b[],int *p){
	*p=0;
	int i,result;
	for(i=0;i<size;i++){
		result=strcmp(a[i].type,type);
		if(result==0){
			strcpy(b[*p].name,a[i].name);
			strcpy(	b[*p].type,a[i].type);
			b[*p].age=a[i].age;
			b[*p].payment=a[i].payment;
			strcpy(b[*p].operation,a[i].operation);
			*p=*p+1;
		}
	}
}
void f3(pat a[],int size, pat b[],int *p){
	*p=0;
	int i,result;
	for(i=0;i<size;i++){
		result=strcmp(a[i].operation,"transfused");
		if(result==0){
			strcpy(b[*p].name,a[i].name);
			strcpy(	b[*p].type,a[i].type);
			b[*p].age=a[i].age;
			b[*p].payment=a[i].payment;
			strcpy(b[*p].operation,a[i].operation);
			++*p;
		}
	}
}
 pat f4(void){
	pat pet1;
	printf("what is the name of the pet:");
	scanf("%s",pet1.name);
	printf("what is the type of the pet:");
	scanf("%s",pet1.type);
	printf("what is the age of the pet:");
	scanf("%d",&pet1.age);
	printf("what is the coast of the new operation:");
	scanf("%d",&pet1.payment);
	printf("what is the name of the operation:");
	scanf("%s",pet1.operation);
	return pet1;
}
void f5(pat a[],int size,pat pet1){
	strcpy(a[size].name,pet1.name);
	strcpy(	a[size].type,pet1.type);
	a[size].age=pet1.age;
	a[size].payment=pet1.payment;
	strcpy(a[size].operation,pet1.operation);
}
void f6(pat a[],int size){
	
	int max=0,i,idx;
	for(i=0;i<size;i++){
		if(max<a[i].payment){
			max=a[i].payment;
			idx=i;
		}	
	}
	printf("---------------------------------------\n");
	printf("%s %s %d %d %s\n",a[idx].name,a[idx].type,a[idx].age,a[idx].payment,a[idx].operation);
	printf("---------------------------------------\n");
}

int f7(void){
	int choice;
	printf("1. Load patient info from a file\n");
	printf("2. Find patients\n");
	printf("3. View patients 'transfused' \n");
	printf("4. Add new patient info\n");
	printf("5. Find largest payment\n");
	printf("6.Quit\n");
	scanf("%d",&choice);
	return choice;
}
