#include "stdafx.h"
#include "DigitalFilter.h"


DigitalFilter::DigitalFilter(const int order, const int NP, double* b, double* a, double* x, double* y, double zi)
{
	this->a = a;
	this->b = b;
	this->a_length = order + 1;
	this->b_length = order + 1;
	this->x = x;
	this->y = y;
	this->zi = zi;
	this->x_length = NP;
	this->y_length = NP;
}


double* DigitalFilter::getY()
{
	calc();
	return y;
}



double* DigitalFilter::getZf()
{
	calc();
	return zf;
}

void DigitalFilter::calc()
{
	for (int i = 0; i < y_length; i++)
	{
		if (i == 0) //��ֵ
		{
			y[i] = b[0] * x[i] + zi;
		}
		else //��y[0]λ�õļ���
		{
			y[i] = b[0] * x[i] + b[1] * x[i - 1] - a[1] * y[i - 1];

			//���������x�����һ������y[i]��ֵ��zf[0]
			if (i == x_length - 1)
			{
				zf[0] = y[i];
			}
		}
	}
}


double* DigitalFilter::zeroFilter()
{
	int len = x_length;    // length of input
	int nb = b_length;
	int na = a_length;
	int nfilt = (na > nb) ? na : nb;
	int nfact = 3 * (nfilt - 1);  // length of edge transients
	//�����ֵ
	double data = 1 + a[1];
	double zi;
	zi = (b[1] - a[1] * b[0]) / data;
	//��β����
	const int yTemp_length = y_length + 2 * nfact;
	double* yTemp = new double[yTemp_length]; //ʹ��new����̬�õ�����
	for (int i = 0; i < nfact; i++)
	{
		yTemp[i] = 2 * x[0] - x[nfact - i];
	}
	for (int i = nfact; i < y_length + nfact; i++)
	{
		yTemp[i] = x[i - nfact];
	}
	for (int i = y_length + nfact; i < yTemp_length; i++)
	{
		yTemp[i] = 2 * x[x_length - 1] - x[yTemp_length - 2 - i + y_length - nfact];
	}
	//�����˲�
	this->zi = zi * yTemp[0];
	yTemp = zeroCalc(yTemp,yTemp_length);
	//����
	yTemp = this->reverse(yTemp, yTemp_length);
	//�����˲�
	this->zi = zi * yTemp[0];
	yTemp = zeroCalc(yTemp,yTemp_length);
	//����
	yTemp = this->reverse(yTemp, yTemp_length);
	for (int i = 0; i < y_length; i++)
	{
		this->y[i] = yTemp[i + nfact];
	}
	delete[] yTemp; //remember to delete
	return this->y;
}

double* DigitalFilter::zeroCalc(double* xx,const int xx_length)
{
	double* yy = new double[xx_length];
	int yy_length = xx_length;
	for (int i = 0; i < yy_length; i++)
	{
		if (i == 0)
		{
			yy[i] = b[0] * xx[i] + zi;
		}
		else
		{
			yy[i] = b[0] * xx[i] + b[1] * xx[i - 1] - a[1] * yy[i - 1];
		}
	}

	//assing back to xx because yy will be detoryed
	for (int i = 0; i < yy_length; i++){
		xx[i] = yy[i];
	}
	delete[] yy;
	return xx;
}

double* DigitalFilter::reverse(double* data, int data_length)
{
	double tmp;
	for (int i = 0; i < data_length / 2; i++)
	{
		tmp = data[data_length - i - 1];
		data[data_length - i - 1] = data[i];
		data[i] = tmp;
	}
	return data;
}



