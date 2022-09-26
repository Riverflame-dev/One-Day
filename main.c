#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <Windows.h>
#include "library.h"


void title(void)
{
   
   TypeSlower("\n\n\n");
   Type("You are Charlie. A 23-year-old man living alone in a city.\n");
   Type("For work, you play piano by day. For fun, you hang out with friends.\n");
   Type("For the rest of the time, you spend with your buddy Eddie - a yellow \n"); 
   Type("cockatiel - and solving math puzzles or reading books all afternoon. \n");
   while (getNewline());
   Type("Life has been good, but maybe a little too good. \n");
   Type("From time to time, you get a sense of separation from the surrounding. \n");
   Type("You often think that you must have lost something somewhere.\n");
   Type("But you could not figure out what is it.\n");
   while (getNewline());
   Type("Until one day, things begin to change.\n");
   TypeSlower("...\n\n");
   
   Title();
   TypeSlower("\n");
   while (getNewline());

   puts("	 =======================================");
   puts("		     -Instruction-");
   puts(" ");
   puts(" 	   -look -go -examine -item -direction");
   puts(" ");
   puts(" 	     -->     [Action + place/object]");
   puts(" 	     ->      [Press 'Enter']");
   puts(" 	     item    [View inventory]");
   puts(" 	     quit    [Exit the game]");
   puts("	 =======================================");
   puts(" ");
   puts("Type [start] to start the game");
   while (getInput() && executePhrase());
}

static int Day(void)
{
   SecretFileFound = false;
   
   // waking up
   TypeSlower("\n\n\n"); 
   Type("You wake up. You Look at the alarm. It is about 8 AM. \n");
  
   if (loop == 1)
   {
      Type("You vaguely feel that you just had a strange dream.\n");
      Type("But you cannot remember what it was about.\n");
   }else if (loop == 2)
   {
      Type("You feel something in your hand.\n");
      while (getNewline());
      Type("It's a fluorescent stone. \n");
      moveObject("stone", SYSTEM, player);
      while (getNewline());
      Type("Holding it underneath the blanket, you see a faint green light glowing from it.\n");
      while (getNewline());
      Type("What is this thing? You wonder,\ndoes it have anything to do with the dream you just had?\n");
   }
   while (getNewline());
   Type("A patch of sunlight comes through between the drawn blinds,\nadding a warm tone to the room.\n");
   Type("You open the window of you room and take a deep breath.\nThe fresh air calms your heart.\n");
   Type("White fluffy clouds dotted the azure blue sky.\n\n");
   Type("It is a bright and sunny morning.\n");
   if (loop == 2){
      while (getNewline());
      Type("The weather is perfect, just like yesterday.\n");
      Type("Which makes you feel a bit strange.\n");
   }
   while (getNewline());
   
   Type("Your phone buzzes and a notification pop up on the screen.\n");
   Type("It is a reminder you set in an app \"Planner\". \n");
   if (loop == 1)
      Type("You found it helpful to keep track of the daily tasks.\n");
   Type("\nOpen Planner? (Y/N)\n");
   if (getYorN() == 'Y')
   {
      puts("\n	Saturday 05/07/xx19\n");
      puts("	Bring in the Landry             -[]");
      puts("	Get grocery                     -[]");
      puts("	Visit Saki with Eddie           -[]");
      Type("\nLooks like you have a couple things planned out for the day.\n");
      while (getNewline());
   }else puts("Ok.");
   
   if (loop == 2)
   {
      Type("\nWait a second");
      TypeSlower("...\n");
      Type("But before you could think more, you phone rings.\nIt'a call from Saki.\n");
   } else Type("\nYour phone rings. It's a call from your friend Saki.\n");
   
   Type("Pick it up? (Y/N)\n");
   if (getYorN() == 'Y')
   {
      Type("\"Hi Charlie! I'm so happy that you are coming to my store today.\nI want to bake a cake for you. What kind of cake do you like?\"\n");
      if (loop == 2)
      {
         while (getNewline());
         Type("\"Saki, didn't I visit you yesterday?\"\n\n");
         Type("\"What are you talking about? Yesterday I was not in the city.\"\n");
         puts("\n   a.  \"It can't be. I was there yesterday\"\n   b.  \"Never mind. I'll come today.\"");
         if (getABC() == 'A')
         {
            Type("\"Charlie, are you ok?\" She sounds worried.\n");
            puts("\n   a.  \"I'm ok. But...\"\n   b.  \"...\"");
            if (getABC())
            {
            Type("\"Charlie. Just come. ");
            Type("I will make you cupcakes and hot chocolate. ");
            Type("You will feel better.\"\n");
            while (getNewline());
            Type("\"Ok.\"\n");
            while (getNewline());
            Type("\"See you soon.\"\n");
            Type("She hung up.\n");
            }
         } else Type("I will make cupcakes then. See you soon!\nShe hung up.\n");
      }
      else
      {
         puts("\n   a. Cheese cake\n   b. Chocolate cake\n   c. Carrot cake");
         if (getABC()) Type("\"Aright. I'm going to get the ingredients. See you soon!\"\nShe hung up.\n");
      }
   } else puts("Ok.");
   while (getNewline());
   TypeSlower("\n");
   
   Direction();
   while (getInput() && executePhrase() && (player->location != street));  

// go for morning run
   if (loop == 1)
   {
      TypeSlower("\n...\n\n");
      Type("It is early in the morning.\n");
      Type("You decide to start your morning running and plan to get grocery on the way back.\n");
   }
   while (getInput() && executePhrase() && (player->location != home));

// return from grocery
   moveObject("player", home, livingroom);
   TypeSlower("\n...\n\n");
   Type("You saw Eddie hopping and singing on the table as you open the door.\n\n");
   EddieIsSleeping = false;
   if (loop == 1)
   {
      Type("\"Hello buddy. Ready to head out with me?\"\n");
      Type("Eddie whistles happily.\n\n");
   } 
   Type("You put down the grocery and start to get ready for visiting Saki.\n");
   if (loop == 1) Type("You had bought her gift. You want to bring it to her today.\n");
   while (getInput() && executePhrase() && (player->location != street));

// go to metro
   TypeSlower("\n...\n\n");
   VisitingSaki = true;
   Type("\nYou walk towards the nearby metro station. \n");
   Type("Eddie sits on your shoulder, singing all the way.\n");
   while (getInput() && executePhrase() && (player->location != downtown));

// arrive at downtown
   if (loop == 1)
   {
      TypeSlower("\n...\n\n");
      Type("\nEddie sits back onto your shoulder.\nHe looks at the surrounding with excitement.\n");
   }
   while (getNewline()); 
   Direction(); 
   while (getInput() && executePhrase() && (player->location != Exit));

// leave cafe
   TypeSlower("\n");
   Type("\"Thanks for visiting me today, Charlie.\"\n\n");
   Type("\"I will surely come by more when I'm free.\"\n\n");
   Type("\"You are always welcomed!\"\n\n");
   TypeSlower("...\n\n");
   Type("You left Saki's coffee shop and walk towards the Metro station. \n");
   Type("Eddie is chirping and telling how he was having fun today.\n");
   while (getNewline());

// walking in the street
   Type("When going through an overpass, ");
   Type("you stop for a moment and watch the busy\ncrowds moving under the glittering high-rises and gigantic neon billboards. \n");
   while (getNewline());
   moveObject("player", player->location, Metro);
   TypeSlower("\n");
   Skyline();
   TypeSlower("\n");
   Type("From the metro, you see the skyline of the city at night.\n");
   while (getNewline());

   Type("The train arrives at the station nearby your street.\n");
   tooLate = true;
   VisitingSaki = false;
   moveObject("player", Metro, metro);
   while (getInput() && executePhrase() && (player->location != home));
   
// get back to home
   TypeSlower("\n...\n\n");
   Type("You come back to home at the end of the day.\n");
   Type("Eddie is very tired. You send him back to his nest.\n");
   Type("Eddie puts his head in his feathers and quickly fall asleep.\n");
   Type("You are also a bit tired. ");
   Type("Time to go to bed.\n");
   moveObject("player", home, livingroom);
   bedtime = true;
   while (getInput() && executePhrase() && (CharlieIsSleeping != true));

   return 0;
}

void Reset(void)
{
   landury = false;
   gift = false;
   getGrocery = false;
   exercise = false;
   VisitingSaki = false;

   EddieIsSleeping = true;
   headphone = false;
   EddieIsHere = false;
   plotComplete = false;
   CharlieIsSleeping = false;
   bedtime = false;
   tooLate = false;

   if (loop > 1)
   {
      moveObject("snowglobe", SYSTEM, desk);
      moveObject("notebook", SYSTEM, riverside);
      moveObject("keyboard", SYSTEM, room);
   }
}

void EddiePlot1(void)
{
   TypeSlower("\n...\n");
   Type("You come to Eddie's birdhouse to check on him.\n");
   Type("He is still sleeping.\n");
   puts("\n   a. Wake him up\n   b. Let him sleep");
   if (getABC() == 'A')
   {
      EddieIsSleeping = false;
      Type("You woke Eddie up.\n");
      Type("Eddie jumps on your shoulder and rubs itself against your face.\n");
      Type("\"Good morning Eddie\", you tap its little head with your finger.\n\n");
      if (loop == 2)
      {
         puts("   a. \"We are going to visit Saki today\"   b. \"Something is wrong, Eddie.\"");
         if (getABC() == 'A')
         {
            Type("Eddie got excited wags his tail.\n\n");
            Type("We will take the subway to get there. You need to behave on the way there, ok?\n");
            Type("Eddie nods and made a gentle simmering sound as you rub his neck.\n");
         }
         else
         {
            Type("Eddie tips his head a little and looks at you with his round eyes.\n");
            puts("   a. \"I think I might be trapped in the same day.\"\n   b. \"I'm fine. Don't worry.\"");
            if (getABC())
               Type("You reach your hand to him.\n");
               Type("Eddie jumps onto your finger and sing to you, trying to cheer you up.\n");
         }
      } else
      {
         Type("\"We are going to visit Saki today\"\n");
         Type("Eddie got excited wags his tail.\n");
         while (getNewline());
         Type("\"I know you like that place. You've got friend there, aren't you?\"\n");
         Type("Eddie did a cheerful whistle which is how he says yes.\n");
         while (getNewline());
         Type("We will take the subway to get there. You need to behave on the way there, ok?\n");
         Type("Eddie nods and made a gentle simmering sound as you rub his neck.\n");
      }
   } else 
   {
      Type("You let Eddie rest for a bit more. \n");
      if (loop ==1 ) Type("You decide to get yourself ready for the day while waiting for him to get up.\n");  
   }
}

void RiversidePlot(void)
{
   exercise = true;
   static int count = 0;
   count++;
   TypeSlower("\n...\n\n");
   if (count == 1)
   {
      Type("You come to the running path built by the riverside and start your exercise. \n");
      Type("There are a few other early joggers, too. \n");
      Type("You exchange customary greetings of good morning with them.\n");
   } else if (loop == 2)
   {
      Type("Your head is full of doubt.\n");
      Type("You decide to walk around by the riverside to clear your mind.\n");
      Type("You see some early joggers as usual ");
      Type("and exchange customary greetings of good morning\nwith them.\n");
   } else if (loop > 2)
   {
      Type("You see some early joggers as usual ");
      Type("and exchange customary greetings of good morning\nwith them.\n");     
   }
}

void NotebookPlot(void)
{
   TypeSlower("\n...\n");
   Type("As you were walking along the cobbled road by the river, you noticed it\nlying in the grass.\n");
   puts("Pick it up (Y/N)");
   while (getYorN() != 'Y') 
      puts("Are you sure?");
   moveObject("notebook", riverside, player);
   Type("\nYou opened the notebook and there are some writings on it.\n");
   puts("Read it? (Y/N)");
   while (getYorN() != 'Y') 
      puts("Come on. You are curious. Just read it.");
   Story1();
   while (getNewline());
   Type("By the time you finished reading, you've got a mixed feeling.\n");
   Type("The story doesn't make much sense, ");
   Type("but a sense of familiarity captured you.\n");
   Type("And you are not sure why.\n");
   TypeSlower("\n");
}

void GroceryPlot(void)
{
   getGrocery = true;
   if (loop == 1)
   {
      puts("Get a cart? (Y/N)");
      if (getYorN() == 'Y'){
         Cart();
      }else puts("Ok.");
      while (getNewline());
      AkihitoPlot();
      while (getNewline());
      TypeSlower("...\n\n");
      Type("You've got everything you need from the store.\n");
      Type("Time to head home and pick up Eddie.\n");
   } else if (loop == 2)
   {
      TypeSlower("\n...\n\n");
      AkihitoPlot();
   }
}

void MetroPlot1(void)
{
   Type("You get on the line heading to downtown.\n");
   
   if (loop == 1)
   {
      Type("Eddie sits on your shoulder quietly, behaving like a good bird.\n");
      Type("It's a few stations away from destination.\nPut on headphones? (Y/N)\n");
      if (getYorN() == 'Y')
      {
         Type("You put on headphones and start to play some music.\n");
         headphone = true;
      } else puts("Ok.");
      while (getNewline());
      TypeSlower("...\n\n");
      Type("The train goes from underground onto an elevated railway, \n");
      Type("shuttling between the sky-craping buildings, \n");
      Type("running through the biggest commercial streets from above. \n");
      if (headphone == true) Type("And the music reaches its climax.\n");
      TypeSlower("\n");
      Type("You've always loved to see the city from this angle.\n");
   } else if (loop == 2)
   {
      Type("Eddie sits on your shoulder quietly. \n");
      TypeSlower("\n...\n\n");
   } else 
   {
      Train();
      TypeSlower("...\n\n");
   }
   while (getNewline());
   Type("The train stopped. You get off.\n");
   if (player->location->location == street)
      moveObject("player", metro, downtown);
}

void BirdroomPlot(void)
{
   static int count = 0;
   count++;
   if (count == 1)
   {
      Type("\nThe bird room is separated from the table area by a giant glass wall. ");
      Type("A\ndoor is on the side for guests to enter and interact with the lovely parrots.\n");
      Type("There are about twenty parrots in the room. ");
      Type("Their names and personality are\nshown on a board for people to view.\n");
      puts("\nLet Eddie go to the parrot room? (Y/N)");
      if (getYorN() == 'Y')
      {
         Type("Eddie gets into the parrot room and quickly flies over next to a pink cockatiel.\n");
         Type("You see he ruffles his feathers, bouncing and dancing in front of the lovely female.\n");
         EddieIsHere = true;
      } else puts("Ok.");   
   } else if (count == 2)
   {
      if (EddieIsHere == true) {
         Type("Eddie is having a lot of fun with his friends.\n");
         Type("You let him to stay for a bit longer.\n");
      }
      puts("\nThere's a note on the door. Read it? (Y/N)");
      if (getYorN() == 'Y')
      {
         Type("Interacting with relaxed, adorable parrots make many people smile, \n");
         Type("and we think parrots can heal our tired hearts like therapy. \n");
         Type("We hope you find new, precious friends here.\n");
      } else puts("Ok."); 
   } else if (count > 2)
   {
      if (EddieIsHere == true)
      {
         puts("Tell Eddie it's time to go home? (Y/N)");
         if (getYorN() == 'Y')
         {
            Type("Eddie comes back to you after you have called him to be back.\n");
            EddieIsHere = false;
         } else puts("Ok.");
      } else {
         Type("There are about twenty parrots in the room. ");
         Type("Their names and personality are\nshown on a board for people to view.\n");
      }
   }
   
}

void Story1(void)
{
   TypeSlower("\n\n");
   Type("I had been living in a house since I can remember\n");
   Type("There were a young man and an old man living with me\n");
   Type("The young man was very odd at first \n");
   Type("He didn't talk much and was always watching\n");
   Type("But later he started to talk to me and play with me a lot\n");
   Type("He would let me sit his shoulder and take me out for a walk\n");
   Type("I liked to dance when he makes nice sounds out of a giant table\n");
   Type("He was my best friend\n");
   TypeSlower("\n");
   Type("The first time I saw Alice, ");
   Type("my heart skipped a beat\n");
   Type("She was the most beautiful girl I've ever met\n");
   Type("I asked her if she'd like to dance with me some time\n");
   Type("She smiled shyly and answered yes\n");
   Type("I thought it was the happiest day of my life");
   TypeSlower("\n");
   Type("And couldn't have known it was also my last\n");
   TypeSlower("\n");
   Type("That night, a man in black broke into the house\n");
   Type("He was about to do some terrible\n");
   Type("I made a loud sound to warn the others\n");
   Type("He grabbed me and broke my neck\n");
   Type("And then all the sounds around me were fading away...");
   TypeSlower("\n");
   TypeSlower("\n");
   Type("But that was all a long long time ago.\n");
   Type("Long enough for me to forget the face of the man and the pain on my neck\n");
   Type("I remember waking up in a room full of sunlight\n");
   Type("There I saw Alice again\n");
   Type("She was as beautiful as the first time I saw her\n");
   TypeSlower("\n");
   Type("I told her I will never be gone again\n");
   TypeSlower("\n\n");
}

void AkihitoPlot(void)
{
   if (loop != 2)
   {
      Type("\nWhile you are picking some apples from the basket,\n");
      Type("Akihito walked right out of aisle five.\n");
      Type("Akihito has been your friend since college.\n");
      Type("Now he lives a couple blocks away from you.\n");
      while (getNewline());
      Type("\"Hey Charlie! What's new?\"\n");
      while (getNewline());
      Type("\"Nothing much. I'm going to Saki's Cafe latter.\"\n\n");
      Type("\"That's nice. Say hi for me.\"\n");
      while (getNewline());
      Type("\"Sure. I heard your are working on a new book.\"\n\n");
      Type("\"Yep. I'm planning to start a new series.\"\n");
      puts("\n   a. \"What's the story about\"\n   b. \"You've got to show me when it's done.\"");
      if (getABC() == 'A'){
         Type("\"It's a story about love, death, and robots.\"\n");
         while (getNewline());
         Type("\"That sounds like what you would write about.\"\n\n");
         Type("\"You know me, Charlie.\"\n");
         while (getNewline());
         Type("\"You've got to show me when it's done.\"\n\n"); 
      }
      Type("\"Definitely!\n");

   } else if (loop == 2)
   {
      Type("You walk around in the store and soon find Akihito\npicking up some ice creams from the freezer.\n");
      while (getNewline());

      Type("\"Hey Charlie! What's new?\"\n");
      puts("\n   a.  \"Akihito, did I see you here yesterday?\"\n   b.  \"What I'm about to say will sound strange...\"");
      if (getABC() == 'A')
      {
         Type("\"I don't think so. I didn't come here yesterday. Why you ask?\"\n");
         while (getNewline());
         Type("\"Well, what I'm about to say will sound strange...\"\n\n");
      }
      Type("\"It'd better be strange! I'm listening.\"\n");
      while (getNewline());
      Type("You told him about everything happened this morning.\n");
      TypeSlower("\n");
      Type("\"Wow, Charlir, that is a very interesting experience to have.\n");
      Type("but what if you are still in your dream?\"\n");
      while (getNewline());
      Type("\"What?\"\n\n");
      Type("\"You see, everything has been strange since you have that dream. ");
      Type("So, what if,\nyou are still in the dream and just haven't wake up yet?\"\n");
      puts("\n   a. \"What makes you think this way?\"\n   b. \"If this is all my dream. What would you be?\"");
      if (getABC() == 'A')
      {
         Type("\"It does sound too bizarre to believe. ");
         Type("But sometimes you just got to give the\nimpossible a shot.\"\n");
         while (getNewline());
         Type("\"If this is all my dream. What would you be? \"\n\n");
      } 
      Type("\"Maybe I'm just a part of your dream but I don't realize. ");
      Type("We are all limited\nby what we see and what we feel as humans.\"\n");
      while (getNewline());
      Type("\"You are not wrong on that.\"\n\n");
      Type("\"And Charlie, isn't this what you have been looking for?\n");
      Type("I remember you told me that you often think what you see is not the complete truth.\n");
      Type("Now it seems like part of the truth has revealed itself.\"\n");
      puts("\n   a. \"But I don't quite understand it yet.\"\n   b. \"I think I know what to do.\"");
      if (getABC() == 'A')
      {
         Type("\"Try to make connections with the clues you have then.\n");
         Type("You like solving puzzles, don't you?\"\n");
         while (getNewline());
         Type("\"Yea.. I do. I will try.\"\n\n");
         Type("\"How about this. You go home and look through some of\nyour old stuff. Maybe you'll remember something.\"\n");
         while (getNewline());
         Type("\"Ok. That sounds like a good plan.\"\n\n");
      } 
      Type("\"That's right buddy. Cheer up. You'll get through this.\"\n");
      while (getNewline());
      Type("\"Akihito.\"\n\n");
      Type("\"Huh?\"\n\n");
      Type("\"Thank you for talking to me. I didn't expect anyone to\nbe willing to talk about all these strange stuff.\"\n");  
      while (getNewline());
      Type("\"A friend never gets bothered doing so, Charlie.\"\n");
      Type("He smiles brightly and taps you on the shoulder.\n");
   }     
   else
   {
      
   }
}

void CafePlot(void)
{
   TypeSlower("\n...\n\n");
   if (loop == 1)
   {
      Type("You arrive at a small store off the street.\n");
      Type("There is a poster on the glass window.\n");
      puts("Read it? (Y/N)");
      if (getYorN() == 'Y')
      {
         Type("OumuCafe, run by a married couple who love parrots, opened on August 8, 20xx.\n");
         Type("OumuCafe aims to create a space where parrots and people can spend a cozy time\ntogether with mutual respect.\n");
      } else puts("Ok.");
      while (getNewline());
      Type("\"Hey Charlie!\", a girl in yellow dress comes out from the store.\n");
      while (getNewline());
      Type("\"Hello Saki. Good to see you again. How have you been?\"\n\n");
      Type("\"We finally finished the renovation of the store last month and\njust get reopened. I can't wait to have you and Eddie back here!\"\n");
      while (getNewline());
      Type("\"Eddie missed here a lot. He can't wait to come back, too.\"\n\n");
      Type("\"Haha- Come on inside. You will love the new designs!\"\n");
      while (getNewline());
      TypeSlower("...\n\n");
      Type("You come to the inside of Saki's coffee shop. ");
      Type("The layout has changed quit a\nlot from the last time you were here. ");
      Type("Wood flooring and finishes create a\nwarm atmosphere. ");
      Type("There are a few other costumers in the store.\n");
      Look("around");
   } else 
   {
      Type("You arrive at Saki's coffee shop.\n\n");
      Type("\"Hey Charlie!\", Saki comes out from the store.\n");
      while (getNewline());
      Type("\"Hello Saki... How have you been?\"\n\n");
      Type("\"We finally finished the renovation of the store last month and\njust get reopened. I can't wait to have you and Eddie back here!\"\n");
      puts("\n   a.  \"...\"\n   b.  \"Eddie missed here a lot. He can't wait to come back, too\"");
      if (getABC() == 'A')
      {
         Type("\"Hey Charlie. Come on inside. I will make you something warm to drink\"\n\n");
         Type("\"Ok.\"\n");

      } else Type("\"Haha- Come on inside. You will love the new designs!\"\n");
      while (getNewline());
      Type("You come to the inside of Saki's coffee shop.\n");
      Type("There are a few other costumers in the store.\n");
   }
   moveObject("player", cafe, seating);
}

void CoffeeBarPlot(void)
{
   static int count = 0;
   static int count2 = 0;
   count++;
   if (loop == 1)
   {
      if (count == 1)
      {
         TypeSlower("...\n\n");
         Type("The barista's realm is covered in small white tiles that give it a sterile\nappearance. ");
         Type("On the other side of the bar, the seating area is lined\nin tactile cork panels.\n");
         while (getNewline());
         Coffee();
         Type("\n\"Here you go\", Saki made you a cup of cappuccino in a cute mug.\n\n");
         Type("\"Thanks. By the way, I have a gift for you.\"\n");
         puts("\nGive Saki the snowglobe? (Y/N)");
            while (getYorN() != 'Y')
               puts("What a bad friend you are.\nI'll give you a chance to chose again.\n");
         Snowglobe();
         moveObject("snowglobe", player, SYSTEM); //might be error
         Type("\"It's beautiful. I love it! Thank you, Charlie.\"\n");
         while (getNewline());
         Type("\"I'm glad you like it.\"\n");
      } else if (count == 2)
      {
         Type("Saki is making another cup of coffee for a customer.\n");
         Type("\"So, how do you like the new layout?\", she says.\n");
         while (getNewline());
         Type("\"It's lovely. I feel like reading here all afternoon.\"\n\n");
         Type("\"I'm happy to have you here, Charlie. ");
         Type("Sometimes my day can get stressful\nand having a friend around helps me a lot.\"\n");
         while (getNewline());
         Type("\"That's what I'm here for.\"\n\n");
         Type("\"You are the best, Charlie\"\nShe gave you a big smile along with a slice of cake.\n");
         plotComplete = true;
      } else if (count > 2)
      {
         Type("Saki seems to be busy helping a customer.\n");
         Type("You decide to not brother her for now.\n");
      }
   } else if (loop > 1)
   {
      count2++;
      if (count2 == 1)
      {
         Type("Saki is the only barista in the store at the moment. \n");
         while (getNewline());
         Coffee();
         Type("\"Here you go\", She made you a cup of cappuccino in a cute mug.\n\n");
         Type("\"Thank you, Saki.\" you take a sip from the cup. \n\n");
         Type("\"Are you feeling a bit better?\"\n");
         while (getNewline());
         Type("\"Maybe... I don't know.\"\n\n");
         Type("\"Tell me what's in your mind.\"\n");
         while (getNewline());
         Type("\"...I'm trying to figure something out, \n");
         Type("but I'm not sure what it is.\"\n\n");
         Type("\"Think about how you solve those math puzzles, Charlie,");
         TypeSlower("\n");
         Type("I'm sure you will figure it out eventually.\"\n");
         while (getNewline());
         Type("\"This one I've came across is hard. ");
         Type("It is about myself.\"\n");
         TypeSlower("\n");
         Type("\"I see...");
         TypeSlower("\n");
         Type("Well, why don't you have some cake first? It will cheer you up.\n");
         Type("Then you can sit down and keep solving your puzzle.\"\n");
         while (getNewline());
         Type("\"Ok. Sounds like a good idea\"\n\n");
         Type("She smiles and hand you a slice of cake she made.\n");
      } else if (count2 == 2)
      {
         Type("\"Saki, I have a gift for you.\"\n");
         puts("\nGive Saki the snowglobe? (Y/N)");
            while (getYorN() != 'Y')
               puts("What a bad friend you are.\nI'll give you a chance to chose again.\n");
         Snowglobe();
         Type("\n\"It's beautiful. I love it! Thank you, Charlie.\"\n");
         Type("\"I'm glad you like it.\"\n");
         plotComplete = true;
      } else if (count2 > 2)
      {
         Type("Saki seems to be busy helping a customer.\n");
         Type("You decide to not brother her for now.\n");
      }
   }
}

void ReadingPlot(void)
{
   //TypeSlower("...\n");
   Type("\nYou find the spot where you seat at every time you come here. ");
   Type("It is a comfortable\nsofa seat by the shelf where many books are stored for customers to read. \n");
   puts("\nFind a book to read? (Y/N)");
   if (getYorN() == 'Y'){
      Type("You find a book that is about a pilot, stranded in the desert, ");
      Type("meets a little\nboy who is a prince on a planet. ");
      Type("It is a story you've read a long time ago\nand you liked it.\n");
      TypeSlower("\n");
      Type("You sit down and begin reading the book. \n");
      while (getNewline());
      TypeSlower("...\n\n");
      TypeSlower("");
      Planet();
      while (getNewline());
      Type("By the time you finished reading, the evening has come down upon the city.\n");
      Type("You feel content with how you have spent the time.\n");
   }else puts("Ok.");
}

void ComputerPlot(void)
{
   if (loop != 1)
   {
      while(getPassword());
      if (SecretFileFound == true)
      {
         TypeSlower("\n");
         TypeSlower("Loading file");
         TypeSlower("...\n\n");
         readFile();
      }
   }
}

void Dream(void)
{
   TypeSlower("\n");
   TypeSlower("\n...\n");
   TypeSlower("\n");
   if (loop == 1){
      Type("You wake up in a golden wheat field. Breeze blow with the golden plants. ");
      Type("You \nfeel something is looking at you.\n");
      while (getNewline());
      Type("It's a sheep.\n");
      while (getNewline());
      Type("But to be more specific - an electronic sheep, because of its\nobvious mechanical joints and metal body.\n\n");
      Type("You look at it and think: ");
      Type("this is such a dedicated piece of work.\n");
      while (getNewline());
      Type("\"You are such a dedicated piece of work\", ");
      Type("says the sheep out of the blue.\n");
      Type("Its voice sounds like a little boy.\n");
      while (getNewline());
      Type("You blink. ");
      Type("\"What did you say?\"\n\n");
      Type("\"Nothing. Will you play with me? \"\n");
      Type("The sheep looks at you with its electric eyes, emitting a faint green light.\n");
      puts("\nPlay with the sheep? (Y/N)");
      if (getYorN() == 'Y'){
         Type("You run with the sheep between the field, and up the hillside. ");
         Type("Rolling around \nunder a big tree. ");
         Type("Somehow, your body is shrinking, and you've become a little\nboy. ");
         Type("You've never felt like this before.\n");
      } else
      {
         Type("You are not in the mood to play with the sheep. \n");
         Type("\"Ok.\" says the sheep,");
         Type("\"will you pet me at least?\"\n");
         Type("\"Ok.\"\n");
      }
      while (getNewline());
      Type("You reach out your hand to pet the sheep on its head. ");
      Type("Instead of the touch of\ncold metal, you feel there is a slight warmth in your palm.\n");
      Type("\nIt feels as if a warm current through your arm and hit your head gently. ");
      Type("It\nmakes you drowsy, and you feel like you're nodding off...\n");
      TypeSlower("...\n\n\n");
   } else if (loop == 2)
   {
      Type("You wake up in a golden wheat field. Breeze blow with the golden plants. ");
      Type("You \nfeel something is looking at you.\n");
      while (getNewline());
      Type("\"Hi, It's you again\", says the sheep.\n");
      while (getNewline());
      Type("\"Is this my dream?\"\n\n");
      Type("\"Maybe it is, maybe it's not.\"\n");
      while (getNewline());
      Type("\"What do you mean?\"\n\n");
      Type("\"I'll tell you a story.\n");
      TypeSlower("\n");
      Type("Once, there was a man fell asleep and dreamed of being a butterfly. ");
      Type("When he\nwoke up, ");
      Type("he did not know whether he really was a man who had dreamed of being\na butterfly ");
      Type("or that he was a butterfly now dreaming of being a man.\n");
      while (getNewline());
      Type("Charlie, ");
      Type("do you know if you are a man dreaming of being here, ");
      Type("or something\nelse dreaming of being a man?\"\n");
      while (getNewline());
      Type("\"...\"\n\n");
      Type("\"Come with me.\"\n");
      while (getNewline());
      Type("You follow the sheep and walk across the wheat filed and onto a road. \n");
      Type("The scenery around you is changing. A vision of desert filled your sight.\n\n");
      Type("\"Did you know that millions of years ago, ");
      Type("this desert was once a seabed.\"\n");
      while (getNewline());
      Type("\"I can imagine so. The world is an old place.\"\n");
      TypeSlower("\n");
      Type("The sun goes down. A new moon appears on the sky.\n");
      while (getNewline());
      Type("Suddenly, ");
      Type("all kinds of prehistoric sea creatures start to appear and swirl\naround in the air, ");
      Type("as if the aquatic spirits have come to where once was\ntheir realm.\n");
      while (getNewline());
      Type("Each species is of a different color. ");
      Type("A range of greens and oranges set\nagainst the navy backdrop of the night sky. \n");
      while (getNewline());
      Type("A glowing jellyfish went through your fingers as you try to touch it.\n");
      Type("And it felt like you've touched a soft ball of light. ");
      Type("You reach for it and\ntry to grab it.\n");
      while (getNewline());
      Type("When you open your palm, a glowing light ball is in your hand. \n");
      while (getNewline());
      Type("\"What is this?\" You ask.\n\n");
      Type("\"The life force in their spirits.\"\n");
      while (getNewline());
      Type("\"It's beautiful.\"\n\n");
      Type("\"It is what life looks and feels like to you, Charlie.\"\n");
      while (getNewline());
      Type("\"Life...\"\n");
      while (getNewline());
      Type("\"Charlie, are you ready to leave?\"\n");
      puts("\n   a.  \"I think so.\"\n   b.  \"I need a little more time.\"");
      if (getABC() == 'A')
      {
         Type("\"Come with me.\"\n");
         while (getNewline());
         EndingPart2();
      } else {
         Type("\"I see.");
         TypeSlower(" ");
         Type("I will take you to see them.\"\n");
         while (getNewline());
         EndingPart1();
      }
   }
}

void EndingPart1(void)
{
   TypeSlower("\n...\n");
   TypeSlower("\n");
   Type("The south street of downtown.\n");
   Type("Saki comes out from the coffee shop.\n");
   while (getNewline());
   Type("\"Hi Charlie.\"\n");
   while (getNewline());
   Type("\"Saki, I think I have the answer to the puzzle.\"\n\n");
   Type("\"That's great. I'm so happy for you.\"\n");
   while (getNewline());
   Type("\"I'll be leaving for a while. ");
   Type("Will you take care of Eddie for me?\"\n\n");
   Type("\"Of course.\"\n");
   while (getNewline());
   Type("\"Thank you, Saki.\"\n\n");
   Type("\"Anytime!\n");
   TypeSlower("\n");
   Type("And Charlie, take care of yourself.\"\n");
   while (getNewline());
   Type("\"I will. You too.\"\n");

   TypeSlower("\n...\n");
   TypeSlower("\n");
   Type("Sunday morning. ");
   Type("The grocery store.\n");
   Type("Akihito is walking towards you.\n");
   while (getNewline());
   Type("\"Hey Charlie, what's new?\"\n");
   while (getNewline());
   Type("\"You were right, Akihito. ");
   Type("This is all my dream.\"\n");
   TypeSlower("\n");
   Type("\"I know.\"\n");
   while (getNewline());
   Type("\"Do you know that you are not real?\"\n");
   TypeSlower("\n");
   Type("\"I probably know that, ");
   Type("and that's alright.\n");
   Type("I may be created for some purpose.\n");
   Type("But they don't define my being solely.\"\n");
   while (getNewline());
   Type("\"I see what you mean.\"\n\n");
   Type("\"Don't worry for me, Charlie. ");
   TypeSlower("\n");
   Type("You are leaving, aren't you?\"\n");  
   while (getNewline());
   Type("\"I am.\"\n");
   TypeSlower("\n");
   Type("\"I will miss you, Charlie. ");
   Type("You have been an awesome friend.\"\n");
   while (getNewline());
   Type("\"I'm really glad to have known you, Akihito.\"\n\n");
   Type("\"Goodbye friend, take care!\"\n");
   while (getNewline());

   EndingPart2();
}

void EndingPart2(void)
{
   TypeSlower("\n...\n");
   TypeSlower("\n");
   Type("The space around you is changing rapidly. ");
   TypeSlower("\n");
   Type("In the end, you find yourself in a white room. \n");
   Type("A letter is in you hand.\n");
   puts("\nRead it? (Y/N)");
   if (getYorN() == 'Y')
   {
      TypeSlower("\n");
      readLetter();
   } else puts("Ok.");
   while (getNewline());
   Type("You feel a growing lightness in your body. \n");
   Type("The walls and ceiling are disappearing. \n");
   while (getNewline());
   Type("You close your eyes.\n");
   TypeSlower("\n...\n\n\n");
   Type("Charlie woke up on a day around dusk \n");
   Type("His memories were back \n");
   Type("It has been the third year since he was put to sleep\n");
   Type("His body was dumped at a landfill full of broken parts of machineries\n");
   Type("Along with many other abandoned robots\n");
   TypeSlower("\n");
   Type("Charlie stood up with his broken limbs \n");
   Type("He slowly walked towards the lights of some faraway city\n");
   Type("Picking up parts along the way to fix his body\n");
   TypeSlower("\n...\n\n\n");
   TheEnd();
   TypeSlower("\n");
   exit(EXIT_GAME);
}

int main(void)
{
   title();
   loop = 0;
   for (int i = 0; ; i++)
   {
      loop++;
      Reset();
      Day();
      Dream();
   }
   
   return 0;
}

