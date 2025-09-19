import tkinter as tk
from tkinter import messagebox

def signup():
    name = entry_name.get()
    email = entry_email.get()
    username = entry_username.get()
    password = entry_password.get()
    confirm_password = entry_confirm.get()
    
    if not name or not email or not username or not password or not confirm_password:
        messagebox.showerror("Error", "All fields are required!")
    elif password != confirm_password:
        messagebox.showerror("Error", "Passwords do not match!")
    else:
        messagebox.showinfo("Success", f"Account created for {username}!")
        # Here you can add code to save details in database

# Main window
root = tk.Tk()
root.title("Login page")
root.geometry("400x400")
root.resizable(False, False)

# Heading
lbl_title = tk.Label(root, text="Signup Form", font=("Arial", 16, "bold"))
lbl_title.pack(pady=10)

# Name
tk.Label(root, text="Full Name:").pack(anchor="w", padx=20)
entry_name = tk.Entry(root, width=30)
entry_name.pack(padx=20, pady=5)

# Email
tk.Label(root, text="Email:").pack(anchor="w", padx=20)
entry_email = tk.Entry(root, width=30)
entry_email.pack(padx=20, pady=5)

# Username
tk.Label(root, text="Username:").pack(anchor="w", padx=20)
entry_username = tk.Entry(root, width=30)
entry_username.pack(padx=20, pady=5)

# Password
tk.Label(root, text="Password:").pack(anchor="w", padx=20)
entry_password = tk.Entry(root, width=30, show="*")
entry_password.pack(padx=20, pady=5)

# Confirm Password
tk.Label(root, text="Confirm Password:").pack(anchor="w", padx=20)
entry_confirm = tk.Entry(root, width=30, show="*")
entry_confirm.pack(padx=20, pady=5)

# Signup button
btn_signup = tk.Button(root, text="Sign Up", width=15, bg="blue", fg="white", command=signup)
btn_signup.pack(pady=20)

root.mainloop()
