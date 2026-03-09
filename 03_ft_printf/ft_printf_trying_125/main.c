/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:03:06 by asadiqui          #+#    #+#             */
/*   Updated: 2023/12/01 15:34:58 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_printf.h"
#include "ft_printf_bonus.h"

int	main(void)
{ // # +
	// - ==> c,s,d,i,u,x,X,p V
	// . ==> s,d,i,u,x,X
	// 0 ==> d,i,u,x,X
	int nft = 0;
	int n = 0;

	// nft += ft_printf("-flag: %-3c, %-3s, %-3d, %-3i, %-3u, %-3x, %-3X, %-15p.\n", 'a', "H", 42, 42, -42, 42, 42, main);
	// n += printf("-flag: %-3c, %-3s, %-3d, %-3i, %-3u, %-3x, %-3X, %-15p.\n", 'a', "H", 42, 42, -42, 42, 42, main);
	// nft += ft_printf(".flag: %.3s, %.3d, %.3i, %.3u, %.3x, %.3X.\n", "H", 42, 42, -42, 42, 42);
	// n += printf(".flag: %.3s, %.3d, %.3i, %.3u, %.3x, %.3X.\n", "H", 42, 42, -42, 42, 42);
	// nft += ft_printf("0flag: %03d, %03i, %03u, %03x, %03X.\n", 42, 42, -42, 42, 42);
	// n += printf("0flag: %03d, %03i, %03u, %03x, %03X.\n", 42, 42, -42, 42, 42);

	// nft += ft_printf("%.5d,%.5d,%.5x,%.5x,%.5u,%.5u\n", 14, -14, 14, -14, 14, -14);
	// n +=printf("%.5d,%.5d,%.5x,%.5x,%.5u,%.5u\n", 14, -14, 14, -14, 14, -14);
	// nft += ft_printf("%-5d,%-5d,%-5x,%-5x,%-5u,%-5u\n", 14, -14, 14, -14, 14, -14);
	// n += printf("%-5d,%-5d,%-5x,%-5x,%-5u,%-5u\n", 14, -14, 14, -14, 14, -14);
	// nft +=ft_printf("%05d,%05d,%05x,%05x,%05u,%05u\n", 14, -14, 14, -14, 14, -14);
	// n += printf("%05d,%05d,%05x,%05x,%05u,%05u\n", 14, -14, 14, -14, 14, -14);

	// nft += ft_printf(". %.1s %.2s %.3s %.4s .\n", " - ", "", "4", "");
	// n +=printf(". %.1s %.2s %.3s %.4s .\n", " - ", "", "4", "");
	// nft += ft_printf("%s,%-3s,%.3s,%-.3s,\n", "H", "H", "Hello", "Hello");
	// n += printf("%s,%-3s,%.3s,%-.3s,\n", "H", "H", "Hello", "Hello");
	
	// nft += ft_printf(",%5c,%10s,%5d,%5i,%5u,%5x,%5X,%p,\n", 'a', NULL, 42, 42, -42, 42, 42, NULL);
	// n +=      printf(",%5c,%10s,%5d,%5i,%5u,%5x,%5X,%p,\n", 'a', NULL, 42, 42, -42, 42, 42, NULL);
	
	// // nft += ft_printf(">------------<%2.4s>------------<\n", "hello");
	// n +=      printf(">------------<%2.s,%2.d,%2.2d>------------<\n", "hello",1,1); // min.max
	// n +=      printf(">------------<%.2s,%.2d>------------<\n", "hello",1); // min.max
	
	nft += ft_printf("%.5d,%5.d,%7.3d,%3.7d;%.5d,%5.d,%7.3d,%3.7d,\n", 42,42,42,42, -42,-42,-42,-42);
	n +=	  printf("%.5d,%5.d,%7.3d,%3.7d;%.5d,%5.d,%7.3d,%3.7d,\n", 42,42,42,42, -42,-42,-42,-42);
	nft += ft_printf("%05d,%50d,\n",42,42);
	n +=	  printf("%05d,%50d,\n",42,42);
	nft += ft_printf("%-5d,\n",42);
	n +=	  printf("%-5d,\n",42);
	ft_printf("-------------------");printf("%d, %d\n", nft, n);
	nft += ft_printf("%.5u,%5.u,%7.3u,%3.7d;%.15u,%15.u,%17.13u,%13.17u,\n", 42,42,42,42, -42,-42,-42,-42);
	n +=	  printf("%.5u,%5.u,%7.3u,%3.7d;%.15u,%15.u,%17.13u,%13.17u,\n", 42,42,42,42, -42,-42,-42,-42);
	nft += ft_printf("%05u,%50u,\n",42,42);
	n +=	  printf("%05u,%50u,\n",42,42);
	nft += ft_printf("%-5u,\n",42);
	n +=	  printf("%-5u,\n",42);
	ft_printf("-------------------");printf("%d, %d\n", nft, n);
	nft += ft_printf("%.5x,%5.x,%7.3x,%3.7d;%.15x,%15.x,%17.13x,%13.17x,\n", 42,42,42,42, -42,-42,-42,-42);
	n +=	  printf("%.5x,%5.x,%7.3x,%3.7d;%.15x,%15.x,%17.13x,%13.17x,\n", 42,42,42,42, -42,-42,-42,-42);
	nft += ft_printf("%05x,%50x,\n",42,42);
	n +=	  printf("%05x,%50x,\n",42,42);
	nft += ft_printf("%-5x,\n",42);
	n +=	  printf("%-5x,\n",42);
	// ft_printf("-------------------");printf("%d, %d\n", nft, n);
	// nft += ft_printf("%15.p,%-15p,\n", main,main);
	// n +=	  printf("%15.p,%-15p,\n", main,main);
	// ft_printf("-------------------");printf("%d, %d\n", nft, n);
	// nft += ft_printf("%.5s,%5.s,%7.3s,%5.7s;\n", "Hell","Hell","Hell","Hell");
	// n +=	  printf("%.5s,%5.s,%7.3s,%5.7s;\n", "Hell","Hell","Hell","Hell");
	// nft += ft_printf("%-.5s,%-5.s,%-7.3s,%-5.7s;\n", "Hell", "Hell", "Hell", "Hell");
	// n +=	  printf("%-.5s,%-5.s,%-7.3s,%-5.7s;\n", "Hell", "Hell", "Hell", "Hell");
	// ft_printf("-------------------");printf("%d, %d\n", nft, n);
	// nft += ft_printf("%.5s,%5.s,%7.3s,%5.7s;\n", NULL,NULL,NULL,NULL);
	// n +=	  printf("%.5s,%5.s,%7.3s,%5.7s;\n", NULL,NULL,NULL,NULL);
	// nft += ft_printf("%-.5s,%-5.s,%-7.3s,%-5.7s;\n", NULL, NULL, NULL, NULL);
	// n +=	  printf("%-.5s,%-5.s,%-7.3s,%-5.7s;\n", NULL, NULL, NULL, NULL);
	// ft_printf("-------------------");printf("%d, %d\n", nft, n);
	// nft += ft_printf("!%1s;%1.s;%-5.s!\n", "hell","hell","hell");
	// n +=	  printf("!%1s;%1.s;%-5.s!\n", "hell","hell","hell");
	ft_printf("-------------------");printf("%d, %d\n", nft, n);
	// nft += ft_printf(";% 42.2d;\n;%9.2d;\n;%-40.36d;\n;%-46d;\n;%024d;\n;%050.36d;\n", 0,0,20,-1946103326,-2077479496,-682667950);
	// n +=	  printf(";% 42.2d;\n;%9.2d;\n;%-40.36d;\n;%-46d;\n;%024d;\n;%050.36d;\n", 0,0,20,-1946103326,-2077479496,-682667950);
	nft += ft_printf(";% 42.2d;\n", 0);
	n +=	  printf(";% 42.2d;\n", 0);
	nft += ft_printf(";% -4d;", -8);
	n +=	  printf(";% -4d;", -8);
	nft += ft_printf(";%9.2d;\n", 0);
	n +=	  printf(";%9.2d;\n", 0);
	nft += ft_printf(";%-40.36d;\n", 20);
	n +=	  printf(";%-40.36d;\n", 20);
	nft += ft_printf(";%-46d;\n", -1946103326);
	n +=	  printf(";%-46d;\n", -1946103326);
	nft += ft_printf(";%024d;\n", -2077479496);
	n +=	  printf(";%024d;\n", -2077479496);
	nft += ft_printf(";%050.36d;\n", -682667950);
	n +=	  printf(";%050.36d;\n", -682667950);
	nft += ft_printf(";% -20d;\n", 10);
	n +=	  printf(";% -20d;\n", 10);
	nft += ft_printf(";% 049d;\n", 0);
	n +=	  printf(";% 049d;\n", 0);
	nft += ft_printf(";% 12.12d;\n", 0);
	n +=	  printf(";% 12.12d;\n", 0);
	ft_printf("-------------------");printf("%d, %d\n", nft, n);
	nft += ft_printf(";%+-24d;%+024d;\n", 0,0);
	n +=	  printf(";%+-24d;%+024d;\n", 0,0);
	ft_printf("-------------------");printf("%d, %d\n", nft, n);
	// nft += ft_printf("%-5d;%05d;%.5d\n", 42,42,42);
	
	return (0);
} // %-3s : width of 3 applied (spaces after the string)
  // %.3s : only 3 characters of the string are printed

// For /Users/asadiqui/francinette/tests/printf/printfTester/tests/minus_test.cpp:
// 35: 	TEST(10, print(" %.1s %.2s %.3s %.4s ", " - ", "", "4", ""));

// For /Users/asadiqui/francinette/tests/printf/printfTester/tests/dot_test.cpp:
// 29: 	TEST(5, print(" %.s ", "-"));
// 32: 	TEST(8, print(" %.1s %.2s %.3s %.4s ", " - ", "", "4", ""));
// 33: 	TEST(9, print(" %.2s %.3s %.4s %.5s %.1s ", " - ", "", "4", "", "2 "));

// For /Users/asadiqui/francinette/tests/printf/printfTester/tests/space_test.cpp:
// 26: 	TEST(2, print(" % 1s", ""));
// 27: 	TEST(3, print("% 1s ", ""));
;-8  ;