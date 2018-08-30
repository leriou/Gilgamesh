#include <stdio.h>
 
int main()
{

//     FILE *fp = NULL;
 
//    fp = fopen("test.txt", "w+");
//    fprintf(fp, "This is testing for fprintf...\n");
//    fputs("This is testing for fputs...\n", fp);
//    fclose(fp);

   char buff[200];
 
   FILE *fp = fopen("local.log", "r");
//    fscanf(fp, "%s", buff);
//    printf("1: %s\n", buff );
 
//    fgets(buff, 255, (FILE*)fp);
//    printf("2: %s\n", buff );
   
   fgets(buff, 255, (FILE*)fp);
   printf("3: %s\n", buff );
   fclose(fp);
 
}