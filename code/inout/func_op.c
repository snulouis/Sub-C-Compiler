/* function operation */

int func1(int a, char b) {
	return 0;
}

char func2(void) {
	return 'a';
}

void func3(int *a, int b) {
	int *c;

}

int main(void) {
	int a;
	char b;

	int c;
	char d;

	a = 1;
	b = 'c';

	c = func1(a, b);
	d = func2();

	func3(&a, c);


	return 0;
}
