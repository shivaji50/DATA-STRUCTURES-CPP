
/////////////////////////////////////////////////////
//
//       SINGLY-CIRCULAR-LINKLIST
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
}NODE,*PNODE;

class SinglyCL
{
  private:
  	PNODE Head;
  	PNODE Tail;
  	int iSize;
  public:
  	SinglyCL()
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


void SinglyCL::InsertFirst(int iNo)
{
   PNODE newn=new NODE;
   newn->data=iNo;
   newn->next=NULL;

   if(Head==NULL)
   {
   	 Head=newn;
   	 Tail=newn;
   }
   else
   {
   	newn->next=Head;
   	Head=newn;
   }
   iSize++;
   Tail->next=Head;
}


void SinglyCL::InsertLast(int iNo)
{
   PNODE newn=new NODE;
   newn->data=iNo;
   newn->next=NULL;

   if(Head==NULL)
   {
   	 Head=newn;
   	 Tail=newn;
   }
   else
   {
   	 Tail->next=newn;
   	 Tail=newn; // Tail = Tail->next; 
   }
   iSize++;
   Tail->next=Head;
}


void SinglyCL::InsertAtPos(int iNo,int iPos)
{
  if((iPos<1)||(iPos>iSize+1))
  {
  	return;
  }

  PNODE newn=new NODE;
  newn->data=iNo;
  newn->next=NULL;
  PNODE temp=Head;

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
  		Head=newn;
  	}
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
  		Tail=newn;
  	}
  }
  else
  {
  	for(int i=1;i<iPos-1;i++)
  	{
       temp=temp->next;
  	}
  	newn->next=temp->next;
  	temp->next=newn;
  }
  iSize++;
  Tail->next=Head;
}


void SinglyCL::DeleteFirst()
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
    	delete Tail->next;
        Tail->next=Head;
    }
    iSize--;

 }


void SinglyCL::DeleteLast()
{
   if(iSize==0)
    {
    	return;
    }
    else if(iSize==1)
    {
    	delete Head;
    	Head=NULL;
    	Tail=NULL;
    }
    else
    {
    	PNODE temp=Head;
    	for(int i=1;i<iSize-1;i++)
    	{
    		temp=temp->next;
    	}
    	delete Tail;
    	Tail=temp;
    	Tail->next=Head; 	
    }
    iSize--;
}


void SinglyCL::DeleteAtPos(int iPos)
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
    	delete Tail->next;
        Tail->next=Head;
    }
   }
    else if(iPos==iSize)
    {
    	PNODE temp = Head;
            int i = 0;
            for(i = 1; i < iSize-1; i++)
            {
                temp = temp -> next;
            }
            delete Tail;
            Tail = temp;
            Tail->next = Head;
    }
    else
    {
    	PNODE temp=Head;
    	PNODE target=NULL;
    	for(int i = 1; i < iPos-1; i++)
        {
            temp = temp->next;
        }
        target=temp->next;
        temp->next=target->next;
        delete target;
        Tail->next = Head;
    }
    iSize--;
}


void SinglyCL::Display()
{
    PNODE temp=Head;
    for(int i=1;i<=iSize;i++)
    {
    	cout<<temp->data<<"\t";
    	temp=temp->next;
    }
    cout<<"\n";
}


int SinglyCL::Count()
{
	return iSize;
}


int main()
{
   int iChoice=1,iValue=0,iRet=0,iPos=0;

   SinglyCL obj;

   while(iChoice!=0)
   {
   	 cout<<"Enter the option\n";
   	 cout<<"1 : Enter first node\n";
   	 cout<<"2 : Enter last node\n";
   	 cout<<"3 : Enter node at position\n";
   	 cout<<"4 : Delete first\n";
   	 cout<<"5 : Delete last\n";
   	 cout<<"6 : Delete at position\n";
   	 cout<<"7 : Display node\n";
   	 cout<<"8 : Count node\n";
   	 cout<<"0 : Exit Application\n";
   	 cin>>iChoice;

   	 switch(iChoice)
   	 {
   	 	case 1:
   	 	cout<<"Enter the number\n";
   	 	cin>>iValue;
   	 	obj.InsertFirst(iValue);
   	 	break;

   	 	case 2:
   	 	cout<<"Enter the value\n";
   	 	cin>>iValue;
   	 	obj.InsertLast(iValue);
   	 	break;

   	 	case 3:
   	 	cout<<"Enter the number\n";
   	 	cin>>iValue;
   	 	cout<<"Enter the position\n";
   	 	cin>>iPos;
   	 	obj.InsertAtPos(iValue,iPos);
   	 	break;

   	 	case 4:
   	 	obj.DeleteFirst();
   	 	break;

   	 	case 5:
   	 	obj.DeleteLast();
   	 	break;

   	 	case 6:
   	 	cout<<"Enter the position\n";
   	 	cin>>iPos;
   	 	obj.DeleteAtPos(iPos);
   	 	break;

   	 	case 7:
   	 	obj.Display();
   	 	break;

   	 	case 8:
   	 	iRet=obj.Count();
   	 	cout<<"Nodes in link list are "<<iRet<<"\n";
   	 	break;

   	 	case 0:
   	 	cout<<"Thanks for using my Application\n";
   	 	break;

   	 	default:
   	 	cout<<"Enter proper option\n";
   	 	break;
   	 }
   }
	return 0;
}