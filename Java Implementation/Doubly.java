
import java.util.Scanner;
class Doubly
{
  static Doubly_Im link;
  static Scanner sc=new Scanner(System.in);
  public static void main(String[] args) {
    System.out.println("Please Enter Size of the Linked List:");
      link=new Doubly_Im();
     Byte s=sc.nextByte();
      for(int i=0;i<s;i++)
      {
          int val=sc.nextInt();
          link.insertAtEnd(val);
      }
      while(true)
      {
          System.out.println("\nSelect your Operation ? : \n1.Insert At Front \n2.Insert At End \n3.Print \n4.print backward");
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
          case 4:
              link.print_back();
              break;
          default:
              System.out.println("Please Select a valid input");
              break;
      }
  }

}

class Doubly_Im
{
  private Node head=null;
  private Node tail=null;
  private class Node
    {
      int data;
      Node next;
      Node prev;
      Node(int data)
      {
        this.data=data;
        this.next=null;
        this.prev=null;
      }
    }
    void InsertatHead(int data)
    {
      Node newnode=new Node(data);
        if(head==null)
        {
          head=newnode;
        }
        else
        {
          Node temp=head;
          newnode.next=head;
          head.prev=newnode;
          head=newnode;
        }
    }

    void insertAtEnd(int data)
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
          newnode.prev=temp;
        }
    }

    void print()
    {
        Node temp=head;
        while(temp!=null)
        {
          System.out.println(temp.data);
          temp=temp.next;
        }
    }

    void print_back()
    {
      Node temp=head;
        while(temp.next!=null)
        {
          temp=temp.next;
        }
        while(temp!=null)
        {
          System.out.println(temp.data);
          temp=temp.prev;
        }
    }
}
