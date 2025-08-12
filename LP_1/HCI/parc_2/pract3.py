import tkinter as tk
from tkinter import ttk, messagebox

def on_submit():
    name = name_entry.get()
    choice = dropdown_var.get()
    if name:
        output_text.delete("1.0", tk.END)
        output_text.insert(tk.END, f"Hello, {name}!\nYou selected: {choice}")
    else:
        messagebox.showwarning("Input Error", "Please enter your name!")

# Create main window
root = tk.Tk()
root.title("Sample Tkinter UI")
root.geometry("400x300")
root.resizable(False, False)

# Title Label
title_label = ttk.Label(root, text="User Interface in Tkinter", font=("Helvetica", 16))
title_label.pack(pady=10)

# Name Input
name_frame = ttk.Frame(root)
name_frame.pack(pady=5)
ttk.Label(name_frame, text="Enter your name: ").pack(side=tk.LEFT)
name_entry = ttk.Entry(name_frame, width=30)
name_entry.pack(side=tk.LEFT)

# Dropdown
dropdown_var = tk.StringVar(value="Option 1")
options = ["Option 1", "Option 2", "Option 3"]
dropdown_menu = ttk.OptionMenu(root, dropdown_var, options[0], *options)
dropdown_menu.pack(pady=10)

# Submit Button
submit_btn = ttk.Button(root, text="Submit", command=on_submit)
submit_btn.pack(pady=10)

# Output Text Box
output_text = tk.Text(root, height=5, width=40)
output_text.pack(pady=10)

# Start the application
root.mainloop()