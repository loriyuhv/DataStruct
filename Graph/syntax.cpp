
//#include <iostream>
//#include <vector>
//using namespace std;
//
//struct node {
//	int next, tre;
//	node(int nn, int tt) :next(nn), tre(tt) {}
//	node() {}
//};
//
//vector<node> road[1005];
//int start[1005];
//int dp[1005];
//
//int main() {
//	int n, m, a, b, c;
//	memset(start, 0, sizeof(start));
//	memset(dp, 0, sizeof(start));
//	cout << "���붥�����ͱ�����\n";
//	cin >> n >> m;
//	for (int i = 0; i < m; i++) {
//		cin >> a >> b >> c;
//		road[a].push_back(node(b, c));
//		start[b] = 1;
//	}
//	return 0;
//}

/*vectorʹ��*/
/*�ɶ�ʸ��ִ�еĲ���*/
//#include<iostream>
//#include<vector>
//
//const int NUM = 5;
//int main() {
//	using std::cin;
//	using std::vector;
//	using std::cout;
//	using std::endl;
//
//	/*
//	vector<double> scores(NUM);
//	vector<double>::iterator pd;
//	pd = scores.begin();
//	*pd = 22.3;
//	++pd;
//
//	vector<double> scores1(NUM);
//	auto pd2 = scores1.begin();
//	*pd2 = 21.3;
//	++pd2;
//	for (int i = 0; i < NUM; ++i)
//		cout << "scores:" << scores[i] << " scores1:" << scores1[i] << endl;
//
//	cout << endl;
//	for (pd2 = scores.begin(); pd2 != scores.end(); pd2++)
//		cout << *pd2 << endl;
//	*/
//	vector<double> scores(NUM);	// create an empty vector
//	double temp;
//	while (cin >> temp && temp >= 0)
//		scores.push_back(temp);	/* ��scores��������һ��Ԫ�� */
//	cout << "You entered " << scores.size() << " scores.\n";
//	
//	for (auto pd = scores.begin(); pd != scores.end(); ++pd)
//		cout << *pd << "\t";
//	cout << endl;
//	scores.erase(scores.begin(), scores.begin() + 5);
//	for (auto pd = scores.begin(); pd != scores.end(); ++pd)
//		cout << *pd << "\t";
//	return 0;
//}
//vecto1.cpp
//#include<iostream>
//#include<string>
//#include<vector>
//
//const int NUM = 5;
//int main() {
//	using std::vector;
//	using std::string;
//	using std::cin;
//	using std::cout;
//	using std::endl;
//
//	vector<int> ratings(NUM);
//	vector<string> titles(NUM);
//	cout << "You will do exactly as told. You will enter\n"
//		<< NUM << " book titles and your ratings(0-10).\n";
//	int i;
//	for (i = 0; i < NUM; ++i) {
//		cout << "Enter title #" << i + 1 << "��";
//		getline(cin, titles[i]);
//		cout << "Enter your rating (0-10)��";
//		cin >> ratings[i];
//		cin.get();
//	}
//	cout << "Thank you. You entered the following:\n"
//		<< "Rating\tBook\n";
//	for (i = 0; i < NUM; i++)
//		cout << ratings[i] << "\t" << titles[i] << endl;
//
//	return 0;
//}
// ʾ��
//#include<iostream>
//#include<vector>
//using namespace std;
//vector<int> ratings(5);
//
//int main() {
//	int n;
//	cin >> n;
//	vector<double> scores(n);
//	ratings[0] = 9;
//	for (int i = 0; i < n; i++)
//		cout << scores[i] << endl;
//	return 0;
//}
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main() {
//	//vector<int>a;	/* ����һ����̬����a��a��Ĭ�ϳ�ֵΪ0 */
//	//vector<int>b(a);	/* ��a��Ԫ�ظ��Ƶ�b�� */
//	//vector<int>a(100);	/*������a��Ԫ�ض���Ϊ100����Ĭ�ϳ�ʼֵ*/
//	//vector<int>a(100, 6); /* ����100��ֵΪ6��Ԫ�� */
//
//	//vector<string>a(10, "hello");
//	//vector<string>b(a.begin(), a.end()); /*����̬����a��Ԫ��ֵ���Ƶ�b��*/
//	vector<int> vec0[10];
//
//	for (int i = 0; i < 10; ++i) {
//		vec0[i].push_back(i);
//	}
//
//	//printf("%d\n", vec0.size());
//
//	//vector<int>::iterator it1;
//	//for (it1 = vec0.begin(); it1 != vec0.end(); ++it1) {
//	//	cout << " " << *it1 << endl;
//	//}
//
//	//vector<int>::reverse_iterator it2;
//	//for (it2 = vec0.rbegin(); it2 != vec0.rend(); ++it2) {
//	//	cout << " " << *it2 << endl;
//	//}
//
//	return 0;
//}
/*�ṹ�幹�캯����ϰ*/
//#include<iostream>
//using namespace std;
//
//struct student {
//	int age;
//	string name;
//	//student(string name, int age) :name(name), age(age) {}
//	student() {}
//}Student[10];
//
//int main() {
//	Student[0] = {};
//	Student[0].name = "Alan";
//	Student[0].age = 18;
//	cout << Student[0].name << " " << Student[0].age << endl;
//	return 0;
//}
/*�ṹ�幹�캯��*/
//#include<iostream>
//using namespace std;
//
//struct node {
//	int data;
//	string str;
//	char x;
//	// ��ʼ������
//	void init(int a, string b, char c) {
//		this->data = a;
//		this->str = b;
//		this->x = c;
//	}
//	// ע�⣺���캯���������û�зֺ�
//	node() :x(), str(), data() {}	/* �޲����Ĺ��캯�������ʼ��ʱ���� */
//	node(int a, string b, char c) :data(a), str(b), x(c) {} /* �вι��� */
//}Node[10];
//
//int main() {
//	Node[0] = { 1, "123a", 'a' };
//	Node[1] = { 2, "c++", 'd' };
//	
//	cout << Node[0].data << " " << Node[0].str << endl;
//
//
//	return 0;
//}