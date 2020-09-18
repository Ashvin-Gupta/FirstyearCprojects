int main()  
{ 
  int hour, minutes; 
  printf("Please enter the hour of the day it is: \n"); 
  scanf("%d",&hour); 
  printf("Please enter the minutes past the hour: \n"); 
  scanf("%d",&minutes); 
  hour = hour%12; 
  if (minutes<=30 && minutes>0){ 
    if (hour == 0){ 
      hour = 12;} 
    printf("The time is %d minutes past %d\n.", minutes,hour);} 
  else if (minutes>30 && minutes<60){ 
    minutes = 60 - minutes; 
    hour = (hour+1)%12; 
    if (hour == 0){ 
      hour = 12;} 
    printf("The time is %d minutes to %d\n.", minutes,hour);} 
  else { 
    printf("Invalid response");} 
} 