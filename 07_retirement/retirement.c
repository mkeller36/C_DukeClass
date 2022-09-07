#include <stdlib.h>
#include <stdio.h>

typedef struct _retire_info {
  int months;
  double contribution;
  double rate_of_return;
} ret;

typedef struct _retire_info retire_info;

typedef struct init_tag {
  int age;
  double balance;
} init_cond;

init_cond calc(retire_info r, init_cond init){
  int i;
  
  for(i=init.age;i<r.months+init.age;i++){
    printf("Age %3d month %2d you have $%.2f\n",(i/12),i%12,init.balance);
    init.balance = init.balance*(1+r.rate_of_return)+r.contribution;
  }
  return init;
}

void retirement(int startAge, double initial, retire_info working, retire_info retired){
  init_cond x1;
  init_cond x2;
  x1.age = startAge;
  x1.balance = initial;
  x2 = calc(working, x1);
  x2.age = startAge + working.months;
  calc(retired, x2);
}
  
int main(void){
  retire_info working;
  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 0.045/12;
  retire_info retired;
  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 0.01/12;
  
  retirement(327, 21345, working, retired);
  return EXIT_SUCCESS;
}
