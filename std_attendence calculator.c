#include <stdio.h>
#include"color.h"

#define MAX_WEEKS 50
#define MAX_STUDENTS 50

struct student
{
    char name[50];
    int id;
    int attendance[MAX_WEEKS];
};

int num_weeks = 0;
int num_students = 0;

void add_student(struct student *s)
{
    printf("Enter name of student: ");
    scanf("%s", s[num_students].name);
    printf("Enter ID of student: ");
    scanf("%d", &s[num_students].id);
    int j;
    for (j = 0; j < num_weeks; j++)
    {
        s[num_students].attendance[j] = -1;
    }
    num_students++;
}

void mark_attendance(struct student *s)
{
    int week;
    printf("Enter the week number: ");
    scanf("%d", &week);
    if (week < 1 || week > num_weeks)
    {
        printf("Invalid week number!\n");
        return;
    }
    int i;
    for ( i = 0; i < num_students; i++)
    {
        printf("Is %s present for week %d? (1 for present, 0 for absent): ", s[i].name, week);
        scanf("%d", &s[i].attendance[week - 1]);
    }
}

float attendance_percentage(struct student s)
{
    int total_classes = num_weeks;
    int present_classes = 0;
    int i;
	for ( i = 0; i < num_weeks; i++)
    {
        if (s.attendance[i] == 1)
        {
            present_classes++;
        }
    }
    return (present_classes * 100.0) / total_classes;
}

void print_attendance_record(struct student *s)
{
    printf("Attendance record:\n");
    printf("Name\tID\t");
    int i;
	for ( i = 1; i <= num_weeks; i++)
    {
        printf("Week %d\t", i);
    }
    printf("Percentage\n");
	for (i = 0; i < num_students; i++)
    {
        printf("%s\t%d\t", s[i].name, s[i].id);
        int j;
		for ( j = 0; j < num_weeks; j++)
        {
            if (s[i].attendance[j] == 1)
            {
                printf("P\t");
            }
            else if (s[i].attendance[j] == 0)
            {
                printf("A\t");
            }
            else
            {
                printf("-\t");
            }
        }
        printf("%.2f\n", attendance_percentage(s[i]));
    }
}

int main()
{
    int choice;
    struct student s[MAX_STUDENTS];
    red();
    printf("Enter number of weeks: ");
    scanf("%d", &num_weeks);
    while (1)
    {
    	green();
        printf("\nMenu:\n");
        printf("1. Add student\n");
        printf("2. Mark attendance\n");
        printf("3. Print attendance record\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (num_students < MAX_STUDENTS)
            {
                add_student(s);
            }
            else
            {
                printf("Maximum number of students reached!\n");
            }
            break;
        case 2:
            mark_attendance(s);
            break;
        case 3:
            print_attendance_record(s);
            break;
        case 4:
            printf("Exiting program...\n");
            return 0;
        default:
            printf("Invalid choice!\n");
            break;
        }
    }
}
