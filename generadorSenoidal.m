% generador senoidal
% comentar o descomentar para imprimir el la respuesta
% al impulso analogico o al impulso digital
close all
% clear
%hold off
% syms f t w
% f = sin(w*t)
% laplace (f) % transformada de laplace del seno
%
% clear

f=100; % frecuencia
T=1/f; % periodo
muestreo=50; % muestras por ciclo
Ts=T/muestreo; % 50 muestras por ciclo;
w=2*pi*f; % 2 por pi por frecuencia


num=[w];
den=[1 0 w^2];
sys=tf(num,den);
%help tf




%impulse(sys,T) % la respuesta sera un seno

% paso a discreto con Timepo de muestreo Ts y aprox bilineal
[numd,dend] = c2dm(num,den,Ts,'tustin');
%help c2dm
dimpulse((1/Ts)*numd,dend,muestreo+1)
hold off


% hacer un generador de 100Hz de un coseno en las mismas condiciones que el
% del seno. en matlab y excel.
%simular una tangente a 90 grados.