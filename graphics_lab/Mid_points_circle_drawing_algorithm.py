import numpy as np
import matplotlib.pyplot as plt


### Data input
x_cent = int(input("Enter x-coordinates of the center: "))
y_cent = int(input("Enter y-coordinates of the center: "))
r = int(input("Enter the radius of the circle: "))



#### Mid-Point Circle Drawing Algorithm ####

### Initializations
x_quad1 = []
y_quad1 = []
decor = []


### Step 01
x_init = 0
y_init = r


### Step 02
decision_parameter = 1 - r


### Step 03: First octant
x = x_init
y = y_init
p = decision_parameter

while(x < y):
    x_quad1.append(x)
    y_quad1.append(y)
    
    if p < 0:
        x += 1
        p += 1 + 2 * x
    else:
        x += 1
        y -= 1
        p += 1 - 2 * y + 2 * x

# append the final point
x_quad1.append(x)
y_quad1.append(y)

# append the second octant to the first quadrant
for i in range(len(x_quad1)):
    x_quad1.append(y_quad1[i])
    y_quad1.append(x_quad1[i])

# Second Quadrant, WRT center coordinates
x_quad2 = [(x_cent - x) for x in x_quad1]
y_quad2 = [(y_cent + y) for y in y_quad1]

# Third Quadrant, WRT center coordinates
x_quad3 = [(x_cent - x) for x in x_quad1]
y_quad3 = [(y_cent - y) for y in y_quad1]

# Fourth Quadrant, WRT center coordinates
x_quad4 = [(x_cent + x) for x in x_quad1]
y_quad4 = [(y_cent - y) for y in y_quad1]

# First Quadrant, WRT center coordinates
x_quad1 = [(x_cent + x) for x in x_quad1]
y_quad1 = [(y_cent + y) for y in y_quad1]

# transform coordinates into a numpy array and print them out
x_quad1 = np.array(x_quad1, dtype = int)
y_quad1 = np.array(y_quad1, dtype = int)
x_quad2 = np.array(x_quad2, dtype = int)
y_quad2 = np.array(y_quad2, dtype = int)
x_quad3 = np.array(x_quad3, dtype = int)
y_quad3 = np.array(y_quad3, dtype = int)
x_quad4 = np.array(x_quad4, dtype = int)
y_quad4 = np.array(y_quad4, dtype = int)

print(np.vstack((x_quad1, y_quad1, x_quad2, y_quad2, 
                 x_quad3, y_quad3, x_quad4, y_quad4)).T)


plt.plot(x_quad1, y_quad1, x_quad2, y_quad2, x_quad3, y_quad3, x_quad4, y_quad4)

plt.show()