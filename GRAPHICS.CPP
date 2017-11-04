#include<bios.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
#include<process.h>
#include<conio.h>

void wait()
{
for(long int i=0;i<99999999;i++) ;
}
/***********************************************************/
void waitp(float f)
{
for(long int i=0;i<(f*9999999);i++) ;
}
/***********************************************************/

void cbab()
{
clrscr();
cout<<"Created by   AMIT BHOLA";
for(long int w=0;w<99999999;w++) ;
}
/***********************************************************/
void hline()
{
for(int i=0;i<80;i++)
printf("Ä");
return;
}
/***********************************************************/
void hlinec(char c)
{
for(int i=0;i<80;i++)
printf("%c",c);
return;
}
/***********************************************************/
void hlinep(int n)
{
for(int i=0;i<n;i++)
printf("Ä");
return;
}
/***********************************************************/
void hlinep(int n,char c)
{
for(int i=0;i<n;i++)
printf("%c",c);
return;
}
/***********************************************************/
void bhline()
{
for(int i=0;i<80;i++)
printf("Û");
return;
}
/***********************************************************/
void bhlinep(int n)
{
for(int i=0;i<n;i++)
printf("Û");
return;
}
/***********************************************************/
void collineppp(char ch,int len,int col)
{
 textcolor(col);
 for(int i=0;i<len;i++) putch(ch);
 return;
}
/***********************************************************/
void fallvert(char text[])
{
int i,j,t,m,l,p,s;
long k;

_setcursortype(_NOCURSOR);

clrscr();
l=strlen(text);
s=37-l/2;  t=s;
for(m=0;m<l;m++,t++)
{   if(m!=0){gotoxy(s,10);for(p=0;p<m;p++)
		{
		printf("%c",text[p]);
		} }
for(i=1;i<=80;i++)
{
for(j=1;j<=25;j++)
{
if(i==t){ if(j<10){
		gotoxy(i,j);
		printf("%c",text[m]);
		for(k=1;k<=999999;k++);
		clrscr();
		gotoxy(s,10);
		for(p=0;p<m;p++)
		{
		printf("%c",text[p]);
		}
		}
	  else if(j==10){
		gotoxy(i,j);
		printf("%c",text[m]);
		for(k=1;k<=999999;k++);
		clrscr();
		gotoxy(s,10);
		for(p=0;p<m;p++)
		{
		printf("%c",text[p]);
		}
		}
	 else if(j>10){
	 gotoxy(s,10);
	 for(p=0;p<m;p++)
		{
		printf("%c",text[p]);
		}
	 gotoxy(i,10);
	 printf("%c",text[m]);
	 gotoxy(i,j);
	 printf("%c",text[m]);
	 for(k=1;k<=999999;k++);
	 clrscr();
	 }
}
}
}
gotoxy(s,10);
for(p=0;p<=m;p++)
		{
		printf("%c",text[p]);
		}
}
//getch();
_setcursortype(_NORMALCURSOR);
return;
}
/***********************************************************************/
//window
const int LEFT=25;
const int TOP=6;
const int RIGHT=55;
const int BOTTOM=18;
const int LEN=500;

class win
  {
   private:
       int left,top,right,bottom;
       char str[LEN];
       int color;
   public:
     win()
       {
	left=LEFT;
	top=TOP;
	right=RIGHT;
	bottom=BOTTOM;
	color=WHITE;
	}

     win(int l,int t,int r,int b,int c)
       { left=l;top=t;right=r;bottom=b;color=c;}

     void text(char s[])
      { strcpy(str,s);}

     void draw();
     void erase()
	{
	 window(left,top,right,bottom);
	 clrscr();
	 }
  };//class ends

void win::draw()
 {
  erase();
  window(left,top,right,bottom+1);
  int width=right-left+1;
  int height=bottom-top+1;
 textcolor(color);
 for(int j=1;j<=width;j++)
   {
    gotoxy(j,1);       putch(char(205));
    gotoxy(j,height);   putch(char(205));
   }
 for(j=1;j<=height;j++)
   {
     gotoxy(1,j);       putch(char(186));
    gotoxy(width,j);   putch(char(186));
   }
   gotoxy(1,1);        putch(char(201));
   gotoxy(width,1);        putch(char(187));
   gotoxy(1,height);        putch(char(200));
   gotoxy(width,height);        putch(char(188));

    window(left+2,top+1,right-1,bottom-1);
    cputs(str);
    textcolor(WHITE);
 }
/************************************************************************/
//table

//table(indentation,2D array[first dim.=no.of columns][max no. of rows=80],
//        no. of columns,no. of rows,array of pointers to colm. headings)
//  see example:see INTRRERPOLN,TABLEUSD
void table(int ind,float a[][80],int cols,int rows,char *c[6])
{

int in,i,j,k,fieldwidth=11; //fieldwidth is one more than 10 ( in %10.3g )
  for(in=1;in<=ind;in++)    //in printdata and printheading line
    putch(' ');

    putch('É');
  for(i=1;i<=fieldwidth*cols;i++)
  {
    if(i%fieldwidth==0)
       {
	if(i!=fieldwidth*cols) putch('Ë');
	else          putch('»');
       }
    else putch('Í');
  }

    printf("\n");

     for(in=1;in<=ind;in++)
    putch(' ');  putch('º');

    for(k=0;k<cols;k++)
    {
	 printf("%10s",*(c+k));             //printheading
       if(k!=fieldwidth*cols) putch('º');
	else          putch('¹');

    }

	      printf("\n");
     for(in=1;in<=ind;in++)
    putch(' ');  putch('Ì');

     for(k=1;k<=fieldwidth*cols;k++)
    {
       if(k%fieldwidth==0)
       {
	if(k!=fieldwidth*cols) putch('Î');
	else          putch('¹');
       }
    else putch('Í');

    }

	printf("\n");

 for( i=0;i<rows;i++)
  { for(in=1;in<=ind;in++)
    putch(' ');  putch('º');
   for( j=0;j<cols;j++)
   {
    printf("%10.3gº",a[j][i]);           //printdata
   }
   printf("\n");
 }


   for(in=1;in<=ind;in++)
    putch(' ');

    putch('È');
    for(i=1;i<=fieldwidth*cols;i++)
  {
    if(i%fieldwidth==0)
       {
	if(i!=fieldwidth*cols) putch('Ê');
	else          putch('¼');
       }

    else putch('Í');
  }

return;
}
/************************************************************************/
int getkey(void)
 {
  int key,lo,hi;
  key=bioskey(0);
  lo=key & 0x00FF;
  hi=(key & 0xFF00)>>8;
  return((lo==0)?hi+256:lo);
 }

/************************************************************************/
void writescreen( char name[])
{
   int i;
   char buffer[4000];

   FILE *fp;

   fp=fopen(name,"a");

   gettext(1, 1, 80, 25, buffer);


 char buffer2[4000];
 int j=0;

    for(i=0;i<4000;i++)
     {
      if(int(buffer[i])==15);
      else
       {
	buffer2[j++]=buffer[i];
       }
     }

  for(i=0;i<2000;i++)
   {
    fprintf(fp,"%c",buffer2[i]);
    if( (i+1)%80==0 ) fprintf(fp,"\n");
   }


  fclose(fp);
 return;

}
/**************************************************************************/
void hscroll(char a[], int rw, int cl, int ln, int rpt, float spd)
{
 int i,j,k,sl,again;
 char ch,b[10000];

 sl=strlen(a);
 again=1;

while(again)
{
 _setcursortype(_NOCURSOR);

 for(i=0;i<10000;i++) b[i]=' ';

 b[ln]='\0';
 strcat(b,a);

 sl=strlen(b);

 for(i=0;i<sl;i++)
  {
   gotoxy(rw,cl);
   for(j=0;j<ln;j++) cout<<" ";
   gotoxy(rw,cl);
   for(j=i,k=0;k<ln;j++,k++)
    cout<<b[j];
   waitp(spd);

  if(kbhit())
   {
    ch=getch();
    if(ch=='`') exit(0);
    else if(ch=='+') spd=spd*0.8;
    else if(ch=='-') spd=spd*1.2;
    else getch();
   }
   clrscr();
  }

 _setcursortype(_NORMALCURSOR);
 again=0;

 if(rpt) again=1;
}
 return;
}
/**************************************************************************/
//////////  IN HSCROLL2, DIFFERENCE IS THAT PRESS ANY KEY TO EXIT
/////////   no facility for pause and resume, also no speed control (+/-)
/////////   also whole 80*25 screen is not cleared after each frame

void hscroll2(char a[], int rw, int cl, int ln, int rpt, float spd)
{
 int i,j,k,sl,again;
 char ch,b[10000];

 sl=strlen(a);
 again=1;

 window(cl,rw,cl+ln,rw);

while(again)
{
 _setcursortype(_NOCURSOR);

 for(i=0;i<10000;i++) b[i]=' ';

 b[ln]='\0';
 strcat(b,a);

 sl=strlen(b);

 for(i=0;i<sl;i++)
  {
   gotoxy(rw,cl);
   for(j=0;j<ln;j++) cprintf(" ");
   gotoxy(rw,cl);
   for(j=i,k=0;k<ln;j++,k++)
    cprintf("%c",b[j]);
   waitp(spd);

  if(kbhit())
   {
    window(1,1,80,25);
    return;
   }
   clrscr();
  }

 _setcursortype(_NORMALCURSOR);
 again=0;

 if(rpt) again=1;
}
 return;
}
