namespace golf {
	const int LEN = 40;

	struct Golf {
		char fullname[LEN];
		int handicap;
	};

	void set_Golf(Golf& g, const char* name, int hc);
	int set_Golf(Golf& g);
	void set_handicap(Golf& g, int hc);
	void show_Golf(const Golf& g);
}