//Simple College Assignment implimentation...
//Some question are dynamic and some are static feel free to modify accordingly..
//Author github username (yankit293)..
//Author email (yankit293@gmail.com)..
#include <stdio.h>
#include <string.h>

char line[70] = "================================================================"; //string to print a line...
//function for all question in assignment 3.
void assignment_3()
{
	void am3_question_1();
	void am3_question_2();
	void am3_question_3();
	void am3_question_4();
	void am3_question_5();
	int am3_question_no;
	while (am3_question_no != 6)
	{
		printf("\n%s\n", line);
		printf("\nPlease Choose a question!\n");
		printf("1)Write a c program to  fill 5*5 matrix with following value?\n\ta)upper left triangle with 1s\n\tb)lower right triangle with -1s\n\tc)right to left diagonal with zero\n");
		printf("2)Write a C program to perform binary search operation for n element?\n");
		printf("3)Write a C program to  create function sorting that sort an array element of size 10.\n");
		printf("4)Write  a C program to  calculate Greatest common divisor of two number\n");
		printf("5)Write a C program that allow the user to enter a string and perform the following operation.\n\ta) Count the no of character in a string\n\tb) Removes spaces in a string\n\tc) Count the no of word in a string\n");
		printf("6) To Exit from Assignment 3");
		printf("\n%s\n", line);
		scanf("%d", &am3_question_no);
		switch (am3_question_no)
		{
		case 1:
			system("CLS"); //use clrscr(); on Turbo only..... or comment every system("CLS"); working fine on Dev c++ 5 version.
			am3_question_1();
			break;
		case 2:
			system("CLS");
			am3_question_2();
			break;
		case 3:
			system("CLS");
			am3_question_3();
			break;
		case 4:
			system("CLS");
			am3_question_4();
			break;
		case 5:
			system("CLS");
			am3_question_5();
			break;
		case 6:
			am3_question_no = 6;
			break;
		default:
			printf("Wrong Choice!");
			break;
		}
	}
}
void am3_question_1()
{

	int arr[5][5], i, j;
	int option;
	do
	{
		system("CLS");
		printf("1)Write a c program to  fill 5*5 matrix with following value?\n\ta)upper left triangle with 1s\n\tb)lower right triangle with -1s\n\tc)right to left diagonal with zero\n");
		for (i = 0; i < 5; i++)
		{
			for (j = 0; j < 5; j++)
			{
				if (i + j == 4)
					arr[i][j] = 0;
				else if (i + j < 4)
					arr[i][j] = 1;
				else
					arr[i][j] = -1;
			}
		}
		printf("\n%s\n", line);
		for (i = 0; i < 5; i++)
		{
			for (j = 0; j < 5; j++)
				printf("%d\t", arr[i][j]);
			printf("\n");
		}
		printf("Press 1 to continue or Press 2 to exit from question 1");
		scanf("%d", &option);
	} while (option == 1);
}
void am3_question_2()
{

	int option;
	do
	{
		system("CLS");
		printf("2)Write a C program to perform binary search operation for n element?\n");
		int binary_search(int *, int, int, int);
		int result, num, i;
		int arr[10] = {2, 3, 4, 6, 8, 9, 14, 17, 19, 21};
		for (i = 0; i < 10; i++)
		{
			printf("%d ", arr[i]);
		}
		printf("\nEnter a Number to Search\n");
		scanf("%d", &num);
		result = binary_search(arr, 0, 9, num);
		if (result != -1)
		{
			printf("\n%s\n", line);
			printf("\nElement %d found at index : %d\n", num, result);
		}
		else
		{
			printf("\n%s\n", line);
			printf("\nElement not Found!\n");
		}
		printf("\nPress 1 to continue or Press 2 to exit from question 2\n");
		scanf("%d", &option);
	} while (option == 1);
}
//function to search an element in a given sorted array...
int binary_search(int *arr, int low, int high, int elm)
{
	int mid;
	if (high >= low)
	{
		mid = (high + low) / 2;
		if (arr[mid] == elm)
			return mid;
		else if (arr[mid] > elm)
			return binary_search(arr, low, mid - 1, elm);
		else if (arr[mid] < elm)
			return binary_search(arr, mid + 1, high, elm);
	}
	else
		return -1;
}
void am3_question_3()
{
	void sort_array(int *);
	int option;
	do
	{
		system("CLS");
		printf("3)Write a C program to  create function sorting that sort an array element of size 10.\n");
		int i, arr[10];

		for (i = 0; i < 10; i++)
		{
			printf("Enter a Number\n");
			scanf("%d", &arr[i]);
		}
		sort_array(arr);
		printf("\n%s\n", line);
		printf("\nSorted array in descending order.......\n");
		for (i = 0; i < 10; i++)
		{
			printf("%d ", arr[i]);
		}
		printf("\nPress 1 to continue or Press 2 to exit from question 3\n");
		scanf("%d", &option);

	} while (option == 1);
}
//function to sort an integer array in descending order.....
void sort_array(int *arr)
{
	int i, j, t;
	for (i = 0; i < 10; i++)
	{
		for (j = i + 1; j < 10; ++j)
		{
			if (arr[i] < arr[j])
			{
				t = arr[i];
				arr[i] = arr[j];
				arr[j] = t;
			}
		}
	}
}
void am3_question_4()
{
	int option;
	do
	{
		system("CLS"); //use clrscr(); in Turbo......
		printf("4) Write  a C program to  calculate Greatest common divisor of two number\n");
		int i, num1, num2, k, gcd = 1;
		printf("\nEnter Two number to get it's GCD\n");
		scanf("%d%d", &num1, &num2);
		if (num1 > num2)
			k = num2;
		else
			k = num1;
		for (i = 2; i <= k; i++)
		{
			if (num1 % i == 0 && num2 % i == 0)
				if (gcd < i)
					gcd = i;
		}
		printf("\n%s\n", line);
		printf("Greatest Common Divisor of %d and %d is: %d", num1, num2, gcd);
		printf("\nPress 1 to continue or Press 2 to exit from question 4\n");
		scanf("%d", &option);
	} while (option == 1);
}
void am3_question_5()
{
	void remove_spaces(char *);
	int count_character(char *);
	int count_word(char *);
	int option;

	do
	{
		system("CLS");
		char str[50];
		printf("5)Write a C program that allow the user to enter a string and perform the following operation.\n\ta) Count the no of character in a string\n\tb) Removes spaces in a string\n\tc) Count the no of word in a string\n");
		printf("Enter A String <50.");
		scanf(" %[^\n]s", str);
		int option1 = 0;
		while (option1 != 4)
		{
			printf("\n%s\n", line);
			printf("\nPlease Choose an option to Perform below task!\n1) Count the no of character in a string.\n2) Removes spaces in a string.\n3) Count the no of word in a string.\n4) Exit\n");
			printf("\n%s\n", line);
			scanf(" %d", &option1);
			if (option1 == 1)
			{
				printf("\n%s\n", line);
				printf("\n\nTotal Character in String : %d\n", count_character(str));
			}
			else if (option1 == 2)
			{
				printf("\n%s\n", line);
				remove_spaces(str);
			}
			else if (option1 == 3)
			{
				printf("\n%s\n", line);
				printf("\n\nTotal Words in String : %d\n", count_word(str));
			}
			else if (option1 == 4)
				break;
			else
				printf("\nWrong Option");
		}
		printf("\nPress 1 to continue or Press 2 to exit from question 5\n");
		scanf(" %d", &option);
	} while (option == 1);
}
//Function To remove spcaes
void remove_spaces(char *str)
{
	char temp[50];
	int i = 0, j = 0;
	strcpy(temp, str);
	while (temp[i])
	{
		if (temp[i] != ' ')
			temp[j++] = temp[i];
		i++;
	}
	temp[j] = '\0';
	printf("\n%s\n", temp);
}
//function to count character in a string..
int count_character(char *str)
{
	int i = 0, counter = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			counter += 1;
		i++;
	}
	return counter;
}
//function to count words in a string...
int count_word(char *str)
{
	int i = 0, counter = 0;
	while (str[i])
	{
		if (str[i] == ' ' && str[i + 1] != ' ')
			counter++;
		i++;
	}
	return counter + 1;
}

//Function for assignment 4 all question..
void assignment_4()
{
	void am4_question_1();
	void am4_question_2();
	void am4_question_3();
	void am4_question_4();
	void am4_question_5();
	void am4_question_6();
	int am4_question_no;
	while (am4_question_no != 7)
	{
		printf("\n%s\n", line);
		printf("\nPlease Choose a question!\n");
		printf("1)Write a program that accepts two strings.\nThe program should add second string  at the end of the first string.(string concatenate)\n");
		printf("2)Write a program to create a function name “avg” that accepts an array of integers and displays the average using pointer.\n");
		printf("3)Write a C program to create  swap  function that will swap two variable using pointer.\n");
		printf("4)write a program to reverse the character array using pointer.\nFor example:\n\tChar a[20]=”hello”;\n\tOutput:olleh\n");
		printf("\nAdvanced Data Types & Sorting\n");
		printf("5)Write a C program to implement an inventory system. Store the item number,name, rate and quantity on hand in a structure.\nAccept the details for five items into a structure array and display the item name and its total price.\n At the end,display the grand total value of the inventory.\n");
		printf("6)Write a C program to store the names and scores of 5 students in a structure array.\nSort the structure array in descending order of scores. Display the top 3scores.\n");
		printf("7)To Exit from Assignment 4");
		printf("\n%s\n", line);
		scanf("%d", &am4_question_no);
		switch (am4_question_no)
		{
		case 1:
			system("CLS");
			am4_question_1();
			break;
		case 2:
			system("CLS");
			am4_question_2();
			break;
		case 3:
			system("CLS");
			am4_question_3();
			break;
		case 4:
			system("CLS");
			am4_question_4();
			break;
		case 5:
			system("CLS");
			am4_question_5();
			break;
		case 6:
			system("CLS");
			am4_question_6();
			break;
		case 7:
			am4_question_no = 7;
			break;
		default:
			printf("Wrong Choice!");
			break;
		}
	}
}
void am4_question_1()
{
	char str1[50], str2[20];
	int i, j, option;
	do
	{
		printf("1)Write a program that accepts two strings.\nThe program should add second string  at the end of the first string.(string concatenate)\n\n");

		printf("Enter String 1 <30\n");
		scanf(" %[^\n]s", str1);
		printf("Enter String 2 <20\n");
		scanf(" %[^\n]s", str2);

		for (i = 0; str1[i] != '\0'; i++)
			;
		for (j = 0; str2[j] != '\0'; j++)
		{
			str1[i] = str2[j];
			i++;
		}
		str1[i] = '\0';
		printf("\n%s\n", line);
		printf("Concatenated String:%s", str1);
		printf("\nPress 1 to continue or Press 2 to exit from question 5\n");
		scanf(" %d", &option);
	} while (option == 1);
}
void am4_question_2()
{
	void avg(int arr[]);
	int arr[5], i, option;
	do
	{
		printf("2)Write a program to create a function name “avg” that accepts an array of integers and displays the average using pointer.\n");
		for (i = 0; i < 5; i++)
		{
			printf("Enter Arr[%d]\n", i + 1);
			scanf("%d", &arr[i]);
		}
		avg(arr);
		printf("\nPress 1 to continue or Press 2 to exit from question 5\n");
		scanf(" %d", &option);
	} while (option == 1);
}
//function to print average of integer array...
void avg(int arr[])
{
	int i, sum = 0, avrg, *p;
	for (i = 0; i < 5; i++)
	{
		sum += arr[i];
	}
	avrg = sum / i;
	p = &avrg;
	printf("\n%s\n", line);
	printf("Average of all number in array:%d", *p);
}
void am4_question_3()
{
	int a, b, option;
	void swap(int *, int *);
	do
	{

		printf("3)Write a C program to create  swap  function that will swap two variable using pointer.\n");
		printf("Enter Two Interger value to swap.\n");
		scanf("%d%d", &a, &b);
		printf("\n%s\n", line);
		printf("Before swap a:%d b:%d\n", a, b);
		swap(&a, &b);
		printf("After swap a:%d b:%d\n", a, b);
		printf("\nPress 1 to continue or Press 2 to exit from question 5\n");
		scanf(" %d", &option);
	} while (option == 1);
}
//function to swap to variable value using pointer.....
void swap(int *p, int *q)
{
	int t; // temp variable
	t = *p;
	*p = *q;
	*q = t;
}
void am4_question_4()
{

	char str[50], *start_index, *end_index, ch;
	int i, j, option;
	do
	{
		printf("4)write a program to reverse the character array using pointer.\nFor example:\n\tChar a[20]=”hello”;\n\tOutput:olleh\n");
		printf("Enter A string to reverse...\n");
		scanf("%s", str);
		start_index = str;
		end_index = str;
		j = strlen(str);
		for (i = 0; i < j - 1; i++)
			end_index++;
		for (i = 0; i < j / 2; i++)
		{

			ch = *end_index;
			*end_index = *start_index;
			*start_index = ch;

			end_index--;
			start_index++;
		}
		printf("\n%s\n", line);
		printf("Reverse of String:%s", str);
		printf("\nPress 1 to continue or Press 2 to exit from question 5\n");
		scanf(" %d", &option);
	} while (option == 1);
}
void am4_question_5()
{
	struct inventry
	{
		int item_number;
		char item_name[20];
		float item_rate;
		int quantity_on_hand;
	} item[5];
	int i, option;
	float total_price, grand_total = 0;
	do
	{
		printf("5)Write a C program to implement an inventory system. Store the item number,name, rate and quantity on hand in a structure.\nAccept the details for five items into a structure array and display the item name and its total price.\n At the end,display the grand total value of the inventory.\n");
		for (i = 0; i < 5; i++)
		{
			printf("Enter the Number of Item %d.\n", i + 1);
			scanf(" %d", &item[i].item_number);
			printf("Enter the name of Item %d.\n", i + 1);
			scanf(" %[^\n]s", item[i].item_name);
			printf("Enter the rate of Item %d.\n", i + 1);
			scanf("%0.2f", &item[i].item_rate);
			printf("Enter the quantity on hand of item %d.\n", i + 1);
			scanf("%d", &item[i].quantity_on_hand);
		}
		printf("\n%s\n", line);
		for (i = 0; i < 5; i++)
		{
			printf("\n%s\n", line);
			printf("Item number:%d\nItem Name:%s\nItem Rate:%0.2fRs.\nItem Quantity on hand:%d\nTotal price of Item:%0.2fRs.\n\n", item[i].item_number, item[i].item_name, item[i].item_rate, item[i].quantity_on_hand, item[i].item_rate * item[i].quantity_on_hand);
			grand_total += item[i].item_rate * item[i].quantity_on_hand;
		}
		printf("Grand Total:%f", grand_total);
		printf("\nPress 1 to continue or Press 2 to exit from question 5\n");
		scanf(" %d", &option);
	} while (option == 1);
}
void am4_question_6()
{

	struct records
	{
		char name[20];
		int score;
	} student[5];
	int i, j, t, option;
	char temp[20];

	do
	{
		printf("6)Write a C program to store the names and scores of 5 students in a structure array.\nSort the structure array in descending order of scores. Display the top 3scores.\n");

		for (i = 0; i < 5; i++)
		{
			printf("Enter the Name of student %d:", i + 1);
			scanf(" %[^\n]s", student[i].name);
			printf("Enter the score of student %d:", i + 1);
			scanf("%d", &student[i].score);
		}

		for (i = 0; i < 5; i++)
		{
			for (j = i + 1; j < 5; ++j)
			{
				if (student[i].score < student[j].score)
				{
					//sorting scores
					t = student[i].score;
					student[i].score = student[j].score;
					student[j].score = t;
					//sorting names
					strcpy(temp, student[i].name);
					strcpy(student[i].name, student[j].name);
					strcpy(student[j].name, temp);
				}
			}
		}
		printf("\n%s\n", line);
		for (i = 0; i < 3; i++)
		{
			printf("\nName of student at %d position : %s\n Score of student:%d\n", i + 1, student[i].name, student[i].score);
		}
		printf("\nPress 1 to continue or Press 2 to exit from question 5\n");
		scanf(" %d", &option);
	} while (option == 1);
}
int main()
{
	void assignment_3();
	void assignment_4();
	int m_option = 0;
	while (m_option != 3)
	{
		system("CLS");
		printf("\nChoose an option from below\n");
		printf("1). Assignment 3\n2). Assignment 4\n3) Exit.\n");
		scanf("%d", &m_option);
		if (m_option == 1)
		{
			system("CLS"); //
			assignment_3();
		}
		else if (m_option == 2)
		{
			system("CLS");
			assignment_4();
		}
		else if (m_option == 3)
			break;
		else
			printf("Wrong Choice");
		continue;
	}

	return 0;
}
