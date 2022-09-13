/*
** EPITECH PROJECT, 2022
** day14a ex00
** File description:
** main
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../ex00/Picture.hpp"
#include "../ex00/Toy.hpp"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(test_one, simple_string, .init = redirect_all_std)
{
    printf("basic toy: TOTO !\nthis alien is: green\n         _|_\n   ,_.-_' _ '_-._,\n    l (.)(.)(.) /\n _,  `l_-===-_/`  ,_\n>  |----\"\"\"\"\"----|  <\n`\"\"`--/   _-@-l--`\"\"`\n     |===L_I===|\n      l       /\n      _l__|__/_\n     `\"\"\"\"`\"\"\"\"`\n\n\n");

    fflush(NULL);

    cr_assert_stdout_eq_str("basic toy: TOTO !\nthis alien is: green\n         _|_\n   ,_.-_' _ '_-._,\n    l (.)(.)(.) /\n _,  `l_-===-_/`  ,_\n>  |----\"\"\"\"\"----|  <\n`\"\"`--/   _-@-l--`\"\"`\n     |===L_I===|\n      l       /\n      _l__|__/_\n     `\"\"\"\"`\"\"\"\"`\n\n\n");
}
