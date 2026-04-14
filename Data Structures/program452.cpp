// Doubly Circular 

#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node* PNODE;

class DoublyCL
{
    private:
        PNODE first;
        PNODE last;
        int iCount;

    public:
        DoublyCL()
        {
            cout<<"Object of DoublyCL gets created.\n";
            this->first = NULL;
            this->last = NULL;
            this->iCount = 0;
        }

        void InsertFirst(int no)
        {
            PNODE newn = NULL;

            newn = new NODE;

            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            if(this->first == NULL)
            {
                this->first = this->last = newn;
                this->first->next = this->first;
                this->first->prev = this->first;
            }
            else
            {
                newn->next = this->first;
                newn->prev = this->last;

                this->first->prev = newn;
                this->last->next = newn;
                this->first = newn;
                
            }

            this->iCount++;
        }

        void InsertLast(int no)
        {
            PNODE newn = NULL;

            newn = new NODE;

            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            if(this->first == NULL)
            {
                this->first = this->last = newn;
                this->first->next = this->first;
                this->first->prev = this->first;
            }
            else
            {
                newn->prev = this->last;
                newn->next = this->first;

                this->last->next = newn;
                this->first->prev = newn;

                this->last = newn;
            }

            this->iCount++;
        }

        void DeleteFirst()
        {
            PNODE temp = NULL;

            if(this->first == NULL)
            {
                return;
            }
            else if(this->first == this->last)
            {
                delete this->first;
                this->first = this->last = NULL;
            }
            else
            {
                temp = this->first;

                this->first = this->first->next;
                this->first->prev = this->last;
                this->last->next = this->first;
                delete temp;
            }
            this->iCount--;
        }

        void DeleteLast()
        {
            PNODE temp = NULL;
            
            if(this->first == NULL)
            {
                return;
            }
            else if(this->first == this->last)
            {
                delete this->first;
                this->first = this->last = NULL;
            }
            else
            {
               temp = this->last;

               this->last = this->last->prev;
               this->last->next = this->first;
               this->first->prev = this->last;

               delete temp;
            }
            this->iCount--;
        }

        void Display()
        {
            PNODE temp = this->first;

            if(first == NULL && last == NULL)         
            {
               cout<<"Linked list is empty\n";
               return;
            }

            cout<<" <=> ";

            do
            {
                cout<<"| "<< temp->data << " |<=>";
                temp = temp->next;
            } while (temp != this->first);
            
            cout<<"\n";
        } 

        int Count()
        {
            return iCount;
        }

        void InsertAtPos(int no, int pos)
        {
            int iCnt = 0;

            PNODE newn = NULL;
            PNODE temp = NULL;
            
            if((pos < 1) || (pos > iCount + 1))
            {
                cout<<"Invalid position\n";
                return;
            }
            
            if(pos == 1)
            {
                InsertFirst(no);
            }
            else if(pos == iCount + 1)
            {
                InsertLast(no);
            }
            else
            {
                newn = new NODE;

                newn->data = no;
                newn->next = NULL;
                newn->prev = NULL;

                temp = this->first;

                for(iCnt = 1; iCnt < pos-1; iCnt++)
                {
                    temp = temp -> next;
                }

                newn->next = temp->next;
                newn->prev = temp;

                temp->next->prev = newn;
                temp->next = newn;

                this->iCount++;
            }
        }

        void DeleteAtPos(int pos)
        {
            int iCnt = 0;

            PNODE temp = NULL;
            PNODE target = NULL;
            
            if((pos < 1) || (pos > iCount))
            {
                cout<<"Invalid position\n";
                return;
            }
            
            if(pos == 1)
            {
                DeleteFirst();
            }
            else if(pos == iCount)
            {
                DeleteLast();
            }
            else
            {
                temp = this->first;

                for(iCnt = 1; iCnt < pos - 1; iCnt++)
                {
                    temp = temp -> next;
                }

                target = temp->next;

                temp->next = target->next;
                target->next->prev = temp;

                delete target;

                this->iCount--;
            }
        }
};

int main()
{
    DoublyCL obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj.DeleteFirst();
    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj.DeleteLast();

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj.InsertAtPos(105,4);

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj.DeleteAtPos(4);

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    return 0;
}