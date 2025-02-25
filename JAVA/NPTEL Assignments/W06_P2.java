class ThreadRun implements Runnable {
    public void run(){ 
        System.out.print("Thread using Runnable interface."); 
    } 
}

public class W06_P2 {  
    public static void main(String[] args) {  
        ThreadRun runnableInstance = new ThreadRun();  
        Thread thread = new Thread(runnableInstance);  
        thread.start();  
    }  
}