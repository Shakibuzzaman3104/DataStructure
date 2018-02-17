
package stack;

import java.util.Scanner;


class Stack_generate<T>
{
    int top=-1;
    int[] stack = new int[20];
    
    boolean isEmpty()
    {
        return top==-1;
    }
    
    void push(T data)
    {
        if(isEmpty())
        {
            top=0;
        }
            stack[top]=(Integer)data;
            top=top+1;
    }
    void print()
    {
        if(isEmpty())
        {
            System.out.println("Stack Is Empty!!");
        }
        else
           for(int i=0;i<top;i++)
           {
               System.out.println(stack[i]);
           }
    }
    
    void pop()
    {
        if(isEmpty())
        {
            System.out.println("Stack Is Empty, Nothing to POP");
        }
        else if(top==0)
        {
            top=-1;
        }
        else
            top--;
    }
}


public class Stack {

     static Scanner sc= new Scanner(System.in);
     static Stack_generate<Integer> stack;
     
     public static void main(String[] args) {
            stack=new Stack_generate();
            while(true)
            {
                operation();
            }
    }
     static void operation() {
        System.out.println("\nSelect your Operation ? : \n1.Push  \n2.POP \n3.Print");
        byte ch = sc.nextByte();
        switch(ch)
        {
            case 1: 
                stack.push(sc.nextInt());
                stack.print();
                break;
            case 2:
                stack.pop();
                //stack.print();
                break;
            case 3:
                stack.print();
                break;
            default:
                System.out.println("Please Select a valid  Number\n");
                break;
        }   
        
     }
    
}
