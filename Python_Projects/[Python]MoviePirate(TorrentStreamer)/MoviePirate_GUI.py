import getDependencies
getDependencies.update()			# Downloads neccesary files
import play
from tkinter import *

def click():
	play.run()

root = Tk()					# Define Default Initial Window
	
# myLabel = Label(root, text = "Movie Pirate")	# Create a label widget
# myLabel.pack()

run_Btn = Button(root, text="Run", padx=50, command=click) # calls click 
run_Btn.pack()

root.mainloop()					# Loop to keep window on screen
