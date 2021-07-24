 



#include<stdio.h>;
#include<conio.h>;
#include<dos.h>;
#include<string.h>;
#include<graphics.h>;
#define PATH "C:\\tc\\bgi"
#define TBG textbackground(WHITE);textcolor(BLUE);

typedef struct customer
    {
     long id;
     char name[20];
     char pn[12];
     char address[40];
     int doj[3];
    }cust;


typedef struct movie
    {
     long id;
     char title[25];
     int copy;
     int cponshelf;
     int issue;
     char sid[20];
     int loc;
    }mov;


typedef struct transaction
    {
     long invoice;
     int doi[3];
     int dor[3];
     char title[25];
     int fine;
     long cid;
     char cname[20];
     int copies;
     int rent;
     int tam;
    }transaction;


cust ctr;
mov mv;
transaction tran;
FILE *fc,*fm,*ft,*tmp;
long int size;
int days,k=0;
struct date d;


void main_menu()
  {
	char *menu[]={"CUSTOMER SECTION",
		"MOVIE SECTION",
		"TRANSACTION SECTION",
		"EXIT"};

	char ch;
	int gd=DETECT,gm,i,choice=0;
	initgraph(&gd,&gm,PATH);
	setfillstyle(SOLID_FILL,RED);
	bar(0,0,640,480);
	title("MAIN MENU",180);
	status();
	box(0,menu[0]);
	box(1,menu[1]);
	box(2,menu[2]);
	box(3,menu[3]);
	selectbox(choice,menu[choice]);

	//72  up
	//80  down
	//75  left
	//77  right
	//13  enter
	//49  1
	//71  Home
	//79  End
	//73 PgUp
	//81 PgDown
	//27 Escape



	while((ch=getch())!=13)
	{
		switch(ch)
		{
		case 80:
		case 81:
		choice++;
		if(choice==4)
		choice=0;
		selectbox(choice,menu[choice]);
		for(i=0;i<=3;i++)
		{
		if(i==choice) continue;
		box(i,menu[i]);
		}
		break;
		case 72:
		case 73:
		choice--;
		if(choice==-1)
		choice=3;
		selectbox(choice,menu[choice]);
		for(i=0;i<=3;i++)
		{
		if(i==choice) continue;
		box(i,menu[i]);
		}
		}
	}

       pressbutton(choice,menu[choice]);
		   closegraph();
		   restorecrtmode();


       switch(choice)
	  {
	    case 0:
		   size=sizeof(ctr);
		   customer();
		   break;
	    case 1:
		   movie();
		   break;
	    case 2:
		   transactions();
		   break;
	    case 3:
	 //	   closegraph();
	 //	   restorecrtmode();
		   exit(0);
	  }
    }



customer()
{
	char *menu[]={
		"ADD CUSTOMER",
		"MODIFY CUSTOMER",
		"DELETE CUSTOMER",
		"LIST CUSTOMER",
		"BACK TO MAIN MENU",
		"EXIT"
		};

	char ch;
	int gd=DETECT,gm;
	int i,choice=0;
	initgraph(&gd,&gm,PATH);
	setfillstyle(SOLID_FILL,RED);
	bar(0,0,640,480);
	title("CUSTOMER MENU",130);
	status();
	box(0,menu[0]);
	box(1,menu[1]);
	box(2,menu[2]);
	box(3,menu[3]);
	box(4,menu[4]);
	box(5,menu[5]);
	selectbox(choice,menu[choice]);

	while((ch=getch())!=13)
	{
		switch(ch)
		{
		case 80:
		case 81:
		choice++;
		if(choice==6)
		choice=0;
		selectbox(choice,menu[choice]);
		for(i=0;i<=5;i++)
		{
		if(i==choice) continue;
		box(i,menu[i]);
		}
		break;
		case 72:
		case 73:
		choice--;
		if(choice==-1)
		choice=5;
		selectbox(choice,menu[choice]);
		for(i=0;i<=5;i++)
		{
		if(i==choice) continue;
		box(i,menu[i]);
		}
		}
	}

	pressbutton(choice,menu[choice]);
	closegraph();
	restorecrtmode();

     clrscr();
     if((fc=fopen("c:customer.txt","rb+"))==NULL)
	fc=fopen("c:customer.txt","wb+");

     switch(choice)
	{
	 case 0:
		addcus();
		break;
	case 1:
		rewind(fc);
		modify();
		break;
	 case 2:
		delete();
		break;
	 case 3:
		listcust();
		break;
	 case 4:
		fclose(fc);
		main_menu();
		break;
	 case 5:
		fclose(fc);
		exit(1);
	}
}




movie()
{
	char *menu[]={
		"ADD MOVIE",
		"LIST MOVIES",
		"SEARCH MOVIE",
		"BACK TO MAIN MENU",
		"EXIT"
		};

	char ch;
	int gd=DETECT,gm;
	int i,choice=0;
	initgraph(&gd,&gm,PATH);
	setfillstyle(SOLID_FILL,RED);
	bar(0,0,640,480);
	title("MOVIE MENU",165);
	status();
	box(0,menu[0]);
	box(1,menu[1]);
	box(2,menu[2]);
	box(3,menu[3]);
	box(4,menu[4]);
	selectbox(choice,menu[choice]);


	while((ch=getch())!=13)
	{
		switch(ch)
		{
		case 80:
		case 81:
		choice++;
		if(choice==5)
		choice=0;
		selectbox(choice,menu[choice]);
		for(i=0;i<=4;i++)
		{
		if(i==choice) continue;
		box(i,menu[i]);
		}
		break;
		case 72:
		case 73:
		choice--;
		if(choice==-1)
		choice=4;
		selectbox(choice,menu[choice]);
		for(i=0;i<=4;i++)
		{
		if(i==choice) continue;
		box(i,menu[i]);
		}
		}
	}

	pressbutton(choice,menu[choice]);
	closegraph();
	restorecrtmode();

     clrscr();
     /*textcolor(4);*/
     fm=fopen("c:movie.txt","rb+");
     if(fm==NULL)
     fm=fopen("c:movie.txt","wb+");
     switch(choice)
	{
	 case 0:
		addmov();
		break;
	 case 1:
		listmov();
		break;
	 case 2:
		searchmov();
		break;
	 case 3:
		main_menu();
		break;
	 case 4:
		fclose(fm);
		exit(1);
	}
}

transactions()
    {
     char *menu[]={
		"NEW TRANSACTION",
		"CLOSE TRANSACTION",
		"LIST TRANSACTIONS",
		"SEARCH MOVIE",
		"BACK TO MAIN MENU",
		"EXIT"
		};

	char ch;
	int gd=DETECT,gm,i,choice=0;
	initgraph(&gd,&gm,PATH);
	setfillstyle(SOLID_FILL,RED);
	bar(0,0,640,480);
	title("TRANSACTION MENU",100);
	status();
	box(0,menu[0]);
	box(1,menu[1]);
	box(2,menu[2]);
	box(3,menu[3]);
	box(4,menu[4]);
	box(5,menu[5]);
	selectbox(choice,menu[choice]);


	while((ch=getch())!=13)
	{
		switch(ch)
		{
		case 80:
		case 81:
		choice++;
		if(choice==6)
		choice=0;
		selectbox(choice,menu[choice]);
		for(i=0;i<=5;i++)
		{
		if(i==choice) continue;
		box(i,menu[i]);
		}
		break;
		case 72:
		case 73:
		choice--;
		if(choice==-1)
		choice=5;
		selectbox(choice,menu[choice]);
		for(i=0;i<=5;i++)
		{
		if(i==choice) continue;
		box(i,menu[i]);
		}
		}
	}

	pressbutton(choice,menu[choice]);
	closegraph();
	restorecrtmode();

     clrscr();
     ft=fopen("c:	ransact.txt","rb+");
     if(ft==NULL)
	ft=fopen("c:	ransact.txt","wb+");
     switch(choice)
	{
	 case 0:
		addtran();
		break;
	 case 1:
		closetran();
		break;
	 case 2:
		listtran();
		break;
	 case 3:
		 fm=fopen("c:movie.txt","rb+");
		 if(fm==NULL)
		 fm=fopen("c:movie.txt","wb+");
		 searchmov();
		 break;
	 case 4:
		main_menu();
		break;
	 case 5:
		exit(0);
	}
    }

addcus()
   {
    char another='y';
    fseek(fc,0,SEEK_END);

    TBG;
    while(another=='y'||another=='Y')
	{
	 clrscr();

	 printf("********************   ADD CUSTOMER FORM ****************");
	 printf("CUSTOMER ID(NUMERIC)  :");
	 printf("CUSTOMER NAME         :");
	 printf("CUSTOMER PHONE NO     :");
	 printf("CUSTOMER ADDRESS      :");
	 printf("DATE OF JOINING       :");
	 printf("CATEGORY(H/A/C/R/S/T) :");

	 gotorc(2,24);
	 customid();
	 gotorc(4,24);
	 fflush(stdin);
	 gets(ctr.name);
	 gotorc(6,24);
	 fflush(stdin);
	 gets(ctr.pn);
	 gotorc(8,24);
	 fflush(stdin);
	 gets(ctr.address);
	 gotorc(10,24);
	 fflush(stdin);
	 getdate(&d);
	 ctr.doj[0]=d.da_day;ctr.doj[1]=d.da_mon;ctr.doj[2]=d.da_year;
	 printf("%d/%d/%d",d.da_day,d.da_mon,d.da_year);
	 gotorc(16,3);
	 printf("DO YOU WANT TO SUBMIT THIS FORM (Y/N)");
	 fflush(stdin);
	 another=getch();
	 if(another=='y'||another=='Y')
	 fwrite(&ctr,size,1,fc);
	 gotorc(18,3);
	 printf("DO YOU WANT TO ADD ANOTHER CUTOMER(Y/N)");
	 fflush(stdin);
	 another=getch();
	}
    fclose(fc);
    customer();
     }

customid()
    {
     rewind(fc);
     if(fread(&ctr,sizeof(ctr),1,fc)!=1)
	ctr.id=1;
     else
       {
	while(fread(&ctr,sizeof(ctr),1,fc)==1);
	     ctr.id++;
	 }
       printf("%ld",ctr.id);
     }


 modify()
   {
    char another='y',choice,name[20],flag='n';
    long id;

    TBG;
    while(another=='y'||another=='Y')
	{
	 clrscr();
	 rewind(fc);

	 printf("	SEARCH BY NAME : PRESS 1	SEARCH BY ID   : PRESS 2	");

	 fflush(stdin);
	 choice=getchar();
	 if(choice=='2')
	   {
	     printf("ENTER CUSTOMER ID : ");
	     scanf("%ld",&id);
		     while(fread(&ctr,size,1,fc)==1)
		       {
		if(ctr.id==id)
		 {
		  new();
		  flag='y';
		  break;
		 }
		      }
	     }
	 if(choice=='1')
	    {
	     printf("ENTER CUSTOMER NAME : ");
	     fflush(stdin);
	     gets(name);
	     while(fread(&ctr,size,1,fc)==1)
		{
		   if(strcmpi(ctr.name,name)==0)
		     {
		       new();
		       flag='y';
		       break;
		     }
		}
	    }
	 if(flag=='n')
	 {
	 gotorc(15,3);
	 printf("CUSTOMER NOT FOUND............ !");
	 }
	 gotorc(18,3);
	 printf("DO YOU WANT TO MODIFY ANOTHER CUTOMER(Y/N)");
	 fflush(stdin);
	 another=getch();
	}
    fclose(fc);
    customer();
     }



new()
	{
	   char another='y';
	   clrscr();
	   TBG;
	   fseek(fc,-size,SEEK_CUR);
		printf("CUSTOMER'S NEW NAME                      :");
		printf("CUSTOMER'S NEW PHONE NO                  :");
		printf("CUSTOMER'S NEW ADDRESS                   :");
		printf("NEW DATE OF JOINING (DD&lt;-|MM&lt;-|YYYY&lt;-|)  :");
		printf("NEW CATEGORY(H/A/C/R/S/T)                :");
		gotorc(1,43);
		fflush(stdin);
		gets(ctr.name);
		gotorc(3,43);
		fflush(stdin);
		gets(ctr.pn);
		gotorc(5,43);
		fflush(stdin);
		gets(ctr.address);
		gotorc(7,43);
		fflush(stdin);
		scanf("%d",&ctr.doj[0]);
		gotorc(7,45);
		printf("%c",'/');
		scanf("%d",&ctr.doj[1]);
		gotorc(7,48);
		printf("%c",'/');
		scanf("%d",&ctr.doj[2]);
		gotorc(16,3);
		printf("UPDATE THE CUSTOMER RECORD (Y/N)");
		fflush(stdin);
		another=getch();
		if(another=='y'||another=='Y')
		fwrite(&ctr,size,1,fc);
		rewind(fc);
	 }





listcust()
{
int i=1,p=4;
clrscr();

TBG;
rewind(fc);
printf("********************  CUSTOMERS LIST ************");
gotorc(2,3);
printf("ID");
gotorc(2,8);
printf("NAME");
gotorc(2,22);
printf("PHONE NO");
gotorc(2,35);
printf("ADDRESS");
gotorc(2,55);
printf("D.O.J");
gotorc(2,68);
printf("CATEGORY");
while(fread(&ctr,size,1,fc)==1)
{
	gotorc(p,3);
	printf("%ld",ctr.id);
	gotorc(p,8);
	printf("%s",strupr(ctr.name));
	gotorc(p,22);
	printf("%s",ctr.pn);
	gotorc(p,35);
	printf("%s",strupr(ctr.address));
	gotorc(p,55);
	printf("%d/%d/%d",ctr.doj[0],ctr.doj[1],ctr.doj[2]);
	if(i%15==0)
	{
	gotorc(40,3);
	printf("PRESS ANY KEY TO CONTINUE.....");
	getch();
	clrscr();
	p=4;
	}
	p+=2;
	i++;

	}
printf("   PRESS ANY KEY TO BACK TO CUSTOMER MENU");
	  getch();
	  customer();
	  }



delete()
   {
    char another='y',choice,name[20],flag='n';
    long id;
    tmp=fopen("c:	emp.txt","wb");
    rewind(fc);

    TBG;
    while(another=='y'||another=='Y')
	{
	 clrscr();
	 printf("	DELETE BY NAME : 1	DELETE BY ID  : 2	");
	 fflush(stdin);
	 choice=getchar();
	 if(choice=='2')
	   {
	     printf("ENTER CUSTOMER ID : ");
	     scanf("%ld",&id);
	     clrscr();
		     while(fread(&ctr,size,1,fc)==1)
		       {
		if(ctr.id!=id)
		  fwrite(&ctr,size,1,tmp);
		else
		flag='y';
		      }
	     }
	 if(choice=='1')
	    {
	     printf("ENTER CUSTOMER NAME : ");
	     fflush(stdin);
	     gets(name);
	     clrscr();
	     while(fread(&ctr,size,1,fc)==1)
		{
		   if(strcmpi(ctr.name,name)!=0)
		      fwrite(&ctr,size,1,tmp);
		   else
		flag='y';
		}
	    }
	    fclose(fc);
	    fclose(tmp);
	    remove("c:customer.txt");
	    rename("c:	emp.txt","c:customer.txt");
	 if(flag=='n')
	 printf(" CUSTOMER NOT FOUND.... !");
	 printf("DO YOU WANT TO DELETE ANOTHER CUTOMER(Y/N)");
	 fflush(stdin);
	 another=getch();
	}
    fclose(fc);
    customer();
     }




 addmov()
   {
    char another='y';

    TBG;
    fseek(fm,0,SEEK_END);
    while(another=='y'||another=='Y')
	{
	 clrscr();
	 printf("*****************ADD MOVIE FORM*****************");
	 printf("MOVIE ID(NUMERIC)    :");
	 printf("MOVIE NAME           :");
	 printf("NO OF COPIES         :");
	 printf("SUPPLIER ID          :");
	 printf("LOCATION             :");
	 gotorc(1,24);
	 movid();
	 gotorc(2,24);
	 fflush(stdin);
	 gets(mv.title);
	 gotorc(3,24);
	 fflush(stdin);
	 scanf("%d",&mv.copy);
	 mv.cponshelf=mv.copy;
	 mv.issue=0;
	 gotorc(4,24);
	 fflush(stdin);
	 gets(mv.sid);
	 gotorc(5,24);
	 fflush(stdin);
	 scanf("%d",&mv.loc);
	 fwrite(&mv,sizeof(mv),1,fm);
	 printf("DO YOU WANT TO ADD ANOTHER MOVIE(Y/N)");
	 fflush(stdin);
	 another=getch();
	}
    fclose(fm);
    printf("PRESS ANY KEY TO BACK TO MOVIE MENU");
    movie();
     }



 movid()
    {
     rewind(fm);
     if(fread(&mv,sizeof(mv),1,fm)!=1)
	mv.id=1;
     else
       {
	while(fread(&mv,sizeof(mv),1,fm)==1);
	     mv.id++;
	 }
       printf("%ld",mv.id);
    }

 listmov()
	  {
	  int i=1,p=4;
	  textbackground(WHITE);
	  textcolor(BLUE);
	  clrscr();
	  rewind(fm);
	  printf("********************  MOVIE LIST *****************");
	  gotorc(2,1);
	  printf("ID");
	  gotorc(2,5);
	  printf("TITLE");
	  gotorc(2,25);
	  printf("TOT_CP");
	  gotorc(2,35);
	  printf("CP_O_SHELF");
	  gotorc(2,48);
	  printf("TOT_ISSUES");
	  gotorc(2,59);
	  printf("SUPPLIER ID");
	  gotorc(2,71);
	  printf("LOCATION");
	  while(fread(&mv,sizeof(mv),1,fm)==1)
		{
		gotorc(p,1);
		printf("%ld",mv.id);
		gotorc(p,5);
		printf("%s",strupr(mv.title));
		gotorc(p,28);
		printf("%d",mv.copy);
		gotorc(p,40);
		printf("%d",mv.cponshelf);
		gotorc(p,52);
		printf("%d",mv.issue);
		gotorc(p,59);
		printf("%s",mv.sid);
		gotorc(p,74);
		printf("%d",mv.loc);
		if(i%10==0)
		{
		printf("PRESS ANY KEY TO CONTINUE.....");
		fflush(stdin);
		getch();
		clrscr();
		p=4;
		}
		i++;
		p+=2;

		}
	  printf("PRESS ANY KEY TO BACK TO MOVIE MENU");
	  getch();
	  fclose(fm);
	  movie();
	  }



 searchmov()
	{
	 char mname[20],another;

	 TBG;
	 clrscr();
	 rewind(fm);
	 gotorc(5,5);
	 printf("ENTER MOVIE TITLE    :   ");
	 fflush(stdin);
	 gets(mname);
	 while(fread(&mv,sizeof(mv),1,fm)==1)
		{
		if(strcmpi(mv.title,mname)==0)
		{
		gotorc(7,12);
		textcolor(0);
		cprintf("MOVIE FOUND..");
		textcolor(4);
		gotorc(9,5);
		printf("MOVIE TITLE            : %s",mv.title);
		gotorc(11,5);
		printf("TOTAL NO OF COPIES     : %d",mv.copy);
		gotorc(13,5);
		printf("NO OF COPIES AVAILABLE : %d",mv.cponshelf);
		gotorc(15,5);
		printf("SUPPLIER ID            : %s",mv.sid);
		gotorc(17,5);
		printf("LOCATION               : %d",mv.loc);
		gotorc(20,5);
		printf("DO YOU WANT TO SEARCH MORE MOVIES(Y/N)");
		fflush(stdin);
		another=getchar();
		if(another=='y'||another=='Y')
		searchmov();
		fclose(fm);
		movie();
		}
		}

	gotorc(7,5);
	textcolor(4);
	cprintf("MOVIE NOT FOUND.....!");
	textcolor(4);
	gotorc(12,5);
	printf("DO YOU WANT TO SEARCH MORE MOVIES(Y/N)");
	fflush(stdin);
	another=getchar();
	if(another=='y'||another=='Y')
	searchmov();
	fclose(fm);
	movie();

	}
  searchmovc()
	{
	 char mname[20],another;

	 TBG;
	 clrscr();
	 rewind(fm);
	 gotorc(5,5);
	 printf("ENTER MOVIE TITLE    :   ");
	 fflush(stdin);
	 gets(mname);
	 while(fread(&mv,sizeof(mv),1,fm)==1)
		{
		if(strcmpi(mv.title,mname)==0)
		{
		gotorc(7,12);
		textcolor(0);
		cprintf("MOVIE FOUND..");
		textcolor(4);
		gotorc(9,5);
		printf("MOVIE TITLE            : %s",mv.title);
		gotorc(11,5);
		printf("TOTAL NO OF COPIES     : %d",mv.copy);
		gotorc(13,5);
		printf("NO OF COPIES AVAILABLE : %d",mv.cponshelf);
		gotorc(15,5);
		printf("SUPPLIER ID            : %s",mv.sid);
		gotorc(17,5);
		printf("LOCATION               : %d",mv.loc);
		gotorc(20,5);
		printf("DO YOU WANT TO SEARCH MORE MOVIES(Y/N)");
		fflush(stdin);
		another=getchar();
		if(another=='y'||another=='Y')
		searchmov();
		fclose(fm);
		movie();
		}
		}

	gotorc(7,5);
	textcolor(4);
	cprintf("MOVIE NOT FOUND.....!");
	textcolor(4);
	gotorc(12,5);
	printf("DO YOU WANT TO SEARCH MORE MOVIES(Y/N)");
	fflush(stdin);
	another=getchar();
	if(another=='y'||another=='Y')
	searchmov();
	fclose(fm);
	customer_menu();
	}


	 listmovc()
	  {
	  int i=1,p=4;
	  textbackground(WHITE);
	  textcolor(BLUE);
	  clrscr();
	  rewind(fm);
	  printf("********************  MOVIE LIST *****************");
	  gotorc(2,1);
	  printf("ID");
	  gotorc(2,5);
	  printf("TITLE");
	  gotorc(2,25);
	  printf("TOT_CP");
	  gotorc(2,35);
	  printf("CP_O_SHELF");
	  gotorc(2,48);
	  printf("TOT_ISSUES");
	  gotorc(2,59);
	  printf("SUPPLIER ID");
	  gotorc(2,71);
	  printf("LOCATION");
	  while(fread(&mv,sizeof(mv),1,fm)==1)
		{
		gotorc(p,1);
		printf("%ld",mv.id);
		gotorc(p,5);
		printf("%s",strupr(mv.title));
		gotorc(p,28);
		printf("%d",mv.copy);
		gotorc(p,40);
		printf("%d",mv.cponshelf);
		gotorc(p,52);
		printf("%d",mv.issue);
		gotorc(p,59);
		printf("%s",mv.sid);
		gotorc(p,74);
		printf("%d",mv.loc);
		if(i%10==0)
		{
		printf("PRESS ANY KEY TO CONTINUE.....");
		fflush(stdin);
		getch();
		clrscr();
		p=4;
		}
		i++;
		p+=2;

		}
	  printf("PRESS ANY KEY TO BACK TO MOVIE MENU");
	  getch();
	  fclose(fm);
	 customer_menu();
    }

addtran()
   {
    char another='y',rec;

    TBG;
    fseek(ft,0,SEEK_END);
    while(another=='y'||another=='Y')
	{
	 clrscr();
	 printf("*****************  TRANSACTION****************");
	 printf("INVOICE NO(NUMERIC) :");
	 printf("MOVIE TITLE         :");
	 printf("COPIES AVAILABLE    :");
	 printf("CUSTOMER ID         :");
	 printf("CUSTOMER NAME       :");
	 printf("NO. OF COPIES       :");
	 printf("DATE OF ISSUE       :");
	 gotorc(2,24);
	 invoice();
	 gotorc(4,24);
	 fflush(stdin);
	 gets(tran.title);
	 gotorc(6,24);
	 avail();
	 gotorc(8,24);
	 fflush(stdin);
	 scanf("%ld",&tran.cid);
	 custcheck();
	 gotorc(12,24);
	 fflush(stdin);
	 scanf("%d",&tran.copies);
	 if(tran.copies>mv.cponshelf)
		{
		gotorc(18,3);
		printf("TRANSACTION NOT POSSIBLE : REQUIRED NO OF COPIES NOT AVAILABLE");
		printf("PRESS ANY KEY TO BACK TO TRANSACTION MENU");
		getch();
		transactions();
		}
	 gotorc(14,24);
	 fflush(stdin);
	 getdate(&d);
	 tran.doi[0]=d.da_day;tran.doi[1]=d.da_mon;tran.doi[2]=d.da_year;
	 printf("%d/%d/%d",d.da_day,d.da_mon,d.da_year);
	 tran.dor[0]=0;
	 tran.rent=0;
	 gotorc(18,4);
	 printf("DO YOU WANT TO RECORD THIS TRANSACTION(Y/N)");
	 rec=getchar();
	 if(rec=='y'||rec=='Y')
		{
		update();
		fwrite(&tran,sizeof(tran),1,ft);
		}
	 printf("DO YOU WANT TO ADD ANOTHER TRANSACTION(Y/N)");
	 fflush(stdin);
	 another=getch();
	}
    fclose(ft);
    printf("PRESS ANY KEY TO BACK TO TRANSACTION MENU");
    transactions();
     }


 custcheck()
	{

	if((fc=fopen("c:customer.txt","rb"))==NULL)
		fc=fopen("c:customer.txt","wb+");
	rewind(fc);
	 while(fread(&ctr,sizeof(ctr),1,fc)==1)
		{
		   if(ctr.id==tran.cid)
		{
		 gotorc(10,24);
		 printf("%s",ctr.name);
		 strcpy(tran.cname,ctr.name);
		 fclose(fc);
		 return;
		 }
		}
	 fclose(fc);
	 gotorc(18,4);
	 printf("INVALID CUSTOMER ............!");
	 gotorc(21,4);
	 printf("PRESS ANY KEY TO BACK TO TRANSACTION MENU");
	 getch();
	 transactions();

	 }



 invoice()
    {
     rewind(ft);
     if(fread(&tran,sizeof(tran),1,ft)!=1)
	tran.invoice=1;
     else
       {
	while(fread(&tran,sizeof(tran),1,ft)==1);
	     tran.invoice++;
	 }
       printf("%ld",tran.invoice);
     }



 avail()
    {
     fm=fopen("c:movie.txt","rb+");
     if(fm==NULL)
     fm=fopen("c:movie.txt","wb+");
     while(fread(&mv,sizeof(mv),1,fm)==1)
	{
	if(strcmpi(tran.title,mv.title)==0)
		{
		printf("%d",mv.cponshelf);
		fclose(fm);
		return;
		}
	}
     gotorc(18,3);
     printf("%s","MOVIE NOT FOUND...!");
     gotorc(21,3);
     printf("PRESS ANY KEY TO RETURN");
     getch();
     fclose(fm);
     transactions();
     }





 update()
    {
    long msize;
    msize=sizeof(mv);
     fm=fopen("c:movie.txt","rb+");
     if(fm==NULL)
     fm=fopen("c:movie.txt","wb+");
     while(fread(&mv,sizeof(mv),1,fm)==1)
	{
	if(strcmpi(tran.title,mv.title)==0)
		{
		mv.cponshelf=mv.cponshelf-tran.copies;
		mv.issue=mv.issue+tran.copies;
		fseek(fm,-msize,SEEK_CUR);
		fwrite(&mv,sizeof(mv),1,fm);
		break;
		}
	}
     fclose(fm);
     return;
     }



listtran()
	  {
	  int i=1;

	  TBG;
	  clrscr();
	  rewind(ft);
	  while(fread(&tran,sizeof(tran),1,ft)==1)
		{
		printf("INVOICE NO(NUMERIC) : %ld	",tran.invoice);
		printf("CUSTOMER ID         : %ld	",tran.cid);
		printf("CUSTOMER NAME       : %s	",tran.cname);
		printf("MOVIE TITLE         : %s	",tran.title);
		printf("NO. OF COPIES       : %d	",tran.copies);
		printf("DATE OF ISSUE       : %d/%d/%d	",tran.doi[0],tran.doi[1],tran.doi[2]);
		if(tran.dor[0]!=0)
		{
		printf("DATE OF RETURN      : %d/%d/%d	",tran.dor[0],tran.dor[1],tran.dor[2]);
		printf("RENT                : %d	",tran.rent);
		printf("FINE                : %d	",tran.fine);
		printf("TOTAL AMOUNT        : %d",tran.tam);
		}

		printf("........................................");

		if(i%2==0)
		{
		printf("PRESS ANY KEY TO CONTINUE.....");
		getch();
		clrscr();
		}
		i++;

		}
	  fclose(ft);
	  printf("PRESS ANY KEY TO BACK TO TRANSACTION MENU");
	  getch();
	  transactions();
	  }




 closetran()
	{
	 long id,sz;

	 TBG;
	 clrscr();
	 sz=sizeof(tran);
	 printf("ENTER INVOICE NO: ");
	 scanf("%ld",&id);
	 clrscr();
	 while(fread(&tran,sz,1,ft)==1)
		{
		if(tran.invoice==id)
		{
		if(tran.dor[0]!=0)
		{
		gotorc(4,4);
		printf("THIS TRANSACTION IS ALL READY CLOSED...!");
		gotorc(7,4);
		printf("PRESS ANY KEY TO BACK TO TRANSACTION MENU......");
		getch();
		transactions();
		}
		fseek(ft,-sz,1);
		getdate(&d);
		tran.dor[0]=d.da_day;tran.dor[1]=d.da_mon;tran.dor[2]=d.da_year;
		difference();
		tran.rent=tran.copies*25;
		if(k==0)
		tran.fine=0;
		else
		tran.fine=tran.copies*(k-1)*5;
		tran.tam=tran.rent+tran.fine;
		printf("INVOICE NO(NUMERIC) : %ld	",tran.invoice);
		printf("CUSTOMER ID         : %ld	",tran.cid);
		printf("CUSTOMER NAME       : %s	",tran.cname);
		printf("MOVIE TITLE         : %s	",tran.title);
		printf("NO. OF COPIES       : %d	",tran.copies);
		printf("DATE OF ISSUE       : %d/%d/%d	",tran.doi[0],tran.doi[1],tran.doi[2]);
		printf("DATE OF RETURN      : %d/%d/%d	",tran.dor[0],tran.dor[1],tran.dor[2]);
		printf("RENT                : %d	",tran.rent);
		printf("FINE                : %d	",tran.fine);
		printf("TOTAL AMOUNT        : %d	",tran.tam);
		updateclose();
		fwrite(&tran,sz,1,ft);
		fclose(ft);
		       }
		}
	  printf("PRESS ANY KEY TO BACK TO TRANSACTION MENU");
	  getch();
	  transactions();

	}


difference()
    {
     int t,m1,m2,y1,y2,d1,d2;
     d1=tran.doi[0];
     d2=tran.dor[0];
     m1=tran.doi[1];
     m2=tran.dor[1];
     y1=tran.doi[2];
     y2=tran.dor[2];
     t=m1;
     if(y2>y1)
       {
       while(y2<y1)
	{
	 while(m1<=12)
	      {
	       check(m1,y1);
	       if(m1==t)
		  k=days-d1;
	       else
		 k=k+days;
	       m1=m1+1;
	      }
	  m1=1;y1++;
	 }
     while(m1<m2)
       {
	check(m1,y1);
	k=k+days;
	m1++;
       }
     k=k+d2;
  }
  else
    {
     if(m1!=m2)
	{
	while(m1<m2)
	      {
	       check(m1,y1);
	       if(m1==t)
		  k=days-d1;
	       else
		 k=k+days;
	       m1=m1+1;
	      }
	    k=k+d2;
	 }
     else
	k=d2-d1;
    }

  }



check(int m1,int y1)
   {
    if(m1==1||m1==3||m1==5||m1==7||m1==8||m1==10||m1==12)
       days=31;
    else
	{
	if(m1!=2)
	   days=30;
	  else
	    {
	     if(y1%4==0)
		days=29;
	     else
		days=28;
	     }
	 }
    }



 updateclose()
    {
     long msize;
    msize=sizeof(mv);
     fm=fopen("c:movie.txt","rb+");
     if(fm==NULL)
     fm=fopen("c:movie.txt","wb+");
     while(fread(&mv,sizeof(mv),1,fm)==1)
	{
	if(strcmpi(tran.title,mv.title)==0)
		{
		mv.cponshelf=mv.cponshelf+tran.copies;
		fseek(fm,-msize,SEEK_CUR);
		fwrite(&mv,msize,1,fm);
		break;
		}
	}
     fclose(fm);
     return;
     }

 gotorc(int r,int c)
    {
     union REGS i,o;
     i.h.ah=2;
     i.h.bh=0;
     i.h.dh=r;
     i.h.dl=c;
     int86(16,&i,&o);
    }

  screen0()
  {
  char *a[]={"ADMINISTRATOR","CUSTOMER","EXIT"};
   char ch;
   int gd=DETECT,gm,i,choice=0;
   initgraph(&gd,&gm,PATH);
   setfillstyle(SOLID_FILL,BLUE);
   bar(0,0,640,480);
   box(0,a[0]);
   box(1,a[1]);
   box(2,a[2]);
   selectbox(choice,a[choice]);
   while((ch=getch())!=13)
   {
    switch(ch)
    {
     case 80:
     case 81:
      choice++;
      if(choice==3)
      choice=0;
      selectbox(choice,a[choice]);
      for(i=0;i<=2;i++)
      {
       if(i==choice) continue;
       box(i,a[i]);
      }
     break;
     case 72:
     case 73:
     choice--;
     if(choice==-1)
     choice=1;
     selectbox(choice,a[choice]);
     for(i=0;i<=2;i++)
     {
      if(i==choice) continue;
      box(i,a[i]);
     }
    }
   }
   pressbutton(choice,a[choice]);
   closegraph();
   restorecrtmode();
   clrscr();
   switch(choice)
   {
    case 0:TBG;
     login();
     break;
     case 1:
     customer_menu();
     break;
     case 2:
     exit(1);
     }
   }

 screen1()
 {
 int gd=DETECT,gm;
 initgraph(&gd,&gm,PATH);
 setfillstyle(SOLID_FILL,BLUE);
 bar(0,0,640,480);
 setfillstyle(SOLID_FILL,WHITE);
 bar(15,15,625,465);
 setfillstyle(SOLID_FILL,BLUE);
 bar(30,30,610,450);
 settextstyle(1,0,8);
 setcolor(WHITE);
 outtextxy(190,35,"VIDEO");
 setfillstyle(SOLID_FILL,LIGHTGRAY);
 bar3d(180,140,385,130,20,20);
 outtextxy(160,150,"LIBRARY");
 bar3d(140,255,440,245,20,20);
 outtextxy(165,270,"SYSTEM");
 bar3d(145,375,440,365,20,20);
getch();
 closegraph();
 restorecrtmode();
 }


 screen2()
 {
 int gd=DETECT,gm;
 initgraph(&gd,&gm,PATH);
 setfillstyle(SOLID_FILL,BLUE);
 bar(0,0,640,480);
 setfillstyle(SOLID_FILL,WHITE);
 bar(15,15,625,465);
 setfillstyle(SOLID_FILL,BLUE);
 bar(30,30,610,450);
 setfillstyle(SOLID_FILL,LIGHTGRAY);
 bar3d(180,100,420,300,25,25); /*members bar*/
 settextstyle(1,1,9);
 setcolor(WHITE);
 outtextxy(10,55,"R.A.M.A.");
 setfillstyle(SOLID_FILL,LIGHTGRAY);
 bar3d(180,50,420,70,20,20);   /*project members bar*/
 bar3d(150,350,570,420,25,25);  /*project guide bar*/
 setcolor(BLUE);
 settextstyle(1,0,2);
 outtextxy(193,48,"PROJECT MADE BY");
 outtextxy(193,110,"RAMA CHAUDHARY");
 outtextxy(235,351,"PROJECT GUIDE:");
 settextstyle(1,0,5);
 outtextxy(160,373,"Mr.HITESH KUMAR");
getch();
 closegraph();
 restorecrtmode();
 }
 customer_menu()
 {
  char *ar[]={"LIST MOVIES","SEARCH MOVIES","EXIT"};
   char ch;
   int gd=DETECT,gm,i,choice=0;
   initgraph(&gd,&gm,PATH);
   setfillstyle(SOLID_FILL,BLUE);
   bar(0,0,640,480);

  title("CUSTOMER MENU",180);
   status();
  box(0,ar[0]);
   box(1,ar[1]);
   box(2,ar[2]);
   selectbox(choice,ar[choice]);
   while((ch=getch())!=13)
   {
    switch(ch)
    {
     case 80:
     case 81:
      choice++;
      if(choice==3)
      choice=0;
      selectbox(choice,ar[choice]);
      for(i=0;i<=2;i++)
      {
       if(i==choice) continue;
       box(i,ar[i]);
      }
     break;
     case 72:
     case 73:
     choice--;
     if(choice==-1)
     choice=2;
     selectbox(choice,ar[choice]);
     for(i=0;i<=2;i++)
     {
      if(i==choice) continue;
      box(i,ar[i]);
     }
    }
   }
   pressbutton(choice,ar[choice]);
   closegraph();
   restorecrtmode();
   clrscr();
   switch(choice)
   {
   case 0:listmovc();
   break;
   case 1:searchmovc();
   break;
   case 2:exit();
   }
}
 box(int i,char *p)
 {
 setfillstyle(SOLID_FILL,WHITE);
 bar(179,108+55*i,409,138+55*i);
 setfillstyle(SOLID_FILL,LIGHTGRAY);
 bar(180,110+55*i,410,140+55*i);
 setcolor(BLUE);
  settextstyle(1,0,2);
 outtextxy(184,110+55*i,p);
 }
selectbox(int i,char *p)
 {
 setfillstyle(SOLID_FILL,WHITE);
 bar(179,108+55*i,409,138+55*i);
 setfillstyle(SOLID_FILL,9);
 bar(180,110+55*i,410,140+55*i);
 setcolor(WHITE);
 settextstyle(1,0,2);
 outtextxy(184,110+55*i,p);
 }
 pressbutton(int i,char *p)
 {
 setfillstyle(SOLID_FILL,WHITE);
 bar(180,110+55*i,410,140+55*i);
 setfillstyle(SOLID_FILL,9);
 bar(179,108+55*i,409,138+55*i);
 setcolor(CYAN);
 settextstyle(1,0,2);
 outtextxy(184,110+55*i,p);
 delay(350);
 }
 title(char *title,int x)
 {
	setfillstyle(SOLID_FILL,9);
	bar(0,0,640,50);
	setcolor(BLACK);
	settextstyle(1,0,5);
	outtextxy(x,0,title);
 }

 status()
 {
	setfillstyle(SOLID_FILL,9);
	bar(0,450,640,480);
	setcolor(BLACK);
	settextstyle(1,0,3);
	outtextxy(30,450,"USE UP & DOWN ARROW KEYS TO SELECT AN OPTION");
 }
 login()
 {
   int i=0,j=0,k=0;
   char ch,ar[6],ar2[5],user[]="hitesh",pwd[]="hites";
   clrscr();
   gotorc(10,12);
   printf("ENTER USERNAME:");
  while((ch=getch())!=13&&(i<6))
  {
   ar[i]=ch;
   if((ch>=65&&ch<=90)||(ch>=97&&ch<=122)||(ch>=48&&ch<=57))
   printf("*");i++;}

  i=0;
  gotorc(11,12);
  printf("ENTER PASSWORD:");
  while((ch=getch())!=13&&(i<5))
 {
   ar2[i]=ch;
   if((ch>=65&&ch<=90)||(ch>=97&&ch<=122)||(ch>=48&&ch<=57))
   printf("*");i++;}
   while(j!=6)
    { if(ar[j]==user[j])
      j++;
      else
      break;
     }
   while(k!=5)
   { if(ar2[k]==pwd[k])
      k++;
     else
     break;
   }
  if(j!=6||k!=5)
   {
    screen0();
    }
  else
   main_menu();
     getch();
  }
  void main()
	{
	screen1();
	screen2();
	screen0();
	getch();
	}
