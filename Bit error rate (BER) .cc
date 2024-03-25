clc;
close all;
EbN0dB=-4:1:24; %dB range
EbN0lin=10.^(EbN0dB/10); %converting to ratios
colors={'k-*','g-o','r-h','c-s','m-s','y-*','k-p','b:s','m:d','g:p'};
index=1;
m=2:2:6;
M=2.^m;
for i=M,
k=log2(i);
berErr = 2/k*(1-1/sqrt(i))*erfc(sqrt(3*EbN0lin*k/(2*(i-1))));
plotHandle=plot(EbN0dB,log10(berErr),char(colors(index)));
set(plotHandle,'LineWidth',1.5);
index=index+1;
end
legend('16-QAM');
axis([-4 24 -8 0]);
set(gca,'XTick',-4:1:24);
ylabel('Probability of BER Error - log10(Pb)');
xlabel('Eb/N0 (dB)');
title('Probability of BER Error log10(Pb) Vs Eb/N0');
grid on;
