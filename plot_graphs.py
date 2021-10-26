import matplotlib.pyplot as plt
from math import pi, cos, sin
import numpy as np


def get_integer(msg="Number: ", wrng_msg="Invalid Input"):
    try:
        i = int(input(msg))
    except ValueError:
        print(wrng_msg)
        return get_integer(msg, wrng_msg)
    else:
        return i


def get_float(msg="Number: ", wrng_msg="Invalid Input"):
    try:
        f = float(input(msg))
    except ValueError:
        print(wrng_msg)
        return get_float(msg, wrng_msg)
    else:
        return f


def plot_circle():
    print("""
Please enter the radius of circle and the coordinates of its centres in the form "x y", for eg, '3 0'
""")
    x = []
    y = []
        
    start = 0
    end = 2 * pi
    i = start
        
    radius = get_float("Radius: ")
    inp = input("Centre coords, default=0,0: ")
    if inp != "":
        cx, cy = inp.split()
        cx, cy = float(cx), float(cy)
    else:
        cx, cy = 0, 0
    resolution = pi / 180

    while i < end + resolution:
        x.append(cx + radius * cos(i))
        y.append(cy + radius * sin(i))
        i += resolution
        
    plt.plot(x, y)
    plt.plot(cx, cy, "o")
    # legend
    if cx == 0 and cy == 0:
        legends.append(u"x\u00B2 + y\u00B2 = " + str(radius**2))
    elif cx != 0 and cy == 0:
        if cx > 0:
            legends.append(u"(x - " + str(cx) + ")\u00B2 + y\u00B2 = " + str(radius**2))
        else:
            legends.append(u"(x + " + str(-cx) + ")\u00B2 + y\u00B2 = " + str(radius**2))
    elif cx == 0 and cy != 0:
        if cy > 0:
            legends.append(u"x\u00B2 + (y - " + str(cy) + ")\u00B2 = " + str(radius**2))
        else:
            legends.append(u"x\u00B2 + (y + " + str(-cy) + ")\u00B2 = " + str(radius**2))
    else:
        if cx < 0 and cy < 0:
            legends.append(u"(x + " + str(-cx) + ")\u00B2 + (y + " + str(-cy) + ")\u00B2 = " + str(radius**2))
        elif cx > 0 and cy < 0:
            legends.append(u"(x - " + str(cx) + ")\u00B2 + (y + " + str(-cy) + ")\u00B2 = " + str(radius**2))
        elif cx < 0 and cy > 0:
            legends.append(u"(x + " + str(-cx) + ")\u00B2 + (y - " + str(cy) + ")\u00B2 = " + str(radius**2))
        else:
            legends.append(u"(x - " + str(cx) + ")\u00B2 + (y - " + str(cy) + ")\u00B2 = " + str(radius**2))
    legends.append(f"Circle centre({cx}, {cy})")
    print(f"Circle with centre = ({cx}, {cy}) and radius = {radius} plotted!")


def plot_ellipse():
    print("""
To plot an ellipse please give the values of a and b respectively
""")
    
    start = 0
    end = 2 * pi
    theta = np.linspace(start, end, 360)

    a = get_float("a: ")
    b = get_float("b: ")

    x = a * np.cos(theta)
    y = b * np.sin(theta)

    plt.plot(x, y)
    legends.append(u"x\u00B2/" + str(a**2) + " + y\u00B2/" + str(b**2) + " = 1")
    print(u"Ellipse: x\u00B2/" + str(a**2) + " + y\u00B2/" + str(b**2) + " = 1 plotted!")
    if a < b:
        c = (b**2 - a**2)**0.5
        plt.plot([0, 0], [c, -c], "o")
        legends.append(f"Ellipse foci(0, ±{round(c, 3)})")
    elif a > b:
        c = (a**2 - b**2)**0.5
        plt.plot([c, -c], [0, 0], "o")
        legends.append(f"Ellipse foci(±{round(c, 3)}, 0)")


def plot_quadrilateral():
    inp = get_integer("""
Choose one way...
1. By providing length and breadth,plot rectangle/square, from the origin.
2. By providing coordinates of all four points.
How would you like to proceed(1 or 2): """, "Invalid input, enter either 1 or 2")
    if inp == 1:
        length = get_float("Length: ")
        breadth = get_float("Breadth: ")
        x = [0, length, length, 0, 0]
        y = [0, 0, breadth, breadth, 0]
        if length != breadth:
            legends.append(f"Rectangle(l={length}, b={breadth})")
            print(f"Rectangle(l={length}, b={breadth}) plotted!")
        else:
            legends.append(f"Square(a={length})")
            print(f"Square(a={length}) plotted")
        plt.plot(x, y, 'o-')
    elif inp == 2:
        x = []
        y = []
        print("Enter points in the form 'x y'")
        for i in range(4):
            a, b = input(f"Point {i+1}: ").split()
            a, b = float(a), float(b)
            x.append(a)
            y.append(b)
        x.append(x[0])
        y.append(y[0])
        legends.append(f"Quadrilateral")
        print('Quadrilateral plotted')
        plt.plot(x, y, "o-")
    else:
        print("Invalid input")


def lnr_cnsts(a):
    consts = []
    x1 = -1
    y1 = -1
    if 'x' in a:
        x1 = a.index('x')
    if x1 >= 1:
        l = a[:x1]
    elif x1 == 0:
        l = 1
    else:
        l = 0
    if l == '+':
        l = 1
    elif l == '-':
        l = -1
    l = float(l)
    consts.append(l)
    if 'y' in a:
        y1 = a.index('y')
    if y1 >= 1:
        m = a[x1 + 1:y1]
    elif y1 == 0:
        m = 1
    else:
        m = 0
    if m == '+':
        m = 1
    elif m == '-':
        m = -1
    m = float(m)
    consts.append(m)
    if y1 != -1:
        if len(a) - 1 != y1:
            n = a[y1 + 1:]
        else:
            n = 0
    else:
        if len(a) - 1 != x1:
            n = a[x1 + 1:]
        else:
            n = 0
    n = float(n)
    consts.append(n)
    return consts


def plot_lnreqn():
    
    print('''
You can get solution of any two pair of linear equations using this program.
Please enter equations in the form "ax + by + c"''')
    
    en = input('Equation: ')
    eqn = ''
    e = en.split()
    for i in e:
        eqn += i

    constants = lnr_cnsts(eqn)
    a, b, c = constants[0], constants[1], constants[2]
    if a != 0 and b != 0:
        xval = []
        yval = []
        l = 5
        x = (-c) / a
        y = (-c) / b
        if x >= 0:
            end = x + l
            start = -l
        else:
            end = l
            start = x - l
        resolution = 0.01
        i = start
        while i <= end:
            xval.append(i)
            yval.append(((-c) - (a * i)) / b)
            i += resolution
        plt.plot(xval, yval)
        legends.append(eqn)
        plt.plot([x, 0], [0, y], 'o')
        legends.append(u"Soln. to linear eq\u2099")
        print(f"{eqn} plotted!")
    elif a == 0 and b != 0:
        xval = []
        yval = []
        l = 5
        y = (-c) / b
        start = -l
        end = l
        resolution = l
        i = start
        while i <= end:
            xval.append(i)
            yval.append(y)
            i += resolution
        plt.plot(xval, yval)
        legends.append(eqn)
        plt.plot([0], [y], 'o')
        legends.append(u"Soln. to linear eq\u2099")
        print(f"{eqn} plotted!")
    elif a != 0 and b == 0:
        xval = []
        yval = []
        l = 5
        x = (-c) / a
        start = -l
        end = l
        resolution = l
        i = start
        while i <= end:
            xval.append(x)
            yval.append(i)
            i += resolution
        plt.plot(xval, yval)
        legends.append(eqn)
        plt.plot([x], [0], 'o')
        legends.append(u"Soln. to linear eq\u2099")
        print(f"{eqn} plotted!")
        

def plot_quadratic():
    print(u"""
A quadratic equation is in the form of ax\u00B2 + bx +c = 0. To plot, please provide a, b, c.
""")
    a = get_float("a: ")
    b = get_float("b: ")
    c = get_float("c: ")

    d = (b**2 - (4 * a * c)) ** 0.5
    x1 = ((-b) + d)/(2 * a)
    x2 = ((-b) - d)/(2 * a)

    print(f"Solution to this equation is x = {x1}, {x2}")
    l = 2
    if x1 <= x2:
        start = x1 - l
        end = x2 + l
    else:
        start = x2 - l
        end = x1 + l

    resolution = 0.01
    x = []
    y = []
    i = start
    while i <= end:
        x.append(i)
        y.append((a * (i ** 2)) + (b * i) + c)
        i += resolution

    plt.plot(x, y)
    legends.append(u""+str(a)+"x\u00B2 + " + str(b) + "x + " + str(c))
    plt.plot([x1, x1], [0, 0], "o")
    legends.append("Quadratic equation solution(s)")
    print(u""+str(a)+"x\u00B2 + " + str(b) + "x + " + str(c) + " plotted!")


def plot_polygon():
    print("""
To plot a polygon, provide its points, minimum of 3 to form a polygon.
To give a point, write its coordinates in the form 'x y', eg '3 2'.
Once you are done giving points, just press 'e' and press enter.
""")
    x = []
    y = []
    pointNo = 1
    poly = {3:"Triangle", 4:"Quadrilateral", 5:"Pentagon", 6:"Hexagon", 7:"Septagon", 8:"Octagon", 9:"Nonagon", 10:"Decagon"}
    while True:
        inp = input(f"Point {pointNo}: ")
        if inp.lower() == "e":
            if pointNo >= 4:
                x.append(x[0])
                y.append(y[0])
                break
            else:
                print("Insufficient points to form a polygon")
                pointNo -= 1
        else:
            xval, yval = inp.split()
            xval, yval = float(xval), float(yval)
            x.append(xval)
            y.append(yval)
        pointNo += 1
    plt.plot(x, y, 'o-')
    legends.append(f"{poly.get(pointNo-1, 'Polygon')}")
    print(f"{poly.get(pointNo-1, 'Polygon')} plotted!")


legends = []

while True:
    action = get_integer("""
1. Plot circle
2. Plot ellipse
3. Plot Quadrilateral
4. Plot linear equation in one/two variables
5. Plot quadratic equation
6. Plot polygon
7. Show plotted graph
8. Exit
Choose a action (1-8): """, "Invalid input, please enter the integer code(1-8)")

    
    if action == 1:
        plot_circle()
    elif action == 2:
        plot_ellipse()
    elif action == 3:
        plot_quadrilateral()
    elif action == 4:
        plot_lnreqn()
    elif action == 5:
        plot_quadratic()
    elif action == 6:
        plot_polygon()
    elif action == 7:
        plt.grid(True)
        leg = input("Would you like to have legends in graph(y/n)(default y)? ").lower()
        if leg == "" or leg == "y" or leg == "yes":
            plt.legend(legends)
        elif leg == "n" or leg == "no":
            pass
        plt.show()
    elif action == 8:
        break
    else:
        print('Invalid input')
        
