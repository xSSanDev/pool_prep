#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/**
 * @brief Helper function to print a found solution (the board array).
 * Prints the 10 digits followed by a newline.
 */
void	print_solution(int board[10])
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = board[i] + '0'; // Convert int 0-9 to char '0'-'9'
		ft_putchar(c);
		i++;
	}
	ft_putchar('\n');
}

/**
 * @brief Checks if placing a queen at (current_col, proposed_row) is safe.
 * Returns 1 if safe, 0 if there is a conflict.
 */
int	is_safe(int board[10], int current_col, int proposed_row)
{
	int	i; // Loop counter for checking previous columns

	i = 0;
	// Loop through all *previously placed* queens (cols 0 to current_col - 1)
	while (i < current_col)
	{
		// 1. Check for Row Conflict
		if (board[i] == proposed_row)
			return (0);

		// 2. Check for Diagonal Conflict (Up-Right/Down-Left)
		if (board[i] - proposed_row == current_col - i)
			return (0);

		// 3. Check for Diagonal Conflict (Up-Left/Down-Right)
		if (board[i] - proposed_row == i - current_col)
			return (0);

		i++; // Move to check the next placed queen
	}
	// If no conflicts were found, the spot is safe
	return (1);
}

/**
 * @brief The recursive solver function (Backtracking).
 * Tries to place a queen in 'current_col' and all subsequent columns.
 * Returns the total number of solutions found from this point.
 */
int	solve_puzzle(int board[10], int current_col)
{
	int	row_to_try;
	int	solution_count;

	// --- BASE CASE ---
	// If current_col is 10, we have successfully placed queens in
	// all 10 columns (0-9). This is a valid solution.
	if (current_col == 10)
	{
		print_solution(board); // Print the solution
		return (1);            // Return 1 to count this solution
	}

	// --- RECURSIVE STEP ---
	solution_count = 0; // Solutions found from this column forward
	row_to_try = 0;
	// Try placing a queen in every row of the current column
	while (row_to_try < 10)
	{
		// Check if this spot (current_col, row_to_try) is safe
		if (is_safe(board, current_col, row_to_try) == 1)
		{
			// 1. "Place" the queen
			board[current_col] = row_to_try;

			// 2. "Recurse": Call the function for the *next* column
			//    and add any solutions it finds to our count.
			solution_count += solve_puzzle(board, current_col + 1);
		}
		row_to_try++; // Move to try the next row
	}

	// Return the total solutions found from this path
	return (solution_count);
}

/**
 * @brief Main function required by the subject.
 * Initializes the board and starts the recursive solver.
 */
int	ft_ten_queens_puzzle(void)
{
	int	board[10]; // Stores the row position for each column
	int	total_solutions;

	// Note: We don't strictly need to initialize the board,
	// as 'is_safe' only checks columns < current_col.

	// Start the recursive process from the first column (column 0)
	total_solutions = solve_puzzle(board, 0);

	// Return the total number of solutions found
	return (total_solutions);
}
int main()
{
  	ft_ten_queens_puzzle();
    return (0);
}