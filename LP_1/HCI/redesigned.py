import tkinter as tk
from tkinter import ttk

# ----- Redesigned GUI -----
root = tk.Tk()
root.title("Redesigned GUI - Optimized Screen Complexity")
root.geometry("600x500")

# Section Title
tk.Label(root, text="User Registration Form", font=("Arial", 16, "bold")).pack(pady=10)

form_frame = tk.Frame(root, padx=20, pady=20)
form_frame.pack(fill="x")

# Structured grid layout
tk.Label(form_frame, text="First Name:").grid(row=0, column=0, sticky="w", pady=5)
tk.Entry(form_frame, width=30).grid(row=0, column=1, pady=5)

tk.Label(form_frame, text="Last Name:").grid(row=1, column=0, sticky="w", pady=5)
tk.Entry(form_frame, width=30).grid(row=1, column=1, pady=5)

tk.Label(form_frame, text="Email:").grid(row=2, column=0, sticky="w", pady=5)
tk.Entry(form_frame, width=30).grid(row=2, column=1, pady=5)

tk.Label(form_frame, text="Phone:").grid(row=3, column=0, sticky="w", pady=5)
tk.Entry(form_frame, width=30).grid(row=3, column=1, pady=5)

tk.Label(form_frame, text="Address:").grid(row=4, column=0, sticky="w", pady=5)
tk.Entry(form_frame, width=30).grid(row=4, column=1, pady=5)

# Gender
tk.Label(form_frame, text="Gender:").grid(row=5, column=0, sticky="w", pady=5)
gender_frame = tk.Frame(form_frame)
gender_frame.grid(row=5, column=1, pady=5)
tk.Radiobutton(gender_frame, text="Male", value=1).pack(side="left")
tk.Radiobutton(gender_frame, text="Female", value=2).pack(side="left")

# Country
tk.Label(form_frame, text="Country:").grid(row=6, column=0, sticky="w", pady=5)
ttk.Combobox(form_frame, values=["India", "USA", "UK"]).grid(row=6, column=1, pady=5)

# Hobbies
tk.Label(form_frame, text="Hobbies:").grid(row=7, column=0, sticky="w", pady=5)
hobby_frame = tk.Frame(form_frame)
hobby_frame.grid(row=7, column=1, pady=5)
tk.Checkbutton(hobby_frame, text="Music").pack(side="left")
tk.Checkbutton(hobby_frame, text="Sports").pack(side="left")
tk.Checkbutton(hobby_frame, text="Reading").pack(side="left")

# Buttons
btn_frame = tk.Frame(root, pady=20)
btn_frame.pack()
tk.Button(btn_frame, text="Submit", width=12).pack(side="left", padx=10)
tk.Button(btn_frame, text="Cancel", width=12).pack(side="left", padx=10)

root.mainloop()

