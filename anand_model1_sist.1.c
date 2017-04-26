#include<stdio.h>												//������ ��� ������� ����������������
#include <stdlib.h>
#include<math.h>

double TF_0=5, VII_0=10, TF__VII_0=0.0, VII_a_0=0.1, TF__VII_a_0=0.0, IX_0=90.0, IX_a_0=0.009, IX_m_0=0.0, IX_a_m_0=0.0;
double X_0=170, X_a_0=0.017, X_m_0=0.0, X_a_m_0=0.0, II_0=1400.0, II_a_0=0.14, II_m_0=0.0, II_a_m_0=0.0, PL_0=10.0, AP_0=0.001;
double VIII_0=0.7, VIII_a_0=0.00007, VIII_m_0=0.0, VIII_a_m_0=0.0, VIII_a_m__IX_a_m_0=0.0;
double V_0=20.0, V_a_0=0.002, V_m_0=0.0, V_a_m_0=0.0, X_a_m__V_a_m_0=0.0, I_0=7000.0, I_a_0=0.70, TFPI_0=2.5, X_a__TFPI_0=0.0, ATIII_0=3400;
double c2_0 = 0, c3_0 = 0, c4_0 = 0, c5_0 = 0, c6_0 = 0, c7_0 = 0, c8_0 = 0, c9_0 = 0, c10_0 = 0, l_0 = 0;

double k_T7_pl=0.0032, k_T7_min=0.0031, k_T7a_pl=0.023, k_T7a_min=0.0031, k_TF7=0.00044, k_10_7=0.013, k_2_7=0.000023, h_7_TP=0.05, h_7_AT=0.00000045;
double k_9=0.26, K_9M=243.0, k_9_pl=0.01, k_9_min=0.0257, h_9=0.0002223, N_9=250, N_9a=550, k_TEN_pl=0.01, k_TEN_min=0.0050, k_7_10=1.15, K_7_10M=450.0;
double k_10_pl=0.029, k_10_min=3.3, N_10=25000, h_10_TP_pl=4.381, h_10_TP_min=0.00000005293, h_10_AT=0.00000305, k_10=8.33, K_10M=63.0;
double k_PRO_pl=0.4, k_PRO_min=0.2, k_2t=0.0000075, k_2_pl=0.01, k_2_min=5.9, N_2=30000, N_2a=1000, h_2=0.000179, k_2=22.4, K_2M=1060.0, k_pp=0.3;
double k_p2=0.37, k_8=0.9, K_8M=147.0, k_8_pl=0.0043, k_8_min=0.00246, N_8=750, h_8=0.0037, k_8_m=0.9, K_8M_m=200, k_8t_m=0.023, K_8tM_m=20.0;
double k_5=0.233, K_5M=71.7, k_5_pl=0.057, k_5_min=0.17, N_5=2700, h_5=0.0028, k_5_m=0.23, K_5M_m=71.7, k_5t_m=0.046, K_5tM_m=10.4, k_f=59.0, K_fM=3160.0;
double K_M14 = 1400;
double k_p = 0.00066, k_vol = 10000, k_lat = 0.0004, betta = 0.66, eps = 0.0000000001, c10_ = 120;

double h, T=800;
int N = 32000;

double f_c10(double c10)
{
	double f_c_10;
	
	if(c10>c10_)
		f_c_10 = 2*(c10/c10_ - 1)/(2*(c10/c10_ - 1) + eps);
	
	else
		f_c_10 = 0;
	
	return f_c_10;
}

double f_c10_(double c10)
{
	double f_c_10_;
	
	if(c10>c10_)
		f_c_10_ = 2*eps/c10_/(2/c10_ - 2 + eps)/(2/c10_ - 2 + eps);
	
	else
		f_c_10_ = 0;
	
	return f_c_10_;
}

double J_0_0(double y[44])            //������� ������ �������� ������� J
{
	return -k_T7_pl*y[1] - k_T7a_pl*y[3];
}

double J_0_1(double y[44])            //������� ������ �������� ������� J
{
	return -k_T7_pl*y[0];
}

double J_0_2(double y[44])            //������� ������ �������� ������� J
{
	return k_T7_min;
}

double J_0_3(double y[44])            //������� ������ �������� ������� J
{
	return -k_T7a_pl*y[0];
}

double J_0_4(double y[44])            //������� ������ �������� ������� J
{
	return k_T7a_min;
}

double J_1_0(double y[44])            //������� ������ �������� ������� J
{
	return -k_T7_pl*y[1];
}

double J_1_1(double y[44])            //������� ������ �������� ������� J
{
	return -k_T7_pl*y[0] - k_TF7*y[4] - k_10_7*y[10] - k_2_7*y[14];
}

double J_1_2(double y[44])            //������� ������ �������� ������� J
{
	return k_T7_min;
}

double J_1_4(double y[44])            //������� ������ �������� ������� J
{
	return -k_TF7*y[1];
}

double J_1_10(double y[44])            //������� ������ �������� ������� J
{
	return -k_10_7*y[1];
}

double J_1_14(double y[44])            //������� ������ �������� ������� J
{
	return -k_2_7*y[1];
}

double J_2_0(double y[44])            //������� ������ �������� ������� J
{
	return k_T7_pl*y[1];
}

double J_2_1(double y[44])            //������� ������ �������� ������� J
{
	return k_T7_pl*y[0];
}

double J_2_2(double y[44])            //������� ������ �������� ������� J
{
	return -k_T7_min;
}

double J_3_0(double y[44])            //������� ������ �������� ������� J
{
	return -k_T7a_pl*y[3];
}

double J_3_1(double y[44])            //������� ������ �������� ������� J
{
	return k_TF7*y[4] + k_10_7*y[10] + k_2_7*y[14];
}

double J_3_3(double y[44])            //������� ������ �������� ������� J
{
	return -k_T7a_pl*y[0];
}

double J_3_4(double y[44])            //������� ������ �������� ������� J
{
	return k_T7a_min + k_TF7*y[1];
}

double J_3_10(double y[44])            //������� ������ �������� ������� J
{
	return k_10_7*y[1];
}

double J_3_14(double y[44])            //������� ������ �������� ������� J
{
	return k_2_7*y[1];
}

double J_4_0(double y[44])            //������� ������ �������� ������� J
{
	return k_T7a_pl*y[3];
}

double J_4_3(double y[44])            //������� ������ �������� ������� J
{
	return k_T7a_pl*y[0];
}

double J_4_4(double y[44])            //������� ������ �������� ������� J
{
	return -k_T7a_min - h_7_TP*y[32] - h_7_AT*y[33];
}

double J_4_32(double y[44])            //������� ������ �������� ������� J
{
	return -h_7_TP*y[4];
}

double J_4_33(double y[44])            //������� ������ �������� ������� J
{
	return -h_7_AT*y[4];
}

double J_5_4(double y[44])            //������� ������ �������� ������� J
{
	return -k_9*y[5]/(K_9M + y[5]);
}

double J_5_5(double y[44])            //������� ������ �������� ������� J
{
	return -k_9*K_9M*y[4]/(K_9M + y[5])/(K_9M + y[5]) - k_9_pl*N_9*y[18];
}

double J_5_7(double y[44])            //������� ������ �������� ������� J
{
	return k_9_min;
}

double J_5_18(double y[44])            //������� ������ �������� ������� J
{
	return -k_9_pl*N_9*y[5];
}

double J_6_4(double y[44])            //������� ������ �������� ������� J
{
	return k_9*y[5]/(K_9M + y[5]);
}

double J_6_5(double y[44])            //������� ������ �������� ������� J
{
	return k_9*K_9M*y[4]/(K_9M + y[5])/(K_9M + y[5]);
}

double J_6_6(double y[44])            //������� ������ �������� ������� J
{
	return -k_9_pl*N_9a*y[18] - h_9*y[33];
}

double J_6_8(double y[44])            //������� ������ �������� ������� J
{
	return k_9_min;
}

double J_6_18(double y[44])            //������� ������ �������� ������� J
{
	return -k_9_pl*N_9a*y[6];
}

double J_6_33(double y[44])            //������� ������ �������� ������� J
{
	return -h_9*y[6];
}

double J_7_5(double y[44])            //������� ������ �������� ������� J
{
	return k_9_pl*N_9*y[18];
}

double J_7_7(double y[44])            //������� ������ �������� ������� J
{
	return -k_9_min;
}

double J_7_18(double y[44])            //������� ������ �������� ������� J
{
	return k_9_pl*N_9*y[5];
}

double J_8_6(double y[44])            //������� ������ �������� ������� J
{
	return k_9_pl*N_9a*y[18];
}

double J_8_8(double y[44])            //������� ������ �������� ������� J
{
	return -k_TEN_pl*y[22] - k_9_min;
}

double J_8_18(double y[44])            //������� ������ �������� ������� J
{
	return k_9_pl*N_9a*y[6];
}

double J_8_22(double y[44])            //������� ������ �������� ������� J
{
	return -k_TEN_pl*y[8];
}

double J_8_23(double y[44])            //������� ������ �������� ������� J
{
	return k_TEN_min;
}

double J_9_4(double y[44])            //������� ������ �������� ������� J
{
	return -k_7_10*y[9]/(K_7_10M + y[9]);
}

double J_9_9(double y[44])            //������� ������ �������� ������� J
{
	return -k_7_10*K_7_10M*y[4]/(K_7_10M + y[9])/(K_7_10M + y[9]) - k_10_pl*N_10*y[18];
}

double J_9_11(double y[44])            //������� ������ �������� ������� J
{
	return k_10_min;
}

double J_9_18(double y[44])            //������� ������ �������� ������� J
{
	return -k_10_pl*N_10*y[9];
}

double J_10_4(double y[44])            //������� ������ �������� ������� J
{
	return k_7_10*y[9]/(K_7_10M + y[9]);
}

double J_10_9(double y[44])            //������� ������ �������� ������� J
{
	return k_7_10*K_7_10M*y[4]/(K_7_10M + y[9])/(K_7_10M + y[9]);
}

double J_10_10(double y[44])            //������� ������ �������� ������� J
{
	return -h_10_TP_pl*y[31] - h_10_AT*y[33] - k_10_pl*N_10*y[18];
}

double J_10_12(double y[44])            //������� ������ �������� ������� J
{
	return k_10_min;
}

double J_10_18(double y[44])            //������� ������ �������� ������� J
{
	return -k_10_pl*N_10*y[10];
}

double J_10_31(double y[44])            //������� ������ �������� ������� J
{
	return -h_10_TP_pl*y[10];
}

double J_10_32(double y[44])            //������� ������ �������� ������� J
{
	return h_10_TP_min;
}

double J_10_33(double y[44])            //������� ������ �������� ������� J
{
	return -h_10_AT*y[10];
}

double J_11_9(double y[44])            //������� ������ �������� ������� J
{
	return k_10_pl*N_10*y[18];
}

double J_11_11(double y[44])            //������� ������ �������� ������� J
{
	return -k_10*K_10M*y[23]/(K_10M + y[11])/(K_10M + y[11]) - k_10_min;
}

double J_11_18(double y[44])            //������� ������ �������� ������� J
{
	return k_10_pl*N_10*y[9];
}

double J_11_23(double y[44])            //������� ������ �������� ������� J
{
	return -k_10*y[11]/(K_10M + y[11]);
}

double J_12_10(double y[44])            //������� ������ �������� ������� J
{
	return k_10_pl*N_10*y[18];
}

double J_12_11(double y[44])            //������� ������ �������� ������� J
{
	return k_10*K_10M*y[23]/(K_10M + y[11])/(K_10M + y[11]);
}

double J_12_12(double y[44])            //������� ������ �������� ������� J
{
	return -k_PRO_pl*y[27] - k_10_min;
}

double J_12_18(double y[44])            //������� ������ �������� ������� J
{
	return k_10_pl*N_10*y[10];
}

double J_12_23(double y[44])            //������� ������ �������� ������� J
{
	return k_10*y[11]/(K_10M + y[11]);
}

double J_12_27(double y[44])            //������� ������ �������� ������� J
{
	return -k_PRO_pl*y[12];
}

double J_12_28(double y[44])            //������� ������ �������� ������� J
{
	return k_PRO_min;
}

double J_13_10(double y[44])            //������� ������ �������� ������� J
{
	return -k_2t*y[13];
}

double J_13_13(double y[44])            //������� ������ �������� ������� J
{
	return -k_2t*y[10] - k_2_pl*N_2*y[18];
}

double J_13_15(double y[44])            //������� ������ �������� ������� J
{
	return k_2_min;
}

double J_13_18(double y[44])            //������� ������ �������� ������� J
{
	return -k_2_pl*N_2*y[13];
}

double J_14_10(double y[44])            //������� ������ �������� ������� J
{
	return k_2t*y[13];
}

double J_14_13(double y[44])            //������� ������ �������� ������� J
{
	return k_2t*y[10];
}

double J_14_14(double y[44])            //������� ������ �������� ������� J
{
	return -k_2_pl*N_2a*y[18] - h_2*y[33];
}

double J_14_16(double y[44])            //������� ������ �������� ������� J
{
	return k_2_min;
}

double J_14_18(double y[44])            //������� ������ �������� ������� J
{
	return -k_2_pl*N_2a*y[14];
}

double J_14_33(double y[44])            //������� ������ �������� ������� J
{
	return -h_2*y[14];
}

double J_15_13(double y[44])            //������� ������ �������� ������� J
{
	return k_2_pl*N_2*y[18];
}

double J_15_15(double y[44])            //������� ������ �������� ������� J
{
	return -k_2*K_2M*y[28]/(K_2M + y[15])/(K_2M + y[15]) - k_2_min;
}

double J_15_18(double y[44])            //������� ������ �������� ������� J
{
	return k_2_pl*N_2*y[13];
}

double J_15_28(double y[44])            //������� ������ �������� ������� J
{
	return -k_2*y[15]/(K_2M + y[15]);
}

double J_16_14(double y[44])            //������� ������ �������� ������� J
{
	return k_2_pl*N_2a*y[18];
}

double J_16_15(double y[44])            //������� ������ �������� ������� J
{
	return k_2*K_2M*y[28]/(K_2M + y[15])/(K_2M + y[15]);
}

double J_16_16(double y[44])            //������� ������ �������� ������� J
{
	return -k_2_min;
}

double J_16_18(double y[44])            //������� ������ �������� ������� J
{
	return k_2_pl*N_2a*y[14];
}

double J_16_28(double y[44])            //������� ������ �������� ������� J
{
	return k_2*y[15]/(K_2M + y[15]);
}

double J_17_14(double y[44])            //������� ������ �������� ������� J
{
	return -k_p2*K_M14*y[17]/(K_M14 + y[14])/(K_M14 + y[14]);
}

double J_17_17(double y[44])            //������� ������ �������� ������� J
{
	return -k_pp*y[18] - k_p2*y[14]/(K_M14 + y[14]);
}

double J_17_18(double y[44])            //������� ������ �������� ������� J
{
	return -k_pp*y[17];
}

double J_18_14(double y[44])            //������� ������ �������� ������� J
{
	return k_p2*K_M14*y[17]/(K_M14 + y[14])/(K_M14 + y[14]);
}

double J_18_17(double y[44])            //������� ������ �������� ������� J
{
	return k_pp*y[18] + k_p2*y[14]/(K_M14 + y[14]);
}

double J_18_18(double y[44])            //������� ������ �������� ������� J
{
	return k_pp*y[17];
}

double J_19_14(double y[44])            //������� ������ �������� ������� J
{
	return -k_8*y[19]/(K_8M + y[19]);
}

double J_19_18(double y[44])            //������� ������ �������� ������� J
{
	return -k_8_pl*N_8*y[19];
}

double J_19_19(double y[44])            //������� ������ �������� ������� J
{
	return -k_8*K_8M*y[14]/(K_8M + y[19])/(K_8M + y[19]) - k_8_pl*N_8*y[18];
}

double J_19_21(double y[44])            //������� ������ �������� ������� J
{
	return k_8_min;
}

double J_20_14(double y[44])            //������� ������ �������� ������� J
{
	return k_8*y[19]/(K_8M + y[19]);
}

double J_20_18(double y[44])            //������� ������ �������� ������� J
{
	return -k_8*N_8*y[20];
}

double J_20_19(double y[44])            //������� ������ �������� ������� J
{
	return k_8*K_8M*y[14]/(K_8M + y[19])/(K_8M + y[19]);
}

double J_20_20(double y[44])            //������� ������ �������� ������� J
{
	return -k_8_pl*N_8*y[18] - h_8;
}

double J_20_22(double y[44])            //������� ������ �������� ������� J
{
	return k_8_min;
}

double J_21_12(double y[44])            //������� ������ �������� ������� J
{
	return -k_8t_m*y[21]/(K_8tM_m + y[21]);
}

double J_21_16(double y[44])            //������� ������ �������� ������� J
{
	return -k_8_m*y[21]/(K_8M_m + y[21]);
}

double J_21_18(double y[44])            //������� ������ �������� ������� J
{
	return k_8_pl*N_8*y[19];
}

double J_21_19(double y[44])            //������� ������ �������� ������� J
{
	return k_8_pl*N_8*y[18];
}

double J_21_21(double y[44])            //������� ������ �������� ������� J
{
	return -k_8_m*K_8M_m*y[16]/(K_8M_m + y[21])/(K_8M_m + y[21]) - k_8t_m*K_8tM_m*y[12]/(K_8tM_m + y[21])/(K_8tM_m + y[21]) - k_8_min;
}

double J_22_8(double y[44])            //������� ������ �������� ������� J
{
	return -k_TEN_pl*y[22];
}

double J_22_12(double y[44])            //������� ������ �������� ������� J
{
	return k_8t_m*y[21]/(K_8tM_m + y[21]);
}

double J_22_16(double y[44])            //������� ������ �������� ������� J
{
	return k_8_m*y[21]/(K_8M_m + y[21]);
}

double J_22_18(double y[44])            //������� ������ �������� ������� J
{
	return k_8_pl*N_8*y[20];
}

double J_22_20(double y[44])            //������� ������ �������� ������� J
{
	return k_8_pl*N_8*y[18];
}

double J_22_21(double y[44])            //������� ������ �������� ������� J
{
	return k_8_m*K_8M_m*y[16]/(K_8M_m + y[21])/(K_8M_m + y[21]) + k_8t_m*K_8tM_m*y[12]/(K_8tM_m + y[21])/(K_8tM_m + y[21]);
}

double J_22_22(double y[44])            //������� ������ �������� ������� J
{
	return -k_8_min - k_TEN_pl*y[8];
}

double J_22_23(double y[44])            //������� ������ �������� ������� J
{
	return k_TEN_min;
}

double J_23_8(double y[44])            //������� ������ �������� ������� J
{
	return k_TEN_pl*y[22];
}

double J_23_22(double y[44])            //������� ������ �������� ������� J
{
	return k_TEN_pl*y[8];
}

double J_23_23(double y[44])            //������� ������ �������� ������� J
{
	return -k_TEN_min;
}

double J_24_14(double y[44])            //������� ������ �������� ������� J
{
	return -k_5*y[24]/(K_5M + y[24]);
}

double J_24_18(double y[44])            //������� ������ �������� ������� J
{
	return -k_5_pl*N_5*y[24];
}

double J_24_24(double y[44])            //������� ������ �������� ������� J
{
	return -k_5*K_5M*y[14]/(K_5M + y[24])/(K_5M + y[24]) - k_5_pl*N_5*y[18];
}

double J_24_26(double y[44])            //������� ������ �������� ������� J
{
	return k_5_min;
}

double J_25_14(double y[44])            //������� ������ �������� ������� J
{
	return k_5*y[24]/(K_5M + y[24]);
}

double J_25_18(double y[44])            //������� ������ �������� ������� J
{
	return -k_5_pl*N_5*y[25];
}

double J_25_24(double y[44])            //������� ������ �������� ������� J
{
	return k_5*K_5M*y[14]/(K_5M + y[24])/(K_5M + y[24]);
}

double J_25_25(double y[44])            //������� ������ �������� ������� J
{
	return -k_5_pl*N_5*y[18] - h_5;
}

double J_25_27(double y[44])            //������� ������ �������� ������� J
{
	return k_5_min;
}

double J_26_12(double y[44])            //������� ������ �������� ������� J
{
	return -k_5t_m*y[26]/(K_5tM_m + y[26]);
}

double J_26_16(double y[44])            //������� ������ �������� ������� J
{
	return -k_5_m*y[26]/(K_5M_m + y[26]);
}

double J_26_18(double y[44])            //������� ������ �������� ������� J
{
	return k_5_pl*N_5*y[24];
}

double J_26_24(double y[44])            //������� ������ �������� ������� J
{
	return k_5_pl*N_5*y[18];
}

double J_26_26(double y[44])            //������� ������ �������� ������� J
{
	return -k_5_m*K_5M_m*y[16]/(K_5M_m + y[26])/(K_5M_m + y[26]) - k_5t_m*K_5tM_m*y[12]/(K_5tM_m + y[26])/(K_5tM_m + y[26]) - k_5_min;
}

double J_27_12(double y[44])            //������� ������ �������� ������� J
{
	return k_5t_m*y[26]/(K_5tM_m + y[26]) - k_PRO_pl*y[27];
}

double J_27_16(double y[44])            //������� ������ �������� ������� J
{
	return k_5_m*y[26]/(K_5M_m + y[26]);
}

double J_27_18(double y[44])            //������� ������ �������� ������� J
{
	return k_5_pl*N_5*y[25];
}

double J_27_25(double y[44])            //������� ������ �������� ������� J
{
	return k_5_pl*N_5*y[18];
}

double J_27_26(double y[44])            //������� ������ �������� ������� J
{
	return k_5_m*K_5M_m*y[16]/(K_5M_m + y[26])/(K_5M_m + y[26]) + k_5t_m*K_5tM_m*y[12]/(K_5tM_m + y[26])/(K_5tM_m + y[26]);
}

double J_27_27(double y[44])            //������� ������ �������� ������� J
{
	return -k_PRO_pl*y[12] - k_5_min;
}

double J_27_28(double y[44])            //������� ������ �������� ������� J
{
	return k_PRO_min;
}

double J_28_12(double y[44])            //������� ������ �������� ������� J
{
	return k_PRO_pl*y[27];
}

double J_28_27(double y[44])            //������� ������ �������� ������� J
{
	return k_PRO_pl*y[12];
}

double J_28_28(double y[44])            //������� ������ �������� ������� J
{
	return -k_PRO_pl;
}

double J_29_14(double y[44])            //������� ������ �������� ������� J
{
	return -k_f*y[29]/(K_fM + y[29]);
}

double J_29_29(double y[44])            //������� ������ �������� ������� J
{
	return -k_f*K_fM*y[14]/(K_fM + y[29])/(K_fM + y[29]);
}

double J_30_14(double y[44])            //������� ������ �������� ������� J
{
	return k_f*y[29]/(K_fM + y[29]);
}

double J_30_29(double y[44])            //������� ������ �������� ������� J
{
	return k_f*K_fM*y[14]/(K_fM + y[29])/(K_fM + y[29]);
}

double J_30_30(double y[44])            //������� ������ �������� ������� J
{
	return -k_p*(4*y[30] + y[34] + y[35] + y[36] + y[37] + y[38] + y[39] + y[40] + y[41]);
}

double J_30_34(double y[44])            //������� ������ �������� ������� J
{
	return -k_p*y[30];
}

double J_30_35(double y[44])            //������� ������ �������� ������� J
{
	return -k_p*y[30];
}

double J_30_36(double y[44])            //������� ������ �������� ������� J
{
	return -k_p*y[30];
}

double J_30_37(double y[44])            //������� ������ �������� ������� J
{
	return -k_p*y[30];
}

double J_30_38(double y[44])            //������� ������ �������� ������� J
{
	return -k_p*y[30];
}

double J_30_39(double y[44])            //������� ������ �������� ������� J
{
	return -k_p*y[30];
}

double J_30_40(double y[44])            //������� ������ �������� ������� J
{
	return -k_p*y[30];
}

double J_30_41(double y[44])            //������� ������ �������� ������� J
{
	return -k_p*y[30];
}

double J_31_10(double y[44])            //������� ������ �������� ������� J
{
	return -h_10_TP_pl*y[31];
}

double J_31_31(double y[44])            //������� ������ �������� ������� J
{
	return -h_10_TP_pl*y[10];
}

double J_31_32(double y[44])            //������� ������ �������� ������� J
{
	return h_10_TP_min;
}

double J_32_4(double y[44])            //������� ������ �������� ������� J
{
	return -h_7_TP*y[32];
}

double J_32_10(double y[44])            //������� ������ �������� ������� J
{
	return h_10_TP_pl*y[31];
}

double J_32_31(double y[44])            //������� ������ �������� ������� J
{
	return h_10_TP_pl*y[10];
}

double J_32_32(double y[44])            //������� ������ �������� ������� J
{
	return -h_10_TP_min - h_7_TP*y[4];
}

double J_33_4(double y[44])            //������� ������ �������� ������� J
{
	return -h_7_AT*y[33];
}

double J_33_6(double y[44])            //������� ������ �������� ������� J
{
	return -h_9*y[33];
}

double J_33_10(double y[44])            //������� ������ �������� ������� J
{
	return -h_10_AT*y[33];
}

double J_33_14(double y[44])            //������� ������ �������� ������� J
{
	return -h_2*y[33];
}

double J_33_33(double y[44])            //������� ������ �������� ������� J
{
	return -h_10_AT*y[10] - h_9*y[6] - h_2*y[14] - h_7_AT*y[4];
}

double J_34_30(double y[44])            //������� ������ �������� ������� J
{
	return k_p*(2*y[30] - y[34]);
}

double J_34_34(double y[44])            //������� ������ �������� ������� J
{
	return -k_p*(y[30] + 4*y[34]);
}

double J_35_30(double y[44])            //������� ������ �������� ������� J
{
	return k_p*(y[34] - y[35]);
}

double J_35_34(double y[44])            //������� ������ �������� ������� J
{
	return k_p*y[30];
}

double J_35_35(double y[44])            //������� ������ �������� ������� J
{
	return -k_p*y[30];
}

double J_36_30(double y[44])            //������� ������ �������� ������� J
{
	return k_p*(y[35] - y[36]);
}

double J_36_34(double y[44])            //������� ������ �������� ������� J
{
	return 2*k_p*y[34];
}

double J_36_35(double y[44])            //������� ������ �������� ������� J
{
	return k_p*y[30];
}

double J_36_36(double y[44])            //������� ������ �������� ������� J
{
	return -k_p*y[30];
}

double J_37_30(double y[44])            //������� ������ �������� ������� J
{
	return k_p*(y[36] - y[37]);
}

double J_37_36(double y[44])            //������� ������ �������� ������� J
{
	return k_p*y[30];
}

double J_37_37(double y[44])            //������� ������ �������� ������� J
{
	return -k_p*y[30];
}

double J_38_30(double y[44])            //������� ������ �������� ������� J
{
	return k_p*(y[37] - y[38]);
}

double J_38_37(double y[44])            //������� ������ �������� ������� J
{
	return k_p*y[30];
}

double J_38_38(double y[44])            //������� ������ �������� ������� J
{
	return -k_p*y[30];
}

double J_39_30(double y[44])            //������� ������ �������� ������� J
{
	return k_p*(y[38] - y[39]);
}

double J_39_38(double y[44])            //������� ������ �������� ������� J
{
	return k_p*y[30];
}

double J_39_39(double y[44])            //������� ������ �������� ������� J
{
	return -k_p*y[30];
}

double J_40_30(double y[44])            //������� ������ �������� ������� J
{
	return k_p*(y[39] - y[40]);
}

double J_40_39(double y[44])            //������� ������ �������� ������� J
{
	return k_p*y[30];
}

double J_40_40(double y[44])            //������� ������ �������� ������� J
{
	return -k_p*y[30];
}

double J_41_30(double y[44])            //������� ������ �������� ������� J
{
	return k_p*(y[40] - y[41]);
}

double J_41_40(double y[44])            //������� ������ �������� ������� J
{
	return k_p*y[30];
}

double J_41_41(double y[44])            //������� ������ �������� ������� J
{
	return -k_p*y[30];
}

double J_42_30(double y[44])            //������� ������ �������� ������� J
{
	return k_p*y[41];
}

double J_42_41(double y[44])            //������� ������ �������� ������� J
{
	return k_p*y[30];
}

double J_42_42(double y[44])            //������� ������ �������� ������� J
{
	return -k_vol*(f_c10(y[42]) + y[42]*f_c10_(y[42])) - k_lat*(4*y[42] + y[43]);
}

double J_42_43(double y[44])            //������� ������ �������� ������� J
{
	return -k_lat*y[42];
}

double J_43_42(double y[44])            //������� ������ �������� ������� J
{
	return betta*(2*k_lat*y[42] + k_vol*(f_c10(y[42]) + y[42]*f_c10_(y[42])) + k_lat*y[43]);
}

double J_43_43(double y[44])            //������� ������ �������� ������� J
{
	return betta*k_lat*y[42];
}

double f0(double y[44])               //������� ������ ����� ���������
{
	return -k_T7_pl*y[0]*y[1] + k_T7_min*y[2] - k_T7a_pl*y[0]*y[3] + k_T7a_min*y[4];
}

double f1(double y[44])               //������� ������ ����� ���������
{
	return -k_T7_pl*y[0]*y[1] + k_T7_min*y[2] - k_TF7*y[4]*y[1] - k_10_7*y[10]*y[1] - k_2_7*y[14]*y[1];
}

double f2(double y[44])               //������� ������ ����� ���������
{
	return k_T7_pl*y[0]*y[1] - k_T7_min*y[2];
}

double f3(double y[44])               //������� ������ ����� ���������
{
	return -k_T7a_pl*y[0]*y[3] + k_T7a_min*y[4] + k_TF7*y[4]*y[1] + k_10_7*y[10]*y[1] + k_2_7*y[14]*y[1];
}

double f4(double y[44])               //������� ������ ����� ���������
{
	return k_T7a_pl*y[0]*y[3] - k_T7a_min*y[4] - h_7_TP*y[32]*y[4] - h_7_AT*y[33]*y[4];
}

double f5(double y[44])               //������� ������ ����� ���������
{
	return -k_9*y[4]*y[5]/(K_9M + y[5]) - k_9_pl*N_9*y[18]*y[5] + k_9_min*y[7];
}

double f6(double y[44])               //������� ������ ����� ���������
{
	return k_9*y[4]*y[5]/(K_9M + y[5]) - k_9_pl*N_9a*y[18]*y[6] + k_9_min*y[8] - h_9*y[6]*y[33];
}

double f7(double y[44])               //������� ������ ����� ���������
{
	return k_9_pl*N_9*y[18]*y[5] - k_9_min*y[7];
}

double f8(double y[44])               //������� ������ ����� ���������
{
	return -k_TEN_pl*y[22]*y[8] + k_TEN_min*y[23] + k_9_pl*N_9a*y[18]*y[6] - k_9_min*y[8];
}

double f9(double y[44])               //������� ������ ����� ���������
{
	return -k_7_10*y[4]*y[9]/(K_7_10M + y[9]) - k_10_pl*N_10*y[18]*y[9] + k_10_min*y[11];
}

double f10(double y[44])               //������� ������ ����� ���������
{
	return k_7_10*y[4]*y[9]/(K_7_10M + y[9]) - h_10_TP_pl*y[31]*y[10] + h_10_TP_min*y[32] - h_10_AT*y[33]*y[10] - k_10_pl*N_10*y[18]*y[10] + k_10_min*y[12];
}

double f11(double y[44])               //������� ������ ����� ���������
{
	return -k_10*y[23]*y[11]/(K_10M + y[11]) + k_10_pl*N_10*y[18]*y[9] - k_10_min*y[11];
}

double f12(double y[44])               //������� ������ ����� ���������
{
	return k_10*y[23]*y[11]/(K_10M + y[11]) - k_PRO_pl*y[27]*y[12] + k_PRO_min*y[28] + k_10_pl*N_10*y[18]*y[10] - k_10_min*y[12];
}

double f13(double y[44])               //������� ������ ����� ���������
{
	return -k_2t*y[10]*y[13] - k_2_pl*N_2*y[18]*y[13] + k_2_min*y[15];
}

double f14(double y[44])               //������� ������ ����� ���������
{
	return k_2t*y[10]*y[13] - k_2_pl*N_2a*y[18]*y[14] + k_2_min*y[16] - h_2*y[33]*y[14];
}

double f15(double y[44])               //������� ������ ����� ���������
{
	return -k_2*y[28]*y[15]/(K_2M + y[15]) + k_2_pl*N_2*y[18]*y[13] - k_2_min*y[15];
}

double f16(double y[44])               //������� ������ ����� ���������
{
	return k_2*y[28]*y[15]/(K_2M + y[15]) + k_2_pl*N_2a*y[18]*y[14] - k_2_min*y[16];
}

double f17(double y[44])               //������� ������ ����� ���������
{
	return -k_pp*y[17]*y[18] - k_p2*y[17]*y[14]/(K_M14 + y[14]);
}

double f18(double y[44])               //������� ������ ����� ���������
{
	return k_pp*y[17]*y[18] + k_p2*y[17]*y[14]/(K_M14 + y[14]);
}

double f19(double y[44])               //������� ������ ����� ���������
{
	return -k_8*y[14]*y[19]/(K_8M + y[19]) - k_8_pl*N_8*y[18]*y[19] + k_8_min*y[21];
}

double f20(double y[44])               //������� ������ ����� ���������
{
	return k_8*y[14]*y[19]/(K_8M + y[19]) - k_8_pl*N_8*y[18]*y[20] + k_8_min*y[22] - h_8*y[20];
}

double f21(double y[44])               //������� ������ ����� ���������
{
	return -k_8_m*y[16]*y[21]/(K_8M_m + y[21]) - k_8t_m*y[12]*y[21]/(K_8tM_m + y[21]) + k_8_pl*N_8*y[18]*y[19] - k_8_min*y[21];
}

double f22(double y[44])               //������� ������ ����� ���������
{
	return k_8_m*y[16]*y[21]/(K_8M_m + y[21]) + k_8t_m*y[12]*y[21]/(K_8tM_m + y[21]) + k_8_pl*N_8*y[18]*y[20] - k_8_min*y[22] - k_TEN_pl*y[22]*y[8] + k_TEN_min*y[23];
}

double f23(double y[44])               //������� ������ ����� ���������
{
	return k_TEN_pl*y[22]*y[8] - k_TEN_min*y[23];
}

double f24(double y[44])               //������� ������ ����� ���������
{
	return -k_5*y[14]*y[24]/(K_5M + y[24]) - k_5_pl*N_5*y[18]*y[24] + k_5_min*y[26];
}

double f25(double y[44])               //������� ������ ����� ���������
{
	return k_5*y[14]*y[24]/(K_5M + y[24]) - k_5_pl*N_5*y[18]*y[25] + k_5_min*y[27] - h_5*y[25];
}

double f26(double y[44])               //������� ������ ����� ���������
{
	return -k_5_m*y[16]*y[26]/(K_5M_m + y[26]) - k_5t_m*y[12]*y[26]/(K_5tM_m + y[26]) + k_5_pl*N_5*y[18]*y[24] - k_5_min*y[26];
}

double f27(double y[44])               //������� ������ ����� ���������
{
	return k_5_m*y[16]*y[26]/(K_5M_m + y[26]) + k_5t_m*y[12]*y[26]/(K_5tM_m + y[26]) - k_PRO_pl*y[12]*y[27] + k_PRO_min*y[28] + k_5_pl*N_5*y[18]*y[25] - k_5_min*y[27];
}

double f28(double y[44])               //������� ������ ����� ���������
{
	return k_PRO_pl*y[12]*y[27] - k_PRO_min*y[28];
}

double f29(double y[44])               //������� ������ ����� ���������
{
	return -k_f*y[14]*y[29]/(K_fM + y[29]);
}

double f30(double y[44])               //������� ������ ����� ���������
{
	return k_f*y[14]*y[29]/(K_fM + y[29]) - k_p*y[30]*(2*y[30] + y[34] + y[35] + y[36] + y[37] + y[38] + y[39] + y[40] + y[41]);
}

double f31(double y[44])               //������� ������ ����� ���������
{
	return -h_10_TP_pl*y[10]*y[31] + h_10_TP_min*y[32];
}

double f32(double y[44])               //������� ������ ����� ���������
{
	return h_10_TP_pl*y[10]*y[31] - h_10_TP_min*y[32] - h_7_TP*y[4]*y[32];
}

double f33(double y[44])               //������� ������ ����� ���������
{
	return -y[33]*(h_10_AT*y[10] + h_9*y[6] + h_2*y[14] + h_7_AT*y[4]);
}

double f34(double y[44])               //������� ������ ����� ���������
{
	return k_p*(y[30]*y[30] - y[30]*y[34] - 2*y[34] *y[34]);
}

double f35(double y[44])               //������� ������ ����� ���������
{
	return k_p*y[30]*(y[34] - y[35]);
}

double f36(double y[44])               //������� ������ ����� ���������
{
	return k_p*(y[35]*y[30] + y[34]*y[34] - y[36]*y[30]);
}

double f37(double y[44])               //������� ������ ����� ���������
{
	return k_p*y[30]*(y[36] - y[37]);
}

double f38(double y[44])               //������� ������ ����� ���������
{
	return k_p*y[30]*(y[37] - y[38]);
}

double f39(double y[44])               //������� ������ ����� ���������
{
	return k_p*y[30]*(y[38] - y[39]);;
}

double f40(double y[44])               //������� ������ ����� ���������
{
	return k_p*y[30]*(y[39] - y[40]);;
}

double f41(double y[44])               //������� ������ ����� ���������
{
	return k_p*y[30]*(y[40] - y[41]);;
}

double f42(double y[44])               //������� ������ ����� ���������
{
	return k_p*y[41]*y[30] - k_vol*y[42]*f_c10(y[42]) - 2*k_lat*y[42]*y[42] - k_lat*y[43]*y[42];
}

double f43(double y[44])               //������� ������ ����� ���������
{
	return betta*(k_lat*y[42]*y[42] + k_vol*y[42]*f_c10(y[42]) + k_lat*y[43]*y[42]);
}

int main(int argc, char *argv[])
{	
	h = T/N;                      //���������� ����� �� �������
	
	double M;
	
	double J[44][44];               //������� ������� ������� 34*34
	double J1[44][44], J2[44][44];    //J1=E-1/2hJ - ������������ �����, J2=-1/2hJ - ������ �����
	double J3[88][88];              //��������������� ������ ��� ������� ������� ��������� � ������������ �������
	
	double f[44], g[88];            //������ ������ ������ � ��������������� ������ � ������
	double u[44], z[88];            //������ ������������ ����� � ���������������
	double y[44];                  //������� ������ �������� �������
	double mn[44];                  //������ ������ ������
	
	for(int j=0; j<44; j++)
		mn[j] = 0;
	
	y[0] = TF_0;                   //��������� �������
	y[1] = VII_0;
	y[2] = TF__VII_0;
	y[3] = VII_a_0;
	y[4] = TF__VII_a_0;
	y[5] = IX_0;
	y[6] = IX_a_0;
	y[7] = IX_m_0;
	y[8] = IX_a_m_0;
	y[9] = X_0;
	y[10] = X_a_0;
	y[11] = X_m_0;
	y[12] = X_a_m_0;
	y[13] = II_0;
	y[14] = II_a_0;
	y[15] = II_m_0;
	y[16] = II_a_m_0;
	y[17] = PL_0;
	y[18] = AP_0;
	y[19] = VIII_0;
	y[20] = VIII_a_0;
	y[21] = VIII_m_0;
	y[22] = VIII_a_m_0;
	y[23] = VIII_a_m__IX_a_m_0;
	y[24] = V_0;
	y[25] = V_a_0;
	y[26] = V_m_0;
	y[27] = V_a_m_0;
	y[28] = X_a_m__V_a_m_0;
	y[29] = I_0;
	y[30] = I_a_0;
	y[31] = TFPI_0;
	y[32] = X_a__TFPI_0;
	y[33] = ATIII_0;
	y[34] = c2_0;
	y[35] = c3_0;
	y[36] = c4_0;
	y[37] = c5_0;
	y[38] = c6_0;
	y[39] = c7_0;
	y[40] = c8_0;
	y[41] = c9_0;
	y[42] = c10_0;
	y[43] = l_0;
	
	FILE *pf_anand, *pf_anand_mn;
	
//	pf_anand = fopen("new1_anand_model1.txt", "w");
//	pf_anand = fopen("new2_anand_model1.txt", "w");
//	pf_anand = fopen("new3_anand_model1.txt", "w");
//	pf_anand = fopen("new4_anand_model1.txt", "w");
//	pf_anand = fopen("new5_anand_model1.txt", "w");
//	pf_anand = fopen("new6_anand_model1.txt", "w");
//	pf_anand = fopen("new7_anand_model1.txt", "w");
//	pf_anand = fopen("new8_anand_model1.txt", "w");
	pf_anand = fopen("new9_anand_model1.txt", "w");
//	pf_anand = fopen("new10_anand_model1.txt", "w");
	pf_anand_mn = fopen("new1_anand_model1_mn.1.1.txt", "w");
	
	double t;
	
	t=0;
	
	for(int i=0; i<44; i++)
		for(int j=0; j<44; j++)
			J[i][j] = 0;			//��������� �������� J, ����� ��� ����, ����� ������ ��� �� ��������� ����
	
	fprintf(pf_anand, "%f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f\n", t, y[0], y[1], y[2], y[3], y[4], y[5], y[6], y[7], y[8], y[9], y[10], y[11], y[12], y[13], y[14], y[15], y[16], y[17], y[18], y[19], y[20], y[21], y[22], y[23], y[24], y[25], y[26], y[27], y[28], y[29], y[30], y[31], y[32], y[33], y[34], y[35], y[36], y[37], y[38], y[39], y[40], y[41], y[42], y[43]);
	fprintf(pf_anand_mn, "%f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f\n", t, mn[0], mn[1], mn[2], mn[3], mn[4], mn[5], mn[6], mn[7], mn[8], mn[9], mn[10], mn[11], mn[12], mn[13], mn[14], mn[15], mn[16], mn[17], mn[18], mn[19], mn[20], mn[21], mn[22], mn[23], mn[24], mn[25], mn[26], mn[27], mn[28], mn[29], mn[30], mn[31], mn[32], mn[33], mn[34], mn[35], mn[36], mn[37], mn[38], mn[39], mn[40], mn[41], mn[42], mn[43]);
	
	for(int i=1; i<=N; i++)
	{
		J[0][0] = J_0_0(y);       //������� �������� �������� J
		J[0][1] = J_0_1(y);
		J[0][2] = J_0_2(y);
		J[0][3] = J_0_3(y);
		J[0][4] = J_0_4(y);
		J[1][0] = J_1_0(y);
		J[1][1] = J_1_1(y);
		J[1][2] = J_1_2(y);
		J[1][4] = J_1_4(y);
		J[1][10] = J_1_10(y);
		J[1][14] = J_1_14(y);
		J[2][0] = J_2_0(y);
		J[2][1] = J_2_1(y);
		J[2][2] = J_2_2(y);
		J[3][0] = J_3_0(y);
		J[3][1] = J_3_1(y);
		J[3][3] = J_3_3(y);
		J[3][4] = J_3_4(y);
		J[3][10] = J_3_10(y);
		J[3][14] = J_3_14(y);
		J[4][0] = J_4_0(y);
		J[4][3] = J_4_3(y);
		J[4][4] = J_4_4(y);
		J[4][32] = J_4_32(y);
		J[4][33] = J_4_33(y);
		J[5][4] = J_5_4(y);
		J[5][5] = J_5_5(y);
		J[5][7] = J_5_7(y);
		J[5][18] = J_5_18(y);
		J[6][4] = J_6_4(y);
		J[6][5] = J_6_5(y);
		J[6][6] = J_6_6(y);
		J[6][8] = J_6_8(y);
		J[6][18] = J_6_18(y);
		J[6][33] = J_6_33(y);
		J[7][5] = J_7_5(y);
		J[7][7] = J_7_7(y);
		J[7][18] = J_7_18(y);
		J[8][6] = J_8_6(y);
		J[8][8] = J_8_8(y);
		J[8][18] = J_8_18(y);
		J[8][22] = J_8_22(y);
		J[8][23] = J_8_23(y);
		J[9][4] = J_9_4(y);
		J[9][9] = J_9_9(y);
		J[9][11] = J_9_11(y);
		J[9][18] = J_9_18(y);
		J[10][4] = J_10_4(y);
		J[10][9] = J_10_9(y);
		J[10][10] = J_10_10(y);
		J[10][12] = J_10_12(y);
		J[10][18] = J_10_18(y);
		J[10][31] = J_10_31(y);
		J[10][32] = J_10_32(y);
		J[10][33] = J_10_33(y);
		J[11][9] = J_11_9(y);
		J[11][11] = J_11_11(y);
		J[11][18] = J_11_18(y);
		J[11][23] = J_11_23(y);
		J[12][10] = J_12_10(y);
		J[12][11] = J_12_11(y);
		J[12][12] = J_12_12(y);
		J[12][18] = J_12_18(y);
		J[12][23] = J_12_23(y);
		J[12][27] = J_12_27(y);
		J[12][28] = J_12_28(y);
		J[13][10] = J_13_10(y);
		J[13][13] = J_13_13(y);
		J[13][15] = J_13_15(y);
		J[13][18] = J_13_18(y);
		J[14][10] = J_14_10(y);
		J[14][13] = J_14_13(y);
		J[14][14] = J_14_14(y);
		J[14][16] = J_14_16(y);
		J[14][18] = J_14_18(y);
		J[14][33] = J_14_33(y);
		J[15][13] = J_15_13(y);
		J[15][15] = J_15_15(y);
		J[15][18] = J_15_18(y);
		J[15][28] = J_15_28(y);
		J[16][14] = J_16_14(y);
		J[16][15] = J_16_15(y);
		J[16][16] = J_16_16(y);
		J[16][18] = J_16_18(y);
		J[16][28] = J_16_28(y);
		J[17][14] = J_17_14(y);
		J[17][17] = J_17_17(y);
		J[17][18] = J_17_18(y);
		J[18][14] = J_18_14(y);
		J[18][17] = J_18_17(y);
		J[18][18] = J_18_18(y);
		J[19][14] = J_19_14(y);
		J[19][18] = J_19_18(y);
		J[19][19] = J_19_19(y);
		J[19][21] = J_19_21(y);
		J[20][14] = J_20_14(y);
		J[20][18] = J_20_18(y);
		J[20][19] = J_20_19(y);
		J[20][20] = J_20_20(y);
		J[20][22] = J_20_22(y);
		J[21][12] = J_21_12(y);
		J[21][16] = J_21_16(y);
		J[21][18] = J_21_18(y);
		J[21][19] = J_21_19(y);
		J[21][21] = J_21_21(y);
		J[22][8] = J_22_8(y);
		J[22][12] = J_22_12(y);
		J[22][16] = J_22_16(y);
		J[22][18] = J_22_18(y);
		J[22][20] = J_22_20(y);
		J[22][21] = J_22_21(y);
		J[22][22] = J_22_22(y);
		J[22][23] = J_22_23(y);
		J[23][8] = J_23_8(y);
		J[23][22] = J_23_22(y);
		J[23][23] = J_23_23(y);
		J[24][14] = J_24_14(y);
		J[24][18] = J_24_18(y);
		J[24][24] = J_24_24(y);
		J[24][26] = J_24_26(y);
		J[25][14] = J_25_14(y);
		J[25][18] = J_25_18(y);
		J[25][24] = J_25_24(y);
		J[25][25] = J_25_25(y);
		J[25][27] = J_25_27(y);
		J[26][12] = J_26_12(y);
		J[26][16] = J_26_16(y);
		J[26][18] = J_26_18(y);
		J[26][24] = J_26_24(y);
		J[26][26] = J_26_26(y);
		J[27][12] = J_27_12(y);
		J[27][16] = J_27_16(y);
		J[27][18] = J_27_18(y);
		J[27][25] = J_27_25(y);
		J[27][26] = J_27_26(y);
		J[27][27] = J_27_27(y);
		J[27][28] = J_27_28(y);
		J[28][12] = J_28_12(y);
		J[28][27] = J_28_27(y);
		J[28][28] = J_28_28(y);
		J[29][14] = J_29_14(y);
		J[29][29] = J_29_29(y);
		J[30][14] = J_30_14(y);
		J[30][29] = J_30_29(y);
		J[30][30] = J_30_30(y);
		J[30][34] = J_30_34(y);
		J[30][35] = J_30_35(y);
		J[30][36] = J_30_36(y);
		J[30][37] = J_30_37(y);
		J[30][38] = J_30_38(y);
		J[30][39] = J_30_39(y);
		J[30][40] = J_30_40(y);
		J[30][41] = J_30_41(y);
		J[31][10] = J_31_10(y);
		J[31][31] = J_31_31(y);
		J[31][32] = J_31_32(y);
		J[32][4] = J_32_4(y);
		J[32][10] = J_32_10(y);
		J[32][31] = J_32_31(y);
		J[32][32] = J_32_32(y);
		J[33][4] = J_33_4(y);
		J[33][6] = J_33_6(y);
		J[33][10] = J_33_10(y);
		J[33][14] = J_33_14(y);
		J[33][33] = J_33_33(y);
		J[34][30] = J_34_30(y);
		J[34][34] = J_34_34(y);
		J[35][30] = J_35_30(y);
		J[35][34] = J_35_34(y);
		J[35][35] = J_35_35(y);
		J[36][30] = J_36_30(y);
		J[36][34] = J_36_34(y);
		J[36][35] = J_36_35(y);
		J[36][36] = J_36_36(y);
		J[37][30] = J_37_30(y);
		J[37][36] = J_37_36(y);
		J[37][37] = J_37_37(y);
		J[38][30] = J_38_30(y);
		J[38][37] = J_38_37(y);
		J[38][38] = J_38_38(y);
		J[39][30] = J_39_30(y);
		J[39][38] = J_39_38(y);
		J[39][39] = J_39_39(y);
		J[40][30] = J_40_30(y);
		J[40][39] = J_40_39(y);
		J[40][40] = J_40_40(y);
		J[41][30] = J_41_30(y);
		J[41][40] = J_41_40(y);
		J[41][41] = J_41_41(y);
		J[42][30] = J_42_30(y);
		J[42][41] = J_42_41(y);
		J[42][42] = J_42_42(y);
		J[42][43] = J_42_43(y);
		J[43][42] = J_43_42(y);
		J[43][43] = J_43_43(y);
		
		for(int j=0; j<44; j++)					  //������� �������� �������� J1
			for(int k=0; k<44; k++)
				J1[j][k] = -J[j][k]*h/2;
		
		for(int j=0; j<44; j++)
			J1[j][j] = 1.0 + J1[j][j];
		
		for(int j=0; j<44; j++)					  //������� �������� �������� J2
			for(int k=0; k<44; k++)
				J2[j][k] = -J[j][k]*h/2;
		
		for(int j=0; j<44; j++)					  //������� �������� �������� J3
			for(int k=0; k<44; k++)
			{
				J3[j][k] = J1[j][k];
				J3[j][k+44] = -J2[j][k];
				J3[j+44][k] = J2[j][k];
				J3[j+44][k+44] = J1[j][k];
			}
		
		g[0] = f0(y);           //������� ��������������� ������� ������ �����
		g[1] = f1(y);
		g[2] = f2(y);
		g[3] = f3(y);
		g[4] = f4(y);
		g[5] = f5(y);
		g[6] = f6(y);
		g[7] = f7(y);
		g[8] = f8(y);
		g[9] = f9(y);
		g[10] = f10(y);
		g[11] = f11(y);
		g[12] = f12(y);
		g[13] = f13(y);
		g[14] = f14(y);
		g[15] = f15(y);
		g[16] = f16(y);
		g[17] = f17(y);
		g[18] = f18(y);
		g[19] = f19(y);
		g[20] = f20(y);
		g[21] = f21(y);
		g[22] = f22(y);
		g[23] = f23(y);
		g[24] = f24(y);
		g[25] = f25(y);
		g[26] = f26(y);
		g[27] = f27(y);
		g[28] = f28(y);
		g[29] = f29(y);
		g[30] = f30(y);
		g[31] = f31(y);
		g[32] = f32(y);
		g[33] = f33(y);
		g[34] = f34(y);
		g[35] = f35(y);
		g[36] = f36(y);
		g[37] = f37(y);
		g[38] = f38(y);
		g[39] = f39(y);
		g[40] = f40(y);
		g[41] = f41(y);
		g[42] = f42(y);
		g[43] = f43(y);
		g[44] = 0.0;
		g[45] = 0.0;
		g[46] = 0.0;
		g[47] = 0.0;
		g[48] = 0.0;
		g[49] = 0.0;
		g[50] = 0.0;
		g[51] = 0.0;
		g[52] = 0.0;
		g[53] = 0.0;
		g[54] = 0.0;
		g[55] = 0.0;
		g[56] = 0.0;
		g[57] = 0.0;
		g[58] = 0.0;
		g[59] = 0.0;
		g[60] = 0.0;
		g[61] = 0.0;
		g[62] = 0.0;
		g[63] = 0.0;
		g[64] = 0.0;
		g[65] = 0.0;
		g[66] = 0.0;
		g[67] = 0.0;
		g[68] = 0.0;
		g[69] = 0.0;
		g[70] = 0.0;
		g[71] = 0.0;
		g[72] = 0.0;
		g[73] = 0.0;
		g[74] = 0.0;
		g[75] = 0.0;
		g[76] = 0.0;
		g[77] = 0.0;
		g[78] = 0.0;
		g[79] = 0.0;
		g[80] = 0.0;
		g[81] = 0.0;
		g[82] = 0.0;
		g[83] = 0.0;
		g[84] = 0.0;
		g[85] = 0.0;
		g[86] = 0.0;
		g[87] = 0.0;
		
		double R, c[88], cc;                 //��������������� ����� ��� ������ ������
		
		for(int k=0; k<88; k++)    //����� ������
		{		
				double max;
				int ind_max;
				
				max = abs(J3[k][k]);
				ind_max = k;
				
				for(int j=k+1; j<88; j++)
				{
					if(abs(J3[j][k]) > max)
					{
						ind_max = j;
					}
				}
				
				for(int j=0; j<88; j++)
				{
					c[j] = J3[k][j];
					J3[k][j] = J3[ind_max][j];
					J3[ind_max][j] = c[j];
				}
				
				cc = g[k];
				g[k] = g[ind_max];
				g[ind_max] = cc;
			
			for(int j=0; j<88; j++)
			{
				if(j != k)
				{ 
					if(J3[j][k] != 0)
					{
					R = J3[k][k]/J3[j][k];
					
						for(int l=0; l<88; l++)
						{
							J3[j][l] = J3[j][l] - J3[k][l]/R;
						}
						
						g[j] = g[j] - g[k]/R;
					}
				}
			}
			
			for(int j=0; j<88; j++)
				if(j != k)
					J3[k][j] = J3[k][j]/J3[k][k];
					
			g[k] = g[k]/J3[k][k];
			
			J3[k][k] = 1;
		}
		
		for(int m=0; m<88; m++)
		{
			z[m] = g[m];
		}
		
		u[0] = z[0];
		u[1] = z[1];
		u[2] = z[2];
		u[3] = z[3];
		u[4] = z[4];
		u[5] = z[5];
		u[6] = z[6];
		u[7] = z[7];
		u[8] = z[8];
		u[9] = z[9];
		u[10] = z[10];
		u[11] = z[11];
		u[12] = z[12];
		u[13] = z[13];
		u[14] = z[14];
		u[15] = z[15];
		u[16] = z[16];
		u[17] = z[17];
		u[18] = z[18];
		u[19] = z[19];
		u[20] = z[20];
		u[21] = z[21];
		u[22] = z[22];
		u[23] = z[23];
		u[24] = z[24];
		u[25] = z[25];
		u[26] = z[26];
		u[27] = z[27];
		u[28] = z[28];
		u[29] = z[29];
		u[30] = z[30];
		u[31] = z[31];
		u[32] = z[32];
		u[33] = z[33];
		u[34] = z[34];
		u[35] = z[35];
		u[36] = z[36];
		u[37] = z[37];
		u[38] = z[38];
		u[39] = z[39];
		u[40] = z[40];
		u[41] = z[41];
		u[42] = z[42];
		u[43] = z[43];

		
		y[0] = y[0] + h*u[0];
		y[1] = y[1] + h*u[1];
		y[2] = y[2] + h*u[2];
		y[3] = y[3] + h*u[3];
		y[4] = y[4] + h*u[4];
		y[5] = y[5] + h*u[5];
		y[6] = y[6] + h*u[6];
		y[7] = y[7] + h*u[7];
		y[8] = y[8] + h*u[8];
		y[9] = y[9] + h*u[9];
		y[10] = y[10] + h*u[10];
		y[11] = y[11] + h*u[11];
		y[12] = y[12] + h*u[12];
		y[13] = y[13] + h*u[13];
		y[14] = y[14] + h*u[14];
		y[15] = y[15] + h*u[15];
		y[16] = y[16] + h*u[16];
		y[17] = y[17] + h*u[17];
		y[18] = y[18] + h*u[18];
		y[19] = y[19] + h*u[19];
		y[20] = y[20] + h*u[20];
		y[21] = y[21] + h*u[21];
		y[22] = y[22] + h*u[22];
		y[23] = y[23] + h*u[23];
		y[24] = y[24] + h*u[24];
		y[25] = y[25] + h*u[25];
		y[26] = y[26] + h*u[26];
		y[27] = y[27] + h*u[27];
		y[28] = y[28] + h*u[28];
		y[29] = y[29] + h*u[29];
		y[30] = y[30] + h*u[30];
		y[31] = y[31] + h*u[31];
		y[32] = y[32] + h*u[32];
		y[33] = y[33] + h*u[33];
		y[34] = y[34] + h*u[34];
		y[35] = y[35] + h*u[35];
		y[36] = y[36] + h*u[36];
		y[37] = y[37] + h*u[37];
		y[38] = y[38] + h*u[38];
		y[39] = y[39] + h*u[39];
		y[40] = y[40] + h*u[40];
		y[41] = y[41] + h*u[41];
		y[42] = y[42] + h*u[42];
		y[43] = y[43] + h*u[43];
		
		t = T/N*i;
		
		for(int j=0; j<44; j++)
			mn[j] = mn[j] + h*z[j+44];
	
		fprintf(pf_anand, "%f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f\n", t, y[0], y[1], y[2], y[3], y[4], y[5], y[6], y[7], y[8], y[9], y[10], y[11], y[12], y[13], y[14], y[15], y[16], y[17], y[18], y[19], y[20], y[21], y[22], y[23], y[24], y[25], y[26], y[27], y[28], y[29], y[30], y[31], y[32], y[33], y[34], y[35], y[36], y[37], y[38], y[39], y[40], y[41], y[42], y[43]);
		fprintf(pf_anand_mn, "%f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f\n", t, mn[0], mn[1], mn[2], mn[3], mn[4], mn[5], mn[6], mn[7], mn[8], mn[9], mn[10], mn[11], mn[12], mn[13], mn[14], mn[15], mn[16], mn[17], mn[18], mn[19], mn[20], mn[21], mn[22], mn[23], mn[24], mn[25], mn[26], mn[27], mn[28], mn[29], mn[30], mn[31], mn[32], mn[33], mn[34], mn[35], mn[36], mn[37], mn[38], mn[39], mn[40], mn[41], mn[42], mn[43]);
	}
	return 0;
}