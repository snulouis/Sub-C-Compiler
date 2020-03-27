int outprint(int* j){
	*j = *j + 10;
	//return *j;
}

int main(){
	int i;
	int k;
	int *l;

	k = 10;
	l = &k;
	
	i = outprint(l);
	write_int(k);
	write_string("\n");
}
