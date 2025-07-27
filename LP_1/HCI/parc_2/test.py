# from tkinter import*
# top = Tk()
# top.title("Naresh")
# top.geometry("200x200")
# top.config(bg="blue")
# w= Label(top,text='Naresh Mali')
# w.pack()
import tkinter as tk
root = tk.Tk()
button = tk.Button(root, 
                   text="Click Me", 
                   activebackground="blue", 
                   activeforeground="white",
                   anchor="center",
                   bd=3,
                   bg="lightgray",
                   cursor="hand2",
                   disabledforeground="gray",
                   fg="black",
                   font=("Arial", 12),
                   height=2,
                   highlightbackground="black",
                   highlightcolor="green",
                   highlightthickness=2,
                   justify="center",
                   overrelief="raised",
                   padx=10,
                   pady=5,
                   width=15,
                   wraplength=100)

button.pack(padx=20, pady=20)
top.mainloop()