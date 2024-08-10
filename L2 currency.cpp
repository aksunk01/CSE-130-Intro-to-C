/*
@author Abhiram Sunkara
@email aksunk01@louisville.edu
@date 8/31/2023
@project CSE130-Lab2
@description NEED TO COMPLETE
*/


#include <stdio.h>
int main(int argc, char* argv[]){
	//Got 8/29/23
	//Currency Exchange Rates on 8/29/23
	float uSDxUSD= 1;
	float uSDxEUR= 0.92;
	float uSDxGBP= 0.79;
	float uSDxCAD= 1.36;
	float uSDxAUD= 1.55;
	
	float gBPxUSD= 1.26;
	float gBPxGBP= 1;
	float gBPxCAD= 1.71;
	float gBPxEUR= 1.16;
	float gBPxAUD= 1.95;
	
	float cADxUSD= 0.74;
	float cADxGBP= 0.58;
	float cADxEUR= 0.68;
	float cADxAUD= 1.14;
	float cADxCAD= 1;
	
	float aUDxUSD= 0.65;
	float aUDxGBP=0.51;
	float aUDxCAD= 0.88;
	float aUDxEUR= 0.60;
	float aUDxAUD= 1;
	
	float eURxUSD= 1.08;
	float eURxGBP= 0.86;
	float eURxCAD= 1.47;
	float eURxEUR= 1;
	float eURxAUD= 1.67;
	//For the for loop and for user input
	int i;
	int user;
	
	//Gets user input
	printf("Enter the amount: ");
	scanf("%d", &user);
	
	
	
	//Array of data points to ouput in table format
	float uSD[5] = {uSDxUSD, uSDxEUR, uSDxGBP, uSDxCAD, uSDxAUD};
	float gBP[5] = {gBPxUSD, gBPxEUR, gBPxGBP, gBPxCAD, gBPxAUD};
	float cAD[5] = {cADxUSD, cADxEUR, cADxGBP, cADxCAD, cADxAUD};
	float aUD[5] = {aUDxUSD, aUDxEUR, aUDxGBP, aUDxCAD, aUDxAUD};
	float eUR[5] = {eURxUSD, eURxEUR, eURxGBP, eURxCAD, eURxAUD};
	
	//Prints out the header
	printf("\tUSD\tEUR\tGBP\tCAD\tAUD\n");
	
	//Prints out the rows
	printf("USD\t");
	for(int i = 0; i < 5; i++){
		printf("%.2f\t", uSD[i] * user);
	}
	
	printf("\nEUR\t");
	for(int i = 0; i < 5; i++){
		printf("%.2f\t", eUR[i] * user);
	}
	
	printf("\nGBP\t");
	for(int i = 0; i < 5; i++){
		printf("%.2f\t", gBP[i] * user);
	}
	
	printf("\nCAD\t");
	for(int i = 0; i < 5; i++){
		printf("%.2f\t", cAD[i] * user);
	}
	
	printf("\nAUD\t");
	for(int i = 0; i < 5; i++){
		printf("%.2f\t", aUD[i] * user);
	}
	
	return 0;
	
}