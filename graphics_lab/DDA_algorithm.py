from matplotlib import pyplot as pt 

def DDA(x0,y0,x1,y1):
    dx = abs(x1-x0)
    dy = abs(y1-y0)

    if(dx>dy):
        steps = dx
    else:
        steps = dy

    xi = dx/steps
    yi = dy/steps

    x = float(x0)
    y = float(y0)

    x_coordinates = []
    y_coordinates = []
    
    for i in range(steps):
        x_coordinates.append(x)
        y_coordinates.append(y)
        x = x + xi
        y = y + yi

    pt.plot(x_coordinates,y_coordinates,marker = "o",markersize = 5,markerfacecolor = "red")
    pt.show()

if __name__ == "__main__":
    DDA(100,60,20,120)