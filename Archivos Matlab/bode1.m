clear
close
clc


sys = tf([1 0.1 7.5],[1 0.12 9 0 0]);
bode (sys)
hold on

%paso a discreto
Ts=0.1;

%sysd=c2d(sys,Ts,'tustin')
sysd=c2d(sys,Ts,'prewarp',0.1)

bode(sys,'r.',sysd,'b--')
% The Bode plot of a discrete-time system includes a vertical line marking 
% the Nyquist frequency of the system.