#include<stdio.h>
#include<string.h>
char hex[100];

char rhex[30];



char dec_to_hex(int a)
{
    int len,i=0,j=0;
    int rem,rem1[100];
     while (a!=0)
    {
        rem=a%16;
        a=a/16;
        rem1[i]=rem;

    //    printf("\n rem is : %d",rem1[i]);
        i++;
    }
   len=i;
   for(i=len-1;i>=0;i--)
   {
     switch(rem1[i])
        {
            case 10:
              hex[j]='A';
              break;
            case 11:
              hex[j]='B';
              break;
            case 12:
              hex[j]='C';
              break;
            case 13:
              hex[j]='D';
              break;
            case 14:
              hex[j]='E';
              break;
            case 15:
              hex[j]='F';
              break;
            default:
              hex[j]=rem1[i]+'0';


        }
         //printf(" hex is : %c",hex[j]);
    j++;
   }

}
void main()
{
 FILE *fp1;
 FILE *fp2;
 char ch;

 int rem,n,results,bc,len,i;
 int byte_count=0;
 fp1 = fopen("one.txt", "r");
 fp2 = fopen("two.txt", "w");
 while ((ch = fgetc(fp1)) != EOF)
{

byte_count++;
 //This is outside the else condition above
}

 fputs("40 ",fp2);
 dec_to_hex(byte_count);
 fputs(hex,fp2);
 fputs(" ",fp2);
 fclose(fp1);
// fclose(fp2);
 fp1 = fopen("one.txt", "r");
 //fp2 = fopen("two.txt", "w");

 while( (ch = getc(fp1) ) != EOF)
 {
  n=(int)ch;
  dec_to_hex(n);


  results=fputs(hex,fp2);
  fputs(" ",fp2);

 // ++byte_count;
 }

 //dec_to_hex(byte_count);
 //bc=fputs(hex,fp2);


  printf("\n byte count : %d",byte_count);
fputs(" 04",fp2);
 //fputs(byte_count,fp2);
 fclose(fp1);
 fclose(fp2);
}
