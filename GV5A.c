#include <stdio.h>
#include <stdlib.h>		// for srand
#include <string.h>
#include <stdbool.h>
#include <time.h>


//--------------------------------------------------------------------------------

void displayCave()
{
    printf( "\n"
      "       ______18______             \n"
        "      /      |       \\           \n"
        "     /      _9__      \\          \n"
        "    /      /    \\      \\        \n"
        "   /      /      \\      \\       \n"
        "  17     8        10     19       \n"
        "  | \\   / \\      /  \\   / |    \n"
        "  |  \\ /   \\    /    \\ /  |    \n"
        "  |   7     1---2     11  |       \n"
        "  |   |    /     \\    |   |      \n"
        "  |   6----5     3---12   |       \n"
        "  |   |     \\   /     |   |      \n"
        "  |   \\       4      /    |      \n"
        "  |    \\      |     /     |      \n"
        "  \\     15---14---13     /       \n"
        "   \\   /            \\   /       \n"
        "    \\ /              \\ /        \n"
        "    16---------------20           \n"
        "\n");
}


//--------------------------------------------------------------------------------
void displayInstructions()
{
    printf( "Hunt the Wumpus:                                             \n"
        "The Wumpus lives in a completely dark cave of 20 rooms. Each \n"
        "room has 3 tunnels leading to other rooms.                   \n"
        "                                                             \n"
        "Hazards:                                                     \n"
          "1. Two rooms have bottomless pits in them.  If you go there you fall and die.   \n"
          "2. Two other rooms have super-bats.  If you go there, the bats grab you and     \n"
          "   fly you to some random room, which could be troublesome.  Then those bats go \n"
          "   to a new room different from where they came from and from the other bats.   \n"
        "3. The Wumpus is not bothered by the pits or bats, as he has sucker feet and    \n"
          "   is too heavy for bats to lift.  Usually he is asleep.  Two things wake       \n"
          "    him up: Anytime you shoot an arrow, or you entering his room.  The Wumpus   \n"
          "    will move into the lowest-numbered adjacent room anytime you shoot an arrow.\n"
          "    When you move into the Wumpus' room, then he wakes and moves if he is in an \n"
          "    odd-numbered room, but stays still otherwise.  After that, if he is in your \n"
          "    room, he snaps your neck and you die!                                       \n"
          "                                                                                \n"
          "Moves:                                                                          \n"
          "On each move you can do the following, where input can be upper or lower-case:  \n"
          "1. Move into an adjacent room.  To move enter 'M' followed by a space and       \n"
          "   then a room number.                                                          \n"
          "2. Shoot your guided arrow through a list of up to three adjacent rooms, which  \n"
          "   you specify.  Your arrow ends up in the final room.                          \n"
          "   To shoot enter 'S' followed by the number of rooms (1..3), and then the      \n"
          "   list of the desired number (up to 3) of adjacent room numbers, separated     \n"
          "   by spaces. If an arrow can't go a direction because there is no connecting   \n"
          "   tunnel, it ricochets and moves to the lowest-numbered adjacent room and      \n"
          "   continues doing this until it has traveled the designated number of rooms.   \n"
          "   If the arrow hits the Wumpus, you win! If the arrow hits you, you lose. You  \n"
          "   automatically pick up the arrow if you go through a room with the arrow in   \n"
          "   it.                                                                          \n"
          "3. Enter 'R' to reset the person and hazard locations, useful for testing.      \n"
          "4. Enter 'C' to cheat and display current board positions.                      \n"
          "5. Enter 'D' to display this set of instructions.                               \n"
          "6. Enter 'P' to print the maze room layout.                                     \n"
          "7. Enter 'X' to exit the game.                                                  \n"
          "                                                                                \n"
          "Good luck!                                                                      \n"
          " \n");
}

void setRooms(int **pArray){
  pArray[0][0] = 2;
  pArray[0][1] = 5;
  pArray[0][2] = 8;
  pArray[1][0] = 1;
  pArray[1][1] = 3;
  pArray[1][2] = 10;
  pArray[2][0] = 2;
  pArray[2][1] = 4;
  pArray[2][2] = 12;
  pArray[3][0] = 3;
  pArray[3][1] = 5;
  pArray[3][2] = 14;
  pArray[4][0] = 1;
  pArray[4][1] = 4;
  pArray[4][2] = 6;
  pArray[5][0] = 5;
  pArray[5][1] = 7;
  pArray[5][2] = 15;
  pArray[6][0] = 6;
  pArray[6][1] = 8;
  pArray[6][2] = 17;
  pArray[7][0] = 1;
  pArray[7][1] = 7;
  pArray[7][2] = 9;
  pArray[8][0] = 8;
  pArray[8][1] = 10;
  pArray[8][2] = 18;
  pArray[9][0] = 2;
  pArray[9][1] = 9;
  pArray[9][2] = 11;
  pArray[10][0] = 10;
  pArray[10][1] = 12;
  pArray[10][2] = 19;
  pArray[11][0] = 3;
  pArray[11][1] = 11;
  pArray[11][2] = 13;
  pArray[12][0] = 12;
  pArray[12][1] = 14;
  pArray[12][2] = 20;
  pArray[13][0] = 4;
  pArray[13][1] = 13;
  pArray[13][2] = 15;
  pArray[14][0] = 6;
  pArray[14][1] = 14;
  pArray[14][2] = 16;
  pArray[15][0] = 15;
  pArray[15][1] = 17;
  pArray[15][2] = 20;
  pArray[16][0] = 7;
  pArray[16][1] = 16;
  pArray[16][2] = 18;
  pArray[17][0] = 9;
  pArray[17][1] = 17;
  pArray[17][2] = 19;
  pArray[18][0] = 11;
  pArray[18][1] = 18;
  pArray[18][2] = 20;
  pArray[19][0] = 13;
  pArray[19][1] = 16;
  pArray[19][2] = 19;
}

int adjecentRoom(int rooms[3], int nextRoom){
  return (rooms[0] == nextRoom || rooms[1] == nextRoom || rooms[2] == nextRoom);
}
void roomHazards(int currentRoom, int **pArray,  int wumpus, int pit1, int pit2, int bat1, int bat2){
  printf("You are in room %d. ", currentRoom);
  int room1 = pArray[currentRoom - 1][0];
  int room2 = pArray[currentRoom - 1][1];
  int room3 = pArray[currentRoom - 1][2];

  if(room1 == wumpus || room2 == wumpus || room3 == wumpus){
    printf("You smell a stench. ");
  }
  if(room1 == pit1 || room2 == pit1 || room3 == pit1 || room1 == pit2 || room2 == pit2 || room3 == pit2){
     printf("You feel a draft. ");
  }
  if(room1 == bat1 || room2 == bat1 || room3 == bat1 || room1 == bat2 || room2 == bat2 || room3 == bat2){
    printf("You hear rustling of bat wings. ");
  }
  printf("\n\n");
  
}

void gameHazards(int **pArray, int *person, int userNumber, bool *personIsAlive , int pit1, int pit2, int *wumpus, int *bat1, int *bat2){
  if( *person == *wumpus ){
    if(*wumpus % 2 == 1 ){
      printf( "You hear a slithering sound, as the Wumpus slips away. \n"
					"Whew, that was close! \n");
    *wumpus = pArray[userNumber - 1][ 0]; 
    }
    else {
      printf("You briefly feel a slimy tentacled arm as your neck is snapped. \n"
              "It is over.\n");
      *personIsAlive = false;
      return;
    }
  }
  if( *person == pit1 || *person == pit2) {
    // Person falls into pit
    printf("Aaaaaaaaahhhhhh....   \n");
    printf("    You fall into a pit and die. \n");
    *personIsAlive = false;
    return;
  }
  if( *person == *bat1 ){
    *person = rand() % 20 + 1;
    printf("Woah... you're flying! \n");
    printf("You've just been transported by bats to room %d.\n",*person);
    srand(1);
    *bat1 = rand() % 20 + 1;
  }
  if( *person == *bat2 ){
    *person = rand() % 20 + 1;
    printf("Woah... you're flying! \n");
    printf("You've just been transported by bats to room %d.\n",*person);
    srand(1);
    *bat2 = rand() % 20 + 1;
  }
  
  
}

void arrowComponent(int person, int **pArray, int rooms, int *arrow, int wumpus){
  switch(rooms){
    int room1, room2, room3;
    case 1: 
      scanf(" %d", &room1);
      if(pArray[person - 1][0] == room1 || pArray[person - 1][1] == room1 || pArray[person - 1][2] == room1){
        *arrow = room1;
      }
      else if (pArray[person - 1][0] != room1 || pArray[person - 1][1] != room1 || pArray[person - 1][2] != room1){
        printf("Room %d is not adjacent.  Arrow ricochets...\n", room1); // always prints room 1
        
      }
      break;
    case 2: 
      scanf(" %d %d",&room1, &room2);
      break;
    case 3:
      scanf(" %d %d %d", &room1, &room2, &room3);
    break;
    }
}
//--------------------------------------------------------------------------------
int main(void) {
  const int arraySize = 20;
  int **pArray = NULL;
  pArray = (int **)malloc( arraySize * (sizeof(int*) ));
  for(int i =  0; i <= arraySize; i++ ){
    pArray[i] = (int *)malloc(3 *(sizeof(int)));
  }
  for(int i = 0; i < arraySize; i++){
    for ( int j = 0; j < 3; j++){
      pArray[i][j] = 0;
    }
  }
  
  setRooms(pArray);

  // Seed the random number generator.  Change seed to time(0) to change output each time.
    // srand(time(0));
    srand(1);
    // How to get a random number
    int person = rand() % 20 + 1;   // Using +1 gives random number 1..20 rather than 0..19
    int wumpus = rand() % 20 + 1; 
    int pit1 = rand() % 20 + 1; 
    int pit2 = rand() % 20 + 1; 
    int bat1 = rand() % 20 + 1; 
    int bat2 = rand() % 20 + 1;
    int arrow = rand() % 20 + 1;
  if(bat2 == person || bat2 == wumpus || bat2 == pit1 || bat2 == pit2 || bat2 == bat1){
        bat2 = rand() % 20 + 1;
    }
    if(arrow == person || arrow == wumpus || arrow == pit1 || arrow == pit2 || arrow == bat1){
        arrow = rand() % 20 + 1;
    }
    
  // Below are all the messages used throughout the program. You may need to change them,
  // or move them to a different place in the code.

  // printf("%d %d %d %d %d %d %d",person, wumpus, pit1, pit2, bat1, bat2, arrow );
  char option;
  int userNumber;
  int gameNumber = 1;
  bool personIsAlive = true;
  bool wumpusIsAlive = true;
  
  
  while (personIsAlive && wumpusIsAlive){
    if(person == arrow){
      printf("Congratulations, you found the arrow and can once again shoot.\n");
      
    }
    roomHazards(person, pArray,  wumpus,  pit1, pit2, bat1, bat2);
    printf("%d. Enter your move (or 'D' for directions): ", gameNumber);
    scanf(" %c",&option);
    if(option == 'D' || option == 'd'){
      displayCave();
      displayInstructions();
      continue;
    }
    else if(option == 'M' || option == 'm'){
      scanf(" %d", &userNumber);
      if( adjecentRoom(pArray[person -1], userNumber) ){
        person = userNumber;
        gameHazards(pArray, &person, userNumber, &personIsAlive, pit1, pit2, &wumpus, &bat1, &bat2);
        gameNumber++;
      }
      else {
        printf("Invalid move.  Please retry. \n");
        continue;
      }
    }
    else if (option == 'P' || option == 'p'){
      displayCave();
      continue;
    }
    else if(option == 'C' || option == 'c'){
      printf( "Cheating! Game elements are in the following rooms: \n"
      "Player Wumpus Pit1 Pit2 Bats1 Bats2 Arrow  \n"
      "%4d %5d %6d %5d %5d %5d %5d \n\n", 
        person, wumpus, pit1, pit2, bat1, bat2, arrow);
      continue;
    }
    else if (option == 'S' || option == 's'){
      if (person == arrow || arrow == -1){
        printf("Enter the number of rooms (1..3) into which you want to shoot, followed by the rooms themselves: ");
        int rooms;
        scanf(" %d", &rooms);
        arrowComponent(person, pArray,rooms, &arrow, wumpus);
        // printf("%d", arrow);
        gameNumber++;
      }
      else {
        printf("Sorry, you can't shoot an arrow you don't have.  Go find it.\n");
      }
    }
    else if (option == 'R' || option == 'r'){
      printf("Enter the room locations (1..20) for player, wumpus, pit1, pit2, bats1, bats2, and arrow: \n");
      scanf(" %d %d %d %d %d %d %d", &person, &wumpus, &pit1, &pit2, &bat1, &bat2, &arrow);
      continue;
    }
    else if (option == 'X' || option == 'x'){
      personIsAlive = false; 
      break;
    }
    
    
  }
  
  



  // /* ---- All messages related to the arrow --- */

  // // Attempt to shoot arrow you don't have
  // printf("Sorry, you can't shoot an arrow you don't have.  Go find it.\n");
  
  // // Prompt user to enter input
  // printf("Enter the number of rooms (1..3) into which you want to shoot, followed by the rooms themselves: ");
  
  // // User enters more than 3 rooms to shoot arrow through
  // printf("Sorry, the max number of rooms is 3.  Setting that value to 3.");
  
  // // Arrow killed Wumpus
  // printf( "Wumpus has just been pierced by your deadly arrow! \n"
 //            "Congratulations on your victory, you awesome hunter you.\n");
  
  // // Arrow killed player
  // printf( "You just shot yourself.  \n"
 //            "Maybe Darwin was right.  You're dead.\n");
  
  // // Attempt to shoot arrow through room that is not adjacent
  
  
  // // Arrow ricochets, and kills person
  // printf( "You just shot yourself, and are dying.\n"
 //            "It didn't take long, you're dead.\n");
  
  // // Arrow ricochets, and kills Wumpus
  // printf( "Your arrow ricochet killed the Wumpus, you lucky dog!\n"
 //            "Accidental victory, but still you win!\n");

  // // Player picks up arrow
  // 

  // /* --- End of messages related to the arrow --- */

  // // Both possible messages when the player enters a room that has the Wumpus
  // printf( "You hear a slithering sound, as the Wumpus slips away. \n"
  // 		"Whew, that was close! \n");
  // printf(	"You briefly feel a slimy tentacled arm as your neck is snapped. \n"
  // 		"It is over.\n");

 //    // Both possible messages after the user guesses where the Wumpus is, for a win or loss.
 //    printf("You won!\n");
 //    printf("You lost.\n");
    
  // // Prompt for user when they choose to reset
  // 

 //    // Prompt for guess of where Wumpus room is
 //    printf("Enter room (1..20) you think Wumpus is in: ");

  // // Message that prints at the end of the program
  printf("\nExiting Program ...\n");
  
  return 0;
}