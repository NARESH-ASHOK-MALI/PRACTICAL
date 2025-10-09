import tkinter as tk
from tkinter import ttk

# ----- Original Complex GUI -----
root = tk.Tk()
root.title("Original GUI - Screen Complexity Example")
root.geometry("600x500")

# Unorganized labels and entries
tk.Label(root, text="First Name").place(x=50, y=30)
tk.Entry(root, width=25).place(x=200, y=30)

tk.Label(root, text="Last Name").place(x=300, y=70)
tk.Entry(root, width=25).place(x=400, y=70)

tk.Label(root, text="Email").place(x=100, y=110)
tk.Entry(root, width=25).place(x=250, y=110)

tk.Label(root, text="Phone").place(x=50, y=160)
tk.Entry(root, width=25).place(x=200, y=160)

tk.Label(root, text="Address").place(x=320, y=210)
tk.Entry(root, width=25).place(x=400, y=210)

tk.Label(root, text="Gender").place(x=70, y=260)
tk.Radiobutton(root, text="Male", value=1).place(x=150, y=260)
tk.Radiobutton(root, text="Female", value=2).place(x=220, y=260)

tk.Label(root, text="Country").place(x=300, y=300)
ttk.Combobox(root, values=["India", "USA", "UK"]).place(x=400, y=300)

tk.Label(root, text="Hobbies").place(x=50, y=350)
tk.Checkbutton(root, text="Music").place(x=150, y=350)
tk.Checkbutton(root, text="Sports").place(x=220, y=350)
tk.Checkbutton(root, text="Reading").place(x=300, y=350)

tk.Button(root, text="Submit").place(x=200, y=400)
tk.Button(root, text="Cancel").place(x=300, y=430)

root.mainloop()
