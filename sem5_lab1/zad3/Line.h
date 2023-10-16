using namespace std;
#include <iostream>

#pragma once
class Line
{
private:
	int len;
	void draw(int len) {
		cout << '\n';
		for (int i = 0; i < len; i++) {
			cout << '*';
		}
		cout << '\n';
	}
	void clear() {
		// CSI[2J clears screen, CSI[H moves the cursor to top-left corner
		std::cout << "\x1B[2J\x1B[H";
	}
public:
	Line(int len) {
		this->len = len;
		draw(len);
	}
	~Line() {
		clear();
	}
};