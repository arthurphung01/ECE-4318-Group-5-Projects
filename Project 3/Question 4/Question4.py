from fileinput import close
from tkinter import *
from turtle import clear
import numpy as np
from matplotlib import pyplot as plt

root = Tk()
root.title('Plotting the curve of a cardioid')
#root.iconbitmap('*')
root.geometry("400x200")

def graph():
    theta = np.linspace(0, 2*np.pi, 1000)
    r = float(a.get()) + float(b.get()) * np.sin(theta)
    plt.polar(theta, r, 'r')
    plt.show()

def clear():
    plt.cla()
    plt.show()

#Initializing labels to display user input
Label(root, text="Enter value for a").grid(row=0)
Label(root, text="Enter value for b").grid(row=1)

#Create an Entry widget to accept User Input
a = Entry(root)
b = Entry(root)

a.grid(row=0, column=1)
b.grid(row=1, column=1)

#plot button
plot_button = Button(root, text="Plot", command=graph).grid(row=3)

#reset button
reset_button = Button(root, text="Reset Plot", command=clear).grid(row=4)

root.mainloop()