
/////////////////////////////////////////////////////
//
//       DOUBLY-LINEAR-LINKLIST
//
// FUNCTION USED:-
//
// void InsertFirst(int);
// void InsertLast(int);
// void InsertAtPos(int,int);
// void DeleteFirst();
// void DeleteLast();
// void DeleteAtPos(int);
// void Display();
// int Count();
//
// AUTHOR:-
// SHIVAJI DAS
//
// DATE:-
// 06-7-2021
//
///////////////////////////////////////////////////
#include<iostream>
using namespace std;

typedef struct node
{
   int data;
   struct node *next;
   struct node *prev;
}NODE, *PNODE;

class DoublyLL
{
    private:
    	PNODE Head;
    	int iSize;
    public:
    
    DoublyLL()
    {
    	Head=NULL;
    	iSize=0;
    }
   
   int Count()
   {
   	return iSize;
   }

    void Display()
    {
    	PNODE temp = Head;
        while(temp != NULL)
        {
            cout<<temp->data<<"\t";
            temp = temp -> next;
        }
        cout<<"\n";
    }	

    void InsertFirst(int iValue)
    {
    	PNODE newn=NULL;
    	newn=new NODE;
    	newn->data=iValue;
    	newn->next=NULL;
    	newn->prev=NULL;

    	if(Head==NULL)
    	{
    		Head=newn;
    	}
    	else
    	{
    		newn->next=Head;
    		Head->prev=newn;
    		Head=newn;
    	}
    	iSize++;
    }

    void InsertLast(int iValue)
    {
    	PNODE newn=NULL;
    	newn=new NODE;
    	newn->data=iValue;
    	newn->next=NULL;
    	newn->prev=NULL;
    	PNODE temp=Head;

    	if(Head==NULL)
    	{
    		Head=newn;
    	}
    	else
    	{
    		while(temp->next!=NULL)
    		{
    			temp=temp->next;
    		}
    		temp->next=newn;
    		newn->prev=temp;
        }
        iSize++;
    }

    void InsertAtPos(int iValue,int iPos)
    {
    	if((iPos<1)||(iPos>iSize+1))
    	{
    		return;
    	}

    	PNODE newn=NULL;
    	newn=new NODE;
    	newn->data=iValue;
    	newn->next=NULL;
    	newn->prev=NULL;
    	PNODE temp=Head;

    	if(iPos==1)
    	{
    		if(Head==NULL)
    		{
    			Head=newn;
    		}
    		else
    		{
    			newn->next=Head;
    			Head->prev=newn;
    			Head=newn;
    		}
    	}
    	else if(iPos==iSize+1)
    	{
    		if(Head==NULL)
    		{
    			Head=newn;
    		}
    		else
    		{
                while(temp->next!=NULL)
                {
                	temp=temp->next;
                }
                temp->next=newn;
                newn->prev=temp;
    		}
    	}
    	else
    	{
    		for(int i=1;i<iPos-1;i++)
    		{
    			temp=temp->next;
    		}
    		newn->next=temp->next;
            temp->next->prev=newn;  
            temp->next=newn;
            newn->prev=temp;
    	}
    	iSize++;
    }

    void DeleteFirst()
    {
    	if(Head==NULL)
    	{
    		return;
    	}
    	else if(Head->next==NULL)
    	{
    		delete Head;
    		Head=NULL;
    	}
    	else
    	{
    		Head=Head->next;
    		delete Head->prev;
    		Head->prev=NULL;
    	}
    	iSize--;
    }

    void DeleteLast()
    {
    	PNODE temp=Head;
    	if(Head==NULL)
    	{
    		return;
    	}
    	else if(Head->next==NULL)
    	{
    		delete Head;
    		Head=NULL;
    	}
    	else
    	{
    		while(temp->next->next!=NULL)
    		{
    			temp=temp->next;
    		}
    		delete temp->next;
    		temp->next=NULL;
    	}
    	iSize--;
    }

    void DeleteAtPos(int iPos)
    {
    	if((iPos<1)||(iPos>iSize))
    	{
    		return;
    	}

    	PNODE temp=Head;

    	if(iPos==1)
    	{
    		if(Head!=NULL)
    		{
    			Head=Head->next;
    			delete Head;
    			Head=NULL;
    		}
    	}
    	else
    	{
    		if(iPos==iSize)
    		{
    			 while(temp->next->next!=NULL)
		 	   {
		 		    temp=temp->next;
		 	   }
		 	    delete temp->next;
		 	    temp->next=NULL;
    		}
    		else
    		{
    			for(int i=1;i<iPos-1;i++)
    		{
    			temp=temp->next;
    		}
    		temp->next=temp->next->next;
    		delete temp->next->prev;
    		temp->next->prev=temp;
    		}
    	}
    	iSize--;
    }
};

int main()
{
	int iChoice=1,iNo=0,iP=0,iRet=0;

	DoublyLL obj1;

	while(iChoice!=0)
	{
		cout<<"Enter your choice:"<<"\n";
		cout<<"1 : Insert the node at first position"<<"\n";
		cout<<"2 : Insert the node at last position"<<"\n";
		cout<<"3 : Insert node at given position"<<"\n";
		cout<<"4 : Delete first node"<<"\n";
		cout<<"5 : Delete last node"<<"\n";
		cout<<"6 : Delete at position"<<"\n";
        cout<<"7 : Display the contents of linked list"<<"\n";
        cout<<"8 : Count the nodes of link list"<<"\n";
        cout<<"0 : Exit the application\n";
        cin>>iChoice;

        switch(iChoice)
        {
        	case 1:
        	cout<<"Enter the number\n";
        	cin>>iNo;
        	obj1.InsertFirst(iNo);
        	break;

        	case 2:
        	cout<<"Enter the number\n";
        	cin>>iNo;
        	obj1.InsertLast(iNo);
        	break;

        	case 3:
        	cout<<"Enter the number\n";
        	cin>>iNo;
        	cout<<"Enter the position\n";
        	cin>>iP;
        	obj1.InsertAtPos(iNo,iP);
        	break;

        	case 4:
        	obj1.DeleteFirst();
        	break;

        	case 5:
        	obj1.DeleteLast();
        	break;

        	case 6:
        	cout<<"Enter the position\n";
        	cin>>iP;
        	obj1.DeleteAtPos(iP);
        	break;

        	case 7:
        	obj1.Display();
        	break;

        	case 8:
        	iRet=obj1.Count();
        	cout<<"Number of node in linklist is"<<iRet<<"\n";
        	break;

        	case 0:
        	cout<<"Thanks for using the application\n";
        	break;


            default:
            printf("Please enter proper option\n");
            break;
        }
	}

	return 0;
}
