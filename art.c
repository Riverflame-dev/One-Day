// Resource
// https://www.oocities.org/spunk1111/indexjava.htm
// https://asciiart.website/index.php?art=transportation/trains

#include <stdio.h>
#include <string.h>
#include "library.h"


void Title(void)
{
    puts("\n\n");
    puts(" ..|''||                       '||''|.                   ");
    puts(".|'    ||  .. ...     ....      ||   ||   ....   .... ...");
    puts("||      ||  ||  ||  .|...||     ||    || '' .||   '|.  | ");
    puts("'|.     ||  ||  ||  ||          ||    || .|' ||    '|.|  ");
    puts(" ''|...|'  .||. ||.  '|...'    .||...|'  '|..'|'    '|   ");
    puts("                                                 .. |    ");
    puts("                                                  ''     ");
}


void ShowFood(void)
{
    static int count = 0;
    count++;
    if (count == 1)
    {
        puts("You made yourself some coffee and cereal.");
        puts(" ");
        puts("  ;)( ;");
        puts(" :----:     o8Oo./");
        puts("C|====| ._o8o8o8Oo_.");
        puts(" |    |  \\========/");
        puts(" `----'   `------'");
    }else if (count == 2)
    {
        puts("You found some soft doughy bread.");
        puts(" ");
        puts("  _   __    _   __");
        puts(" ( `^` ))  ( `^` ))");
        puts(" |     ||  |     ||");
        puts(" |     ||  |     ||");
        puts(" '-----'`  '-----'`");
    }else if (count == 3)
    {
        puts("You found a tiny apple.\n");
        puts("     __");
        puts("     \\_}");
        puts("    .-./--.");
        puts("   /# ^^   \\");
        puts("   |       |");
        puts("    \\     /");
        puts("     `\"`\"`");
    }else if (count == 4)
    {
        puts("There's nothing in the kitchen. ");
        puts("You are out of grocery, so you ordered dilivery.");
        puts("       __");
        puts("      /");
        puts("   .-/-.");
        puts("   |'-'|");
        puts("   |   |");
        puts("   |   |   .-\"\"\"\"-. ");
        puts("   \\___/  /' .  '. \\   \\|/\\//");
        puts("         (`-..:...-')  |`\"\"`| ");
        puts("          ;-......-;   |    |");
        puts("           '------'    \\____/");
        count = 0;
    }
}

void Laundry(void)
{
    puts("Your laundry is hanging at the balcony.");
    puts(" ");
    puts("==!====!====!=====!=====!====!===!===!=====!===!===");
    puts("     /`\\__/`\\   /`\\   /`\\  |~| |~|  /)=I=(\\   ");
    puts("    |        | |   `\"`   | | | | |  |  :  |      ");
    puts("    '-|    |-' '-|     |-' )/\\ )/\\  |  T  \\     ");
    puts("      |    |     |     |  / \\// \\/  (  |\\  |    ");
    puts("      '.__.'     '.___.'  \\_/ \\_/   |  |/  /");
    puts("                                    |  /  /");
    puts("jgs                                 |  \\ /");
    puts("                                    '--'`\n");
}

void NoLaundry(void)
{
    puts("\n==!====!====!=====!=====!====!===!===!=====!===!====");
    puts("\n\n\n\n\n\n\n\n");
    puts("No laundry is hanging at the balcony now.");
}

void Clothes(void)
{
    static int count = 0;
    count++;
    if (count == 1)
    {
        puts("You found a clean shirt and put it on.\n");
        puts("      .-<\\ />-.");
        puts("     / , \\V/ , \\");
        puts("     | |  :  | |");
        puts("     | |  :  | |");
        puts("     | |__:__| |");
        puts(" jgs \\_/     \\_/");
    } else if (count == 2)
    {
        puts("You found a clean sweater and put it on.\n");
        puts("                 ,..,");
        puts("              .-//||\\\\-.");
        puts("             / ,      , \\");
        puts("            /  ;      ;  \\");
        puts("           /, /|      |\\ .\\");
        puts("           \\` \\|      |/ `/");
        puts("            \\  \\      /  /");
        puts("       jgs   \\_/||||||\\_/");
        puts("               `\"====\"`");
    count = 0;
    }
}


void Cart(void)
{
    puts("Here's a cart.\n");
    puts("      ___");
    puts("      '-||__/__________");
    puts("        |==/|_|_|_|_|_/");
    puts("        |=/_|_|_|_|_|/");
    puts("        |/|_|_|_|_|_/");
    puts("        |_|_|_|_|_|/");
    puts("          )_____(_");
    puts("    jgs  [--------|");
    puts("         (o)\"\"\"\"(o)");
}


void Eye(void)
{
    puts(" ");
    puts("        _....,_         _,...._");
    puts("    _.-` _,..,_'.     .'_,..,_ `-._     In the mirror, you see your eyes");
    puts("     _,-`/ o \\ '.     .' / o \\`-,_           emitting a faint green light.");
    puts("jgs   '-.\\___/.-`     `-.\\___/.-'      \n");
}


void Computer(void)
{
    puts("You see a computer.");
    puts("                          ________");
    puts("                         | ______o|");
    puts("         _______________ ||__---_||");
    puts("        |  ___________  || ______ |");
    puts("        | |           | |||______||");
    puts("        | | #         | ||--------|");
    puts("        | |           | ||      O |");
    puts("        | |           | ||      | |");
    puts("        | '-----------' ||      | |");
    puts("        |_____________-_||      | |");
    puts("          __/_______\\__  |::::::::|");
    puts("         ________________'-.__");
    puts("        /:::::::::':::'::\\ .\\\\\\---.");
    puts("    jgs/::======::: .:.:::\\ \\\\_)   \\");
    puts("       `""""""""""""""""""`  '-----'");

}

void ComputerOn(void)
{
    if (loop == 1)
    {
        puts("The computer is on.");
        puts("                          ________");
        puts("                         | ______o|");
        puts("         _______________ ||__---_||");
        puts("        |  ___________  || ______ |");
        puts("        | |72 65 6d 65| |||______||");
        puts("        | |6d 62 65 72| ||--------|");
        puts("        | |69 74      | ||      O |");
        puts("        | |           | ||      | |");
        puts("        | '-----------' ||      | |");
        puts("        |_______________||      | |");
        puts("          __/_______\\__  |::::::::|");
        puts("         ________________'-.__");
        puts("        /:::::::::':::'::\\ .\\\\\\---.");
        puts("    jgs/::======::: .:.:::\\ \\\\_)   \\");
        puts("       `""""""""""""""""""`  '-----'");
    } else
    {
        puts("The computer is on.");
        puts("                          ________");
        puts("                         | ______o|");
        puts("         _______________ ||__---_||");
        puts("        |  ___________  || ______ |");
        puts("        | |           | |||______||");
        puts("        | | password: | ||--------|");
        puts("        | |  _ _ _ _  | ||      O |");
        puts("        | |           | ||      | |");
        puts("        | '-----------' ||      | |");
        puts("        |_______________||      | |");
        puts("          __/_______\\__  |::::::::|");
        puts("         ________________'-.__");
        puts("        /:::::::::':::'::\\ .\\\\\\---.");
        puts("    jgs/::======::: .:.:::\\ \\\\_)   \\");
        puts("       `""""""""""""""""""`  '-----'");
    }
}

void Keyboard(void)
{
    puts("\n. -------------------------------------------------------------------.  ");
    puts("| [Esc] [F1][F2][F3][F4][F5][F6][F7][F8][F9][F0][F10][F11][F12] o o o|  ");
    puts("|                                                                    |  ");
    puts("| [`][1][2][3][4][5][6][7][8][9][0][-][=][_<_] [I][H][U] [N][/][*][-]|  ");
    puts("| [|-][Q][ ][ ][R][T][Y][ ][I][O][ ][{][}] | | [D][E][D] [7][8][9]|+||  ");
    puts("| [CAP][ ][S][D][F][G][H][J][ ][L][;]['][#]|_|           [4][5][6]|_||  ");
    puts("| [^][\\][Z][X][C][V][B][N][M][,][.][/] [__^__]    [^]    [1][2][3]| ||  ");
    puts("| [c]   [a][________________________][a]   [c] [<][V][>] [ 0  ][.]|_||  ");
    puts("`--------------------------------------------------------------------'  ");
}

void Books(void)
{
    puts("");
    puts("       ///|      ///|");
    puts("      /// |     /// |");
    puts("     |=| ////| |=|  |");
    puts("     |R|//// //|T|  |");
    puts("     |E|===|///|H|  |");
    puts("     |A| N |===|I|  |");
    puts("     |L| O | I |S|  |");
    puts("     | | T | S | | /");
    puts("jgs  |=|===|===|=|/");
    puts("     `````````````");
}

void Bathtub(void)
{
    puts("It is a bathtub.");
    puts("                   _______");
    puts("       _____      |.-----.|");
    puts("      /.---.\\     ||     ||");
    puts("      ||   ||     ||_____||");
    puts("      ||  /__\\    |-_---_-|");
    puts("      ||          =| |=| |=");
    puts("      ||           !!! !!!");
    puts("      ||  ");
    puts("      ||  ");
    puts("      ||  ");
    puts("     _||___.---.____.-\" _...__)");
    puts("    (______|   |_____.-'    /");
    puts("     \\     |___|            |");
    puts("     |     !!!!!            |");
    puts("      \\                    /");
    puts("       '.__            __.'");
    puts("        _\\/``\"\"\"\"\"\"\"``\\/_");
    puts("  jgs  (__(           )__)");
    puts("");
}

void TakeBath(void)
{
    puts("                   _______");
    puts("       _____      |.-----.|");
    puts("      /.---.\\     ||     ||");
    puts("      ||   ||     ||_____||");
    puts("      ||  /__\\    |-_---_-|");
    puts("      ||          =| |=| |=");
    puts("      ||           !!! !!!");
    puts("      ||                .");
    puts("      || o       .  o o_..---.");
    puts("     _||___.---.O_o_.-\" _...__)");
    puts("    (______|   |_____.-'    /");
    puts("     \\     |___|            |");
    puts("     |     !!!!!            |");
    puts("      \\                    /");
    puts("       '.__            __.'");
    puts("  jgs   _\\/``\"\"\"\"\"\"\"``\\/_");
    puts("\nYou just took a warm bath and felt really good.");
}


void Piano(void)
{
    puts("       ________________________");
    puts("     /           ___ ___       '.");
    puts("     |\\ .-------|:::/:::|--------;");
    puts("     | |        |:::|:::|        |");
    puts("     |\\|_  ___ _|:::/:::| __ ____|");
    puts("     |    __  ___\"\"\" \"\"\"_ ____ __`\\");
    puts("     | |\\##\\\\###\\\\##\\\\###\\\\##\\\\### \\");
    puts("     \\ \\ \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \\");
    puts("     |\\ \\||||||||||||||||||||||||||_|");
    puts("     | | ;\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\";\"|");
    puts("     | | |\"\"\"\"\"\".----------.\"\"\"\"\"\"| |");
    puts("     | | |     |\\           \\  |  | |");
    puts("     | | |-----| \\___________\\-|  | |");
    puts(" jgs | | |     | |---------- |  \\ | |");
    puts("     `\\| |     | |         | |   `| |");
    puts("       \\_|       |           |    `\\|");
    puts("");
}


void Planet(void)
{
    puts("");
    puts("                 *       + ");
    puts("           '                  |          ");
    puts("       ()    .-.,=\"``\"=.    - o -          Sometimes you would dream ");
    puts("             '=/_       \\     |          about living on a tiny planet");
    puts("          *   |  '=._    |                  like the little prince do   ");
    puts("               \\     `=./`,        '        and watching the sunset");
    puts("            .   '=.__.=' `='      *      for thirty-three times a day");
    puts("   +                         +");
    puts("        O      *        '       .");
    puts("  jgs                .");

}

void Bed(void)
{
    puts("This is your bed.\n");
    puts("      ()___ ");
    puts("    ()//__/)_________________()");
    puts("    ||(___)//#/_/#/_/#/_/#()/||");
    puts("    ||----|#| |#|_|#|_|#|_|| ||");
    puts(" jgs||____|_|#|_|#|_|#|_|#||/||");
    puts("    ||    |#|_|#|_|#|_|#|_||");
}

void Snowglobe(void)
{
    puts("         ____");
    puts("      .-\" +' \"-.");
    puts("     /.'.'A_'*`.\\");
    puts("    |:.*'/\\-\\. ':|");
    puts("    |:.'.||\"|.'*:|");
    puts("     \\:~^~^~^~^:/");
    puts("      /`-....-'\\");
    puts("     / for Saki \\");
    puts("jgs  `-.,____,.-'");
}


void Coffee(void)
{
    puts("          )  (");
    puts("         (   ) )");
    puts("          ) ( (");
    puts("        _______)_");
    puts("     .-'---------|  ");
    puts("    ( C|/\\/\\/\\/\\/|");
    puts("     '-./\\/\\/\\/\\/|");
    puts("       '_________'");
    puts("        '-------'");
}


void OpenBook(void)
{
    puts("\n      ___________________   ___________________");
    puts("  .-/|  78   ~~**~~      \\ /      ~~**~~   79  |\\-.");
    puts("  ||||                    :                    ||||");
    puts("  |||| \"I've seen things  :  dark near the     ||||");
    puts("  ||||  you people would  :  Tannhauser Gate   ||||");
    puts("  ||||  not believe       :                    ||||");
    puts("  ||||                    :  All those moments ||||");
    puts("  ||||  Attack ships on   :  will be lost      ||||");
    puts("  ||||  fire off the      :  in time           ||||");
    puts("  ||||  shoulder of Orion :                    ||||");
    puts("  ||||                    :  Like... tears     ||||");
    puts("  ||||  I watched C-beams :  in rain\"          |||| ");
    puts("  ||||  glitter in the    :                    ||||");
    puts("  ||||___________________ : ___________________||||");
    puts("  ||/====================\\:/====================\\||\n");
}


void Skyline(void)
{
    puts("");
    puts("                       .|        ,       +");
    puts("             *         | |      ((             *");
    puts("                       |'|       `    ._____");
    puts("         +     ___    |  |   *        |.   |' .---\"|");
    puts("       _    .-'   '-. |  |     .--'|  ||   | _|    |");
    puts("    .-'|  _.|  |    ||   '-__  |   |  |    ||      |");
    puts("    |' | |.    |    ||       | |   |  |    ||      |");
    puts(" ___|  '-'     '    ""       '-'   '-.'    '`      |____");
}


void Train(void)
{
    puts("\n___________   _______________________________________^__");
    puts(" ___   ___ |||  ___   ___   ___    ___ ___  |   __  ,----\\");
    puts("|   | |   |||| |   | |   | |   |  |   |   | |  |  | |_____\\");
    puts("|___| |___|||| |___| |___| |___|  | O | O | |  |  |        \\");
    puts("           |||                    |___|___| |  |__|         )");
    puts("___________|||______________________________|______________/");
    puts("           |||                                        /--------");
    puts("-----------'''---------------------------------------'");
}


void TheEnd(void)
{
    puts("            __..._   _...__");
    puts("       _..-\"      `Y`      \"-._");
    puts("       \\           |           /");
    puts("       \\\\    THE   |   END    //");
    puts("       \\\\\\         |         ///");
    puts("        \\\\\\ _..---.|.---.._ ///");
    puts("         \\\\`_..---.Y.---.._`//");
    puts("          '`               `'");
}























 
























 

    
    
    
    
    
    
    
    