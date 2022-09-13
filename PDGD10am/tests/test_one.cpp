/*
** EPITECH PROJECT, 2022
** day14a ex00
** File description:
** main
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../ex00/Banana.hpp"
#include "../ex00/FruitBox.hpp"
#include "../ex00/Fruit.hpp"
#include "../ex00/FruitNode.hpp"
#include "../ex00/Lemon.hpp"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(test_one, simple_string, .init = redirect_all_std)
{
    Lemon l;
    Banana b;

    std::cout << l.getVitamins() << std::endl;
    std::cout << b.getVitamins() << std::endl;
    std::cout << l.getName() << std::endl;
    std::cout << b.getName() << std::endl;
    Fruit &f = l;
    std::cout << f.getVitamins() << std::endl;
    std::cout << f.getName() << std::endl;

    cr_assert_stdout_eq_str("3\n5\nlemon\nbanana\n3\nlemon\n");
}

Test(test_two, simple_string, .init = redirect_all_std)
{
    {
        FruitBox fb(2);
        Banana *IMABANANA = new Banana;

        std::cout << fb.nbFruits() << std::endl;
        std::cout << std::boolalpha << (fb.head() == NULL) << std::noboolalpha << std::endl;
        std::cout << std::boolalpha << (fb.pickFruit() == NULL) << std::noboolalpha << std::endl;
        std::cout << fb.nbFruits() << std::endl;
        std::cout << std::boolalpha << fb.putFruit(IMABANANA) << std::noboolalpha << std::endl;
        std::cout << fb.nbFruits() << std::endl;
        std::cout << std::boolalpha << fb.putFruit(IMABANANA) << std::noboolalpha << std::endl;
        std::cout << fb.nbFruits() << std::endl;
        std::cout << std::boolalpha << fb.putFruit(NULL) << std::noboolalpha << std::endl;
        std::cout << fb.nbFruits() << std::endl;
        std::cout << std::boolalpha << fb.putFruit(new Lemon) << std::noboolalpha << std::endl;
        std::cout << fb.nbFruits() << std::endl;
        std::cout << std::boolalpha << (fb.head() != NULL) << std::noboolalpha << std::endl;
        std::cout << std::boolalpha << (fb.pickFruit() == IMABANANA) << std::noboolalpha << std::endl;
        std::cout << fb.nbFruits() << std::endl;
        std::cout << std::boolalpha << fb.putFruit(new Banana) << std::noboolalpha << std::endl;
        std::cout << fb.nbFruits() << std::endl;
        std::cout << std::boolalpha << (fb.pickFruit() != NULL) << std::noboolalpha << std::endl;
        std::cout << fb.nbFruits() << std::endl;
        std::cout << std::boolalpha << (fb.pickFruit() != NULL) << std::noboolalpha << std::endl;
        std::cout << fb.nbFruits() << std::endl;
        std::cout << std::boolalpha << (fb.pickFruit() == NULL) << std::noboolalpha << std::endl;
        std::cout << fb.nbFruits() << std::endl;
        delete IMABANANA;
    }

    cr_assert_stdout_eq_str("0\ntrue\ntrue\n0\ntrue\n1\nfalse\n1\nfalse\n1\ntrue\n2\ntrue\ntrue\n1\ntrue\n2\ntrue\n1\ntrue\n0\ntrue\n0\n");
}

Test(test_three, simple_string, .init = redirect_all_std)
{
    FruitBox fb(0);
    FruitBox fb2(-1);
    Banana *IMABANANA = new Banana;

    std::cout << fb.nbFruits() << std::endl;
    std::cout << std::boolalpha << (fb.head() == NULL) << std::noboolalpha << std::endl;
    std::cout << std::boolalpha << (fb.pickFruit() == NULL) << std::noboolalpha << std::endl;
    std::cout << std::boolalpha << fb.putFruit(IMABANANA) << std::noboolalpha << std::endl;
    std::cout << std::boolalpha << (fb.head() == NULL) << std::noboolalpha << std::endl;
    std::cout << std::boolalpha << (fb.pickFruit() == NULL) << std::noboolalpha << std::endl;
    std::cout << fb.nbFruits() << std::endl;
    std::cout << fb2.nbFruits() << std::endl;
    std::cout << std::boolalpha << (fb2.head() == NULL) << std::noboolalpha << std::endl;
    std::cout << std::boolalpha << (fb2.pickFruit() == NULL) << std::noboolalpha << std::endl;
    std::cout << std::boolalpha << fb2.putFruit(IMABANANA) << std::noboolalpha << std::endl;
    std::cout << std::boolalpha << (fb2.head() == NULL) << std::noboolalpha << std::endl;
    std::cout << std::boolalpha << (fb2.pickFruit() == NULL) << std::noboolalpha << std::endl;
    std::cout << fb2.nbFruits() << std::endl;
    delete IMABANANA;

    cr_assert_stdout_eq_str("0\ntrue\ntrue\ntrue\nfalse\nfalse\n0\n0\ntrue\ntrue\nfalse\ntrue\ntrue\n0\n");
}
