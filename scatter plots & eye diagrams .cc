% Parameters
M = 4;          % Modulation order for OPSK
SNR_dB = 10;    % Signal-to-noise ratio in dB
numSymbols = 1000;
numSamplesPerSymbol = 8;
 
% Generate OPSK signal
data = randi([0 M-1], 1, numSymbols);
modulatedSignal = dpskmod(data, M);
 
% Add AWGN
receivedSignal = awgn(modulatedSignal, SNR_dB);
 
% Scatter Plot
scatterplot(receivedSignal);
title('Scatter Plot of OPSK Signal with AWGN');
xlabel('In-Phase');
ylabel('Quadrature');
 
% Eye Diagram
eyediagram(receivedSignal, numSamplesPerSymbol);
title('Eye Diagram of OPSK Signal with AWGN');
xlabel('Time');
ylabel('Amplitude');
