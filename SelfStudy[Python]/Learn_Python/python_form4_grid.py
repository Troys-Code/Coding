
from tkinter import *

root = Tk()

label_1 = Label(root, text = "Name")
label_2 = Label(root, text = "Password")

entry1 = Entry(root) # Blank Field For The User To Type Something In
					 # Displays On Main Window
entry2 = Entry(root)

# Organize Rows (<->) and Columns (^ v)

label_1.grid(row = 1, column = 0) 
label_2.grid(row = 2, column = 0)

entry1.grid(row = 1, column = 1)
entry2.grid(row = 2, column = 1)

my_canvas = Canvas(root, width = 500, height = 500, bg = "red")
my_canvas.grid(row = 0, column = )
root.mainloop()
