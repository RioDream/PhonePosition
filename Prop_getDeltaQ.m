function deltaQ = Prop_getDeltaQ(deltaT, w_l, w_)

%{

	最好还是使用4阶龙格库塔积分进行
	w_代表的是 l+1|l 时刻 的估计
%}


%{
	这里的 DeltaPhi对应的实际是 [IJRR](25)中的 deltaQ的L方程
    这里使用Mars中(124)式子Zero-Order Integrate
%}



%借鉴[TUM] 6.11中的 Runge-Kutta方法（其实就是直接拿来用）
q0 = [0 0 0 1]'; %deltaQ的初始值
k1 = 1/2 * Quater_omega(w_l)*q0;
k2 = 1/2 * Quater_omega( (w_l+w_)/2 )*(q0+deltaT/2*k1);
k3 = 1/2 * Quater_omega( (w_l+w_)/2 )*(q0+deltaT/2*k2);
k4 = 1/2 * Quater_omega(w_)*(q0+deltaT*k3);

deltaQ = q0 + deltaT/6 * (k1 + 2*k2 + 2*k3 + k4);

deltaQ = Quater_normalize(deltaQ);

%#TEST_DEBUG#
%也可以使用Mars中的 First-Order Integrate
mat_deltaPhi = eye(4) + (deltaT/2)*Quater_omega(w_l);
Quater_deltaQ = Quater_normalize( mat_deltaPhi(:,4) );
Debug_error = deltaQ - Quater_deltaQ;
assert( norm(Debug_error)<0.1, 'RioError: 两种方式计算得到的 deltaQ 不一致' );

end
