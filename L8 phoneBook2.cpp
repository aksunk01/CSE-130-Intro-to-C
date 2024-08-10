#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NAME_LEN 16
#define PHONE_NUM_LEN 16



#define WORD_LENGTH 16;


typedef struct Contact{
	char first_name[NAME_LEN];
	char last_name[NAME_LEN];
	char phone_number[PHONE_NUM_LEN];
}Contact;

enum CMP_ORDER{
	FIRST_NAME_PRIMARY,
	LAST_NAME_PRIMARY,
};

int compare_contacts(Contact *contact1, Contact *contact2, enum CMP_ORDER order){
	if(order == FIRST_NAME_PRIMARY){
		int result = strcmp(contact1->first_name, contact2->first_name);
		if(result != 0){
			return result;
		}else{
			return strcmp(contact1->last_name, contact2->last_name);
		}
	}else{
		int result = strcmp(contact1->last_name, contact2->last_name);
		if(result!=0){
			return result;
		}else{
			return strcmp(contact1->first_name, contact2->first_name);
		}
	}
}

void print_contact(Contact* contact){
	printf("\n%16s %-16s:%-16s", contact->first_name,contact->last_name, contact->phone_number);
}

Contact* create_contact(char* first_name, char* last_name, char* phone_number){
	Contact* c = (Contact *) malloc(sizeof(Contact));
	strcpy(c->first_name, first_name);
	strcpy(c->last_name, last_name);
	strcpy(c->phone_number, phone_number);
	return c;
}

void delete_contact(Contact* contact){
	free(contact);
	
}

typedef struct Phonebook{
	Contact ** contacts;
	int size;
	int capacity;
}PhoneBook;

void print_phone_book(PhoneBook *phone_book){
	printf("\n%-16s %-16s:%-16s", "First name", "Last name", "Phone number");
	printf("\n%-16s %-16s:%-16s", "----------", "---------", "------------");
	for(int i = 0; i < phone_book->size; ++i){
		print_contact(phone_book->contacts[i]);
	}
	printf("\nSize: %d, Capacity: %d", phone_book->size, phone_book->capacity);
}

PhoneBook *create_phone_book(int capacity){
	PhoneBook *phone_book = (PhoneBook *)malloc(sizeof(PhoneBook));
	phone_book->size = 0;
	phone_book->capacity = capacity;
	phone_book->contacts = (Contact **)malloc(capacity * sizeof(Contact *));
	return phone_book;
}

void delete_phone_book(PhoneBook *phone_book){
	printf("Deleting phone book... \n");
	for(int i = 0; i < phone_book->size; ++i){
		delete_contact(phone_book->contacts[i]);
	}
	free(phone_book->contacts);
	free(phone_book);
}

void add_contact(PhoneBook *phone_book, char *first_name, char *last_name, char *phone_number){
	if(phone_book->size == phone_book->capacity){
		phone_book->capacity = 1 + phone_book->capacity * 2;
		phone_book->contacts = (Contact **)realloc(phone_book->contacts, phone_book->capacity * sizeof(Contact *));
	}
	phone_book->contacts[phone_book->size++] = create_contact(first_name, last_name, phone_number);
}

int find_contact(PhoneBook *phone_book, char *first_name, char *last_name){
	for(int i = 0; i < phone_book->size; ++i){
		if(strcmp(phone_book->contacts[i]->first_name, first_name) == 0 && strcmp(phone_book->contacts[i]->last_name, last_name) == 0){
			return i;
		}
	}
	return -1;
}

void remove_contact(PhoneBook *phone_book, char* first_name, char* last_name){
	int index = find_contact(phone_book, first_name, last_name);
	if(index != -1){
		delete_contact(phone_book->contacts[index]);
		phone_book->contacts[index] = phone_book->contacts[phone_book->size -1];
		phone_book->size--;
	}else{
		printf("\nContact not found!\n");
	}
}

void randomly_pick(PhoneBook *book){
	int index = rand() & book->size;
	print_contact(book->contacts[index]);
}

void clear_phone_book(PhoneBook *phone_book){
	for(int i = 0; i < phone_book->size; ++i){
		delete_contact(phone_book->contacts[i]);
	}
	phone_book->size = 0;
}

void insertion_sort(PhoneBook *phone_book, enum CMP_ORDER order){
	for(int i =1; i < phone_book->size; i++){
		Contact *to_be_inserted = phone_book->contacts[i];
		int insert_after = i -1;
		while(insert_after >= 0 && compare_contacts(phone_book->contacts[insert_after], to_be_inserted, order) > 0){
			phone_book->contacts[insert_after + 1] = phone_book->contacts[insert_after];
			insert_after--;
		}
		phone_book->contacts[insert_after +1] = to_be_inserted;
	}
}

int menu(){
	printf("\nMenu: 1)" 
			"\n1)Add friend" 
			"\n2) Delete contact" 
			"\n3) Show contacts" 
			"\n4) Find contacts"
			"\n5) Sort Contacts(First_name_Primary)"
			"\n6) Sort Contacts(Last_name_Primary)"
			"\n7) Randomly pick a contact"
			"\n8) Delete all contacts"
			"\n9) Print from document"
			"\n10 Exit\n");
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

	static char buffer[512];
	char filename[256];

	int choice = 0;
	char blank;
	FILE *fp;
	FILE *fp_read;
	printf("Enter the name of the file to save data: ");
	scanf("%s", filename);

	srand(time(NULL));
	static int option;
	static char first_name[NAME_LEN];
	static char second_name[NAME_LEN];
	static char phone_number[PHONE_NUM_LEN];
	PhoneBook *phone_book = create_phone_book(2);
	add_contact(phone_book, "Abi", "Sunkara", "50");
	add_contact(phone_book, "Friend", "1", "40");
	
	
	Contact** book = NULL; //book is an array that it's element is points;
					//We use tindex to access the contact pointer just like book[0]

	fp = fopen(filename, "w");
	
	if(fp == NULL){
		printf("Error opening file %s", filename);
		return 1;
	}
	
	
	for(;;){
		option = menu();
		switch(option){
			case 1:{
				read_name(first_name, second_name);
				read_phone_number(phone_number);
				add_contact;
				fprintf(fp, "%s,%s,%s\n", first_name, second_name, phone_number);
				break;
			}
			case 2:{
				read_name(first_name,second_name);
				remove_contact(phone_book, first_name, second_name);
				break;
			}
			case 3:{
				print_phone_book(phone_book);
				break;
			}
			case 4:{
				read_name(first_name, second_name);
				int index = find_contact(phone_book, first_name, second_name);
				if(index != -1){
					print_contact(phone_book->contacts[index]);
				}else{
					printf("\nContact not found!\n");
				}
				break;
			}
			case 5:{
				insertion_sort(phone_book, FIRST_NAME_PRIMARY);
				print_phone_book(phone_book);
				break;
			}
			case 6:{
				insertion_sort(phone_book, LAST_NAME_PRIMARY);
				print_phone_book(phone_book);
				break;
			}
			case 7:{
				randomly_pick(phone_book);
				break;
			}
			case 8:{
				clear_phone_book(phone_book);
				break;
			}
			case 9:{
				if(fp == NULL){
					printf("file cannot be read");
				}else{
					printf("\nName\tNumber\n\n");
					fscanf(fp, "%s%s%s", first_name, second_name, phone_number);
				}
				
				break;
			}
			case 10:{
				delete_phone_book(phone_book);
				return 0;
			}
			default:{ 
				printf("\nInvalid option!\n");
			}	
		}
	}
	fclose(fp);
}