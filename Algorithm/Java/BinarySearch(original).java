import java.util.Scanner;

class BinarySearch
{
  public static void main(String args[])
  {
    Search sr=new Search();
    Scanner sc=new Scanner(System.in);
    System.out.println("Enter size of array");
    int s=sc.nextInt();
    int arr[]=new int[s];
    System.out.println("Enter Elements in Sorted order");
    for(int i=0;i<s;i++)
    {
      arr[i]=sc.nextInt();
    }
    int first=0;
    int last=s-1;
    System.out.println("Insert a Data to Search");
    int val=sc.nextInt();
    boolean b=sr.search(arr,first,last,val);

    System.out.println(b);
  }
}
class Search
{
    boolean search(int[] arr,int first,int last,int val)
    {
      int mid=(first+last)/2;
      if(val==arr[mid])
      {
        return true;
      }
      if()
    }
}
