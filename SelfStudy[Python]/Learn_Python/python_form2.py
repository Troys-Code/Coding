from tkinter import *

root = Tk()

topFrame = Frame(root) # Invisible Container and its gonna go in the main window
topFrame.pack() # Place it 

bottomFrame = Frame(root)
bottomFrame.pack(side = BOTTOM)


# CREATES BUTTON DETAILS
button1 = Button(topFrame, text = "Click Me 1", fg = "red") # First param = where do you want it, Second param what do you want to show up on the button, last param = color
button2 = Button(topFrame, text = "Click Me 2", fg = "blue")
button3 = Button(topFrame, text = "Click Me 3", fg = "green")
button4 = Button(bottomFrame, text = "Click Me 4", fg = "purple")

# ADDS THEM TO THE FORM AND DISPLAYS THEM ON YOUR SCREEN
button1.pack(side = TOP)
button2.pack(side = LEFT)
button3.pack(side = RIGHT)
button4.pack(side = BOTTOM)

root.mainloop()
