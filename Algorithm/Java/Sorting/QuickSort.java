import java.util.Scanner;

class QuickSort
{
  public static void main(String args[])
  {
    Sorting sort = new Sorting();
    Scanner sc = new Scanner(System.in);
    System.out.println("Please Enter Size of the array");
    byte s= sc.nextByte();
    int arr[]=new int[s];
    System.out.println("Enter values in any order");
    for(int i=0;i<s;i++)
    {
      arr[i]=sc.nextInt();
    }
    int start=0;
    int end=s-1;
    sort.sort(arr,start,end);
  }
}

class Sorting
{
  void sort(int[] arr,int start,int end)
  {
      boolean flag=true;
      int n=arr.length;
      if(start<end)
      {
          int Ipivot=partition(arr,start,end);
          sort(arr,start,Ipivot-1);
          sort(arr,Ipivot+1,end);

          flag=false;
      }
      if(flag==true)
        {
        for (int i=0;i<n;i++)
         {
         System.out.println("sorted"+arr[i]);
         }
       }

  }

  int partition(int[] arr,int start,int end)
  {
    int pivot=arr[end];
    int Ipivot=start;
    int sw;
    for(int i=start;i<end;i++)
    {
      if(arr[i]<=pivot)
      {
        sw=arr[Ipivot];
        arr[Ipivot]=arr[i];
        arr[i]=sw;
        Ipivot++;
      }
    }
    sw=arr[Ipivot];
    arr[Ipivot]=arr[end];
    arr[end]=sw;
    return Ipivot;
  }

  void print(int []arr)
  {
       for (int i=0;i<n;i++)
       {
       System.out.println("sorted"+arr[i]);
       }
  }
}
