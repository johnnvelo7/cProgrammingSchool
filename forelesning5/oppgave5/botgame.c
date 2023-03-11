// botgame.c: Lession 5, exercise 4
//
// gcc -std=c11 botgame.c -lncurses -o botgame
//
// -or- make TARGET=botgame
//
// As this program is using ncurses, it will not compile on Windows
// without installing CygWin and lots of fuzz...
//
// Ncurses may or may not exist on your Linux box. If it is not
// run this command to get it "sudo apt-get install libncurses5-dev"
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curses.h>
#include <stdbool.h>

typedef struct {
  char cArr[3][3];
} BOT;

typedef struct _BOTLIST {
  struct _BOTLIST *psNext;
  BOT sThis;
} BOTLIST;

int addBot();

int main (int iArgC, char *apszArgV[])
{

  srand (time(NULL)); // A simple seed to random numbers
  initscr();          // Init ncurses library.

  printw("Welcome to the crappy bot game. Your life is 100\n\n");

  printw("100\n111\n101"); //Example bot - this is not how you should be printing though

  timeout (5000);  // This is how you do a timed-input. In milliseconds
  int c = getch(); // And just normal input - it gives -1 if the input is timedout

  endwin();        // Close ncurses library.

  printf("Game Summary and timeout character is %d\n", c);

  return 0;
}
