// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;

struct Node
{
  int Data;
  struct Node *Next;
};

class LinkedList
{
    private:
    Node *Head;
  public:

  void InsertFront(int Val)
  {
      Node *newNode = new Node;
      newNode->Data = Val;
      newNode->Next=NULL;
      
      if(Head==NULL)
      {
          Head=newNode;
          Head->Next=NULL;
      }
      else
      { //swap head and new node
          Node *p = Head;
          Head=newNode;
          Head->Next=p;
      }
  }
  
  void InsertLast(int Val)
  {
      Node *newNode = new Node;
      newNode->Next = NULL;
      newNode->Data = Val;
      
      Node *temp= Head;
      while(temp->Next!=NULL)
      {
          temp=temp->Next;
      }
      
      newNode->Next=NULL;
      temp->Next=newNode;
      
  }
  
  void InsertPos(int Val, int Pos)
  {
      Node *newNode = new Node;
      newNode->Data=Val;
      int LengthLL = GetLenghtLL();
      
      Node *temp= Head;
      if(Pos==1)
      {
          InsertFront(Val);
      }
      else if(Pos>1 && Pos<=LengthLL)
      {
          temp= Head;
          Node *Ptr;
          for (int i=1; i<Pos; i++)
          {
              Ptr = temp;
              temp=temp->Next;
          }
          Ptr->Next=newNode;
          newNode->Next=temp;
      }
      else if(Pos==LengthLL+1)
      {
          InsertLast(Val);

      }
      else
      {
           cout<<"Positon out of range"<<endl; 
      }
  }
  
  void DeletePos(int  Pos)
  {
      if (Head==NULL)
      {
          cout << "LL is empty" <<endl;
          return;
      }
      if (Pos==1)
      {
          Head=Head->Next;
      }
      else
      {
        int LengthLL = GetLenghtLL();
        if(Pos>1 && Pos<=LengthLL)
        {
            Node *temp= Head;
            Node *p;
            for (int i=1; i<Pos; i++)
            {
                p=temp;
                temp=temp->Next;
            }
            p->Next = temp->Next;
        }
        else
        {
            cout<<"Position out of range"<<endl;
        }
        //free(s);
      }
      
  }
  
  int GetLenghtLL()
  {
      int LengthLL = 0;
      
      Node *temp= Head;
      while(temp!=NULL)
      {
          temp=temp->Next;
          LengthLL++;
      }
      return LengthLL;
  }
  void SortLL()
  {
      if (Head == NULL)
      {
        cout<<"The List is empty"<<endl;
        return;
      }
    Node *ptr, *s;
    int value;
    
    ptr = Head;
    while (ptr != NULL)
    {
        for (s = ptr->Next;s !=NULL;s = s->Next)
        {
            if (ptr->Data > s->Data)
            {
                value = ptr->Data;
                ptr->Data = s->Data;
                s->Data = value;
            }
        }
        ptr = ptr->Next;
    }
  }
  int Search(int Val)
  {
      bool Present=false;
      
      if(Head==NULL)
      {
          cout << "LL is empty" <<endl;
          return -1;
      }
      
      Node *temp = Head;
      int counter=-1;
      while(temp!=NULL || Present!=true)
      {
          counter++;
          if(temp->Data==Val)
          {
              Present=true;
          }
          temp=temp->Next;
      }
      if(Present)
      {
        return counter-1;
      }
      else
      {
        cout <<"Not Found"<<endl;
        return -1;
      }
        
  }
  void Update(int Val, int Pos)
  {
      if (Head == NULL)
      {
        cout<<"The List is Empty"<<endl;
        return;
      }
      if(Pos==0)
      {
          cout<<"Pl enter Pos > 0"<<endl;
          return;
      }
      
      int counter=0;
      Node *temp = Head;
      for (int i = 0;i < Pos - 1;i++)
        {
            if (temp == NULL)
            {
                cout<<"There are less than "<<Pos<<" elements";
                return;
            }
            temp = temp->Next;
        }
        temp->Data = Val;  
  }
  void Reverse()
  {
      if (Head == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    if (Head->Next == NULL)
    {
        return;
    }  
    Node *Current = Head;
    Node *Prev=NULL, *Next=NULL;
    
    while(Current!=NULL)
    {
        Next=Current->Next;
        Current->Next=Prev;
        Prev = Current;
        Current = Next;
    }
    Head = Prev;
  }
  void Display()
  {
      Node *temp;
      if (Head == NULL)
      {
        cout<<"The List is Empty"<<endl;
        return;
      }
      temp=Head;
      while(temp!=NULL)
      {
          cout<<temp->Data <<endl;
          temp=temp->Next;
      }
  }
  
  LinkedList(){Head = NULL;}
};
int main() {
    
    int choice, nodes, element, position, i;
    LinkedList LL;
    //LL.Display();


    LL.InsertFront(5);
    LL.InsertFront(55);
    
    LL.InsertLast(1);
    //LL.Display();
    LL.InsertFront(22);
    LL.InsertPos(100, 5);
    LL.DeletePos(4);
    LL.Display();
    LL.SortLL();
    LL.Display();
    int c = LL.Search(55);
    cout<< "----" << c<<endl;
    LL.Update(99, 0);
    cout<< "----" <<endl;
    LL.Display();
    cout<< "----" <<endl;
    LL.Reverse();
    LL.Display();
    return 0;
}