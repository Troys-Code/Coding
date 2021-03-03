from tkinter import *

class Window(Frame):	# Importing Frame From tkinter
	
	def __init__(self, master = None):
		Frame.__init__(self, master)
		
		self.master = master 		# main window
		
root = Tk() 	# Constructor Creates A tinkter object(Blank Window) Called root

thelable = Label(root, text = "This is too easy")

thelable.pack() # Places It First Place You Can Fit It


root.mainloop() # Puts Window Continuously On Your Screen
