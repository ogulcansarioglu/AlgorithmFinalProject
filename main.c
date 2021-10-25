#include <stdio.h>
#include <string.h>
#define SIZE 42

typedef struct module
{
  char first[13];
  char sur[13];
  char course[13];
  char type[13];
 } module;

int j = 0; 

void mergeAllStructs(struct module *course, struct module *all_students);

void searchFullTime(struct module *all); 

void sortBySurname(struct module *all);

void binarySearchBySurname(struct module *all, char x[]); 

int main(void) {
 
  module allStudent[52];
  module module1[13] = {{"David", "Bowie", "DT265A", "Part"}, {"Jane", "Doe", "DT265A", "Part"}, {"John", "Ericson", "DT265A", "Part"}, {"Eliott", "Smith", "DT265A", "Part"}, {"Nick", "Drake", "DT265A", "Part"}, {"Dallas", "Green", "DT265A", "Part"}, {"Lebron", "James", "DT265A", "Part"}, {"Anthony", "Davis", "DT265A", "Part"}, {"Douglas", "Adams", "DT265A", "Part"}, {"Terry", "Pratchet", "DT265A", "Part"}, {"Stanislav", "Lem", "DT265A", "Part"}, {"Ted", "Chiang", "DT265A", "Part"}, {"Haruki", "Murakami", "DT265A", "Part"}};
  module module2[9] = {{"Nick", "Young", "DT265C", "Part"}, {"Albert", "Einstein", "DT265C", "Part"}, {"Hedde", "Gray", "DT265C", "Part"}, {"Laura", "Silver", "DT265C", "Part"}, {"Jonathan", "Isaac", "DT265C", "Part"}, {"Kevin", "Journey", "DT265C", "Part"}, {"Jim", "Morrisson", "DT265C", "Part"}, {"Danny", "House", "DT265C", "Part"}, {"Eve", "Orwell", "DT265C", "Part"}};
  module module3[14] = {{"Luke", "Walton", "DT265B", "Full"}, {"Anthony", "Morris", "DT265B", "Full"}, {"Avril", "Lawrance", "DT265B", "Full"}, {"Dennis", "Salvage", "DT265B", "Full"}, {"Dave", "Grohl", "DT265B", "Full"}, {"Alice", "Wonderland", "DT265B", "Full"}, {"Marta", "Lambring", "DT265B", "Full"}, {"Andrea", "Lawful", "DT265B", "Full"}, {"Tommy", "Old", "DT265B", "Full"}, {"Justin", "Vladamir", "DT265B", "Full"}, {"Anton", "Blueberry", "DT265B", "Full"}, {"Barry", "Walks", "DT265B", "Full"}, {"Tim", "Sunflowers", "DT265B", "Full"}, {"Becky", "Andre", "DT265B", "Full"}};
  module module4[6] = {{"Branden", "Snail", "DT8900", "Full"}, {"Mayford", "Holmes", "DT8900", "Full"}, {"Simone", "Giertz", "DT8900", "Full"}, {"Rory", "Gilmore", "DT8900", "Full"}, {"London", "Tewers", "DT8900", "Full"}, {"Nick", "Offerman", "DT8900", "Full"}};

  mergeAllStructs(module1, allStudent);
  mergeAllStructs(module2, allStudent);
  mergeAllStructs(module3, allStudent);
  mergeAllStructs(module4, allStudent);
  sortBySurname(allStudent);

  //added now for the demonstration purposes
  for (int i = 0 ; i < SIZE; i++) 
  {
      
      printf("%s", allStudent[i].first); 
      printf("%s\n", allStudent[i].sur); 

  }

  

  searchFullTime(allStudent); 
  binarySearchBySurname(allStudent,"Orwell"); 
  
  return 0;
}

//this function merges all the structs into one.

void mergeAllStructs(struct module *course, struct module *all_students) 
{


int size = sizeof(course->first)/sizeof(course->first[0]); 


char temp[20];

int i;

//copies all the information to their corresponding space in allstudent struct.
for (i = 0; i < size; i++) 
{
  strcpy(temp, course[i].first); 
  strcpy(all_students[j].first,temp);
 
  strcpy(temp,course[i].sur);
  strcpy(all_students[j].sur,temp);
  
  strcpy(temp,course[i].course);
  strcpy(all_students[j].course,temp);
 
  strcpy(temp,course[i].type);
  strcpy(all_students[j++].type,temp);

  
}



}
//This algorithm sort the all data by surname in the main struct. It's running time is O(n^2).
void sortBySurname(struct module *all) 
{
  int size = sizeof(all->first)/sizeof(all->first[0]);
  char temp[size]; 

  //Compares strings by using their ASCII value and sort them accordingly.

  for(int i=0; i < size; i++)
  {
    for(int j = i + 1; j < size; j++)
    {
      if(strcmp(all[i].sur,all[j].sur) > 0)
      {
        strcpy(temp, all[i].first);
        strcpy(all[i].first, all[j].first);
        strcpy(all[j].first, temp);

        strcpy(temp, all[i].sur);
        strcpy(all[i].sur, all[j].sur);
        strcpy(all[j].sur, temp);

        strcpy(temp, all[i].course);
        strcpy(all[i].course, all[j].course);
        strcpy(all[j].course, temp);

        
        strcpy(temp, all[i].type);
        strcpy(all[i].type, all[j].type);
        strcpy(all[j].type, temp);
      }
    }
  }
}

//Search for the full time students in the main struct. It prints all the full times students. It's running time is O(n).

void searchFullTime(struct module *all) 
{

int size = sizeof(all->first)/sizeof(all->first[0]); 

printf("All full times students are as follows: \n");

for (int i = 0; i < size; i++) 
{

    if(strcmp(all[i].type,"Half") != 0)
    
    {

      printf("%s", all[i].first); 
      printf("%s\n", all[i].sur); 

    }

}

}

//This algorithm utulitizes the binary search to find a particular student and display her/his information. The running time is O(log(N)).
void binarySearchBySurname(struct module *all, char x[]) {
   int left = 0;
   int right = SIZE;
   int isFound = 0;
   while (left <= right) {
      int middle = left + (right - left) / 2;
      int res;
      if (strcmp(x, all[middle].sur) == 0)
        res = 0;
      if (res == 0)
        printf("\nThe student is %s %s and study %s %s Time", all[middle].first, all[middle].sur, all[middle].course, all[middle].type);
        isFound = 1; 
        break; 
      if (res > 0)
        left = middle + 1;
      else
        right = middle - 1;
   }
   if (isFound == 0) {
     printf("\nThe Student cannot be found.");
   }
}





