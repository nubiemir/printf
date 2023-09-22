# printf


// if (format->type == 'x' || format->type == 'X')
//     res += ft_puthex_fd(va_arg(args, int), 1);
// if (format->type == 'p')
//     res += ft_putptr_fd(va_arg(args, int), 1);



#include <stdio.h>
#include <stdlib.h>

void intToHex(unsigned int n, char *hex_string, int index) {
    
     if (n == 0) {
        return; // Base case: stop recursion when n becomes 0
    }

    int remainder = n % 16;
    char digit;

    if (remainder < 10) {
        digit = '0' + remainder;
    } else {
        digit = 'A' + (remainder - 10);
    }

    intToHex(n / 16, hex_string, index--); // Recursive call

    hex_string[index] = digit;
}

int    ft_count_hex_digits(unsigned int nbr)
{
    int    count;

    count = 0;
    while (nbr)
    {
        count++;
        nbr /= 16;
    }
    return (count);
}

int main() {
  int x = 12342342342342;
  int y = ft_count_hex_digits(x);
  char  *hex_string =(char *)malloc(y + 1);
  intToHex(x, hex_string, y);
  
  return 0;
}
