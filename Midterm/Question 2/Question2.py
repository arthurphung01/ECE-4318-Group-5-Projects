"""
part a

compute 50! 100! and 2^63 - 1
"""

#computing factorial
def fact():
    n = ''

    while (n != 0):
        randString = input("Input a value for n: ")

        n = int(randString)
        fact = 1

        for i in range(1, n+1):
            fact = fact * i
        
        print(f"The factorial of {n} is {fact}")
        return main()

#computing exponential
def expo():
    n = ''

    while (n != 0):
        int1 = input("Input a base value for b: ")
        int2 = input("Input a value for n: ")
        b = int(int1)
        n = int(int2)
        expo = (b ** n) - 1
        print(f"{b}^{n} - 1 = {expo}")
        return main()

#main function
def main():
    func = input("Would you like to find the factorial (1) or exponential (2) of a number or close the program (3): ")
    x = int(func)
    if (x == 1):
        return fact()
    if (x == 2):
        return expo()
    if (x == 3):
        return 0

#calling main
if __name__ == "__main__":
    main()