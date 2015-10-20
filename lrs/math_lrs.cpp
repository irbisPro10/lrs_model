#define _USE_MATH_DEFINES
#include <cmath> 
#include "math_lrs.h"
#define TO_RAD M_PI / 180
inline static double rad(double deg)
{
	return deg / 180 * M_PI;
}
static double l_rmax()
{
	const double c = 3e8; //�������� ����� � �������
	const double k = 1.38e-23;//���������� ���������
	const double T0 = 300;//����������� ��������� ����������
	const double ksh = 1.995;//���������� ��������� ����������
	const double kp = 1;

	const double Pi = 4.558e6;//���������� ���������� ��������
	const double Gp = 2.926e4;//���� �������� ���������� ���
	const double Gpr = 7.803e4;//���� �������� ����������� ���

	const double df = 1.555e5;//������ ������������ ����������
	const double snr = 23.056;

	const double fw = 6e8;//������� ������� ������� (+)

	const double L = c/fw;//����� �����
	const double sigma = 1;//��� ���� (+)
	const int ni = 1;//���������� ������������� ���������� �� ���� ���������(+)

	return std::pow(((Pi*Gp*Gpr*L*L*sigma*ni) / (64 * std::pow(M_PI, 3)*k*T0*df*ksh*snr*kp)),1./4);
}

namespace Lrs {

	double rmax(double alpha,double eps)
	{
		//static const double max = l_rmax(); // it's a trick
		double max = l_rmax(); // 
		return max * std::pow( (std::cos(rad(alpha)) * std::cos(rad(eps))),1./4);
	}

}

/*
int _tmain(int argc, _TCHAR* argv[])
{	
	//���� ����������

	double alpha;
	double eps;


	

	cin >> sigma;
	cin >> ni;
	cin >> alpha;
	cin >> eps;
	L = lv(c, fw);
	//cout << Rmax(pi, Pi, Gp, Gpr, L, sigma, ni, k, T0, df, ksh, snr, kp) << endl;
	for (int i = -45; i < 46; i++)
	{
		alpha = i;
		cout << "alpha=" << alpha << " rmax="<<cos(alpha*grad())*rmax(alpha, eps, Rmax(pi, Pi, Gp, Gpr, L, sigma, ni, k, T0, df, ksh, snr, kp)) << endl;
	}
	return 0;
}

*/