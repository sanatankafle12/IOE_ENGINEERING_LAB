weight = [0.5,0.5]
alpha = 0.2
x_in = [[i,j] for i in range(2) for j in range(2)]
target = [1,1,1,0]
y = [0,0,0,0]
bias = [1,1,1,1]

for i in range(10000):
    for j in range(4):
        y[j] = bias[j]+x_in[j][0]*weight[0]+x_in[j][1]*weight[1]
        weight[0] = weight[0] + alpha*(target[j]-y[j])*x_in[j][0]
        weight[1] = weight[1] + alpha*(target[j]-y[j])*x_in[j][1]
        bias[j] = bias[j] + alpha*(target[j]-y[j])

output = [round(bias[j]+weight[0]*x_in[j][0]+weight[1]*x_in[j][1],5) for j in range(4)]
print(output)