% Given sequences
x = [1, 1, 1, 1, 1, 0, 0, 0, 0, 0];  
h = [0, 2, 4, 6, 8, 10, 12, 0, 0, 0];

y = conv(x, h);


n = 0:9;

subplot(3,1,1);
stem(n, x);
xlabel('n');
ylabel('x[n]');
title('Input Signal');

subplot(3,1,2);
stem(n, h);
xlabel('n');
ylabel('h[n]');
title('Impulse Response');

subplot(3,1,3);
stem(0:length(y)-1, y);
xlabel('n');
ylabel('y[n]');
title('System Response');