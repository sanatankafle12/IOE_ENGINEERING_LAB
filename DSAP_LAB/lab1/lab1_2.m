a = 2
w = 5
t = 0:0.1:10

y = exp(-a*t).*cos(w*t)

plot(t,y)