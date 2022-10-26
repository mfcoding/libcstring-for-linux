#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/cstring.h"

int main()
{
    string msg = new string(12, 'H', 'e', 'l', 'l', 'o', ' ', 'g', 'i', 't', 'h', 'u', 'b');

	display(&msg);

	insert(&msg, length(&msg), "!");

	display(&msg);

	string str = $("Hello world");

	display(&str);

	append(&str, " 2022");
	
	display(&str);

	replace_all(&str, "new text", strlen("new text"));

	display(&str);

	string digits = new string(5, 48, 49, 50, 51, 52);

	display(&digits);

	Used_memory();

	puts("");
	
	About_Author();

    return 0;
}
