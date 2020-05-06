clear
clc

num=[1];
den=conv([1 2],[1 3]);
sys=tf(num,den)
Ts=0.02;
[numd,dend] = c2dm(num,den,Ts,'zoh')



sisotool (sys)
