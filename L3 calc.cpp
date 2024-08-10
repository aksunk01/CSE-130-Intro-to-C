/*
@author Abhiram Sunkara
@email aksunk01@louisville.edu
@date 8/31/2023
@project CSE130-Lab2
@description A calculator that is able to do different types of calculations ranging from addition to testing if numberes are prime
*/

#include <stdio.h>
int main(int argc, char* argv[]){
	//List of variables for the operations
	int loop = 2;
	int response;
	float n1;
	float n2;
	int n3=0;
	int n4=0;
	int n5=0;
	float answer;
	int answer2;
	
	
	
	while(loop==2){
		//Calculator Menu
		printf("\nCalculator Menu:\n");
		printf("(1) Addition\n");
		printf("(2) Subtration\n");
		printf("(3) Multiplication\n");
		printf("(4) Division\n");
		printf("(5) Modulus (INTEGERS ONLY)\n");
		printf("(6) Test if prime (INTEGERS ONLY)\n");
		printf("(7) Exit")
		printf("Please choose an operation: ");
		scanf("%d", &response);
		
		//Addition Operator
		if(response == 1){
			printf("Enter the first number: ");
			scanf("%f", &n1);
			printf("\nEnter the second number: ");
			scanf("%f", &n2);
			answer = n1 + n2;
			printf("%f + %f = %f\n", n1, n2, answer);
			
		}
		//Subtraction Operator
		else if(response == 2){
			printf("Enter the first number: ");
			scanf("%f", &n1);
			printf("\nEnter the second number: ");
			scanf("%f", &n2);
			answer = n1 - n2;
			printf("%f - %f = %f\n", n1, n2, answer);
			
		}
		//Multiplication
		else if(response == 3){
			printf("Enter the first number: ");
			scanf("%f", &n1);
			printf("\nEnter the second number: ");
			scanf("%f", &n2);
			answer = n1 * n2;
			printf("%f * %f = %f", n1, n2, answer);
		}
		else if(response == 4){
			printf("Enter the first number: ");
			scanf("%f", &n1);
			printf("\nEnter the second number: ");
			scanf("%f", &n2);
			answer = n1 / n2;
			printf("%f / %f = %f", n1, n2, answer);
		}
		else if(response == 5){
			printf("Enter only integers, if failed to do so then it will truncate the decimal");
			printf("\nEnter the first number: ");
			scanf("%f", &n1);
			printf("\nEnter the second number: ");
			scanf("%f", &n2);
			answer2 = (int) n1 % (int) n2;
			printf("%f %% %f = %d", n1, n2, answer2);
		}
		else if(response == 6){
			printf("Enter only integers, if failed to do so please try again:  ");
			printf("\nEnter the number to be tested: ");
			scanf("%d", &n3);
			if(n3 != 1 )
			for(int i = 2; i <= n3/2; i++){
				if(n3 % i == 0){
					n4 = n3/i;
					n5 = i;
					i = n3*2;
					
				}
			}
			if(n4 > 0 && n3 != 1 && n3!= 2){
				printf("Not prime %d x %d = %d", n5,n4,n3);
			}else{
				printf("Number is prime");
			}
			n3 = 0;
			n4 = 0;
			n5 = 0;
		}
		else if(response == 7){
			loop = 3;
		}else{
			printf("Invalid option please pick again");
		}
	}
	printf("Goodbye");
	
	return 0;
	
}