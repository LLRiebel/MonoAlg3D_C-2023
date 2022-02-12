real nao = 140.0;
real cao = 1.8;
real ko = 5.0;
real clo = 150.0;
real R = 8314;
real T = 310;
real F = 96485;
real zna = 1;
real zca = 2;
real zk = 1;
real zcl = -1;
real L = 0.01;
real rad = 0.0011;
real KmCaMK = 0.15;
real aCaMK = 0.05;
real bCaMK = 0.00068;
real CaMKo = 0.05;
real KmCaM = 0.0015;
real cmdnmax_b = 0.05;
real kmcmdn = 0.00238;
real trpnmax = 0.07;
real kmtrpn = 0.0005;
real BSRmax = 0.047;
real KmBSR = 0.00087;
real BSLmax = 1.124;
real KmBSL = 0.0087;
real csqnmax = 10;
real kmcsqn = 0.8;
real PKNa = 0.01833;
real gkatp = 4.3195;
real fkatp = 0.0;
real K_o_n = 5;
real A_atp = 2;
real K_atp = 0.25;
real GNa = 11.7802;
real thL = 200;
real GNaL_b = 0.0279;
real Gto_b = 0.16;
real EKshift = 0;
real Kmn = 0.002;
real k2n = 500;
real PCa_b = 8.3757e-05;
real Aff = 0.6;
real tjca = 72.5;
real vShift = 0;
real offset = 0;
real dielConstant = 74;
real ICaL_fractionSS = 0.8;
real GKr_b = 0.0321;
real alpha_1 = 0.154375;
real beta_1 = 0.1911;
real GKs_b = 0.0011;
real GK1_b = 0.6992;
real INaCa_fractionSS = 0.35;
real kna1 = 15;
real kna2 = 5;
real kna3 = 88.12;
real kasymm = 12.5;
real wna = 6e4;
real wca = 6e4;
real wnaca = 5e3;
real kcaon = 1.5e6;
real kcaoff = 5e3;
real qna = 0.5224;
real qca = 0.167;
real KmCaAct = 150e-6;
real Gncx_b = 0.0034;
real k1p = 949.5;
real k1m = 182.4;
real k2p = 687.2;
real k2m = 39.4;
real k3p = 1899;
real k3m = 79300;
real k4p = 639;
real k4m = 40;
real Knai0 = 9.073;
real Knao0 = 27.78;
real delta = -0.155;
real Kki = 0.5;
real Kko = 0.3582;
real MgADP = 0.05;
real MgATP = 9.8;
real Kmgatp = 1.698e-7;
real H = 1e-7;
real eP = 4.2;
real Khp = 1.698e-7;
real Knap = 224;
real Kxkur = 292;
real Pnak_b = 15.4509;
real GKb_b = 0.0189;
real PNab = 1.9239e-09;
real PCab = 5.9194e-08;
real GpCa = 5e-04;
real KmCap = 0.0005;
real GClCa = 0.2843;
real GClb = 1.98e-3;
real KdClCa = 0.1;
real Fjunc = 1;
real tauNa = 2.0;
real tauK = 2.0;
real tauCa = 0.2;
real tauCl = 2.0;
real bt = 4.75;
real cajsr_half = 1.7;
real Jrel_b = 1.5378;
real Jup_b = 1.0;
real vcell =  1000.00*3.14000*rad*rad*L;
real cmdnmax = (celltype==EPI ?  cmdnmax_b*1.30000 : cmdnmax_b);
real akik = pow(ko/K_o_n, 0.240000);
real bkik = 1.00000/(1.00000+pow(A_atp/K_atp, 2.00000));
real thLp =  3.00000*thL;
real GNaL = (celltype==EPI ?  GNaL_b*0.600000 : GNaL_b);
real Gto = (celltype==EPI ?  Gto_b*2.00000 : celltype==MID ?  Gto_b*2.00000 : Gto_b);
real Afs = 1.00000 - Aff;
real PCa = (celltype==EPI ?  PCa_b*1.20000 : celltype==MID ?  PCa_b*2.00000 : PCa_b);
real Io = ( 0.500000*(nao+ko+clo+ 4.00000*cao))/1000.00;
real GKr = (celltype==EPI ?  GKr_b*1.30000 : celltype==MID ?  GKr_b*0.800000 : GKr_b);
real GKs = (celltype==EPI ?  GKs_b*1.40000 : GKs_b);
real GK1 = (celltype==EPI ?  GK1_b*1.20000 : celltype==MID ?  GK1_b*1.30000 : GK1_b);
real GKb = (celltype==EPI ?  GKb_b*0.600000 : GKb_b);
real a_rel = ( 0.500000*bt)/1.00000;
real btp =  1.25000*bt;
real upScale = (celltype==EPI ? 1.30000 : 1.00000);
real Ageo =  2.00000*3.14000*rad*rad+ 2.00000*3.14000*rad*L;
real PCap =  1.10000*PCa;
real PCaNa =  0.00125000*PCa;
real PCaK =  0.000357400*PCa;
real constA =  1.82000e+06*pow( dielConstant*T, - 1.50000);
real a_relp = ( 0.500000*btp)/1.00000;
real Acap =  2.00000*Ageo;
real PCaNap =  0.00125000*PCap;
real PCaKp =  0.000357400*PCap;
real gamma_cao = exp( - constA*4.00000*( pow(Io, 1.0 / 2)/(1.00000+ pow(Io, 1.0 / 2)) -  0.300000*Io));
real gamma_nao = exp( - constA*1.00000*( pow(Io, 1.0 / 2)/(1.00000+ pow(Io, 1.0 / 2)) -  0.300000*Io));
real gamma_ko = exp( - constA*1.00000*( pow(Io, 1.0 / 2)/(1.00000+ pow(Io, 1.0 / 2)) -  0.300000*Io));
real vmyo =  0.680000*vcell;
real vnsr =  0.0552000*vcell;
real vjsr =  0.00480000*vcell;
real vss =  0.0200000*vcell;
real h10_i = kasymm+1.00000+ (nao/kna1)*(1.00000+nao/kna2);
real h11_i = ( nao*nao)/( h10_i*kna1*kna2);
real h12_i = 1.00000/h10_i;
real k1_i =  h12_i*cao*kcaon;
real k2_i = kcaoff;
real k5_i = kcaoff;
real Gncx = (celltype==EPI ?  Gncx_b*1.10000 : celltype==MID ?  Gncx_b*1.40000 : Gncx_b);
real h10_ss = kasymm+1.00000+ (nao/kna1)*(1.00000+nao/kna2);
real h11_ss = ( nao*nao)/( h10_ss*kna1*kna2);
real h12_ss = 1.00000/h10_ss;
real k1_ss =  h12_ss*cao*kcaon;
real k2_ss = kcaoff;
real k5_ss = kcaoff;
real b1 =  k1m*MgADP;
real a2 = k2p;
real a4 = (( k4p*MgATP)/Kmgatp)/(1.00000+MgATP/Kmgatp);
real Pnak = (celltype==EPI ?  Pnak_b*0.900000 : celltype==MID ?  Pnak_b*0.700000 : Pnak_b);

real mss = 1.00000/pow(1.00000+exp(- (v+56.8600)/9.03000), 2.00000);
real hss = 1.00000/pow(1.00000+exp((v+71.5500)/7.43000), 2.00000);
real mLss = 1.00000/(1.00000+exp(- (v+42.8500)/5.26400));
real hLss = 1.00000/(1.00000+exp((v+87.6100)/7.48800));
real hLssp = 1.00000/(1.00000+exp((v+93.8100)/7.48800));
real ass = 1.00000/(1.00000+exp(- ((v+EKshift) - 14.3400)/14.8200));
real iss = 1.00000/(1.00000+exp((v+EKshift+43.9400)/5.71100));
real dss = (v>=31.4978 ? 1.00000 :  1.07630*exp( - 1.00700*exp( - 0.0829000*v)));
real fss = 1.00000/(1.00000+exp((v+19.5800)/3.69600));
real jcass = 1.00000/(1.00000+exp((v+18.0800)/2.79160));
real km2n =  jca*1.00000;
//Istim = (VOI>=CONSTANTS[14]&&(VOI - CONSTANTS[14]) -  floor((VOI - CONSTANTS[14])/CONSTANTS[17])*CONSTANTS[17]<=CONSTANTS[18] ? CONSTANTS[16] : 0.00000);
real Istim = calc_I_stim;
real xs1ss = 1.00000/(1.00000+exp(- (v+11.6000)/8.93200));
real tm =  0.129200*exp(- pow((v+45.7900)/15.5400, 2.00000))+ 0.0648700*exp(- pow((v - 4.82300)/51.1200, 2.00000));
real ah = (v>=- 40.0000 ? 0.00000 :  0.0570000*exp(- (v+80.0000)/6.80000));
real aj = (v>=- 40.0000 ? 0.00000 : ( ( - 25428.0*exp( 0.244400*v) -  6.94800e-06*exp( - 0.0439100*v))*(v+37.7800))/(1.00000+exp( 0.311000*(v+79.2300))));
real tmL =  0.129200*exp(- pow((v+45.7900)/15.5400, 2.00000))+ 0.0648700*exp(- pow((v - 4.82300)/51.1200, 2.00000));
real ta = 1.05150/(1.00000/( 1.20890*(1.00000+exp(- ((v+EKshift) - 18.4099)/29.3814)))+3.50000/(1.00000+exp((v+EKshift+100.000)/29.3814)));
real delta_epi = (celltype==EPI ? 1.00000 - 0.950000/(1.00000+exp((v+EKshift+70.0000)/5.00000)) : 1.00000);
real fcass = fss;
real anca_ss = 1.00000/(k2n/km2n+pow(1.00000+Kmn/cass, 4.00000));
real anca_i = 1.00000/(k2n/km2n+pow(1.00000+Kmn/cai, 4.00000));
real td = offset+0.600000+1.00000/(exp( - 0.0500000*(v+vShift+6.00000))+exp( 0.0900000*(v+vShift+14.0000)));
real tff = 7.00000+1.00000/( 0.00450000*exp(- (v+20.0000)/10.0000)+ 0.00450000*exp((v+20.0000)/10.0000));
real tfs = 1000.00+1.00000/( 3.50000e-05*exp(- (v+5.00000)/4.00000)+ 3.50000e-05*exp((v+5.00000)/6.00000));
real vffrt = ( v*F*F)/( R*T);
real xs2ss = xs1ss;
real txs1 = 817.300+1.00000/( 0.000232600*exp((v+48.2800)/17.8000)+ 0.00129200*exp(- (v+210.000)/230.000));
real vfrt = ( v*F)/( R*T);
real bh = (v>=- 40.0000 ? 0.770000/( 0.130000*(1.00000+exp(- (v+10.6600)/11.1000))) :  2.70000*exp( 0.0790000*v)+ 310000.*exp( 0.348500*v));
real bj = (v>=- 40.0000 ? ( 0.600000*exp( 0.0570000*v))/(1.00000+exp( - 0.100000*(v+32.0000))) : ( 0.0242400*exp( - 0.0105200*v))/(1.00000+exp( - 0.137800*(v+40.1400))));
real tiF_b = 4.56200+1.00000/( 0.393300*exp(- (v+EKshift+100.000)/100.000)+ 0.0800400*exp((v+EKshift+50.0000)/16.5900));
real assp = 1.00000/(1.00000+exp(- ((v+EKshift) - 24.3400)/14.8200));
real tfcaf = 7.00000+1.00000/( 0.0400000*exp(- (v - 4.00000)/7.00000)+ 0.0400000*exp((v - 4.00000)/7.00000));
real tfcas = 100.000+1.00000/( 0.000120000*exp(- v/3.00000)+ 0.000120000*exp(v/7.00000));
real tffp =  2.50000*tff;
real txs2 = 1.00000/( 0.0100000*exp((v - 50.0000)/20.0000)+ 0.0193000*exp(- (v+66.5400)/31.0000));
real th = 1.00000/(ah+bh);
real jss = hss;
real tiS_b = 23.6200+1.00000/( 0.00141600*exp(- (v+EKshift+96.5200)/59.0500)+ 1.78000e-08*exp((v+EKshift+114.100)/8.07900));
real tfcafp =  2.50000*tfcaf;
real alpha =  0.116100*exp( 0.299000*vfrt);
real alpha_2 =  0.0578000*exp( 0.971000*vfrt);
real CaMKb = ( CaMKo*(1.00000 - CaMKt))/(1.00000+KmCaM/cass);
real tj = 1.00000/(aj+bj);
real hssp = 1.00000/pow(1.00000+exp((v+77.5500)/7.43000), 2.00000);
real tiF =  tiF_b*delta_epi;
real beta =  0.244200*exp( - 1.60400*vfrt);
real beta_2 =  0.000349000*exp( - 1.06200*vfrt);
real CaMKa = CaMKb+CaMKt;
real tjp =  1.46000*tj;
real tiS =  tiS_b*delta_epi;
real alpha_i =  0.253300*exp( 0.595300*vfrt);
real Bcai = 1.00000/(1.00000+( cmdnmax*kmcmdn)/pow(kmcmdn+cai, 2.00000)+( trpnmax*kmtrpn)/pow(kmtrpn+cai, 2.00000));
real dti_develop = 1.35400+0.000100000/(exp(((v+EKshift) - 167.400)/15.8900)+exp(- ((v+EKshift) - 12.2300)/0.215400));
real beta_i =  0.0652500*exp( - 0.820900*vfrt);
real Bcass = 1.00000/(1.00000+( BSRmax*KmBSR)/pow(KmBSR+cass, 2.00000)+( BSLmax*KmBSL)/pow(KmBSL+cass, 2.00000));
real dti_recover = 1.00000 - 0.500000/(1.00000+exp((v+EKshift+70.0000)/20.0000));
real alpha_C2ToI =  5.20000e-05*exp( 1.52500*vfrt);
real Bcajsr = 1.00000/(1.00000+( csqnmax*kmcsqn)/pow(kmcsqn+cajsr, 2.00000));
real tiFp =  dti_develop*dti_recover*tiF;
real tiSp =  dti_develop*dti_recover*tiS;
real beta_ItoC2 = ( beta_2*beta_i*alpha_C2ToI)/( alpha_2*alpha_i);
real ENa =  (( R*T)/( zna*F))*log(nao/nai);
real EK =  (( R*T)/( zk*F))*log(ko/ki);
real EKs =  (( R*T)/( zk*F))*log((ko+ PKNa*nao)/(ki+ PKNa*nai));
real ECl =  (( R*T)/( zcl*F))*log(clo/cli);
real EClss =  (( R*T)/( zcl*F))*log(clo/clss);
real I_katp =  fkatp*gkatp*akik*bkik*(v - EK);
real fINap = 1.00000/(1.00000+KmCaMK/CaMKa);
real INa =  GNa*(v - ENa)*pow(m, 3.00000)*( (1.00000 - fINap)*h*j+ fINap*hp*jp);
real fINaLp = 1.00000/(1.00000+KmCaMK/CaMKa);
real INaL =  GNaL*(v - ENa)*mL*( (1.00000 - fINaLp)*hL+ fINaLp*hLp);
real AiF = 1.00000/(1.00000+exp(((v+EKshift) - 213.600)/151.200));
real AiS = 1.00000 - AiF;
real i =  AiF*iF+ AiS*iS;
real ip =  AiF*iFp+ AiS*iSp;
real fItop = 1.00000/(1.00000+KmCaMK/CaMKa);
real Ito =  Gto*(v - EK)*( (1.00000 - fItop)*a*i+ fItop*ap*ip);
real f =  Aff*ff+ Afs*fs;
real Afcaf = 0.300000+0.600000/(1.00000+exp((v - 10.0000)/10.0000));
real Afcas = 1.00000 - Afcaf;
real fca =  Afcaf*fcaf+ Afcas*fcas;
real fp =  Aff*ffp+ Afs*fs;
real fcap =  Afcaf*fcafp+ Afcas*fcas;
real Iss = ( 0.500000*(nass+kss+clss+ 4.00000*cass))/1000.00;
real gamma_cass = exp( - constA*4.00000*( pow(Iss, 1.0 / 2)/(1.00000+ pow(Iss, 1.0 / 2)) -  0.300000*Iss));
real gamma_nass = exp( - constA*1.00000*( pow(Iss, 1.0 / 2)/(1.00000+ pow(Iss, 1.0 / 2)) -  0.300000*Iss));
real gamma_kss = exp( - constA*1.00000*( pow(Iss, 1.0 / 2)/(1.00000+ pow(Iss, 1.0 / 2)) -  0.300000*Iss));
real PhiCaL_ss = ( 4.00000*vffrt*( gamma_cass*cass*exp( 2.00000*vfrt) -  gamma_cao*cao))/(exp( 2.00000*vfrt) - 1.00000);
real PhiCaNa_ss = ( 1.00000*vffrt*( gamma_nass*nass*exp( 1.00000*vfrt) -  gamma_nao*nao))/(exp( 1.00000*vfrt) - 1.00000);
real PhiCaK_ss = ( 1.00000*vffrt*( gamma_kss*kss*exp( 1.00000*vfrt) -  gamma_ko*ko))/(exp( 1.00000*vfrt) - 1.00000);
real fICaLp = 1.00000/(1.00000+KmCaMK/CaMKa);
real ICaL_ss =  ICaL_fractionSS*( (1.00000 - fICaLp)*PCa*PhiCaL_ss*d*( f*(1.00000 - nca_ss)+ jca*fca*nca_ss)+ fICaLp*PCap*PhiCaL_ss*d*( fp*(1.00000 - nca_ss)+ jca*fcap*nca_ss));
real ICaNa_ss =  ICaL_fractionSS*( (1.00000 - fICaLp)*PCaNa*PhiCaNa_ss*d*( f*(1.00000 - nca_ss)+ jca*fca*nca_ss)+ fICaLp*PCaNap*PhiCaNa_ss*d*( fp*(1.00000 - nca_ss)+ jca*fcap*nca_ss));
real Jrel_inf_b = (( - a_rel*ICaL_ss)/1.00000)/(1.00000+pow(cajsr_half/cajsr, 8.00000));
real Jrel_infp_b = (( - a_relp*ICaL_ss)/1.00000)/(1.00000+pow(cajsr_half/cajsr, 8.00000));
real ICaK_ss =  ICaL_fractionSS*( (1.00000 - fICaLp)*PCaK*PhiCaK_ss*d*( f*(1.00000 - nca_ss)+ jca*fca*nca_ss)+ fICaLp*PCaKp*PhiCaK_ss*d*( fp*(1.00000 - nca_ss)+ jca*fcap*nca_ss));
real Jrel_inf = (celltype==MID ?  Jrel_inf_b*1.70000 : Jrel_inf_b);
real Jrel_infp = (celltype==MID ?  Jrel_infp_b*1.70000 : Jrel_infp_b);
real Ii = ( 0.500000*(nai+ki+cli+ 4.00000*cai))/1000.00;
real tau_rel_b = bt/(1.00000+0.0123000/cajsr);
real tau_relp_b = btp/(1.00000+0.0123000/cajsr);
real gamma_cai = exp( - constA*4.00000*( pow(Ii, 1.0 / 2)/(1.00000+ pow(Ii, 1.0 / 2)) -  0.300000*Ii));
real tau_rel = (tau_rel_b<0.00100000 ? 0.00100000 : tau_rel_b);
real tau_relp = (tau_relp_b<0.00100000 ? 0.00100000 : tau_relp_b);
real gamma_nai = exp( - constA*1.00000*( pow(Ii, 1.0 / 2)/(1.00000+ pow(Ii, 1.0 / 2)) -  0.300000*Ii));
real gamma_ki = exp( - constA*1.00000*( pow(Ii, 1.0 / 2)/(1.00000+ pow(Ii, 1.0 / 2)) -  0.300000*Ii));
real PhiCaL_i = ( 4.00000*vffrt*( gamma_cai*cai*exp( 2.00000*vfrt) -  gamma_cao*cao))/(exp( 2.00000*vfrt) - 1.00000);
real PhiCaNa_i = ( 1.00000*vffrt*( gamma_nai*nai*exp( 1.00000*vfrt) -  gamma_nao*nao))/(exp( 1.00000*vfrt) - 1.00000);
real PhiCaK_i = ( 1.00000*vffrt*( gamma_ki*ki*exp( 1.00000*vfrt) -  gamma_ko*ko))/(exp( 1.00000*vfrt) - 1.00000);
real ICaL_i =  (1.00000 - ICaL_fractionSS)*( (1.00000 - fICaLp)*PCa*PhiCaL_i*d*( f*(1.00000 - nca_i)+ jca*fca*nca_i)+ fICaLp*PCap*bt*d*( fp*(1.00000 - nca_i)+ jca*fcap*nca_i));
real ICaNa_i =  (1.00000 - ICaL_fractionSS)*( (1.00000 - fICaLp)*PCaNa*PhiCaNa_i*d*( f*(1.00000 - nca_i)+ jca*fca*nca_i)+ fICaLp*PCaNap*PhiCaNa_i*d*( fp*(1.00000 - nca_i)+ jca*fcap*nca_i));
real ICaK_i =  (1.00000 - ICaL_fractionSS)*( (1.00000 - fICaLp)*PCaK*PhiCaK_i*d*( f*(1.00000 - nca_i)+ jca*fca*nca_i)+ fICaLp*PCaKp*PhiCaK_i*d*( fp*(1.00000 - nca_i)+ jca*fcap*nca_i));
real ICaL = ICaL_ss+ICaL_i;
real ICaNa = ICaNa_ss+ICaNa_i;
real ICaK = ICaK_ss+ICaK_i;
real IKr =  GKr* pow((ko/5.00000), 1.0 / 2)*O*(v - EK);
real KsCa = 1.00000+0.600000/(1.00000+pow(3.80000e-05/cai, 1.40000));
real IKs =  GKs*KsCa*xs1*xs2*(v - EKs);
real aK1 = 4.09400/(1.00000+exp( 0.121700*((v - EK) - 49.9340)));
real bK1 = ( 15.7200*exp( 0.0674000*((v - EK) - 3.25700))+exp( 0.0618000*((v - EK) - 594.310)))/(1.00000+exp( - 0.162900*((v - EK)+14.2070)));
real K1ss = aK1/(aK1+bK1);
real IK1 =  GK1* pow((ko/5.00000), 1.0 / 2)*K1ss*(v - EK);
real hca = exp( qca*vfrt);
real hna = exp( qna*vfrt);
real h1_i = 1.00000+ (nai/kna3)*(1.00000+hna);
real h2_i = ( nai*hna)/( kna3*h1_i);
real h3_i = 1.00000/h1_i;
real h4_i = 1.00000+ (nai/kna1)*(1.00000+nai/kna2);
real h5_i = ( nai*nai)/( h4_i*kna1*kna2);
real h6_i = 1.00000/h4_i;
real h7_i = 1.00000+ (nao/kna3)*(1.00000+1.00000/hna);
real h8_i = nao/( kna3*hna*h7_i);
real h9_i = 1.00000/h7_i;
real k3p_i =  h9_i*wca;
real k3pp_i =  h8_i*wnaca;
real k3_i = k3p_i+k3pp_i;
real k4p_i = ( h3_i*wca)/hca;
real k4pp_i =  h2_i*wnaca;
real k4_i = k4p_i+k4pp_i;
real k6_i =  h6_i*cai*kcaon;
real k7_i =  h5_i*h2_i*wna;
real k8_i =  h8_i*h11_i*wna;
real x1_i =  k2_i*k4_i*(k7_i+k6_i)+ k5_i*k7_i*(k2_i+k3_i);
real x2_i =  k1_i*k7_i*(k4_i+k5_i)+ k4_i*k6_i*(k1_i+k8_i);
real x3_i =  k1_i*k3_i*(k7_i+k6_i)+ k8_i*k6_i*(k2_i+k3_i);
real x4_i =  k2_i*k8_i*(k4_i+k5_i)+ k3_i*k5_i*(k1_i+k8_i);
real E1_i = x1_i/(x1_i+x2_i+x3_i+x4_i);
real E2_i = x2_i/(x1_i+x2_i+x3_i+x4_i);
real E3_i = x3_i/(x1_i+x2_i+x3_i+x4_i);
real E4_i = x4_i/(x1_i+x2_i+x3_i+x4_i);
real allo_i = 1.00000/(1.00000+pow(KmCaAct/cai, 2.00000));
real JncxNa_i = ( 3.00000*( E4_i*k7_i -  E1_i*k8_i)+ E3_i*k4pp_i) -  E2_i*k3pp_i;
real JncxCa_i =  E2_i*k2_i -  E1_i*k1_i;
real INaCa_i =  (1.00000 - INaCa_fractionSS)*Gncx*allo_i*( zna*JncxNa_i+ zca*JncxCa_i);
real h1_ss = 1.00000+ (nass/kna3)*(1.00000+hna);
real h2_ss = ( nass*hna)/( kna3*h1_ss);
real h3_ss = 1.00000/h1_ss;
real h4_ss = 1.00000+ (nass/kna1)*(1.00000+nass/kna2);
real h5_ss = ( nass*nass)/( h4_ss*kna1*kna2);
real h6_ss = 1.00000/h4_ss;
real h7_ss = 1.00000+ (nao/kna3)*(1.00000+1.00000/hna);
real h8_ss = nao/( kna3*hna*h7_ss);
real h9_ss = 1.00000/h7_ss;
real k3p_ss =  h9_ss*wca;
real k3pp_ss =  h8_ss*wnaca;
real k3_ss = k3p_ss+k3pp_ss;
real k4p_ss = ( h3_ss*wca)/hca;
real k4pp_ss =  h2_ss*wnaca;
real k4_ss = k4p_ss+k4pp_ss;
real k6_ss =  h6_ss*cass*kcaon;
real k7_ss =  h5_ss*h2_ss*wna;
real k8_ss =  h8_ss*h11_ss*wna;
real x1_ss =  k2_ss*k4_ss*(k7_ss+k6_ss)+ k5_ss*k7_ss*(k2_ss+k3_ss);
real x2_ss =  k1_ss*k7_ss*(k4_ss+k5_ss)+ k4_ss*k6_ss*(k1_ss+k8_ss);
real x3_ss =  k1_ss*k3_ss*(k7_ss+k6_ss)+ k8_ss*k6_ss*(k2_ss+k3_ss);
real x4_ss =  k2_ss*k8_ss*(k4_ss+k5_ss)+ k3_ss*k5_ss*(k1_ss+k8_ss);
real E1_ss = x1_ss/(x1_ss+x2_ss+x3_ss+x4_ss);
real E2_ss = x2_ss/(x1_ss+x2_ss+x3_ss+x4_ss);
real E3_ss = x3_ss/(x1_ss+x2_ss+x3_ss+x4_ss);
real E4_ss = x4_ss/(x1_ss+x2_ss+x3_ss+x4_ss);
real allo_ss = 1.00000/(1.00000+pow(KmCaAct/cass, 2.00000));
real JncxNa_ss = ( 3.00000*( E4_ss*k7_ss -  E1_ss*k8_ss)+ E3_ss*k4pp_ss) -  E2_ss*k3pp_ss;
real JncxCa_ss =  E2_ss*k2_ss -  E1_ss*k1_ss;
real INaCa_ss =  INaCa_fractionSS*Gncx*allo_ss*( zna*JncxNa_ss+ zca*JncxCa_ss);
real Knai =  Knai0*exp(( delta*vfrt)/3.00000);
real Knao =  Knao0*exp(( (1.00000 - delta)*vfrt)/3.00000);
real P = eP/(1.00000+H/Khp+nai/Knap+ki/Kxkur);
real a1 = ( k1p*pow(nai/Knai, 3.00000))/((pow(1.00000+nai/Knai, 3.00000)+pow(1.00000+ki/Kki, 2.00000)) - 1.00000);
real b2 = ( k2m*pow(nao/Knao, 3.00000))/((pow(1.00000+nao/Knao, 3.00000)+pow(1.00000+ko/Kko, 2.00000)) - 1.00000);
real a3 = ( k3p*pow(ko/Kko, 2.00000))/((pow(1.00000+nao/Knao, 3.00000)+pow(1.00000+ko/Kko, 2.00000)) - 1.00000);
real b3 = ( k3m*P*H)/(1.00000+MgATP/Kmgatp);
real b4 = ( k4m*pow(ki/Kki, 2.00000))/((pow(1.00000+nai/Knai, 3.00000)+pow(1.00000+ki/Kki, 2.00000)) - 1.00000);
real x1 =  a4*a1*a2+ b2*b4*b3+ a2*b4*b3+ b3*a1*a2;
real x2 =  b2*b1*b4+ a1*a2*a3+ a3*b1*b4+ a2*a3*b4;
real x3 =  a2*a3*a4+ b3*b2*b1+ b2*b1*a4+ a3*a4*b1;
real x4 =  b4*b3*b2+ a3*a4*a1+ b2*a4*a1+ b3*b2*a1;
real E1 = x1/(x1+x2+x3+x4);
real E2 = x2/(x1+x2+x3+x4);
real E3 = x3/(x1+x2+x3+x4);
real E4 = x4/(x1+x2+x3+x4);
real JnakNa =  3.00000*( E1*a3 -  E2*b3);
real JnakK =  2.00000*( E4*b1 -  E3*a1);
real INaK =  Pnak*( zna*JnakNa+ zk*JnakK);
real xkb = 1.00000/(1.00000+exp(- (v - 10.8968)/23.9871));
real IKb =  GKb*xkb*(v - EK);
real INab = ( PNab*vffrt*( nai*exp(vfrt) - nao))/(exp(vfrt) - 1.00000);
real JdiffK = (kss - ki)/tauK;
real ICab = ( PCab*4.00000*vffrt*( gamma_cai*cai*exp( 2.00000*vfrt) -  gamma_cao*cao))/(exp( 2.00000*vfrt) - 1.00000);
real JdiffNa = (nass - nai)/tauNa;
real IpCa = ( GpCa*cai)/(KmCap+cai);
real IClCa_junc =  (( Fjunc*GClCa)/(1.00000+KdClCa/cass))*(v - EClss);
real Jdiff = (cass - cai)/tauCa;
real IClCa_sl =  (( (1.00000 - Fjunc)*GClCa)/(1.00000+KdClCa/cai))*(v - ECl);
real fJrelp = 1.00000/(1.00000+KmCaMK/CaMKa);
real IClCa = IClCa_junc+IClCa_sl;
real Jrel =  Jrel_b*( (1.00000 - fJrelp)*Jrel_np+ fJrelp*Jrel_p);
real IClb =  GClb*(v - ECl);
real Jupnp = ( upScale*0.00542500*cai)/(cai+0.000920000);
real Jupp = ( upScale*2.75000*0.00542500*cai)/((cai+0.000920000) - 0.000170000);
real JdiffCl = (clss - cli)/tauNa;
real fJupp = 1.00000/(1.00000+KmCaMK/CaMKa);
real Jleak = ( 0.00488250*cansr)/15.0000;
real Jup =  Jup_b*(( (1.00000 - fJupp)*Jupnp+ fJupp*Jupp) - Jleak);
real Jtr = (cansr - cajsr)/60.0000;

// Euler
rDY_[0] = - (INa+INaL+Ito+ICaL+ICaNa+ICaK+IKr+IKs+IK1+INaCa_i+INaCa_ss+INaK+INab+IKb+IpCa+ICab+IClCa+IClb+I_katp+Istim);
rDY_[1] =  aCaMK*CaMKb*(CaMKb+CaMKt) -  bCaMK*CaMKt;
rDY_[2] =  Bcass*((( - (ICaL_ss -  2.00000*INaCa_ss)*Acap)/( 2.00000*F*vss)+( Jrel*vjsr)/vss) - Jdiff);
rDY_[3] = ( - (INa+INaL+ 3.00000*INaCa_i+ICaNa_i+ 3.00000*INaK+INab)*Acap)/( F*vmyo)+( JdiffNa*vss)/vmyo;
rDY_[4] = ( - (ICaNa_ss+ 3.00000*INaCa_ss)*Acap)/( F*vss) - JdiffNa;
rDY_[5] = ( - (((Ito+IKr+IKs+IK1+IKb+I_katp+Istim) -  2.00000*INaK)+ICaK_i)*Acap)/( F*vmyo)+( JdiffK*vss)/vmyo;
rDY_[6] = ( - ICaK_ss*Acap)/( F*vss) - JdiffK;
rDY_[7] = Jup - ( Jtr*vjsr)/vnsr;
rDY_[8] =  Bcajsr*(Jtr - Jrel);
rDY_[9] =  Bcai*((( - ((ICaL_i+IpCa+ICab) -  2.00000*INaCa_i)*Acap)/( 2.00000*F*vmyo) - ( Jup*vnsr)/vmyo)+( Jdiff*vss)/vmyo);
rDY_[10] = ( (IClb+IClCa_sl)*Acap)/( F*vmyo)+( JdiffCl*vss)/vmyo;
rDY_[11] = ( IClCa_junc*Acap)/( F*vss) - JdiffCl;

// Euler
rDY_[12] = (mss - m)/tm;
rDY_[13] = (hss - h)/th;
rDY_[14] = (jss - j)/tj;
rDY_[15] = (hssp - hp)/th;
rDY_[16] = (jss - jp)/tjp;
rDY_[17] = (mLss - mL)/tmL;
rDY_[18] = (hLss - hL)/thL;
rDY_[19] = (hLssp - hLp)/thLp;
rDY_[20] = (ass - a)/ta;
rDY_[21] = (iss - iF)/tiF;
rDY_[22] = (iss - iS)/tiS;
rDY_[23] = (assp - ap)/ta;
rDY_[24] = (iss - iFp)/tiFp;
rDY_[25] = (iss - iSp)/tiSp;
rDY_[26] = (dss - d)/td;
rDY_[27] = (fss - ff)/tff;
rDY_[28] = (fss - fs)/tfs;
rDY_[29] = (fcass - fcaf)/tfcaf;
rDY_[30] = (fcass - fcas)/tfcas;
rDY_[31] = (jcass - jca)/tjca;
rDY_[32] = (fss - ffp)/tffp;
rDY_[33] = (fcass - fcafp)/tfcafp;

// Rush-Larsen
//rDY_[12] = mss + (m - mss)*exp(-dt/tm);
//rDY_[13] = hss + (h - hss)*exp(-dt/th);
//rDY_[14] = jss + (j - jss)*exp(-dt/tj);
//rDY_[15] = hssp + (hp - hssp)*exp(-dt/th);
//rDY_[16] = jss + (jp - jss)*exp(-dt/tjp);
//rDY_[17] = mLss + (mL - mLss)*exp(-dt/tmL);
//rDY_[18] = hLss + (hL - hLss)*exp(-dt/thL);
//rDY_[19] = hLssp + (hLp - hLssp)*exp(-dt/thLp);
//rDY_[20] = ass + (a - ass)*exp(-dt/ta);
//rDY_[21] = iss + (iF - iss)*exp(-dt/tiF);
//rDY_[22] = iss + (iS - iss)*exp(-dt/tiS);
//rDY_[23] = assp + (ap - assp)*exp(-dt/ta);
//rDY_[24] = iss + (iFp - iss)*exp(-dt/tiFp);
//rDY_[25] = iss + (iSp - iss)*exp(-dt/tiSp);
//rDY_[26] = dss + (d - dss)*exp(-dt/td);
//rDY_[27] = fss + (ff - fss)*exp(-dt/tff);
//rDY_[28] = fss + (fs - fss)*exp(-dt/tfs);
//rDY_[29] = fcass + (fcaf - fcass)*exp(-dt/tfcaf);
//rDY_[30] = fcass + (fcas - fcass)*exp(-dt/tfcas);
//rDY_[31] = jcass + (jca - jcass)*exp(-dt/tjca);
//rDY_[32] = fss + (ffp - fss)*exp(-dt/tffp);
//rDY_[33] = fcass + (fcafp - fcass)*exp(-dt/tfcafp);

// Euler
rDY_[34] =  anca_ss*k2n -  nca_ss*km2n;
rDY_[35] =  anca_i*k2n -  nca_i*km2n;
rDY_[36] = ( alpha_1*C2+ beta_2*O+ beta_ItoC2*I) -  (beta_1+alpha_2+alpha_C2ToI)*C1;
rDY_[37] = ( alpha*C3+ beta_1*C1) -  (beta+alpha_1)*C2;
rDY_[38] =  beta*C2 -  alpha*C3;
rDY_[39] = ( alpha_C2ToI*C1+ alpha_i*O) -  (beta_ItoC2+beta_i)*I;
rDY_[40] = ( alpha_2*C1+ beta_i*I) -  (beta_2+alpha_i)*O;

// Euler
rDY_[41] = (xs1ss - xs1)/txs1;
rDY_[42] = (xs2ss - xs2)/txs2;
rDY_[43] = (Jrel_inf - Jrel_np)/tau_rel;
rDY_[44] = (Jrel_infp - Jrel_p)/tau_relp;

// Rush-Larsen
//rDY_[41] = xs1ss + (xs1 - xs1ss)*exp(-dt/txs1);
//rDY_[42] = xs2ss + (xs2 - xs2ss)*exp(-dt/txs2);
//rDY_[43] = Jrel_inf + (Jrel_np - Jrel_inf)*exp(-dt/tau_rel);
//rDY_[44] = Jrel_infp + (Jrel_p - Jrel_infp)*exp(-dt/tau_relp);