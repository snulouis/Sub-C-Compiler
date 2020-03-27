/* struct operation */
struct str1 {
	int i;
	char c;
};

struct str2 {
	int *i;
	char *c;

	struct str3 {
		int *i;
		char *c;
	} st;
};

int main(void) {
	int i1;
	char c1;

	struct str1 st1;
	struct str2 st2;

	struct str1 *pst1;
	struct str2 *pst2;

	pst1 = &st1;
	pst2 = &st2;

	i1 = st1.i;


	i1 = *(pst2->st.i);

	return 0;
}
