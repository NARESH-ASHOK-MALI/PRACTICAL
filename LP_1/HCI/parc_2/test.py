import tkinter as tk
from tkinter import messagebox

# Dummy user data (can be replaced with database)
users = {"naresh": "1234"}

def login():
    username = entry_username.get()
    password = entry_password.get()
    
    if username in users and users[username] == password:
        messagebox.showinfo("Success", f"Welcome {username}!")
    else:
        messagebox.showerror("Error", "Invalid Username or Password!")

def open_forgot():
    forgot_win = tk.Toplevel(root)
    forgot_win.title("Forgot Password")
    forgot_win.geometry("300x200")

    tk.Label(forgot_win, text="Enter Username:").pack(pady=5)
    entry_user = tk.Entry(forgot_win, width=25)
    entry_user.pack(pady=5)

    tk.Label(forgot_win, text="Enter New Password:").pack(pady=5)
    entry_newpass = tk.Entry(forgot_win, width=25, show="*")
    entry_newpass.pack(pady=5)

    def reset_password():
        user = entry_user.get()
        new_pass = entry_newpass.get()
        if user in users:
            users[user] = new_pass
            messagebox.showinfo("Success", "Password updated successfully!")
            forgot_win.destroy()
        else:
            messagebox.showerror("Error", "User not found!")

    tk.Button(forgot_win, text="Reset Password", command=reset_password, bg="blue", fg="white").pack(pady=10)

def open_signup():
    signup_win = tk.Toplevel(root)
    signup_win.title("Signup Page")
    signup_win.geometry("300x300")

    tk.Label(signup_win, text="Create Username:").pack(pady=5)
    entry_newuser = tk.Entry(signup_win, width=25)
    entry_newuser.pack(pady=5)

    tk.Label(signup_win, text="Create Password:").pack(pady=5)
    entry_newpass = tk.Entry(signup_win, width=25, show="*")
    entry_newpass.pack(pady=5)

    def register():
        new_user = entry_newuser.get()
        new_pass = entry_newpass.get()
        if new_user in users:
            messagebox.showerror("Error", "User already exists!")
        else:
            users[new_user] = new_pass
            messagebox.showinfo("Success", "Account created!")
            signup_win.destroy()

    tk.Button(signup_win, text="Register", command=register, bg="green", fg="white").pack(pady=10)

# Main login window
root = tk.Tk()
root.title("Login Page")
root.geometry("350x250")
root.resizable(False, False)

# Title
tk.Label(root, text="Login", font=("Arial", 16, "bold")).pack(pady=10)

# Username
tk.Label(root, text="Username:").pack(anchor="w", padx=20)
entry_username = tk.Entry(root, width=30)
entry_username.pack(padx=20, pady=5)

# Password
tk.Label(root, text="Password:").pack(anchor="w", padx=20)
entry_password = tk.Entry(root, width=30, show="*")
entry_password.pack(padx=20, pady=5)

# Login button
tk.Button(root, text="Login", width=15, bg="blue", fg="white", command=login).pack(pady=10)

# Forgot Password link
tk.Button(root, text="Forgot Password?", fg="red", relief="flat", command=open_forgot).pack()

# Signup link
tk.Button(root, text="New user? Signup here", fg="green", relief="flat", command=open_signup).pack()

root.mainloop()