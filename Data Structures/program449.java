// Doubly Circular 

class node
{
    public int data;
    public node next;
    public node prev;

    public node(int no)
    {
        this.data = no;
        this.next = null;
        this.prev = null;
    }
}

class DoublyCL
{
    private node first;
    private node last;

    private int iCount;

    public DoublyCL()
    {
        System.out.println("Object of DoublyCL gets created.");

        this.first = null;
        this.last = null;

        this.iCount = 0;
    }

    public void InsertFirst(int no)
    {
        node newn = null;

        newn = new node(no);

        if(this.first == null)
        {
            this.first = this.last = newn;
            this.first.next = this.first;
            this.first.prev = this.first;
        }
        else
        {
            newn.next = this.first;
            newn.prev = this.last;

            this.first.prev = newn;
            this.last.next = newn;
            this.first = newn;
        }

        this.iCount++;
    }

    public void InsertLast(int no)
    {
        node newn = null;

        newn = new node(no);

        if(this.first == null)
        {
            this.first = this.last = newn;
            this.first.next = this.first;
            this.first.prev = this.first;
        }
        else
        {
            newn.prev = this.last;
            newn.next = this.first;

            this.last.next = newn;
            this.first.prev = newn;

            this.last = newn;
        }

        this.iCount++;
    }

    public void DeleteFirst()
    {
        node temp = null;

        if(this.first == null)
        {
            return;
        }
        else if(this.first == this.last)
        {
            this.first = this.last = null;
        }
        else
        {
            temp = this.first;

            this.first = this.first.next;
            this.first.prev = this.last;
            this.last.next = this.first;
        }

        System.gc();
        this.iCount--;
    }

    public void DeleteLast()
    {
        node temp = null;

        if(this.first == null)
        {
            return;
        }
        else if(this.first == this.last)
        {
            this.first = this.last = null;
        }
        else
        {
            temp = this.first;

            this.last = this.last.prev;
            this.last.next = this.first;
            this.first.prev = this.last;
        }

        System.gc();
        this.iCount--;
    }

    public void Display()
    {
        node temp = this.first;

        if(this.first == null && this.last == null)
        {
            System.out.println("Linked List is empty");
            return;
        }

        do
        {
            System.out.print("| "+temp.data+" | -> ");
            temp = temp.next;
        }while(temp != this.first);

        System.out.println("null");
    }

    public int Count()
    {
        return this.iCount;
    }

    public void InsertAtPos(int no, int pos)
    {
        int iCnt = 0;
        
        node newn = null;
        node temp = null;

        if((pos < 1) || (pos > this.iCount + 1))
        {
            System.out.println("Invalid position");
            return;
        }
        
        if(pos == 1)
        {
            InsertFirst(no);
        }
        else if(pos == this.iCount + 1)
        {
            InsertLast(no);
        }
        else
        {
            newn = new node(no);

            temp = this.first;

            for(iCnt = 1; iCnt < pos - 1; iCnt++)
            {
                temp = temp.next;
            }

            newn.next = temp.next;
            newn.prev = temp;

            temp.next.prev = newn;
            temp.next = newn;

            this.iCount++;
        }
    }

    public void DeleteAtPos(int pos)
    {
        int iCnt = 0;
        
        node temp = null;
        node target = null;

        if((pos < 1) || (pos > this.iCount))
        {
            System.out.println("Invalid position");
            return;
        }
        
        if(pos == 1)
        {
            DeleteFirst();
        }
        else if(pos == this.iCount)
        {
            DeleteLast();
        }
        else
        {
            temp = this.first;

            for(iCnt = 1; iCnt < pos - 1; iCnt++)
            {
                temp = temp.next;
            }

            target = temp.next;

            temp.next = target.next;
            target.next.prev = temp;

            System.gc();
            this.iCount--;
        }
    }
}

class program449
{
   public static void main(String A[])
    {
        DoublyCL obj = null;
        int iRet = 0;

        obj = new DoublyCL();

        obj.InsertFirst(51);
        obj.InsertFirst(21);
        obj.InsertFirst(11);

        obj.Display();

        iRet = obj.Count();
        System.out.println("Number of nodes are : "+iRet);

        obj.InsertLast(101);
        obj.InsertLast(111);
        obj.InsertLast(121);

        obj.Display();
        
        iRet = obj.Count();
        System.out.println("Number of nodes are : "+iRet);

        obj.DeleteFirst();

        obj.Display();
        
        iRet = obj.Count();
        System.out.println("Number of nodes are : "+iRet);

        obj.DeleteLast();

        obj.Display();
        
        iRet = obj.Count();
        System.out.println("Number of nodes are : "+iRet);

        obj.InsertAtPos(105,4);

        obj.Display();
        
        iRet = obj.Count();
        System.out.println("Number of nodes are : "+iRet);

        obj.DeleteAtPos(4);

        obj.Display();
        
        iRet = obj.Count();
        System.out.println("Number of nodes are : "+iRet);

        // Important for memory deallocation
        obj = null;
        System.gc();
    }
}