
/////////////////////////////////////////////////////
//
//       DOUBLY-CIRCULAR-LINKLIST
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
}NODE,*PNODE;


class DoublyCL
{
  private:
  	PNODE Head;
  	PNODE Tail;
  	int iSize;
  public:

  	 DoublyCL()
  	 {
  	 	Head=NULL;
  	 	Tail=NULL;
  	 	iSize=0;
  	 }

  	 void InsertFirst(int);
  	 void InsertLast(int);
  	 void InsertAtPos(int,int);
  	 void DeleteFirst();
  	 void DeleteLast();
  	 void DeleteAtPos(int);
  	 void Display();
  	 int Count();
};


void DoublyCL::InsertFirst(int iValue)
{
   PNODE newn=new NODE;
   newn->data=iValue;
   newn->next=NULL;
   newn->prev=NULL;

   if(Head==NULL)
   {
   	  Head=newn;
   	  Tail=newn;
   }
   else
   {
   	 newn->next=Head;
   	 Head->prev=newn;
   	 Head=newn;
   }
   Tail->next=Head;
   Head->prev=Tail;
   iSize++;
}


void DoublyCL::InsertLast(int iValue)
{
   PNODE newn=new NODE;
   newn->data=iValue;
   newn->next=NULL;
   newn->prev=NULL;

   if(Head==NULL)
   {
   	  Head=newn;
   	  Tail=newn;
   }
   else
   {
   	 Tail->next=newn;
   	 newn->prev=Tail;
   	 Tail=newn;
   }
   Tail->next=Head;
   Head->prev=Tail;
   iSize++;
}


void DoublyCL::InsertAtPos(int iValue,int iPos)
{
    if((iPos < 1) || (iPos > iSize +1))
    {
        return;
    }

        PNODE newn = new NODE;
        newn->data = iValue;
        newn->next = NULL;
        newn->prev = NULL;

    if(iPos==1)
   {
    	if(Head==NULL)
        {
   	      Head=newn;
   	      Tail=newn;
        }
       else
       {
   	     newn->next=Head;
   	     Head->prev=newn;
   	     Head=newn;
       }
       Tail->next=Head;
       Head->prev=Tail;
   }
   else if(iPos==iSize+1)
   {
   	   if(Head==NULL)
   	   {
   	   	  Head=newn;
   	      Tail=newn;
   	   }
   	   else
   	   {
   	   	Tail->next=newn;
   	   	newn->prev=Tail;
   	   	Tail=newn;
   	   }
   	   Tail->next=Head;
       Head->prev=Tail;
   }
   else
   {
   	  PNODE temp=Head;
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


void DoublyCL::DeleteFirst()
{
     if(Head==NULL)
     {
     	return;
     }
     else if(Head==Tail)
     {
     	delete Head;
     	Head=NULL;
     	Tail=NULL;
     }
     else
     {
     	Head=Head->next;
     	delete Head->prev;
     	Tail->next = Head;
        Head->prev = Tail;
     }
     iSize--;
}


void DoublyCL::DeleteLast()
{
      if(Head==NULL)
     {
     	return;
     }
     else if(Head==Tail)
     {
     	delete Head;
     	Head=NULL;
     	Tail=NULL;
     }
     else
     {
     	Tail=Tail->prev;
     	delete Head->prev;
     	Tail->next = Head;
        Head->prev = Tail;
     }
     iSize--;
}


void DoublyCL::DeleteAtPos(int iPos)
{
   if((iPos<1)||(iPos>iSize))
   {
   	return;
   }

   if(iPos==1)
   {
   	 if(Head==Tail)
   	 {
   	 	delete Head;
   	 	Head=NULL;
   	 	Tail=NULL;
   	 }
   	 else
   	 {
   	 	Head=Head->next;
   	 	delete Head->prev;
   	 	Tail->next=Head;
   	 	Head->prev=Tail;
   	 }
   }
   else if(iPos==iSize)
   {
   	  if(iSize==1)
   	  {
   	  	delete Head;
   	  	Head=NULL;
   	  	Tail=NULL;
   	  }
   	  else
   	  {
   	  	Tail=Tail->prev;
   	  	delete Head->prev;
   	  	Tail->next=Head;
   	  	Head->prev=Tail;
   	  }
   }
   else
   {
   	   PNODE temp = Head;
        for(int i = 1; i < iPos-1; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete(temp->next->prev);
        temp->next->prev = temp;
   }
   iSize--;
}


void DoublyCL::Display()
{
   PNODE temp=Head;
   for(int i = 1; i<= iSize; i++)
    {
        cout<<temp->data<<"\t";
        temp = temp -> next;
    }
   cout<<"\n";
}


int DoublyCL::Count()
{
	return iSize;
}


int main()
{
	int iChoice=1,iNo=0,iRet=0,iP=0;

	DoublyCL obj;

	while(iChoice!=0)
	{
		cout<<"Enter the option\n";
		cout<<"1 :Insert first\n";
		cout<<"2 :Insert last\n";
		cout<<"3 :Insert at position\n";
		cout<<"4 :Delete first\n";
		cout<<"5 :DeleteLast\n";
		cout<<"6 :Delete at position\n";
		cout<<"7 :Display nodes\n";
		cout<<"8 :Count the nodes\n";
		cout<<"0 :Exit application\n";
		cin>>iChoice;

		switch(iChoice)
		{
			case 1:
			cout<<"Enter the number\n";
			cin>>iNo;
			obj.InsertFirst(iNo);
			break;

			case 2:
			cout<<"Enter the number\n";
			cin>>iNo;
			obj.InsertLast(iNo);
			break;

			case 3:
			cout<<"Enter the number\n";
			cin>>iNo;
			cout<<"Enter the position\n";
			cin>>iP;
			obj.InsertAtPos(iNo,iP);
			break;

			case 4:
			obj.DeleteFirst();
			break;

			case 5:
			obj.DeleteLast();
			break;

			case 6:
			cout<<"Enter the position\n";
			cin>>iP;
			obj.DeleteAtPos(iP);
			break;

			case 7:
			obj.Display();
			break;

			case 8:
			iRet=obj.Count();
			cout<<"The number of nodes are "<<iRet<<"\n";
			break;

			case 0:
			cout<<"Thanks for using my application\n";
			break;

			default:
			cout<<"Enter proper option\n";
			break;
		}
	}

	return 0;
}