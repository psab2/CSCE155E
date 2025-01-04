/**
 * Author: Prisha
 * 2024/09/16
 * Write an application for the company to help customers track their
 * mobile data usage.
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {

  if(argc!=4) {
    printf("ERROR: incorrect number of command line arguments\n");
    exit(1);
  }

  double TotalGBAllocation = atof(argv[1]);
  int CurrentDay = atoi(argv[2]);
  double TotalGBUsed = atof(argv[3]);

  if(CurrentDay<0 || CurrentDay>30) {
    printf("ERROR one or more of your inputs is invalid\n");
    exit(1);
  }

  int RemainingDays;
  RemainingDays = 30 - CurrentDay;
  printf("%d days used today, %d days remaining\n", CurrentDay, RemainingDays);

  double AvgDailyUse;
  AvgDailyUse = TotalGBUsed/CurrentDay;
  printf("Average daily use: %.2f GB/day\n", AvgDailyUse);

  double ActualAvgUse;
  ActualAvgUse = TotalGBAllocation/30;
/*/
  if (AvgDailyUse > ActualAvgUse) {
      printf("You are EXCEEDING your average daily use (%.2f GB/day)\n", ActualAvgUse);
      double ExceedingPlan;
      ExceedingPlan = (AvgDailyUse * 30)-TotalGBAllocation;
      printf("Continuing this high usage, you'll exceed your data plan by %.2f GB\n", ExceedingPlan);

      double ToStayBelow;
      ToStayBelow = (TotalGBAllocation-TotalGBUsed)/RemainingDays;
      printf("To stay below your data plan, use no more than %.2f GB/day\n", ToStayBelow);
  }
  else if (AvgDailyUse < ActualAvgUse) {
      printf("You are at or below your average daily use (%.2f GB/day)\n", ActualAvgUse);
      double UseUpTo;
      UseUpTo = (TotalGBAllocation-TotalGBUsed)/RemainingDays;
      printf("You can use up to %.2f GB/day and stay below your data plan limit\n", UseUpTo);
  }
  else {
      printf("You have already met your limit for this month. Looks like you're getting some overage charges...\n");
  }
}
/*/

  if (TotalGBUsed >= TotalGBAllocation) {
      printf("You have already met your limit for this month. Looks like you're getting some overage charges...\n");

  }
  else if (AvgDailyUse > ActualAvgUse){
      printf("You are EXCEEDING your average daily use (%.2f GB/day)\n", ActualAvgUse);
      double ExceedingPlan;
      ExceedingPlan = (AvgDailyUse * 30)-TotalGBAllocation;
      printf("Continuing this high usage, you'll exceed your data plan by %.2f GB\n", ExceedingPlan);

      double ToStayBelow;
      ToStayBelow = (TotalGBAllocation-TotalGBUsed)/RemainingDays;
      printf("To stay below your data plan, use no more than %.2f GB/day\n", ToStayBelow);
  }
  else if (AvgDailyUse < ActualAvgUse) {
      printf("You are at or below your average daily use (%.2f GB/day)\n", ActualAvgUse);
      double UseUpTo;
      UseUpTo = (TotalGBAllocation-TotalGBUsed)/RemainingDays;
      printf("You can use up to %.2f GB/day and stay below your data plan limit\n", UseUpTo);

  }

}
