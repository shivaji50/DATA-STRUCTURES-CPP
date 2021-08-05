#include<iostream>
using namespace std;

template <class T>
struct node
{
	T data;
	struct node *next;
};


template <class T>
class Queue
{
  private:
  	struct node<T> *Head;
  	int iSize;
  public:
    Queue();
    void Push(T);
    int Pop();
    int Count();
    void Display();	
};

template <class T>
Queue<T>::Queue()
{
	Head=NULL;
	iSize=0;
}

template <class T>
void Queue<T>::Push(T iNo)
{
	struct node<T> *newn=NULL;
	struct node<T>  *temp;
	newn =new struct node<T>;
	newn->data=iNo;
	newn->next=NULL;

	if(Head==NULL)
	{
		Head=newn;
	}
	else
	{
		temp=Head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newn;
	}
	iSize++;
}


template <class T>
T Queue<T>::Pop()
{
	
	T iNo;
	struct node<T> *temp;

	if(iSize==0)
	{
		cout<<"Queue is Empty\n";
		return -1;
	}


	if(Head->next==NULL)
	{
        iNo=Head->data;
		delete Head;
		Head=NULL;
	}
	else
	{
		iNo=Head->data;
		temp=Head;
		Head=Head->next;
		delete temp;

	}
	iSize--;
	return iNo
}

template <class T>
void Queue<T>::Display()
{
	struct node<T> *temp = Head;
    cout<<"Elements of queue are\n";
    while(temp != NULL)
    {
        cout<<temp->data<<"\t";
        temp = temp -> next;
    }
    cout<<"\n";
}

template <class T>
int Queue<T>::Count()
{
	return iSize;
}


int main()
{
	int iChoice=1,iSize=0;
	char iNo,iRet;

	Queue<char>obj;

	while(iChoice!=0)
	{
		cout<<"1 : Push Element\n";
		cout<<"2 : Pop Element\n";
		cout<<"3 : Count Element\n";
		cout<<"4 : Display\n";
		cout<<"0 : Exit\n";
		cin>>iChoice;

		switch(iChoice)
		{
			case 1:
			cout<<"Enter The Element\n";
			cin>>iNo;
			obj.Push(iNo);
			break;

			case 2:
			iRet=obj.Pop();
			cout<<"The Poped Element is : "<<iRet<<"\n";
			break;

			case 3:
			iSize=obj.Count();
			cout<<"Number of Elements in the Queue is :"<<iSize<<"\n";
			break;

			case 4:
			obj.Display();
			break;

			case 0:
			cout<<"Thanks for using the application\n";
			break;

			default:
			cout<<"wrong option\n";
			break;
		}
	}
	return 0;
}