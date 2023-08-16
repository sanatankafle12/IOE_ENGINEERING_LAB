a = 2;
t = 0:0.01:5;

x = ones(size(t));
h = exp(-a * t) .* (t >= 0);

Y = conv(x, h) * 0.01;

tY = t(1) + t(1) : t(end) + t(end);

% Plot the result
figure;
plot(tY, Y);
xlabel('Time');
ylabel('Convolution Result');
title('Convolution of x(t) and h(t)');