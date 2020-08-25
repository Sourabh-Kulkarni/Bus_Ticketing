#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct booking
{	char src[30],dest[30],name[30];
        int day,month,age;
	unsigned long int mobi;
	struct booking *link;
}ticket;
ticket *first=NULL;
ticket *last=NULL;
static int seats = 25;
int num=0;

void create()
{
	char src1[30],dest1[30],name1[30];
	int age1,i=0;
	unsigned long int mobi1;
	seats--;
        if(first==NULL)
        {
                ticket *new=(ticket*)malloc(sizeof(ticket));
		printf("\n Enter the Source:");
		scanf("%s",src1);
		printf("\n Enter the Destination:");
		scanf("%s",dest1);
		printf("\n Please enter the Name:");
		scanf("%s",name1);
		printf("\n Enter the Age:");
		scanf("%d",&age1);
		printf("\n Enter the Mobile Number:");
		scanf("%lu",&mobi1);
		printf("\n Number of seats available:%d\n",seats);

		strcpy(new->src,src1);
		strcpy(new->dest,dest1);
		strcpy(new->name,name1);
                new->age=age1;
                new->mobi=mobi1;
                first=new;
                last=new;

        }
        else
        {
		ticket *new=(ticket*)malloc(sizeof(ticket));
                printf("\n Enter the Source:");
                scanf("%s",src1);
                printf("\n Enter the Destination:");
                scanf("%s",dest1);
                printf("\n Please enter the Name:");
		scanf("%s",name1);
                printf("\n Enter the Age:");
                scanf("%d",&age1);
                printf("\n Enter the Mobile Number:");
                scanf("%lu",&mobi1);
                printf("\n Number of seats available:%d\n",seats);
		strcpy(new->src,src1);
		strcpy(new->dest,dest1);
                strcpy(new->name,name1);
                new->age=age1;
                new->mobi=mobi1;
                new->link=NULL;
                last->link=new;
                last=new;
        }
}


void delete_first()
{
	seats++;
        printf("\nTicket has been cancelled for mentioned name:\n");
        ticket *temp1=first;
        first=temp1->link;
        free(temp1);
}


void delete_middle()
{
	seats++;
        char key[30];
        printf("\n Enter the name :");
        scanf("%s",key);	
        printf("\nTicket has been cancelled for mentioned name:\n");
        ticket *temp1=first,*temp2;
        while(strcmp(temp1->name,key))
        {
                temp2=temp1;
                temp1=temp1->link;
        }
        temp2->link=temp1->link;
        free(temp1);
}


void display()
{
	char src1[30],dest1[30],name1[30];
        int age1,i=0;
	long int mobi1;
	
	//********************************************************************************************************
	FILE *fptr=fopen("tickets_data.txt","w");

	//********************************************************************************************************
        int key=0;
        ticket *temp1=first,*temp2;
        while(temp1->link!=NULL)
        {
		strcpy(src1,temp1->src);
		strcpy(dest1,temp1->dest);
		strcpy(name1,temp1->name);
		age1=temp1->age;
		mobi1=temp1->mobi;
                printf("source = %s\n",src1);
                printf("destination = %s\n",dest1);
                printf("name = %s\n",name1);
                printf("age= %d\n",age1);
                printf("mobile number =  %lu\n",mobi1);

	//********************************************************************************************************
		fprintf(fptr,"source = %s\n",src1);
                fprintf(fptr,"destination = %s\n",dest1);
                fprintf(fptr,"name = %s\n",name1);
                fprintf(fptr,"age= %d\n",age1);
                fprintf(fptr,"mobile number =  %lu\n",mobi1);

	//********************************************************************************************************


                temp1=temp1->link;
        }
		
		strcpy(src1,temp1->src);
		strcpy(dest1,temp1->dest);
		strcpy(name1,temp1->name);
                age1=temp1->age;
                mobi1=temp1->mobi;
                printf("source = %s\n",src1);
                printf("destination = %s\n",dest1);
                printf("name = %s\n",name1);
                printf("age= %d\n",age1);
                printf("mobile number =  %lu\n",mobi1);
	//********************************************************************************************************
		fprintf(fptr,"source = %s\n",src1);
                fprintf(fptr,"destination = %s\n",dest1);
                fprintf(fptr,"name = %s\n",name1);
                fprintf(fptr,"age= %d\n",age1);
                fprintf(fptr,"mobile number =  %lu\n",mobi1);

	//********************************************************************************************************

	fclose(fptr);
        printf("\n");

}


int main()
{
	int WID=0,WPW=0;
	char login[20],pass[20],Ologin[]="ram@gmail.com",Opass[]="123password";
	printf("\n Enter to Bus Ticket Booking Zone!!!!\n");
	do{
	printf("\n Enter the login id: ");
	gets(login);
	printf("\n Enter the password: ");
	gets(pass);
	if(strcmp(Ologin,login))
	{
		printf("\n Wrong ID!!!! Try again\n");
		WID++;
	}
	else
		WID=0;
	
	if(strcmp(Opass,pass))
        {
                printf("\n Wrong Password!!!! Try again\n");
		WID++;
        }
	else
		WID=0;
	if(WID==0)
	{	
		printf("\n You are now logged in\n");
		break;
	}	
	}while(WID);

	int sel=0,money=500,ch=0;
	static int am;
	do{
		printf("\n Press 1 to book a ticket\n Press 2 to cancel ticket\nPress 3 to show overall bookings\n");
		scanf("%d",&sel);
		
       		switch(sel)
       		{
			case 1:if(seats!=0)
			       {
				create();
				am+=money;
				printf("\n Total amount = %d\n",am);
				break;
			       }
			case 2:
				if(first==last)
				{
					delete_first();
					am-=money;
	                                printf("\n Total amount = %d\n",am);

				}
				else
				{
					delete_middle();
					am-=money;
	                                printf("\n Total amount = %d\n",am);

				}
				break;
			case 3:printf("\n Overall info\n");
			       display();
	                       printf("\n Total amount = %d\n",am);
			       break;

			default :printf("\n Sorry wrong option selected....Please try again !!!\n");
				 break;


      	 	}
 		printf("\n Do you want to continue booking ?...If yes press any number else press 0 \n");
		scanf("%d",&ch);		
		if(ch==0)
			printf("\n Thank you so much for using our services!!!!.....Happy and safe journey.....\n Feel free to call our customer service toll free number any time for any quarries\n\n");
	}while(ch);

}
