% Given signals
X1 = [1, 1, 1, 1, 1];
n1 = [-2, -1, 0, 1, 2];
X2 = [1, 0, 0, 0, 0, 0, 0, 0, 0, 0];
n2 = [-4, -3, -2, -1, 0, 1, 2, 3, 4, 5];

Y2 = zeros(1, length(n1) + length(n2) - 1);

for i = 1:length(n1)
    for j = 1:length(n2)
        index = i + j - 1;
        Y2(index) = Y2(index) + X1(i) * X2(j);
    end
end

disp('Convolution Result:');
disp(Y2);