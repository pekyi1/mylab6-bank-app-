#include <stdio.h>

 float authenticate(int pin);
 float requestAmount(float amount);
 float deposit(float amount);
 float withdraw(float amount);
 float transfer(float amount);
 float amount;
 float balance=10000;


  float authenticate(int pin){
  if(pin==2000){
    return 1;
  }
  return 0;
  }

  float requestAmount(float amount){
   printf("Enter the amount: ");
  scanf("%f",&amount);
  return amount;
  }

  float deposit(float amount){
  balance+=amount;
  printf("Your balance is: %f\n",balance);
  return amount;
  }

  float withDraw(float amount){
  if(balance>=amount){
    balance-=amount;
    printf("Your remaining balance is: %f\n",balance);
  }
  else{
    printf("Abeg go search money\n");
  }
  }

   float transfer(float amount){
   int rec_num;
   printf("Enter recepient number: \n");
   scanf("%d", &rec_num);
   if(amount<=balance){
    balance-=amount;
    printf("You have sent %f to %d\n",amount,rec_num);
   }
   else{
    printf("Talk am say your money no go reach");
   }
   }



int main(){
 start:
 printf("WELCOME TO ABC BANK\nEnter your four digit pin\n");
 int tries = 0;
 int pin=0;
 scanf("%d", &pin);
 menu:
 if(authenticate(pin) && tries < 4){
 int menu_item;
 printf("Select an option\n1. Check Balance\n2. Withdrawal\n3.Deposit\n4. Transfer\n");
 scanf("%d", &menu_item);
 switch(menu_item){
 case 1: printf("%g\n", balance);
 break;
 case 2: withDraw(requestAmount(amount));
 break;
 case 3: deposit(requestAmount(amount));
 break;
 case 4: transfer(requestAmount(amount));
 }
 }
 else{
 ++tries;
 printf("Invalid pin after %d tries\n", tries);
 goto start;
 }
 int response;
 printf("Would you like to perform another transaction?\n1. Yes\n2.No\n");
 scanf("%d", &response);
 if(response == 1){goto menu;}

printf("Thank you for banking with us\n");
return 0; }
