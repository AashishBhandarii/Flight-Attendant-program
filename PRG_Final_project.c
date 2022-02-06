
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct Seats 
{

	int seatNo, report;
	char Firstname[20], Lastname[20];

};

void setupseats(seats);
void showallSeats(seats);
void showallemptyseats(seats);
void showallassignedseat(seats);
void assignnewseat(seats);
void deleteonlyoneAssignment(seats);
void deleteallseats(seats);
void programmers_block(void);
int main_menu(void);

int main()
{
	

	programmers_block();
	main_menu();

	_getch();
	return 0;

}

void programmers_block(void)
{
	printf("\n\n\n\n\n\n\t\t\t\t\t=================================\n");
	printf("\n\t\t\t\t\tprogram: PRG_Final_project.c\n");
	printf("\t\t\t\t\tprogrammer : Sanamjeet Singh\n");
	printf("\t\t\t\t\tdate : NOV 29, 2021\n");
	printf("\t\t\t\t\tpurpose : Econo-Flight Airline Reservation Program\n");
	printf("\n\n\t\t\t\t\t=================================\n");
	_getch();
	system("cls");

	return;
}



int main_menu(void) {

	struct Seats seats[12];
	setupseats(seats);

	char choice;

	
	while (1) {

		printf("\na. Display ALL 12 seats assignments (including Empty).\n");
		printf("\nb. Show ONLY a list of empty seats and show total of empty seats");
		printf("\nc. SHOW ONLY the assigned seats with name of person and total assigned.");
		printf("\nd. Assign the customer to an empty seat.");	
		printf("\ne. Delete ONE seat assignment.");
		printf("\nf. Delete ALL seat assignments.");
		printf("\nq. Quit program.");
		printf("\nEnter Choice: ");

		choice = getchar();

		switch (choice) {

		case 'a':

			showallSeats(seats);
			break;

		case 'b':

			showallemptyseats(seats);
			break;

		case 'c':

			showallassignedseat(seats);
			break;

		case 'd':

			assignnewseat(seats);
			break;

		case 'e':

			deleteonlyoneAssignment(seats);
			break;

		case 'f':

			deleteallseats(seats);
			break;

		case 'q':

			exit(0);

		}

		getchar();

	}

	return 0;

}

/* function will assign seat No and set all seats as empty */

void setupseats(struct Seats* seats) 
{

	int i;

	for (i = 0; i < 12; i++)
	{

		seats[i].seatNo = i + 1;

		seats[i].report = 0;

	}

}

/* function will display the report of all the seats */

void showallSeats(struct Seats* seats)
{

	printf("\n");

	int i;

	printf("No\tReport\n");

	for (i = 0; i < 12; i++) 
	{

		printf("%d\t", seats[i].seatNo);

		if (seats[i].report == 0)

			printf("Empty seat\n");

		else

			printf("Assigned to %s %s\n", seats[i].Firstname, seats[i].Lastname);

	}

}

/* function will display all empty seats */

void showallemptyseats(struct Seats* seats) 
{

	printf("\n");

	int i, x = 0;

	printf("List of empty seats:\n");

	for (i = 0; i < 12; i++) {

		if (i % 2 == 0) 
		{

			if (seats[i].report == 0) 
			{

				printf("\n%d", seats[i].seatNo);

				x++;

			}

		}

		else {

			if (seats[i].report == 0) 
			{

				printf("\t%d", seats[i].seatNo);

				x++;

			}

		}

	}

	printf("\nTotal no of empty seats: %d\n", x);

}

/* function will show all the seats that are assigned and name of the person */

void showallassignedseat(struct Seats* seats) 
{

	printf("\n");

	int i, x = 0;

	printf("List of assigned seats:\n");

	printf("Id\tName\n");

	for (i = 0; i < 12; i++) {

		if (seats[i].report == 1) 
		{

			printf("%d\t%s %s\n", seats[i].seatNo, seats[i].Firstname, seats[i].Lastname);

			x++;

		}

	}

	printf("Total no of assigned seats: %d\n", x);

}

/* function will assigns the seat and asks the seat no and name  */

void assignnewseat(struct Seats* seats) 
{

	printf("\n");

	int No;

	printf("Enter Seat No: ");
	scanf("%d", &No);

	while (seats[No - 1].report == 1) 
	{

		printf("Seat already assigned! Please enter another Seat Id: ");

		scanf("%d", &No);

	}

	printf("Enter the First Name: ");
	scanf("%s", seats[No - 1].Firstname);

	printf("Enter the Last Name: ");
	scanf("%s", &seats[No - 1].Lastname);

	seats[No - 1].report = 1;

}

/* function will delete a single seat assignment by asking their seat no */

void deleteonlyoneAssignment(struct Seats* seats) {

	printf("\n");

	int No;

	printf("Enter the Seat No: ");
	scanf("%d", &No);

	seats[No - 1].report = 0;

}

/* function will delete all the seat assignment */

void deleteallseats(struct Seats* seats) {

	int i;

	for (i = 0; i < 12; i++) 
	{

		seats[i].report = 0;

	}

}

