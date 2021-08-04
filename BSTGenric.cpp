#include<iostream>
#include<stdbool.h>
using namespace std;

template <class T>
struct node
{
	T data;
	struct node *lchild;
	struct node *rchild;
};

template <class T>
class BST
{
  private:
  	struct node<T> *Head;
  	int iSize;
  public:
    
    BST()
    {
    	Head=NULL;
    	iSize=0;
    }

    void InsertNode(struct node<T> **,T);
    void Inorder(struct node<T> *);
    void Preorder(struct node<T> *);
    void Postorder(struct node<T> *);
    void Count(struct node<T> *,int *);
    void CountParents(struct node<T> *,int *);
    void CountLeaf(struct node<T> *,int *);
    bool SearchRecursion(struct node<T> *,T);
    bool SearchNormal(T);
    int NormalCount();	
};

template <class T>
void BST<T>::InsertNode(struct node<T> **Root,T iNo)
{
	struct node<T> *temp = Head;
	struct node<T> *newn = NULL;
	newn = new struct node<T>;
	newn->data = iNo;
	newn->lchild = NULL;
	newn->rchild = NULL;

	if(Head == NULL)
	{
		
		Head = newn;
	    *Root = Head;
		iSize++;
		
	}
	else
	{
		while(1)
		{
			if(iNo > temp->data)
			{
				if(temp->rchild == NULL)
				{
					temp->rchild = newn;
					iSize++;
					break;
				}
				temp = temp->rchild;
			}
			else if(iNo < temp->data)
			{
				if(temp->lchild == NULL)
				{
					temp->lchild = newn;
					iSize++;
					break;
				}
				temp = temp->lchild;
			}
			else if(iNo == temp->data)
			{
				cout<<"Duplicate elements\n";
				delete newn;
				break;
			}
		}
	}
}

template <class T>
void BST<T>::Inorder(struct node<T> *Head1)
{
	
	if(Head1!=NULL)
	{
		
        Inorder(Head1->lchild);
        cout<<Head1->data<<"\t";
        Inorder(Head1->rchild);
	}
}

template <class T>
void BST<T>::Preorder(struct node<T> *Head1)
{
    if(Head1!=NULL)
    {
    	cout<<Head1->data<<"\t";
    	Preorder(Head1->lchild);
    	Preorder(Head1->rchild);
    }
}

template <class T>
void BST<T>::Postorder(struct node<T> *Head1)
{
	 if(Head1!=NULL)
    {
    	
    	Postorder(Head1->lchild);
    	Postorder(Head1->rchild);
    	cout<<Head1->data<<"\t";
    }
}

template <class T>
void BST<T>::Count(struct node<T> *Head1,int *i)
{
    if(Head1!=NULL)
    {
    	(*i)++;
    	Count(Head1->lchild,i);
    	Count(Head1->rchild,i);
    }
}

template <class T>
void BST<T>::CountLeaf(struct node<T> *Head1,int *i)
{
	if(Head1!=NULL)
	{
		if((Head1->lchild==NULL)&&(Head1->rchild==NULL))
		{
			(*i)++;
		}
		CountLeaf(Head1->lchild,i);
		CountLeaf(Head1->rchild,i);
	}
}


template <class T>
void BST<T>::CountParents(struct node<T> *Head1,int *i)
{
	if(Head1!=NULL)
	{
		if((Head1->lchild!=NULL)||(Head1->rchild!=NULL))
		{
			(*i)++;
		}
		CountParents(Head1->lchild,i);
		CountParents(Head1->rchild,i);
	}
}

template <class T>
bool BST<T>::SearchRecursion(struct node<T> *Head1,T iNo)
{
	if(Head1!=NULL)
	{
		if(iNo > Head1->data)
		{
			return SearchRecursion(Head1->rchild,iNo);
		}
		else if(iNo < Head1->data)
		{
			return SearchRecursion(Head1->lchild,iNo);
		}
		else if(iNo==Head1->data)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

template <class T>
bool BST<T>::SearchNormal(T iNo)
{
   struct node<T> *temp = Head;

   if(temp==NULL)
   {
   	return false;
   }
   else
   {
   	 while(1)
   	 {
   	 	 if(iNo > temp->data)
   	 	 {
   	 	 	 if(temp->rchild==NULL)
   	 	 	 {
   	 	 	 	break;
   	 	 	 }
   	 	 	 temp = temp->rchild;
   	 	 }
   	 	 else if(iNo < temp->data)
   	 	 {
   	 	 	 if(temp->lchild==NULL)
   	 	 	 {
   	 	 	 	break;
   	 	 	 }
   	 	 	 temp = temp->lchild;
   	 	 }
   	 	 else if(iNo==temp->data)
   	 	 {
   	 	 	break;
   	 	 }
   	 }
   }

   if(iNo==temp->data)
   {
   	 return true;
   }
   else
   {
   	 return false;
   }
}

template <class T>
int BST<T>::NormalCount()
{
	return iSize;
}


int main()
{
	int iChoice = 1,iRet = 0,i = 0;
    BST<double> obj;
    struct node<double> *Root = NULL;
    double iNo;

	while(iChoice!=0)
	{
		cout<<"\n";
		cout<<"Enter your choice\n";
		cout<<"1  : InsertNode\n";
		cout<<"2  : Inorder\n";
		cout<<"3  : Preorder\n";
		cout<<"4  : Postorder\n";
		cout<<"5  : Count\n";
		cout<<"6  : NormalCount\n";
		cout<<"7  : CountParents\n";
		cout<<"8  : CountLeaf\n";
		cout<<"9  : Search using Recursion\n";
		cout<<"10 : Normal Search\n";
        cout<<"0  : Exit\n";
		cin>>iChoice;

		switch(iChoice)
		{
			case 1:
			cout<<"Enter the number\n";
			cin>>iNo;
			obj.InsertNode(&Root,iNo);
			break;

			case 2:
			cout<<"Inorder traversal\n";
			obj.Inorder(Root);
			break;

			case 3:
			cout<<"Preorder traversal\n";
			obj.Preorder(Root);
			break;

			case 4:
			cout<<"Postorder traversal\n";
			obj.Postorder(Root);
			break;

			case 5:
			i = 0;
			obj.Count(Root,&i);
			cout<<"Numbers of nodes are "<<i<<"\n";
			break;

			case 6:
			iRet = obj.NormalCount();
			cout<<"Numbers of nodes are "<<iRet<<"\n";
			break;

            case 7:
            i = 0;
            obj.CountParents(Root,&i);
            cout<<"Numbers of Parents nodes are "<<i<<"\n";
			break;

			case 8:
            i = 0;
            obj.CountLeaf(Root,&i);
            cout<<"Numbers of Leaf nodes are "<<i<<"\n";
			break;

			case 9:
			cout<<"Enter the number to search\n";
			cin>>iNo;
			iRet=obj.SearchRecursion(Root,iNo);
			if(iRet==true)
			{
				cout<<iNo<<" is Present in BST\n";
			}
			else
			{
				cout<<iNo<<" is Not Present in BST\n";
			}
			break;

            case 10:
            cout<<"Enter the number to search\n";
			cin>>iNo;
			iRet=obj.SearchNormal(iNo);
			if(iRet==true)
			{
				cout<<iNo<<" is Present in BST\n";
			}
			else
			{
				cout<<iNo<<" is Not Present in BST\n";
			}
			break;

			case 0:
			cout<<"Thanks for using the application\n";
			break;

			default:
			cout<<"Wrong input\n";
			break;

		}
	}
	return 0;
}


