
/*
*A Simple Program to Store Student Records in A txt File.
*And perform Some task on it i.e read, write and append records.
*Author: yankit293(github)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *f1;
struct Result{
    int Roll_no;
    char name[20];
    int marks[3];
    int obtain_marks;
    int percentage;
    char division[10];
};
char line[70] = "================================================================";


int main()
{   
    void write_in_file();
    void read_file();
    void append_file();
    int choice;
    while (choice != 4)
    {
        printf("%s\n", line);
        printf("1)Write the Result File(This will Override previous records!\n");
        printf("2)Read the Result File.\n");
        printf("3)Append the Result File(Add more records)\n");
        printf("4) Exit.\n");
        printf("%s\n", line);
        printf("What do you want to do ???\n");
        scanf(" %d", &choice);

        switch (choice)
        {
        case 1:
            write_in_file();
            break;
        case 2:
            read_file();
            break;

        case 3:
            append_file();
            break;

        case 4:
            choice = 4;
            break;
        default:
            break;
        }
    }

    return 0;
}
void write_in_file()
{
    struct Result student[3];

    int i, j, total, n = 3;
    f1 = fopen("Result.dat", "w");
    if (f1 != NULL)
    {
        for (i = 0; i < n; i++)
        {
            //student Roll number
            printf("Enter Student %d Roll Number\n", i + 1);
            scanf("%d", &student[i].Roll_no);
            //student Name
            printf("Enter Student %d name\n", i + 1);
            scanf(" %[^\n]s", student[i].name);
            //Student Marks
            total = 0;
            for (j = 0; j < 3; j++)
            {
                printf("Enter Student %d Subject %d mark.\n", i + 1, j + 1);
                scanf("%d", &student[i].marks[j]);
                total += student[i].marks[j];
            }
            student[i].obtain_marks = total;
            student[i].percentage = total/3;
            if(student[i].percentage > 60){
                strcpy(student[i].division,"First");
            }
            else if(student[i].percentage > 45 || student[i].percentage < 60){
                strcpy(student[i].division,"Second");
            }
            else if(student[i].percentage > 33 || student[i].percentage < 45){
                strcpy(student[i].division,"Third");
            }
            else{
                strcpy(student[i].division,"Fail");
            }        
        }
        for (i = 0; i < n; i++)
        {
            fwrite(&student[i], sizeof(struct Result), 1, f1);
        }
        if (fwrite != 0)
            printf("contents to file written successfully !\n");
        else
            printf("error writing file !\n");
    }
    else
        printf("Unable to open file!\n");

    fclose(f1);
}
void read_file()
{
    struct Result student;
    f1 = fopen("Result.dat", "r");
    int i=0;
    if (f1 != NULL)
    {   
        while(fread(&student, sizeof(struct Result), 1, f1)){
            printf ("Roll Number = %d\nname = %s\nSubject1 = %d\nsubject2 = %d\nsubject3 = %d\nobtain marks = %d\nPercentage = %d\nDivision = %s\n\n\n",
            student.Roll_no, student.name, student.marks[0],student.marks[1],student.marks[2],
            student.obtain_marks, student.percentage, student.division);
        }
        
    }
    fclose(f1);
}
void append_file(){
    int i, j, total, n;
    f1 = fopen("Result.dat", "a");
    if (f1 != NULL)
    {
        printf("How many student record you want to add?\n");
        scanf("%d", &n);
        struct Result student['n'];
        for (i = 0; i < n; i++)
        {
            //student Roll number
            printf("Enter Student %d Roll Number\n", i + 1);
            scanf("%d", &student[i].Roll_no);
            //student Name
            printf("Enter Student %d name\n", i + 1);
            scanf(" %[^\n]s", student[i].name);
            //Student Marks
            total = 0;
            for (j = 0; j < 3; j++)
            {
                printf("Enter Student %d Subject %d mark.\n", i + 1, j + 1);
                scanf("%d", &student[i].marks[j]);
                total += student[i].marks[j];
            }
            student[i].obtain_marks = total;
            student[i].percentage = total/3;
            if(student[i].percentage > 60){
                strcpy(student[i].division,"First");
            }
            else if(student[i].percentage > 45 || student[i].percentage < 60){
                strcpy(student[i].division,"Second");
            }
            else if(student[i].percentage > 33 || student[i].percentage < 45){
                strcpy(student[i].division,"Third");
            }
            else{
                strcpy(student[i].division,"Fail");
            }        
        }
        for (i = 0; i < n; i++)
        {
            fwrite(&student[i], sizeof(struct Result), 1, f1);
        }
        if (fwrite != 0)
            printf("contents to file written successfully !\n");
        else
            printf("error writing file !\n");
    }
    else
        printf("Unable to open file!\n");

    fclose(f1);
}