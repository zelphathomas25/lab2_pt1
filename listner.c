#include <stdio.h>
#include <stdlib.h> /* for atoi() */
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define fileNameLength  32
#define dateTimeLength  32
#define fileLineLength  256
#define MAX_LINES_PER_PAGE  40

FILE *source_file, *outputFile;
char *moder = "r";
char *modew = "w";
char source_name[fileNameLength];
char dateAndTime[dateTimeLength];

time_t now;
int line_number = 0;
//time(&now);
//printf("%s",ctime(&now));


void init_lister(char fileN[] );
bool get_source_line();
void print_line(char print_buff[]);
void print_page_header();


int main(int argc, char *argv[]){
bool continueReadingFile = true;

     if (argc <2 ){
          printf("input is: %d",argc);
          return 0;
     }
init_lister(argv[1]);

while ( continueReadingFile){
  continueReadingFile = get_source_line();
}
printf("\nend reading file !\nTotal lines: %d ",line_number);

return 0;
}

void init_lister(char fileN[] ){

strcpy(source_name,fileN); // destination, source
source_file = fopen(source_name, moder);
if (source_file == NULL) {
  printf("Can't open input file %s!\n", source_name);
  exit(1);
}
time(&now);
sprintf(dateAndTime, "%s", ctime(&now));
printf("input file name is : %s  time is: %s", source_name, dateAndTime );

}

bool get_source_line(){

bool value = false;
char source_buffer[fileLineLength];
char print_buffer[fileLineLength];
if( fgets (source_buffer, fileLineLength, source_file)!=NULL ) {
      /* writing content to stdout */
      //puts(source_buffer);
      value = true;
      line_number += 1;
      sprintf(print_buffer,"%d: %s",line_number,source_buffer);
     print_line(print_buffer);
   }
//value = false;
return value;
}
void print_line(char print_buff[]){
    static int  line_count =0;
    line_count +=1;
    if ((line_count % MAX_LINES_PER_PAGE) == 1)
    {print_page_header(); }

    printf("%s",print_buff);
}
void print_page_header(){
    printf("**************************************\n");
    printf("************* Page Header  ***********\n");
    printf("*************              ***********\n")     ;
    printf("**************************************\n");
}
