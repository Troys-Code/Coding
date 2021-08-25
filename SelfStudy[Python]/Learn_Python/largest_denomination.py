def largest_denomination(total_cash):
	change_Dict = {
        	"Hundreds" : 0,
        	"Fiftys"   : 0,
        	"Twenties" : 0,
        	"Tens"     : 0,
        	"Fives"    : 0,
        	"Ones"     : 0,
        	"Quarters" : 0,
        	"Dimes"    : 0,
        	"Nickels"  : 0,
        	"Pennies"  : 0
	}
	while total_cash >= 100:
		total_cash -= 100
		change_Dict["Hundreds"] += 1
	while total_cash >= 50:
		total_cash -= 50
		change_Dict["Fiftys"] += 1
	while total_cash >= 20:
		total_cash -= 20
		change_Dict["Twenties"] += 1
	while total_cash >= 10:
		total_cash -= 10
		change_Dict["Tens"] += 1
	while total_cash >= 5:
		total_cash -= 5
		change_Dict["Fives"] += 1
	while total_cash >= 1:
		total_cash -= 1
		change_Dict["Ones"] += 1
	while total_cash >= 0.25:
		total_cash -= 0.25
		change_Dict["Quarters"] += 1
	while total_cash >= 0.10:
		total_cash -= .10
		change_Dict["Dimes"] += 1
	while total_cash >= .05:
		total_cash -= .05
		change_Dict["Nickels"] += 1
	while total_cash >= 0.0:
		total_cash -= .01
		change_Dict["Pennies"] += 1

	return change_Dict 

	
def main():
	cash = float(input("Please Input the amount of cash: "))
	change = largest_denomination(cash)
	print(f"The amount of cash held is ${cash}")
	print("The largest denomination of change is")
	for val in change:
		print(f"\t{val} : {change[val]}")

if __name__ == "__main__":
	main()
