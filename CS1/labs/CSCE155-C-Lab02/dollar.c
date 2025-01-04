/**
 * Author: Prishs
 *
 * 2024/09/15
 *
 * This program converts US dollars
 * 10% of the total amount of US Dollars will be taken as an exchange fee.
 * For the rest of the US Dollars, half will be changed to British Pounds and the other half to JPY
 * 1 US Dollar = 0.79 British Pound; 1 US Dollar = 127.65 JPY
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {

  double amount;
  printf("Please input the total amount of US Dollars: ");
  scanf("%lf", &amount);

  double fee;
  fee = .10 * amount;

  double remaining;
  remaining = amount - fee;

  double GBP;
  GBP = (remaining/2)*.79;

  double JPY;
  JPY = (remaining/2)*127.65;

  printf("Fee: %.2f\n", fee);
  printf("Amount in GBP: %.2f\n", GBP);
  printf("Amount in JPY: %.2f\n", JPY);
}
