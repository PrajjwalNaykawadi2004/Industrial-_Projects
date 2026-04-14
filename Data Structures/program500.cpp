///////////////////////////////////////////////////
//      Generalised Data Structure Library
///////////////////////////////////////////////////

/*
---------------------------------------------------------------------------------------
Type                    Name of class for node      Name of class for Functionality
---------------------------------------------------------------------------------------
Singly Linear            SinglyLLLnode               SinglyLLL          Done
Singly Cirular           SinglyCLLnode               SinglyCLL          Done
Doubly Linear            DoublyLLLnode               DoublyLLL          Done
Doubly Circular          DoublyCLLnode               DoublyCLL          Done
Stack                    Stacknode                   Stack              Done
Queue                    Queuenode                   Queue              Done
---------------------------------------------------------------------------------------
*/

#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////
//          Singly Linear LinlkedList using Generic Approach
///////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class SinglyLLLnode
{
    public:
        T data;
        SinglyLLLnode<T> *next;

        SinglyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     SinglyLLL (Constructor)
//  Input :             Position
//  Output :            Nothing
//  Description :       Initializes empty Singly linear linked list
//  Author :            Prajjwal Dilip Naykawadi
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
class SinglyLLL
{
    private:        
        SinglyLLLnode<T> * first;
        int iCount;

    public:
        SinglyLLL();
        void InsertFirst(T);
        void InsertLast(T);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(T,int);
        void DeleteAtPos(int);
};

template<class T>
SinglyLLL<T> :: SinglyLLL()
{
    cout<<"Object of SinglyLL gets created.\n";
    this->first = NULL;
    this->iCount = 0;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertFirst
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at first position
//  Author :            Prajjwal Dilip Naykawadi
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: InsertFirst(T no)
{
    SinglyLLLnode<T> * newn = NULL;

    newn = new SinglyLLLnode<T>(no);

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertLast
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at last position
//  Author :            Prajjwal Dilip Naykawadi
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> ::InsertLast(T no)
{
    SinglyLLLnode<T> * newn = NULL;
    SinglyLLLnode<T> * temp = NULL;

    newn = new SinglyLLLnode<T>(no);

    if(this->iCount == 0)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }
    this->iCount++;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteFirst
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to delete first node from linked list
//  Author :            Prajjwal Dilip Naykawadi
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> ::DeleteFirst()
{
    SinglyLLLnode<T> * temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        this->first = this->first -> next;
        delete temp;
    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteLast
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to delete Last node from linked list
//  Author :            Prajjwal Dilip Naykawadi
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> ::DeleteLast()
{
    SinglyLLLnode<T> * temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)  
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp -> next;
        }

        delete temp->next;
        temp->next = NULL;

    }
    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display
//  Input :             Nothing
//  Output :            Displays all elements of linked list
//  Description :       Used to display linked list elements
//  Author :            Prajjwal Dilip Naykawadi
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> ::Display()
{
    SinglyLLLnode<T> * temp = NULL;
    int iCnt = 0;

    temp = this->first;

    for(iCnt = 1; iCnt <= this->iCount; iCnt++)
    {
        cout<<"| "<<temp->data<<" |-> ";
        temp = temp->next;
    }

    cout<<"NULL\n";
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count
//  Input :             Nothing
//  Output :            Integer value (number of nodes)
//  Description :       Returns total number of nodes in linked list
//  Author :            Prajjwal Dilip Naykawadi
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
int SinglyLLL<T> ::Count()
{
    return this->iCount;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertAtPos
//  Input :             Data of node, Position
//  Output :            Nothing
//  Description :       Inserts node at specified position
//  Author :            Prajjwal Dilip Naykawadi
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> ::InsertAtPos(T no, int pos)
{
    SinglyLLLnode<T> * temp = NULL;
    SinglyLLLnode<T> * newn = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount + 1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new SinglyLLLnode<T>(no);

        temp = this->first;
        
        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        this->iCount++;
    }
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteAtPos
//  Input :             Position
//  Output :            Nothing
//  Description :       Deletes node from specified position
//  Author :            Prajjwal Dilip Naykawadi
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> ::DeleteAtPos(int pos)
{
    SinglyLLLnode<T> * temp = NULL;
    SinglyLLLnode<T> * target = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;
        
        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp->next = target->next;
        delete target;

        this->iCount--;
    }
}

///////////////////////////////////////////////////////////////////////
//          Doubly Linear Linlked List using Generic Approach
///////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class DoublyLLLnode
{
    public:
        T data;
        DoublyLLLnode *next;
        DoublyLLLnode *prev;

        DoublyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DoublyLLL (Constructor)
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Initializes empty Doubly linear linked list
//  Author :            Prajjwal Dilip Naykawadi
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
class DoublyLLL
{
    private:
        DoublyLLLnode<T> * first;
        int iCount;

    public:
        DoublyLLL();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();
};

template<class T>
DoublyLLL<T> :: DoublyLLL()
{
    cout<<"Linked List gets created\n";

    this->first = NULL;
    this->iCount = 0;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertFirst
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Inserts new node at the beginning of doubyLL
//  Author :            Prajjwal Dilip Naykawadi
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> ::InsertFirst(T no)
{
    DoublyLLLnode<T> *newn = NULL;
    
    newn = new DoublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }
    this->iCount++;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertLast
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Inserts new node at the end of doubyLL
//  Author :            Prajjwal Dilip Naykawadi
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> ::InsertLast(T no) 
{
    DoublyLLLnode<T> *newn = NULL;
    DoublyLLLnode<T> *temp = NULL;

    newn = new DoublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;
        
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }
    this->iCount++;    
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertAtPos
//  Input :             Data of node, Position
//  Output :            Nothing
//  Description :       Inserts new node at the specified position in doubyLL
//  Author :            Prajjwal Dilip Naykawadi
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> ::InsertAtPos(T no,int pos)
{
    DoublyLLLnode<T> *temp = NULL;
    DoublyLLLnode<T> *newn = NULL;

    int iCnt = 0;

    if((pos < 1) || (pos > this->iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }  

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new DoublyLLLnode<T>(no);

        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        this->iCount++;
    }
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteFirst
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Deletes first node from doubyLL
//  Author :            Prajjwal Dilip Naykawadi
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> ::DeleteFirst()
{
    if(this->first == NULL)                
    {
        return;
    }
    else if(this->first->next == NULL)    
    {
        delete this->first;
        this->first = NULL;
    }
    else                                   
    {
        this->first = this->first->next;
        delete this->first->prev;
        this->first->prev = NULL;
    }

    this->iCount--;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteLast
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Deletes last node from doubyLL
//  Author :            Prajjwal Dilip Naykawadi
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> ::DeleteLast()
{
    DoublyLLLnode<T> *temp = NULL;

    if(this->first == NULL)                 
    {
        return;
    }
    else if(this->first->next == NULL)      
    {
        delete this->first;
        this->first = NULL;
    }
    else                                  
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    this->iCount--;    
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteAtPos
//  Input :             Position
//  Output :            Nothing
//  Description :       Deletes node from specified position in doubyLL
//  Author :            Prajjwal Dilip Naykawadi
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> ::DeleteAtPos(int pos)
{
    DoublyLLLnode<T> *temp = NULL;
    int iCnt = 0;

    if((pos < 1) || (pos > this->iCount))
    {
        cout<<"Invalid position\n";
        return;
    }  

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        this->iCount--;
    }    
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display
//  Input :             Nothing
//  Output :            Display all elements of doublyLL
//  Description :       Displays elements in forward direction
//  Author :            Prajjwal Dilip Naykawadi
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> ::Display()
{
    DoublyLLLnode<T> *temp = NULL;
    
    temp = this->first;

    cout<<"\nNULL<=>";
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |<=>";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count
//  Input :             Nothing
//  Output :            Integer value (number of nodes)
//  Description :       Returns total number of nodes in doublyLL
//  Author :            Prajjwal Dilip Naykawadi
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
int DoublyLLL<T> ::Count()
{
    return this->iCount;
}

///////////////////////////////////////////////////////////////////////
// Singly Circular Linked List using Generic Approach
///////////////////////////////////////////////////////////////////////

#pragma pack(1)

template<class T>
class SinglyCLLnode
{
public:
    T data;
    SinglyCLLnode<T> *next;

    SinglyCLLnode(T no)
    {
        this->data = no;
        this->next = NULL;
    }
};

template<class T>
class SinglyCLL
{
private:
    SinglyCLLnode<T> *first;
    SinglyCLLnode<T> *last;
    int iCount;

public:
    SinglyCLL();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);

    void Display();
    int Count();
};

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     SinglyCLL
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Initializes empty Singly Circular Linked List
//  Author :            Prajjwal Dilip Naykawadi
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
SinglyCLL<T> :: SinglyCLL()
{
    cout<<"Object of SinglyCL gets created.\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertFirst
//  Input :             Data to insert
//  Output :            Nothing
//  Description :       Inserts new node at the beginning of SinglyCLL
//  Author :            Prajjwal Dilip Naykawadi
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T> ::InsertFirst(T no)
{
    SinglyCLLnode<T> *newn = new SinglyCLLnode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        newn->next = this->first;
        this->first = newn;
    }
    this->last->next = this->first;
    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertLast
//  Input :             Data to insert
//  Output :            Nothing
//  Description :       Inserts new node at the end of SinglyCLL
//  Author :            Prajjwal Dilip Naykawadi
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T> ::InsertLast(T no)
{
    SinglyCLLnode<T> *newn = new SinglyCLLnode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        this->last = newn;
    }
    this->last->next = this->first;
    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertAtPos
//  Input :             Data, Position
//  Output :            Nothing
//  Description :       Inserts node at specified position in SinglyCLL
//  Author :            Prajjwal Dilip Naykawadi
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T> ::InsertAtPos(T no, int pos)
{
    if(pos < 1 || pos > this->iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }
    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        SinglyCLLnode<T> *newn = new SinglyCLLnode<T>(no);
        SinglyCLLnode<T> *temp = this->first;

        for(int i=1; i<pos-1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
        this->iCount++;
    }
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteFirst
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Deletes first node from SinglyCLL
//  Author :            Prajjwal Dilip Naykawadi
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T> ::DeleteFirst()
{
    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        SinglyCLLnode<T> *temp = this->first;
        this->first = this->first->next;
        delete temp;
        this->last->next = this->first;
    }
    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteLast
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Deletes last node from SinglyCLL
//  Author :            Prajjwal Dilip Naykawadi
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T> ::DeleteLast()
{
    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        SinglyCLLnode<T> *temp = this->first;
        while(temp->next != this->last)
        {
            temp = temp->next;
        }
        delete this->last;
        this->last = temp;
        this->last->next = this->first;
    }
    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteAtPos
//  Input :             Position
//  Output :            Nothing
//  Description :       Deletes node at specified position from SinglyCLL
//  Author :            Prajjwal Dilip Naykawadi
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T> ::DeleteAtPos(int pos)
{
    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid position\n";
        return;
    }
    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        DeleteLast();
    }
    else
    {
        SinglyCLLnode<T> *temp = this->first;
        SinglyCLLnode<T> *target = NULL;

        for(int i=1; i<pos-1; i++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        delete target;
        this->iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Displays all nodes from SinglyCLL
//  Author :            Prajjwal Dilip Naykawadi
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T> ::Display()
{
    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Linked List is empty\n";
        return;
    }
    SinglyCLLnode<T> *temp = this->first;
    do
    {
        cout<<"| "<<temp->data<<" |<=> ";
        temp = temp->next;
    }while(temp != this->first);
    cout<<"NULL\n";
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count
//  Input :             Nothing
//  Output :            Number of nodes
//  Description :       Returns toatal number of nodes in SinglyCLL
//  Author :            Prajjwal Dilip Naykawadi
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
int SinglyCLL<T> ::Count()
{
    return this->iCount;
}

///////////////////////////////////////////////////////////////////////
// Doubly Circular Linked List using Generic Approach
///////////////////////////////////////////////////////////////////////

#pragma pack(1)

template<class T>
struct DoublyCLLnode
{
    T data;
    DoublyCLLnode *next;
    DoublyCLLnode *prev;
};

template<class T>
class DoublyCLL
{
private:
    DoublyCLLnode<T> *first;
    DoublyCLLnode<T> *last;
    int Count;

public:
    DoublyCLL();
    void Display();
    int CountNode();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};


/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DoublyCLL (Constructor)
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Initializes empty Doubly Circular Linked List
//  Author :            Prajjwal Dilip Naykawadi
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
DoublyCLL<T> :: DoublyCLL()
{
    first = NULL;
    last = NULL;
    Count = 0;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertFirst
//  Input :             Data of node (T no)
//  Output :            Nothing
//  Description :       Inserts new node at the beginning of DoublyCLL
//  Author :            Prajjwal Dilip Naykawadi
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> ::InsertFirst(T no)
{
    DoublyCLLnode<T> *newn = new DoublyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)      // Empty list
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }

    last->next = first;
    first->prev = last;

    Count++;
}


/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertLast
//  Input :             Data of node (T no)
//  Output :            Nothing
//  Description :       Inserts new node at the end of DoublyCLL
//  Author :            Prajjwal Dilip Naykawadi
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> ::InsertLast(T no)
{
    DoublyCLLnode<T> *newn = new DoublyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)     // Empty list
    {
        first = newn;
        last = newn;
    }
    else
    {
        last->next = newn;
        newn->prev = last;
        last = newn;
    }

    last->next = first;
    first->prev = last;

    Count++;
}


/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertAtPos
//  Input :             Data of node (T no), Position (int ipos)
//  Output :            Nothing
//  Description :       Inserts node at the specified position in DoublyCLL
//  Author :            Prajjwal Dilip Naykawadi
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> ::InsertAtPos(T no, int ipos)
{
    if(ipos < 1 || ipos > Count+1)
    {
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == Count+1)
    {
        InsertLast(no);
    }
    else
    {
        DoublyCLLnode<T> *newn = new DoublyCLLnode<T>;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        DoublyCLLnode<T> *temp = first;

        for(int i = 1; i < ipos-1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;

        Count++;
    }
}


/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteFirst
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Deletes the first node from DoublyCLL
//  Author :            Prajjwal Dilip Naykawadi
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> ::DeleteFirst()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete last->next;   
        first->prev = last;
        last->next = first;
    }

    Count--;
}


/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteLast
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Deletes the last node from DoublyCLL
//  Author :            Prajjwal Dilip Naykawadi
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> ::DeleteLast()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        last = last->prev;
        delete last->next;   // old last
        last->next = first;
        first->prev = last;
    }

    Count--;
}


/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteAtPos
//  Input :             Position (int ipos)
//  Output :            Nothing
//  Description :       Deletes node from the specified position in DoublyCLL
//  Author :            Prajjwal Dilip Naykawadi
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> ::DeleteAtPos(int ipos)
{
    if(ipos < 1 || ipos > Count)
    {
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == Count)
    {
        DeleteLast();
    }
    else
    {
        DoublyCLLnode<T> *temp = first;

        for(int i = 1; i < ipos-1; i++)
        {
            temp = temp->next;
        }

        DoublyCLLnode<T> *tempDelete = temp->next;
        
        temp->next = tempDelete->next;
        tempDelete->next->prev = temp;

        delete tempDelete;

        Count--;
    }
}


/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display
//  Input :             Nothing
//  Output :            Displays all nodes from DoublyCLL
//  Description :       Displays elements in forward direction from first 
//                      to last
//  Author :            Prajjwal Dilip Naykawadi
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> ::Display()
{
    if(first == NULL && last == NULL)
    {
        cout<<"Linked list is empty\n";
        return;
    }

    DoublyCLLnode<T> *temp = first;

    do
    {
        cout<<"| "<<temp->data<<" |<=> ";
        temp = temp->next;
    }while(temp != first);

    cout<<"NULL\n";
}


/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count
//  Input :             Position
//  Output :            Integer (Number of nodes)
//  Description :       Returns total number of nodes in DoublyCLL
//  Author :            Prajjwal Dilip Naykawadi
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
int DoublyCLL<T> ::CountNode()
{
    return Count;
}

///////////////////////////////////////////////////////////////////////
//                  Stack using Generic Approach
///////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class Stacknode
{
    public:
        T data;
        Stacknode<T> *next;

        Stacknode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template<class T>
class Stack
{
    private:
        Stacknode<T> *first;
        int iCount;

    public:
        Stack();

        void push(T);     
        T pop();
        T peep();
        void Display();
        int Count();
};

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Stack
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Initializes empty stack
//  Author :            Prajjwal Dilip Naykawadi
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
Stack<T> :: Stack()
{
    cout<<"Stack gets created succesfully...\n";

    this->first = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Push
//  Input :             Generic (T)
//  Output :            Nothing
//  Description :       Inserts element at top of stack
//  Author :            Prajjwal Dilip Naykawadi
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void Stack<T> :: push(T no)
{
    Stacknode<T> *newn = NULL;

    newn = new Stacknode<T>(no);

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Pop
//  Input :             Nothing
//  Output :            Returns popped element (T)
//  Description :       Removes top element and returns it
//  Author :            Prajjwal Dilip Naykawadi
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
T Stack<T> :: pop()
{
    T Value = 0;
    Stacknode<T> *temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
        return -1;
    }

    Value = this->first->data;

    this->first = this->first->next;
    delete temp;

    this->iCount--;

    return Value;
}   

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Peep
//  Input :             Nothing
//  Output :            Returns top element (T)
//  Description :       Displays elements at top without removal
//  Author :            Prajjwal Dilip Naykawadi
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
T Stack<T> :: peep()
{
    T Value = 0;

    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
        return -1;
    }

    Value = this->first->data;    
    return Value;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Displays all elements of stack
//  Author :            Prajjwal Dilip Naykawadi
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void Stack<T> :: Display()
{
    Stacknode<T> *temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
        return;
    }

    while(temp != NULL)
    {
        cout<<"|\t"<<temp->data<<"\t|\n";
        temp = temp->next;
    }
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count
//  Input :             Nothing
//  Output :            Returns number of elements in stack
//  Description :       Returns the total number of elements present in stack
//  Author :            Prajjwal Dilip Naykawadi
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
int Stack<T> :: Count()
{
    return this->iCount;
}

///////////////////////////////////////////////////////////////////////
//          Queue using Generic Approach
///////////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class Queuenode
{
    public:
        T data;
        Queuenode<T> *next;

        Queuenode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template<class T>
class Queue
{
    private:
        Queuenode<T> *first;
        Queuenode<T> *last;

        int iCount;
    
    public:
        Queue();

        void enqueue(T);                          
        T dequeue();                              
        void Display();
        int Count();
};

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Queue
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Initializes empty generic queue
//  Author :            Prajjwal Dilip Naykawadi
//  Date :              07/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
Queue<T> :: Queue()
{
    cout<<"Queue gets created successfully...\n";

    this->first = NULL;
    this->last = NULL;

    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     enqueue
//  Input :             T (Generic Data)
//  Output :            Nothing
//  Description :       Inserts data at near end of queue
//  Author :            Prajjwal Dilip Naykawadi
//  Date :              07/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void Queue<T> :: enqueue(T no)
{
    Queuenode<T> *newn = NULL;
    
    newn = new Queuenode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        this->last = this->last->next;
    }

    this->iCount++;
}   

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     dequeue
//  Input :             Nothing
//  Output :            T (Deleted Element)
//  Description :       Removes data from front end of queue
//  Author :            Prajjwal Dilip Naykawadi
//  Date :              07/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
T Queue<T> :: dequeue()   
{
    T Value = 0;
    Queuenode<T> *temp = this->first;

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Queue is empty\n";
        return -1;
    }

    Value = this->first->data;

    this->first = this->first->next;
    delete temp;

    this->iCount--;

    return Value;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Displays all elements of queue from front to user
//  Author :            Prajjwal Dilip Naykawadi
//  Date :              07/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void Queue<T> :: Display()
{
    Queuenode<T> *temp = this->first;

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Queue is empty\n";
        return;
    }

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | - ";
        temp = temp->next;
    } 
    
    cout<<"\n";
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count
//  Input :             Nothing
//  Output :            Integer
//  Description :       Returns number of elements present in queue
//  Author :            Prajjwal Dilip Naykawadi
//  Date :              07/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
int Queue<T> :: Count()
{
    return this->iCount;
}

//////////////////////////////// End of Library //////////////////////////////////

int main()
{
    cout << "\n===== Singly Linear Linked List =====\n\n";

    SinglyLLL<int> *obj = new SinglyLLL<int>();

    int iRet = 0;

    obj->InsertFirst(51);
    obj->InsertFirst(21);
    obj->InsertFirst(11);

    obj->Display();

    iRet = obj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj->InsertLast(101);
    obj->InsertLast(111);
    obj->InsertLast(121);
    
    obj->Display();

    iRet = obj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    obj->DeleteFirst();
    obj->Display();

    iRet = obj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    obj->DeleteLast();

    obj->Display();

    iRet = obj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    obj->InsertAtPos(105,4);

    obj->Display();

    iRet = obj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    obj->DeleteAtPos(4);

    obj->Display();

    iRet = obj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    delete obj;

    ///////////////////////////////////////////////////////////////////////
    
    cout << "\n===== Doubly Linear Linked List =====\n\n";

    DoublyLLL<char> *dobj = new DoublyLLL<char>();

    dobj->InsertFirst('A');
    dobj->InsertFirst('B');
    dobj->InsertFirst('C');
    
    dobj->Display();

    cout<<"Number of elements are : "<<dobj->Count()<<"\n";

    dobj->InsertLast('X');
    dobj->InsertLast('Y');
    dobj->InsertLast('Z');
    
    dobj->Display();

    cout<<"Number of elements are : "<<dobj->Count()<<"\n";

    dobj->DeleteFirst();

    dobj->Display();

    cout<<"Number of elements are : "<<dobj->Count()<<"\n";

    dobj->DeleteLast();

    dobj->Display();

    cout<<"Number of elements are : "<<dobj->Count()<<"\n";

    dobj->InsertAtPos('$',4);

    dobj->Display();

    cout<<"Number of elements are : "<<dobj->Count()<<"\n";

    dobj->DeleteAtPos(4);

    dobj->Display();

    cout<<"Number of elements are : "<<dobj->Count()<<"\n";
    
    delete dobj;

    ///////////////////////////////////////////////////////////////////////////

    cout << "\n===== Singly Circular Linked List =====\n\n";

    SinglyCLL<int> *cobj = new SinglyCLL<int>();

    cobj->InsertFirst(51);
    cobj->InsertFirst(21);
    cobj->InsertFirst(11);

    cobj->Display();
    iRet = cobj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    cobj->InsertLast(101);
    cobj->InsertLast(111);

    cobj->Display();
    iRet = cobj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    cobj->DeleteFirst();

    cobj->Display();
    iRet = cobj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    cobj->DeleteLast();

    cobj->Display();
    iRet = cobj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    cobj->InsertAtPos(75,2);

    cobj->Display();
    iRet = cobj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    cobj->DeleteAtPos(2);

    cobj->Display();
    iRet = cobj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    ///////////////////////////////////////////////////////////////////////////

    cout << "\n===== Doubly Circular Linked List =====\n\n";

    DoublyCLL<int> *scobj = new DoublyCLL<int>();

    scobj->InsertFirst(51);
    scobj->InsertFirst(21);
    scobj->InsertFirst(11);

    scobj->Display();
    iRet = scobj->CountNode();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    scobj->InsertLast(101);
    scobj->InsertLast(111);

    scobj->Display();
    iRet = scobj->CountNode();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    scobj->DeleteFirst();

    scobj->Display();
    iRet = scobj->CountNode();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    scobj->DeleteLast();

    scobj->Display();
    iRet = scobj->CountNode();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    scobj->InsertAtPos(75,2);

    scobj->Display();
    iRet = scobj->CountNode();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    scobj->DeleteAtPos(2);

    scobj->Display();
    iRet = scobj->CountNode();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    ///////////////////////////////////////////////////////////////////////////

    cout << "\n===== Stack =====\n\n";

    Stack<char> *sobj = new Stack<char>();

    sobj->push('a');
    sobj->push('b');
    sobj->push('c');
    sobj->push('d');

    sobj->Display();

    cout<<"Number of elements in Stack are : "<<sobj->Count()<<"\n";

    cout<<"Return value of peep is : "<<sobj->peep()<<"\n";

    sobj->Display();

    cout<<"Number of elements in Stack are : "<<sobj->Count()<<"\n";

    cout<<"Poped elements is : "<<sobj->pop()<<"\n";

    sobj->Display();

    cout<<"Number of elements in Stack are : "<<sobj->Count()<<"\n";

    cout<<"Poped elements is : "<<sobj->pop()<<"\n";

    sobj->Display();

    cout<<"Number of elements in Stack are : "<<sobj->Count()<<"\n";

    sobj->push('e');

    sobj->Display();

    cout<<"Number of elements in Stack are : "<<sobj->Count()<<"\n";

    delete sobj;

    ///////////////////////////////////////////////////////////////////

    cout << "\n===== Queue =====\n\n";

    Queue<double> *qobj = new Queue<double>();

    qobj->enqueue(11.56789);
    qobj->enqueue(21.56789);
    qobj->enqueue(51.56789);
    qobj->enqueue(101.56789);
    
    qobj->Display();

    cout<<"Number of elements in queue are : "<<qobj->Count()<<"\n";

    cout<<"Removed element is : "<<qobj->dequeue()<<"\n";
    
    qobj->Display();

    cout<<"Number of elements in queue are : "<<qobj->Count()<<"\n";

    cout<<"Removed element is : "<<qobj->dequeue()<<"\n";
    
    qobj->Display();

    cout<<"Number of elements in queue are : "<<qobj->Count()<<"\n";

    qobj->enqueue(121.56789);

    qobj->Display();

    cout<<"Number of elements in queue are : "<<qobj->Count()<<"\n";

    delete qobj;
    
    return 0;
}