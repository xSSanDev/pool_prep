#include <unistd.h>

/**
 * @brief Writes a single character to the standard output.
 * @param c The character to write.
 */
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/**
 * @brief Recursively prints a large number in hexadecimal (base-16).
 * This is a helper for ft_print_address.
 * @param n The number to print.
 */
void	ft_puthex_long(unsigned long long n)
{
	char	*hex_base = "0123456789abcdef";

	// The recursive step: if the number is still larger than the base (16),
	// call the function again with the number divided by the base.
	// This is the same logic as ft_putnbr, but with base-16.
	if (n >= 16)
	{
		ft_puthex_long(n / 16);
	}
	// The base case: print the last digit (the remainder).
	ft_putchar(hex_base[n % 16]);
}

/**
 * @brief Prints the memory address for Column 1.
 * It formats the address as a 16-digit hexadecimal number,
 * padded with leading zeros, and followed by a colon.
 * @param addr The memory address to print.
 */
void	ft_print_address(void *addr)
{
	unsigned long long	ptr_val;
	int					i;
	int					padding_count;
	unsigned long long	temp;

	// Cast the void pointer to a number so we can do math on it.
	ptr_val = (unsigned long long)addr;
	
	// This section calculates how many leading zeros are needed for padding.
	// A 64-bit address has 16 hex digits.
	padding_count = 15;
	temp = ptr_val;
	while (temp > 0)
	{
		temp /= 16;
		padding_count--;
	}

	// Print the required number of leading zeros.
	i = 0;
	while (i < padding_count)
	{
		ft_putchar('0');
		i++;
	}

	// Print the actual address in hexadecimal.
	ft_puthex_long(ptr_val);

	// Print the required colon at the end.
	ft_putchar(':');
}

/**
 * @brief Prints a single character as two hexadecimal digits for Column 2.
 * @param c The character to convert and print.
 */
void	ft_print_hex_char(unsigned char c)
{
	char	*hex_digits = "0123456789abcdef";

	// The first hex digit is the result of integer division by 16.
	ft_putchar(hex_digits[c / 16]);
	// The second hex digit is the remainder of division by 16.
	ft_putchar(hex_digits[c % 16]);
}

/**
 * @brief Prints the printable characters for Column 3.
 * If a character is not printable, it prints a dot instead.
 * @param chunk A pointer to the 16-byte (or smaller) line of memory.
 * @param size The number of characters to print from the chunk.
 */
void	ft_print_printable_chars(unsigned char *chunk, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		// A character is "printable" if it's between space (32) and tilde (126).
		if (chunk[i] >= 32 && chunk[i] <= 126)
		{
			ft_putchar(chunk[i]);
		}
		else
		{
			ft_putchar('.');
		}
		i++;
	}
}

/**
 * @brief The main orchestrator function. It prints a region of memory
 * in a formatted way, 16 bytes at a time.
 * @param addr A pointer to the start of the memory region.
 * @param size The number of bytes to print.
 * @return The original address pointer.
 */
void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	line_pos;
	unsigned char	*ptr;
	int				chars_on_this_line;

	ptr = (unsigned char *)addr;
	i = 0;
	if (size == 0)
		return (addr);

	// Main loop: process the memory in 16-byte chunks.
	while (i < size)
	{
		// --- COLUMN 1: Address ---
		ft_print_address(ptr + i);
		ft_putchar(' ');

		// --- COLUMN 2: Hex Content ---
		line_pos = 0;
		while (line_pos < 16)
		{
			if (i + line_pos < size)
				ft_print_hex_char(ptr[i + line_pos]);
			else // If we're past the end, print spaces for padding.
			{
				ft_putchar(' ');
				ft_putchar(' ');
			}
			if (line_pos % 2 == 1) // Add a space every two bytes.
				ft_putchar(' ');
			line_pos++;
		}
		
		// --- COLUMN 3: Printable Content ---
		chars_on_this_line = size - i;
		if (chars_on_this_line > 16)
			chars_on_this_line = 16;
		ft_print_printable_chars(ptr + i, chars_on_this_line);

		// End of the line.
		ft_putchar('\n');
		i += 16;
	}
	return (addr);
}

/**
 * @brief A main function to test the ft_print_memory implementation.
 */
int	main(void)
{
	// A test string containing various printable and non-printable characters.
	char	test_string[] = "Bonjour les aminches\t\n\tc'est fou\ttout\tce qu on "
							"peut faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n ";

	// Call the function to print the memory view of the string.
	ft_print_memory(test_string, sizeof(test_string));

	return (0);
}