
import java.util.Scanner;
import java.util.ArrayList;
class BubbleSort
{
  static Scanner sc=new Scanner(System.in);
  static Sorting sort;
  public static void main(String args[])
  {
      sort = new Sorting();
      System.out.println("Please Enter Size of the Array");
      Byte n=sc.nextByte();
      int arr[]=new int[n];
      System.out.println("Please Enter numbers in any order");
      for(int i=0;i<n;i++)
      {
        arr[i]=sc.nextInt();
      }
      sort.Sort(arr,n);
  }
}

class Sorting
{
  void Sort(int arra[],int size)
  {
      int flag=0,sw;
      for(int i=0;i<size-2;i++)
      {
        for(int j=0;j<size-i-1;j++)
        {
            if(arra[j]>arra[j+1])
            {
              sw=arra[j];
              arra[j]=arra[j+1];
              arra[j+1]=sw;
              flag=1;
            }
        }
        if(flag==0)
        {
          break;
        }
      }
      System.out.println("\n");
      for(int i=0;i<size;i++)
      {
        System.out.println(arra[i]);
      }
  }

}
