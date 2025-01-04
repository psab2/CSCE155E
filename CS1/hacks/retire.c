/**
 * Author: Prisha
 * 2024/09/19
 * A program to compute the monthly savings table detailing the
 * (inflation-adjusted) interest earned each month, contribution, and new balance.
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {

  if(argc!=6) {
    printf("ERROR: incorrect number of command line arguments\n");
    exit(1);
  }

  double initialStartingBalance = atof(argv[1]);
  double monthlyContribution = atof(argv[2]);
  double rateReturn = atof(argv[3]);
  double rateInflation = atof(argv[4]);
  int numYrsRetire = atoi(argv[5]);

  if ((rateReturn > 1 || rateReturn < 0) || (rateInflation > 1 || rateInflation < 0)) {
    printf("Error: on the scale [0,1]\n");
    exit(1);
  }
  if (monthlyContribution > (18500.0/12.0)) {
      printf("Error: maximum annual contribution limit of $18,500\n");
      exit(1);
  }
  double interest=0.0;
  double totalInterest=0.0;
  double balance = initialStartingBalance;

  int months = numYrsRetire*12;
  printf("Month     Interest     Balance\n");
  for(int i=1; i<=months; i++) {
    double inflationAdjustedAnnualRate = (((1.0+rateReturn)/(1.0+rateInflation))-1.0);
    interest = round(((inflationAdjustedAnnualRate/12)*balance)*100.0)/100.0;
    balance += monthlyContribution + interest;
    printf("%5d $       %5.2f $      %5.2f \n", i, interest, balance);
    totalInterest += interest;
  }
  printf("Total Interest Earned: $ %.2f\n", totalInterest);
  printf("Total Nest Egg: $ %.2f\n", balance);
}
