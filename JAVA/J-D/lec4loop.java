public class lec4loop {
    public static void main (String [] args){
        System.out.println("Executing For loop");
        for(int i=0;i<5;i++){
            System.out.println("Hello");
        }
        int Count=0;
        System.out.println("Executing While loop");
        while(Count<5){
            System.out.println("Namaste");
            Count++;
        }
        System.out.println("Executing do While loop");
        int b=0;
        do{
            System.out.println("Bonjour");
            b++;
        }while(b<5);
    }
}
