#include <iostream>
#include <stdio.h>
#include <cassert>
#include <string>

struct datetime {
    enum month { JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER };

    int month, day, year, hour, minute;
};

int getDaysInMonth(int);
int getDatetimeMinutesDifference(datetime, datetime); 
int datetimeToMinutes(datetime);
int monthToDays(int);

int main() {
    int month, day, year, hour, minute, difference;
    std::string beforeAfter;
    datetime dt1, dt2;
    do {
        std::cout << "Please input two datetimes (MM/DD/YYYY hh:mm) to compare:" << std::endl;
        scanf("%d/%d/%d %d:%d", &month, &day, &year, &hour, &minute);
        dt1 = {month, day, year, hour, minute};
        std::cout << "What is the second datetime (MM/DD/YYYY hh:mm)?" << std::endl;
        scanf("%d/%d/%d %d:%d", &month, &day, &year, &hour, &minute);
        dt2 = {month, day, year, hour, minute};
        
        difference = getDatetimeMinutesDifference(dt1, dt2);

        if (difference < 0) {
            difference *= -1;
            beforeAfter = "before";
        } else if (difference > 0) {
            beforeAfter = "after";
        } else {
            std::cout << "The two datetimes occured at/are the same time!" << std::endl;
            continue;
        }

        std::cout << "The first datetime happened " << difference << " minutes " << beforeAfter << " the second datetime." << std::endl;
    } while (!feof(stdin));

    return(0);
}

int getDatetimeMinutesDifference(datetime dt1, datetime dt2) {
    // Returns the difference between the two datetimes, in minutes
    return datetimeToMinutes(dt1)-datetimeToMinutes(dt2);
}

int datetimeToMinutes(datetime dt) {
    int minutes = dt.minute;
    int hoursToMinutes = 60*dt.hour;
    int dayToMinutes = 60*24*(dt.day-1); // days do not start at 0
    int monthToMinutes = 60*24*monthToDays(dt.month);
    int yearToMinutes = 60*24*365*dt.year;

    return minutes+hoursToMinutes+dayToMinutes+monthToMinutes+yearToMinutes;
}

int monthToDays(int month) {
    assert(month >= 0);

    int days = 0;

    while (--month >= 0) { // The starting month is not complete
        days += getDaysInMonth(month);
    }

    return days;
}

int getDaysInMonth(int m) {
    switch (m) {
        case datetime::JANUARY:
            return 31;
        case datetime::FEBRUARY:
            // pretending leap-years don't exist
            return 28;
        case datetime::MARCH:
            return 31;
        case datetime::APRIL:
            return 30;
        case datetime::MAY:
            return 31;
        case datetime::JUNE:
            return 30;
        case datetime::JULY:
            return 31;
        case datetime::AUGUST:
            return 31;
        case datetime::SEPTEMBER:
            return 30;
        case datetime::OCTOBER:
            return 31;
        case datetime::NOVEMBER:
            return 30;
        case datetime::DECEMBER:
            return 31;
        default:
            assert(false);
    }
}