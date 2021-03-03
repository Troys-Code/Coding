from tkinter import *
from PIL import Image,ImageTk #pip install pillow

''' 	 		'''
#	User Class	  #
'''		 		'''
class User:
    def __init__(self, name, reward_points):
        self.name = name
        self.reward_points = reward_points

    def printStats(self):
        # Reference the name
        print(f'\nName: {self.name}')
        print(f'Reward Points: {self.reward_points}')
        
    

def displayMessage():
	#print("demo tkinter")
	label2.pack()
	#print(Quest_List)
def exit1():
	exit()

''' 			'''
#    User Login	  #     TODO: Read Info From Google Calender
'''				'''
troy = User(name = 'troy', reward_points = 10)

troy.printStats()



''' 			'''
# Gui : Main Page #
'''				'''

window = Tk()
# window.geometry("400x300")
window.title("Welcome To Quest Tracker Reward System")

label1 = Label(window, text = "Quest List:", fg = 'blue', bg = 'yellow', relief = 'solid',font = ("ariel", 10,"bold"))
label1.pack(fill = BOTH, pady = 2, padx = 2)

button1 = Button(window, text = "View All Quest Image", command = displayMessage)
button1.pack()


inFile = Image.open("/Users/user/Downloads/R6.jpg") # Read In Image File
photo = ImageTk.PhotoImage(inFile)

label2 = Label(image = photo)

#Quest_List = ['eat better', 'take care of health', 'fix teeth']







window.mainloop()


