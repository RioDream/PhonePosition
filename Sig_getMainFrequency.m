function mainFrequency = Sig_getMainFrequency(values)
%{
Usage:
    values 是一个信号随时间变化的值， 
    从其中找到其中的主要频率
%}


fs = 100; %采样频率， 并不是说一定是这个频率， 只是近似100Hz， 误差在2Hz之间
nof_samples = length(values);
n = 0:nof_samples-1;
t=n/fs; %采样时间

y=fft(values, nof_samples);%进行fft变换
mag=abs(y);%求幅值
m=length(y);
f=(0:m/2-1)'*fs/m;%进行对应的频率转换
    
PLOT = 1;
if PLOT
    figure;
    plot(f,mag(1:m/2));%做频谱图
    axis([0,10,0,100]);
    xlabel('频率(Hz)');
    ylabel('幅值');
    title('linPosHP 的频率谱');
    
    figure;
    plot(t,values);%作正弦信号的时域波形
    xlabel('t');
    ylabel('y');
    title('linPosHP时域波形');
end
    
    [max_mag, max_mag_idx] = Sig_findMaxima(mag);
    mainFrequency = f(max_mag_idx);
end