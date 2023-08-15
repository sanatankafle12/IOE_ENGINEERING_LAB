from graphics import *

def main():
  win = GraphWin("My Window", 800, 800)
  win.setBackground('white')
  bresenham(78,41,542,100,win)
  win.getMouse()
  win.close()

def bresenham(x1,y1,x2,y2, win):
  dx = x2 - x1
  dy = y2 - y1
  pk = 2*dy - dx
  if(x2 > x1):
    lx = 1
  else:
    lx = -1
  if(y2 > y1):
    ly = 1
  else:
    ly = -1
    pt = Point(round(x1),round(y1))
    pt.setFill('black')
    pt.draw(win)
  if(dx > dy):
    pk = 2*dy - dx
    for i in range(dx):
      if(pk < 0):
        x1 = x1 + lx
        y1 = y1
        pk = pk + 2*dy
      else:
        x1 = x1 + lx
        y1 = y1 + ly
        pk = pk + 2 *(dy - dx)
      pt = Point(x1,y1)
      pt.setFill('black')
      pt.draw(win)
  else:
    pk = 2*dx - dy
    for i in range(dy):
      if(pk < 0):
        x1 = x1
        y1 = y1 + ly
        pk = pk + 2*dx
      else:
        x1 = x1 + lx
        y1 = y1 + ly
        pk = pk + 2 *(dx - dy)
      pt = Point(x1,y1)
      pt.setFill('black')
      pt.draw(win)
  
main()
  
  



         
