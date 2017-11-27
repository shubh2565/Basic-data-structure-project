#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
 

 

struct electronics
{
    int price,rating,sno;
    char brand[20];
    struct node *next;
}*head;
 
int s=1;
 
void append_electronics(int num,int rate,char bran[])
{
    struct electronics *temp,*right;
    temp= (struct electronics *)malloc(sizeof(struct electronics));
    temp->price=num;
    temp->sno=s++;
    temp->rating=rate;
    strcpy(temp->brand,bran);
    right=(struct electronics *)head;
    while(right->next != NULL)
    right=right->next;
    right->next =temp;
    right=temp;
    right->next=NULL;
}
 
 
 
void add_electronics( int num,int rate,char bran[] )
{
    struct electronics *temp;
    temp=(struct electronics *)malloc(sizeof(struct electronics));
    temp->price=num;
    temp->rating=rate;
    temp->sno=s++;
	strcpy(temp->brand,bran);
    if (head== NULL)
    {
    head=temp;
    head->next=NULL;
    }
    else
    {
    temp->next=head;
    head=temp;
    }
}
void addafter_electronics(int num, int loc,int rate,char bran[])
{
    int i;
    struct electronics *temp,*left,*right;
    right=head;
    for(i=1;i<loc;i++)
    {
    left=right;
    right=right->next;
    }
    temp=(struct electronics *)malloc(sizeof(struct electronics));
    temp->price=num;
    temp->rating=rate;
    temp->sno=s++;
    strcpy(temp->brand,bran);
    left->next=temp;
    left=temp;
    left->next=right;
    return;
}
 
 
 
void insert_electronics(int num,int rate,char bran[])
{
    int c=0;
    struct electronics *temp;
    temp=head;
    if(temp==NULL)
    {
    add_electronics(num,rate,bran);
    }
    else
    {
    while(temp!=NULL)
    {
        if(temp->sno<s)
        c++;
        temp=temp->next;
    }
    if(c==0)
        add_electronics(num,rate,bran);
    else if(c<count_electronics())
        addafter_electronics(num,++c,rate,bran);
    else
        append_electronics(num,rate,bran);
    }
}
 
 
 
int delete_electronics(int num)
{
    struct electronics *temp, *prev;
    temp=head;
    while(temp!=NULL)
    {
    if(temp->price==num)
    {
        if(temp==head)
        {
        head=temp->next;
        free(temp);
        return 1;
        }
        else
        {
        prev->next=temp->next;
        free(temp);
        return 1;
        }
    }
    else
    {
        prev=temp;
        temp= temp->next;
    }
    }
    return 0;
}
 
 
void  display_electronics(struct electronics *r,int x)
{
    r=head;
    if(r==NULL)
    {
    return;
    }
    if(x==1)
	{	
	    printf("Mobiles:\n");
	    while(r!=NULL)
	    {
		    if(r->sno<3)
		    {
		        printf("\n%d price-%d ratings-%d brand-%s\n",r->sno,r->price,r->rating,r->brand);
            }
            r=r->next;	
        }
    }
    if(x==2)
	{	
	    printf("Laptops:\n");
	    while(r!=NULL)
	    {
		    if(r->sno>2&&r->sno<5)
		    {
		        printf("\n%d price-%d ratings-%d brand-%s\n",r->sno,r->price,r->rating,r->brand);
            }
            r=r->next;	
        }
    }
    if(x==3)
	{	
	    printf("Headphones:\n");
	    while(r!=NULL)
	    {
		    if(r->sno>4&&r->sno<7)
		    {
		        printf("\n%d price-%d ratings-%d brand-%s\n",r->sno,r->price,r->rating,r->brand);	
            }
            r=r->next;	
        }
    }
	if(x==4)
	{	
	    printf("Storage Media:\n");
	    while(r!=NULL)
	    {
		    if(r->sno>6&&r->sno<9)
		    {
		        printf("\n%d price-%d ratings-%d brand-%s\n",r->sno,r->price,r->rating,r->brand);
            }
            r=r->next;	
        }
    }
	if(x==5)
	{	
	    printf("TV:\n");
	    while(r!=NULL)
	    {
            
		    if(r->sno>8&&r->sno<11)
		    {
		        printf("\n%d price-%d ratings-%d brand-%s\n",r->sno,r->price,r->rating,r->brand);	
            }
            r=r->next;
        }
	}
    printf("\n");
}
 
 
int count_electronics()
{
    struct electronics *n;
    int c=0;
    n=head;
    while(n!=NULL)
    {
    n=n->next;
    c++;
    }
    return c;
}
 
 

struct cart{
int price,rating;
char brand[20];
}cart1[20];

int c=0,d=1,sum=0,j;

void search_electronics(struct electronics *n1, int choice1)
{
    if (n1->sno == choice1)
    {
        cart1[c].price=n1->price;
        cart1[c].rating=n1->rating;
        strcpy(cart1[c].brand,n1->brand);
        c++;
    }
    if (n1->next == NULL)
    {
        return;
    }
    search_electronics(n1->next,choice1);
}

int p=0;

void bill()
{
	int pincode,discount=0,delivery_charge=0,coupon_code,i,k,flag=0,choice,choice1,choice2,max_entry=0,payment,q;
	q=0;
	char contact[10];
	int coupons[10][10];
	coupons[0][0]=12349876;
	for(i=1;i<10;i++)
	for(k=1;k<10;k++)
	{
		coupons[i][k]=coupons[i-1][k-1]+1;
	}
	char name[20],address[100],email[30];
	if(p==0)
	{
		printf("\nEnter your name: ");
		scanf("%s",&name);
		printf("\nEnter your delivery address: ");
		scanf("%s",&address);
		printf("\nEnter your Email and contact number: ");
		scanf("%s",&email);
		scanf("%s",&contact);
		printf("\nEnter Pincode: ");
		scanf("%d",&pincode);
		p=1;
	}
	for(j=0;j<c;j++)
	sum=sum+cart1[j].price;
			
	printf("\n\n\nE-BILL\n\n");
	printf("NAME: %s\nADDRESS: %s\nEmail: %s\nCONTACT NO: %s\nPINCODE: %d",name,address,email,contact,pincode);
	printf("\n\nThe total bill amount is: %d.",sum);
		
	printf("Do you have any discount coupons\n1.YES\n2.NO\n");
	scanf("%d",&choice);
	if(choice==1)
	{
		do
		{
			max_entry++;
			printf("\nEnter coupon code:");
		    scanf("%d",&coupon_code);
		    for(i=0;i<10;i++)
		    for(k=0;k<10;k++)
		    {
			    if(coupon_code==coupons[i][k])
			    {
				   flag=1;
				   discount=(sum*15)/100;
				   break;
			    }
		    }
		    
		if(flag==0)
		{
		    printf("\nInvalid coupon code");
		    if(max_entry<4)
		    {
		        printf("Do you want to enter the code again?\n1.YES\n2.NO");
		        scanf("%d",&choice1);
	        }
	    }
	    else
	    break;
	    }
	    while(choice1==1&&max_entry<4);
	    if(max_entry>3)
	    printf("\nSorry maximum number of tries exceeded!");
	}
	
	if(flag==1)
	{
	   sum=sum-discount;
	   printf("\n\nYou got 15 percent discount on your total purchase.\nThe new bill amount is: %d.",sum);
	}
	
	printf("\nDo want to have next day delivery?\n(Rs.200 extra for next day delivery)\n\n1.YES\n2.NO\n");
	scanf("%d",&choice2);
	if(choice2==1)
	{
		sum=sum+200;
		printf("\nThe new bill amount is : Rs.%d",sum);
		q=1;
	}
	
	else
	{
		if(sum<2001)
		{
		    sum=sum+100;
		    printf("\nYour bill amount is: Rs.%d",sum );
		}
	}
	
	int opt,cvv;
	char card_no[16];
	
	printf("\nDo you want to proceed to pay?(y=0/n=9)\n ");
	scanf("%d",&payment);
	if(payment==0)
	{
			printf("\nChoose a payment option:\n1.Cash on Delivery\n2.Debit/Credit Card\n",&opt);
			scanf("%d",&opt);
			if(opt==1&&q==1)
			printf("\nYour product will be delivered tomorrow!\nKeep Rs.%d ready!!\n\nHAPPY SHOPPING.",sum);
			if(opt==1&&q!=1)
			printf("\nYour product will be delivered in 5-7 business days(Excluding sundays).\nKeep Rs.%d ready!!\n\nHAPPY SHOPPING.",sum);
			if(opt==2&&q==1)
			{
				printf("\nEnter the card no. : ");
				scanf("%s",&card_no);
				printf("\nEnter CVV: ");
				scanf("%d",&cvv);
				printf("\nYour transaction was successful.\nYour product will be delivered tomorrow!\n\nHAPPY SHOPPING.",sum);
			}
			if(opt==2&&q!=1)
			{
				printf("\nEnter the card no. : ");
				scanf("%s",card_no);
				printf("\nEnter CVV: ");
				scanf("%d",cvv);
				printf("\nYour transaction was successful.\nYour product will be delivered in 5-7 business days!\n\nHAPPY SHOPPING.",sum);
			}
	}
		
}

main()
{
	
	int i,num,rate,ch;
    char bran[20];
    ch=0;
    struct electronics *n;
    head=NULL;
    while(ch!=5)
    {
    printf("\nList Operations\n");
    printf("===============\n");
    printf("1.Insert\n");
    printf("2.Display\n");
    printf("3.Size\n");
    printf("4.Delete\n");
    printf("5.Exit\n");
    printf("Enter your choice : ");
    if(scanf("%d",&i)<=0){
        printf("Enter only an Integer\n");
        exit(0);
    } else {
        switch(i)
        {
        case 1:      printf("Enter the attributes to insert : ");
                 scanf("%d %d %s",&num,&rate,&bran);
                 insert_electronics(num,rate,bran);
                 break;
        case 2:     if(head==NULL)
                {
                printf("List is Empty\n");
                }
                else
                {
                printf("Element(s) in the list are : ");
                }
                break;
        case 3:     printf("Size of the list is %d\n",count_electronics());
                break;
        case 4:     if(head==NULL)
                printf("List is Empty\n");
                else{
                printf("Enter the number to delete : ");
                scanf("%d",&num);
                if(delete_electronics(num))
                    printf("%d deleted successfully\n",num);
                else
                    printf("%d not found in the list\n",num);
                }
                break;
        case 5:     ch=5;
        }
    }
    }
    
    
    
    
	int *cart[20],choice,choice1,choice2;
	struct electronics *n1;
	n1=head;
	do{
	printf("\nChoose a category to shop:\n1.Mobiles\n2.Laptops\n3.TV\n4.Headphones\n5.Storage Media\nTo display purchased item press 6\nTo see the total bill press 7\n");
	scanf("%d",&choice);
	switch (choice)
	{
		case 1:
			display_electronics(n1,choice);
			printf("Choose a serial number(or 0): ");
	        scanf("%d",&choice1);
	        if(choice1!=0)
	        {
	            search_electronics(n1,choice1);
	            sum=0;
	        }
			break;
			
	   case 2:
		    display_electronics(n1,choice);
			printf("Choose a serial number(or 0): ");
	        scanf("%d",&choice1);
	        if(choice1!=0)
	        {
	            search_electronics(n1,choice1);
	            sum=0;
	        }
			break;	
			
		case 3:
			display_electronics(n1,choice);
			printf("Choose a serial number(or 0): ");
	        scanf("%d",&choice1);
	        if(choice1!=0)
	        {
	            search_electronics(n1,choice1);
	            sum=0;
	        }
			break;
			
		case 4:
			display_electronics(n1,choice);
			printf("Choose a serial number(or 0): ");
	        scanf("%d",&choice1);
	        if(choice1!=0)
	        {
	            search_electronics(n1,choice1);
	            sum=0;
	        }
			break;
			
		case 5:
			display_electronics(n1,choice);
			printf("Choose a serial number(or 0): ");
	        scanf("%d",&choice1);
	        if(choice1!=0)
	        {
	            search_electronics(n1,choice1);
	            sum=0;
	        }
			break;
		case 6:
			if(c!=0)
			{
			    for(j=0;j<c;j++)
			    {
				    printf("\n%d %d %s\n",cart1[j].price,cart1[j].rating,cart1[j].brand);
				    sum=0;
			    }
			}
			else
			printf("No items to display\n");
			    break;
		case 7:
			bill();
			break;
	}printf("\nDo you want to continue(y=0/n=9)?");
	scanf("%d",&choice2);
	
	
}while(choice2==0);
}
