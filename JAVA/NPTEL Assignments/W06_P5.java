class W06_P5 extends Thread {  
    public void run() {  
        System.out.println("Thread is running.");  
    }  

    public static void main(String args[]) {  
        W06_P5 t = new W06_P5();  

        // Print the default name of the thread
        System.out.println("Name of thread 't': " + t.getName());

        // Start the thread
        t.start();  

        // Set a new name for the thread
        t.setName("NPTEL");  

        // Print the updated name of the thread
        System.out.println("New name of thread 't': " + t.getName());  
    }  
}
