#ifndef LIBRARY_H_
#define LIBRARY_H_

// io.c
extern void Type(const char * p);
extern void TypeSlower(const char * p);
extern int getNewline(void);
extern int getInput(void);
extern char getYorN(void);
extern char getABC(void);
extern int getPassword(void);
extern int executePhrase(void);
extern int readFile(void);
extern int readLetter(void);

// function.c
extern void Look(const char *noun);
extern void Go(const char *noun);
extern void Examine(const char *noun);
extern void Talk(const char *noun);
extern void Item(void);
extern void Direction(void);

typedef struct objs {
   struct objs     *location;
   const char      *tag;
   const char      *description;
   const char      *sidenote;
}OBJECT;

extern OBJECT object[];
extern OBJECT *parseObject(const char *noun);
extern int listObjectsAtLocation(OBJECT *location);
extern void moveObject(const char *noun, OBJECT *from, OBJECT *to);

#define home       (object + 1)
#define room       (object + 2)
#define bathroom   (object + 3)
#define balcony    (object + 4)
#define kitchen    (object + 5)
#define livingroom (object + 6)
#define door       (object + 7)
#define desk       (object + 27)

#define street     (object + 8)
#define metro      (object + 9)
#define grocery    (object + 10)
#define riverside  (object + 11)

#define downtown   (object + 12)
#define north      (object + 13)
#define south      (object + 14)
#define east       (object + 15)
#define west       (object + 16)
#define Metro      (object + 17)
#define cafe       (object + 17)
#define birdroom   (object + 18)
#define seating    (object + 19)
#define coffee     (object + 20)
#define Exit       (object + 21)

#define player     (object + 0)
#define endOfObjs  (object + 42)
#define SYSTEM      NULL
#define bool        _Bool
#define true       1
#define false      0
#define EXIT_GAME  1

// Some bool values
int loop;
bool landury;
bool gift;
bool VisitingSaki;
bool EddieIsSleeping;
bool headphone;
bool EddieIsHere;
bool getGrocery;
bool exercise;
bool plotComplete;
bool CharlieIsSleeping;
bool bedtime;
bool tooLate;
bool SecretFileFound;

// Plots (main.c)
extern void Reset(void);
extern void EddiePlot1(void);
extern void RiversidePlot(void);
extern void NotebookPlot(void);
extern void GroceryPlot(void);
extern void AkihitoPlot(void);
extern void MetroPlot1(void);
extern void DowntownPlot(void);
extern void CafePlot(void);
extern void BirdroomPlot(void);
extern void CoffeeBarPlot(void);
extern void ReadingPlot(void);
extern void Story1(void);
extern void ComputerPlot(void);
extern void EndingPart1(void);
extern void EndingPart2(void);

// art.c
extern void Title(void);
extern void ShowFood(void);
extern void Cart(void);
extern void Laundry(void);
extern void NoLaundry(void);
extern void Clothes(void);
extern void Books(void);
extern void Computer(void);
extern void ComputerOn(void);
extern void Keyboard(void);
extern void Piano(void);
extern void Eye(void);
extern void Bed(void);
extern void Bathtub(void);
extern void TakeBath(void);
extern void Snowglobe(void);
extern void Coffee(void);
extern void Planet(void);
extern void Skyline(void);
extern void Train(void);
extern void OpenBook(void);
extern void TheEnd(void);

#endif