/* 
FILTER.C 
An ANSI C implementation of MATLAB FILTER.M (built-in)
Written by Chen Yangquan <elecyq@nus.edu.sg>
1998-11-13
Recursive and real-time version.
*/

#include<stdio.h>
#define ORDER 3
#define NP 1001


main()
{
 FILE *fp;
 float x[NP],y[NP],a[ORDER+1],b[ORDER+1];
 float in_buffer[ORDER+1],out_buffer[ORDER];
 float xin,xout;
 int i,j;
 int SP;

/* printf("hello world \n"); */

if((fp=fopen("acc1.dat","r"))!=NULL)
{
        for (i=0;i<NP;i++)
        {
         fscanf(fp,"%f",&x[i]);
/*         printf("%f\n",x[i]); */
        }
}
else
{
        printf("\n file not found! \n");
        exit(-1);
}
close(fp);

/*  test coef from
 [b,a]=butter(3,30/500);  in MATLAB
*/
b[0]=0.0007;
b[1]=0.0021;
b[2]=0.0021;
b[3]=0.0007;
a[0]=1.0000;
a[1]=-2.6236;
a[2]=2.3147;
a[3]=-0.6855;


/* a major revision for real-time recuesive use */
/* in-buffer; out_buffer :
        can be used to specify the initial conditions.
        default 0
http://www.geocities.com/Paris/Lights/3811
*/
for (i=0;i<ORDER;i++) {in_buffer[i]=0.;out_buffer[i]=0.;}
in_buffer[ORDER]=0.;

for (SP=0;SP<NP;SP++)
{
        xin=x[SP];
        /* move buffer */
        for (i=0;i<ORDER;i++) {in_buffer[ORDER-i]=in_buffer[ORDER-i-1];}
        in_buffer[0]=xin;

        xout=0.0;
        for (j=0;j<ORDER+1;j++)
        xout=xout+b[j]*in_buffer[j];
        for (j=0;j<ORDER;j++)
        xout=xout-a[j+1]*out_buffer[j];

        y[SP]=xout;
        for (i=0;i<ORDER-1;i++) {out_buffer[ORDER-i-1]=out_buffer[ORDER-i-2];}
        out_buffer[0]=xout;

} /* end of SP loop */



if((fp=fopen("acc10.dat","w+"))!=NULL)
{
        for (i=0;i<NP;i++)
        {
         fprintf(fp,"%f\n",y[i]);
        }
}
else
{
        printf("\n file cannot be created! \n");
        exit(-1);
}
close(fp);
}  

