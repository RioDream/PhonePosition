
//************************************
//
// DigitalFilter class is a C++ implementation of filtfilt() function in Matlab.  
// This code is based on C# implementation version here, http://blog.csdn.net/iamoyjj/article/details/4556381
// 
//************************************

class DigitalFilter
{
public:
	//************************************
	// Method:    DigitalFilter
	// FullName:  DigitalFilter::DigitalFilter
	// Access:    public 
	// Returns:   
	// Qualifier:
	// Parameter: const int order : the order of filter,for example -> in Matlab [b, a] = butter(order, (2 * filtCutOff) / (1 / samplePeriod), 'high');
	// Parameter: const int np: the number of samples 
	// Parameter: double * b: coefficient of filter
	// Parameter: double * a: coefficient of filter
	// Parameter: double * x: input 
	// Parameter: double * y: output
	// Parameter: double zi: initial status
	//************************************
	DigitalFilter(const int order, const int np, double* b, double* a, double* x, double* y, double zi = 0.0);
	//************************************
	// Method:    zeroFilter
	// FullName:  DigitalFilter::zeroFilter
	// Access:    public 
	// Returns:   double* : return the output
	// Qualifier:
	//************************************
	double* zeroFilter();

private:
	//ÂË²¨Æ÷ÏµÊý
	double* b;
	double* a;
	int b_length;
	int a_length;

	//xÊÇÊäÈë
	double* x;
	int x_length;
	double zi;

	//yÊÇÊä³ö
	double* y;
	int y_length;
	double zf[1];

	double* getY();
	double* getZf();

	void calc();
	double* zeroCalc(double* xx,const int xx_length);
	double* reverse(double* data, int data_length);





};
