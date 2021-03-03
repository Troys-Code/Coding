while True:
    weight = float(input("\nEnter Your Weight: "))
    units = input("Is this in [K]g or [L]bs?\n(Any other entry end the program): ").upper()

    if(units == 'K'):
        print("Weight in Lbs: " + str(weight / 0.45359237))
    elif(units == 'L'):
        print("Weight in Kg: " + str(weight * 0.45359237))
    else:
        break