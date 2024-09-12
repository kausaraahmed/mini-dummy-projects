#include <stdio.h>
#include <string.h>

// Introduction text and precautions
void intro();

// swapping function
void swapSlNum(int *xp, int *yp);

// swapping course names
void swapName(char *str1, char *str2);

struct routine
{
    int slNum;
    char name[10];
};

int main(void)
{
    intro();
    // struct routine sem[6] = {{11, "CSE1301"}, {21, "CSE1302"}, {12, "EEE1101"}, {22, "MAT1301"}, {41, "EEE1102"}, {42, "UCC1201"}};

    // Taking initial data input
    int theoryCourse, labCourse, time, day;
    char semName[14];
    printf("Semester name: ");
    scanf("%s", &semName);
    printf("Number of Theory Course(s): ");
    scanf("%d", &theoryCourse);
    printf("Number of Lab Course(s): ");
    scanf("%d", &labCourse);
    int totalCourse = theoryCourse + labCourse;

    // declaring
    struct routine sem[totalCourse];
    int i = 0, j = 0;
    printf("\n");

    // theory course input
    for (i = 0; i < theoryCourse; i++)
    {
        printf("----------------------------\n");
        printf("Theory Course %d:\n", i + 1);
        printf("Name of the course: ");
        scanf("%s", &sem[i].name);
        printf("1. Sun - Tue\t2. Mon - Wed\n-> ");
        scanf("%d", &day);
        printf("\nClass time: \n1. 08:30 - 09:50\n2. 10:00 - 11:20\n3. 11:30 - 12:50\n4. 01:10 - 02:30\n5. 02:40 - 04:00\n6. 04:10 - 05:30\n-> ");
        scanf("%d", &time);
        sem[i].slNum = --time * 10 + day;
        printf("----------------------------\n\n");
    }

    // lab course input
    for (i = theoryCourse; i < totalCourse; i++)
    {
        printf("----------------------------\n");
        printf("Lab Course %d:\n", j + 1);
        printf("Name of the course: ");
        scanf("%s", &sem[i].name);
        printf("1. Sun\t2. Mon\n3. Tue\t4. Wed\n-> ");
        scanf("%d", &day);
        printf("\nClass time: \n1. 08:30 - 11:20\n2. 10:00 - 12:50\n3. 11:30 - 02:30\n4. 01:10 - 04:00\n5. 02:40 - 05:30\n-> ");
        scanf("%d", &time);
        sem[i].slNum = --time * 10 + day;
        j++;
        printf("----------------------------\n\n");
    }

    // sorting courses according to their serial number (SlNum)
    for (i = 0; i < totalCourse; i++)
    {
        for (j = 0; j < totalCourse - i - 1; j++)
        {
            if (sem[j].slNum > sem[j + 1].slNum)
            {
                swapSlNum(&sem[j].slNum, &sem[j + 1].slNum);
                swapName(sem[j].name, sem[j + 1].name);
            }
        }
    }

    // routine header row
    const char *daysOfTheWeek[] = {"Sat", "Sun", "Mon", "Tue", "Wed", "Thu   |"};
    printf("\n     \t\t\t\t%s Routine", semName);
    printf("\n=============================================================================\n");
    printf("| ^Time - Day > ");
    for (i = 0; i < 6; i++)
        printf("|   %s   ", daysOfTheWeek[i]);

    // line separator
    printf("\n");
    printf("-----------------------------------------------------------------------------");
    printf("\n");

    // class time array
    const char *classTime[] = {"08:30 - 09:50", "10:00 - 11:20", "11:30 - 12:50", "01:10 - 02:30", "02:40 - 04:00", "04:10 - 05:30"};

    // main logic
    int k = 0, l = 0, m = 0; // necessary variables
    for (i = 0; i < 6; i++)
    {
        printf("| %s\t", classTime[i]); // print time for each line

        for (j = 0; j < 6; j++)
        {
            if ((i * 10) + j == sem[k].slNum)
            {
                printf("| %s ", sem[k].name); // first class day

                if (sem[k].name[6] != '2')
                    sem[k].slNum += 2; // for next class day

                else
                    sem[k].slNum += 10; // 2 cells for lab classes in same column

                if (j % 2 == 0)
                    m = k; // storing to another variable for next class
                else
                    l = k; // storing to another variable for next class

                k++; // move to next course
            }

            // second class for odd cells
            else if ((i * 10) + j == sem[l].slNum)
                printf("| %s ", sem[l].name);

            // second class for even cells
            else if ((i * 10) + j == sem[m].slNum)
                printf("| %s ", sem[m].name);

            // empty cells
            else if (j != 5)
                printf("|         ");

            // printing extra '|' at the end of a line
            else
                printf("|         |");
        }

        // line separator
        printf("\n");
        printf("-----------------------------------------------------------------------------");
        printf("\n");
    }

    printf("\n\n");
}

// Introduction text and precautions.
void intro()
{
    printf("\n\n");
    printf("\t\t\t---------------------------------\n");
    printf("\t\t\t| Course-wise Routine Generator |\n");
    printf("\t\t\t---------------------------------\n");
    printf("\nThis program will generate routine accordingly from your data. After entering all the data you will get a routine. You can take a screenshot of that and use it. It has much cleaner and easy Interface than urms schedule.\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("[Precautions!!]\n");
    printf("\n1. This code is not able to handle exception. So, Enter data properly to get desired output. (but, I am working on it.)\n");
    printf("\n2. Course name format: XXX#### (e.g.- CSE1101). [(CSE 1101) is incorrect, it will cause error.]\n");
    printf("\n3. Get your output terminal a bit long space to get output correctly.\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("\n");
}

// swapping function
void swapSlNum(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// swapping course names
void swapName(char *str1, char *str2)
{
    char temp[10];
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}