import java.util.Scanner;

class MergeSort
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
    sort.sort(arr);
  }
}

class Sorting
{
  void sort(int[] arr)
  {
      int i;
      int n=arr.length;
      int mid=n/2;
      int S_left=mid;
      int S_right=n-mid;
      int[] left=new int[S_left];
      int[] right= new int [S_right];
      //System.out.println("mid="+mid);
      if(n<2)
      {
        return;
      }
      for(i=0;i<mid;i++)
      {
        left[i]=arr[i];
      }
      for(i=mid;i<n;i++)
      {
        right[i-mid]=arr[i];
      }
      sort(left);
      sort(right);
      merge(left,right,arr,S_left,S_right);
        for (i=0;i<n;i++)
        {
          System.out.println("sorted"+arr[i]);
        }
  }

  void merge(int[] left,int[] right,int[] arr,int S_left,int S_right)
  {
    int i=0;int j=0;int k=0;
    while(i<S_left && j<S_right)
    {
        if(left[i]<right[j])
        {
          arr[k]=left[i];
          i++;
        }
        else
        {
          arr[k]=right[j];
          j++;
        }
        k++;
    }
    while(i<S_left)
    {
      arr[k]=left[i];
      i++;
      k++;
    }
    while(j<S_right)
    {
      arr[k]=right[j];
      j++;
      k++;
    }

  }
}
