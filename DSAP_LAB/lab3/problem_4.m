k = 0:100;
Tp = [10, 20, 50];
t = 1:100;
x = ones(size(t));
y = zeros(length(Tp), length(t) + length(k) - 1);

for i = 1:length(Tp)
    h = (2 / Tp(i)) * sinc((k * 2) / Tp(i));
    y(i, :) = conv(x, h);
end

figure;
for i = 1:length(Tp)
    subplot(length(Tp), 1, i);
    plot(t, y(i, 1:length(t)));
    xlabel('t');
    ylabel('y(t)');
    title(['Output for Tp = ', num2str(Tp(i))]);
end