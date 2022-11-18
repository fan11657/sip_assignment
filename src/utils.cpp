#include <random>
#include "utils.h"

string RandomStrGenerator::generate(int len) {
	const string ALLOWED_CHARS =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";

	//Mersenne twister
	mt19937 generator(random_device{}());
	uniform_int_distribution<int> distribution(0, ALLOWED_CHARS.size() - 1);

	string randStr(len, '\0');
	for (char& c : randStr) {
		c = ALLOWED_CHARS[distribution(generator)];
	}
	return randStr;
}