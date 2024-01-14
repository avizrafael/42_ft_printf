
int	main(void)
{
	char		byte;
	char		*string;
	int			number1;
	int			number2;
	void		*pointer;
	unsigned int	number3;
	unsigned int	number4;

	byte = 'a';
	string = "Hello World!";
	number1 = 42;
	number2 = -42;
	pointer = &number1;
	number3 = 42;
	number4 = 42;
	ft_printf("%c\n", byte);
	ft_printf("%s\n", string);
	ft_printf("%d\n", number1);
	ft_printf("%i\n", number2);
	//ft_printf("%d %i\n", number1, number2);
	ft_printf("%p\n", pointer);
	ft_printf("%x\n", number3);
	ft_printf("%X\n", number4);
	//ft_printf("%x %X\n", number3, number4);
	ft_printf("%%\n");
	ft_printf("%c %c\n", byte, byte);
	return (0);
}
