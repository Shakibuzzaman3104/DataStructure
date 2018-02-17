
package queue;

import java.util.Scanner;

class Queue_Operate
{
    int Front=-1;
    int Rear=-1;
    final int MAX=5;
    int[] queue = new int[MAX];
    
    boolean isEmpty()
    {
       return Front==-1 && Rear==-1;
    }
    boolean isFull()
    {
       return (Rear+1)%MAX==Front;
    }
    
    void enqueue(int data)
    {
        try
        {
            if(isEmpty())
             {
                Front=Rear=0;
             }
                queue[Rear]=data;
                Rear=Rear+1;
        }
        catch(ArrayIndexOutOfBoundsException E)
        {
            System.out.println("Queue is Full!!");
        }
        
    }
    
    void dequeue()
    {
        if(isEmpty())
        {
            System.out.println("Queue is Empty, Nothing To Dequeue");
            return;
        }
       else if(Front==Rear)
        {
            Front=Rear=-1;
        }
        else
            Front++;
    }
    
    void print()
    {
        for (int i=Front;i<Rear;i++)
        { 
            System.out.println(queue[i]);
        }
    }
}

public class Queue {

    static Scanner sc=new Scanner(System.in);
    static Queue_Operate queue;
    public static void main(String[] args) {
        queue=new Queue_Operate();
        while(true)
        {
            System.out.println("\nSelect your Operation ? : \n1.EnQueue  \n2.Dequeue \n3.Print");
            Byte ch=sc.nextByte();
            operation(ch);
        }
    }
   static void operation(Byte ch)
    {
        switch(ch)
        {
            case 1: 
                queue.enqueue(sc.nextInt());
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                queue.print();
                break;
            default:
                System.out.println("Please Select a valid  Number\n");
                break;
  
        }
    }
    
}
