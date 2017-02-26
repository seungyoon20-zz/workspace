01/20/2017
Yixue Wang
PA1

Run gcc -Wall -o PA1 PA1.c in terminal to compile the program and run ./PA1 to run it.

This program is totally my own work.

The ifLeap function considers the year and if given year is leap year then returns 1, else returns 0.

The getStartingDate function considers the year provided and get the day of the week of the first day in that year. I use while-loop to find the starting day year by year.
-> When the target year is larger than 2000, the current year, which is between target year and 2000 loops through and find the starting day wanted year by year. When current year is less than the target year and larger than 2000, it finds the starting day of next year, and current year becomes next year. 
-> When the target year is smaller than 2000, the current year start from 1999 and when current year is less than the target year and larger than 2000, it finds the starting day of next year, and current year becomes previous year. 

The printDateName function prints the title of each day.

The printMonthTitle function print the title of each month and return the number of days in this month with a switch-case statement.

The printMonth function consider the number of days of this month and the starting postion of the first day and print the dates. Finally returns the starting position of next month. 
The currentDay(day of week) is initialized as 0 and loops through the first while-loop. In the 1st while-loop the currentDay must be less than startingDate and prints blanks. Jumping out of the 1st while-loop, the currentDay equals startingDate and enters the 2nd while-loop. The date must be less than numOfDays in the 2nd while-loop and prints the date and update the currentDay.

The printCalendar function considers the target year, stores the startingDate of targetYear, and loops through a for-loop to modify the value of startingDay of next month. The i must be less than 12 and larger or equal to 0 in the loop.

The main function prints the title and store the value of the target year, and calls the printCalendar function. It returns 0 if succeed.