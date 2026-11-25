#include <stdio.h>

int main() {
    int y, m, d, day;
    char *months[] = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun",
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    printf("Enter year: ");
    scanf("%d", &y);

    if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
        days[1] = 29;
    }

    int y0 = y - 1;
    day = (y0 + y0 / 4 - y0 / 100 + y0 / 400 + 1) % 7;

    for (m = 0; m < 12; m++) {
        printf("\n\n        --- %s %d ---\n", months[m], y);
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        for (d = 0; d < day; d++) {
            printf("     ");
        }

        for (d = 1; d <= days[m]; d++) {
            printf("%5d", d);
            if (++day > 6) {
                day = 0;
                printf("\n");
            }
        }
    }

    return 0;
}
