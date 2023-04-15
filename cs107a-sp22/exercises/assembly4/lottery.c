// Andrew Benson
// A Lottery for CS 107A!
// It's definitely Secure! Nobody can Cheat!

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void setup() {
  // Ignore this, it's necessary to get the assembly I want to exist.
  // Yes, this program is extremely fragile.
  asm(
      "nop;nop;nop;nop;nop;nop;nop;nop;nop;"
      "nop;nop;nop;nop;nop;nop;nop;nop;nop;"
  );
}

void you_won_the_lottery() {
  printf("OMG you won the lottery!!! ðŸ’°ðŸ’°ðŸ’°ðŸ’°\n");
}

void you_did_not_win_the_lottery() {
  printf("Better luck next time ðŸ¤·â€â™‚ï¸\n");
}

bool try_lottery() {
  // By default, you do not win the lottery.
  // You can ignore the `volatile` keyword. It's necessary to get the assembly
  // that I want to exist.
  void (*volatile lottery_result_fn)() = you_did_not_win_the_lottery;
  char guess[6];

  if (scanf("%s", guess) == EOF) {
    printf("\n");
    return false;
  }

  int lottery_number = rand() % 10000;
  if (atoi(guess) == lottery_number) {
    lottery_result_fn = you_won_the_lottery;
  }

  lottery_result_fn();

  return true;
}

int main()
{
  setup();

  // Seed the random number generator.
  srand(time(NULL));

  printf(
      "Welcome to the CS 107A Lottery!\n"
      "The odds are [relatively] good...\n"
      "...but the prize currency is emoji.\n"
      "At least it's free to play!\n"
  );

  printf("Enter a number from 1-10,000: ");
  while (true) {
    if (!try_lottery()) {
      break;
    }
    printf("Play again? Enter a number from 1-10,000: ");
  }

  printf("Thank you for playing the CS 107A Lottery!\n");
  return 0;
}
