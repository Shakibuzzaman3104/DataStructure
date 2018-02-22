import java.util.Scanner;

class SelectionSort
{
  public static void main(String args[])
  {
    Scanner sc=new Scanner(System.in);
    Sorting sort = new Sorting();
    System.out.println("Please Enter Size of Array");
    byte s =sc.nextByte();
    int arr[]=new int[s];
    System.out.println("Please Enter numbers in any order");
    for(int i=0;i<s;i++)
    {
      arr[i]=sc.nextInt();
    }
    sort.sort(arr,s);
  }

}

class Sorting
{
  void sort(int arr[],int size)
  {
      int swap;

      for(int i=0;i<size-1;i++)
      {
        int Min=i;
        for(int j=i+1;j<size;j++)
        {
            if(arr[j]<arr[Min])
            {
              Min=j;
            }
        }
        swap=arr[i];
        arr[i]=arr[Min];
        arr[Min]=swap;
      }
      System.out.println("\n");
      for(int i=0;i<size;i++)
      {
        System.out.println(arr[i]);
      }
  }
}
