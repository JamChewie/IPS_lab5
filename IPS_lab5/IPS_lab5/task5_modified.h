#ifndef TASK5M_H
#define TASK5M_H
#include <iostream>
#include <omp.h>
namespace TASK5_M {
	long long num = 100000000;
	double step;

	double par(void)
	{
		int num_of_threads = 3;
		long long inc = 0;
		long long i = 0;
		double x = 0.0;
		double pi;
		double S = 0.0;
		step = 1.0 / (double)num;
		double t = omp_get_wtime();
		// ���������������� ���� �� num_of_threads ���������� �������
		// ���������� ���������� reduction ��� ��������� ����� ������ ��� ���������� x, S � inc
		#pragma omp parallel for  num_threads(num_of_threads) reduction(+:x)  reduction(+:S) reduction(+:inc)
		for (i = 0; i < num; i++)
		{
			x = (i + 0.5)*step;
			S = S + 4.0 / (1.0 + x * x);
			inc++;
		}
		t = omp_get_wtime() - t;
		pi = step * S;
		printf("Par: pi = %.14f\n", pi);

		return t;

	}

	int run()
	{

		printf("time: %f sec.\n\n", par());
		return 0;
	}
}
#endif // !TASK5M_H
