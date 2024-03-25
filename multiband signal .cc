% Parameters
Fs = 1000;          % Sampling frequency
t = 0:1/Fs:1;       % Time vector
frequencies = [5, 20, 20];  % Frequencies of the bands
 
% Generate multi-band signal
signal = zeros(size(t));
for freq = frequencies
    modulationIndex = 2;  % Adjust the modulation index as needed
    carrier = cos(2*pi*freq*t);
    modulatedSignal = fmmod(carrier, freq, Fs, modulationIndex);
    signal = signal + modulatedSignal;
end
 
% Plot the multi-band signal
figure;
plot(t, signal);
title('Multi-Band Signal');
xlabel('Time (s)');
ylabel('Amplitude');
 
% Play the audio (optional)
soundsc(signal, Fs);
