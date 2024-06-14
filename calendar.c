#include <stdio.h>

int getDayOfWeek(int day, int month, int year) {
    if (month < 3) {
        month += 12;
        year -= 1;
    }

    int k = year % 100;
    int j = year / 100;

    int f = day + 13 * (month + 1) / 5 + k + k / 4 + j / 4 + 5 * j;
    int dayOfWeek = f % 7;

    dayOfWeek = (dayOfWeek + 5) % 7;

    return dayOfWeek;
}

void printCalendar(int month, int year) {
    const char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    int isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    int days = daysInMonth[month - 1];

    if (isLeapYear && month == 2) {
        days = 29;
    }

    int firstDay = getDayOfWeek(1, month, year);

    printf("\n  %s %d\n", months[month - 1], year);
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    for (int i = 0; i < firstDay; i++) {
        printf("     ");
    }

    for (int day = 1; day <= days; day++) {
        printf("%5d", day);

        if ((day + firstDay) % 7 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

const char* getDayOfWeekString(int dayOfWeek) {
    const char* daysOfWeek[] = {
        "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
    };

    return daysOfWeek[dayOfWeek];
}

int main() {
    int choice;
    printf("Choose an option:\n");
    printf("1. Find the day of the week for a given date\n");
    printf("2. Display the calendar for a given month and year\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        int day, month, year;
        printf("Enter day (1-31): ");
        scanf("%d", &day);
        printf("Enter month (1-12): ");
        scanf("%d", &month);
        printf("Enter year: ");
        scanf("%d", &year);

        if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1) {
            printf("Invalid input.\n");
            return 1;
        }

        int dayOfWeek = getDayOfWeek(day, month, year);
        printf("The day of the week is: %s\n", getDayOfWeekString(dayOfWeek));
    } else if (choice == 2) {
        int month, year;
        printf("Enter month (1-12): ");
        scanf("%d", &month);
        printf("Enter year: ");
        scanf("%d", &year);

        if (month < 1 || month > 12 || year < 1) {
            printf("Invalid input.\n");
            return 1;
        }

        printCalendar(month, year);
    } else {
        printf("Invalid choice.\n");
        return 1;
    }

    return 0;
}
