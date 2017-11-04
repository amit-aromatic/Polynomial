#include <conio.h>
#include <process.h>
#include <stdio.h>
#include <iostream.h>
#include"graphics.cpp"

void main()
{
 char choice;

 inp_again:

 clrscr();
 cout<<"POLYNOMIAL OPERATIONS\n";
 hlinec('~');
 cout<<"Press 1 : To divide a polynomial in x by a factor (x-c)      c: a constant\n"
     <<"      2 : To express a polynomial in x in terms of (x-c)     c: a constant\n"
     <<"      3 : To express a polynomial in (x-c) in terms of x     c: a constant\n\n"
     <<"      4 : To express a polynomial in x in terms of [x] \n          (ie. in factorial form)\n\n"
     <<"      5 : To express a polynomial in [x] in terms of x \n          (ie. from 'factorial form' to standard form)\n\n"
     <<"      6 : To evaluate a polynomial in x at c                 c: a constant\n"
     <<"      0 : EXIT\n";

 choice=getche();

 switch(choice)
 {
  case '1': //////////////////////////////////////////////////////////////

  { // NOTE THE IMPORTANCE OF THESE OUTERMOST ENCLOSING BRACES IN CASE 1,2
    // ETC. THESE MAKE ALL VARIABLES USED IN THE RESPECTIVE CASES AS
    // LOCAL TO THOSE CASES ONLY AND HENCE THERE ARE NO ERRORS OF MULTIPLE
    // DECLARATION

   clrscr();
   int degree;
   float coeff[80],c,coeff_quo[80];

   for(int i=0;i<80;i++)
    {
     coeff[i]=0;
     coeff_quo[i]=0;
    }
       //---------------------- input
   cout<<"Enter degree of polynomial            : ";
   cin>>degree;

   cout<<"Enter the constant c in divisor (x-c) : ";
   cin>>c;

   cout<<"\nEnter the polynomial ( dividend ) :\n";

  for(i=0;i<=degree;i++)
    {
     cout<<"Coefficient of x^"<<degree-i<<" : ";
     cin>>coeff[i];
    }

      //---------------------- processing

  for(i=0;i<=degree;i++)
    {
     if(i==0) coeff_quo[i]=coeff[i];
     else
      {
       float temp=c*coeff_quo[i-1];
       coeff_quo[i]=coeff[i]+temp;
      }
    }
      //---------------------- output
  cout<<"\nThe quotient is :-\n\nterm  : ";

   for(i=0;i<degree;i++)
    {
     printf("x%d     ",degree-i-1);
    }

    cout<<endl<<"coeff : ";

   for(i=0;i<degree;i++)
    {
     printf("%g     ",coeff_quo[i]);
    }
  cout<<"\n\nAnd the remainder is : "<<coeff_quo[degree];

  getch();
  break;
 }

  case '2':
  case '3'://////////////////////////////////////////////////////////////

  { // NOTE THE IMPORTANCE OF THESE OUTERMOST ENCLOSING BRACES IN CASE 1,2
    // ETC. THESE MAKE ALL VARIABLES USED IN THE RESPECTIVE CASES AS
    // LOCAL TO THOSE CASES ONLY AND HENCE THERE ARE NO ERRORS OF MULTIPLE
    // DECLARATION
   clrscr();
   int degree;
   float coeff[80],c,coeff_quo[80],ans[80];

   for(int i=0;i<80;i++)
    {
     coeff[i]=0;
     coeff_quo[i]=0;
    }

     //---------------------- input

   cout<<"Enter degree of polynomial    : ";
   cin>>degree;

   cout<<"Enter the constant c in (x-c) : ";
   cin>>c;

   cout<<"\nEnter the polynomial :\n";

  for(i=0;i<=degree;i++)
    {
     if(choice=='2') cout<<"Coefficient of x^"<<degree-i<<" : ";
     else
      {
       if(c>=0) cout<<"Coefficient of (x-"<<c<<")^"<<degree-i<<"  :    ";
       else     cout<<"Coefficient of (x+"<<-1*c<<")^"<<degree-i<<"  :    ";
      }

     cin>>coeff[i];
    }

    //---------------------- processing

  if(choice=='3') c=-1*c;

  int count=degree;

  for(int a=0;a<=count;a++)
  {
   for(i=0;i<=degree;i++)
    {
     if(i==0) coeff_quo[i]=coeff[i];
     else
      {
       float temp=c*coeff_quo[i-1];
       coeff_quo[i]=coeff[i]+temp;
      }
    }

    ans[count-a]=coeff_quo[degree];

    for(i=0;i<degree;i++)
     {
      coeff[i]=coeff_quo[i];
     }
     degree--;
   }

    //---------------------- output

  degree=count;

  cout<<"\nThe transformed polynomial is :-\n\nterm  : ";

  if(choice=='2')
   {
    for(i=0;i<=degree;i++)
     {
      if(c>=0) cout<<"(x-"<<c<<")^"<<degree-i<<"      ";
      else     cout<<"(x+"<<-1*c<<")^"<<degree-i<<"      ";
     }
   }
  else
   {
    for(i=0;i<=degree;i++)
     {
      cout<<"x^"<<degree-i<<"          ";
     }
   }
    cout<<endl<<"coeff : ";

   for(i=0;i<=degree;i++)
    {
     printf("%g           ",ans[i]);
    }

  getch();
  break;
  }

 case '4'://////////////////////////////////////////////////////////////

  { // NOTE THE IMPORTANCE OF THESE OUTERMOST ENCLOSING BRACES IN CASE 1,2
    // ETC. THESE MAKE ALL VARIABLES USED IN THE RESPECTIVE CASES AS
    // LOCAL TO THOSE CASES ONLY AND HENCE THERE ARE NO ERRORS OF MULTIPLE
    // DECLARATION
   clrscr();
   int degree;
   float coeff[80],c,coeff_quo[80],ans[80];

   for(int i=0;i<80;i++)
    {
     coeff[i]=0;
     coeff_quo[i]=0;
    }

     //---------------------- input

   cout<<"Enter degree of polynomial    : ";
   cin>>degree;

   cout<<"\nEnter the polynomial :\n";

  for(i=0;i<=degree;i++)
    {
     cout<<"Coefficient of x^"<<degree-i<<" : ";
     cin>>coeff[i];
    }

    //---------------------- processing

  c=1;

  int count=degree-1;
  ans[degree]=coeff[degree];

  for(int a=0;a<=count;a++)
  {
   for(i=0;i<degree;i++)
    {
     if(i==0) coeff_quo[i]=coeff[i];
     else
      {
       float temp=c*coeff_quo[i-1];
       coeff_quo[i]=coeff[i]+temp;
      }
    }

    ans[count-a]=coeff_quo[degree-1];

    for(i=0;i<degree;i++)
     {
      coeff[i]=coeff_quo[i];
     }
     degree--;
     c++;
   }

    //---------------------- output

  degree=count+1;

  cout<<"\nThe transformed polynomial is :-\n\nterm  : ";

    for(i=0;i<=degree;i++)
     {
      cout<<"[x]^"<<degree-i<<"      ";
     }

    cout<<endl<<"coeff : ";

   for(i=0;i<=degree;i++)
    {
     printf("%g           ",ans[i]);
    }

  getch();
  break;
  }

 case '5'://////////////////////////////////////////////////////////////

  { // NOTE THE IMPORTANCE OF THESE OUTERMOST ENCLOSING BRACES IN CASE 1,2
    // ETC. THESE MAKE ALL VARIABLES USED IN THE RESPECTIVE CASES AS
    // LOCAL TO THOSE CASES ONLY AND HENCE THERE ARE NO ERRORS OF MULTIPLE
    // DECLARATION
   clrscr();
   int degree;
   float coeff[80],c,coeff_quo[80],ans[80];

   for(int i=0;i<80;i++)
    {
     coeff[i]=0;
     coeff_quo[i]=0;
    }

     //---------------------- input

   cout<<"Enter degree of polynomial    : ";
   cin>>degree;

   cout<<"\nEnter the polynomial :\n";

  for(i=0;i<=degree;i++)
    {
     cout<<"Coefficient of [x]^"<<degree-i<<" : ";
     cin>>coeff[i];
    }

    //---------------------- processing


  int count=degree-1;
  ans[degree]=coeff[degree];

  for(int a=0;a<=count;a++)
  {
   c=-1*degree;

   for(i=0;i<degree;i++)
    {
     if(i==0) coeff_quo[i]=coeff[i];
     else
      {
       float temp=c*coeff_quo[i-1];
       coeff_quo[i]=coeff[i]+temp;
      }
     c++;
    }

    ans[count-a]=coeff_quo[degree-1];

    for(i=0;i<degree;i++)
     {
      coeff[i]=coeff_quo[i];
     }
     degree--;

   }

    //---------------------- output

  degree=count+1;

  cout<<"\nThe transformed polynomial is :-\n\nterm  : ";

    for(i=0;i<=degree;i++)
     {
      cout<<"x^"<<degree-i<<"         ";
     }

    cout<<endl<<"coeff : ";

   for(i=0;i<=degree;i++)
    {
     printf("%g           ",ans[i]);
    }

  getch();
  break;
  }

  case '6':
   {// NOTE THE IMPORTANCE OF THESE OUTERMOST ENCLOSING BRACES IN CASE 1,2
    // ETC. THESE MAKE ALL VARIABLES USED IN THE RESPECTIVE CASES AS
    // LOCAL TO THOSE CASES ONLY AND HENCE THERE ARE NO ERRORS OF MULTIPLE
    // DECLARATION
   clrscr();
   int degree;
   float coeff[80],c,ans;

   for(int i=0;i<80;i++)
    {
     coeff[i]=0;
    }

     //---------------------- input

   cout<<"Enter degree of polynomial    : ";
   cin>>degree;

   cout<<"\nEnter the polynomial :\n";

  for(i=0;i<=degree;i++)
    {
     cout<<"Coefficient of x^"<<degree-i<<" : ";
     cin>>coeff[i];
    }

   cout<<"Enter the constant c at which evaluation is reqd. : ";
   cin>>c;
    //---------------------- processing
   process_again_case6:

   ans=coeff[0];

   for(i=0;i<degree;i++)
    {
      ans=(c*ans+coeff[i+1]);
    }

    //---------------------- output
   cout<<"\n\nThe value of polynomial at "<<c<<" is : "<<ans;

   inpagain_case6:
   cout<<"\n\nMore? (y/n) : ";
   char ch;
   ch=getch();
   if (ch=='y'||ch=='Y')
    {
     cout<<"Enter the constant c at which evaluation is reqd. : ";
     cin>>c;
     goto process_again_case6;
    }
   else if (ch=='n' ||ch=='N') ;
   else { cout<<"\nERROR !!!"; goto inpagain_case6; }

 break;
 }
  case '0':
   goto end;

  default:
   {
   cout<<"ERROR !!!\n"
      <<endl<<"PRESS ANY KEY TO CONTINUE...";
     getch();
     goto inp_again;
     }
 }

end:
cbab();
;
}
