#include <unistd.h> // For write
#include <stdlib.h> // For malloc, free, NULL

/*
 * ===================================================================
 * HELPER FUNCTIONS
 * ===================================================================
 */

/**
 * @brief Writes a single character to the standard output.
 */
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/**
 * @brief Writes a null-terminated string to the standard output.
 */
void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

/**
 * @brief Prints an integer to the standard output.
 * Handles negative numbers and the INT_MIN edge case.
 */
void	ft_putnbr(int nb)
{
	long long	n_long;

	n_long = nb;
	if (n_long < 0)
	{
		ft_putchar('-');
		n_long = -n_long;
	}
	if (n_long >= 10)
	{
		ft_putnbr(n_long / 10);
	}
	ft_putchar((n_long % 10) + '0');
}

/**
 * @brief Checks if a base string is valid according to C04 rules.
 * A valid base must:
 * 1. Have at least 2 characters.
 * 2. Not contain '+' or '-'.
 * 3. Not contain any duplicate characters.
 * 4. Not contain any whitespace characters.
 * @return 1 if valid, 0 if invalid.
 */
int	is_valid_base(char *base)
{
	int	base_len;
	int	i;
	int	j;

	base_len = 0;
	while (base[base_len] != '\0')
		base_len++;
	if (base_len < 2)
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ' ||
			base[i] == '\t' || base[i] == '\n' || base[i] == '\v' ||
			base[i] == '\f' || base[i] == '\r')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/**
 * @brief Finds the integer value (index) of a character in a base.
 * @return The index (0 to base_len-1) or -1 if not found.
 */
int	get_char_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

/**
 * @brief Calculates the length of the string needed to represent
 * a number in a new base, including the sign.
 * @return The number of characters (excluding the final '\0').
 */
int	get_final_string_len(long nbr, int base_len)
{
	int	len;

	len = 0;
	if (nbr < 0)
	{
		len++; // For the '-' sign
		nbr = -nbr;
	}
	if (nbr == 0)
	{
		return (1); // For the '0' character
	}
	while (nbr > 0)
	{
		nbr = nbr / base_len;
		len++;
	}
	return (len);
}

/*
 * ===================================================================
 * MAIN EXERCISE FUNCTION
 * ===================================================================
 */

/**
 * @brief Converts a number string from one base to another.
 * @param nbr The input number string (e.g., "101010").
 * @param base_from The base of the input string (e.g., "01").
 * @param base_to The base to convert to (e.g., "0123456789").
 * @return A new, malloc'd string of the converted number, or NULL on error.
 */
char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int			base_from_len;
	int			i;
	int			sign;
	int			result;
	int			digit_value;
	long long	final_nbr;
	int			base_to_len;
	int			final_str_len;
	char		*final_string;
	int			k;

	// 1. Validate both bases
	if (is_valid_base(base_from) == 0 || is_valid_base(base_to) == 0)
		return (NULL);

	// --- PART A: ft_atoi_base logic (String to Int) ---
	base_from_len = 0;
	while (base_from[base_from_len] != '\0')
		base_from_len++;
	i = 0;
	while (nbr[i] == ' ' || (nbr[i] >= '\t' && nbr[i] <= '\r'))
		i++;
	sign = 1;
	while (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			sign *= -1;
		i++;
	}
	result = 0;
	digit_value = get_char_index(nbr[i], base_from);
	while (digit_value != -1)
	{
		result = (result * base_from_len) + digit_value;
		i++;
		digit_value = get_char_index(nbr[i], base_from);
	}
	final_nbr = (long long)result * sign;

	// --- PART B: ft_putnbr_base logic (Int to String) ---
	base_to_len = 0;
	while (base_to[base_to_len] != '\0')
		base_to_len++;
	final_str_len = get_final_string_len(final_nbr, base_to_len);
	final_string = (char *)malloc(sizeof(char) * (final_str_len + 1));
	if (final_string == NULL)
		return (NULL);
	final_string[final_str_len] = '\0';
	k = final_str_len - 1;
	if (final_nbr == 0)
	{
		final_string[0] = base_to[0];
		return (final_string);
	}
	if (final_nbr < 0)
	{
		final_string[0] = '-';
		final_nbr = -final_nbr;
	}
	while (final_nbr > 0)
	{
		digit_value = final_nbr % base_to_len;
		final_string[k] = base_to[digit_value];
		final_nbr = final_nbr / base_to_len;
		k--;
	}
	return (final_string);
}

/*
 * ===================================================================
 * MAIN TEST FUNCTION
 * ===================================================================
 */

int	main(void)
{
	char	*hex = "0123456789ABCDEF";
	char	*bin = "01";
	char	*dec = "0123456789";
	char	*nbr_str = "   --+101010"; // Represents 42 in binary
	char	*result_str;

	ft_putstr("Input string: '");
	ft_putstr(nbr_str);
	ft_putstr("'\n");
	ft_putstr("Input base: '");
	ft_putstr(bin);
	ft_putstr("'\n");
	ft_putstr("Output base: '");
	ft_putstr(dec);
	ft_putstr("'\n");

	// Call the function
	result_str = ft_convert_base(nbr_str, bin, dec);

	// Print the result
	ft_putstr("Result: '");
	if (result_str == NULL)
	{
		ft_putstr("NULL");
	}
	else
	{
		ft_putstr(result_str);
	}
	ft_putstr("'\n");

	// CRITICAL: Free the allocated memory
	free(result_str);

	return (0);
}