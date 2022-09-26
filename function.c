#include <stdio.h>
#include <string.h>
#include "library.h"
#include <stdbool.h>




OBJECT object[] = {
   {room, "player", "yourself"},
   //1
   {street, "home", "your aprtment (home)", "Your aprtment is small, but comfy."},
   {home, "room", "your room", "Everything is kept clean and tidy."},
   {home, "bathroom", "the bathroom"},
   {home, "balcony", "your balcony", "You have many plants here. You take good care of them."},
   {home, "kitchen", "the kitchen"},
   {home, "livingroom", "the livingroom"},
   {home, "door", NULL, NULL},
   //8
   {street, "street", "the street by your home", "It's quite convenient to go to other places from here."},
   {street, "metro", "the metro station", "The station is clean. A few passengers are waiting for their trains to come."},
   {street, "grocery", "grocery store", "You can find pretty much everything you need here."},
   {street, "riverside", "the riverside", "This is where you come to exercise every morning."},
   //12
   {downtown, "downtown", "downtown", NULL},
   {downtown, "north", "north", "There is a park at the north district."},
   {downtown, "south", "south", "This is a bookshop street. Many bookstores and cafes are located along this road."},
   {downtown, "east", "east", "There are a couple malls at the east district. The streets are filled with people."},
   {downtown, "west", "west", "In this area, restaurants and street stalls are serving all kinds of delicious food."},
   //17
   {south, "OumuCafe", "OumuCafe", NULL},
   {cafe, "birdroom", "birdroom", NULL},
   {cafe, "seating", "seating area", "There're tables and chairs for customer to sit at."},
   {cafe, "coffee", "coffee bar", NULL},
   {cafe, "exit", "exit", NULL},
   //22
   {player, "photo", "An old photograph", "A photo of you, Eddie, and another man. You can't see the man's face clearly."},
   {room, "shelf", "a shelf", "The shelf is filled with books.\nMost of them are about music and math."},
   {room, "closet", "a closet" , "Most of your clothes are simple and casual.\nBut some are quite stylish."},
   {room, "birdhouse", "", "It is Eddie's little house.\nHe sleeps there at night."},
   {room, "computer", "a computer", NULL},
   {room, "desk", "a desk", "You often sit in front of it to read or solving some puzzles." },
   {desk, "snowglobe", "a snowglobe", "It is a snowglobe. You bought this as a gift to Saki."},
   {room, "bed", "your bed", NULL},
   {bathroom, "mirror", "a mirror", "You can see your reflection in the mirror."},
   {bathroom, "bathtub", NULL, NULL},
   {balcony, "landury", NULL, NULL},
   {balcony, "flower1", "flower1", "This is a lemon balm.\nLemon balm means sympathy." },
   {balcony, "flower2", "flower2", "This is a canterbury bell.\nCanterbury bell means gratitude."},
   {balcony, "flower3", "flower3", "This is a sage.\nSage means wisdom, immortality."},
   {livingroom, "piano", "piano"},
   {riverside, "river", NULL, "A river runs through the city, separating it into two parts."},
   {riverside, "road", NULL, "There is a cobbled road by the river. You like taking a walk along it."},
   //39
   {SYSTEM, "notebook", "a old notebook", "It is a leather bound notebook."},
   {SYSTEM, "stone", "a fluorescent stone", "It emits a faint green light in the darkness."},
   {SYSTEM, "keyboard", "keyboard", "Some letters on the keyboard are missing."}
};

// go through the object list
OBJECT *parseObject(const char *noun)
{
   OBJECT *obj, *found = NULL;
   for (obj = object; obj < endOfObjs; obj++)
   {
      if (noun != NULL && strcmp(noun, obj->tag) == 0)
         found = obj;
   }
   return found;
}

int listObjectsAtLocation(OBJECT *location)
{
   int count = 0;
   OBJECT *obj;
   for (obj = object; obj < endOfObjs; obj++)
   {
      if (obj != player && obj->location == location)
      {
         if (count++ == 0)
         {
            if (location == home || location == street || location == downtown || location == cafe)
               printf("\n*place(s) availible to go to:\n");
            else printf("\n*object(s) availible to examine:\n");
         }
         if (location == cafe || location == downtown)
            printf("-%s   ", obj->description);
         else printf("-%s   ", obj->tag);
      }
   }
   printf("\n");
   return count;
}

void moveObject(const char *noun, OBJECT *from, OBJECT *to)
{
   OBJECT *obj = parseObject(noun);
   if (obj == NULL)
   {
      printf("Item unavaible.\n");
   }
   else if (from != obj->location)
   {
      printf("You are not at where the item can be found.\n");
   }
   else
   {
      obj->location = to;
      if (to == player)
         puts("*new item acquired!");
   }
}

void Item(void)
{
   OBJECT *item;
   printf("\nInventory:\n\n");
   printf("Item                       description\n");
   for (item = object; item < endOfObjs; item++)
   {
      if (item != player && item->location == player)
         printf("%-27s%s\n", item->description, item->sidenote);
   }
}

void Direction(void)
{
   if (player->location->location == home || player->location->location == street || player->location->location == downtown )
   {
      printf("Your location is %s.\n", player->location->location->description);
      listObjectsAtLocation(player->location->location);
   } 
   else if (player->location == home || player->location == street || player->location == downtown || player->location == cafe)
   {
      printf("Your location is %s.\n", player->location->description);
      listObjectsAtLocation(player->location);
   }
   else puts("There's no direction guide at your current location.");
}

void Look(const char *noun)
{
   if (noun != NULL && strcmp(noun, "around") == 0)
   {
      if (player->location->location != downtown)
         printf("You are in %s.\n", player->location->description);
      if (player->location->sidenote != NULL)
         puts(player->location->sidenote);
      listObjectsAtLocation(player->location);
   } else puts("Try again with the phrase 'look around'.");
}

void Go(const char *noun)
{
   OBJECT *place = parseObject(noun);
   if (place == NULL || place->location != player->location->location)
   {
      puts("Pleace unavalible.\nCheck [Direction] for avalible places.");
      return;
   }
   else if (place == player->location)
   {
      printf("You are already there.\n");
      return;
   } 
  
  if (strcmp(place->tag, "home") == 0)
   {
      if (getGrocery == false)
      {
         puts("You forget to the groceries. Go get it!");
         return;
      } else if (VisitingSaki == true)
      {
         puts("This is not the way to metro.");
         return;
      } else {
         player->location = place;
         printf("You are in %s.\n", player->location->description);
         }
   }
   else if (strcmp(place->tag, "grocery") == 0)
   {
      if (exercise == false && (loop < 3)){
         puts("Have you done your exercise yet?");
         return;
      } else if (tooLate == true)
      {
         puts("It's time to go home.");
         return;
      } else if (VisitingSaki == true)
      {
         puts("This is not the way to metro.");
         return;
      }
      else {
         player->location = place;
         Look("around");
         GroceryPlot();
         }
   } 
   else if (strcmp(place->tag, "riverside") == 0)
   {
      if (tooLate == true)
      {
         puts("It's time to go home.");
         return;
      } else if (VisitingSaki == true)
      {
         puts("This is not the way to metro.");
         return;
      }
      else {
         player->location = place;
         RiversidePlot();
         }
   }
   else if (strcmp(place->tag, "metro") == 0)
   {
      if (getGrocery == false){
         puts("Have you got groceries yet?");
         return;
      } else if ((getGrocery == true) && (EddieIsSleeping == true))
      {
         puts("You should go home and put down the grocery first.");
         return;
      }
      else if (tooLate == true)
      {
         puts("It's time to go home.");
         return;
      }
      else {
         player->location = place;
         Look("around");
         MetroPlot1();
      }
   } else if (strcmp(place->tag, "OumuCafe") == 0)
   {
      player->location = place;
      CafePlot();
   }
   else if (strcmp(place->tag, "exit") == 0)
   {
      if (EddieIsHere == true){
         puts("Don't forget your Eddie.");
         return;
      } else if (plotComplete == false)
      {
         puts("Already leaving? Check out the coffee bar a couple more times!");
         return;
      } else player->location = place;
   }
   else // Moves player
   {
      player->location = place;
      if (player->location->description != NULL)
         Look("around");
   }

   if (strcmp(place->tag, "kitchen") == 0)
   {
      puts("Get something to eat?(Y/N)");
      if (getYorN() == 'Y')
      {
         ShowFood();
      }else puts("Ok.");
   } 
   else if (strcmp(place->tag, "door") == 0)
   {
      if (landury == false){
         puts("Have you brought in the laundry yet?");
         moveObject("player", door, room);
      } else if((getGrocery == true) && (gift == false))
      {
         puts("You forget Saki's gift.\nIt's probably somewhere in your room.");
         moveObject("player", door, room);
      } else if (tooLate == true)
      {
         puts("It's time to sleep.");
         moveObject("player", door, room);
      } 
      else 
      {
         puts("You left your apartment.\nNow you are in the street.");
         moveObject("player", door, street);
      }
   }  
   else if (strcmp(place->tag, "south") == 0)
   {
      if (cafe->location != downtown)
         moveObject("OumuCafe", south, downtown);
   }
   else if (strcmp(place->tag, "birdroom") == 0)
   {
      BirdroomPlot();
   } 
   else if (strcmp(place->tag, "coffee") == 0)
   {
      CoffeeBarPlot();
   } 
   else if (strcmp(place->tag, "seating") == 0)
   {
      ReadingPlot();
   }
}


void Examine(const char *noun)
{
   OBJECT *item = parseObject(noun);
   if (item == NULL)
   {
      puts("Item unavalible.\n[look] around for avalible items");
      return;
   }else printf("%s\n", item->sidenote);
   
   if (strcmp(item->tag, "closet") == 0)
   {
      puts("\nGet changed? (Y/N)");
      if (getYorN() == 'Y'){
         Clothes();
      }else puts("Ok.");
   } else if (strcmp(item->tag, "landury") == 0)
   {
      Laundry();
      puts("The clothes are dry now.\nBring them in? (Y/N)");
      if (getYorN() == 'Y'){
         NoLaundry();
         landury = true;
      } else puts("Ok.");
   } else if (strcmp(item->tag, "shelf") == 0)
   {
      Books();
      puts("\nYou notice one book holding a bookmark.\nOpen the book? (Y/N)");
      if (getYorN() == 'Y')
      {
         OpenBook();
      } else puts("Ok.");
   } else if (strcmp(item->tag, "computer") == 0)
   {
      Computer();
      puts("Turn it on? (Y/N)");
      if (getYorN() == 'Y'){
         ComputerOn();
         ComputerPlot();
      } else puts("Ok.");
   } else if (strcmp(item->tag, "mirror") == 0)
   {
      if (loop == 2){
         TypeSlower("\n...\n\n");
         Eye();
      } 
   } else if (strcmp(item->tag, "bed") == 0)
   {
      Bed();
      if (bedtime)
      {
         puts("\nGo to bed? (Y/N)");
         if (getYorN() == 'Y'){
            CharlieIsSleeping = true;
         } else puts("Ok.");
      }
   } else if (strcmp(item->tag, "bathtub") == 0)
   {
      Bathtub();
      puts("Take a bath? (Y/N)");
      if (getYorN() == 'Y'){
         TakeBath();
      } else puts("Ok.");
   } else if (strcmp(item->tag, "desk") == 0)
   {
      if (gift == false){
         puts("Right now there is something on the desk:");
         Snowglobe();
         puts("\nPick it up? (Y/N)");
         if (getYorN() == 'Y')
         {
            moveObject("snowglobe", desk, player);
            gift = true;
         } else puts("Ok.");
      }
   } else if (strcmp(item->tag, "birdhouse") == 0)
   {
      if (EddieIsSleeping == true) EddiePlot1();
   } else if (strcmp(item->tag, "notebook") == 0)
   {
      NotebookPlot();
   } else if (strcmp(item->tag, "keyboard") == 0)
   {
      Keyboard();
   } else if (strcmp(item->tag, "piano") == 0)
   {
      Piano();
   }
}

