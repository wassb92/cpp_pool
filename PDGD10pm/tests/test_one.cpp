/*
** EPITECH PROJECT, 2022
** day14a ex00
** File description:
** main
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(test_one, simple_string, .init = redirect_all_std)
{
    cr_assert_eq(system("cd ./ex01/ && make re && ./RoverUnit"), 0);
}