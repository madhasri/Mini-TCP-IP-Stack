#include<stdio.h>
int rem[100]; int bin[100][100]; char d[100];

void bin_dec(  int bin[])
{
     int i,k,c=0;
   for( k=3 ; k<=15;k=k+4)
   {
        int deci=0;
        int j=1;
        int i = k;

    while(i>=k-3){
         if( bin[i] == 0)
           {

            j=j*2;
            i--;
    }
         else

         {deci=deci+bin[i]*j;
        j=j*2;
        i--;
         }

    }
 d[c++] = deci;
 printf(" %d" ,deci );

}
}

int xoro(int a , int b)
{

    if( (a==1 && b==1) || ( a==0 && b==0))
    return 0;
    else
    return 1;
}

void dec_bin( int num)   // Function Definition
{


 int i=0,length=0;
while(num>0)
 {
 rem[i]=num%2;
 num=num/2;
 i++;
 length++;
 }
printf("\n Binary number : ");
     for(i=3;i>=0;i--)
             printf("%d",rem[i]);
}

main()
{
    //int c = 0, t=0;
    char ch;
    int xor_result[100];
    int sum[100];
    int i,j,ctr=-1,k;
    FILE *f,*fp3;
    for( i=0;i<16;i++)
   sum[i] = 0;
    f = fopen( "trans_out.txt" , "r");

    for( j=0 ; j<40 ; j= j+4)
    {
        ctr++;


     int c=0, t=0;
    while(   c < 4  && (ch = getc(f)) != EOF  )
    {
        //printf("%%%%");
        printf(" \n %c " , ch);
        if( ch == 'a') dec_bin(10);
        else if( ch == 'b') dec_bin(11);
        else if( ch == 'c') dec_bin(12);
        else if( ch == 'd') dec_bin(13);
        else if( ch == 'e') dec_bin(14);
        else if( ch == 'f') dec_bin(15);
        else dec_bin(ch);
        printf("\n");
        /*for( i= 0 ;i<4 ;i++)
        printf("%d " , rem[i]);*/
        for( i= 0 ;i<4 ;i++)
            bin[ctr][i + t] = rem[3-i];
            t = t+4;
        c++;
    }

    //printf("\n");
    for(i=0;i<16;i++)
        printf("%d" , bin[ctr][i]);


}
for(i=0;i<=ctr;i++)
{
    printf("\n ");

    for(j=0;j<16;j++)
    printf("%d " , bin[i][j]);
}
printf("\n");
  printf(" ctr = %d" , ctr);
     fclose(f);

     for(i=15;i>=0; i--)
     {
         xor_result[i] = xoro(bin[0][i] , bin[1][i]);

     }

     for( j=2 ; j<=ctr ;j = j+1)
    {

        for( i= 15 ;i>=0 ; i--)
     {
          //printf("\n %d" , bin[j][i]);
      xor_result[i] = xoro( xor_result[i] , bin[j][i]);

      /*if( sum[j] == 2)
       {

        sum[j] = 0;
        if( j!=0)
        //printf("\n  j = %d" , j);
        sum[j-1] = 1;
       }
       printf("\n %d  %d" , sum[j] , bin[i][j]);
       //printf("\n");
       //printf("\n %d" , sum[j]);


     }
     printf("\n");
       for( k=0;k<16;k++)


     printf("%d " , sum[k]);
    }
     printf("\n");
     for( k=0;k<16;k++)

     printf("%d " , sum[k]);*/

}
printf("\n Result :");
for( i= 0 ;i<16 ; i++)
    printf("%d " , xor_result[i]);
}
printf("\n Checksum:");
for( i= 0 ;i<16 ; i++)
    printf("%d " , xor_result[i]);

    bin_dec( xor_result);
    //fseek()
    f = fopen( "trans_out.txt" , "r");
    fp3 = fopen( "ip_in.txt" , "w");
    int cnt = 1;
    while( cnt <= 20)
    {
        ch = getc(f);
         //printf(" %c" , ch);
        fputc(ch,fp3);
        cnt++;
    }
    for(i=0;i<4;i++)
    {
        //printf(" %d" , d[i]);

        fprintf(fp3 , "%d" , d[i]);

    }

    fseek(f , 24 , SEEK_SET);

    while( ( ch = fgetc(f) ) != EOF )
    {
        fputc( ch , fp3);
    }



    fclose(f);
    fclose(fp3);


}
