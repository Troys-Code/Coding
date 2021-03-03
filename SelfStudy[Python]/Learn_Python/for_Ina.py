from tkinter import *

root = Tk()

def print_meow():
	print(f"Meow\n")

def print_woof():
	print(f"Woof\n")


# (where do you want it, what do you want to show up on the button, foreground = color, function call when action is done on botton)
button1 = Button(root, text = "Click Me 1", fg = "black", command = print_meow) 
button2 = Button(root, text = "Click Me 2", fg = "black", command = print_woof)
my_entry = Entry(root)
my_canvas = Canvas(root, width = 500, height = 500, bg = "red")

# sticky = N-orth E-ast S-outh W-est will make it stick to top right down left
my_canvas.grid	(sticky = W)		
button1.grid	(row = 1, sticky = W, column = 0) 
my_entry.grid	(row = 1, sticky = N, column = 0)		
button2.grid	(row = 2, sticky = W, column = 0)	
	
'''
c = Checkbutton(root, text = "CheckBox1")
c.grid(row = 3, column = 0, sticky = W)
'''
root.mainloop()
