// botgame2.c: Lession 5, exercise 4
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
// (I'm not extremely proud of this code - but it works, somehow...)
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curses.h>
#include <stdbool.h>

typedef struct {
  char cArr[3][3];  // The 3x3 pixels filled by random with '0' and '1'
  int  iOnes;       // A counter for number of 1's
} BOT;

typedef struct _BOTLIST {
  struct _BOTLIST *psNext;
  BOT sThis;
} BOTLIST;

BOTLIST *MakeBot(void);
BOTLIST *MakeRoom (void);
void DestroyRoom (BOTLIST *psList);
bool PlayRoom (BOTLIST *pbRoom, int *piLife, int *piTimeOut, int iRooms);

int main (int iArgC, char *apszArgV[])
{
  int iLife = 100;        // Initial life 
  int iTimeOut = 10;      // Initial timeout
  int iRoomsCleared = 0;  // Number of rooms cleared.
  BOTLIST *psRoom = NULL; // List of bots in the room
  bool bFinished = FALSE;
  
  srand (time(NULL)); // A simple seed to random numbers
  initscr();          // Init ncurses library

  printw("Welcome to the crappy bot game. Your life is 100\n\n");
  
  while (iLife > 0) {
    psRoom = MakeRoom ();        // Make a room of 2 - 8 bots as linked list.
    if (PlayRoom (psRoom, &iLife, &iTimeOut, iRoomsCleared)) { 
      ++iRoomsCleared;
    }  
    DestroyRoom (psRoom);
  } 

  endwin();        // Close ncurses library.
  return 0;
}

// Make a botlist element consisting of a bot ++ initialize the bitpattern etc.
//
BOTLIST *MakeBot(void)
{
  BOTLIST *psBot = malloc (sizeof(BOTLIST));
  if (psBot != NULL) {
    psBot->psNext = NULL;
    // Initialize bot:
    psBot->sThis.iOnes = 0;
    for (int y = 0; y < 3; y++) {
      for (int x = 0; x < 3; x++) {
        char c = (rand() % 2) + '0';  
        psBot->sThis.cArr[x][y] = c;
        if (c == '1') psBot->sThis.iOnes++;
      }
    }  
  }
  return psBot;
}

// Destroy the list of bots

void DestroyRoom (BOTLIST *psList)
{
  BOTLIST *psThis = NULL;
  while (psList) {
    psThis = psList;
    psList = psThis->psNext;
    free (psThis);
  }
}        

// Make a "room"

BOTLIST *MakeRoom (void)
{
  BOTLIST *psList = NULL;
  BOTLIST *psThis = NULL;
  int iNoOfBots = rand() % 8; // Rand returns a number 0..RAND_MAX, typically 32767
  
  for (int i = 0; i < iNoOfBots; i++) {
    psThis = MakeBot();       // Make and initialize one bot.
    if (psThis == NULL) {     // Oops - destroy what's made so far
      DestroyRoom (psList);
      return NULL;  
    }
    // Insert in front of list.
    if (psList != NULL) {
      psThis->psNext = psList;
    }    
    psList = psThis;
  }
  return psList;
}   

void PrintBot (BOT *psBot)
{
  printw("\n");
  for (int y = 0; y < 3; y++) {
    for (int x = 0; x < 3; x++) {
      printw("%c ", psBot->cArr[x][y]);
    }
    printw("\n");
  } 
  printw("\nNumber %d\n", psBot->iOnes);
}
      
bool PlayRoom (BOTLIST *psRoom, int *piLife, int *piTimeOut, int iRooms)
{
  BOTLIST *psThis = psRoom;
  
  while (psThis) {
    clear();
    printw("Your life is %d.\n\n", *piLife);
    PrintBot (&psThis->sThis);
    printw("Number of ones? (0...9)");
    timeout (*piTimeOut*1000); // Wait ...
    int c = getch();           // Get character ...
    
    if (c == -1) {
      *piLife -= 10;
       printw(" Timeout.\n");
       break;
    }
    else if ((c - '0') != psThis->sThis.iOnes) {
      *piLife -= 5;
       printw(" Wrong.\n");
       break;     
    }
    else {
       printw(" Hey, you killed me!\n"); 
    }
    timeout(2000); getch();
    psThis = psThis->psNext;
  }
  if (psThis == NULL) {
    *piTimeOut -= 1;  
    printw("\n\n%d rooms cleared!", iRooms);
    timeout(2000); getch();    
    return TRUE;
  }
  return FALSE;  
}  
  

