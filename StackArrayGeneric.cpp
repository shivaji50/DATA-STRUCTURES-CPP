#include<iostream>
#include <cstddef>
using namespace std;

template <class T>
class Stack
{
  private:
  	T *Arr;
  	int iTop;
  	int iSize;
  public:
  Stack(int);
  ~Stack();
  void Push(T);
  T Pop();
  T Peek();
  void Display();	
};

template <class T>
Stack<T>::Stack(int iNo)
{
	iTop=-1;
	iSize=iNo;
	Arr=new T[iSize];
}

template <class T>
Stack<T>::~Stack()
{
   delete []Arr;
}

template <class T>
void Stack<T>::Push(T iNo)
{
	if(iTop==iSize-1)
	{
		cout<<"Stack is Full\n";
		return;
	}
	else
	{
		iTop++;
		Arr[iTop]=iNo;
	}

}

template <class T>
T Stack<T>::Pop()
{
	if(iTop==-1)
	{
		cout<<"Stack is empty\n";
		return -1;
	}
	else
	{
		T iNo=Arr[iTop];
		iTop--;
		return iNo;
	}
}

template <class T>
T Stack<T>::Peek()
{
	if(iTop==-1)
	{
		cout<<"Stack is empty\n";
		return -1;
	}
	else
	{
		int iNo=Arr[iTop];
		return iNo;
	}
}

template <class T>
void Stack<T>::Display()
{
	if(iTop==-1)
	{
		cout<<"Stack is empty\n";
		
	}
	else
	{
		for(int i=0;i<=iTop;i++)
		{
			cout<<Arr[i]<<"\t";
		}
		cout<<"\n";
	}
}


int main()
{
	int iChoice=1,iSize=0;
	
	cout<<"Enter the size of the Array\n";
	cin>>iSize;

	Stack<char>obj(iSize);
   char iRet='\0';
   char iNo='\0';
	while(iChoice!=0)
	{
		cout<<"1 : Push Elements in Stack\n";
		cout<<"2 : Pop Elements in stack\n";
		cout<<"3 : Peek Elements in Stack\n";
		cout<<"4 : Display all Elements from stack\n";
		cout<<"0 :Exit\n";
		cin>>iChoice;

        switch(iChoice)
        {
        	case 1:
        	cout<<"Enter the Element\n";
        	cin>>iNo;
        	obj.Push(iNo);
        	break;

        	case 2:
        	iRet=obj.Pop();
        	cout<<"The Poped Elements is :"<<iRet<<"\n";
        	break;

        	case 3:
        	iRet=obj.Peek();
        	cout<<"The Topmost Element in the Stack is:"<<iRet<<"\n";
        	break;

        	case 4:
        	obj.Display();
        	break;

        	case 0:
        	cout<<"Thanks for using the Application\n";
        	//delete obj;   //Do this only when object is created dynamicaly
        	break;

        	default:
        	cout<<"Wrong option\n";
        	break;
        }
	}
	return 0;

}