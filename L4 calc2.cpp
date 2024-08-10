/*
@author Abhiram Sunkara
@email aksunk01@louisville.edu
@date 9/22/2023
@project CSE130-Lab3
@description A calculator that is able to do different types of calculations ranging from addition to testing if numbers are prime and giving the fibonacci sequqence
*/

#include <stdio.h>
#include <math.h>

float addition(float n1, float n2){
	return n1 + n2;
}

float sub(float n1, float n2){
	return n1 - n2;
}

float mult(float n1, float n2){
	return n1 * n2;
}

float div(float n1, float n2){
	return n1/n2;
}

int mod(int n1, int n2){
	return n1 % n2;
}

bool prime(int n1){
	if(n1 == 1 || n1==2){
		return(true);
	}else{
		for(int i = 2; i = n1/2; i++){
			if(n1%i == 0){
				return(false);
			}else{
				return(true);
			}
		}
	}
}

int facts(int n1){
	int f = 1;
	for(int i = 1; i < n1+1; i++){
		f = f*i;
	}
	return f;
}

float p (float base, float powr){
	return(pow(base, powr));
}


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
		printf("(7) Factorial (INTEGERS ONLY)\n");
		printf("(8) Power\n");
		printf("(9) Fibonacci\n");
		printf("(0) exit");
		printf("Please choose an operation: ");
		scanf("%d", &response);
		
		//Addition Operator
		if(response == 1){
			printf("Enter the first number: ");
			scanf("%f", &n1);
			printf("\nEnter the second number: ");
			scanf("%f", &n2);
			answer = addition(n1,n2);
			printf("%f + %f = %f\n", n1, n2, answer);
			
		}
		//Subtraction Operator
		else if(response == 2){
			printf("Enter the first number: ");
			scanf("%f", &n1);
			printf("\nEnter the second number: ");
			scanf("%f", &n2);
			answer = sub(n1, n2);
			printf("%f - %f = %f\n", n1, n2, answer);
			
		}
		//Multiplication
		else if(response == 3){
			printf("Enter the first number: ");
			scanf("%f", &n1);
			printf("\nEnter the second number: ");
			scanf("%f", &n2);
			answer = mult(n1,n2);
			printf("%f * %f = %f", n1, n2, answer);
		}
		//Division
		else if(response == 4){
			printf("Enter the first number: ");
			scanf("%f", &n1);
			printf("\nEnter the second number: ");
			scanf("%f", &n2);
			answer = div(n1,n2);
			printf("%f / %f = %f", n1, n2, answer);
		}
		//Modulus
		else if(response == 5){
			printf("Enter only integers, if failed to do so then it will truncate the decimal");
			printf("\nEnter the first number: ");
			scanf("%f", &n1);
			n1 = (int(n1));
			printf("\nEnter the second number: ");
			scanf("%f", &n2);
			n2 = (int(n2));
			answer2 = mod(n1,n2);
			printf("%f %% %f = %d", n1, n2, answer2);
		}
		//Prime
		else if(response == 6){
			printf("Enter only integers, if failed to do so please try again");
			printf("\nEnter the number to be tested: ");
			scanf("%d", &n3);
			bool prim = prime(n3);
			if(prim == true){
				printf("%d is prime", n3);				
			}else{
				printf("%d is not prime", n3);
			}
			n3 = 0;

		}
		//Factorial
		else if(response == 7){
			printf("Enter only integers, if failed to do so please try again: ");
			printf("\nEnter the number to be tested: ");
			scanf("%d",&n4);
			int fact = 1;
			for(int i = 1; i < n4+1; i++){
				fact = fact*i;
			}
			printf("%d", fact);
		}
		//Powers
		else if(response == 8){
			printf("Enter the base: ");
			scanf("%f", &n1);
			printf("\nEnter the power: ");
			scanf("%f", &n2);
			float pow = p(n1,n2);
			printf("%f ^ %f = %f", n1,n2,pow);
		}
		//Fib
		else if(response == 9){
			printf("Enter the how many fibonacci number you would like printed (only integers): ");
			scanf("%d",&n3);
			int fib[n3];
			fib[0] = 0;
			fib[1] = 1;
			for(int i = 2; i < n3; i++){
				fib[i] = fib[i-1] + fib[i-2];
			}
			for(int j = 0; j < n3; j++){
				printf("%d ", fib[j]);
			}
			printf("\n");
		}
		else if(response == 0){
			loop = 1;
		}
	}
	printf("\nGoodbye");
	
	return 0;
	
}