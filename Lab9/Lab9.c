#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"

/* DO NOT EDIT THE LINES BELOW */
#define STRING_MAX 1024

typedef struct node {
	char *name;
	int lines;
	int runtime;
	int memory_usage;

	struct node *next;
} Node;

typedef struct linked_list {
	Node *head;
} LinkedList;

void readInputString(char *, int);
void readInputNumber(int *);
void readInputChar(char *);

LinkedList * newList();
char getCommand();

void handleInsert(LinkedList *);
void handleDelete(LinkedList *);
void handleSearch(LinkedList *);
void handlePrint(LinkedList *);
void handleQuit(LinkedList *);

int main() {
	LinkedList *list = newList();
	char command = '\0';

	printf("Experimental database entry\n");

	while (command != 'Q') {
		command = getCommand();

		switch (command) {
			case 'I':
				handleInsert(list);
				break;
			case 'D':
				handleDelete(list);
				break;
			case 'S':
				handleSearch(list);
				break;
			case 'P':
				handlePrint(list);
				break;
			case 'Q':
				handleQuit(list);
				break;
		}
	}

	free(list);
	return 0;
}
/* DO NOT EDIT THE LINES ABOVE */

void handleInsert(LinkedList *list) {
	// place your code to handle the insert command here
  
  printf("Number of characters in file name: ");
  int nameSize = 0;
  Node* inputList;
  LinkedList input;
  input.head = inputList;
  readInputNumber(&nameSize);
  printf("File name: ");
  readInputString(inputList->name, nameSize);
  printf("Number of lines in CSV file: ");
  readInputNumber(&inputList->lines);
  printf("Experiment runtime (ms): ");
  readInputNumber(&inputList->runtime);
  printf("Experiment memory usage (B): ");
  readInputNumber(&inputList->memory_usage);

  Node* iterator = list->head, *copyList;
  LinkedList copy, iter;
  copy.head = copyList;
  iter.head = iterator;
  while(1) {
    if (strcmp(inputList->name, iterator->name) > 0) {
      copyList->next = inputList;
      inputList = iterator;
      break;
    }
    else if (strcmp(inputList->name, iterator->name) < 0) {
      inputList->next = iterator->next;
      iterator = inputList;
      break;
    }
    else
      printf("An entry with that file name already exists.");
    copy = iter;
    iterator = iterator->next;
  }
}

void handleDelete(LinkedList *list) {
  printf("\nEnter file name to delete:\n");
  char name[STRING_MAX];
  readInputString(name, STRING_MAX);
  Node* iterator = list->head, *copyList;
  LinkedList copy, iter;
  copy.head = copyList;
  iter.head = iterator;
  while(iterator != NULL) {
    if (name == iterator->name) {
      printf("Deleting entry for CSV file <%s>", name);
      iterator = iterator->next;
      copyList->next = iterator;
      break;
    }
    copy = iter;
    iterator = iterator->next;
  }
  printf("An entry for file <%s> does not exist.", name);
}

void handleSearch(LinkedList *list) {
	// place your code to handle the search command here
  printf("\nData entries:\n");
  char name[STRING_MAX];
  readInputString(name, STRING_MAX);
  Node* iterator = list->head;
  while(iterator != NULL) {
    if (name == iterator->name) {
      printf("File <%s>\nLines: %d\nRuntime (ms): %d\nMemory usage (B): %d\nThroughput: %.2lf", iterator->name, iterator->lines, iterator->runtime, iterator->memory_usage, ((double)iterator->lines)/(iterator->runtime));
      break;
    }
    iterator = iterator->next;
  }
  printf("An entry for file <%s> does not exist.", name);
}

void handlePrint(LinkedList *list) {
	// place your code to handle the print command here
  printf("\nEnter file name to find:\n");
  Node* iterator = list->head;
  while(iterator != NULL) {
    printf("File <%s>\nLines: %d\nRuntime (ms): %d\nMemory usage (B): %d\nThroughput: %.2lf", iterator->name, iterator->lines, iterator->runtime, iterator->memory_usage, ((double)iterator->lines)/(iterator->runtime));
    iterator = iterator->next;
  }
}

void handleQuit(LinkedList *list) {
	// place your code to handle the quit command here
  Node* iterator = list->head;
  while(iterator != NULL) {
    printf("Deleting entry for CSV file <%s>", iterator->name);
    LinkedList* listCopy = list;
    iterator = iterator->next;
    free(listCopy);
  }
}

/* DO NOT EDIT THE LINES BELOW */
void readInputString(char *str, int length) {
	int i = 0;
	char c;

	while (i < length && (c = getchar()) != '\n') {
		str[i++] = c;
	}

	str[i] = '\0';
}

void readInputNumber(int *number) {
	char buf[STRING_MAX];
	readInputString(buf, STRING_MAX);
	*number = (int)strtol(buf, (char **)NULL, 10);
}

void readInputChar(char *character) {
	char buf[2];
	readInputString(buf, 3);
	*character = buf[0];
}

LinkedList * newList() {
	LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
	list->head = NULL;
	return list;
}

char getCommand() {
	char command;

	printf("\nSupported commands are:\n");
	printf("  I - Insert\n");
	printf("  D - Delete\n");
	printf("  S - Search\n");
	printf("  P - Print\n");
	printf("  Q - Quit\n");

	printf("\nPlease select a command: ");
	readInputChar(&command);

	while (command != 'I' && command != 'D' && command != 'S' && command != 'P' && command != 'Q') {
		printf("Invalid command <%c>, please select a command: ", command);
		readInputChar(&command);
	}

	return command;
}
/* DO NOT EDIT THE LINES ABOVE */
