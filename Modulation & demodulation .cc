clc;
clear all;
close all;
Am=0.75;   % message signal amplitude
Ac=1;   % carrier signal amplitude
fc=20;   % carrier signal frequency
fm=1;   % message signal frequency
fs=100; % sampling frequency
N=200; % Number of samples
ts=1/fs;
t=0:ts:(N-1)*ts;
vm=Am*sin(2*pi*fm*t); % message signal
vc=Ac*sin(2*pi*fc*t); % carrier signal
y=(Ac+vm).*vc; % modulated signal
subplot(311);
plot(t,vm,'b');
xlabel('Time');
ylabel('Amplitude');
title('Message signal')
subplot(312)
plot(t,vc,'r');
xlabel('Time');
ylabel('Amplitude');
title('Carrier signal');
subplot(313);
plot(t,y,'m');
xlabel('Time');
ylabel('Amplitude');
title('Modulated signal');
m=Am/Ac;
disp('Modulation Index m=');
disp(m);
% Frequency Spectrum
figure(2);
f=[-fs/2:fs/N:fs/2-fs/N];%frequency axis
ff=fftshift(abs(fft(y)));
stem(f,ff)
xlabel('Frequency');
ylabel('Magnitude');
title('Frequency Spectrum');

