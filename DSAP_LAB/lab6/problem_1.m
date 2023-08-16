% Part (a) - Hamming Window for M=31
M1 = 31;
w_hamming_31 = hamming(M1);
freqz(w_hamming_31);

% Part (b) - Frequency response of the truncated FIR filter with Hamming window for M=31
ideal_response = [ones(M1/6+1, 1); zeros(M1/6, 1)];
h_fir_hamming_31 = firpm(M1, [0, 1/6, 1/6, 1], ideal_response, w_hamming_31);
freqz(h_fir_hamming_31);

% Part (c) - Hanning, Blackman, and Bartlett windows for M=31
w_hanning_31 = hann(M1);
w_blackman_31 = blackman(M1);
w_bartlett_31 = bartlett(M1);

% Part (d) - Frequency response of the truncated FIR filter with different windows for M=31
h_fir_hanning_31 = firpm(M1, [0, 1/6, 1/6, 1], ideal_response, w_hanning_31);
h_fir_blackman_31 = firpm(M1, [0, 1/6, 1/6, 1], ideal_response, w_blackman_31);
h_fir_bartlett_31 = firpm(M1, [0, 1/6, 1/6, 1], ideal_response, w_bartlett_31);

figure;
subplot(2, 2, 1);
freqz(h_fir_hamming_31);
title('Hamming Window (M=31)');

subplot(2, 2, 2);
freqz(h_fir_hanning_31);
title('Hanning Window (M=31)');

subplot(2, 2, 3);
freqz(h_fir_blackman_31);
title('Blackman Window (M=31)');

subplot(2, 2, 4);
freqz(h_fir_bartlett_31);
title('Bartlett Window (M=31)');

% Part (a) - Hamming Window for M=61
M2 = 61;
w_hamming_61 = hamming(M2);
freqz(w_hamming_61);

% Part (b) - Frequency response of the truncated FIR filter with Hamming window for M=61
h_fir_hamming_61 = firpm(M2, [0, 1/6, 1/6, 1], ideal_response, w_hamming_61);
freqz(h_fir_hamming_61);

% Part (c) - Hanning, Blackman, and Bartlett windows for M=61
w_hanning_61 = hann(M2);
w_blackman_61 = blackman(M2);
w_bartlett_61 = bartlett(M2);

% Part (d) - Frequency response of the truncated FIR filter with different windows for M=61
h_fir_hanning_61 = firpm(M2, [0, 1/6, 1/6, 1], ideal_response, w_hanning_61);
h_fir_blackman_61 = firpm(M2, [0, 1/6, 1/6, 1], ideal_response, w_blackman_61);
h_fir_bartlett_61 = firpm(M2, [0, 1/6, 1/6, 1], ideal_response, w_bartlett_61);

figure;
subplot(2, 2, 1);
freqz(h_fir_hamming_61);
title('Hamming Window (M=61)');

subplot(2, 2, 2);
freqz(h_fir_hanning_61);
title('Hanning Window (M=61)');

subplot(2, 2, 3);
freqz(h_fir_blackman_61);
title('Blackman Window (M=61)');

subplot(2, 2, 4);
freqz(h_fir_bartlett_61);
title('Bartlett Window (M=61)');