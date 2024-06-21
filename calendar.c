#include <stdio.h>

int main() {
    int day, month, year, dayOfWeek;
    
    printf("Enter the day: ");
    scanf("%d", &day);
    
    printf("Enter the month: ");
    scanf("%d", &month);
    
    printf("Enter the year: ");
    scanf("%d", &year);
    
    if (month < 3) {
        month += 12;
        year--;
    }
    
    dayOfWeek = (day + 13*(month+1)/5 + year + year/4 - year/100 + year/400) % 7;
    
    switch(dayOfWeek) {
        case 0:
            printf("The day of the week is Saturday.\n");
            break;
        case 1:
            printf("The day of the week is Sunday.\n");
            break;
        case 2:
            printf("The day of the week is Monday.\n");
            break;
        case 3:
            printf("The day of the week is Tuesday.\n");
            break;
        case 4:
            printf("The day of the week is Wednesday.\n");
            break;
        case 5:
            printf("The day of the week is Thursday.\n");
            break;
        case 6:
            printf("The day of the week is Friday.\n");
            break;
        default:
            printf("Invalid day.\n");
    }
    
    return 0;
}
