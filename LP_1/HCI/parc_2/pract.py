from tkinter import*
top = Tk()
top.title("Naresh")
top.geometry("200x200")
top.config(bg="black")
w= Label(top,text='Naresh Ashok Mali')

# Label
w = Label(top, text='Naresh Ashok Mali', bg="black", fg="white", font=("Arial", 12, "bold"))
w.pack(pady=30)

# Button
# btn = Button(top, text="Click Me", command=on_click, font=("Arial", 10), bg="white", fg="blue")
# btn.pack(pady=10)

w.pack()
top.mainloop()

