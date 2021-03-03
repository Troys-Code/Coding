from tkinter import *

root = Tk()

one = Label(root, text = "One", bg = "red",fg = "white")
two = Label(root, text = "Two", bg = "green",fg = "white")
three = Label(root, text = "Three", bg = "blue",fg = "white")


one.pack()
two.pack(fill = X) 				  # Fills BG Color To The X-Width Of The Form
three.pack(side = LEFT, fill = Y) # Fills BG Color To The Y-Height Of The Form

root.mainloop()
