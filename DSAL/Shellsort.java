import java.util.Scanner;
class shellsort{
    
    static void printArray(int arr[]){
        int n=arr.length;
        for(int i=0;i<n;i++){
            System.out.print(arr[i]  + " ");
        }
        System.out.println();
    }

    static int sort(int arr[]){
        int n=arr.length;
        for (int gap = n/2; gap > 0; gap=( gap /2)){
            for (int i = gap; i < n; i++){
                int temp = arr[i];
                int j;
                for (j = i; j >= gap && arr[j - gap] > temp; j=j- gap){
                    arr[j] = arr[j - gap];
                }
                arr[j] = temp;
            }
        }
        return 0;
    }

    public static void main(String[] args) {
        //make useer input to create an array
        
  
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the no. elements of the array: ");
        int n = sc.nextInt();
        int arr[] = new int[n];
        System.out.println("Enter the elements of the array: ");
        for (int i = 0; i < n; i++){
           arr[i] = sc.nextInt();
        }
        sc.close();
        System.out.print("Orignal array: ");
        printArray(arr);
        System.out.print("sorted array: ");
        sort(arr);
        printArray(arr);
    }
}
    
