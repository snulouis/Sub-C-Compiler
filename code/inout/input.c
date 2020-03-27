int global_1;
int global_2;

struct _str1{
	int x;
	int y;
	struct _str2{
		int z;
		int w[5];
	} strstr;
}sample_str;

struct _str1 func(int i, struct _str1 t, int j) {
	write_int(t.strstr.w[3]);
	write_string("\n");

	write_int(t.strstr.z);
	write_string("\n");

	write_int(t.x);
	write_string("\n");

	return t; 
}


struct _str1 func2() {
	struct _str1 t;
	t.x = -5;
	t.strstr.z = -44;
	t.strstr.w[3] = -333;

	return t; 
}




int main(){
	int i;
	int j;
	int k;
	int *l;
	int x;
	int a;
	int b;
	struct _str1 teststr; //teststr[10];
	struct _str1 aa;
	struct _str1 bb;

	//i = 5;
	k = -11111;
	i = -99999;

	teststr.x = -9;
	teststr.strstr.z = -88;
	teststr.strstr.w[3] = -777;

	aa = func(-2222, teststr, i);
	bb = teststr;

	write_int(aa.strstr.w[3]);
	write_string("\n");

	write_int(aa.strstr.z);
	write_string("\n");

	write_int(aa.x);
	write_string("\n");

	write_int(bb.strstr.w[3]);
	write_string("\n");

	write_int(bb.strstr.z);
	write_string("\n");

	write_int(bb.x);
	write_string("\n");

	a = func(-2222, teststr, i).strstr.z;
	write_int(a);
	write_string("\n");



	a = func2().strstr.z;
	write_int(a);
	write_string("\n");

	a = func2().strstr.w[3];
	write_int(a);
	write_string("\n");

	a = func2().x;
	write_int(a);
	write_string("\n");


	

	return 0;

}
