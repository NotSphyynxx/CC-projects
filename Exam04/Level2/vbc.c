#include <stdio.h>
#include <ctype.h>

void    unexpected(char c)
{
    if (c)
        printf("Unexpected token '%c'\n", c);
    else
        printf("Unexpected end of file\n");
}

char *s;
int parsefactor();
int parseproduct();
int parsesum();

int checkinput(char *str){
	int i = 0;
	int par = 0;
	char last_char = 0;
	while (str[i]){
		if (str[i] == '(')
			par++;
		if (str[i] == ')')
			par--;
		if (isdigit(str[i]) && isdigit(str[i + 1]))
			return (unexpected(str[i + 1]), 1);
		last_char = str[i];
		i++;
	}
	if (par > 0)
		return (unexpected('('), 1);
	if (par < 0)
		return (unexpected(')'), 1);
	if (last_char == '*' || last_char == '+')
		return (unexpected(0), 1);
	return (0);
}

int parsesum(){
	int sum1 = parseproduct();
	int sum2;
	while (*s == '+'){
		s++;
		sum2 = parseproduct();
		sum1 = sum1 + sum2;
	}
	return (sum1);
}

int parseproduct(){
	int multi1 = parsefactor();
	int multi2;
	while (*s == '*'){
		s++;
		multi2 = parsefactor();
		multi1 = multi1 * multi2;
	}
	return (multi1);
}

int parsefactor(){
	int nb = 0;
	if (isdigit(*s))
		return (*s++ - '0');
	else if (*s == '('){
		s++;
		nb = parsesum();
		s++;
	}
	return (nb);
}

int main(int ac, char **av){
	(void)ac;
	s = av[1];
	if (checkinput(av[1]))
		return (1);
	int res = parsesum();
	printf("%d\n", res);
}
