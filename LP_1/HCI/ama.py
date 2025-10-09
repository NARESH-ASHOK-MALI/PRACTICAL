import tkinter as tk
from tkinter import messagebox


# ----------------- Login Window -----------------
def login():
    username = entry_user.get()
    password = entry_pass.get()

    # Dummy credentials
    if username == "amazon" and password == "1234":
        root.destroy()
        open_main_menu()
    else:
        messagebox.showerror("Login Failed", "Invalid Username or Password")


# ----------------- Pages -----------------
def open_page(title):
    page = tk.Toplevel()
    page.title(title)
    page.geometry("400x250")
    tk.Label(page, text=f"Welcome to {title}", font=("Arial", 14)).pack(pady=50)


# ----------------- Main Menu -----------------
def open_main_menu():
    main = tk.Tk()
    main.title("Amazon Main Menu")
    main.geometry("500x300")

    menubar = tk.Menu(main)

    # Shopping Menu
    shopping_menu = tk.Menu(menubar, tearoff=0)
    shopping_menu.add_command(label="Shop by Category", command=lambda: open_page("Shop by Category"))
    shopping_menu.add_command(label="Today's Deals", command=lambda: open_page("Today's Deals"))
    shopping_menu.add_command(label="Cart", command=lambda: open_page("Cart"))
    menubar.add_cascade(label="Shopping", menu=shopping_menu)

    # Orders Menu
    orders_menu = tk.Menu(menubar, tearoff=0)
    orders_menu.add_command(label="Your Orders", command=lambda: open_page("Your Orders"))
    orders_menu.add_command(label="Track Order", command=lambda: open_page("Track Order"))
    menubar.add_cascade(label="Orders", menu=orders_menu)

    # Account Menu
    account_menu = tk.Menu(menubar, tearoff=0)
    account_menu.add_command(label="Your Account", command=lambda: open_page("Your Account"))
    account_menu.add_separator()
    account_menu.add_command(label="Logout", command=main.destroy)
    menubar.add_cascade(label="Account", menu=account_menu)

    main.config(menu=menubar)
    tk.Label(main, text="Welcome to Amazon", font=("Arial", 16)).pack(pady=100)

    main.mainloop()


# ----------------- Root Login Window -----------------
root = tk.Tk()
root.title("Amazon Login")
root.geometry("400x250")

tk.Label(root, text="Amazon Login", font=("Arial", 16)).pack(pady=10)

tk.Label(root, text="Username").pack()
entry_user = tk.Entry(root)
entry_user.pack()

tk.Label(root, text="Password").pack()
entry_pass = tk.Entry(root, show="*")
entry_pass.pack()

tk.Button(root, text="Login", command=login).pack(pady=20)

root.mainloop()
