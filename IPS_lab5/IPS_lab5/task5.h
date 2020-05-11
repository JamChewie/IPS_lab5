#ifndef TASK5_H
#define TASK5_H
#include <iostream>
#include <omp.h>
namespace TASK5 {
	long long num = 100000000;
	double step;

	double par(void)
	{
		int num_of_threads = 3;
		omp_set_num_threads(num_of_threads);
		long long inc = 0;
		long long i = 0;
		double x = 0.0;
		double pi;
		double S = 0.0;
		step = 1.0 / (double)num;
		double t = omp_get_wtime();
		// создаем замок
		omp_lock_t lock;
		// Инициализирует простой замок
		omp_init_lock(&lock);
		// распараллеливаем цикл на num_of_threads количество потоков
		// используем сокращение reduction для избежания гонок данных для переменных x и S
		#pragma omp parallel for  num_threads(num_of_threads) reduction(+:x)  reduction(+:S) 
		for (i = 0; i < num; i++)
		{
			x = (i + 0.5)*step;
			S = S + 4.0 / (1.0 + x * x);
			// устанавливаем замок
			omp_set_lock(&lock);
			inc++;
			// снимаем замок
			omp_unset_lock(&lock);
		}
		omp_destroy_lock(&lock);
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
#endif // !TASK5_H
