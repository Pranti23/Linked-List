#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int data;
    struct list *next;
    struct list *prev;
}l;

l *head=0;
char ch;

void create(l *);
void view(l *);
void insert();
	void insertion_beg(l *);
	void insertion_end(l *);
	void insertion_middle(l *);
void deletion();	
	void deletion_beg(l *);
	void deletion_end(l *);
	void deletion_middle(l *);
//void sort(l *);
//void search(l *);
//void reverse();

int main()
{
    int c;
    head = (l *)malloc(sizeof(l));    //ekhane head lekha mane tui check korte parbi na je head null kina , mane head null hobe na
    head->next=head;
    head->prev=NULL;
	while(1)
    {
        printf("\nMAIN MENU");
        printf("\n------------------------------------------------------\n");
        printf("\n1.Creation");
        printf("\n2.Display");
        printf("\n3.Insert");
        printf("\n4.Deletion");
//        printf("\n5.Sorting");
//        printf("\n6.Searching");
//        printf("\n7.Reverse");
		printf("\n5.Exit");
        
        printf("\n\nEnter your choice:");
        scanf("%d", &c);
        switch(c)
        {
        case 1:
            printf("\nCreating a node");
            create(head);
            break;
        case 2:
            printf("\nDisplaying the list:\n");
            view(head);
            break;   
		case 3:
            insert();
            break;    
        case 4:
            deletion();
            break;   
//        case 5:
//            printf("\nSorting the list");
//            sort(head);
//            break;
//        case 6:
//            printf("\nSearching one element in the list");
//            search(head);
//            break;
//        case 7:
//        	printf("\nReverse a List\n");..
//        	reverse();
//        	break;
        case 5:
            printf("\nExit from the list");
            exit(0);
            break;
        default:printf("\nIncorrect Choice!!");
        }
    }
}


void create(l *ptr)
{
    printf("\nEnter any data you want:");
    scanf("%d", &ptr->data);
    ptr->next = NULL;

    printf("Do you want to continue:");
    scanf(" %c", &ch);
    if (ch == 'y' || ch == 'Y')
    {
        ptr->next = (l *)malloc(sizeof(l));
        ptr->next->prev=ptr;
        ptr = ptr->next;
        create(ptr);
    }
}

void view(l *ptr)
{
	if(head==0)
	{
		printf("\nList is empty. Please, create a list first.");
		return;
	}
	while(ptr->next!=0)
	{
		printf("%d\t",ptr->data);
		ptr=ptr->next;
	}
	while(ptr!=0)
	{
		printf("%d\t",ptr->data);
		ptr=ptr->prev;
	}
}

void insert()
{
	if(head==NULL)
	{
		printf("\nList is empty.Please, create a list first.");
		return;
	}
	int ch1;
	printf("\n\nSUB MENU\n--------------------------------------\n");
	printf("\n1.Insertion at the beginning");
    printf("\n2.Insertion at the end");
    printf("\n3.Insertion in the middle");
    
	printf("\n\nEnter your choice:");
    scanf("%d", &ch1);
    switch(ch1)
    {
    	case 1:
            printf("\nInsertion at the beginning of the list");
            insertion_beg(head);
            break;

        case 2:
            printf("\nInsertion at the end of the list");
            insertion_end(head);
            break;

        case 3:
            printf("\nInsertion in the middle of the list");
            insertion_middle(head);
            break;
        default:printf("Invalid Choice!");
	}
}

void insertion_beg(l *ptr)
{
	l *temp=(l *)malloc(sizeof(l));
	printf("\nEnter the data you want:");
	scanf("%d",&temp->data);
	temp->prev=head->prev;
	temp->next=head;
	ptr->prev=temp;
	head=temp;
}

void insertion_end(l *ptr)
{
	l *temp=(l *)malloc(sizeof(l));
	printf("\nEnter the data you want:");
	scanf("%d",&temp->data);
	while(ptr->next!=0)
	{
		ptr=ptr->next;
	}
	temp->next=ptr->next;
	ptr->next=temp;
	temp->prev=ptr;
}

void insertion_middle(l *ptr)
{
	int ele;
	printf("\nEnter the element after which you want to insert:");
	scanf("%d",&ele);
	
	while(ptr->next!=0)
	{
		if(ptr->data==ele)
		{
			l *temp=(l *)malloc(sizeof(l));
			printf("\nEnter the data you want:");
			scanf("%d",&temp->data);
			temp->next=ptr->next;
			temp->prev=ptr;
			ptr->next->prev=temp;
			ptr->next=temp;
		}
		ptr=ptr->next;
	}
}

void deletion()
{
	if(head==0)
	{
		printf("\nList is empty.Please, create a list first.");
		return;
	}
	int ch1;
	printf("\n\nSUB MENU\n--------------------------------------\n");
	printf("\n1.Deletion at the beginning");
    printf("\n2.Deletion at the end");
    printf("\n3.Deletion in the middle");
    
	printf("\n\nEnter your choice:");
    scanf("%d", &ch1);
    switch(ch1)
    {
    	case 1:
            printf("\nDeleting at the beginning of the list");
            deletion_beg(head);
            break;

        case 2:
            printf("\nDeleting at the end of the list");
            deletion_end(head);
            break;

        case 3:
            printf("\nDeleting in the middle of the list");
            deletion_middle(head);
            break;
			   
        default:printf("Invalid Choice!");
	}
}

void deletion_beg(l *ptr)
{
	head=head->next;
	head->prev=NULL;
	printf("\nDeleted element is %d",ptr->data);
	free(ptr);
}

void deletion_end(l *ptr)
{
	while(ptr->next!=0)
	{
		ptr=ptr->next;
	}
	ptr->prev->next=ptr->next;
	printf("\nDeleted element is %d",ptr->data);
	free(ptr);
}

void deletion_middle(l *ptr)
{
	int ele;
	printf("\nEnter the element you want to delete:");
	scanf("%d",&ele);
	while(ptr->next!=0)
	{
		if(ptr->data==ele)
		{
			l *ptr1;
			ptr->prev->next=ptr->next;
			ptr->next->prev=ptr->prev;
			ptr1=ptr;
			ptr=ptr->next;
			free(ptr1);
			if(ptr==0)
				break;
		}
		else
		{
			ptr=ptr->next;
		}
	}
}


