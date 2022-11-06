#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //Bug - you need to include the library #include <string.h> beacuse you use functions from this library

//struct to collect counting info about english letters found in a text file.
typedef struct t_letter //Bug - need to give a different name for the variables of the *pointer =>  struct t_letter
{
	char small;
	char big; 
	int counter;
	struct t_letter* next; //Bug - need prev and next for creating the linked list => struct t_letter* next;
	struct t_letter* prev; //struct t_letter* prev;
}letter;
letter* HEAD; //Bug - they need to be global => letter* HEAD; letter* TAIL; 
letter* TAIL; 

//Function to free linked list
void freeList()  //Bug - you dont need to get a parameter because the HEAD is global 
{
	letter* releaseItem;
	letter* runItem = HEAD; //Bug - you need to write the global variable HEAD

	while (runItem != NULL) 
	{
		releaseItem = runItem;
		runItem = runItem->next;
		free(releaseItem);
	}
}

int main()
{
	//Next two string represents all the english alphabets (small and capital)
	char* smallAlpha = "abcdefghijklmnopqrstuvwxyz";
	char* bigAlpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int lettersCountArr[26] = { 0 }; //Bug - in  the english alphabet there is 26 letters => int lettersCountArr[26]
	char readChar, ch;
	FILE* f;
	f = fopen("myFile.txt", "r");
	if (f == NULL)  //Bug - there was no check if the file was opened successfully
	{
		//ERROR - write to log error that the file is not opened successfully
		return;
	}

	// Display the content of myFile.txt and count letters
	printf("the content of myFile.txt :\n");
	while ((readChar = fgetc(f)) != EOF)  //Bug - you need to check if its not EOF instead of 0 => fgetc(f)) != EOF
	{
		printf("%c", readChar);
		for (int i = 0; i < strlen(smallAlpha); ++i) 
		{
			if (readChar == smallAlpha[i] || readChar == bigAlpha[i])
				lettersCountArr[i]++;
		}
	}
	fclose(f);

	// Build Linked list from file content
	// Every node represent English letter (small and big).
	HEAD = NULL;
	TAIL = NULL;

	for (int j = 0; j < strlen(smallAlpha); ++j)
	{
		letter* letterItem = (letter*)malloc(sizeof(letter));
		if (!letterItem)
		{
			puts("Error Allocating Memory!");
			exit(1);
		}

		letterItem->small = 'a' + j;
		letterItem->big = 'A' + j;
		letterItem->counter = lettersCountArr[j];
		
		// Creating the linked list
		if (HEAD == NULL)  //Bug - when you are making a linked list you need to start with the condition : if (HEAD == NULL)
		{
			HEAD = letterItem;
			TAIL = letterItem;
			letterItem->next = NULL;
			letterItem->prev = NULL;
		}
		else
		{
			TAIL->next = letterItem;
			letterItem->prev = TAIL;
			TAIL = letterItem;
			TAIL->next = NULL; 
		}
	}

	return 0;
}