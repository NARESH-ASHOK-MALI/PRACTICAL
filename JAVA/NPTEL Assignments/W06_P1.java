// Modify the code to extend the Thread class to complete the class Question61.
public class W06_P1 extends Thread{
	public void run(){
		System.out.print("Thread is Running.");
	}

    public static void main(String args[]){  

		// Creating object of thread class
		W06_P1 thread=new W06_P1();  

                // Start the thread
		thread.start();
	}  
}