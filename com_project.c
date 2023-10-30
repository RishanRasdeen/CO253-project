#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int count =0 ;

typedef struct stu{

        int batch;
        int regNo;
        char firstName[20];
        char lastName[20];
        float cGPA;
    }student;

   student s[10];
  
    void insertStud();
    void printStud();
    void listStud();
    void deleteStud();

int main()
{
    int option;


    printf("--------------------------------------------\nA VOLATILE STUDENT RECORD MAINTENANCE SYSTEM\n--------------------------------------------\n");

    printf("0. Quit\n1. Insert a Student Record\n2. Print a Student Record\n3. Print all Student Records\n4. Delete a Student Record");

    while(1)
    {
        printf("\n------------------\nENTER OPTION [0-4]\n------------------");
        scanf("%d",&option);

        switch (option)
        {
        case 0:
            exit(0);

        case 1:
            printf("\n");
            insertStud();
            break;
        case 2:
            printf("\n");
            printStud();
            break;
        case 3:
            printf("\n");
            listStud();
            break;
        case 4:
            printf("\n");
            deleteStud();
            break;
        default:
            
            break;
        }
    }

    return 0;
}


void insertStud()
{
    printf("Enter the batch (14/15/16/17): ");
    scanf("%d",&s[count].batch);

    printf("Enter the registration number: ");
    scanf("%d",&s[count].regNo);

    printf("Enter the first name         : ");
    scanf("%s",s[count].firstName);

    printf("Enter the last name          : ");
    scanf("%s",s[count].lastName);

    printf("Enter the cumulative GPA     : ");
    scanf("%f",&s[count].cGPA);

    ++count;
}
void printStud()
{
    
    float k;
    int b,c;
    int i = 0,p=0,j=0;
    char a[10];
    printf("Enter the Registration Number: ");
    scanf("%s",a);
    char *token;
    token = strtok(a,"/");
    char *array[3];

    while(token != NULL)
    {
        array[i] = token;
        token = strtok(NULL,"/");
        ++i;
    }

    b = atoi(array[1]);
    c = atoi(array[2]);


    for (j = 0; j <= count; j++)
    {
        if (b == s[j].batch && c == s[j].regNo)
        {
            k = s[j].cGPA;
            p=1;

            break;
        }

    }

    if (p==1)
    {
        printf("The student %s %s (E/%d/%d) has a cumulative GPA of %.2f\n",s[j].firstName,s[j].lastName,s[j].batch,s[j].regNo,k);
    }
    else
    {
        printf("No student with the given Registration Number!\n");
    }
}



void listStud()
{
    for (int  j = 0; j <= count; j++)
    {
        if(s[j].batch == 0)
    {
       continue;

    }
    else
    {
        printf("The student %s %s (E/%d/%d) has a cumulative GPA of %.2f\n",s[j].firstName,s[j].lastName,s[j].batch,s[j].regNo,s[j].cGPA);
    }

    }
}


void deleteStud()
{
    int i = 0,b,c,p=0;
    char a[10];
    printf("Enter the Registration Number: ");
    scanf("%s",a);
    char *token;
    token = strtok(a,"/");
    char *array[3];

    while(token != NULL)
    {
        array[i] = token;
        token = strtok(NULL,"/");
        ++i;
    }

    b = atoi(array[1]);
    c = atoi(array[2]);

    for (int j = 0; j <= count; j++)
    {
        if (b == s[j].batch && c == s[j].regNo)
        {
            s[j].batch = 0;
            p=1;
            --count;
            break;
        }

    }

    if (p==1)
    {
        printf("Delete Successful!\n");
    }
    else
    {
        printf("No student with the given Registration Number!\n");
    }



}