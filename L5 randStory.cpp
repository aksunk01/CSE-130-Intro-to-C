/*
@author Abhiram Sunkara
@email aksunk01@louisville.edu
@date 8/31/2023
@project CSE130-Lab2
@description A calculator that is able to do different types of calculations ranging from addition to testing if numberes are prime
*/

#include <stdio.h>
#include <string.h>
#include <time.h>
#define MAX_LEN 32
int main(int argc, char* argv[]){
	char name[MAX_LEN];
	printf("What is your name: ");
	gets(name);
	
	char age[MAX_LEN];
	printf("\nWhat is your age: ");
	gets(age);
	
	char color[MAX_LEN];
	printf("\nWhat is your favorite color: ");
	gets(color);
	
	char food[MAX_LEN];
	printf("\nWhat is your favorite food: ");
	gets(food);
	
	char hobby[MAX_LEN];
	printf("\nWhat is your favorite hobby: ");
	gets(hobby);
	
	int op;
	printf("\nPick a number between 1 and 3: ");
	scanf("%d", &op);
	
	if(op == 1){
		printf("\n%s is in the park. ", name);
		printf("%s turned %s today, they came to the park to celebrate their birthday. ", name, age);
		printf("To celebrate their big day they went to a restuarant and bought %s to go as well as a %s cake. ", food, color);
		printf("They spent the rest of the day %s and had a fun birthday to themselves. ", hobby);
		printf("The end");
	}else if(op ==2 ){
		printf("%s is at home.", name);
		printf("%s is %s and invited a bunch of friends over for dinner. ", name, age);
		printf("For dinner %s brought a lot of food but they were most excited for %s. ",name, food);
		printf("They spent the whole day decorating their house %s. ", color);
		printf("When all of %s's friends came over they had dinner and they were all %s together. ", name, hobby);
		printf("The end.");
	}else{
		printf("%s is at his friends house. ", name);
		printf("%s friend turned %s today, and they came to celebrate their birthday. ", name, age);
		printf("To celebrate their big day %s cooked %s and baked a %s cake. ", food, color);
		printf("They spent the rest of the day %s and had a fun birthday to themselves. ", hobby);
		printf("The end");
	}
	

	
	

	
	
	
	return 0;
}