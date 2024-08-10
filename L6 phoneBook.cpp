#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 16
#define PHONE_NUM_LEN 16


typedef struct Contact{
	char first_name[NAME_LEN];
	char second_name[NAME_LEN];
	char phone_number[PHONE_NUM_LEN];
}Contact;

void print_contact(Contact* contact){
	printf("\n%16s %-16s:%-16s", contact->first_name,contact->second_name, contact->phone_number);
}

Contact* create_contact(char* first_name, char* second_name, char* phone_number){
	Contact* c = (Contact *) malloc(sizeof(Contact));
	strcpy(c->first_name, first_name);
	strcpy(c->second_name, second_name);
	strcpy(c->phone_number, phone_number);
	return c;
}

void delete_contact(Contact* contact){
	free(contact);
	
}


int menu(){
	printf("\nMenu: 1) Add friend; 2) Delete friend; 3) Show phone book 4) Exit");
	int r;
	scanf("%d", &r);
	getchar(); //read the newline char
	return r;
	
}

void safe_read(char *buffer, unsigned int buffer_size){
	fgets(buffer, buffer_size, stdin);
	if (buffer[strlen(buffer) -1] == '\n'){
		buffer[strlen(buffer) - 1] = '\0';
	}
}

void read_name(char *first_name, char*second_name){
	printf("\nFirst name: ");
	safe_read(first_name, NAME_LEN);
	printf("\nSecond name: ");
	safe_read(second_name, NAME_LEN);
}

void read_phone_number(char *phone_number){
	printf("\nPhone number: ");
	safe_read(phone_number, PHONE_NUM_LEN);
}




int main(){
	static int option;
	static char first_name[NAME_LEN];
	static char second_name[NAME_LEN];
	static char phone_number[PHONE_NUM_LEN];
	
	
	Contact** book = NULL; //book is an array that it's element is points;
					//We use tindex to access the contact pointer just like book[0]
	
	int size = 0;
	int capacity = 0;
	
	for(;;){
		option = menu();
		switch(option){
			case 1:{
				read_name(first_name, second_name);
				read_phone_number(phone_number);
				Contact* contact = create_contact(first_name, second_name,phone_number);
				if(size == capacity){
					int extend = 10;
					capacity +=extend;
					book = (Contact**) realloc(book,capacity*sizeof(Contact*));
				}
				size+=1;
				break;
			}
			case 2:{
				read_name(first_name,second_name);
				for(int i = 0; i < size; ++i){
					if(book[i] == NULL) continue;
					if(strcmp(book[i]->first_name,first_name) == 0 && strcmp(book[i] ->second_name, second_name)==0){
						delete_contact(book[i]);
						book[i] = NULL;
						break;
					}
				}
				break;
			}
			case 3:{
				for(int i = 0; i < size; i++){
					if(book[i] != NULL){
						print_contact(book[i]);
					}
				}

				break;
			}
			case 4:{
				for(int i = 0; i < size; ++i){
					if(book[i] != NULL){
						delete_contact(book[i]);
					}
				}
				free(book);
				return 0;
				break;
			}
			default:{ 
				break;
			}	
		}
	}
}