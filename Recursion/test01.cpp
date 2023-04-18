#include<iostream>
#include<time.h>  
using namespace std;
int main() {
	clock_t start_time = clock();
	{
		int a[1000][1000] = { 0 };
		for (int i = 0; i < 1000; i++) {
			for (int j = 0; j < 1000; j++) {
				a[i][j] = 9999;
			}
		}
	
	} 
	clock_t end_time = clock();
	cout << "Running time is: " << static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
	return 0;
}
/*����*/
//#include<iostream>
//#include<cmath>
//#include<algorithm>
//using namespace std;
//
//int main() {
//    cout << fixed;
//    
//    long int seconds = (int)3.156 * pow(10.0, 7);
//    cout << seconds << endl;
//    //cout << setprecision(0);
//    long int age;
//    cin >> age;
//    cout << age * seconds;
//
//    return 0;
//}

//#include<iostream>
//using namespace std;
//
//int main() {
//    int i, j;
//    for (i = 1; i <= 9; i++) {
//        for (j = 1; j <= i; j++) {
//            printf("%d*%d= %d\t", i, j, i * j);
//        }
//        cout << endl;
//    }
//    return 0;
//}
/*����*/
//# include<iostream>
//# include<algorithm>
//using namespace std;
//
//void f(int t[9]);
//void res_factors(int preres, int factorL, int factorR);
//
//void getProduct(int a[]);
//void judgeProduct(int product, int factorL, int factorR);
//
//
//int main() {
//	// �����1��9�����飬ʹ��next_permutation(a, a+9)��ȫ����
//	int t[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	/*
//	int a[3] = { 1, 2, 3 };
//	do {
//		for (int i = 0; i < 3; i++)
//			cout << a[i] << ' ';
//		cout << endl;
//	}
//	while (next_permutation(a, a + 3));
//	*/
//	//f(t);
//	getProduct(t);
//	return 0;
//}
//
//void getProduct(int a[9]) {
//	int product;
//	int factor1, factor2, factor3, factor4;
//	do {
//		// ��λ�� = ��λ�� x ��λ��
//		product = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
//		factor2 = a[4] * 10 + a[5];
//		factor3 = a[6] * 100 + a[7] * 10 + a[8];
//		judgeProduct(product, factor2, factor3);
//		// ��λ�� = һλ�� x ��λ��
//		product = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
//		factor1 = a[4];
//		factor4 = a[5] * 1000 + a[6] * 100 + a[7] * 10 + a[8];
//		judgeProduct(product, factor1, factor4);
//	} while (next_permutation(a, a + 9));
//	return;
//}
//void judgeProduct(int product, int factorL, int factorR) {
//	if (product == factorL * factorR) {
//		cout << product << " = " << factorL << " x " << factorR << endl;
//	}
//	return;
//}
//
//void f(int a[9]) {
//	int res; // �˻���
//	int factor1, factor4; // factor1: һλ������ factor4: ��λ������
//	int factor2, factor3; // factor2: ��λ������ factor3: ��λ������
//
//
//	do {
//		// 4λ��=1λ�� * 4λ��
//		res = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
//		factor1 = a[4];
//		factor4 = a[5] * 1000 + a[6] * 100 + a[7] * 10 + a[8];
//		res_factors(res, factor1, factor4);
//		// 4λ��=2λ�� * 2λ��
//		res = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
//		factor2 = a[4] * 10 + a[5];
//		factor3 = a[6] * 100 + a[7] * 10 + a[8];
//		res_factors(res, factor2, factor3);
//	} while (next_permutation(a, a + 9));
//}
//
//void res_factors(int preres, int factorL, int factorR) {
//	if (preres == factorL * factorR) {
//		cout << preres << " = " << factorL << " x " << factorR << endl;
//	}
//	return;
//}