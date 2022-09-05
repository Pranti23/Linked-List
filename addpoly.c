#include<stdio.h>
#include<stdlib.h>

typedef struct poly
{
	int c;
	int e;
	struct poly *next;
}p;

p *head1=0, *head2=0, *result, *temp;
char ch;

void create(p *);
void sort(p *);
void display(p *);
p *add();


int main()
{
	head1=(p *)malloc(sizeof(p));
	create(head1);
	sort(head1);
	display(head1);
	head2=(p *)malloc(sizeof(p));
	create(head2);
	sort(head2);
	display(head2);
	result=add();
	display(result);
}


void create(p *pt)
{
	printf("\nEnter the element for c:");
	scanf("%d",&pt->c);
	printf("\nEnter the element for exp:");
	scanf("%d",&pt->e);
	pt->next=0;
//	if(head==0)
//	{
//		head=temp;
//		current=temp;   /
//	}
//	else
//	{
//		current->next=temp;
//		current=temp;
//	}
	printf("\nDo you want to continue?");
	scanf(" %c",&ch);
	if(ch=='Y' || ch=='y')
	{
		pt->next=(p *)malloc(sizeof(p));
		pt=pt->next;
		create(pt);
	}
}

void sort(p *ptr)
{
	p* ptr1;
    int temp;
    for(;ptr->next!=NULL;ptr = ptr->next)
    {
        for(ptr1=ptr->next;ptr1!=NULL;ptr1 = ptr1->next)
        {
            if((ptr->e) < (ptr1->e))
            {
                temp = ptr->e;
                ptr->e = ptr1->e;
                ptr1->e = temp;
                
                temp = ptr->c;
                ptr->c = ptr1->c;
                ptr1->c = temp;
            }
        }
    }
}


p *add()
{
	p *poly1=head1;
	p *poly2=head2;
	p *poly;
	p *head3=0;
	while(poly1 || poly2)
	{
		temp=(p *)malloc(sizeof(p));
		if((poly1->e) > (poly2->e))
		{
			if(head3==0)
			{
				head3=temp;
				poly=temp; 
			}
			else
			{
				poly->next=temp;
				poly=temp;
			}
			poly->c=poly1->c;
			poly->e=poly1->e;
			poly->next=0;
			poly1=poly1->next;
		}
		
		else if(poly1->e < poly2->e)
		{
			if(head3==0)
			{
				head3=temp;
				poly=temp; 
			}
			else
			{
				poly->next=temp;
				poly=temp;
			}
			poly->c=poly2->c;
			poly->e=poly2->e;
			poly->next=0;
			poly2=poly2->next;
		}
		
		else if(poly1!=0)
		{
			poly->next=temp;
			poly=temp;
			poly->c=poly1->c;
			poly->e=poly1->e;
			poly->next=0;
			poly1=poly1->next;
		}
		else if(poly2!=0)
		{
			poly->next=temp;
			poly=temp;
			poly->c=poly2->c;
			poly->e=poly2->e;
			poly->next=0;
			poly2=poly2->next;
		}
		else 
		{
			if(head3==0)
			{
				head3=temp;
				poly=temp; 
			}
			else
			{
				poly->next=temp;
				poly=temp;
			}
			poly->c=poly1->c+poly2->c;
			poly->e=poly1->e+poly2->e;
			poly->next=0;
		}
	}
	return head3;
}


void display(p *ptr)
{
	printf("\nDisplaying the list:\n");
	while(ptr!=0)
	{
		printf("%dx^%d \t",ptr->c,ptr->e);
		ptr=ptr->next;	
	}
}
