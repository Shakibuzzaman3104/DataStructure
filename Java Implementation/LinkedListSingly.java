
package linkedlist.singly;

import java.util.Scanner;

public class LinkedListSingly {

    static LinkedList<Integer> link;
    static Scanner sc=new Scanner(System.in);
    public static void main(String[] args) {
        System.out.println("Please Enter Size of the Linked List:");
        link=new LinkedList();
        Byte s=sc.nextByte();
        for(int i=0;i<s;i++)
        {
            int val=sc.nextInt();
            link.insertAtEnd(val);
        }
        while(true)
        {
            System.out.println("\nSelect your Operation ? : \n1.Insert At Front \n2.Insert At End \n3.Print");
            Byte ch=sc.nextByte();
            operation(ch);
        }
    }
    
    static void operation(Byte ch)
    {
        switch(ch)
        {
            case 1:
                link.InsertatHead(sc.nextInt());
                link.print();
                break;
            case 2:
                link.insertAtEnd(sc.nextInt());
                link.print();
                break;
            case 3:
                link.print();
                break;    
            default:
                System.out.println("Please Select a valid input");
                break;
        }
    }
    
}


class LinkedList<In>
{
    private Node head=null;
    private class Node
    {
        In data;
        Node next;
        Node(In data)
        {
            this.data=data;
            this.next=null;
        }
    }
    
    void InsertatHead(In data)
    {
        Node newnode= new Node(data);
        if(head==null)
        {
            head=newnode;
        }
        else
            newnode.next=head;
            head=newnode;
    }
    
    void insertAtEnd(In data)
    {
        Node newnode= new Node(data);
        if(head==null)
        {
            head=newnode;
        }
        else
        {
            Node temp=head;
            while(temp.next!=null)
            {
                temp=temp.next;
            }
            temp.next=newnode;
        }
    }
    
    void print()
    {
        Node temp=head;
        if(head==null)
        {
            System.out.println("List is Empty");
        }
        
        else
        {
            while(temp!=null)
            {
                System.out.println(temp.data);
                temp=temp.next;
            }
        }
    }
}
