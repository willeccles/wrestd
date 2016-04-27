#include "wrestd.h"
#include <string>

/* Count occurrences of substring 'substr' in std::string 'str'. */
int wrestd::substr_count(std::string str, std::string substr, bool overlap=true) {
	if (str.find(substr) == str.npos) return 0;

	int index = 0;
	int count = 0;

	while (str.find(substr, index) != str.npos) {
		index = str.find(substr, index) + (overlap ? 1 : substr.length());
		count++;
	}

	return count;
}

/* Same as substr_replace, but acts directly on 'str'. */
void substr_replace_volatile(std::string &str, std::string substr, std::string replacement, bool overlap = false) {
	if (str.find(substr) == str.npos) return;

	int index = 0;

	while (str.find(substr, index) != str.npos) {
		index = str.find(substr, index);
		str.erase(index, substr.length());
		str.insert(index, replacement);
		index += (overlap ? 1 : replacement.length());
	}
}

/* Replace all occurrences of substring 'substr' in std::string 'str'. */
std::string wrestd::substr_replace(std::string &str, std::string substr, std::string replacement, bool overlap = false, bool replace = false) {
	if (replace) {
		substr_replace_volatile(str, substr, replacement, overlap);
		return str;
	}

	std::string _str = str;

	if (_str.find(substr) == _str.npos) return _str;

	int index = 0;

	while (_str.find(substr, index) != _str.npos) {
		index = _str.find(substr, index);
		_str.erase(index, substr.length());
		_str.insert(index, replacement);
		index += (overlap ? 1 : replacement.length());
	}

	return _str;
}