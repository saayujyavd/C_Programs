#include <stdio.h>
#include "mymalloc.h"

#define MAX_NAME 128

typedef struct
{
	char name[MAX_NAME], marital_stat[MAX_NAME];
	float age;
}
Person;

main()
{
	Person* person = (Person*)mymalloc(sizeof(Person) * 1);

	printf("Age: ");
	scanf("%f", &person->age);
	while (getchar() != '\n');   // drain the rest of the line, including '\n

	printf("Name: ");
	fgets(person->name, MAX_NAME, stdin);

	printf("Marital status: ");
	fgets(person->marital_stat, MAX_NAME, stdin);

	printf("\nAge: %f", person->age);
	printf("\nName: %s", person->name);
	printf("Marital status: %s", person->marital_stat);

	if (person)
		myfree(person);
	return(0);
}
