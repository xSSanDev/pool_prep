#include <unistd.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
/*
 * Checks if the given base string is valid for number conversion.
 * A valid base must:
 * 1. Have at least 2 unique characters.
 * 2. Not contain '+' or '-'.
 * 3. Not contain the same character twice.
 * Returns:
 * 1 if the base is valid.
 * 0 if the base is invalid.
 */
int	is_base_valid(char *base)
{
	int	len; // To store the length of the base string
	int	i;   // Index for looping through the base
	int	j;   // Index for nested loop (duplicate check)

	// --- Check Rule 1: Length must be >= 2 ---
	len = 0;
	// Calculate the length of the base string
	while (base[len] != '\0')
	{
		len++;
	}
	// If length is less than 2 (empty or single char), base is invalid
	if (len < 2)
	{
		return (0);
	}
	// --- Check Rule 2: Must not contain '+' or '-' ---
	i = 0;
	while (base[i] != '\0')
	{
		// If a '+' or '-' is found, base is invalid
		if (base[i] == '+' || base[i] == '-')
		{
			return (0);
		}
		i++;
	}
	// --- Check Rule 3: Must not contain duplicates ---
	i = 0;
	// Outer loop: Iterate through each character of the base
	while (base[i] != '\0')
	{
		// Inner loop: Start checking from the *next* character
		j = i + 1;
		while (base[j] != '\0')
		{
			// If the character at 'i' is found again at 'j', it's a duplicate
			if (base[i] == base[j])
			{
				return (0); // Duplicate found, base is invalid
			}
			j++; // Move to the next character in the inner loop
		}
		i++; // Move to the next character in the outer loop
	}
	// If all checks passed without returning 0, the base is valid
	return (1);
}
// --- Main Number Printing Function ---
/*
 * Prints an integer 'nbr' in the specified 'base'.
 * Handles negative numbers and the INT_MIN edge case.
 * Prints nothing if the provided 'base' is invalid.
 */
void	ft_putnbr_base(int nbr, char *base)
{
	int			base_len; // The number of unique digits in the base (e.g., 10 for decimal, 16 for hex)
	long long	n_long;

	if (is_base_valid(base) == 0)
	{
		return; // Stop execution if base is invalid
	}
	// 2. Calculate the length (the actual base number) of the valid base string.
	base_len = 0;
	while (base[base_len] != '\0')
	{
		base_len++;
	}
	// Convert nbr to long long to handle potential INT_MIN overflow during negation
	n_long = nbr;
	// 3. Handle negative numbers.
	if (n_long < 0)
	{
		ft_putchar('-');     // Print the negative sign
		n_long = -n_long; // Make the number positive for processing (safe with long long)
	}
	// 4. Recursive Conversion Logic:
	// Base Case: If the number is smaller than the base length, it's a single digit.
	if (n_long < base_len)
	{
		// Print the character from the base string at the index corresponding to the number.
		ft_putchar(base[n_long]);
	}
	else // Recursive Step: If the number is larger or equal to the base length...
	{
		// a) Recursively call the function to print the digits to the left.
		//    We pass the integer division result and the base.
		//    Cast back to int as the result of division will fit.
		ft_putnbr_base((int)(n_long / base_len), base);

		// b) AFTER the recursive call returns, print the character for the current digit.
		//    The index of the character is the remainder of the division.
		ft_putchar(base[n_long % base_len]);
	}
}
int main(void)
{
    ft_putnbr_base(42, "0123456789ABCDEF");// Hexadecimal (base 16)
	ft_putchar('\n');
	ft_putnbr_base(-2147483648, "0123456789"); //Decimal (Base 10)
	ft_putchar('\n');
    ft_putnbr_base(42, "01"); ft_putchar('\n'); // Binary (base 2)
	ft_putchar('\n');
    ft_putnbr_base(42, "01234567");  // Octal (base 8)
	ft_putchar('\n');
    return (0);
}