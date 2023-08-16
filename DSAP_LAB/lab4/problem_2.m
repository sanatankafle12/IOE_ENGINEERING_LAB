num = [0.0018, 0.0073, 0.011, 0.007, 0.008];
den = [1, -3.0544, 3.8291, -2.2925, 0.55072];

zplane(num, den);
sosMatrix = tf2sos(num, den);
freqz(num, den);