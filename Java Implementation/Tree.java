import java.util.Scanner;


class Tree
{
  static Scanner sc=new Scanner(System.in);
  public static void main(String[] args) {
     System.out.println("");
     Node root=null;
     Byte s=sc.nextByte();
      for(int i=0;i<s;i++)
      {
          int val=sc.nextInt();
          link.insertAtEnd(val);
      }
      while(true)
      {
          System.out.println("\nSelect your Operation ? : \n1.Insert \n2.Insert At End \n3.Print \n4.print backward");
          Byte ch=sc.nextByte();
          operation(ch);
      }
  }

  static void operation(Byte ch)
  {
      switch(ch)
      {
          default:
              System.out.println("Please Select a valid input");
              break;
      }
  }


  class Node
  {
        int data;
        Node left;
        Node Right;
        Node(int data)
        {
          this.data=data;
          left=null;
          right=null;
        }
  }

  Node insert(int data)
  {

  }

}
