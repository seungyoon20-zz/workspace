#include <stdio.h>
#include <math.h>

//int ifLeap;

int ifLeap(int NOY){
  if(NOY%400 == 0){
    return 1;
  }
  if(NOY%100 == 0){
    return 0;
  }
  if(NOY%4 == 0){
    return 1;
  }
  return 0;
}


int getStartingDate(int targetYear){
 
  int startingDate = 6;
  int currentYear = 2000;
  if(targetYear > currentYear){
    while(currentYear < targetYear){
      if(ifLeap(currentYear)){
	startingDate = startingDate + 366 % 7;
      }
      else{
	startingDate = startingDate + 365 % 7;
      }
      currentYear++;
    }
    startingDate %= 7;
  }
  else if(targetYear < currentYear){
    currentYear--;
    while(currentYear >= targetYear){
      if(ifLeap(currentYear)){
	startingDate = startingDate - (366 % 7);
      }
      else{
	startingDate = startingDate - (365 % 7);
      }
      currentYear--;
    }
    startingDate %= 7;
    if(startingDate < 0){
      startingDate += 7;
    }
  }
  return startingDate;
}

void printDateName(void){
  printf("SUN MON TUE WED THR FRI SAT\n");
}

void printMonthTitle(int targetYear, int whichMonth){
  switch(whichMonth){
  case 0:
    printf("January %d\n", targetYear);
    printDateName();
    break;
  case 1:
    printf("Febuary %d\n", targetYear);
    printDateName();
    break;
  case 2:
    printf("March %d\n", targetYear);
    printDateName();
    break;
  case 3:
    printf("April %d\n", targetYear);
    printDateName();
    break;
  case 4:
    printf("May %d\n", targetYear);
    printDateName();
    break;
  case 5:
    printf("June %d\n", targetYear);
    printDateName();
    break;
  case 6:
    printf("July %d\n", targetYear);
    printDateName();
    break;
  case 7:
    printf("August %d\n", targetYear);
    printDateName();
    break;
  case 8:
    printf("September %d\n", targetYear);
    printDateName();
    break;
  case 9:
    printf("October %d\n", targetYear);
    printDateName();
    break;
  case 10:
    printf("November %d\n", targetYear);
    printDateName();
    break;
  case 11:
    printf("December %d\n", targetYear);
    printDateName();
    break;
  }
   
}

int printMonth(int targetYear, int startingDate, int whichMonth){
  int numOfDays;
  int date = 1;
  int currentDay = 0;
  switch(whichMonth){
  case 0:
    numOfDays = 31;
    break;
  case 1:
    if(ifLeap(targetYear)){
      numOfDays = 29;
      break;
    }
    else{
      numOfDays = 28;
      break;
    }
  case 2:
    numOfDays = 31;
    break;
  case 3:
    numOfDays = 30;
    break;
  case 4:
    numOfDays = 31;
    break;
  case 5:
    numOfDays = 30;
    break;
  case 6:
    numOfDays = 31;
    break;
  case 7:
    numOfDays = 31;
    break;
  case 8:
    numOfDays = 30;
    break;
  case 9:
    numOfDays = 31;
    break;
  case 10:
    numOfDays = 30;
    break;
  case 11:
    numOfDays = 31;
    break;
  }
  
  while(currentDay < startingDate){
      printf("    ");
      currentDay = (currentDay + 1) % 7;
    }
  while(date <= numOfDays){
      printf("%4d", date);
      if(currentDay == 6){
	printf("\n");
      }
      currentDay = (currentDay + 1) % 7;
      date++;
     
  }
  
  printf("\n\n");
  return currentDay;
}

void printCalendar(int targetYear){
  printf("\t*** CARLENDAR for %d ***\n", targetYear);
  int startingDate = getStartingDate(targetYear);
  for(int i = 0; i < 12; i++){
    printMonthTitle(targetYear, i);
    startingDate = printMonth(targetYear, startingDate, i);
  }
}



int main(void){
  int numOfYear;
  printf("\t\tMONTH CALENDAR\nPlease enter your year for this carlender: -");
  scanf("%d", &numOfYear);
  printCalendar(numOfYear);

}
