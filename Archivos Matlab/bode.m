clear
close
clc

num=1;
den=[1 1];
sys=tf(num,den)
bode (sys)
hold on

%paso a discreto
Ts=0.1;

%sysd=c2d(sys,Ts,'tustin')
sysd=c2d(sys,Ts,'prewarp',0.1)

bode(sys,'r.',sysd,'b--')
% The Bode plot of a discrete-time system includes a vertical line marking 
% the Nyquist frequency of the system.




