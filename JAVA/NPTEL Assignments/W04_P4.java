interface First {
    // Default method
    default void show() {
        System.out.println("Default method implementation of First interface.");
    }
}

interface Second {
    // Default method
    default void show() {
        System.out.println("Default method implementation of Second interface.");
    }
}

class W04_P4 implements First, Second {

    // Overriding default show method to resolve ambiguity
    public void show() {
        First.super.show(); // Explicitly call the First interface method
        Second.super.show(); // Explicitly call the Second interface method
    }
    public static void main(String[] args) {
        W04_P4 q = new W04_P4();
        q.show();
    }
}
