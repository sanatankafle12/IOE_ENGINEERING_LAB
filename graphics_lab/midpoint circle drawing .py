from graphics import *

def main():
	win = GraphWin("My Window", 800, 800)
	win.setBackground('white')
	xc =50
	yc = 50
	r = 200
	circle(r, 100, win, xc, yc)
	win.getMouse()
	win.close()
	



def circle(radius,offset, win, xc, yc):
	x,y = 0,radius
	plotCircle(x,y,radius,offset, win, xc, yc)

def symmetry_points(x,y,offset,win, xc, yc):
	pt = Point(x+xc+offset,y+yc+offset)
	pt.setFill('brown')
	pt.draw(win)
	pt = Point(-x+xc+offset,y+yc+offset)
	pt.setFill('brown')
	pt.draw(win)
	pt = Point(x+xc+offset,-y+yc+offset)
	pt.setFill('brown')
	pt.draw(win)
	pt = Point(-x+xc+offset,-y+yc+offset)
	pt.setFill('brown')
	pt.draw(win)
	pt = Point(y+xc +offset,x+yc+offset)
	pt.setFill('brown')
	pt.draw(win)
	pt = Point(-y+xc+offset,x+yc+offset)
	pt.setFill('brown')
	pt.draw(win)
	pt = Point(y+xc+offset,-x+yc+offset)
	pt.setFill('brown')
	pt.draw(win)
	pt = Point(-y+xc+offset,-x+yc+offset)
	pt.setFill('brown')
	pt.draw(win)

def plotCircle(x,y,radius,offset, win,xc, yc):
	d = 5/4.0 - radius
	symmetry_points(x,y,radius+offset,win,xc,yc)
	while x < y:
		if d < 0:
			x += 1
			d += 2*x + 1
		else:
			x += 1
			y -= 1
			d += 2*(x-y) + 1
		symmetry_points(x,y,radius+offset, win, xc, yc)


main()
